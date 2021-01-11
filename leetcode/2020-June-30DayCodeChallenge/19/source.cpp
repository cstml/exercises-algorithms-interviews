#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

#define ll long long
#define log(a) std::cout<<a<<std::endl

//bool compareFunc(pair<string,ll> &a, pair<string,ll>&b)
//{
    //return a.first < b.first;
//}

class Solution {
public:
    string longestDupSubstring(string S) {
        //vector<pair<string,ll>> strV;
        vector<string> strV;
        ll maxV=0;
        ll maxIndex=0;
        ll sz = S.size();
        for(ll i =S.size()-1;i>=0;i--)
        {
            strV.push_back(S.substr(i,sz-1));
        }
        //std::sort(strV.begin(),strV.end(),compareFunc);
        std::sort(strV.begin(),strV.end());
        //
        /*for ( auto i : strV)
            std::cout<<i.first<<" ";
        cout<<endl;
        for ( auto i : strV)
            std::cout<<i.second<<" ";
        cout<<endl;
        */


        sz=strV.size();
        vector<ll> LCP;
        LCP.push_back(0);
        //std::cout<<0<<" ";
        
        for (ll i=0;i<sz-1;i++)
        {
            ll j=0;

            while(strV[i][j] == strV[i+1][j])
                j++;
            //std::cout<<j<<" ";

            if (j>maxV)
            {
                maxV=j;
                maxIndex=S.length()-strV[i].length();
            }
        }
        //cout<<endl<<S.substr(maxIndex,maxV)<<endl;
        return S.substr(maxIndex,maxV);
    }
};



int main()
{
    Solution s;
    std::cout<<s.longestDupSubstring("banana")<<std::endl;
    std::cout<<s.longestDupSubstring("")<<std::endl;
    std::cout<<s.longestDupSubstring("abcde")<<std::endl;
    std::cout<<s.longestDupSubstring("abcda")<<std::endl;
    std::cout<<s.longestDupSubstring("dogdogdog")<<std::endl;
    std::cout<<s.longestDupSubstring("moplvidmaagmsiyyrkchbyhivlqwqsjcgtumqscmxrxrvwsnjjvygrelcbjgbpounhuyealllginkitfaiviraqcycjmskrozcdqylbuejrgfnquercvghppljmojfvylcxakyjxnampmakyjbqgwbyokaybcuklkaqzawageypfqhhasetugatdaxpvtevrigynxbqodiyioapgxqkndujeranxgebnpgsukybyowbxhgpkwjfdywfkpufcxzzqiuglkakibbkobonunnzwbjktykebfcbobxdflnyzngheatpcvnhdwkkhnlwnjdnrmjaevqopvinnzgacjkbhvsdsvuuwwhwesgtdzuctshytyfugdqswvxisyxcxoihfgzxnidnfadphwumtgdfmhjkaryjxvfquucltmuoosamjwqqzeleaiplwcbbxjxxvgsnonoivbnmiwbnijkzgoenohqncjqnckxbhpvreasdyvffrolobxzrmrbvwkpdbfvbwwyibydhndmpvqyfmqjwosclwxhgxmwjiksjvsnwupraojuatksjfqkvvfroqxsraskbdbgtppjrnzpfzabmcczlwynwomebvrihxugvjmtrkzdwuafozjcfqacenabmmxzcueyqwvbtslhjeiopgbrbvfbnpmvlnyexopoahgmwplwxnxqzhucdieyvbgtkfmdeocamzenecqlbhqmdfrvpsqyxvkkyfrbyolzvcpcbkdprttijkzcrgciidavsmrczbollxbkytqjwbiupvsorvkorfriajdtsowenhpmdtvamkoqacwwlkqfdzorjtepwlemunyrghwlvjgaxbzawmikfhtaniwviqiaeinbsqidetfsdbgsydkxgwoqyztaqmyeefaihmgrbxzyheoegawthcsyyrpyvnhysynoaikwtvmwathsomddhltxpeuxettpbeftmmyrqclnzwljlpxazrzzdosemwmthcvgwtxtinffopqxbufjwsvhqamxpydcnpekqhsovvqugqhbgweaiheeicmkdtxltkalexbeftuxvwnxmqqjeyourvbdfikqnzdipmmmiltjapovlhkpunxljeutwhenrxyfeufmzipqvergdkwptkilwzdxlydxbjoxjzxwcfmznfqgoaemrrxuwpfkftwejubxkgjlizljoynvidqwxnvhngqakmmehtvykbjwrrrjvwnrteeoxmtygiiygynedvfzwkvmffghuduspyyrnftyvsvjstfohwwyxhmlfmwguxxzgwdzwlnnltpjvnzswhmbzgdwzhvbgkiddhirgljbflgvyksxgnsvztcywpvutqryzdeerlildbzmtsgnebvsjetdnfgikrbsktbrdamfccvcptfaaklmcaqmglneebpdxkvcwwpndrjqnpqgbgihsfeotgggkdbvcdwfjanvafvxsvvhzyncwlmqqsmledzfnxxfyvcmhtjreykqlrfiqlsqzraqgtmocijejneeezqxbtomkwugapwesrinfiaxwxradnuvbyssqkznwwpsbgatlsxfhpcidfgzrc")<<std::endl;
    std::cout<<s.longestDupSubstring("bwvzoubsovtdpokbjgubpkzsdmxpdxwrkjzjbhcuvppjowoaapfpaqmgpkflwookqdujdfqsifdbkmwqfumwhotpdmevmshumjcdquspnihgceaedgxjgrtjdxqacznaluiiwrivaulamzyecdpyfyxmiavwkqvbybabmshszoslhxzhmaqtvhbnznnxuyctrbywifcuguutkdxchpyxurmskwbygnbtatoxwesmtzchjlrnqsjxanoemmzsqcraykiszrieoaqcwcwlyorrcvlamxztujsglqcwjmqvcmmuwwjgkdfhfxfahlefserldejymbhgdddlwjllantqxeivdbrsbjdcsgrcngejbfvwdjbaffvarzdkizozlszqvzsyszqklvinaypeqyppcyafzqkdlreddrmbxwiikymgcqaghptuvbgkoebirotkfdxcfxeykqvdqlbmnbpgumksbsdwdbyqfdwdqpfustxqorwpxyatjuiocqjytiqzymfkyagtxqypmwnppqwpoltglrpalpextaglktgzauzwxnzgwqfvxitoqkiqcacpcetzscypoumazhyjtqhflnihtmboxmqqqvahqsukxebqnyxpyoiczdjikslukjvgeejnirpijjkhdjrfkjrvvqlrdpzwfyredgxljfjmbtrkpdydmpqqvywtqmdcyrtapmqwhkaocdzkamlbunnfhfcfpoechlqripwsmskcprihcnptbqyqxdnhewuehycuaxbzxbftjaqsfqtvmfvisepjnrzqibkbwtncipwcejllhlqxylwzmquwqgbizbumshhoxwvexjxgiexmjfsrfnplybfdouqggsntludnaznsbnloorlwkhicbzrfvcqohmlzojfdsyzjniyoinfszmaelknerpwgmctnkjjnixlmxjdvpxjjbonmfxrxgpxrculamkmwwnrxgsjlwdohonruecrtuknjjjgsmcctqdfsttcikawjaowskacuretxcdqnkapiiiwezklfnbayedclkkdwdqqsmxqupcphgdmaldcnidadhpvyvbsprbrqpifrpdsjgwvoxumxeuybmcwbmuyacvrfqfkuszjpwyjwbmrhbbvdmhwrowsqahmeexucshsvknchkzljwoztqgrthoeldityevjljhavuqcxgwzcoyvsjoxvmlrxtytlomorbfkskzkfzhbhqjumnwzbfaalogdwztbeirzxitgbmfcwkkgfwapubspmhuygtfhsxjcoklybqoultxvmtactpqqsgewzzguxndxouiacalpopiovashsfcnftuaxaafwjhruheabclgjjyxpaiyuqjybpkdzkyrfnxfwcvdedcfqiseljtebxzcjqmqkhyiurdiybznjnkzaqthrpanhflnunqucliwsdttzbkmndrckzucllnjosvryowfkielbdziuqhiilbbsfbllxjyodgurluibsfjxqoupbxfpxkjscslirbszjmhklgevhdrqykonnnekacqtcworjpgxuraikciaburspaldpihnyafojwmclckulomsyyzxonthymcffhlxjfzonzxpwkpihianrywxejbghxrvsadkhljtubrenaemecmmvesijfqpthrkhiqhdrkvxlrkciaklncrnxzdhcsuaesjmbjlupwvwjfelxipbaligpeojbrvosyimousrqaenebgeleuuybixbwirltnctluazywoqcefcrejgtlfruyiotcbmubuqxbdthtakywfopbvkysddivfaaqaylpoadazdskcuhklvuqmbguwtlaawymbkveoszsysramyowewkheriglqwqejursmaiyhmnrlxryolizwsywgaizflzghtammlntphjmvlvyujgfsjlscpjhavxbeutapfieswtpldeeuxetbqphkqibwdzfeqbjxaryeogyirhleulfeeprmshdmiikfhuqxxpxdryenhdzgxojixhcjswllduemothoxzzpbiapvinihgucazbvggihobmscpijwcavhqxlcenuqjjjpehpreyccucfiecnyflxojxdskncvvdpwzrlwkfhhvgcdeevtflgwypgvvuzlntncpqiczyzxoxsfabybcxlarysptirnzpbzfzlagchruxjfzibrwfyxtyydathyctagcnokpwqfiowsdjvfrnzogemfchwitmoqsoezqdkwefjufdnvnhogqzzcqngkgaiwoqofwjtdygktqvmzcwwmzemvxlgryjjzoyguwjuczziosldbwwygftujlpzanbszeaakidazfpdtbnrowhnlqgyvssziolsfedivgsqvamcliuqeemeorxlrzyofbiozdpuobjwuxglvuuvxebvsnxomfziirlvhuqxjwunehjcqjnmlliqkywwmguloxmapflwhoddpqzduyfkizkneooifsndynggljsfbjcfzahmkambrojzdbatgtimxiisguvdpftjcwmjxbqyaltbgvfefyqwnminsuqraztojpshmlrqtrbpyiekbanjjndnfkhlyihbmxvwyrfomlpcsbrkrptkfyapjctyoruxdwrzjgcrfsxytlripxckhabdqnxwyiidegjwsqvqckjhlmlvdhfnlclizhdpsvmsrkbrzahcuvonpizhyrwilmbmwexzzohvlhzfcqcwhfgamikhkhfrwmymvxrmbypdurouthrlzubtclfltanroeegkfjqqrjxwgyzymcoopcubqvghnckoccjdicffridjupfylgseipqgbshoesjjcjhpyodpituvipopeizgwortgqvotiyfzfnkixcsbuywrxowetievuudmwtnxcbbxpotkcuqmxczzldimrdulntjsieciuebztdtfftligeybplqculadfvnqqxdbrnjqgptjlhqrutfvsiencukxpioekrszfgryxsbcaqaabbsvskhpivnedwejrnooejfvfmozywtkntdcpphrwnnqdvnakujmrqymxgetisbvllvcszyaojatpmogehyfaecerykkratgouegtfsetpywknkhzgzmpdwkjmvimnpjtloqumcntnhqxnbzycwrhkxwaxhweefmrlnemyoeygyxrbwpkrtsbzqkapxkobfoytbhvemmqhnjipwsjenrcegvbbkwjjuckixszmptqbydsigpatqsbybivryjxfcbmjprfleoxhfpdpzwujtbbzunbuvqaxwlrfxsnfhsereyewipnradhqocwyvllxfsyvfmdxmntdjbkjhewufyackxviawolgyevjfitgtvaitkexckrxcwvhqyhfqkjrxnmsgavnxdwqxzdfykfkohprhmiuzlrhnkgcprtnixgjosfgdkbecvwhjeghxbnshmmzqfrbeaepzujjopmfwwgwdkguunugjtwronvdwthlzipilehrnfdxlflyspxdounyhjdkbmdgprqqebpgszrpjwpzsfapdtgyunjgzgvernvkvxfwnxahwbawjrivczeomcjoecuckeglrmgygpqmrpraujjbcrtgdqvhtszwulmwdzxswtwmdpmcuyqirrfujrcrbjpxnklyehmsifbfgpprdtptrjtaauoxguntymzlqroucijjaqtbdipxcrikfbiavjkpapsgfuvgojbdklidflwdqpyddgylyfpkxjpopsnlxpfhngjhpsifbdfpgmtluxrevxczumrddonelqdtzrtyswsokhjjybjlfkoxeeluioxrjkjbkfnzoesywvdegskgbnnxenlwjxibbzfuygcvdrijueiegvapxhrhsqsdvdstbjjmpuotzceluhiqxxhowtfafltqipugbbubtixdgutxbbfpaqqrpurxytjbomgsncnvsibaedbtmvnvhtfsiviotjzikmkahwckcjgxdovdhjynlhhplbkklowfyfwlaobxazpdeyjxaikvcujspctbsaboohilrgrpmyuvwmkrutzlrjjmsczxdwestatrrthgkewhfqfwfsigntrpkxnfrrlxszvpwvodornyrjpeepsdaoqbqcfoptrjbcnjqyepnumdwwqzrohiipounayuklksidvysyoaquhnsnafwxusqhnqhqdsguuuopbnfugprvblrpnykxegzqqmcuehhsmbxuymbbvddfjmqplxqndjtvkwpockfyigspcryulkqunugsxqsvmqxfruegmqbdhrpqyofhjuichixisrqovmgvsaitcwvbouslnqnwbxuyldltrsbdasafhjzbcwsholeetygedllizzxmjzfrnsjkpphgulpkiaizbgprspjfvwoivvfqafqhfrtpmccrjaqdqqnrrjidjvpmbovopcqkeykqrsdykrenmrmgrzfycwkrmajzertyobgrkabhqrhrvtswtlinrwjrafiwlggeibhtlwpaesbdvqkvrwlkmyxdfdzocqagjssirvhgvqqxuzzzborhilzmcuwmdbbxyfhoveudokxrtgfkauvukprmtmtoyprgnghqvujfhanwzogstrrvixbkwadnbmddidciqeshyfmmevtttyzldbyrkmcwcvghywscejheyaegfihroufxjzpfgwynwqsrcuqufjxftyqozyvkjvyjaxutnheqzwqftvidgbfnmirwqrxnmwfnqmqqqvflyekoakzfbcdgesabnaxlgnetkmqgobnyplpndyaahqfghpeginvovqdnknoimrwyttackovtkpyyuzmufutvkjpcpmuhmzxnutduwjcoycjolneqinpqmltgtwfxddaksdmggdtdxhdsvbclxiuowmbhdrmxrexzxbmzvxhpnjssdwginukazqbwddoaryxsgswgphlsjtylqnkqcfwrcprhashjjgfqadgbvdlmhqeutwsuuohzmpkbqhlmwbnfgurkryfeiezahdccpujbatzozvxwwshfhkpmvgdyqcyfduruseuylxgwjsxoaneqzaxmacwixtnsjbfqhvpqscbdxeuuirwqudavgnfsmiuiedqbshrwirrpfodjhicsmikoztytnsgncsrchrzthxnvowckygpbyybzqaqmzncyictygqpuchnknpghotmnlbioojhiboigybydgcfxpzpqsmuvorcojgmaeglnzqgndyytzowmtkntcfahrseijgnzjftsmezyzzbawybsyaspibinurjnnoqfkmlkhbymxnsjzjsttvvacnzaliwaddeyoxwpmopvdnqkxjvffisnwwyhhvyrepxjzwmhzzpqoerfgzqkngtcytvtufreqbhbyutlgvrgtdrtekrzclgkisdmvbgimsvbtdekvttcjabqdecnlswfwmwwjhftgvslxysevchkpqawxiqbrjcrepconkeouluueqnvhxacwbrmwzobbqyrpvvexoqbskobhoppnyrudbdiewmaiipbijhoieeuqrzkwatwosyndbrwbsilhxvxtecefmcovghmpspmjfehnhxzfzdslpepbouknjmirbgepeyhqdailmgvygikoevfuwvstgfrzizqosiqokebsbmcuqacaccoldjcyvhqhzrhccrpfmefsgbukspuebyjmenqdsfwpjsawqgdzmvhudjgijbxgjzeoqvqvqxgekbpxnrkdsuwajzghcxetddxjwakpabectgbfnzgfkjixaaatwogwllelqjowwcqajotiifjyexfjugzrfohtdifulmmxbmpogesfojdytckpjslzmuhtaqxwubizvqkfjmeanvcnbzqjxwbdiiwamboxgrerxcbjiajdkjcxnruqoebllwfxmeibafrlvcxqjtzhhimiqgdfyfvneeonplkgelfwgwnomqtychtbdffvgxfzsihbfdqqlgiwvmyrnfdjfkzujejlyrfzcgrwkgvvmvzqsxepffzkylyggxoumvczppnlpqxsgajqvcraswicfgzlhfmbbvgheecnquozstyptypidxfhverlojsednujcqzyxbanuxjyssxvhtdougahbvhqxzczvbupgbxeztvaiwrsdgfgqitfuitjbyyvgblcfmwlirrgfknecilmawtkqxjkvjphinfiipiuaccdhzwliqmpvfxjpyibbvdcsopdhazkahsyolmqkzskdaxmvuurmiyepqeejotmbalmuohvnbgqrrryyxoyarggvdhhcfysvryioxfbyffmlunmiptxebijbuybenicvjrlwurymwfpjdaiesfmyhybqeweklmespoyavsdtexvaroeaunmwkivffmdtzcudlvhpczkefqbqlvqbjaghrzohietzavwvxxvedcjgunlhxsgowgbjzlwsufzfhlocajuhinqoqkwbpxsokwamhyxtvoivhukrtufpvcxhhwuoeawwhpasgulxvpxqflohryyknkubkceopapepkmzqympdzxomwzpymsevopnkywlwrzjykjrmlysebsigfiggfheofsatzjgdfzdwjogsfbhkpipjatdmhfqzxtpzexbijdyjdnriiievawzdfnmvxbtrqhxbvxgqtuokdtshcwoatauavwkaanwmqyjsbmvwtwxqquhabvwkkypepsixczqrprvivtbsrkubnhcraqykmrbpxjweocaywkwqqxwgumbnbsvotloekfkgnojgznmnevnwenslidezmivsipxskzlpzdfhhudzpbdxzwrjbbnogbyrwgjabqqsjdfyltfehodmpubkeyfnwxwdlbpayxogeanmghahqsnzpabyxacojnpzpueemylkoqpzmcidinwcdeepahfbifvkbrqlvnymzzqekikoiebubpajsfnlmjxynaunxhkkwcglfecisipcsqaypijzjuxnjlqnsfbmbhcxwsavglhsrhigjjsdqldfiwayvshrftuoxjwcvrmhvblnvmhtgmrpkvdscpzaiyqdyukfdwwziavtzoyajllgrcmxvwfzecfrjkvwaeahtqrqzviduvskrbleprfgtvzovdmrbelczysfdzafwsudzwemftlgluzteyzmcntqedjsqjwensvweprwgvtvrzjgavxdxbjzzifjxzbkcidqfnooxonbyjunibhprhlifcsrnadoukujkmtokwbdgxhvpbfumjeuzahtmnsbrvkttjxziumihncvibcckoahbhaphcpggjseymqakdavvjqaczlwysrkvextvpthyfutaetngqfduboilmwequaukikdmcomrdsfellscboolthxoixgkwzduqhsydnnygeqhjnnhwiiqhwxrpgmhqhfjxvdrifxchcczesgxmtbspeqlmjuhymffvkcvznpznjucvzngqgrxxvgvxbocqfwttehpkqqodjbatiduvtndxmujhgncetiahfzkddfkikptawxbkzzjensuwufoyyqfgzlkpfkazaskgevdeavhfcjtzfikwftaafpprclmvnuraehcunmjgdilcmyakzpwgvprnzwhheswfgcwejtdazfqqbubibsuplneetigxnnqzjbbyqsrsndrujhfukxluvqjwyihynlbjjjvnqrwusefdxjqostnwjhktopvmneiwlsqriobvjqcyjbrngsgsbcuaapxcqltkksshnsarzfzizlitonubgtzrkkhyoywqoyrfdkralbvmepptkajswfjbbymlodawovvqhcawlqupaivayazohogwibrxednbfvrgslxxgrjinjeqyyoidgisbvaoltxtghfmmrpdjdlkjckwhmjjkmajbzalglcpedtzwyoktwvmktnfdncbjxjbnzsmlfozuxgwmxmqnjfqjbqpvzxtmzzycapddkktndlmrqizldbzaavciitdxkgazfftnrpjrbhgvcmrclzdqccosppcyjwuxwnnhqfhthgrwfzkngchoyulklgolfhobikldjshsbnuphjerjortnhpactwruunlaobjfclmphsixgsxfpuizyonduhoqmncoeoxwhvcviyrpqehoanvaxsnvdgwqryzmwcuuadecpvsclxkoitlgyrochrfeidknrnostmbmnfjdcfbvclugdupenmdqcaudsafokyhczbomavdxraivgwkcwmflsczponlywoyxbxufvzpmzporubznjymwcatqotlinabpnopyvpaxmfsmuspqakozwyvoyyraizusgcqukxbdplvfwhfjyypesmukjvtwdfwdtwukkjsetcythejsppbbxqwkzqhfgxzznhoqgdmytdlicnjemmdjjolfbczrvqzizuuoklcmooguozvksarpkuvqgqzwacrjfenvpxwzmqejjqgerpevrmthixhbshrlacrlvxvqonjydlzclmmnmiaiaukmsxaabragyvizjmhugkgjkdfyjoywrycrgeoiqsodnzcgrtwhbpbiqfalpvzkcitwjcgogiqlaemehhuherfyxegnoapqpxcrwhptwkeebzrmvsbtzyyprhrbizbpowlmurfnqptykyeqkyqtrbpvwbyuonoijdzhbgxphgxaxqdsvalxoyltmznyquchxhfudtctwwmkxzjrixgcwfaszgnweopimmjzbznjrjvjtbrwhclpgmtkrzsycqwqklhupillpskebbhlqssmakdumzpuzibsciopfvwrlkietropnwkputlrllfmtpfigkyjfmjlukqotugzqndpviipusaluvdmwubithizeuhfvyqtyvtltanazhywrmnfqxheehzttlugahkmhyuvgpvbtvilqauivbaclcptvrtwotygxlopjcqxtuirpldquwefibdulpzkpavfjxdioypshdpcdplzwnfznojszggaigdlavwupvvoyaewuevvnfmmkrscjhkvdqxgatthiruwzswgyumkernhdobpanbifcpuwecqxafjlbgkeorkriwctvbxrvfaafzendmigwqrfasnoaqddainzuryzmzxmvudulathdjnzfxysdikjzzfloornefbdwajzuydrpuulodrivwndaytunixzsfqbhoabazslxdcqkkczfcdtmfxrkohvaxkhqunbuljmuthlqojrxzzxsuzrtnrsnnooyrbzxglrmscdxtngwxxxcdgwqihrvsyqyohwksatsrylikstjmjfrxkioaqhtoxxkjztyeuxulmfmjsqqxovlwctjbndfvjdjxdzveuqczgssidyfltsitaogaejsxsigbmglyvfvmqzktldwqcbzykrmstwkkxvdkpsnsjqpcbgupghjqokknhaxcodgfmgmvsccymptmiizkdowpegfbmuqnxexgyamhynjdihlptvrpuenkqvvwrludyoilyrkrvyazeqpkgojhdqesecdyatztcwqsqjuvhgiafntuyerqfnpzzoqxkrpuemkfaxwuudtcncrqyzseentxelxfvxelihnkmaetgosrqzlybnigoyfudygeknupyashjzjydmlvbeftnkucvsvvjqjkzesshhkttjnurxjnydrmyozkxhqjtmxcaiphcvjwthvraodjrxcpthkuosqsphewmnteirqkscltemixutwklutgahkkfnoqfbdhrtfgzpuyytdxnvmwcrcqwlcmomokwvmevcdcjzkuukvjqnsrzsntnyjsrjwcorcldnmytptsbadqfjxyvkyhqwnvmdtdbnwjqavszormcrgekhvumooushqainmjnsmgksvkrrkjhybbjsbxkegbifahaamayykhwkbmqrawgmmrgcaoaljvifnpaihejvevkmbcnkpmihqgtowhlyqqvovveozdgyaawvlpkyniqovonyqqzacfvguctrruafppkqejtksakumqwcpwkjziwtabedujuyryysvyuoejxknqqzjithifvltdxydazozbkonccdfqeqvcolwgdackiqkpitvvcncfgkrfyhvsbzwmdcxnklguqrdnmkoeavczwuxiosxamkjytgpsxgidjgtqwzysxhyjunrzkaxkkzybsrewdebnpemzoswldzgelouabxgvctyhswgmsrtoavfsdhnvdhqnxchrtoqbcvyskmzdailqmliiyuwsiaipjsroiqswvjrejtkdsskuifafphdugsjdyicycpcyucuzxbhhhjpgxxyphoddhdtwmrvtxlqhvbgaeonywqlgshofihaipxrmbsvxzockokelzyixrmigencoiscrvolaolbsielzeytctiznwiaavocorhggchincedilqanigqdsxwawacupeqpprydkhomlozwdkxvmdvcckjhqfqwdhunqkkkhgnskfaildedwffelzixmwcprochpybawuztwbnygjaepsqhastdmltlftwwdwivofyuhepalekzapztqdqkbxrkjucakngjftoxjejkcbapyqocvxfccvvbihdhqtwojdtyplkqhrtbbbcsjfymotwmxfcrvxwqmkbdmndhhhgebaybdevujanwmtlbdijshfaqeiwrfwdhljthoweotzefqpvqmxfmjgsguafwvpdqqcvzazvaniflvzwwdjzpurddgdhqlxiqvdcrdtzeiuzuhvrrbaugqkedctuzybpygspdpaolugvnvxqacqdshabauuvsoaqfdplmpjnfuooyejyhacspyozpeaqjlbqyboesedoldrlsgoxneleiyrqmmzswolhnyzqiqzokxyuxhzhbboibzrfeuuvpwxlxxiuszdnowvhhakcbwobleewccjsataahndxonzkedhffxnoulnpdvuvrcmmjvkabouyihloznpfxigztgisnooyejuktlvnohsnpwcniuqqtouxvqvzckefsnkfkhmfcqbbtslrcolgbetcbqhjzfectddiyglumixkxtluqwegdchcywjjoohlcmpajojtaxdhkisqbxxcpkxolprajanuewhivzqifuuersixrlplhvtegrtgcyshhpsbtuckaqwwmtnzzbxvczflukbpttkioseilahdznsguroekkujisnxwadgdisrniqopbvexcxrfdbepcbqlvofkxdwwlhswihlbnrhvzcftluchdcfshehllpgagmneatwfzwhwngwmzekmorjegrkdznybbhpscptytahzohacqpzbufplkynestxqydswnyjmzllwqvtdbrzvsvacetkndvanvpzgcyihovowzbaukxvbmwdtspsroleogpdcbqfvxqzahvmtdptawjdujsuohfxfudajcrrwwfwlqnekhxhstsiypcwukvqmdefylyrdzcnswtbomehkiqftgnstabnndnjzmdkenagijqsqryptzckulhlahnpaynyebrdrgxbixvfompzgeqmqfpoadodyxlyuvxxoqdtyrhjhjnpmulfcaifhikvbrgffnljrgoxxvaqznaljqewnemxzvlbfwnfbxeuwlituulydyldwxrhjyclrscurtmqkblbujfabdbydhlhkpbgxolvtvsonynizfufdqfnjkquojqxqixatduwblelwndusvebllrqwofcfqifbthtjzhauvaqxjedudoywmgeabpbuuxbavurpkswgulokplpwkowqerlsvsolnwvnspdgzzucfucfvelpedgyonfxypqtivqffiqqhvjatngxdfbrcgeiukgpijarqeirdqrqevzdfdpyyrkflzgsqiytxyrpngshgojvmayushwoggqhpbvicnruelgapfhvqxmmkywzossnzyannddarrhjkllgcdlsgjtyykffmkmxezihxygeraopqsruvglgrgehmzxdqrfymjijnftbkkarmzcsblionmsszfwmpebibdconajzisdlqzvraiqvgcdnqsehalgidsmuhzrwrsdoopskjfbexoegnunzbkcukduqtxslbqqblhcdujfmfefcgpozvvderdendtlvnpaxmvjmzsmjwxxveurljzwfppocrazypgjlebeivxluxmgajtrcrtehskckbjcjdeyqrsbbgcnmfafexvqfjyctxhilmyvsjxtwlevtlxeboqzdrymseiwtakokozyvkmpckjhwympwwshjceyoawuflpdcevizbwlvmiyupzfxmembggcnqlbddnjynhzkknjxrurxxlordndjjwgqbfdkicptvioneieuwkzpdmhaihpvqeernjxclyvvqxltdylxghdrtviopsthrqbereoysiwpdsvylswuhnnpxouomcofdjuujloanjimjaeuxinalxwlahbigqkvwxtfoarqzkzriunyqegqdfwmulmhqxziiwivxtizbbljbstqqfdycauteotzggiqmfexcsudnnxerdvihnojblnoacgwczldpgowrsgkjwijakyagizayoimslpqntljdjeabdtcqlglchxsjkdepmhvbgyislhuwqkxbtixoqhheerwwtfsjwlnyldkytnrlukmbjqvhbquxgllgjzhntpxjcknrcaigexfygvyizucvnexqqqcdpqjcikubbspurvkzbxfqevyviioyvonvtxfmdlcpiysxpbcakdqzegfrjwwebtbkwptthaxqcrhrgtjrolrppympiixujmtrohrpnzikakcvgimdcogpinqhchqjeniqcojzziiiqeorkkfbkextieofwrnugjjyfzrwvcuvfkdqxlrvdexlsnddatcznwaifxqokxxfkhhtgfvhasgjcxbvnynypwygvvavkoscqhyktulgorqtnaxdghiwsxelwormdwijfssvguuhhujpkhudhgjicrdnnfxzpbrtinwuhttljsftzwuyhdjihwyosehuphcqksuwpxjqzybjgbcidxaumslixgfqmmgqffysyitkdvtnbczsodwyrzfdsdbofupwqxiqkywldivvohoppkijcdptiuleivqvfoayohlzvsxzgowlsndyavsnfhleepzdxbbawiuicohuxrutfkvlqxhuffejkmyrpjxzkfupllqciadtjhnuhukghhzxoiioqrxeydeqdmivbdhzlrfalyuxsgkdoaiupgatfqeqghlgwbldqvxidwekrvsnwvapofjtxptoltvackkljsaiqsfolxydobuqwrsgokdkjemdrdrxieimulmiovmmbtuazjcepfjiqzorrahguiycsonesaxlmzrkeoxywyxddqwkiyabzhhxjvhmynqcdceietyekcxopskltndguoyaqsktptlhsyfqvfqrnystedyfogjrylanbpiwavidpsgdgvhfdesrtnoofydenydyimtvahliycpausyowmixnxsklbgldgqnijlfxoiluqrlgsedgvervafoclccinzbrozmywecbincqwjjasklfrrmkwsoglmvdsbvsenjvspadybytpxeypogmoncakpvsogrfobhnmdswzhcxalxnrsiodmmjmusamtooxkfmmwxrreejnvmwavgqzcimkicpbaofffhfkclxjswobvukmkorsmmbsbztmmqhswvgimmpawgbwzorprefkiolqbclpxvvtqsuyxfprapedncawrvwyxyjludqzdtbykkgzzxelxezmieehvesbaxmpafbanfdfvdmtnoffnxmcefwvgwwdjnuzygxoeddviemzmthatigvqijiauupcjpzeiehyexpfmsvbjkvsakzljrlcvibcqvwcmovhbnthjewzsudiwhqahnayhnnfohqgdndnigbolnudwjjffvivjfmdjtsakricvfnyfcygrtwlwggqwlvrfuqwjgoumbldgqgehvmhxnbyxtoiaaxgxhxhfdqykaevpinuhklghpvgzkabnwiwcwodqwisyrkpyowstigluvebgaiwttwnzkuvmfcpmsuwasmbmvnlposzbupkhzpfgygbozivmejhhyvjxshbuuxbvnlzqwzbhjprkaqeogqxzdnsmkrmvbdlclnevjffzjodgkgisbuovjgsnmuhzfarvjcoxsxqjzcllibqcoihkgpprswugezllabltyivzwwieyfqldjkkbyfppusznvnsiwptritmoyczwnipfbllautpeydblqazgvydxesdgntkrvlrwxnujguqrrfnolugpxwsvyhivhraenemzxyxxcktrmhkepmpovolpbgmxblpysribkximfjmrbrbfufontaangpfjdbqkcvvwafquakdwiqttlqhohsptfyfmgvhzenghofcwzbnyonpzgcsgmssnscmoxveodvaldwcskxdrhpetxzihdoqghvsuxrwylvztmcyunpxcnzurokeffdkpeiznmbortzczkmbjylzajfeqjeacsniqpjyoebergheioyfhfucgpolqsykwdwqnuwgbymyakblhneaeowplgyewjrefkkxgiunkhwrcdoncooaykfxzylfgekejarojoxhrtrzkxpfysuhhezobuvyuxzcjzelliywbuohxgcyegvzucocwiihfqjbuwpulxngaxrrurbcytzwopdyippuyxhjruojenbzcjvvzjpctwkuflohskasumphpaxfkrzwqhheqiiemkvzlbcghypfmjnsshqrthxajdvixxfwvbhbetwxvaeqjduecehfzkofsobchrdqpqaouglovhjpckuclgjnrufdmaqfxookndntemsossbgrdahngewypzlhcwxirhyboeihprbackuiojvbleshhtetyrisexickxtvtxwuyajksnuwqbxuodjzxzsnxpuptqnrufwfljscttnoixvveiutgwyzcyubbugwoipreroyphjotjiefupxsobwsjdfzxurjdodxqspslsuotgltvjjmpvrfxrzsfbsjincvrxqzbaxnblvgvhkdkkjawfdlkfryipruwamtpaqpvplyexlkzqctteexoysmofgpthdyehcqvsvxpipqyiofnopxotekdbyspqroopohkkzqcoikuhvktwrgrqncgvsevlawkzcuudxzihfjnlvjvkuczvddvuiabgpfrmotfebhwtlwigzyikropxnfvtlvmzkzomltvpyoncybbdblyytyycrfpsicgsvzksqgemejeetvaxravacbyspfoylutyryzcewfadqhsnqlwwhzkvhsweyvvjcxfmmceqdecioftgdtuetdllhvxqjgxrhtnwqicuzvebslytyatcqlwldvbdkiyncvhpcaglnykzarxvylgmhabrygigthtuihniyrcaxfcukuocekcglwoukubxchvbwvvcpjbvfungoyazrvzcirlpafbwjyhjizxxlvemozkbwahbndlukmqstsoncwyivojibarktzzxqmepgwrbjjtperuhjyychghelbihbsqnasgnjuschbtpgssfoqwqjjicfdzrysuzlvhdvvqfiaxgohuubjemhxavfucupwmmadihyhtqcdzmdlgabyzgyyjyfxbydaqurffmggfzdfnnqmlmllaousvupvvxjbyxddleyudclwpzwdmbnrnidgrdidszdjgmkggzlissorrwjfddgixeomcvwklenifdhvgegyqfifxzstwioxcgoswuqjtqywwquybujwhiypebngdiraqcueeekdkvlgzzsaemrmerokqcrqfhzjbuvacskujlbyuptandooraxnqzoitortxakjivjndbflestdctbrqsdyruvwzujwsaeldfhhcdbfpqkizwatggvgpikezneqpuryzkdkczjifemhfnccwvrulifqeuosnmhwbkcfaeqbpetlvhgigifjbmpdfivlzatdshwxvbvyybpskrdpqotyipxfsohxlxwruavnbcjlsbaciogqvkjjdowmbcnkfjfltnriwqemxekjbmylvzvnrgxeekdepgkfpoitperbwartimmkfyjxpmpvwgcugtenpacxxzymybrtqtfduplmpktuivwnlxwfrvlqyorhvoavytaqgijhrgbuynfldqtlxnhpfdvlbxzegjkyfplxnxnhwexypdfudtyxjwsudxkzooidthzkuoyqnxjpszyynfzzmuaofusvfqcvxhrbgofeyefwpvplzdzydsyxdaobdkperkxjugpxnzepxkvhaakkydzxaamtdlvcfqqtnmgkqbxekihgigxelmgnkqpssdhjjbimnjboboiyxfsflnuxcpqrxoejuflkfjwicxlzdoxxpemomauofvdhrohocaapnbjwbvlrnscuunxfxhroqhfjcgyaqqnwszvrxqpqdkjkymiygwcnydbukbrbvqdtkpjyeeqkxiswkhkrxcricwhmqsauiztyzieubkgalgduxdyxermeknpiitlnrhocsecfzrgagzsrevawvhtcsuqxccusudzrbbtgwkdwbkbtfklshcapanqsnjggugrhywtouppmeaheuwpriffjmnicbyobgxhgexmksnurkbhgmahheuudqaulkmyeubuiyakpftlbfcnnmframtjghcyeegxbngnwmifflhsjnsgacfmwgtcdzhrrflolqangavivxmjerjfhyznewejvtjvojhvprwtjdroxvjpfzfcrdsvenkvgqdonxwtpqvpmmopdvnatqksfmutmseevwtdrpgsocgiyfzmdtgboaadmfmslbsfcuvhcxwgpqxqvqujrkosfduvxfjzfykonzwqvzvzxkzqigppuhfcabhmmlfdvubqcbxehywjltjyprzusjfpvmpisprlyszhpeyyjzzorxtfxlalefpszblfkqgxvgiubroswiwaaksmbhfohtqswlstrkooxwgimdwymiffoijobsqhxocipnriklewyjofhszrwrkjxxryyyfsdachjreudpjcqdcbhefxmjagzjkthrojpwmgymdvfuvyqkssjsnnwpisqkfmkstmbdjoeoqblyntvvhkiforfhifvgnwdtxtqdmwmjyouykvublnirayriijgxokgwisnvgnucdxjhjhzqxxgriablmloyzbbypzgfgwesvkwjbhbkrhnwxwarchejbixmocevuoidpkqkcwgbdqhmnxkdngllyrkuthaxkpyzpcuqqngipinovmvwpduzzfsmrvhrnamblypfmnrkzclyuggwgwtltmzruyolblwvkbytlbjryukcyknrpofhevilgzkqoxzcysydycqxttegydqxkypovobxvohxowrgnjxhollloxxmvqpidclnrwwpmisswtqzoosgvjkykfskiqmevegieatdhluvrffkhxinqtbmwvrprdjdfkeadrswkxygcvnjycnshbnbzlrohwbgimmqzcflwgzpdcmljttyzswzhjqjrdkzeuuauomgfvbijpxdvinhvwjrydoilzwumsuqtssjvlxojbqldlxsfqgswbuteejiahtrxjlrmefchfdjauockaewgziuvxpxvubqfwpsfalieclziczxthohobdbcehprhtfzcpwridippqekavvbkimmzphaajzcptduwjsqftcgbsqdwlneannbbtosvrafjwrjfsfabmourlzjdvuhpqeznqniybrcnblecnrdpmcimlxmtycvhphrzmltghdbgghqpkqnuedsqxykmbuuhgstcogoydumkaomtvhpknjbsygztkadowvqiptpnwwqhmxmepbfexjammwoeuvvagsbukxzosrvzrsheujrirwzasokqpaktgjrgqspgjnvycywucyalewtncynffzjahkwrcohbthdkxyvwrbazdsjjttwbrwjyphoxtqeqgnjlhypankvvfmeofieemcvgpeqwtjvhjklpgozrcdwjptgdhlsuegnqhmgmbjndcmsaupemiqjhqoojyeqtlytdejqbmktlpfqcvkagozgbeejxalkcfxzfjrzxipbhiwbfnhyokaapigbspxattkazejeiwlletvsnbkphalnrzazfwnppydulfiyaeiuyqppmjsbwjznhjiqnzrhiaifunigjitrjcgcjyqrzleyvnugsuzygdqodaptpzhzoxywsrghkzqpljvktzcbomugpgnocogbaryhahdmsvmrmdpbeqgiobgwuptuppppsbrvrvupxnvfcunlivhhnbxtcbebhukbvyvvmhtcrrdtqlmvlmhhcbeplsibaxhyaempzolhfcsxmccygkwojjnarmzehpixeqfhmngxlgcxrjtbrbwsemmtjmmysvpriawtxjgoaiccdmwcxfberbapwycoplmtjfavmdtwtorvncgwcbdwznwhlsfymnadyrsedpnibafzggvybymyxpcglbbqyrcogjntkwgjxboikuskrkmswigopiqfpuyvlismrzhravhujioylsdtnefsjvpfefkqoiajudnlxknllfphwiqyoaopojnrpagcdtuwlduqtufpuxxvbpzaxlavecohmdqqmhtdilkddjmraclqpbgzaenajssnpvoeowmzmcjmaxlnhuoyrnqqaqvrkswfvexzdlrhrxzplcwfbemlaoagvjxohwwpgmjormlucxaeqfcaqgszgiavokanoomwxxhrzliatfjwxsncjryyepknrkbwqewdkimfmoabppphnppcpamecapslkgjgqsohbmfpeixaugvuaeaqsgaxclgufjsbwehjlarxnblyryzlnbmtproblkuguflgemsitlslxxovxtellpnwqoslkrxrlmosxvxhuhtwskpblbjseipppiprflvdljugbezzjinncliuswdtmrmzqkstlinyxjvkmegwyrcpoujuozsefcscxaxeosugkmvxcupjyvyijdwlswxizzhfsxjinexdztvbslefecbljjhrlutmtrqoivhbpagpcqgjmtbetmwarhxmesmhbeclpbalsbxkgsmjyytuwynkunhugojivvniysfqofccqyaekvcndrkdubrbbpeodqtdqeebiwgzfwtyofmffbuqkgdtivuyfvqauihaspbecowgluhqnfickixbkskiyqejvqptsenrdfbaouqqaangrnlxaskfwlglpobdyafdverlrsdsxycfiiwwjpaljbqujeqjoezilfburkivrexsaqmeyvkprhinmkvqkkxdcfpwvmetgywarjzaxharauhuduecocwmpmgwvrpbbkusyxamrkuigwhaxlrufiolnctvscthrmxthbdivhggeypjsqhkrzzswvvorzgvlibiwvogsoskydhijleeaikmpeaxcytccokanquirbkegytqlmsjlttynmozlehauprkcmxeynzdmsxbxjvhasqwtsieirfauwxpifdciklqcwxiycwmgulqinxhnbzufzjbnmbkwpycjjkuolsfxnrzwvqbvrpaykvddylehrlexkdxqhctknrgghqtsuzimpcpkjzuqgfzaaexhtehmtuzfhvriuyaoyxgyvmibrwseruawlfabwszeukixxfoivkmmncnnejwposwqnycgaytolopuctknniiebxzpgtyyltqpprekbbrmqbflwawimifoqspcxzwnqdxgnpcjarsaqehzhsntvcmquxdjjwzlmixivjnllgmbjkwzxvvmdjasnukmoerjqphmuvatpwoildncsrzgwwcyoxcidxdkoislmuinhjmdowhzdnhdpptlyvpiusreczseilrqiwpbgqtafkwgfnwjnaxnjkisbgagtnksturmdhiwkxaqadwupoawaaigjhefpiexhnqdkijxcpyvkssobcagkjadopuwhbmnscuagwjnjrfoogbhdudrghowdpumnxhlqejlgrteemfhdovmtqpmxpnfthhbmiednkfvegpnwvhojbtdavgwfmkpetdyrrmayiikgagcbeafifxonpeockevwlfpkmqrcqinigqianomjtorcezfzhknpdpmnwvrsocqdkoodpxylrkitpltnkxbwefzxqqonlihcfsduastaicomqsrzlkbszicjncpwzjdoejiasaebxqzizsyxkntlyagpgcoistuejmhbehstbwdehebhdloqwqbyflzqdxryjypewxocllmmagdkugwnoamwmtklmrckvaqpiiljtucjwxfvzdrolwguwhzadiwmtnowhjfmooohgsdsqyfcjkedxrxttfynyysgrmfzvohyxfavxerxapjphogpgeqmpikcuyoysdvzyklbotpeyzvkmuhoouxemupyxdztxeuaaxzvncfxujptvevugewbojskkmlifhieolztmvzugkcznhdcseilwaefjvqqkqgzldzkmdxsykxqvotosayrpfkzjmfysgafycglxzvnxhjrlrtxeodkfnwjyfrizppntjngpypahhuhesgkxktlqybdouzyasngwgzlhfgikedyhitdjxzshfhzlbweevugtrljolczhaxecglqgqlhosgywgosuvrhmwxtunrpirdksmfrbbxlfgoknzaqgyxgciszicygndcncupbwpjvyzfywshppnwhjobcrjfzbyjrczcdalsnrwihkpibyznznullsqpzseotnukhfxpnivzrloyfpdauppzyiihesvmpawrjpszufdomrzygnvmqpjflzpdepmoyznwbuahrulnsftnwvtlucgohbyfmohmddsfuunohdmiwtihqsnmiwyxnfpsuhxiydvyjejjwaxyjjdyfipgtjrlrwbgycwvfrljokekkzuvlevsrrmhugedchgpzalnlycyzpocemrlwgakizxdxhhuwhxbcvqdjbnxlntuzxjoljtynfvdsarmxowothhcjpjwdedrjueiczvhdhvzvjlavxuschkxyidwnzcaucqhnxayohehheveamijgvzmqnubtconujewfnggisqpdcgymgfcwfqcchtvhvtrhpsnzdvwybovbgwunywrsivtbyfacmxjvjxajsplpnfttlnhbyxokskxnftmbaewjijqfmehtcyxnmdeackmjtrydyisytwbegsymsahlbveuyiybaabrgifjmyepdecqqfkykrgitfyvifswmjcezxcdtrczducxdyjiapjggejuxohkyxznmgrzhegyzxifejhcanbqnrhljgwmgtywcnffsvkwtytmyvccshycrjctiuzucfpthxnfdolpulqoprlzryjwvpfbfizmmapevylmjrlfidsghbawryhghumvgznjcqmtijllxvuuxpiofbuhdwyeforrvcyymmtwkfvkfomqybclteoqfifwoiedbxpncseeuasnemhcxtzqvucuveibywaacawxgplxfhrsqiyxaporvnulqmwwvxtrwhibuyhtdlktihzmnfxbcmzecvjdpyokkiizcecdoidmluukzzjrddhtdvwyeisxwsdoxgytgyqgjgjcoxzvzhiszzcpqjznuoguzpbhhbucygoamwunmicwdvjkvydvfmdbqqtbczugehpwcldknjlarkodhuzphnnmrgwrieyuxustkkhizavkvwmbseznguvcvwijciamzksgvghiqstgycaumqjdfzyedoqviaryszppvpnhvqfvkmbrnwvimhxgxdkxoplewqlswlwbjvrxharvdfvrdsasqhqzyxndztlgmftfkkteoiheuahuimihntchzhctezhdprgfpgfvlxxrcemduvaqifizopcbrolrkqkmngqnkjhpbuexfyzfyejsosmsqbpzhshdotksgnrgoahsljcnymhetufasunglvmuzwxepmdsuwoedlwndxsztgeesdvcyjrfryzibqiuntezjegjdiqaeogcqpzxqkmbaycmwyyzaonhxgexuplwfiodlcyoiacldyuohvupvmukksxmhgwliclayoyrkvhjvbsjjdjypdluoakdagphdsfncalpwvmaehsargabrmijhpvknumtjgtqzbpgegxflzgblczzqxnfglxlogvnggeyyjeebpaapvuyaxpwtrlwxytdagituuboemdifgehhgmsjkatwqoskqcjetochkmittwnkqnhahfbuiedpteumshslhtxmkgncgjltbqdijravxzkxxputqruhevuuqpdurguworxhxkqxcqpvfpwpvnzbxmjgxrpajzvdvtgkwoefwdeaotbeapqaqupkvoiykluxrpzgdlvftidvjryglmmkkjcttfqaryvojpgyfeofwigqjzlrnnhcdstmjqhjsojqdgndrdizjidkrpabztvnelspwacrnjfwxhbrqwcxtwiykpfpxdkmbkpioveuvbdmpxnfnrhpwksauprqbxcxdrfcjxruczzsdzprocrfhpkckjzvtodavodklpqwqhkknkrgqwbiqpyjikvmjxsxmwxpvxulovkrzpezdvbkbeqrroxdkzudnphocodenlxraarmgdzymbwavbscjxjynpeucanhefiatkpydsqaxoqsrsfryhrilsyghylpypsbwcuahobwmuqrnxwfscksigmymbajnuhkeksbcbqcfnztzahgepabbywkijqboolekpgfgdbckylcyhwwodxusesbbhkkpbtdslnhkjbfactiuwownbgfezvfhuyrlzenxeigtjoelhcvrzgcppchraxpurzohwwiroreedqnuowrsektacvzaqnjblakqxtwyfomgcskrygusvuxjrtbppwvartyuqoqammlqsldzstbutpkwvochacifhoferdidjgdbtzceltmdafjmzwvkdjwbkubbagtwrwbtlcqzimvnmcafixfwvfhmteaqnovhbcgggdzfodbborphlcwenrrntssgapwkqrbbeqishxrpqzgyapovriwktficsfppvaenbhfgiqxkwsvqsbqseotvbxytzgyfqhhvbyszmakksyzairweznjgkdwctmpwwnoppvqzfahuiyjoebswovbttcnqwjeugniaerjagzvgmtilhgizbtgozcgqgycrddljrvhenlnnqjqpuuplsyxvnyinkxpxujdheoidqvphvcjwgfqubgniauuiysrfnwfuijytgkfzdpbvgdozfnfliskqgnvbbvkmjgcdwqcmykjmnynjycbvsigpwltmamnwdprcuckljvoqwqwjksfofapwehplowndkflsrgnpjpfcloaftxqbsoyflfmoxneseiiaqebncnqinzvcmpgaajifjkaupuwgssgriafyfdzrbagkzmfgpuoaycrabqkzuslhcicpyrukqtqdmlorgvuhwdyobzjhbiqdtijdnjszpohctlrsqclhxqdcuqivkmxztxqehgroqcmrawccmbivgyeidliugietpmsxqxxvczeafmwftevnzzdsowrnracxzlogrwhqaqyycqhrxzprwlzagaaoeitlbkeivpjobgmogbpwhtrirpqikaqypysfhbdjjpteojddfftmabvbwhkrpozxbhbrvglimnmgdqasxkjzvpqkpzmcgflsbsshuvjremmrrtbnfknprxppncgbkybhfcgjsrdpelrqlbnqbumwolcxexjrmrdlggrxxanguhajqoaiwtykjfgtocficbhdhbtznfvlcapbvzdblrpymjuibxkpbwjsuheshpovkfoqyljdievhvcowtuykyuptdzakfcrxbyrkiuhrxxlbeyjcvobqsndptroqancmttbyyvufdwqzpciyxoabutzzhfviblyfausqpoakyhlznfjvjqlrcczubqwdfsavwogvifglkhyfglrrbehghbunqwrpmsaaxiovgxitnzomblnxrbyowrwggggzpizgxoucsxxadlmmrcaqtckjvzhssztiqpsqofsiwyssavscimwjwjcndpirmgdgjvyydvflrolgpqyahbdjyacwqjswlsfjrqtwowbygthdkgmyiurvnhwkhvxxaaidxvwbnfqndglqucmclnnqmtgpykahxcaizbedpyhhjcqkyvdovfrxgpnasncgqstokqnlwcoorsstxkbyprtnbtjxszmbscjlvnqihkzmqkqnripsxposgfedyjykrctynxerlwqalsjfiinvkunsnylmfldylitudkrzqsmkbltutwdpdqxounovmtsyuelvihmvgukxxedbzuepryjsqsbcmtzdgxoysgoaajtebdcslawrptvazfxayazcrxykqlxzaxfxiqegaoremtshgcewcdluvydrhwutcomhdcmdsopiuwvnuygalvosddsmmxezgqozfedlgidiwbkhvkcgesivrgvzmqqiavexdmdrgrffhxxgpiqwkujkjlcolcadshnfxhfnofdnmqnppqaiymadkuepightrfodmauhrsyvuhctzscenlqbvfxggmygvtqtvbhwdaoczloprvfwwmoiuuvbsylfurqobkifaidqqmhitgpynnnhmwyajqbcuabjlw")<<endl; 
    return 0;
}
