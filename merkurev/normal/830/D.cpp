#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int MOD = (int) 1e9 + 7;

void sadd(int &a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
}
int add(int a, int b)
{
	sadd(a, b);
	return a;
}
int mul(int a, int b)
{
	return (a * 1LL * b) % MOD;
}

const int N = 405;
//int dp[N][N];
//int C[N][N];
int dp[N];

void init()
{
	dp[1] = 1;
	dp[2] = 9;
	dp[3] = 245;
	dp[4] = 126565;
	dp[5] = 54326037;
	dp[6] = 321837880;
	dp[7] = 323252721;
	dp[8] = 754868154;
	dp[9] = 328083248;
	dp[10] = 838314395;
	dp[11] = 220816781;
	dp[12] = 893672292;
	dp[13] = 166441208;
	dp[14] = 251255697;
	dp[15] = 114256285;
	dp[16] = 118775501;
	dp[17] = 482714697;
	dp[18] = 11784725;
	dp[19] = 460862131;
	dp[20] = 550384565;
	dp[21] = 106742050;
	dp[22] = 425241115;
	dp[23] = 626692854;
	dp[24] = 674266678;
	dp[25] = 320014275;
	dp[26] = 345949512;
	dp[27] = 527320049;
	dp[28] = 897822749;
	dp[29] = 137190263;
	dp[30] = 491039182;
	dp[31] = 810384961;
	dp[32] = 482023334;
	dp[33] = 658099864;
	dp[34] = 886790989;
	dp[35] = 845381174;
	dp[36] = 371433224;
	dp[37] = 278969124;
	dp[38] = 420088324;
	dp[39] = 696766322;
	dp[40] = 388302635;
	dp[41] = 141033366;
	dp[42] = 46387851;
	dp[43] = 932125021;
	dp[44] = 278342766;
	dp[45] = 371131134;
	dp[46] = 922501918;
	dp[47] = 110778457;
	dp[48] = 506223573;
	dp[49] = 806353719;
	dp[50] = 391845991;
	dp[51] = 923507761;
	dp[52] = 780307355;
	dp[53] = 109951115;
	dp[54] = 830090230;
	dp[55] = 605558495;
	dp[56] = 344686604;
	dp[57] = 988110893;
	dp[58] = 944684429;
	dp[59] = 715019947;
	dp[60] = 799898820;
	dp[61] = 384672708;
	dp[62] = 907325090;
	dp[63] = 758952329;
	dp[64] = 550672104;
	dp[65] = 368337206;
	dp[66] = 394915145;
	dp[67] = 401744167;
	dp[68] = 923781939;
	dp[69] = 831857516;
	dp[70] = 407845661;
	dp[71] = 329267374;
	dp[72] = 927004007;
	dp[73] = 891609656;
	dp[74] = 897919613;
	dp[75] = 481297880;
	dp[76] = 737337940;
	dp[77] = 651873737;
	dp[78] = 287246681;
	dp[79] = 973133651;
	dp[80] = 679864988;
	dp[81] = 784719328;
	dp[82] = 820504764;
	dp[83] = 875613823;
	dp[84] = 806512665;
	dp[85] = 164851642;
	dp[86] = 500228957;
	dp[87] = 951814419;
	dp[88] = 447763649;
	dp[89] = 273141670;
	dp[90] = 979349615;
	dp[91] = 964027956;
	dp[92] = 809510400;
	dp[93] = 276634497;
	dp[94] = 116631976;
	dp[95] = 426739449;
	dp[96] = 175282420;
	dp[97] = 885948162;
	dp[98] = 62270880;
	dp[99] = 974395255;
	dp[100] = 675165056;
	dp[101] = 759589968;
	dp[102] = 837957573;
	dp[103] = 931897605;
	dp[104] = 152352780;
	dp[105] = 585420109;
	dp[106] = 1772087;
	dp[107] = 333401718;
	dp[108] = 898833639;
	dp[109] = 745874265;
	dp[110] = 786209423;
	dp[111] = 691982338;
	dp[112] = 498790927;
	dp[113] = 473374639;
	dp[114] = 274302623;
	dp[115] = 971280670;
	dp[116] = 241671319;
	dp[117] = 13070005;
	dp[118] = 302088807;
	dp[119] = 550276351;
	dp[120] = 436592588;
	dp[121] = 631667314;
	dp[122] = 548656698;
	dp[123] = 730626984;
	dp[124] = 146295220;
	dp[125] = 674398632;
	dp[126] = 400383348;
	dp[127] = 454138904;
	dp[128] = 786220712;
	dp[129] = 118620797;
	dp[130] = 233440672;
	dp[131] = 217349271;
	dp[132] = 274853536;
	dp[133] = 310607544;
	dp[134] = 105221205;
	dp[135] = 769566615;
	dp[136] = 853585061;
	dp[137] = 800665807;
	dp[138] = 695377419;
	dp[139] = 924327065;
	dp[140] = 388199705;
	dp[141] = 551624811;
	dp[142] = 721435546;
	dp[143] = 501720515;
	dp[144] = 308465454;
	dp[145] = 825369234;
	dp[146] = 396065729;
	dp[147] = 451899519;
	dp[148] = 295058424;
	dp[149] = 142088952;
	dp[150] = 473485086;
	dp[151] = 378771634;
	dp[152] = 734511215;
	dp[153] = 462404399;
	dp[154] = 959198328;
	dp[155] = 337668263;
	dp[156] = 794122911;
	dp[157] = 38911400;
	dp[158] = 951992982;
	dp[159] = 472696081;
	dp[160] = 373904752;
	dp[161] = 105884826;
	dp[162] = 630251717;
	dp[163] = 28980684;
	dp[164] = 845136347;
	dp[165] = 353665773;
	dp[166] = 691661192;
	dp[167] = 19922354;
	dp[168] = 231463797;
	dp[169] = 757917231;
	dp[170] = 242739918;
	dp[171] = 979036950;
	dp[172] = 713722080;
	dp[173] = 234689388;
	dp[174] = 2243164;
	dp[175] = 209872853;
	dp[176] = 240808787;
	dp[177] = 539523346;
	dp[178] = 425797848;
	dp[179] = 913772061;
	dp[180] = 224613100;
	dp[181] = 421742777;
	dp[182] = 222232478;
	dp[183] = 92712941;
	dp[184] = 215137570;
	dp[185] = 949901408;
	dp[186] = 274827432;
	dp[187] = 15162482;
	dp[188] = 593145989;
	dp[189] = 274574232;
	dp[190] = 239282092;
	dp[191] = 762720192;
	dp[192] = 804146934;
	dp[193] = 500629424;
	dp[194] = 565985054;
	dp[195] = 81127381;
	dp[196] = 671811155;
	dp[197] = 655565571;
	dp[198] = 890331075;
	dp[199] = 237994348;
	dp[200] = 743647404;
	dp[201] = 667160634;
	dp[202] = 713914299;
	dp[203] = 668506729;
	dp[204] = 741341289;
	dp[205] = 277636808;
	dp[206] = 762781382;
	dp[207] = 14272789;
	dp[208] = 902864131;
	dp[209] = 567443405;
	dp[210] = 149113383;
	dp[211] = 648844381;
	dp[212] = 825489976;
	dp[213] = 933016723;
	dp[214] = 192288078;
	dp[215] = 734493315;
	dp[216] = 240985733;
	dp[217] = 861817693;
	dp[218] = 762711459;
	dp[219] = 525904609;
	dp[220] = 532463481;
	dp[221] = 377133989;
	dp[222] = 620711079;
	dp[223] = 772561562;
	dp[224] = 980733194;
	dp[225] = 227599811;
	dp[226] = 162774370;
	dp[227] = 209512798;
	dp[228] = 787116594;
	dp[229] = 3509258;
	dp[230] = 748795368;
	dp[231] = 378035466;
	dp[232] = 612938915;
	dp[233] = 802091952;
	dp[234] = 857679599;
	dp[235] = 481748937;
	dp[236] = 493370392;
	dp[237] = 358420805;
	dp[238] = 48301629;
	dp[239] = 412001241;
	dp[240] = 463126722;
	dp[241] = 509578422;
	dp[242] = 967799131;
	dp[243] = 994766554;
	dp[244] = 687287243;
	dp[245] = 863623583;
	dp[246] = 771554899;
	dp[247] = 690911527;
	dp[248] = 855314994;
	dp[249] = 923686429;
	dp[250] = 246862514;
	dp[251] = 192479791;
	dp[252] = 133487041;
	dp[253] = 703444043;
	dp[254] = 295281758;
	dp[255] = 801816257;
	dp[256] = 920762934;
	dp[257] = 749306433;
	dp[258] = 973004841;
	dp[259] = 848644684;
	dp[260] = 560026478;
	dp[261] = 952127278;
	dp[262] = 616654635;
	dp[263] = 839390326;
	dp[264] = 975154012;
	dp[265] = 409583672;
	dp[266] = 635350249;
	dp[267] = 343228425;
	dp[268] = 335331602;
	dp[269] = 223826406;
	dp[270] = 952341037;
	dp[271] = 589677800;
	dp[272] = 249747234;
	dp[273] = 555694261;
	dp[274] = 137143500;
	dp[275] = 628190328;
	dp[276] = 461598392;
	dp[277] = 431912756;
	dp[278] = 29349807;
	dp[279] = 759199489;
	dp[280] = 783281228;
	dp[281] = 781971312;
	dp[282] = 915823407;
	dp[283] = 388508707;
	dp[284] = 718062705;
	dp[285] = 27424111;
	dp[286] = 309999451;
	dp[287] = 963383322;
	dp[288] = 831185229;
	dp[289] = 132910888;
	dp[290] = 347028136;
	dp[291] = 850484840;
	dp[292] = 223055285;
	dp[293] = 142335980;
	dp[294] = 144754000;
	dp[295] = 772005560;
	dp[296] = 81796039;
	dp[297] = 167696020;
	dp[298] = 79454283;
	dp[299] = 172772542;
	dp[300] = 201056991;
	dp[301] = 484957644;
	dp[302] = 716630285;
	dp[303] = 763194701;
	dp[304] = 211505841;
	dp[305] = 903448791;
	dp[306] = 926964672;
	dp[307] = 257752668;
	dp[308] = 482951716;
	dp[309] = 411539070;
	dp[310] = 620249847;
	dp[311] = 592476107;
	dp[312] = 170473128;
	dp[313] = 814662613;
	dp[314] = 898000271;
	dp[315] = 57354872;
	dp[316] = 361106091;
	dp[317] = 488697643;
	dp[318] = 889007954;
	dp[319] = 138725767;
	dp[320] = 684860983;
	dp[321] = 36248116;
	dp[322] = 304610143;
	dp[323] = 137633385;
	dp[324] = 413715776;
	dp[325] = 99010024;
	dp[326] = 779653665;
	dp[327] = 100387568;
	dp[328] = 286328069;
	dp[329] = 564731826;
	dp[330] = 621740468;
	dp[331] = 943513219;
	dp[332] = 506666491;
	dp[333] = 249987886;
	dp[334] = 553719884;
	dp[335] = 769853086;
	dp[336] = 337485319;
	dp[337] = 702455584;
	dp[338] = 809637762;
	dp[339] = 755400257;
	dp[340] = 892290368;
	dp[341] = 502180086;
	dp[342] = 364275817;
	dp[343] = 118162370;
	dp[344] = 873374339;
	dp[345] = 261271695;
	dp[346] = 970132574;
	dp[347] = 744105500;
	dp[348] = 434447173;
	dp[349] = 117975095;
	dp[350] = 383088393;
	dp[351] = 625447969;
	dp[352] = 180281249;
	dp[353] = 545367713;
	dp[354] = 133236931;
	dp[355] = 360175662;
	dp[356] = 148087453;
	dp[357] = 806871297;
	dp[358] = 498529036;
	dp[359] = 886076476;
	dp[360] = 65645000;
	dp[361] = 465138299;
	dp[362] = 967109895;
	dp[363] = 331362616;
	dp[364] = 472283705;
	dp[365] = 796894900;
	dp[366] = 199697765;
	dp[367] = 503759892;
	dp[368] = 472807906;
	dp[369] = 187586706;
	dp[370] = 941198065;
	dp[371] = 782234442;
	dp[372] = 57693411;
	dp[373] = 18678611;
	dp[374] = 82626204;
	dp[375] = 395317191;
	dp[376] = 570588915;
	dp[377] = 152519440;
	dp[378] = 449852456;
	dp[379] = 63696518;
	dp[380] = 763741345;
	dp[381] = 878748386;
	dp[382] = 494317541;
	dp[383] = 444782633;
	dp[384] = 93316211;
	dp[385] = 929164666;
	dp[386] = 529288371;
	dp[387] = 165769871;
	dp[388] = 730546850;
	dp[389] = 955877127;
	dp[390] = 994202767;
	dp[391] = 492009567;
	dp[392] = 275683011;
	dp[393] = 415902127;
	dp[394] = 95725776;
	dp[395] = 718047399;
	dp[396] = 786963365;
	dp[397] = 73091278;
	dp[398] = 986172399;
	dp[399] = 174591541;
	dp[400] = 913259286;
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	init();

	int n = 400;
	scanf("%d", &n);
	printf("%d\n", dp[n] );
/*
	for (int i = 0; i < N; i++)
	{
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j] );
	}

	for (int k = 0; k <= n; k++)
		dp[k][0] = 1;

	for (int k = 1; k <= n; k++)
	{
		for (int seg = 1; seg <= n; seg++)
		{
			int cur = 0;
			for (int l = 0; l <= seg; l++)
			{
				int kk = C[seg][l];
				int ndp = mul(dp[k - 1][l], dp[k - 1][seg - l] );
				sadd(cur, mul(kk, ndp) );
			}
			for (int l = 0; l <= seg - 1; l++)
			{
				int kk = mul(seg, C[seg - 1][l] );
				int ndp = mul(dp[k - 1][l], dp[k - 1][seg - 1 - l] );
				sadd(cur, mul(kk, ndp) );
			}
			for (int l = 0; l <= seg; l++)
			{
				int kk = mul(seg * 2, C[seg][l] );
				int ndp = mul(dp[k - 1][l], dp[k - 1][seg - l] );
				sadd(cur, mul(kk, ndp) );
			}
			for (int l = 0; l <= seg + 1; l++)
			{
				int kk = mul(seg, C[seg + 1][l] );
				int ndp = mul(dp[k - 1][l], dp[k - 1][seg + 1 - l] );
				sadd(cur, mul(kk, ndp) );
			}
			dp[k][seg] = cur;
		}
	}

	for (int i = 1; i <= 400; i++)
		printf("dp[%d] = %d;\n", i, dp[i][1] );
//	printf("%d\n", dp[n][1] );
*/

	return 0;
}