/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-9;
const int mod=998244353;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int n,k,ans;
int lmt=64;
int arr[66];
bool check(int x){
	vector<int>cur;
	for(int i=1;i<=x;i++)cur.push_back(arr[i]);
	for(int i=1;i<=k;i++){
		vector<int>new_v;
		int sum=0;
		for(auto u:cur)sum+=u;
		if(sum>n)return false;
		sort(cur.rbegin(),cur.rend());
		int pos=0;
		for(auto u:cur){
			pos++;
			for(int j=0;j<u;j++)new_v.push_back(pos);
		}
		cur=new_v;
	}
	return cur.size()<=n;
}
void dfs(int x,int sum){
	if(check(x-1))ans++;
	else return;
	if(sum==lmt)return;
	for(int i=arr[x-1];i+sum<=lmt;i++){
		arr[x]=i;dfs(x+1,sum+i);
	}
}
int dp[2205],f[66][2205];
const int ans3[]={0,1,1,2,3,3,4,5,5,5,7,8,8,9,10,11,12,12,13,14,15,16,18,18,19,21,21,22,24,25,25,27,28,28,30,33,34,35,36,38,39,41,43,44,44,45,48,49,51,53,55,56,57,58,59,63,67,67,70,72,72,75,76,78,79,82,84,86,87,89,93,96,98,101,102,103,106,109,110,114,119,121,124,125,128,130,133,133,137,139,142,146,149,151,155,157,160,164,167,168,172,178,180,183,185,190,193,196,200,204,206,209,213,218,219,222,227,228,231,236,242,245,248,251,255,260,267,272,274,278,283,285,290,296,301,302,308,314,316,323,329,333,336,339,343,347,352,359,363,368,371,377,382,384,392,400,402,406,413,417,422,432,437,444,451,453,458,463,469,472,479,487,492,496,501,513,520,526,534,537,538,545,550,554,562,571,577,584,590,595,602,613,621,627,635,641,647,653,655,667,677,684,691,699,704,709,720,726,733,742,751,758,765,772,779,785,797,805,813,818,827,835,840,848,857,869,880,887,894,903,913,921,934,942,950,957,967,977,986,994,1000,1014,1023,1031,1044,1054,1063,1071,1080,1089,1097,1109,1118,1129,1137,1146,1159,1169,1176,1185,1197,1209,1218,1231,1237,1250,1265,1274,1283,1295,1308,1319,1333,1345,1354,1364,1373,1383,1395,1408,1424,1437,1446,1456,1469,1479,1496,1513,1518,1530,1549,1561,1573,1582,1594,1605,1618,1625,1639,1650,1665,1680,1692,1707,1721,1729,1740,1755,1773,1784,1803,1826,1836,1844,1856,1873,1885,1899,1913,1927,1938,1949,1969,1989,2005,2019,2034,2047,2060,2079,2093,2109,2130,2141,2156,2176,2189,2202,2215,2237,2249,2266,2282,2296,2313,2326,2341,2361,2373,2388,2403,2421,2435,2452,2468,2485,2509,2529,2549,2565,2584,2602,2618,2631,2651,2673,2690,2707,2721,2735,2755,2773,2793,2816,2833,2851,2870,2888,2910,2934,2956,2977,2996,3011,3027,3052,3076,3088,3105,3128,3144,3163,3186,3202,3224,3244,3267,3288,3305,3320,3342,3370,3393,3413,3429,3451,3478,3502,3520,3545,3567,3579,3599,3629,3647,3670,3701,3722,3738,3765,3790,3811,3834,3857,3880,3901,3928,3952,3978,3994,4023,4050,4068,4092,4122,4139,4159,4192,4214,4240,4264,4293,4314,4332,4361,4387,4408,4438,4464,4486,4504,4540,4572,4591,4621,4649,4669,4695,4720,4747,4772,4804,4839,4864,4895,4910,4937,4967,4990,5022,5053,5081,5106,5133,5156,5190,5231,5258,5286,5319,5347,5369,5391,5427,5456,5489,5524,5555,5581,5606,5638,5674,5701,5724,5760,5783,5819,5852,5878,5905,5946,5982,6010,6042,6070,6098,6134,6162,6189,6219,6255,6289,6323,6352,6385,6424,6465,6502,6532,6566,6595,6626,6657,6686,6716,6759,6801,6829,6861,6892,6926,6960,7001,7038,7066,7101,7143,7178,7216,7259,7294,7334,7377,7414,7450,7487,7526,7557,7593,7622,7662,7699,7726,7775,7816,7858,7895,7933,7961,7993,8032,8083,8126,8165,8200,8237,8275,8321,8361,8408,8447,8479,8516,8550,8591,8629,8673,8724,8763,8797,8834,8885,8925,8967,9022,9061,9099,9145,9178,9217,9264,9305,9347,9392,9437,9481,9528,9573,9625,9668,9706,9751,9789,9832,9877,9937,9981,10022,10074,10120,10170,10220,10273,10307,10349,10395,10453,10496,10526,10577,10626,10664,10726,10777,10816,10860,10919,10956,11000,11057,11103,11146,11206,11252,11303,11362,11417,11464,11509,11552,11607,11667,11712,11763,11809,11853,11893,11946,12001,12052,12114,12171,12214,12266,12324,12376,12432,12491,12547,12604,12658,12711,12766,12808,12865,12924,12973,13038,13094,13146,13191,13253,13313,13367,13426,13485,13542,13600,13656,13711,13762,13825,13879,13934,13986,14046,14112,14169,14224,14281,14344,14409,14468,14519,14563,14636,14699,14755,14821,14873,14934,15000,15063,15128,15189,15247,15313,15374,15434,15496,15556,15604,15664,15733,15799,15865,15936,15989,16048,16112,16177,16255,16332,16384,16443,16514,16581,16646,16721,16792,16851,16920,16989,17044,17110,17187,17257,17330,17402,17467,17526,17580,17653,17716,17788,17869,17943,18008,18070,18142,18212,18287,18363,18429,18496,18562,18636,18716,18788,18857,18929,18996,19066,19136,19215,19284,19358,19436,19496,19578,19661,19739,19808,19881,19955,20028,20105,20178,20240,20322,20400,20476,20560,20627,20702,20780,20861,20949,21026,21104,21170,21258,21334,21412,21503,21579,21660,21746,21823,21901,21989,22064,22145,22217,22299,22390,22475,22560,22644,22728,22790,22879,22969,23055,23130,23221,23292,23364,23455,23548,23640,23734,23825,23894,23979,24063,24157,24244,24323,24418,24514,24595,24685,24765,24841,24925,25030,25115,25205,25302,25394,25488,25572,25661,25746,25837,25918,26020,26107,26173,26279,26388,26471,26559,26654,26743,26834,26934,27024,27110,27209,27313,27407,27489,27581,27680,27790,27897,28000,28093,28174,28277,28384,28472,28576,28687,28780,28862,28964,29062,29152,29280,29378,29455,29552,29661,29759,29862,29962,30056,30163,30272,30370,30482,30573,30686,30805,30900,30995,31099,31211,31293,31421,31544,31642,31747,31863,31960,32052,32163,32269,32370,32482,32588,32693,32792,32905,33025,33131,33245,33358,33466,33575,33673,33782,33882,33998,34110,34217,34330,34427,34554,34674,34788,34917,35025,35136,35239,35359,35468,35596,35722,35826,35932,36050,36158,36279,36404,36516,36628,36748,36869,37007,37129,37232,37356,37482,37598,37708,37847,37961,38077,38207,38316,38427,38554,38684,38811,38928,39062,39186,39298,39419,39551,39696,39822,39941,40075,40174,40287,40424,40570,40701,40836,40968,41080,41194,41327,41465,41598,41747,41877,41993,42110,42231,42373,42504,42643,42781,42895,43011,43156,43277,43403,43550,43698,43825,43955,44087,44210,44353,44509,44657,44792,44924,45065,45198,45316,45452,45602,45729,45867,46031,46160,46296,46444,46595,46732,46882,47022,47159,47310,47457,47596,47721,47863,48018,48158,48293,48441,48586,48723,48870,49024,49173,49330,49494,49635,49774,49927,50088,50238,50401,50543,50685,50830,50969,51127,51287,51414,51573,51745,51886,52030,52197,52339,52482,52661,52795,52943,53112,53281,53432,53585,53745,53890,54053,54206,54364,54519,54667,54852,55017,55168,55322,55484,55639,55785,55948,56116,56274,56455,56619,56772,56929,57083,57236,57413,57587,57746,57930,58090,58243,58421,58594,58781,58969,59135,59283,59447,59630,59798,59980,60143,60305,60472,60635,60801,60961,61142,61323,61515,61688,61856,62032,62175,62354,62551,62727,62902,63087,63273,63438,63624,63794,63972,64164,64362,64536,64713,64893,65064,65254,65431,65625,65814,65999,66174,66354,66520,66720,66908,67096,67269,67459,67647,67831,68019,68195,68374,68580,68768,68950,69135,69319,69516,69712,69913,70084,70291,70450,70659,70870,71049,71227,71430,71646,71823,72034,72221,72407,72604,72828,73033,73221,73414,73607,73801,73993,74195,74403,74594,74789,75022,75218,75421,75635,75827,76018,76238,76456,76636,76839,77062,77264,77478,77692,77904,78081,78282,78502,78724,78931,79130,79351,79548,79755,79979,80188,80412,80636,80854,81069,81253,81456,81680,81907,82140,82373,82576,82769,82994,83219,83431,83655,83904,84137,84341,84552,84764,84982,85218,85463,85685,85901,86116,86352,86579,86769,86990,87229,87449,87660,87894,88113,88332,88593,88831,89048,89278,89514,89739,89970,90187,90427,90662,90902,91150,91377,91600,91834,92088,92315,92529,92780,93011,93255,93518,93739,93965,94230,94493,94739,94973,95213,95432,95669,95908,96156,96412,96663,96902,97140,97359,97586,97845,98092,98347,98624,98874,99117,99374,99620,99873,100113,100398,100658,100903,101156,101392,101637,101889,102146,102409,102658,102919,103189,103425,103675,103944,104204,104475,104770,105024,105279,105572,105824,106073,106334,106578,106842,107118,107364,107638,107903,108165,108441,108734,108988,109238,109508,109778,110039,110308,110574,110838,111139,111420,111686,111939,112212,112488,112763,113038,113312,113581,113844,114150,114420,114699,114968,115276,115573,115839,116138,116417,116699,116992,117246,117521,117827,118090,118379,118686,118964,119240,119561,119848,120112,120417,120702,120985,121287,121575,121855,122141,122440,122722,123010,123303,123588,123908,124204,124492,124790,125096,125383,125707,125998,126297,126629,126931,127222,127542,127859,128144,128465,128754,129066,129366,129657,129936,130252,130566,130893,131227,131546,131854,132155,132467,132788,133093,133406,133694,134000,134311,134612,134918,135254,135584,135905,136233,136543,136836,137144,137468,137823,138163,138470,138807,139114,139443,139804,140116,140417,140768,141072,141376,141702,142021,142347,142697,143031,143346,143674,144013,144353,144690,145014,145355,145697,146024,146385,146725,147041,147379,147748,148105,148421,148769,149127,149430,149778,150112,150436,150790,151156,151506,151830,152172,152496,152845,153191,153544,153915,154266,154631,155017,155362,155682,156042,156398,156718,157072,157432,157780,158145,158507,158884,159236,159599,159982,160331,160677,161034,161401,161775,162142,162527,162876,163236,163650,164023,164368,164727,165139,165497,165837,166219,166583,166947,167290,167682,168062,168412,168800,169173,169533,169916,170323,170683,171044,171438,171844,172212,172606,173004,173372,173752,174112,174504,174891,175272,175661,176062,176443,176820,177216,177588,177954,178367,178802,179195,179576,179994,180367,180777,181193,181568,181953,182360,182776,183195,183543,183937,184366,184739,185166,185581,185964,186353,186788,187198,187571,187970,188390,188782,189220,189656,190063,190452,190880,191317,191706,192101,192522,192958,193346,193747,194193,194607,195020,195442,195848,196241,196687,197121,197545,197991,198450,198869,199282,199696,200119,200563,201001,201484,201933,202310,202738,203186,203599,204047,204510,204937,205343,205796,206233,206654,207108,207550,207983,208454,208855,209293,209768,210185,210640,211095,211535,211980,212452,212895,213323,213786,214257,214682,215127,215590,216019,216490,216953,217402,217857,218317,218798,219260,219722,220211,220690,221144,221579,222035,222480,222945,223429,223890,224353,224799,225264,225729,226230,226705,227148,227622,228096,228560,229075,229537,229992,230506,230958,231445,231932,232412,232869,233404,233887,234335,234799,235279,235771,236281,236738,237222,237722,238228,238716,239224,239711,240175,240716,241219,241712,242205,242697,243171,243686,244173,244626,245122,245675,246172,246689,247204,247689,248191,248670,249185,249702,250191,250733,251297,251786,252285,252847,253400,253882,254389,254895,255393,255921,256473,256982,257462,257983,258517,259038,259548,260092,260598,261132,261656,262191,262704,263245,263779,264334,264838,265393,265935,266484,267061,267588,268090,268607,269131,269645,270194,270690,271262,271830,272357,272903,273479,274013,274567,275160,275682,276219,276802,277357,277854,278436,279004,279553,280113,280674,281216,281759,282337,282916,283490,284026,284553,285091,285657,286201,286786,287361,287899,288488,289071,289604,290204,290800,291392,292012,292556,293099,293667,294252,294843,295430,295989,296591,297174,297747,298307,298908,299463,300054,300683,301250,301807,302396,303016,303585,304196,304827,305434,306041,306671,307231,307819,308417,309030,309633,310231,310811,311433,312014,312584,313215,313823,314423,315062,315676,316260,316865,317521,318134,318757,319355,319963,320595,321209,321835,322444,323034,323680,324341,324957,325563,326213,326808,327398,328047,328694,329310,329942,330614,331244,331844,332518,333158,333778,334434,335048,335679,336298,336963,337642,338286,338920,339601,340253,340860,341523,342167,342790,343433,344094,344743,345373,346050,346691,347317,347990,348679,349369,350032,350696,351348,351963,352645,353338,353995,354622,355298,355984,356644,357329,358012,358715,359345,360016,360707,361362,362025,362710,363431,364118,364797,365512,366171,366851,367596,368257,368929,369664,370374,371016,371704,372395,373083,373802,374493,375188,375881,376577,377319,378042,378731,379413,380138,380834,381513,382256,382934,383632,384390,385118,385807,386551,387261,387962,388697,389405,390093,390830,391563,392278,393012,393678,394401,395176,395952,396666,397400,398111,398815,399553,400316,401010,401762,402531,403271,403975,404699,405459,406206,406985,407716,408478,409194,409924,410671,411432,412148,412925,413682,414441,415223,415981,416745,417539,418303,419009,419773,420519,421312,422079,422819,423590,424384,425112,425895,426674,427446,428195,428996,429751,430500,431327,432111,432897,433679,434455,435193,436039,436852,437637,438418,439237,439989,440731,441536,442311,443096,443905,444714,445538,446336,447112,447937,448732,449543,450365,451174,451945};
int main(){
	cin>>n>>k;
	if(k==1){
		dp[0]=1;
		for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)dp[j]=(dp[j]+dp[j-i])%mod;
		int ans=0;
		for(int i=1;i<=n;i++)ans=(ans+dp[i])%mod;
		cout<<ans<<endl;
		return 0;
	}
	if(k==2){
		f[0][0]=1;
		for(int i=n;i>=1;i--){
			for(int j=0;j<=65;j++){
				for(int t=0;t<=n;t++)if(f[j][t]&&t+i*(j+1)<=n){
					f[j+1][t+i*(j+1)]=(f[j+1][t+i*(j+1)]+f[j][t])%mod;
				}
			}
		}
		int ans=0;
		for(int i=0;i<=65;i++)for(int j=0;j<=n;j++)ans=(ans+f[i][j])%mod;
		cout<<(ans-1+mod)%mod<<endl;
		return 0;
	}
	if(k==3){
		cout<<ans3[n]<<endl;
		return 0;
	} 
	lmt=min(lmt,n);lmt=min(lmt,30);
	arr[0]=1;dfs(1,0);
	cout<<(ans-1+mod)%mod<<endl;
	return 0;
}