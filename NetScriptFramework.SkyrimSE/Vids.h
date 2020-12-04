#pragma once
#pragma warning(push)
#pragma warning(disable : 4638)

namespace NetScriptFramework
{
	namespace SkyrimSE
	{
		/// <summary>
		/// Implement helper functions for converting between base address types.
		/// </summary>
		[System::Runtime::CompilerServices::ExtensionAttribute]
		public ref class MCH sealed abstract
		{
		internal:
			/// <summary>
			/// The internal base address value.
			/// </summary>
			static System::Nullable<System::IntPtr> _base;

			/// <summary>
			/// The library base address value.
			/// </summary>
			static System::Nullable<System::IntPtr> _lbase;

			/// <summary>
			/// Gets the base address of main module.
			/// </summary>
			/// <returns></returns>
			static System::IntPtr GetBase()
			{
				if (!_base.HasValue)
					_base = NetScriptFramework::Main::GetMainTargetedModule()->BaseAddress;
				return _base.Value;
			}

			/// <summary>
			/// Gets the base address in library module.
			/// </summary>
			/// <returns></returns>
			static System::IntPtr GetLibraryBase()
			{
				if (!_lbase.HasValue)
					_lbase = System::IntPtr((System::Int64)NetScriptFramework::Main::GameInfo->LibraryBaseOffset);
				return _lbase.Value;
			}

		public:
			/// <summary>
			/// Convert pointer from static base address to current module's base.
			/// </summary>
			/// <param name="ptr">The pointer to convert.</param>
			/// <returns></returns>
			[System::Runtime::CompilerServices::ExtensionAttribute]
			static System::IntPtr FromBase(System::IntPtr ptr)
			{
				return System::IntPtr(ptr.ToInt64() - GetLibraryBase().ToInt64() + GetBase().ToInt64());
			}

			/// <summary>
			/// Convert pointer from current module's base address to static base.
			/// </summary>
			/// <param name="ptr">The pointer to convert.</param>
			/// <returns></returns>
			[System::Runtime::CompilerServices::ExtensionAttribute]
			static System::IntPtr ToBase(System::IntPtr ptr)
			{
				return System::IntPtr(ptr.ToInt64() - GetBase().ToInt64() + GetLibraryBase().ToInt64());
			}

			/// <summary>
			/// Convert pointer from static base address to current module's base.
			/// </summary>
			/// <param name="ptr">The pointer to convert.</param>
			/// <returns></returns>
			[System::Runtime::CompilerServices::ExtensionAttribute]
			static System::IntPtr FromBase(System::Int64 ptr)
			{
				return System::IntPtr(ptr - GetLibraryBase().ToInt64() + GetBase().ToInt64());
			}

			/// <summary>
			/// Convert pointer from current module's base address to static base.
			/// </summary>
			/// <param name="ptr">The pointer to convert.</param>
			/// <returns></returns>
			[System::Runtime::CompilerServices::ExtensionAttribute]
			static System::IntPtr ToBase(System::Int64 ptr)
			{
				return System::IntPtr(ptr - GetLibraryBase().ToInt64() + GetBase().ToInt64());
			}

			/// <summary>
			/// Throws an exception.
			/// </summary>
			/// <param name="typeName">The type name.</param>
			/// <returns></returns>
			static System::Int32 _UNKNOWN_SIZEOF(System::String^ typeName)
			{
				throw gcnew System::ArgumentOutOfRangeException(typeName);
			}

		internal:
			/// <summary>
			/// Convert pointer to a convertible value.
			/// </summary>
			/// <param name="ptr">The pointer to convert.</param>
			/// <returns></returns>
			static System::UInt64 u(System::IntPtr ptr)
			{
				return System::UInt64(ptr.ToInt64());
			}

			/// <summary>
			/// Convert pointer to a boolean value.
			/// </summary>
			/// <param name="ptr">The pointer to convert.</param>
			/// <returns></returns>
			static System::Boolean b(System::IntPtr ptr)
			{
				return (u(ptr) & 0xFF) != 0;
			}

			/// <summary>
			/// Process function argument type.
			/// </summary>
			/// <param name="obj">The value to process.</param>
			/// <param name="checkNullArg">If this is set the argument will be checked for null value and throw exception if it is null.</param>
			/// <returns></returns>
			generic <typename T> where T : NetScriptFramework::IMemoryObject
			static System::Boolean e(T% obj, System::String^ checkNullArg)
			{
				if(obj != nullptr)
					obj = safe_cast<T>(obj);
				if(obj == nullptr)
				{
					if(checkNullArg != nullptr) throw gcnew System::ArgumentNullException(checkNullArg);
					return false;
				}
				return true;
			}
		};

		/// <summary>
		/// Contains cached version specific addresses.
		/// </summary>
		public ref class __VIDS sealed abstract
		{
		public:
			static NetScriptFramework::CachedVid VID10878;
			static NetScriptFramework::CachedVid VID11275;
			static NetScriptFramework::CachedVid VID11433;
			static NetScriptFramework::CachedVid VID11435;
			static NetScriptFramework::CachedVid VID11436;
			static NetScriptFramework::CachedVid VID11546;
			static NetScriptFramework::CachedVid VID12176;
			static NetScriptFramework::CachedVid VID12192;
			static NetScriptFramework::CachedVid VID12200;
			static NetScriptFramework::CachedVid VID12210;
			static NetScriptFramework::CachedVid VID12229;
			static NetScriptFramework::CachedVid VID12230;
			static NetScriptFramework::CachedVid VID12272;
			static NetScriptFramework::CachedVid VID12275;
			static NetScriptFramework::CachedVid VID12666;
			static NetScriptFramework::CachedVid VID13163;
			static NetScriptFramework::CachedVid VID13549;
			static NetScriptFramework::CachedVid VID13632;
			static NetScriptFramework::CachedVid VID13789;
			static NetScriptFramework::CachedVid VID13882;
			static NetScriptFramework::CachedVid VID13915;
			static NetScriptFramework::CachedVid VID14108;
			static NetScriptFramework::CachedVid VID14125;
			static NetScriptFramework::CachedVid VID14461;
			static NetScriptFramework::CachedVid VID14577;
			static NetScriptFramework::CachedVid VID14799;
			static NetScriptFramework::CachedVid VID15231;
			static NetScriptFramework::CachedVid VID15232;
			static NetScriptFramework::CachedVid VID15713;
			static NetScriptFramework::CachedVid VID15801;
			static NetScriptFramework::CachedVid VID15808;
			static NetScriptFramework::CachedVid VID15873;
			static NetScriptFramework::CachedVid VID15874;
			static NetScriptFramework::CachedVid VID16828;
			static NetScriptFramework::CachedVid VID17693;
			static NetScriptFramework::CachedVid VID18185;
			static NetScriptFramework::CachedVid VID18505;
			static NetScriptFramework::CachedVid VID18524;
			static NetScriptFramework::CachedVid VID18536;
			static NetScriptFramework::CachedVid VID19006;
			static NetScriptFramework::CachedVid VID19369;
			static NetScriptFramework::CachedVid VID19385;
			static NetScriptFramework::CachedVid VID19446;
			static NetScriptFramework::CachedVid VID19818;
			static NetScriptFramework::CachedVid VID19823;
			static NetScriptFramework::CachedVid VID20061;
			static NetScriptFramework::CachedVid VID21343;
			static NetScriptFramework::CachedVid VID22315;
			static NetScriptFramework::CachedVid VID23073;
			static NetScriptFramework::CachedVid VID25980;
			static NetScriptFramework::CachedVid VID32141;
			static NetScriptFramework::CachedVid VID32289;
			static NetScriptFramework::CachedVid VID32290;
			static NetScriptFramework::CachedVid VID33281;
			static NetScriptFramework::CachedVid VID33286;
			static NetScriptFramework::CachedVid VID33362;
			static NetScriptFramework::CachedVid VID33629;
			static NetScriptFramework::CachedVid VID33630;
			static NetScriptFramework::CachedVid VID33726;
			static NetScriptFramework::CachedVid VID33733;
			static NetScriptFramework::CachedVid VID33734;
			static NetScriptFramework::CachedVid VID33736;
			static NetScriptFramework::CachedVid VID33752;
			static NetScriptFramework::CachedVid VID35565;
			static NetScriptFramework::CachedVid VID35984;
			static NetScriptFramework::CachedVid VID36272;
			static NetScriptFramework::CachedVid VID36326;
			static NetScriptFramework::CachedVid VID36429;
			static NetScriptFramework::CachedVid VID36604;
			static NetScriptFramework::CachedVid VID36607;
			static NetScriptFramework::CachedVid VID36727;
			static NetScriptFramework::CachedVid VID36877;
			static NetScriptFramework::CachedVid VID37513;
			static NetScriptFramework::CachedVid VID37596;
			static NetScriptFramework::CachedVid VID37672;
			static NetScriptFramework::CachedVid VID37757;
			static NetScriptFramework::CachedVid VID37758;
			static NetScriptFramework::CachedVid VID37773;
			static NetScriptFramework::CachedVid VID37799;
			static NetScriptFramework::CachedVid VID37808;
			static NetScriptFramework::CachedVid VID37828;
			static NetScriptFramework::CachedVid VID37829;
			static NetScriptFramework::CachedVid VID37864;
			static NetScriptFramework::CachedVid VID38235;
			static NetScriptFramework::CachedVid VID38236;
			static NetScriptFramework::CachedVid VID38375;
			static NetScriptFramework::CachedVid VID38826;
			static NetScriptFramework::CachedVid VID38850;
			static NetScriptFramework::CachedVid VID38852;
			static NetScriptFramework::CachedVid VID39375;
			static NetScriptFramework::CachedVid VID40554;
			static NetScriptFramework::CachedVid VID40555;
			static NetScriptFramework::CachedVid VID41259;
			static NetScriptFramework::CachedVid VID41659;
			static NetScriptFramework::CachedVid VID41778;
			static NetScriptFramework::CachedVid VID42928;
			static NetScriptFramework::CachedVid VID49858;
			static NetScriptFramework::CachedVid VID49863;
			static NetScriptFramework::CachedVid VID49968;
			static NetScriptFramework::CachedVid VID49999;
			static NetScriptFramework::CachedVid VID50066;
			static NetScriptFramework::CachedVid VID50211;
			static NetScriptFramework::CachedVid VID51236;
			static NetScriptFramework::CachedVid VID51324;
			static NetScriptFramework::CachedVid VID52050;
			static NetScriptFramework::CachedVid VID53029;
			static NetScriptFramework::CachedVid VID53761;
			static NetScriptFramework::CachedVid VID53762;
			static NetScriptFramework::CachedVid VID53845;
			static NetScriptFramework::CachedVid VID53846;
			static NetScriptFramework::CachedVid VID53847;
			static NetScriptFramework::CachedVid VID53848;
			static NetScriptFramework::CachedVid VID53852;
			static NetScriptFramework::CachedVid VID53854;
			static NetScriptFramework::CachedVid VID53856;
			static NetScriptFramework::CachedVid VID53858;
			static NetScriptFramework::CachedVid VID53859;
			static NetScriptFramework::CachedVid VID53861;
			static NetScriptFramework::CachedVid VID53862;
			static NetScriptFramework::CachedVid VID53863;
			static NetScriptFramework::CachedVid VID53864;
			static NetScriptFramework::CachedVid VID53870;
			static NetScriptFramework::CachedVid VID53871;
			static NetScriptFramework::CachedVid VID53872;
			static NetScriptFramework::CachedVid VID53873;
			static NetScriptFramework::CachedVid VID53874;
			static NetScriptFramework::CachedVid VID53877;
			static NetScriptFramework::CachedVid VID53878;
			static NetScriptFramework::CachedVid VID53879;
			static NetScriptFramework::CachedVid VID53880;
			static NetScriptFramework::CachedVid VID53881;
			static NetScriptFramework::CachedVid VID53882;
			static NetScriptFramework::CachedVid VID53883;
			static NetScriptFramework::CachedVid VID53884;
			static NetScriptFramework::CachedVid VID53885;
			static NetScriptFramework::CachedVid VID53886;
			static NetScriptFramework::CachedVid VID53888;
			static NetScriptFramework::CachedVid VID53889;
			static NetScriptFramework::CachedVid VID53890;
			static NetScriptFramework::CachedVid VID53891;
			static NetScriptFramework::CachedVid VID53892;
			static NetScriptFramework::CachedVid VID53893;
			static NetScriptFramework::CachedVid VID53894;
			static NetScriptFramework::CachedVid VID53895;
			static NetScriptFramework::CachedVid VID53896;
			static NetScriptFramework::CachedVid VID53898;
			static NetScriptFramework::CachedVid VID53899;
			static NetScriptFramework::CachedVid VID53900;
			static NetScriptFramework::CachedVid VID53914;
			static NetScriptFramework::CachedVid VID53919;
			static NetScriptFramework::CachedVid VID53922;
			static NetScriptFramework::CachedVid VID53923;
			static NetScriptFramework::CachedVid VID53924;
			static NetScriptFramework::CachedVid VID53929;
			static NetScriptFramework::CachedVid VID53930;
			static NetScriptFramework::CachedVid VID53931;
			static NetScriptFramework::CachedVid VID53932;
			static NetScriptFramework::CachedVid VID53933;
			static NetScriptFramework::CachedVid VID53934;
			static NetScriptFramework::CachedVid VID53935;
			static NetScriptFramework::CachedVid VID53936;
			static NetScriptFramework::CachedVid VID53937;
			static NetScriptFramework::CachedVid VID53939;
			static NetScriptFramework::CachedVid VID53940;
			static NetScriptFramework::CachedVid VID53941;
			static NetScriptFramework::CachedVid VID53946;
			static NetScriptFramework::CachedVid VID53947;
			static NetScriptFramework::CachedVid VID53948;
			static NetScriptFramework::CachedVid VID53949;
			static NetScriptFramework::CachedVid VID53950;
			static NetScriptFramework::CachedVid VID53952;
			static NetScriptFramework::CachedVid VID53954;
			static NetScriptFramework::CachedVid VID53955;
			static NetScriptFramework::CachedVid VID53956;
			static NetScriptFramework::CachedVid VID53957;
			static NetScriptFramework::CachedVid VID54119;
			static NetScriptFramework::CachedVid VID54120;
			static NetScriptFramework::CachedVid VID54121;
			static NetScriptFramework::CachedVid VID54122;
			static NetScriptFramework::CachedVid VID54123;
			static NetScriptFramework::CachedVid VID54124;
			static NetScriptFramework::CachedVid VID54125;
			static NetScriptFramework::CachedVid VID54126;
			static NetScriptFramework::CachedVid VID54127;
			static NetScriptFramework::CachedVid VID54128;
			static NetScriptFramework::CachedVid VID54129;
			static NetScriptFramework::CachedVid VID54130;
			static NetScriptFramework::CachedVid VID54131;
			static NetScriptFramework::CachedVid VID54132;
			static NetScriptFramework::CachedVid VID54133;
			static NetScriptFramework::CachedVid VID54135;
			static NetScriptFramework::CachedVid VID54136;
			static NetScriptFramework::CachedVid VID54137;
			static NetScriptFramework::CachedVid VID54139;
			static NetScriptFramework::CachedVid VID54140;
			static NetScriptFramework::CachedVid VID54141;
			static NetScriptFramework::CachedVid VID54142;
			static NetScriptFramework::CachedVid VID54143;
			static NetScriptFramework::CachedVid VID54144;
			static NetScriptFramework::CachedVid VID54145;
			static NetScriptFramework::CachedVid VID54146;
			static NetScriptFramework::CachedVid VID54147;
			static NetScriptFramework::CachedVid VID54148;
			static NetScriptFramework::CachedVid VID54149;
			static NetScriptFramework::CachedVid VID54150;
			static NetScriptFramework::CachedVid VID54151;
			static NetScriptFramework::CachedVid VID54152;
			static NetScriptFramework::CachedVid VID54153;
			static NetScriptFramework::CachedVid VID54154;
			static NetScriptFramework::CachedVid VID54155;
			static NetScriptFramework::CachedVid VID54156;
			static NetScriptFramework::CachedVid VID54157;
			static NetScriptFramework::CachedVid VID54158;
			static NetScriptFramework::CachedVid VID54159;
			static NetScriptFramework::CachedVid VID54160;
			static NetScriptFramework::CachedVid VID54161;
			static NetScriptFramework::CachedVid VID54162;
			static NetScriptFramework::CachedVid VID54163;
			static NetScriptFramework::CachedVid VID54164;
			static NetScriptFramework::CachedVid VID54165;
			static NetScriptFramework::CachedVid VID54166;
			static NetScriptFramework::CachedVid VID54167;
			static NetScriptFramework::CachedVid VID54168;
			static NetScriptFramework::CachedVid VID54169;
			static NetScriptFramework::CachedVid VID54170;
			static NetScriptFramework::CachedVid VID54171;
			static NetScriptFramework::CachedVid VID54172;
			static NetScriptFramework::CachedVid VID54173;
			static NetScriptFramework::CachedVid VID54174;
			static NetScriptFramework::CachedVid VID54175;
			static NetScriptFramework::CachedVid VID54632;
			static NetScriptFramework::CachedVid VID54633;
			static NetScriptFramework::CachedVid VID54634;
			static NetScriptFramework::CachedVid VID55187;
			static NetScriptFramework::CachedVid VID55288;
			static NetScriptFramework::CachedVid VID55289;
			static NetScriptFramework::CachedVid VID55369;
			static NetScriptFramework::CachedVid VID55527;
			static NetScriptFramework::CachedVid VID55528;
			static NetScriptFramework::CachedVid VID56364;
			static NetScriptFramework::CachedVid VID61531;
			static NetScriptFramework::CachedVid VID66391;
			static NetScriptFramework::CachedVid VID66859;
			static NetScriptFramework::CachedVid VID66861;
			static NetScriptFramework::CachedVid VID66862;
			static NetScriptFramework::CachedVid VID66976;
			static NetScriptFramework::CachedVid VID66977;
			static NetScriptFramework::CachedVid VID66982;
			static NetScriptFramework::CachedVid VID66983;
			static NetScriptFramework::CachedVid VID67819;
			static NetScriptFramework::CachedVid VID67822;
			static NetScriptFramework::CachedVid VID67991;
			static NetScriptFramework::CachedVid VID67992;
			static NetScriptFramework::CachedVid VID68836;
			static NetScriptFramework::CachedVid VID68900;
			static NetScriptFramework::CachedVid VID73882;
			static NetScriptFramework::CachedVid VID73884;
			static NetScriptFramework::CachedVid VID74038;
			static NetScriptFramework::CachedVid VID74039;
			static NetScriptFramework::CachedVid VID76160;
			static NetScriptFramework::CachedVid VID76258;
			static NetScriptFramework::CachedVid VID76261;
			static NetScriptFramework::CachedVid VID76539;
			static NetScriptFramework::CachedVid VID79937;
			static NetScriptFramework::CachedVid VID100414;
			static NetScriptFramework::CachedVid VID100419;
			static NetScriptFramework::CachedVid VID227780;
			static NetScriptFramework::CachedVid VID227781;
			static NetScriptFramework::CachedVid VID227783;
			static NetScriptFramework::CachedVid VID227784;
			static NetScriptFramework::CachedVid VID229633;
			static NetScriptFramework::CachedVid VID501132;
			static NetScriptFramework::CachedVid VID501133;
			static NetScriptFramework::CachedVid VID501244;
			static NetScriptFramework::CachedVid VID511989;
			static NetScriptFramework::CachedVid VID514110;
			static NetScriptFramework::CachedVid VID514112;
			static NetScriptFramework::CachedVid VID514141;
			static NetScriptFramework::CachedVid VID514145;
			static NetScriptFramework::CachedVid VID514167;
			static NetScriptFramework::CachedVid VID514178;
			static NetScriptFramework::CachedVid VID514351;
			static NetScriptFramework::CachedVid VID514360;
			static NetScriptFramework::CachedVid VID514642;
			static NetScriptFramework::CachedVid VID514705;
			static NetScriptFramework::CachedVid VID514706;
			static NetScriptFramework::CachedVid VID515124;
			static NetScriptFramework::CachedVid VID515446;
			static NetScriptFramework::CachedVid VID516573;
			static NetScriptFramework::CachedVid VID516574;
			static NetScriptFramework::CachedVid VID516923;
			static NetScriptFramework::CachedVid VID516933;
			static NetScriptFramework::CachedVid VID516943;
			static NetScriptFramework::CachedVid VID517014;
			static NetScriptFramework::CachedVid VID517043;
			static NetScriptFramework::CachedVid VID517228;
			static NetScriptFramework::CachedVid VID519283;
			static NetScriptFramework::CachedVid VID523673;
			static NetScriptFramework::CachedVid VID523909;
			static NetScriptFramework::CachedVid VID524557;
			static NetScriptFramework::CachedVid VID527999;

		private:
			static void _Init1()
			{
				VID10878 = NetScriptFramework::CachedVid::TryInitialize(10878, 0, 0, nullptr);
				VID11275 = NetScriptFramework::CachedVid::TryInitialize(11275, 0, 0, nullptr);
				VID11433 = NetScriptFramework::CachedVid::TryInitialize(11433, 0, 0, nullptr);
				VID11435 = NetScriptFramework::CachedVid::TryInitialize(11435, 0, 0, nullptr);
				VID11436 = NetScriptFramework::CachedVid::TryInitialize(11436, 0, 0, nullptr);
				VID11546 = NetScriptFramework::CachedVid::TryInitialize(11546, 0, 0, nullptr);
				VID12176 = NetScriptFramework::CachedVid::TryInitialize(12176, 0, 0, nullptr);
				VID12192 = NetScriptFramework::CachedVid::TryInitialize(12192, 0, 0, nullptr);
				VID12200 = NetScriptFramework::CachedVid::TryInitialize(12200, 0, 0, nullptr);
				VID12210 = NetScriptFramework::CachedVid::TryInitialize(12210, 0, 0, nullptr);
				VID12229 = NetScriptFramework::CachedVid::TryInitialize(12229, 0, 0, nullptr);
				VID12230 = NetScriptFramework::CachedVid::TryInitialize(12230, 0, 0, nullptr);
				VID12272 = NetScriptFramework::CachedVid::TryInitialize(12272, 0, 0, nullptr);
				VID12275 = NetScriptFramework::CachedVid::TryInitialize(12275, 0, 0, nullptr);
				VID12666 = NetScriptFramework::CachedVid::TryInitialize(12666, 0, 0, nullptr);
				VID13163 = NetScriptFramework::CachedVid::TryInitialize(13163, 0, 0, nullptr);
				VID13549 = NetScriptFramework::CachedVid::TryInitialize(13549, 0, 0, nullptr);
				VID13632 = NetScriptFramework::CachedVid::TryInitialize(13632, 0, 0, nullptr);
				VID13789 = NetScriptFramework::CachedVid::TryInitialize(13789, 0, 0, nullptr);
				VID13882 = NetScriptFramework::CachedVid::TryInitialize(13882, 0, 0, nullptr);
				VID13915 = NetScriptFramework::CachedVid::TryInitialize(13915, 0, 0, nullptr);
				VID14108 = NetScriptFramework::CachedVid::TryInitialize(14108, 0, 0, nullptr);
				VID14125 = NetScriptFramework::CachedVid::TryInitialize(14125, 0, 0, nullptr);
				VID14461 = NetScriptFramework::CachedVid::TryInitialize(14461, 0, 0, nullptr);
				VID14577 = NetScriptFramework::CachedVid::TryInitialize(14577, 0, 0, nullptr);
				VID14799 = NetScriptFramework::CachedVid::TryInitialize(14799, 0, 0, nullptr);
				VID15231 = NetScriptFramework::CachedVid::TryInitialize(15231, 0, 0, nullptr);
				VID15232 = NetScriptFramework::CachedVid::TryInitialize(15232, 0, 0, nullptr);
				VID15713 = NetScriptFramework::CachedVid::TryInitialize(15713, 0, 0, nullptr);
				VID15801 = NetScriptFramework::CachedVid::TryInitialize(15801, 0, 0, nullptr);
				VID15808 = NetScriptFramework::CachedVid::TryInitialize(15808, 0, 0, nullptr);
				VID15873 = NetScriptFramework::CachedVid::TryInitialize(15873, 0, 0, nullptr);
				VID15874 = NetScriptFramework::CachedVid::TryInitialize(15874, 0, 0, nullptr);
				VID16828 = NetScriptFramework::CachedVid::TryInitialize(16828, 0, 0, nullptr);
				VID17693 = NetScriptFramework::CachedVid::TryInitialize(17693, 0, 0, nullptr);
				VID18185 = NetScriptFramework::CachedVid::TryInitialize(18185, 0, 0, nullptr);
				VID18505 = NetScriptFramework::CachedVid::TryInitialize(18505, 0, 0, nullptr);
				VID18524 = NetScriptFramework::CachedVid::TryInitialize(18524, 0, 0, nullptr);
				VID18536 = NetScriptFramework::CachedVid::TryInitialize(18536, 0, 0, nullptr);
				VID19006 = NetScriptFramework::CachedVid::TryInitialize(19006, 0, 0, nullptr);
				VID19369 = NetScriptFramework::CachedVid::TryInitialize(19369, 0, 0, nullptr);
				VID19385 = NetScriptFramework::CachedVid::TryInitialize(19385, 0, 0, nullptr);
				VID19446 = NetScriptFramework::CachedVid::TryInitialize(19446, 0, 0, nullptr);
				VID19818 = NetScriptFramework::CachedVid::TryInitialize(19818, 0, 0, nullptr);
				VID19823 = NetScriptFramework::CachedVid::TryInitialize(19823, 0, 0, nullptr);
				VID20061 = NetScriptFramework::CachedVid::TryInitialize(20061, 0, 0, nullptr);
				VID21343 = NetScriptFramework::CachedVid::TryInitialize(21343, 0, 0, nullptr);
				VID22315 = NetScriptFramework::CachedVid::TryInitialize(22315, 0, 0, nullptr);
				VID23073 = NetScriptFramework::CachedVid::TryInitialize(23073, 0, 0, nullptr);
				VID25980 = NetScriptFramework::CachedVid::TryInitialize(25980, 0, 0, nullptr);
				VID32141 = NetScriptFramework::CachedVid::TryInitialize(32141, 0, 0, nullptr);
				VID32289 = NetScriptFramework::CachedVid::TryInitialize(32289, 0, 0, nullptr);
				VID32290 = NetScriptFramework::CachedVid::TryInitialize(32290, 0, 0, nullptr);
				VID33281 = NetScriptFramework::CachedVid::TryInitialize(33281, 0, 0, nullptr);
				VID33286 = NetScriptFramework::CachedVid::TryInitialize(33286, 0, 0, nullptr);
				VID33362 = NetScriptFramework::CachedVid::TryInitialize(33362, 0, 0, nullptr);
				VID33629 = NetScriptFramework::CachedVid::TryInitialize(33629, 0, 0, nullptr);
				VID33630 = NetScriptFramework::CachedVid::TryInitialize(33630, 0, 0, nullptr);
				VID33726 = NetScriptFramework::CachedVid::TryInitialize(33726, 0, 0, nullptr);
				VID33733 = NetScriptFramework::CachedVid::TryInitialize(33733, 0, 0, nullptr);
				VID33734 = NetScriptFramework::CachedVid::TryInitialize(33734, 0, 0, nullptr);
				VID33736 = NetScriptFramework::CachedVid::TryInitialize(33736, 0, 0, nullptr);
				VID33752 = NetScriptFramework::CachedVid::TryInitialize(33752, 0, 0, nullptr);
				VID35565 = NetScriptFramework::CachedVid::TryInitialize(35565, 0, 0, nullptr);
				VID35984 = NetScriptFramework::CachedVid::TryInitialize(35984, 0, 0, nullptr);
				VID36272 = NetScriptFramework::CachedVid::TryInitialize(36272, 0, 0, nullptr);
				VID36326 = NetScriptFramework::CachedVid::TryInitialize(36326, 0, 0, nullptr);
				VID36429 = NetScriptFramework::CachedVid::TryInitialize(36429, 0, 0, nullptr);
				VID36604 = NetScriptFramework::CachedVid::TryInitialize(36604, 0, 0, nullptr);
				VID36607 = NetScriptFramework::CachedVid::TryInitialize(36607, 0, 0, nullptr);
				VID36727 = NetScriptFramework::CachedVid::TryInitialize(36727, 0, 0, nullptr);
				VID36877 = NetScriptFramework::CachedVid::TryInitialize(36877, 0, 0, nullptr);
				VID37513 = NetScriptFramework::CachedVid::TryInitialize(37513, 0, 0, nullptr);
				VID37596 = NetScriptFramework::CachedVid::TryInitialize(37596, 0, 0, nullptr);
				VID37672 = NetScriptFramework::CachedVid::TryInitialize(37672, 0, 0, nullptr);
				VID37757 = NetScriptFramework::CachedVid::TryInitialize(37757, 0, 0, nullptr);
				VID37758 = NetScriptFramework::CachedVid::TryInitialize(37758, 0, 0, nullptr);
				VID37773 = NetScriptFramework::CachedVid::TryInitialize(37773, 0, 0, nullptr);
				VID37799 = NetScriptFramework::CachedVid::TryInitialize(37799, 0, 0, nullptr);
				VID37808 = NetScriptFramework::CachedVid::TryInitialize(37808, 0, 0, nullptr);
				VID37828 = NetScriptFramework::CachedVid::TryInitialize(37828, 0, 0, nullptr);
				VID37829 = NetScriptFramework::CachedVid::TryInitialize(37829, 0, 0, nullptr);
				VID37864 = NetScriptFramework::CachedVid::TryInitialize(37864, 0, 0, nullptr);
				VID38235 = NetScriptFramework::CachedVid::TryInitialize(38235, 0, 0, nullptr);
				VID38236 = NetScriptFramework::CachedVid::TryInitialize(38236, 0, 0, nullptr);
				VID38375 = NetScriptFramework::CachedVid::TryInitialize(38375, 0, 0, nullptr);
				VID38826 = NetScriptFramework::CachedVid::TryInitialize(38826, 0, 0, nullptr);
				VID38850 = NetScriptFramework::CachedVid::TryInitialize(38850, 0, 0, nullptr);
				VID38852 = NetScriptFramework::CachedVid::TryInitialize(38852, 0, 0, nullptr);
				VID39375 = NetScriptFramework::CachedVid::TryInitialize(39375, 0, 0, nullptr);
				VID40554 = NetScriptFramework::CachedVid::TryInitialize(40554, 0, 0, nullptr);
				VID40555 = NetScriptFramework::CachedVid::TryInitialize(40555, 0, 0, nullptr);
				VID41259 = NetScriptFramework::CachedVid::TryInitialize(41259, 0, 0, nullptr);
				VID41659 = NetScriptFramework::CachedVid::TryInitialize(41659, 0, 0, nullptr);
				VID41778 = NetScriptFramework::CachedVid::TryInitialize(41778, 0, 0, nullptr);
				VID42928 = NetScriptFramework::CachedVid::TryInitialize(42928, 0, 0, nullptr);
				VID49858 = NetScriptFramework::CachedVid::TryInitialize(49858, 0, 0, nullptr);
				VID49863 = NetScriptFramework::CachedVid::TryInitialize(49863, 0, 0, nullptr);
				VID49968 = NetScriptFramework::CachedVid::TryInitialize(49968, 0, 0, nullptr);
				VID49999 = NetScriptFramework::CachedVid::TryInitialize(49999, 0, 0, nullptr);
				VID50066 = NetScriptFramework::CachedVid::TryInitialize(50066, 0, 0, nullptr);
				VID50211 = NetScriptFramework::CachedVid::TryInitialize(50211, 0, 0, nullptr);
				VID51236 = NetScriptFramework::CachedVid::TryInitialize(51236, 0, 0, nullptr);
				VID51324 = NetScriptFramework::CachedVid::TryInitialize(51324, 0, 0, nullptr);
				VID52050 = NetScriptFramework::CachedVid::TryInitialize(52050, 0, 0, nullptr);
				VID53029 = NetScriptFramework::CachedVid::TryInitialize(53029, 0, 0, nullptr);
				VID53761 = NetScriptFramework::CachedVid::TryInitialize(53761, 0, 0, nullptr);
				VID53762 = NetScriptFramework::CachedVid::TryInitialize(53762, 0, 0, nullptr);
				VID53845 = NetScriptFramework::CachedVid::TryInitialize(53845, 0, 0, nullptr);
				VID53846 = NetScriptFramework::CachedVid::TryInitialize(53846, 0, 0, nullptr);
				VID53847 = NetScriptFramework::CachedVid::TryInitialize(53847, 0, 0, nullptr);
				VID53848 = NetScriptFramework::CachedVid::TryInitialize(53848, 0, 0, nullptr);
				VID53852 = NetScriptFramework::CachedVid::TryInitialize(53852, 0, 0, nullptr);
				VID53854 = NetScriptFramework::CachedVid::TryInitialize(53854, 0, 0, nullptr);
				VID53856 = NetScriptFramework::CachedVid::TryInitialize(53856, 0, 0, nullptr);
				VID53858 = NetScriptFramework::CachedVid::TryInitialize(53858, 0, 0, nullptr);
				VID53859 = NetScriptFramework::CachedVid::TryInitialize(53859, 0, 0, nullptr);
				VID53861 = NetScriptFramework::CachedVid::TryInitialize(53861, 0, 0, nullptr);
				VID53862 = NetScriptFramework::CachedVid::TryInitialize(53862, 0, 0, nullptr);
				VID53863 = NetScriptFramework::CachedVid::TryInitialize(53863, 0, 0, nullptr);
				VID53864 = NetScriptFramework::CachedVid::TryInitialize(53864, 0, 0, nullptr);
				VID53870 = NetScriptFramework::CachedVid::TryInitialize(53870, 0, 0, nullptr);
				VID53871 = NetScriptFramework::CachedVid::TryInitialize(53871, 0, 0, nullptr);
				VID53872 = NetScriptFramework::CachedVid::TryInitialize(53872, 0, 0, nullptr);
				VID53873 = NetScriptFramework::CachedVid::TryInitialize(53873, 0, 0, nullptr);
				VID53874 = NetScriptFramework::CachedVid::TryInitialize(53874, 0, 0, nullptr);
				VID53877 = NetScriptFramework::CachedVid::TryInitialize(53877, 0, 0, nullptr);
				VID53878 = NetScriptFramework::CachedVid::TryInitialize(53878, 0, 0, nullptr);
				VID53879 = NetScriptFramework::CachedVid::TryInitialize(53879, 0, 0, nullptr);
				VID53880 = NetScriptFramework::CachedVid::TryInitialize(53880, 0, 0, nullptr);
				VID53881 = NetScriptFramework::CachedVid::TryInitialize(53881, 0, 0, nullptr);
				VID53882 = NetScriptFramework::CachedVid::TryInitialize(53882, 0, 0, nullptr);
				VID53883 = NetScriptFramework::CachedVid::TryInitialize(53883, 0, 0, nullptr);
				VID53884 = NetScriptFramework::CachedVid::TryInitialize(53884, 0, 0, nullptr);
				VID53885 = NetScriptFramework::CachedVid::TryInitialize(53885, 0, 0, nullptr);
				VID53886 = NetScriptFramework::CachedVid::TryInitialize(53886, 0, 0, nullptr);
				VID53888 = NetScriptFramework::CachedVid::TryInitialize(53888, 0, 0, nullptr);
				VID53889 = NetScriptFramework::CachedVid::TryInitialize(53889, 0, 0, nullptr);
				VID53890 = NetScriptFramework::CachedVid::TryInitialize(53890, 0, 0, nullptr);
				VID53891 = NetScriptFramework::CachedVid::TryInitialize(53891, 0, 0, nullptr);
				VID53892 = NetScriptFramework::CachedVid::TryInitialize(53892, 0, 0, nullptr);
				VID53893 = NetScriptFramework::CachedVid::TryInitialize(53893, 0, 0, nullptr);
				VID53894 = NetScriptFramework::CachedVid::TryInitialize(53894, 0, 0, nullptr);
				VID53895 = NetScriptFramework::CachedVid::TryInitialize(53895, 0, 0, nullptr);
				VID53896 = NetScriptFramework::CachedVid::TryInitialize(53896, 0, 0, nullptr);
				VID53898 = NetScriptFramework::CachedVid::TryInitialize(53898, 0, 0, nullptr);
				VID53899 = NetScriptFramework::CachedVid::TryInitialize(53899, 0, 0, nullptr);
				VID53900 = NetScriptFramework::CachedVid::TryInitialize(53900, 0, 0, nullptr);
				VID53914 = NetScriptFramework::CachedVid::TryInitialize(53914, 0, 0, nullptr);
				VID53919 = NetScriptFramework::CachedVid::TryInitialize(53919, 0, 0, nullptr);
				VID53922 = NetScriptFramework::CachedVid::TryInitialize(53922, 0, 0, nullptr);
				VID53923 = NetScriptFramework::CachedVid::TryInitialize(53923, 0, 0, nullptr);
				VID53924 = NetScriptFramework::CachedVid::TryInitialize(53924, 0, 0, nullptr);
				VID53929 = NetScriptFramework::CachedVid::TryInitialize(53929, 0, 0, nullptr);
				VID53930 = NetScriptFramework::CachedVid::TryInitialize(53930, 0, 0, nullptr);
				VID53931 = NetScriptFramework::CachedVid::TryInitialize(53931, 0, 0, nullptr);
				VID53932 = NetScriptFramework::CachedVid::TryInitialize(53932, 0, 0, nullptr);
				VID53933 = NetScriptFramework::CachedVid::TryInitialize(53933, 0, 0, nullptr);
				VID53934 = NetScriptFramework::CachedVid::TryInitialize(53934, 0, 0, nullptr);
				VID53935 = NetScriptFramework::CachedVid::TryInitialize(53935, 0, 0, nullptr);
				VID53936 = NetScriptFramework::CachedVid::TryInitialize(53936, 0, 0, nullptr);
				VID53937 = NetScriptFramework::CachedVid::TryInitialize(53937, 0, 0, nullptr);
				VID53939 = NetScriptFramework::CachedVid::TryInitialize(53939, 0, 0, nullptr);
				VID53940 = NetScriptFramework::CachedVid::TryInitialize(53940, 0, 0, nullptr);
				VID53941 = NetScriptFramework::CachedVid::TryInitialize(53941, 0, 0, nullptr);
				VID53946 = NetScriptFramework::CachedVid::TryInitialize(53946, 0, 0, nullptr);
				VID53947 = NetScriptFramework::CachedVid::TryInitialize(53947, 0, 0, nullptr);
				VID53948 = NetScriptFramework::CachedVid::TryInitialize(53948, 0, 0, nullptr);
				VID53949 = NetScriptFramework::CachedVid::TryInitialize(53949, 0, 0, nullptr);
				VID53950 = NetScriptFramework::CachedVid::TryInitialize(53950, 0, 0, nullptr);
				VID53952 = NetScriptFramework::CachedVid::TryInitialize(53952, 0, 0, nullptr);
				VID53954 = NetScriptFramework::CachedVid::TryInitialize(53954, 0, 0, nullptr);
				VID53955 = NetScriptFramework::CachedVid::TryInitialize(53955, 0, 0, nullptr);
				VID53956 = NetScriptFramework::CachedVid::TryInitialize(53956, 0, 0, nullptr);
				VID53957 = NetScriptFramework::CachedVid::TryInitialize(53957, 0, 0, nullptr);
				VID54119 = NetScriptFramework::CachedVid::TryInitialize(54119, 0, 0, nullptr);
				VID54120 = NetScriptFramework::CachedVid::TryInitialize(54120, 0, 0, nullptr);
				VID54121 = NetScriptFramework::CachedVid::TryInitialize(54121, 0, 0, nullptr);
				VID54122 = NetScriptFramework::CachedVid::TryInitialize(54122, 0, 0, nullptr);
				VID54123 = NetScriptFramework::CachedVid::TryInitialize(54123, 0, 0, nullptr);
				VID54124 = NetScriptFramework::CachedVid::TryInitialize(54124, 0, 0, nullptr);
				VID54125 = NetScriptFramework::CachedVid::TryInitialize(54125, 0, 0, nullptr);
				VID54126 = NetScriptFramework::CachedVid::TryInitialize(54126, 0, 0, nullptr);
				VID54127 = NetScriptFramework::CachedVid::TryInitialize(54127, 0, 0, nullptr);
				VID54128 = NetScriptFramework::CachedVid::TryInitialize(54128, 0, 0, nullptr);
				VID54129 = NetScriptFramework::CachedVid::TryInitialize(54129, 0, 0, nullptr);
				VID54130 = NetScriptFramework::CachedVid::TryInitialize(54130, 0, 0, nullptr);
				VID54131 = NetScriptFramework::CachedVid::TryInitialize(54131, 0, 0, nullptr);
				VID54132 = NetScriptFramework::CachedVid::TryInitialize(54132, 0, 0, nullptr);
				VID54133 = NetScriptFramework::CachedVid::TryInitialize(54133, 0, 0, nullptr);
				VID54135 = NetScriptFramework::CachedVid::TryInitialize(54135, 0, 0, nullptr);
				VID54136 = NetScriptFramework::CachedVid::TryInitialize(54136, 0, 0, nullptr);
				VID54137 = NetScriptFramework::CachedVid::TryInitialize(54137, 0, 0, nullptr);
				VID54139 = NetScriptFramework::CachedVid::TryInitialize(54139, 0, 0, nullptr);
				VID54140 = NetScriptFramework::CachedVid::TryInitialize(54140, 0, 0, nullptr);
				VID54141 = NetScriptFramework::CachedVid::TryInitialize(54141, 0, 0, nullptr);
				VID54142 = NetScriptFramework::CachedVid::TryInitialize(54142, 0, 0, nullptr);
				VID54143 = NetScriptFramework::CachedVid::TryInitialize(54143, 0, 0, nullptr);
				VID54144 = NetScriptFramework::CachedVid::TryInitialize(54144, 0, 0, nullptr);
				VID54145 = NetScriptFramework::CachedVid::TryInitialize(54145, 0, 0, nullptr);
				VID54146 = NetScriptFramework::CachedVid::TryInitialize(54146, 0, 0, nullptr);
				VID54147 = NetScriptFramework::CachedVid::TryInitialize(54147, 0, 0, nullptr);
				VID54148 = NetScriptFramework::CachedVid::TryInitialize(54148, 0, 0, nullptr);
				VID54149 = NetScriptFramework::CachedVid::TryInitialize(54149, 0, 0, nullptr);
				VID54150 = NetScriptFramework::CachedVid::TryInitialize(54150, 0, 0, nullptr);
				VID54151 = NetScriptFramework::CachedVid::TryInitialize(54151, 0, 0, nullptr);
				VID54152 = NetScriptFramework::CachedVid::TryInitialize(54152, 0, 0, nullptr);
				VID54153 = NetScriptFramework::CachedVid::TryInitialize(54153, 0, 0, nullptr);
				VID54154 = NetScriptFramework::CachedVid::TryInitialize(54154, 0, 0, nullptr);
				VID54155 = NetScriptFramework::CachedVid::TryInitialize(54155, 0, 0, nullptr);
				VID54156 = NetScriptFramework::CachedVid::TryInitialize(54156, 0, 0, nullptr);
				VID54157 = NetScriptFramework::CachedVid::TryInitialize(54157, 0, 0, nullptr);
				VID54158 = NetScriptFramework::CachedVid::TryInitialize(54158, 0, 0, nullptr);
				VID54159 = NetScriptFramework::CachedVid::TryInitialize(54159, 0, 0, nullptr);
				VID54160 = NetScriptFramework::CachedVid::TryInitialize(54160, 0, 0, nullptr);
				VID54161 = NetScriptFramework::CachedVid::TryInitialize(54161, 0, 0, nullptr);
				VID54162 = NetScriptFramework::CachedVid::TryInitialize(54162, 0, 0, nullptr);
				VID54163 = NetScriptFramework::CachedVid::TryInitialize(54163, 0, 0, nullptr);
				VID54164 = NetScriptFramework::CachedVid::TryInitialize(54164, 0, 0, nullptr);
				VID54165 = NetScriptFramework::CachedVid::TryInitialize(54165, 0, 0, nullptr);
				VID54166 = NetScriptFramework::CachedVid::TryInitialize(54166, 0, 0, nullptr);
				VID54167 = NetScriptFramework::CachedVid::TryInitialize(54167, 0, 0, nullptr);
				VID54168 = NetScriptFramework::CachedVid::TryInitialize(54168, 0, 0, nullptr);
				VID54169 = NetScriptFramework::CachedVid::TryInitialize(54169, 0, 0, nullptr);
				VID54170 = NetScriptFramework::CachedVid::TryInitialize(54170, 0, 0, nullptr);
				VID54171 = NetScriptFramework::CachedVid::TryInitialize(54171, 0, 0, nullptr);
				VID54172 = NetScriptFramework::CachedVid::TryInitialize(54172, 0, 0, nullptr);
				VID54173 = NetScriptFramework::CachedVid::TryInitialize(54173, 0, 0, nullptr);
				VID54174 = NetScriptFramework::CachedVid::TryInitialize(54174, 0, 0, nullptr);
				VID54175 = NetScriptFramework::CachedVid::TryInitialize(54175, 0, 0, nullptr);
				VID54632 = NetScriptFramework::CachedVid::TryInitialize(54632, 0, 0, nullptr);
				VID54633 = NetScriptFramework::CachedVid::TryInitialize(54633, 0, 0, nullptr);
				VID54634 = NetScriptFramework::CachedVid::TryInitialize(54634, 0, 0, nullptr);
				VID55187 = NetScriptFramework::CachedVid::TryInitialize(55187, 0, 0, nullptr);
				VID55288 = NetScriptFramework::CachedVid::TryInitialize(55288, 0, 0, nullptr);
				VID55289 = NetScriptFramework::CachedVid::TryInitialize(55289, 0, 0, nullptr);
				VID55369 = NetScriptFramework::CachedVid::TryInitialize(55369, 0, 0, nullptr);
				VID55527 = NetScriptFramework::CachedVid::TryInitialize(55527, 0, 0, nullptr);
				VID55528 = NetScriptFramework::CachedVid::TryInitialize(55528, 0, 0, nullptr);
				VID56364 = NetScriptFramework::CachedVid::TryInitialize(56364, 0, 0, nullptr);
				VID61531 = NetScriptFramework::CachedVid::TryInitialize(61531, 0, 0, nullptr);
				VID66391 = NetScriptFramework::CachedVid::TryInitialize(66391, 0, 0, nullptr);
				VID66859 = NetScriptFramework::CachedVid::TryInitialize(66859, 0, 0, nullptr);
				VID66861 = NetScriptFramework::CachedVid::TryInitialize(66861, 0, 0, nullptr);
				VID66862 = NetScriptFramework::CachedVid::TryInitialize(66862, 0, 0, nullptr);
				VID66976 = NetScriptFramework::CachedVid::TryInitialize(66976, 0, 0, nullptr);
				VID66977 = NetScriptFramework::CachedVid::TryInitialize(66977, 0, 0, nullptr);
				VID66982 = NetScriptFramework::CachedVid::TryInitialize(66982, 0, 0, nullptr);
				VID66983 = NetScriptFramework::CachedVid::TryInitialize(66983, 0, 0, nullptr);
				VID67819 = NetScriptFramework::CachedVid::TryInitialize(67819, 0, 0, nullptr);
				VID67822 = NetScriptFramework::CachedVid::TryInitialize(67822, 0, 0, nullptr);
				VID67991 = NetScriptFramework::CachedVid::TryInitialize(67991, 0, 0, nullptr);
				VID67992 = NetScriptFramework::CachedVid::TryInitialize(67992, 0, 0, nullptr);
				VID68836 = NetScriptFramework::CachedVid::TryInitialize(68836, 0, 0, nullptr);
				VID68900 = NetScriptFramework::CachedVid::TryInitialize(68900, 0, 0, nullptr);
				VID73882 = NetScriptFramework::CachedVid::TryInitialize(73882, 0, 0, nullptr);
				VID73884 = NetScriptFramework::CachedVid::TryInitialize(73884, 0, 0, nullptr);
				VID74038 = NetScriptFramework::CachedVid::TryInitialize(74038, 0, 0, nullptr);
				VID74039 = NetScriptFramework::CachedVid::TryInitialize(74039, 0, 0, nullptr);
				VID76160 = NetScriptFramework::CachedVid::TryInitialize(76160, 0, 0, nullptr);
				VID76258 = NetScriptFramework::CachedVid::TryInitialize(76258, 0, 0, nullptr);
				VID76261 = NetScriptFramework::CachedVid::TryInitialize(76261, 0, 0, nullptr);
				VID76539 = NetScriptFramework::CachedVid::TryInitialize(76539, 0, 0, nullptr);
				VID79937 = NetScriptFramework::CachedVid::TryInitialize(79937, 0, 0, nullptr);
				VID100414 = NetScriptFramework::CachedVid::TryInitialize(100414, 0, 0, nullptr);
				VID100419 = NetScriptFramework::CachedVid::TryInitialize(100419, 0, 0, nullptr);
				VID227780 = NetScriptFramework::CachedVid::TryInitialize(227780, 0, 0, nullptr);
				VID227781 = NetScriptFramework::CachedVid::TryInitialize(227781, 0, 0, nullptr);
				VID227783 = NetScriptFramework::CachedVid::TryInitialize(227783, 0, 0, nullptr);
				VID227784 = NetScriptFramework::CachedVid::TryInitialize(227784, 0, 0, nullptr);
				VID229633 = NetScriptFramework::CachedVid::TryInitialize(229633, 0, 0, nullptr);
				VID501132 = NetScriptFramework::CachedVid::TryInitialize(501132, 0, 0, nullptr);
				VID501133 = NetScriptFramework::CachedVid::TryInitialize(501133, 0, 0, nullptr);
				VID501244 = NetScriptFramework::CachedVid::TryInitialize(501244, 0, 0, nullptr);
				VID511989 = NetScriptFramework::CachedVid::TryInitialize(511989, 0, 0, nullptr);
				VID514110 = NetScriptFramework::CachedVid::TryInitialize(514110, 0, 0, nullptr);
				VID514112 = NetScriptFramework::CachedVid::TryInitialize(514112, 0, 0, nullptr);
				VID514141 = NetScriptFramework::CachedVid::TryInitialize(514141, 0, 0, nullptr);
				VID514145 = NetScriptFramework::CachedVid::TryInitialize(514145, 0, 0, nullptr);
				VID514167 = NetScriptFramework::CachedVid::TryInitialize(514167, 0, 0, nullptr);
				VID514178 = NetScriptFramework::CachedVid::TryInitialize(514178, 0, 0, nullptr);
				VID514351 = NetScriptFramework::CachedVid::TryInitialize(514351, 0, 0, nullptr);
				VID514360 = NetScriptFramework::CachedVid::TryInitialize(514360, 0, 0, nullptr);
				VID514642 = NetScriptFramework::CachedVid::TryInitialize(514642, 0, 0, nullptr);
				VID514705 = NetScriptFramework::CachedVid::TryInitialize(514705, 0, 0, nullptr);
				VID514706 = NetScriptFramework::CachedVid::TryInitialize(514706, 0, 0, nullptr);
				VID515124 = NetScriptFramework::CachedVid::TryInitialize(515124, 0, 0, nullptr);
				VID515446 = NetScriptFramework::CachedVid::TryInitialize(515446, 0, 0, nullptr);
				VID516573 = NetScriptFramework::CachedVid::TryInitialize(516573, 0, 0, nullptr);
				VID516574 = NetScriptFramework::CachedVid::TryInitialize(516574, 0, 0, nullptr);
				VID516923 = NetScriptFramework::CachedVid::TryInitialize(516923, 0, 0, nullptr);
				VID516933 = NetScriptFramework::CachedVid::TryInitialize(516933, 0, 0, nullptr);
				VID516943 = NetScriptFramework::CachedVid::TryInitialize(516943, 0, 0, nullptr);
				VID517014 = NetScriptFramework::CachedVid::TryInitialize(517014, 0, 0, nullptr);
				VID517043 = NetScriptFramework::CachedVid::TryInitialize(517043, 0, 0, nullptr);
				VID517228 = NetScriptFramework::CachedVid::TryInitialize(517228, 0, 0, nullptr);
				VID519283 = NetScriptFramework::CachedVid::TryInitialize(519283, 0, 0, nullptr);
				VID523673 = NetScriptFramework::CachedVid::TryInitialize(523673, 0, 0, nullptr);
				VID523909 = NetScriptFramework::CachedVid::TryInitialize(523909, 0, 0, nullptr);
				VID524557 = NetScriptFramework::CachedVid::TryInitialize(524557, 0, 0, nullptr);
				VID527999 = NetScriptFramework::CachedVid::TryInitialize(527999, 0, 0, nullptr);
			}

		internal:
			static void Init()
			{
				_Init1();
			}
		};

		/// <summary>
		/// Contains cached version specific values.
		/// </summary>
		public ref class __CVTS sealed abstract
		{
		public:
			static NetScriptFramework::CachedLibValue CVT0;
			static NetScriptFramework::CachedLibValue CVT1;
			static NetScriptFramework::CachedLibValue CVT2;
			static NetScriptFramework::CachedLibValue CVT3;
			static NetScriptFramework::CachedLibValue CVT4;
			static NetScriptFramework::CachedLibValue CVT5;
			static NetScriptFramework::CachedLibValue CVT6;
			static NetScriptFramework::CachedLibValue CVT7;
			static NetScriptFramework::CachedLibValue CVT8;
			static NetScriptFramework::CachedLibValue CVT9;
			static NetScriptFramework::CachedLibValue CVT10;
			static NetScriptFramework::CachedLibValue CVT11;
			static NetScriptFramework::CachedLibValue CVT12;
			static NetScriptFramework::CachedLibValue CVT13;
			static NetScriptFramework::CachedLibValue CVT14;
			static NetScriptFramework::CachedLibValue CVT15;
			static NetScriptFramework::CachedLibValue CVT16;
			static NetScriptFramework::CachedLibValue CVT17;
			static NetScriptFramework::CachedLibValue CVT18;
			static NetScriptFramework::CachedLibValue CVT19;
			static NetScriptFramework::CachedLibValue CVT20;
			static NetScriptFramework::CachedLibValue CVT21;
			static NetScriptFramework::CachedLibValue CVT22;
			static NetScriptFramework::CachedLibValue CVT23;
			static NetScriptFramework::CachedLibValue CVT24;
			static NetScriptFramework::CachedLibValue CVT25;
			static NetScriptFramework::CachedLibValue CVT26;
			static NetScriptFramework::CachedLibValue CVT27;
			static NetScriptFramework::CachedLibValue CVT28;
			static NetScriptFramework::CachedLibValue CVT29;
			static NetScriptFramework::CachedLibValue CVT30;
			static NetScriptFramework::CachedLibValue CVT31;
			static NetScriptFramework::CachedLibValue CVT32;
			static NetScriptFramework::CachedLibValue CVT33;
			static NetScriptFramework::CachedLibValue CVT34;
			static NetScriptFramework::CachedLibValue CVT35;
			static NetScriptFramework::CachedLibValue CVT36;
			static NetScriptFramework::CachedLibValue CVT37;
			static NetScriptFramework::CachedLibValue CVT38;
			static NetScriptFramework::CachedLibValue CVT39;
			static NetScriptFramework::CachedLibValue CVT40;
			static NetScriptFramework::CachedLibValue CVT41;
			static NetScriptFramework::CachedLibValue CVT42;
			static NetScriptFramework::CachedLibValue CVT43;
			static NetScriptFramework::CachedLibValue CVT44;
			static NetScriptFramework::CachedLibValue CVT45;
			static NetScriptFramework::CachedLibValue CVT46;
			static NetScriptFramework::CachedLibValue CVT47;
			static NetScriptFramework::CachedLibValue CVT48;
			static NetScriptFramework::CachedLibValue CVT49;
			static NetScriptFramework::CachedLibValue CVT50;
			static NetScriptFramework::CachedLibValue CVT51;
			static NetScriptFramework::CachedLibValue CVT52;
			static NetScriptFramework::CachedLibValue CVT53;
			static NetScriptFramework::CachedLibValue CVT54;
			static NetScriptFramework::CachedLibValue CVT55;
			static NetScriptFramework::CachedLibValue CVT56;
			static NetScriptFramework::CachedLibValue CVT57;
			static NetScriptFramework::CachedLibValue CVT58;
			static NetScriptFramework::CachedLibValue CVT59;
			static NetScriptFramework::CachedLibValue CVT60;
			static NetScriptFramework::CachedLibValue CVT61;
			static NetScriptFramework::CachedLibValue CVT62;
			static NetScriptFramework::CachedLibValue CVT63;
			static NetScriptFramework::CachedLibValue CVT64;
			static NetScriptFramework::CachedLibValue CVT65;
			static NetScriptFramework::CachedLibValue CVT66;
			static NetScriptFramework::CachedLibValue CVT67;
			static NetScriptFramework::CachedLibValue CVT68;
			static NetScriptFramework::CachedLibValue CVT69;
			static NetScriptFramework::CachedLibValue CVT70;
			static NetScriptFramework::CachedLibValue CVT71;
			static NetScriptFramework::CachedLibValue CVT72;
			static NetScriptFramework::CachedLibValue CVT73;
			static NetScriptFramework::CachedLibValue CVT74;
			static NetScriptFramework::CachedLibValue CVT75;
			static NetScriptFramework::CachedLibValue CVT76;
			static NetScriptFramework::CachedLibValue CVT77;
			static NetScriptFramework::CachedLibValue CVT78;
			static NetScriptFramework::CachedLibValue CVT79;
			static NetScriptFramework::CachedLibValue CVT80;
			static NetScriptFramework::CachedLibValue CVT81;
			static NetScriptFramework::CachedLibValue CVT82;
			static NetScriptFramework::CachedLibValue CVT83;
			static NetScriptFramework::CachedLibValue CVT84;
			static NetScriptFramework::CachedLibValue CVT85;
			static NetScriptFramework::CachedLibValue CVT86;
			static NetScriptFramework::CachedLibValue CVT87;
			static NetScriptFramework::CachedLibValue CVT88;
			static NetScriptFramework::CachedLibValue CVT89;
			static NetScriptFramework::CachedLibValue CVT90;
			static NetScriptFramework::CachedLibValue CVT91;
			static NetScriptFramework::CachedLibValue CVT92;
			static NetScriptFramework::CachedLibValue CVT93;
			static NetScriptFramework::CachedLibValue CVT94;
			static NetScriptFramework::CachedLibValue CVT95;
			static NetScriptFramework::CachedLibValue CVT96;
			static NetScriptFramework::CachedLibValue CVT97;
			static NetScriptFramework::CachedLibValue CVT98;
			static NetScriptFramework::CachedLibValue CVT99;
			static NetScriptFramework::CachedLibValue CVT100;
			static NetScriptFramework::CachedLibValue CVT101;
			static NetScriptFramework::CachedLibValue CVT102;
			static NetScriptFramework::CachedLibValue CVT103;
			static NetScriptFramework::CachedLibValue CVT104;
			static NetScriptFramework::CachedLibValue CVT105;
			static NetScriptFramework::CachedLibValue CVT106;
			static NetScriptFramework::CachedLibValue CVT107;
			static NetScriptFramework::CachedLibValue CVT108;
			static NetScriptFramework::CachedLibValue CVT109;
			static NetScriptFramework::CachedLibValue CVT110;
			static NetScriptFramework::CachedLibValue CVT111;
			static NetScriptFramework::CachedLibValue CVT112;
			static NetScriptFramework::CachedLibValue CVT113;
			static NetScriptFramework::CachedLibValue CVT114;
			static NetScriptFramework::CachedLibValue CVT115;
			static NetScriptFramework::CachedLibValue CVT116;
			static NetScriptFramework::CachedLibValue CVT117;
			static NetScriptFramework::CachedLibValue CVT118;
			static NetScriptFramework::CachedLibValue CVT119;
			static NetScriptFramework::CachedLibValue CVT120;
			static NetScriptFramework::CachedLibValue CVT121;
			static NetScriptFramework::CachedLibValue CVT122;
			static NetScriptFramework::CachedLibValue CVT123;
			static NetScriptFramework::CachedLibValue CVT124;
			static NetScriptFramework::CachedLibValue CVT125;
			static NetScriptFramework::CachedLibValue CVT126;
			static NetScriptFramework::CachedLibValue CVT127;
			static NetScriptFramework::CachedLibValue CVT128;
			static NetScriptFramework::CachedLibValue CVT129;
			static NetScriptFramework::CachedLibValue CVT130;
			static NetScriptFramework::CachedLibValue CVT131;
			static NetScriptFramework::CachedLibValue CVT132;
			static NetScriptFramework::CachedLibValue CVT133;
			static NetScriptFramework::CachedLibValue CVT134;
			static NetScriptFramework::CachedLibValue CVT135;
			static NetScriptFramework::CachedLibValue CVT136;
			static NetScriptFramework::CachedLibValue CVT137;
			static NetScriptFramework::CachedLibValue CVT138;
			static NetScriptFramework::CachedLibValue CVT139;
			static NetScriptFramework::CachedLibValue CVT140;
			static NetScriptFramework::CachedLibValue CVT141;
			static NetScriptFramework::CachedLibValue CVT142;
			static NetScriptFramework::CachedLibValue CVT143;
			static NetScriptFramework::CachedLibValue CVT144;
			static NetScriptFramework::CachedLibValue CVT145;
			static NetScriptFramework::CachedLibValue CVT146;
			static NetScriptFramework::CachedLibValue CVT147;
			static NetScriptFramework::CachedLibValue CVT148;
			static NetScriptFramework::CachedLibValue CVT149;
			static NetScriptFramework::CachedLibValue CVT150;
			static NetScriptFramework::CachedLibValue CVT151;
			static NetScriptFramework::CachedLibValue CVT152;
			static NetScriptFramework::CachedLibValue CVT153;
			static NetScriptFramework::CachedLibValue CVT154;
			static NetScriptFramework::CachedLibValue CVT155;
			static NetScriptFramework::CachedLibValue CVT156;
			static NetScriptFramework::CachedLibValue CVT157;
			static NetScriptFramework::CachedLibValue CVT158;
			static NetScriptFramework::CachedLibValue CVT159;
			static NetScriptFramework::CachedLibValue CVT160;
			static NetScriptFramework::CachedLibValue CVT161;
			static NetScriptFramework::CachedLibValue CVT162;
			static NetScriptFramework::CachedLibValue CVT163;
			static NetScriptFramework::CachedLibValue CVT164;
			static NetScriptFramework::CachedLibValue CVT165;
			static NetScriptFramework::CachedLibValue CVT166;
			static NetScriptFramework::CachedLibValue CVT167;
			static NetScriptFramework::CachedLibValue CVT168;
			static NetScriptFramework::CachedLibValue CVT169;
			static NetScriptFramework::CachedLibValue CVT170;
			static NetScriptFramework::CachedLibValue CVT171;
			static NetScriptFramework::CachedLibValue CVT172;
			static NetScriptFramework::CachedLibValue CVT173;
			static NetScriptFramework::CachedLibValue CVT174;
			static NetScriptFramework::CachedLibValue CVT175;
			static NetScriptFramework::CachedLibValue CVT176;
			static NetScriptFramework::CachedLibValue CVT177;
			static NetScriptFramework::CachedLibValue CVT178;
			static NetScriptFramework::CachedLibValue CVT179;
			static NetScriptFramework::CachedLibValue CVT180;
			static NetScriptFramework::CachedLibValue CVT181;
			static NetScriptFramework::CachedLibValue CVT182;
			static NetScriptFramework::CachedLibValue CVT183;
			static NetScriptFramework::CachedLibValue CVT184;
			static NetScriptFramework::CachedLibValue CVT185;
			static NetScriptFramework::CachedLibValue CVT186;
			static NetScriptFramework::CachedLibValue CVT187;
			static NetScriptFramework::CachedLibValue CVT188;
			static NetScriptFramework::CachedLibValue CVT189;
			static NetScriptFramework::CachedLibValue CVT190;
			static NetScriptFramework::CachedLibValue CVT191;
			static NetScriptFramework::CachedLibValue CVT192;
			static NetScriptFramework::CachedLibValue CVT193;
			static NetScriptFramework::CachedLibValue CVT194;
			static NetScriptFramework::CachedLibValue CVT195;
			static NetScriptFramework::CachedLibValue CVT196;
			static NetScriptFramework::CachedLibValue CVT197;
			static NetScriptFramework::CachedLibValue CVT198;
			static NetScriptFramework::CachedLibValue CVT199;
			static NetScriptFramework::CachedLibValue CVT200;
			static NetScriptFramework::CachedLibValue CVT201;
			static NetScriptFramework::CachedLibValue CVT202;
			static NetScriptFramework::CachedLibValue CVT203;
			static NetScriptFramework::CachedLibValue CVT204;
			static NetScriptFramework::CachedLibValue CVT205;
			static NetScriptFramework::CachedLibValue CVT206;
			static NetScriptFramework::CachedLibValue CVT207;
			static NetScriptFramework::CachedLibValue CVT208;
			static NetScriptFramework::CachedLibValue CVT209;
			static NetScriptFramework::CachedLibValue CVT210;
			static NetScriptFramework::CachedLibValue CVT211;
			static NetScriptFramework::CachedLibValue CVT212;
			static NetScriptFramework::CachedLibValue CVT213;
			static NetScriptFramework::CachedLibValue CVT214;
			static NetScriptFramework::CachedLibValue CVT215;
			static NetScriptFramework::CachedLibValue CVT216;
			static NetScriptFramework::CachedLibValue CVT217;
			static NetScriptFramework::CachedLibValue CVT218;
			static NetScriptFramework::CachedLibValue CVT219;
			static NetScriptFramework::CachedLibValue CVT220;
			static NetScriptFramework::CachedLibValue CVT221;
			static NetScriptFramework::CachedLibValue CVT222;
			static NetScriptFramework::CachedLibValue CVT223;
			static NetScriptFramework::CachedLibValue CVT224;
			static NetScriptFramework::CachedLibValue CVT225;
			static NetScriptFramework::CachedLibValue CVT226;
			static NetScriptFramework::CachedLibValue CVT227;
			static NetScriptFramework::CachedLibValue CVT228;
			static NetScriptFramework::CachedLibValue CVT229;
			static NetScriptFramework::CachedLibValue CVT230;
			static NetScriptFramework::CachedLibValue CVT231;
			static NetScriptFramework::CachedLibValue CVT232;
			static NetScriptFramework::CachedLibValue CVT233;
			static NetScriptFramework::CachedLibValue CVT234;
			static NetScriptFramework::CachedLibValue CVT235;
			static NetScriptFramework::CachedLibValue CVT236;
			static NetScriptFramework::CachedLibValue CVT237;
			static NetScriptFramework::CachedLibValue CVT238;
			static NetScriptFramework::CachedLibValue CVT239;
			static NetScriptFramework::CachedLibValue CVT240;
			static NetScriptFramework::CachedLibValue CVT241;
			static NetScriptFramework::CachedLibValue CVT242;
			static NetScriptFramework::CachedLibValue CVT243;
			static NetScriptFramework::CachedLibValue CVT244;
			static NetScriptFramework::CachedLibValue CVT245;
			static NetScriptFramework::CachedLibValue CVT246;
			static NetScriptFramework::CachedLibValue CVT247;
			static NetScriptFramework::CachedLibValue CVT248;
			static NetScriptFramework::CachedLibValue CVT249;
			static NetScriptFramework::CachedLibValue CVT250;
			static NetScriptFramework::CachedLibValue CVT251;
			static NetScriptFramework::CachedLibValue CVT252;
			static NetScriptFramework::CachedLibValue CVT253;
			static NetScriptFramework::CachedLibValue CVT254;
			static NetScriptFramework::CachedLibValue CVT255;
			static NetScriptFramework::CachedLibValue CVT256;
			static NetScriptFramework::CachedLibValue CVT257;
			static NetScriptFramework::CachedLibValue CVT258;
			static NetScriptFramework::CachedLibValue CVT259;
			static NetScriptFramework::CachedLibValue CVT260;
			static NetScriptFramework::CachedLibValue CVT261;
			static NetScriptFramework::CachedLibValue CVT262;
			static NetScriptFramework::CachedLibValue CVT263;
			static NetScriptFramework::CachedLibValue CVT264;
			static NetScriptFramework::CachedLibValue CVT265;
			static NetScriptFramework::CachedLibValue CVT266;
			static NetScriptFramework::CachedLibValue CVT267;
			static NetScriptFramework::CachedLibValue CVT268;
			static NetScriptFramework::CachedLibValue CVT269;
			static NetScriptFramework::CachedLibValue CVT270;
			static NetScriptFramework::CachedLibValue CVT271;
			static NetScriptFramework::CachedLibValue CVT272;
			static NetScriptFramework::CachedLibValue CVT273;
			static NetScriptFramework::CachedLibValue CVT274;
			static NetScriptFramework::CachedLibValue CVT275;
			static NetScriptFramework::CachedLibValue CVT276;
			static NetScriptFramework::CachedLibValue CVT277;
			static NetScriptFramework::CachedLibValue CVT278;
			static NetScriptFramework::CachedLibValue CVT279;
			static NetScriptFramework::CachedLibValue CVT280;
			static NetScriptFramework::CachedLibValue CVT281;
			static NetScriptFramework::CachedLibValue CVT282;
			static NetScriptFramework::CachedLibValue CVT283;
			static NetScriptFramework::CachedLibValue CVT284;
			static NetScriptFramework::CachedLibValue CVT285;
			static NetScriptFramework::CachedLibValue CVT286;
			static NetScriptFramework::CachedLibValue CVT287;
			static NetScriptFramework::CachedLibValue CVT288;
			static NetScriptFramework::CachedLibValue CVT289;
			static NetScriptFramework::CachedLibValue CVT290;
			static NetScriptFramework::CachedLibValue CVT291;
			static NetScriptFramework::CachedLibValue CVT292;
			static NetScriptFramework::CachedLibValue CVT293;
			static NetScriptFramework::CachedLibValue CVT294;
			static NetScriptFramework::CachedLibValue CVT295;
			static NetScriptFramework::CachedLibValue CVT296;
			static NetScriptFramework::CachedLibValue CVT297;
			static NetScriptFramework::CachedLibValue CVT298;
			static NetScriptFramework::CachedLibValue CVT299;
			static NetScriptFramework::CachedLibValue CVT300;
			static NetScriptFramework::CachedLibValue CVT301;
			static NetScriptFramework::CachedLibValue CVT302;
			static NetScriptFramework::CachedLibValue CVT303;
			static NetScriptFramework::CachedLibValue CVT304;
			static NetScriptFramework::CachedLibValue CVT305;
			static NetScriptFramework::CachedLibValue CVT306;
			static NetScriptFramework::CachedLibValue CVT307;
			static NetScriptFramework::CachedLibValue CVT308;
			static NetScriptFramework::CachedLibValue CVT309;
			static NetScriptFramework::CachedLibValue CVT310;
			static NetScriptFramework::CachedLibValue CVT311;
			static NetScriptFramework::CachedLibValue CVT312;
			static NetScriptFramework::CachedLibValue CVT313;
			static NetScriptFramework::CachedLibValue CVT314;
			static NetScriptFramework::CachedLibValue CVT315;
			static NetScriptFramework::CachedLibValue CVT316;
			static NetScriptFramework::CachedLibValue CVT317;
			static NetScriptFramework::CachedLibValue CVT318;
			static NetScriptFramework::CachedLibValue CVT319;
			static NetScriptFramework::CachedLibValue CVT320;
			static NetScriptFramework::CachedLibValue CVT321;
			static NetScriptFramework::CachedLibValue CVT322;
			static NetScriptFramework::CachedLibValue CVT323;
			static NetScriptFramework::CachedLibValue CVT324;

		private:
			static void _Init1()
			{
				auto ls = NetScriptFramework::Main::GameInfo->CachedValues;
				CVT0 = NetScriptFramework::CachedLibValue(ls[0]);
				CVT1 = NetScriptFramework::CachedLibValue(ls[1]);
				CVT2 = NetScriptFramework::CachedLibValue(ls[2]);
				CVT3 = NetScriptFramework::CachedLibValue(ls[3]);
				CVT4 = NetScriptFramework::CachedLibValue(ls[4]);
				CVT5 = NetScriptFramework::CachedLibValue(ls[5]);
				CVT6 = NetScriptFramework::CachedLibValue(ls[6]);
				CVT7 = NetScriptFramework::CachedLibValue(ls[7]);
				CVT8 = NetScriptFramework::CachedLibValue(ls[8]);
				CVT9 = NetScriptFramework::CachedLibValue(ls[9]);
				CVT10 = NetScriptFramework::CachedLibValue(ls[10]);
				CVT11 = NetScriptFramework::CachedLibValue(ls[11]);
				CVT12 = NetScriptFramework::CachedLibValue(ls[12]);
				CVT13 = NetScriptFramework::CachedLibValue(ls[13]);
				CVT14 = NetScriptFramework::CachedLibValue(ls[14]);
				CVT15 = NetScriptFramework::CachedLibValue(ls[15]);
				CVT16 = NetScriptFramework::CachedLibValue(ls[16]);
				CVT17 = NetScriptFramework::CachedLibValue(ls[17]);
				CVT18 = NetScriptFramework::CachedLibValue(ls[18]);
				CVT19 = NetScriptFramework::CachedLibValue(ls[19]);
				CVT20 = NetScriptFramework::CachedLibValue(ls[20]);
				CVT21 = NetScriptFramework::CachedLibValue(ls[21]);
				CVT22 = NetScriptFramework::CachedLibValue(ls[22]);
				CVT23 = NetScriptFramework::CachedLibValue(ls[23]);
				CVT24 = NetScriptFramework::CachedLibValue(ls[24]);
				CVT25 = NetScriptFramework::CachedLibValue(ls[25]);
				CVT26 = NetScriptFramework::CachedLibValue(ls[26]);
				CVT27 = NetScriptFramework::CachedLibValue(ls[27]);
				CVT28 = NetScriptFramework::CachedLibValue(ls[28]);
				CVT29 = NetScriptFramework::CachedLibValue(ls[29]);
				CVT30 = NetScriptFramework::CachedLibValue(ls[30]);
				CVT31 = NetScriptFramework::CachedLibValue(ls[31]);
				CVT32 = NetScriptFramework::CachedLibValue(ls[32]);
				CVT33 = NetScriptFramework::CachedLibValue(ls[33]);
				CVT34 = NetScriptFramework::CachedLibValue(ls[34]);
				CVT35 = NetScriptFramework::CachedLibValue(ls[35]);
				CVT36 = NetScriptFramework::CachedLibValue(ls[36]);
				CVT37 = NetScriptFramework::CachedLibValue(ls[37]);
				CVT38 = NetScriptFramework::CachedLibValue(ls[38]);
				CVT39 = NetScriptFramework::CachedLibValue(ls[39]);
				CVT40 = NetScriptFramework::CachedLibValue(ls[40]);
				CVT41 = NetScriptFramework::CachedLibValue(ls[41]);
				CVT42 = NetScriptFramework::CachedLibValue(ls[42]);
				CVT43 = NetScriptFramework::CachedLibValue(ls[43]);
				CVT44 = NetScriptFramework::CachedLibValue(ls[44]);
				CVT45 = NetScriptFramework::CachedLibValue(ls[45]);
				CVT46 = NetScriptFramework::CachedLibValue(ls[46]);
				CVT47 = NetScriptFramework::CachedLibValue(ls[47]);
				CVT48 = NetScriptFramework::CachedLibValue(ls[48]);
				CVT49 = NetScriptFramework::CachedLibValue(ls[49]);
				CVT50 = NetScriptFramework::CachedLibValue(ls[50]);
				CVT51 = NetScriptFramework::CachedLibValue(ls[51]);
				CVT52 = NetScriptFramework::CachedLibValue(ls[52]);
				CVT53 = NetScriptFramework::CachedLibValue(ls[53]);
				CVT54 = NetScriptFramework::CachedLibValue(ls[54]);
				CVT55 = NetScriptFramework::CachedLibValue(ls[55]);
				CVT56 = NetScriptFramework::CachedLibValue(ls[56]);
				CVT57 = NetScriptFramework::CachedLibValue(ls[57]);
				CVT58 = NetScriptFramework::CachedLibValue(ls[58]);
				CVT59 = NetScriptFramework::CachedLibValue(ls[59]);
				CVT60 = NetScriptFramework::CachedLibValue(ls[60]);
				CVT61 = NetScriptFramework::CachedLibValue(ls[61]);
				CVT62 = NetScriptFramework::CachedLibValue(ls[62]);
				CVT63 = NetScriptFramework::CachedLibValue(ls[63]);
				CVT64 = NetScriptFramework::CachedLibValue(ls[64]);
				CVT65 = NetScriptFramework::CachedLibValue(ls[65]);
				CVT66 = NetScriptFramework::CachedLibValue(ls[66]);
				CVT67 = NetScriptFramework::CachedLibValue(ls[67]);
				CVT68 = NetScriptFramework::CachedLibValue(ls[68]);
				CVT69 = NetScriptFramework::CachedLibValue(ls[69]);
				CVT70 = NetScriptFramework::CachedLibValue(ls[70]);
				CVT71 = NetScriptFramework::CachedLibValue(ls[71]);
				CVT72 = NetScriptFramework::CachedLibValue(ls[72]);
				CVT73 = NetScriptFramework::CachedLibValue(ls[73]);
				CVT74 = NetScriptFramework::CachedLibValue(ls[74]);
				CVT75 = NetScriptFramework::CachedLibValue(ls[75]);
				CVT76 = NetScriptFramework::CachedLibValue(ls[76]);
				CVT77 = NetScriptFramework::CachedLibValue(ls[77]);
				CVT78 = NetScriptFramework::CachedLibValue(ls[78]);
				CVT79 = NetScriptFramework::CachedLibValue(ls[79]);
				CVT80 = NetScriptFramework::CachedLibValue(ls[80]);
				CVT81 = NetScriptFramework::CachedLibValue(ls[81]);
				CVT82 = NetScriptFramework::CachedLibValue(ls[82]);
				CVT83 = NetScriptFramework::CachedLibValue(ls[83]);
				CVT84 = NetScriptFramework::CachedLibValue(ls[84]);
				CVT85 = NetScriptFramework::CachedLibValue(ls[85]);
				CVT86 = NetScriptFramework::CachedLibValue(ls[86]);
				CVT87 = NetScriptFramework::CachedLibValue(ls[87]);
				CVT88 = NetScriptFramework::CachedLibValue(ls[88]);
				CVT89 = NetScriptFramework::CachedLibValue(ls[89]);
				CVT90 = NetScriptFramework::CachedLibValue(ls[90]);
				CVT91 = NetScriptFramework::CachedLibValue(ls[91]);
				CVT92 = NetScriptFramework::CachedLibValue(ls[92]);
				CVT93 = NetScriptFramework::CachedLibValue(ls[93]);
				CVT94 = NetScriptFramework::CachedLibValue(ls[94]);
				CVT95 = NetScriptFramework::CachedLibValue(ls[95]);
				CVT96 = NetScriptFramework::CachedLibValue(ls[96]);
				CVT97 = NetScriptFramework::CachedLibValue(ls[97]);
				CVT98 = NetScriptFramework::CachedLibValue(ls[98]);
				CVT99 = NetScriptFramework::CachedLibValue(ls[99]);
				CVT100 = NetScriptFramework::CachedLibValue(ls[100]);
				CVT101 = NetScriptFramework::CachedLibValue(ls[101]);
				CVT102 = NetScriptFramework::CachedLibValue(ls[102]);
				CVT103 = NetScriptFramework::CachedLibValue(ls[103]);
				CVT104 = NetScriptFramework::CachedLibValue(ls[104]);
				CVT105 = NetScriptFramework::CachedLibValue(ls[105]);
				CVT106 = NetScriptFramework::CachedLibValue(ls[106]);
				CVT107 = NetScriptFramework::CachedLibValue(ls[107]);
				CVT108 = NetScriptFramework::CachedLibValue(ls[108]);
				CVT109 = NetScriptFramework::CachedLibValue(ls[109]);
				CVT110 = NetScriptFramework::CachedLibValue(ls[110]);
				CVT111 = NetScriptFramework::CachedLibValue(ls[111]);
				CVT112 = NetScriptFramework::CachedLibValue(ls[112]);
				CVT113 = NetScriptFramework::CachedLibValue(ls[113]);
				CVT114 = NetScriptFramework::CachedLibValue(ls[114]);
				CVT115 = NetScriptFramework::CachedLibValue(ls[115]);
				CVT116 = NetScriptFramework::CachedLibValue(ls[116]);
				CVT117 = NetScriptFramework::CachedLibValue(ls[117]);
				CVT118 = NetScriptFramework::CachedLibValue(ls[118]);
				CVT119 = NetScriptFramework::CachedLibValue(ls[119]);
				CVT120 = NetScriptFramework::CachedLibValue(ls[120]);
				CVT121 = NetScriptFramework::CachedLibValue(ls[121]);
				CVT122 = NetScriptFramework::CachedLibValue(ls[122]);
				CVT123 = NetScriptFramework::CachedLibValue(ls[123]);
				CVT124 = NetScriptFramework::CachedLibValue(ls[124]);
				CVT125 = NetScriptFramework::CachedLibValue(ls[125]);
				CVT126 = NetScriptFramework::CachedLibValue(ls[126]);
				CVT127 = NetScriptFramework::CachedLibValue(ls[127]);
				CVT128 = NetScriptFramework::CachedLibValue(ls[128]);
				CVT129 = NetScriptFramework::CachedLibValue(ls[129]);
				CVT130 = NetScriptFramework::CachedLibValue(ls[130]);
				CVT131 = NetScriptFramework::CachedLibValue(ls[131]);
				CVT132 = NetScriptFramework::CachedLibValue(ls[132]);
				CVT133 = NetScriptFramework::CachedLibValue(ls[133]);
				CVT134 = NetScriptFramework::CachedLibValue(ls[134]);
				CVT135 = NetScriptFramework::CachedLibValue(ls[135]);
				CVT136 = NetScriptFramework::CachedLibValue(ls[136]);
				CVT137 = NetScriptFramework::CachedLibValue(ls[137]);
				CVT138 = NetScriptFramework::CachedLibValue(ls[138]);
				CVT139 = NetScriptFramework::CachedLibValue(ls[139]);
				CVT140 = NetScriptFramework::CachedLibValue(ls[140]);
				CVT141 = NetScriptFramework::CachedLibValue(ls[141]);
				CVT142 = NetScriptFramework::CachedLibValue(ls[142]);
				CVT143 = NetScriptFramework::CachedLibValue(ls[143]);
				CVT144 = NetScriptFramework::CachedLibValue(ls[144]);
				CVT145 = NetScriptFramework::CachedLibValue(ls[145]);
				CVT146 = NetScriptFramework::CachedLibValue(ls[146]);
				CVT147 = NetScriptFramework::CachedLibValue(ls[147]);
				CVT148 = NetScriptFramework::CachedLibValue(ls[148]);
				CVT149 = NetScriptFramework::CachedLibValue(ls[149]);
				CVT150 = NetScriptFramework::CachedLibValue(ls[150]);
				CVT151 = NetScriptFramework::CachedLibValue(ls[151]);
				CVT152 = NetScriptFramework::CachedLibValue(ls[152]);
				CVT153 = NetScriptFramework::CachedLibValue(ls[153]);
				CVT154 = NetScriptFramework::CachedLibValue(ls[154]);
				CVT155 = NetScriptFramework::CachedLibValue(ls[155]);
				CVT156 = NetScriptFramework::CachedLibValue(ls[156]);
				CVT157 = NetScriptFramework::CachedLibValue(ls[157]);
				CVT158 = NetScriptFramework::CachedLibValue(ls[158]);
				CVT159 = NetScriptFramework::CachedLibValue(ls[159]);
				CVT160 = NetScriptFramework::CachedLibValue(ls[160]);
				CVT161 = NetScriptFramework::CachedLibValue(ls[161]);
				CVT162 = NetScriptFramework::CachedLibValue(ls[162]);
				CVT163 = NetScriptFramework::CachedLibValue(ls[163]);
				CVT164 = NetScriptFramework::CachedLibValue(ls[164]);
				CVT165 = NetScriptFramework::CachedLibValue(ls[165]);
				CVT166 = NetScriptFramework::CachedLibValue(ls[166]);
				CVT167 = NetScriptFramework::CachedLibValue(ls[167]);
				CVT168 = NetScriptFramework::CachedLibValue(ls[168]);
				CVT169 = NetScriptFramework::CachedLibValue(ls[169]);
				CVT170 = NetScriptFramework::CachedLibValue(ls[170]);
				CVT171 = NetScriptFramework::CachedLibValue(ls[171]);
				CVT172 = NetScriptFramework::CachedLibValue(ls[172]);
				CVT173 = NetScriptFramework::CachedLibValue(ls[173]);
				CVT174 = NetScriptFramework::CachedLibValue(ls[174]);
				CVT175 = NetScriptFramework::CachedLibValue(ls[175]);
				CVT176 = NetScriptFramework::CachedLibValue(ls[176]);
				CVT177 = NetScriptFramework::CachedLibValue(ls[177]);
				CVT178 = NetScriptFramework::CachedLibValue(ls[178]);
				CVT179 = NetScriptFramework::CachedLibValue(ls[179]);
				CVT180 = NetScriptFramework::CachedLibValue(ls[180]);
				CVT181 = NetScriptFramework::CachedLibValue(ls[181]);
				CVT182 = NetScriptFramework::CachedLibValue(ls[182]);
				CVT183 = NetScriptFramework::CachedLibValue(ls[183]);
				CVT184 = NetScriptFramework::CachedLibValue(ls[184]);
				CVT185 = NetScriptFramework::CachedLibValue(ls[185]);
				CVT186 = NetScriptFramework::CachedLibValue(ls[186]);
				CVT187 = NetScriptFramework::CachedLibValue(ls[187]);
				CVT188 = NetScriptFramework::CachedLibValue(ls[188]);
				CVT189 = NetScriptFramework::CachedLibValue(ls[189]);
				CVT190 = NetScriptFramework::CachedLibValue(ls[190]);
				CVT191 = NetScriptFramework::CachedLibValue(ls[191]);
				CVT192 = NetScriptFramework::CachedLibValue(ls[192]);
				CVT193 = NetScriptFramework::CachedLibValue(ls[193]);
				CVT194 = NetScriptFramework::CachedLibValue(ls[194]);
				CVT195 = NetScriptFramework::CachedLibValue(ls[195]);
				CVT196 = NetScriptFramework::CachedLibValue(ls[196]);
				CVT197 = NetScriptFramework::CachedLibValue(ls[197]);
				CVT198 = NetScriptFramework::CachedLibValue(ls[198]);
				CVT199 = NetScriptFramework::CachedLibValue(ls[199]);
				CVT200 = NetScriptFramework::CachedLibValue(ls[200]);
				CVT201 = NetScriptFramework::CachedLibValue(ls[201]);
				CVT202 = NetScriptFramework::CachedLibValue(ls[202]);
				CVT203 = NetScriptFramework::CachedLibValue(ls[203]);
				CVT204 = NetScriptFramework::CachedLibValue(ls[204]);
				CVT205 = NetScriptFramework::CachedLibValue(ls[205]);
				CVT206 = NetScriptFramework::CachedLibValue(ls[206]);
				CVT207 = NetScriptFramework::CachedLibValue(ls[207]);
				CVT208 = NetScriptFramework::CachedLibValue(ls[208]);
				CVT209 = NetScriptFramework::CachedLibValue(ls[209]);
				CVT210 = NetScriptFramework::CachedLibValue(ls[210]);
				CVT211 = NetScriptFramework::CachedLibValue(ls[211]);
				CVT212 = NetScriptFramework::CachedLibValue(ls[212]);
				CVT213 = NetScriptFramework::CachedLibValue(ls[213]);
				CVT214 = NetScriptFramework::CachedLibValue(ls[214]);
				CVT215 = NetScriptFramework::CachedLibValue(ls[215]);
				CVT216 = NetScriptFramework::CachedLibValue(ls[216]);
				CVT217 = NetScriptFramework::CachedLibValue(ls[217]);
				CVT218 = NetScriptFramework::CachedLibValue(ls[218]);
				CVT219 = NetScriptFramework::CachedLibValue(ls[219]);
				CVT220 = NetScriptFramework::CachedLibValue(ls[220]);
				CVT221 = NetScriptFramework::CachedLibValue(ls[221]);
				CVT222 = NetScriptFramework::CachedLibValue(ls[222]);
				CVT223 = NetScriptFramework::CachedLibValue(ls[223]);
				CVT224 = NetScriptFramework::CachedLibValue(ls[224]);
				CVT225 = NetScriptFramework::CachedLibValue(ls[225]);
				CVT226 = NetScriptFramework::CachedLibValue(ls[226]);
				CVT227 = NetScriptFramework::CachedLibValue(ls[227]);
				CVT228 = NetScriptFramework::CachedLibValue(ls[228]);
				CVT229 = NetScriptFramework::CachedLibValue(ls[229]);
				CVT230 = NetScriptFramework::CachedLibValue(ls[230]);
				CVT231 = NetScriptFramework::CachedLibValue(ls[231]);
				CVT232 = NetScriptFramework::CachedLibValue(ls[232]);
				CVT233 = NetScriptFramework::CachedLibValue(ls[233]);
				CVT234 = NetScriptFramework::CachedLibValue(ls[234]);
				CVT235 = NetScriptFramework::CachedLibValue(ls[235]);
				CVT236 = NetScriptFramework::CachedLibValue(ls[236]);
				CVT237 = NetScriptFramework::CachedLibValue(ls[237]);
				CVT238 = NetScriptFramework::CachedLibValue(ls[238]);
				CVT239 = NetScriptFramework::CachedLibValue(ls[239]);
				CVT240 = NetScriptFramework::CachedLibValue(ls[240]);
				CVT241 = NetScriptFramework::CachedLibValue(ls[241]);
				CVT242 = NetScriptFramework::CachedLibValue(ls[242]);
				CVT243 = NetScriptFramework::CachedLibValue(ls[243]);
				CVT244 = NetScriptFramework::CachedLibValue(ls[244]);
				CVT245 = NetScriptFramework::CachedLibValue(ls[245]);
				CVT246 = NetScriptFramework::CachedLibValue(ls[246]);
				CVT247 = NetScriptFramework::CachedLibValue(ls[247]);
				CVT248 = NetScriptFramework::CachedLibValue(ls[248]);
				CVT249 = NetScriptFramework::CachedLibValue(ls[249]);
				CVT250 = NetScriptFramework::CachedLibValue(ls[250]);
				CVT251 = NetScriptFramework::CachedLibValue(ls[251]);
				CVT252 = NetScriptFramework::CachedLibValue(ls[252]);
				CVT253 = NetScriptFramework::CachedLibValue(ls[253]);
				CVT254 = NetScriptFramework::CachedLibValue(ls[254]);
				CVT255 = NetScriptFramework::CachedLibValue(ls[255]);
				CVT256 = NetScriptFramework::CachedLibValue(ls[256]);
				CVT257 = NetScriptFramework::CachedLibValue(ls[257]);
				CVT258 = NetScriptFramework::CachedLibValue(ls[258]);
				CVT259 = NetScriptFramework::CachedLibValue(ls[259]);
				CVT260 = NetScriptFramework::CachedLibValue(ls[260]);
				CVT261 = NetScriptFramework::CachedLibValue(ls[261]);
				CVT262 = NetScriptFramework::CachedLibValue(ls[262]);
				CVT263 = NetScriptFramework::CachedLibValue(ls[263]);
				CVT264 = NetScriptFramework::CachedLibValue(ls[264]);
				CVT265 = NetScriptFramework::CachedLibValue(ls[265]);
				CVT266 = NetScriptFramework::CachedLibValue(ls[266]);
				CVT267 = NetScriptFramework::CachedLibValue(ls[267]);
				CVT268 = NetScriptFramework::CachedLibValue(ls[268]);
				CVT269 = NetScriptFramework::CachedLibValue(ls[269]);
				CVT270 = NetScriptFramework::CachedLibValue(ls[270]);
				CVT271 = NetScriptFramework::CachedLibValue(ls[271]);
				CVT272 = NetScriptFramework::CachedLibValue(ls[272]);
				CVT273 = NetScriptFramework::CachedLibValue(ls[273]);
				CVT274 = NetScriptFramework::CachedLibValue(ls[274]);
				CVT275 = NetScriptFramework::CachedLibValue(ls[275]);
				CVT276 = NetScriptFramework::CachedLibValue(ls[276]);
				CVT277 = NetScriptFramework::CachedLibValue(ls[277]);
				CVT278 = NetScriptFramework::CachedLibValue(ls[278]);
				CVT279 = NetScriptFramework::CachedLibValue(ls[279]);
				CVT280 = NetScriptFramework::CachedLibValue(ls[280]);
				CVT281 = NetScriptFramework::CachedLibValue(ls[281]);
				CVT282 = NetScriptFramework::CachedLibValue(ls[282]);
				CVT283 = NetScriptFramework::CachedLibValue(ls[283]);
				CVT284 = NetScriptFramework::CachedLibValue(ls[284]);
				CVT285 = NetScriptFramework::CachedLibValue(ls[285]);
				CVT286 = NetScriptFramework::CachedLibValue(ls[286]);
				CVT287 = NetScriptFramework::CachedLibValue(ls[287]);
				CVT288 = NetScriptFramework::CachedLibValue(ls[288]);
				CVT289 = NetScriptFramework::CachedLibValue(ls[289]);
				CVT290 = NetScriptFramework::CachedLibValue(ls[290]);
				CVT291 = NetScriptFramework::CachedLibValue(ls[291]);
				CVT292 = NetScriptFramework::CachedLibValue(ls[292]);
				CVT293 = NetScriptFramework::CachedLibValue(ls[293]);
				CVT294 = NetScriptFramework::CachedLibValue(ls[294]);
				CVT295 = NetScriptFramework::CachedLibValue(ls[295]);
				CVT296 = NetScriptFramework::CachedLibValue(ls[296]);
				CVT297 = NetScriptFramework::CachedLibValue(ls[297]);
				CVT298 = NetScriptFramework::CachedLibValue(ls[298]);
				CVT299 = NetScriptFramework::CachedLibValue(ls[299]);
				CVT300 = NetScriptFramework::CachedLibValue(ls[300]);
				CVT301 = NetScriptFramework::CachedLibValue(ls[301]);
				CVT302 = NetScriptFramework::CachedLibValue(ls[302]);
				CVT303 = NetScriptFramework::CachedLibValue(ls[303]);
				CVT304 = NetScriptFramework::CachedLibValue(ls[304]);
				CVT305 = NetScriptFramework::CachedLibValue(ls[305]);
				CVT306 = NetScriptFramework::CachedLibValue(ls[306]);
				CVT307 = NetScriptFramework::CachedLibValue(ls[307]);
				CVT308 = NetScriptFramework::CachedLibValue(ls[308]);
				CVT309 = NetScriptFramework::CachedLibValue(ls[309]);
				CVT310 = NetScriptFramework::CachedLibValue(ls[310]);
				CVT311 = NetScriptFramework::CachedLibValue(ls[311]);
				CVT312 = NetScriptFramework::CachedLibValue(ls[312]);
				CVT313 = NetScriptFramework::CachedLibValue(ls[313]);
				CVT314 = NetScriptFramework::CachedLibValue(ls[314]);
				CVT315 = NetScriptFramework::CachedLibValue(ls[315]);
				CVT316 = NetScriptFramework::CachedLibValue(ls[316]);
				CVT317 = NetScriptFramework::CachedLibValue(ls[317]);
				CVT318 = NetScriptFramework::CachedLibValue(ls[318]);
				CVT319 = NetScriptFramework::CachedLibValue(ls[319]);
				CVT320 = NetScriptFramework::CachedLibValue(ls[320]);
				CVT321 = NetScriptFramework::CachedLibValue(ls[321]);
				CVT322 = NetScriptFramework::CachedLibValue(ls[322]);
				CVT323 = NetScriptFramework::CachedLibValue(ls[323]);
				CVT324 = NetScriptFramework::CachedLibValue(ls[324]);
			}

		internal:
			static void Init()
			{
				_Init1();
			}
		};
	}
}

#pragma warning(pop)
