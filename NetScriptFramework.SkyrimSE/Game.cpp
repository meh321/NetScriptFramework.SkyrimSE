#include "Vids.h"
#include "Game.h"
#include "Interfaces.h"
#include "Module.h"
#include "Events.h"

namespace NetScriptFramework
{
	namespace SkyrimSE
	{
		int CrashLogModListWriter__Sort(TESFile^ a, TESFile^ b)
		{
			bool aesl = a->IsSmallFile;
			bool besl = b->IsSmallFile;
			if(aesl != besl) return aesl.CompareTo(besl);
			return a->Index.CompareTo(b->Index);
		}

		void CrashLogModListWriter__Write(NetScriptFramework::CrashLogEventArgs^ e)
		{
			if(e->Skip)
				return;
			auto data = DataHandler::Instance;
			if(data == nullptr)
				return;
			auto mods2 = data->CompiledFileCollection->Files;
			auto mods3 = data->CompiledFileCollection->SmallFiles;
			auto mods = gcnew System::Collections::Generic::List<TESFile^>(256);
			if(mods2 != nullptr)
			{
				for each(TESFile^ m in mods2)
					mods->Add(m);
			}
			if(mods3 != nullptr)
			{
				for each(TESFile^ m in mods3)
					mods->Add(m);
			}
			mods->Sort(gcnew System::Comparison<TESFile^>(CrashLogModListWriter__Sort));
			e->Output->AppendLine();
			e->Output->AppendLine("Game plugins (" + mods->Count + ")");
			e->Output->AppendLine("{");
			for each(TESFile^ mod in mods)
			{
				auto name = mod->Name;
				if(name == nullptr)
					name = "(null)";
				if(!mod->IsSmallFile)
					e->Output->AppendLine("  [" + mod->Index.ToString("X2") + "] " + name);
				else
					e->Output->AppendLine("  [FE " + mod->Index.ToString("X3") + "] " + name);
			}
			e->Output->AppendLine("}");
		}

		void DontWriteCrashLogOnExit__Write(NetScriptFramework::CrashLogEventArgs^ e)
		{
			if(e->Skip)
				return;
			auto main = Main::Instance;
			if(main == nullptr)
				return;
			if(main->QuitGame)
				e->Skip = true;
		}

		void KeywordCache::Initialize()
		{
			_map = gcnew System::Collections::Generic::Dictionary<System::String^, System::Collections::Generic::List<BGSKeyword^>^>();

			auto all = DataHandler::Instance->GetAllFormsByType(FormTypes::Keyword);
			if (all == nullptr)
				return;

			for each(TESForm^ form in all)
			{
				auto kw = safe_cast<BGSKeyword^>(form);
				if (kw == nullptr)
					continue;

				System::String^ text = kw->KeywordText->Text;
				if (text == nullptr)
					continue;

				text = text->ToLowerInvariant();
				System::Collections::Generic::List<BGSKeyword^>^ ls = nullptr;
				if (!_map->TryGetValue(text, ls))
				{
					ls = gcnew System::Collections::Generic::List<BGSKeyword^>();
					_map[text] = ls;
				}

				ls->Add(kw);
			}
		}

		void KeywordCache__Initialize(MainMenuEventArgs^ e)
		{
			KeywordCache::Initialize();
		}

		void NiObjectLoadParameters::_RequestModelDirect(NiObjectLoadParameters^ p)
		{
			System::Int32 result = 0;
			p->_alloc = NetScriptFramework::Memory::Allocate(0x30, 0, false);
			NetScriptFramework::Memory::WritePointer(p->_alloc->Address, System::IntPtr::Zero, false);
			NetScriptFramework::Memory::WriteInt32(p->_alloc->Address + 0x10, 0, false);
			NetScriptFramework::Memory::WriteInt32(p->_alloc->Address + 0x14, 3, false);
			NetScriptFramework::Memory::WriteInt32(p->_alloc->Address + 0x18, 0x1010001, false);

			auto str = NetScriptFramework::Memory::AllocateString(p->FileName, false);
			try
			{
				result = (System::Int32)(NetScriptFramework::Memory::InvokeCdecl(__VIDS::VID74039.Value, str->Address, p->_alloc->Address, p->_alloc->Address + 0x10).ToInt64() & 0xFF);
			}
			finally
			{
				delete str;
			}

			if ((result != 0 && result != 6) || !p->Process())
				p->Finish();
		}

		void NiObjectLoadParameters::_RequestModelAsync(NiObjectLoadParameters^ p)
		{
			System::Int32 result = 0;
			p->_alloc = NetScriptFramework::Memory::Allocate(0x30, 0, false);
			NetScriptFramework::Memory::WritePointer(p->_alloc->Address, System::IntPtr::Zero, false);
			NetScriptFramework::Memory::WriteInt32(p->_alloc->Address + 0x10, 0, false);
			NetScriptFramework::Memory::WriteInt32(p->_alloc->Address + 0x14, 3, false);
			NetScriptFramework::Memory::WriteInt32(p->_alloc->Address + 0x18, 0x1010001, false);

			auto str = NetScriptFramework::Memory::AllocateString(p->FileName, false);
			try
			{
				result = (System::Int32)(NetScriptFramework::Memory::InvokeCdecl(__VIDS::VID74038.Value, str->Address, p->_alloc->Address, p->_alloc->Address + 0x10, 0).ToInt64() & 0xFF);
			}
			finally
			{
				delete str;
			}

			if (result == 0 || result == 6)
			{
				System::Threading::Monitor::Enter(_locker);
				try
				{
					_queued->Add(p);
				}
				finally
				{
					System::Threading::Monitor::Exit(_locker);
				}
				return;
			}

			p->Finish();
		}

		void NiObjectLoadParameters::_UpdateRequestModel()
		{
			System::Collections::Generic::List<NiObjectLoadParameters^>^ ls = nullptr;
			System::Threading::Monitor::Enter(_locker);
			try
			{
				if (_queued->Count == 0)
					return;

				ls = _queued;
				_queued = gcnew System::Collections::Generic::List<NiObjectLoadParameters^>();
			}
			finally
			{
				System::Threading::Monitor::Exit(_locker);
			}

			for (System::Int32 i = 0; i < ls->Count; )
			{
				auto p = ls[i];

				if (!p->Process())
				{
					i++;
					continue;
				}

				ls->RemoveAt(i);
			}

			if (ls->Count != 0)
			{
				System::Threading::Monitor::Enter(_locker);
				try
				{
					if (_queued->Count == 0)
						_queued = ls;
					else
						_queued->InsertRange(0, ls);
				}
				finally
				{
					System::Threading::Monitor::Exit(_locker);
				}
			}
		}

		bool NiObjectLoadParameters::Process()
		{
			auto ptr = NetScriptFramework::Memory::ReadPointer(_alloc->Address, false);
			if (ptr != System::IntPtr::Zero)
			{
				auto prototypePtr = NetScriptFramework::Memory::ReadPointer(ptr + 0x28, false);
				if (prototypePtr == System::IntPtr::Zero)
					return false;

				auto obj = NetScriptFramework::MemoryObject::FromAddress<NiObject^>(prototypePtr);
				if (obj != nullptr)
				{
					System::Int32 c = this->Count;
					for (System::Int32 i = 0; i < c; i++)
					{
						auto cloned = obj->Clone();
						if (cloned == nullptr)
							break;

						cloned->IncRef();
						_result->Add(cloned);
					}

					if (c <= 0 || c == _result->Count)
						_success = true;
				}
			}

			Finish();
			return true;
		}

		void NiObjectLoadParameters::Finish()
		{
			try
			{
				if (Callback != nullptr)
					Callback(this);
			}
			finally
			{
				Cleanup();
			}
		}

		void NiObjectLoadParameters::Cleanup()
		{
			for (System::Int32 i = 0; i < _result->Count; i++)
				_result[i]->DecRef();

			if (_alloc != nullptr)
			{
				auto ptr = NetScriptFramework::Memory::ReadPointer(_alloc->Address, false);
				if (ptr != System::IntPtr::Zero)
				{
					auto db = NetScriptFramework::Memory::ReadPointer(__VIDS::VID514145.Value, false) + 0xD0;
					NetScriptFramework::Memory::InvokeCdecl(__VIDS::VID11275.Value, db, ptr);
				}

				delete _alloc;
				_alloc = nullptr;
			}
		}

		void NiObjectLoadParameters__OnFrame(FrameEventArgs^ e)
		{
			NiObjectLoadParameters::_UpdateRequestModel();
		}

		RayCastResult^ RayCastResult::GetClosestResult(array<float>^ source, System::Collections::Generic::List<RayCastResult^>^ results, ... array<NiAVObject^>^ ignore)
		{
			if (source == nullptr)
				throw gcnew System::ArgumentNullException("source");

			if (source->Length != 3)
				throw gcnew System::ArgumentOutOfRangeException("source.Length");

			if (results != nullptr)
			{
				bool checkIgnore = ignore != nullptr && ignore->Length != 0;
				RayCastResult^ bestResult = nullptr;
				float bestDist = 0.0f;

				for each(RayCastResult^ r in results)
				{
					array<float>^ rpos = r->Position;
					float dx = rpos[0] - source[0];
					float dy = rpos[1] - source[1];
					float dz = rpos[2] - source[2];
					float dist = dx * dx + dy * dy + dz * dz;

					if (bestResult != nullptr && bestDist <= dist)
						continue;

					if (checkIgnore)
					{
						auto obj = r->Object;
						if (obj != nullptr)
						{
							bool ok = true;
							for (int i = 0; i < ignore->Length; i++)
							{
								auto io = (NetScriptFramework::IMemoryObject^)ignore[i];
								if (io != nullptr && io->Equals(obj))
								{
									ok = false;
									break;
								}
							}
							if (!ok)
								continue;
						}
					}

					bestResult = r;
					bestDist = dist;
				}

				return bestResult;
			}

			return nullptr;
		}

		System::Collections::Generic::List<RayCastResult^>^ _Havok::RayCast(RayCastParameters^ p)
		{
			if (p == nullptr)
				throw gcnew System::ArgumentNullException("p");

			if (p->Cell == nullptr)
				throw gcnew System::NullReferenceException("RayCastParameters.Cell");

			auto result = gcnew System::Collections::Generic::List<RayCastResult^>();
			auto begin = p->Begin;
			auto end = p->End;

			if (begin == nullptr)
				begin = gcnew array<float>(3);
			if (end == nullptr)
				end = gcnew array<float>(3);

			auto havokWorldPtr = NetScriptFramework::Memory::InvokeCdecl(__VIDS::VID18536.Value, p->Cell->Cast<TESObjectCELL^>());
			if (havokWorldPtr == System::IntPtr::Zero)
				return result;

			const float havokWorldScale = 0.0142875f;
			customRayHitCollector collector;
			char _argsRaw[0x110];
			__int64 args = (__int64)_argsRaw;
			if ((args & 0xF) != 0)
				args += 0x10 - (args & 0xF);

			*((bool*)(args + 0x20)) = false;
			*((int*)(args + 0x24)) = 0; // this is sometimes set in specific actor or object ref cases
			*((float*)(args + 0x40)) = 1.0f;
			for (int i = 0; i < 3; i++)
				*((int*)(args + 0x44 + 4 * i)) = -1;
			*((int*)(args + 0x70)) = 0;
			*((__int64*)(args + 0x80)) = 0;

			for (int i = 0; i < 4; i++)
				*((__int64*)(args + 0xA0 + i * 8)) = 0;

			*((bool*)(args + 0xC0)) = false;

			*((float*)(args + 0)) = begin[0] * havokWorldScale;
			*((float*)(args + 4)) = begin[1] * havokWorldScale;
			*((float*)(args + 8)) = begin[2] * havokWorldScale;
			*((float*)(args + 0xC)) = 0.0f;

			*((float*)(args + 0x90)) = (end[0] - begin[0]) * havokWorldScale;
			*((float*)(args + 0x94)) = (end[1] - begin[1]) * havokWorldScale;
			*((float*)(args + 0x98)) = (end[2] - begin[2]) * havokWorldScale;
			*((float*)(args + 0x9C)) = 0.0f;

			*((void**)(args + 0xA8)) = &collector;

			auto vtable = NetScriptFramework::Memory::ReadPointer(havokWorldPtr, false);
			auto func51 = NetScriptFramework::Memory::ReadPointer(vtable + 0x198, false);
			System::IntPtr callfn = NetScriptFramework::Memory::InvokeCdecl(func51, havokWorldPtr, System::IntPtr(args));

			/*if ((callfn.ToInt64() & 0xFF) == 0)
			return result;*/

			auto n = collector.first;
			while (n != 0)
			{
				auto r = gcnew RayCastResult();
				result->Add(r);
				r->Fraction = n->fraction;
				r->Normal = gcnew array<float>(3);
				r->Normal[0] = n->normal[0];
				r->Normal[1] = n->normal[1];
				r->Normal[2] = n->normal[2];
				r->Position = gcnew array<float>(3);
				r->Position[0] = (end[0] - begin[0]) * n->fraction + begin[0];
				r->Position[1] = (end[1] - begin[1]) * n->fraction + begin[1];
				r->Position[2] = (end[2] - begin[2]) * n->fraction + begin[2];

				System::IntPtr obj = System::IntPtr(n->obj);
				r->_hkObj = obj;
				//r->Debug = NetScriptFramework::Memory::ReadUInt32(obj + 44, false) >> 16;
				/*if ((Memory::ReadUInt32(obj + 44) & 0xFFFF0000) == 0x10000) // Terrain
				{

				}
				else*/
				{
					obj = NetScriptFramework::Memory::InvokeCdecl(__VIDS::VID76160.Value, obj);
				}
				r->_obj = obj;

				n = n->next;
			}

			return result;
		}

		TESForm^ TESForm::LookupFormFromFile(System::UInt32 formId, System::String^ fileName)
		{
			if (fileName == nullptr) throw gcnew System::ArgumentNullException("fileName");
			auto dataHandler = DataHandler::Instance;
			if (dataHandler == nullptr) return nullptr;
			auto alloc = NetScriptFramework::Memory::AllocateString(fileName, false);
			auto alloc2 = NetScriptFramework::Memory::Allocate(0x10, 0, false);
			try
			{
				auto filePtr = NetScriptFramework::Memory::InvokeCdecl(__VIDS::VID13632.Value, dataHandler->Address, alloc->Address);
				if (filePtr == System::IntPtr::Zero) return nullptr;
				if ((MCH::u(NetScriptFramework::Memory::InvokeCdecl(__VIDS::VID13882.Value, filePtr)) & 0xFF) == 0) return nullptr;
				alloc2->Zero();
				NetScriptFramework::Memory::WriteUInt32(alloc2->Address, formId, false);
				NetScriptFramework::Memory::InvokeCdecl(__VIDS::VID13915.Value, filePtr, alloc2->Address);
				formId = NetScriptFramework::Memory::ReadUInt32(alloc2->Address, false);
				return LookupFormById(formId);
			}
			finally
			{
				delete alloc2;
				delete alloc;
			}
		}

		void NiObject::LoadFromFile(NiObjectLoadParameters^ p)
		{
			if (p == nullptr)
				throw gcnew System::ArgumentNullException("p");

			if (p->FileName == nullptr)
				throw gcnew System::ArgumentNullException("p.FileName");

			NiObjectLoadParameters::_RequestModelDirect(p);
		}

		void NiObject::LoadFromFileAsync(NiObjectLoadParameters^ p)
		{
			if (p == nullptr)
				throw gcnew System::ArgumentNullException("p");

			if (p->FileName == nullptr)
				throw gcnew System::ArgumentNullException("p.FileName");

			NiObjectLoadParameters::_RequestModelAsync(p);
		}

		System::Collections::Generic::List<RayCastResult^>^ TESObjectCELL::RayCast(RayCastParameters^ p)
		{
			if(p == nullptr)
				throw gcnew System::ArgumentNullException("p");
			if(p->Cell == nullptr)
				throw gcnew System::ArgumentNullException("p.Cell");
			return _Havok::RayCast(p);
		}

		void SkyrimSEGame::Initialize()
		{
			// Perform base class initialization.
			Game::Initialize();

			// Ensure base address is cached.
			MCH::GetBase();
			MCH::GetLibraryBase();

			// Cache values for later.
			__VIDS::Init();
			__CVTS::Init();

			// Register types.
			RegisterTypes();

			// Register events.
			Events::InitializeEvents();

			Events::OnFrame->Register(gcnew NetScriptFramework::Event<FrameEventArgs^>::EventHandler(NiObjectLoadParameters__OnFrame), 0, 0, NetScriptFramework::EventRegistrationFlags::None);

			Events::OnMainMenu->Register(gcnew NetScriptFramework::Event<MainMenuEventArgs^>::EventHandler(KeywordCache__Initialize), 0, 1, NetScriptFramework::EventRegistrationFlags::None);

			NetScriptFramework::CrashLog::OnAfterWrite->Register(gcnew NetScriptFramework::Event<CrashLogEventArgs^>::EventHandler(CrashLogModListWriter__Write), 0, 0, NetScriptFramework::EventRegistrationFlags::None);

			NetScriptFramework::CrashLog::OnBeforeWrite->Register(gcnew NetScriptFramework::Event<CrashLogEventArgs^>::EventHandler(DontWriteCrashLogOnExit__Write), 0, 0, NetScriptFramework::EventRegistrationFlags::None);
		}

		void SkyrimSEGame::RegisterTypes()
		{
			auto modulePtr = NetScriptFramework::Main::GetMainTargetedModule()->BaseAddress;
			System::Reflection::Assembly^ assembly = nullptr;
			System::IO::FileInfo^ file = gcnew System::IO::FileInfo(NetScriptFramework::Main::FrameworkPath + "\\NetScriptFramework.SkyrimSE.Implementations.dll");
			if (!file->Exists) throw gcnew System::IO::FileNotFoundException("The implementations file was not found!", NetScriptFramework::Main::FrameworkPath + "\\NetScriptFramework.SkyrimSE.Implementations.dll");
			NetScriptFramework::Loader::Load(file, assembly);
			auto types = assembly->GetTypes();
			for each(System::Type^ t in types)
			{
				if (t->Name != "NetScriptFramework_SkyrimSE_TypeRegistrations") continue;
				auto methods = t->GetMethods(System::Reflection::BindingFlags::Static | System::Reflection::BindingFlags::NonPublic | System::Reflection::BindingFlags::Public);
				for each(System::Reflection::MethodInfo^ m in methods)
				{
					if (!m->IsStatic || m->Name != "RegisterTypes" || m->GetParameters()->Length != 0 || m->ReturnType != System::Collections::Generic::List<System::Tuple<System::Int32, System::Type^, System::UInt64>^>::typeid) continue;
					auto ls = safe_cast<System::Collections::Generic::List<System::Tuple<System::Int32, System::Type^, System::UInt64>^>^>(m->Invoke(nullptr, gcnew array<System::Object^>(0)));
					for each(auto t in ls)
					{
						if (t->Item1 >= 0) this->RegisterImplementationType((System::UInt32)t->Item1, t->Item2, t->Item3);
						else this->RegisterInterfaceType((System::UInt32)(-t->Item1), t->Item2, t->Item3);
					}
				}
			}
		}
	}
}
