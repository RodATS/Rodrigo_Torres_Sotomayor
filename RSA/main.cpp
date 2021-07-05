#include <iostream>
#include <string>
#include <sstream>
#include "algebra.h"
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;

string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890[]";
string datos="Pablo Luis Carazas Barrios 201-10-47470 71569511 Daniela Alejandra Chavez Aguilar 201-10-47515 71646137 Paolo Rafael Delgado Vidal 201-10-47577 70671343 Giulia Alexa Naval Fernandez 201-10-47725 74698876 Rodrigo Alonso Torres Sotomayor 201-10-47891 70512744 ";
class RSA {
  ZZ d,p,q,oN;
  public:
  ZZ e,n,eB,nB;
  RSA(long bits){
    Generar_claves(bits);
    cout<<"p:"<<p<<endl<<"q:"<<q<<endl<<"n:"<<n<<endl<<"e:"<<e<<endl<<"d:"<<d<<endl;
  }
  RSA(ZZ e, ZZ n){
    this->e=e;
    this->n=n;
  }
  
  
  
  /////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
  string cifrado(string m)
    {   ostringstream c,r;
        long num_dig=Num2Str(alfabeto.size()-1).size();
        long k=Num2Str(nB).size()-1;
        ////cifrado mensaje////
        while(divi((m.size()*num_dig),k)!=0)
            m+=' ';
        for (long i=0; i<m.size(); i++){
        long l=alfabeto.find(m[i]);
        c<<Completar0s(l,num_dig);
        }
        string C=c.str();
        string Cifrado="";
        for (long i=0; i<C.size(); i=i+k){
            string bloque=C.substr(i,k);
            ZZ cypher=right2left_binary_modexp(Str2Num(bloque),eB,nB);
            Cifrado+= Completar0s(cypher,k+1);
        }
        /////rúbrica y firma/////
        long k2=Num2Str(n).size()-1;
        string d_F=Completar_datos(datos,k2);
        //while(divi((d_F.size()num_dig),k2)!=0 || divi(((k2+1)((d_F.size()*num_dig)/k2)),k)!=0){
            //d_F+=' ';}
            cout<<"texto divisible"<<endl;
        for (long i=0; i<d_F.size(); i++){
            long l=alfabeto.find(d_F[i]);
            r<<Completar0s(l,num_dig);
        }
        string R=r.str();
        string Rubrica="";
        for (long i=0; i<R.size(); i=i+k2){
            string bloque=R.substr(i,k2);
            ZZ rubric=Expmod_rchino(Str2Num(bloque),d,n);
            Rubrica+= Completar0s(rubric,k2+1);
        }
        string Firma="";
        for (long i=0; i<Rubrica.size(); i=i+k){
            string bloque=Rubrica.substr(i,k);
            ZZ signature=right2left_binary_modexp(Str2Num(bloque),eB,nB);
            Firma+= Completar0s(signature,k+1);
        }
        return Cifrado+" "+Firma;
    }
    

  /////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
  string descifrado(string m)
    {   long p = m.find(" ");
        string msje= m.substr(0,p);
        string firma=m.substr(p+1,m.size()-1);
        /////Descifrado//////
        string Descifrado="",D="";
        long long num_dig=Num2Str(alfabeto.size()-1).size();
        long long k=Num2Str(n).size();
        for (long long i=0; i<msje.size(); i=i+k){
            string bloque=msje.substr(i,k);
            ZZ decode=right2left_binary_modexp(Str2Num(bloque),d,n);
            D+= Completar0s(decode,k-1);
        }
        for (long long i=0; i<D.size(); i=i+num_dig){
            string bloque=D.substr(i,num_dig);
            long long pos=Str2Int(bloque);
            char a=alfabeto[pos];
            Descifrado+=a;
        }
        ////Firma y rúbrica/////
        string Rubrica="",F="";
        for (long long i=0; i<firma.size(); i=i+k){
            string bloque=firma.substr(i,k);
            ZZ signature=right2left_binary_modexp(Str2Num(bloque),d,n);
            F+= Completar0s(signature,k-1);
        }
        string R="";
        long long k2=Num2Str(nB).size();
        for (long long i=0; i<F.size(); i=i+k2){
            string bloque=F.substr(i,k2);
            ZZ rubric=right2left_binary_modexp(Str2Num(bloque),eB,nB);
            R+=Completar0s(rubric,k2-1);
        }
        for (long long i=0; i<R.size(); i=i+num_dig){
            string bloque=R.substr(i,num_dig);
            long long pos=Str2Int(bloque);
            char a=alfabeto[pos];
            Rubrica+=a;
        }
        return Descifrado+" "+Rubrica;
    }
    
  /////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   ///////////////////////////////////////////// 
  void Generar_claves(long bits){
    bitz=ZZ(bits);
    exp_bitsminus1=exponenciacion(bits-1);
    expbits=exp_bitsminus1<<1;
    expbits_minus1=expbits-1;
    intervalo=expbits_minus1-exp_bitsminus1+1;
    pyq[0]=p=GenPrimo(bits);
    pyq[1]=q=GenPrimo(bits);
    while (p==q){
      q=GenPrimo(bits);
    }
    n=p*q;
    oN=(p-1)*(q-1);
    e=divi(random_numberBBS(bitz),oN);
    ZZ ee=BinaryGCD(e,oN);
    while(ee!=1){
      e=divi(random_numberBBS(bitz),oN);
      ee=BinaryGCD(e,oN);
    }
    d=inversa_1(e,oN);
     }
};

/////////////////////////////////////////////  /////////////////////////////////////////////   /////////////////////////////////////////////   /////////////////////////
int main()
{ ZZ e,n;
  RSA Alice(512);
  RSA Bob(512);
  //e=Str2Num("290514897511153885887794943339173992165");
  //n=Str2Num("35290790830208760546086632587874503330259961290434468506368498861514990357329");
  Bob.eB=e;
  Bob.nB=n;
  Alice.eB=e;
  Alice.nB=n;
  string m="The idea of an asymmetric public-private key cryptosystem is attributed to Whitfield Diffie and Martin Hellman, who published this concept in 1976. They also introduced digital signatures and attempted to apply number theory. Their formulation used a shared-secret-key created from exponentiation of some number, modulo a prime number. However, they left open the problem of realizing a one-way function, possibly because the difficulty of factoring was not well-studied at the time.[4]Ron Rivest, Adi Shamir, and Leonard Adleman at the Massachusetts Institute of Technology, made several attempts over the course of a year to create a one-way function that was hard to invert. Rivest and Shamir, as computer scientists, proposed many potential functions, while Adleman, as a mathematician, was responsible for finding their weaknesses. They tried many approaches including knapsack-based and permutation polynomials. For a time, they thought what they wanted to achieve was impossible due to contradictory requirements.[5] In April 1977, they spent Passover at the house of a student and drank a good deal of Manischewitz wine before returning to their homes at around midnight.[6] Rivest, unable to sleep, lay on the couch with a math textbook and started thinking about their one-way function. He spent the rest of the night formalizing his idea, and he had much of the paper ready by daybreak. The algorithm is now known as RSA – the initials of their surnames in same order as their paper.[7] Clifford Cocks, an English mathematician working for the British intelligence agency Government Communications Headquarters (GCHQ), described an equivalent system in an internal document in 1973.[8] However, given the relatively expensive computers needed to implement it at the time, it was considered to be mostly a curiosity and, as far as is publicly known, was never deployed. His discovery, however, was not revealed until 1997 due to its top-secret classification.Kid-RSA (KRSA) is a simplified public-key cipher published in 1997, designed for educational purposes. Some people feel that learning Kid-RSA gives insight into RSA and other public-key ciphers, analogous to simplified DES.[9][10][11][12][13] A patent describing the RSA algorithm was granted to MIT on 20 September 1983 U.S. Patent 4,405,829 Cryptographic communications system and method. From DWPIs abstract of the patent The system includes a communications channel coupled to at least one terminal having an encoding device and to at least one terminal having a decoding device. A message-to-be-transferred is enciphered to ciphertext at the encoding terminal by encoding the message as a number M in a predetermined set. That number is then raised to a first predetermined power (associated with the intended receiver) and finally computed. The remainder or residue, C, is... computed when the exponentiated number is divided by the product of two predetermined prime numbers (associated with the intended receiver).A detailed description of the algorithm was published in August 1977, in Scientific Americans Mathematical Games column.[7] This preceded the patents filing date of December 1977. Consequently, the patent had no legal standing outside the United States. Had Cocks's work been publicly known, a patent in the United States would not have been legal either.When the patent was issued, terms of patent were 17 years. The patent was about to expire, on 21 September 2000, when RSA Security released the algorithm to the public domain, on 6 September 2000.[14]There are a number of attacks against plain RSA as described below. When encrypting with low encryption exponents (e.g., e  3) and small values of the m, (i.e., m <n1e) the result of me is strictly less than the modulus n. In this case, ciphertexts can be decrypted easily by taking the eth root of the ciphertext over the integers. If the same clear text message is sent to e or more recipients in an encrypted way, and the receivers share the same exponent e, but different p, q, and therefore n, then it is easy to decrypt the original clear text message via the Chinese remainder theorem. Johan Håstad noticed that this attack is possible even if the cleartexts are not equal, but the attacker knows a linear relation between them.[22] This attack was later improved by Don Coppersmith (see Coppersmiths attack).[23]Because RSA encryption is a deterministic encryption algorithm (i.e., has no random component) an attacker can successfully launch a chosen plaintext attack against the cryptosystem, by encrypting likely plaintexts under the public key and test if they are equal to the ciphertext. A cryptosystem is called semantically secure if an attacker cannot distinguish two encryptions from each other, even if the attacker knows (or has chosen) the corresponding plaintexts. As described above, RSA without padding is not semantically secure.[24]RSA has the property that the product of two ciphertexts is equal to the encryption of the product of the respective plaintexts. That is m1em2e  (m1m2)e (mod n). Because of this multiplicative property a chosen-ciphertext attack is possible. E.g., an attacker who wants to know the decryption of a ciphertext c  me (mod n) may ask the holder of the private key d to decrypt an unsuspicious-looking ciphertext c  cre (mod n) for some value r chosen by the attacker. Because of the multiplicative property c is the encryption of mr (mod n). Hence, if the attacker is successful with the attack, they will learn mr (mod n) from which they can derive the message m by multiplying mr with the modular inverse of r modulo n.[citation needed]Given the private exponent d one can efficiently factor the modulus n  pq. And given factorization of the modulus n  pq, one can obtain any private key (d,n) generated against a public key (e,n).[15]To avoid these problems, practical RSA implementations typically embed some form of structured, randomized padding into the value m before encrypting it. This padding ensures that m does not fall into the range of insecure plaintexts, and that a given message, once padded, will encrypt to one of a large number of different possible ciphertexts.Standards such as PKCS1 have been carefully designed to securely pad messages prior to RSA encryption. Because these schemes pad the plaintext m with some number of additional bits, the size of the un-padded message M must be somewhat smaller. RSA padding schemes must be carefully designed so as to prevent sophisticated attacks that may be facilitated by a predictable message structure. Early versions of the PKCS1 standard (up to version 1.5) used a construction that appears to make RSA semantically secure. However, at Crypto 1998, Bleichenbacher showed that this version is vulnerable to a practical adaptive chosen ciphertext attack. Furthermore, at Eurocrypt 2000, Coron et al.[25] showed that for some types of messages, this padding does not provide a high enough level of security. Later versions of the standard include Optimal Asymmetric Encryption Padding (OAEP), which prevents these attacks. As such, OAEP should be used in any new application, and PKCS1 v1.5 padding should be replaced wherever possible. The PKCS1 standard also incorporates processing schemes designed to provide additional security for RSA signatures, e.g. the Probabilistic Signature Scheme for RSA (RSA-PSS).Secure padding schemes such as RSA-PSS are as essential for the security of message signing as they are for message encryption. Two USA patents on PSS were granted (USPTO 6266771 and USPTO 70360140); however, these patents expired on 24 July 2009 and 25 April 2010, respectively. Use of PSS no longer seems to be encumbered by patents.[original research] Note that using different RSA key-pairs for encryption and signing is potentially more secure.[26]";
  //string m="Obi Wan Kenobi dice Tu eras el elegido El que destruiria a los Sith no el que se uniria a ellos Se suponia que ibas a traer el equilibrio a la Fuerza no a hundirla en la oscuridad Darth Vader Te odio Obi Wan Kenobi Eras mi hermano Anakin Yo te queria Fue ahi donde comenzo la triste historia entre Obi Wan Kenobi y Darth Vader Todos los espectadores sueltan una lagrimita";
  string m_C=Bob.cifrado(m);
  cout<<m_C<<endl;
  //string m_C="32192983927330563192317032927005562967986057899881121197075876255596420928776144562160325110531825731758541185096692591956600109100318106798258815288107142701287626428588549165543987120942490744174620381054786931546986766286566058721698169733484382339836999146017143562572884926242109200533127241075884755109393137217680377632560647287667399638581674170903831258506704840318590202295752478630129210969613311147305118068380619996394430103765232720440082222602682721799618747381968693700396574178291372935041219153493168343421738754217694615194042397619359328847563253869070275974892872806773451812204543343443970977690783054177488506803283621702015310518374543220505998192671722076300665558676012929441245754959781154467798932220747015765365471580525422985285668069120336 0885137568271260800739955532874371854151295600468237488908021777930061052955707829218427837789697613862773322442261468810611796052409980640490535161361938425457653240827837637722255896600318800276193727871550873493007230124218374802292705195628193103738633315440348248556910519241560132968885276509254868663742219368183490715683788667162381887943613690141868424034558526207776211668430437444614260297297217735958315829389542642640951023773151373615844157673599791532150762293439712274090059021321987907521944866724123543171029399903184416137394261644073295526884340693335918030574258366407634395051312613260836802001435530878421819106477354046067017078831778506711841818253793895790174799532114227924049996134688316400274650735394845096366333090360838856735635928256929009627800865377977033361862410887987138228858615687777929481252439834511746353050477820218628938272595277160379020471156066908794977675590178973396636884204226650079151530610403000309656199349879317275943006253788709710826642280526508309775628253070738397943428828991068668765098551214266273556825506459458071077166351325074332809197668542115699358725908323802673862677907915866182775242554627932715917905546860776966170952343745712674704512252909594486090670460310231049477842244780500758778666657749026015803652460472575346813664215808759037868983326363266477484646882860396985467922655377537316281395767448922662841456072538149237263492639845565800955152043638847324170524459545326579460512811954042748191157448332366148908302322247863176316598634524908227289905467116188219317567180138175433021686708837620342340624183165756344670286870558823772593090969970860750583366634245333408605398464192712759473550690042293793153440775152456454975917614948439644494996920651421149149026385442242083398759220048419583495135133229599063757603198127782123103052011006598384580531672774383288217293080982304857761558719413217995139901958054539484816246340969265722438565287602426516043613006694756346111224408336478352055721976753336382074478082939055302079973062499656101289180849891546377063001376104583792737992333250386061746568509737219064030897181587256075224712152270774640207130555454397843282123793350898441627756099250423808699862223727833901120006770026532247269082013539996756879457555621084519704396795847364066317318235603268588281127522212203603749009608813928338272224644042701105616017786276775335656418956540122070295010174229083638999552706555316870465420689047363751507285144443545665097152514276259207792526783898118431123402703256306565978580176655301713356551364096237267391785669115022354955396351059959771199344642144426142876411813036476880912998642799070086101764845522016948317135642975495215890595548058190243617754986959325337330718201694169117629395236273673260362902453369104837820902282619123041949107680532532449501020154139841669080165327688809068913931732146662726025494776207609027392553612995806167057851110346061253902467812450190536493779024316670915273942116177411172940835906960124211639152118767529412661206932880370643151780355023492749411631839252166161279195600312257081801945981678679062252643180790708579000421411926638053481831215093296908142585337226260565527541545372035539839012213785257130569638050294814067017186686075941221358045008363049052427133489287711058157589382570510419472270405193042309619003628501354417160533860005971948126498668985034466677183096197422966213546199607833731204065300548271678770781888174656462336113690005927487290244011651359033280490377808741790009084072909378790015890411006263504836540941897571626369041486860609670927032349039473423127620936816172144211825346957183547845399556168393963639537882303555206440352453840205106979017812153120297148744171176088996270955802234589295056897965658780142488789835234191569757920287906539147683919992157816101284315653148681804006258019384863225065003894752141396161328878142690082278806455780298653061095105559079246805252288549966628841443411808424984718361116742693210445309822761249583131479441089653225904353858042829919173936622690792278036482602113473777186481531762325967853916734496680191389782690226865379269070906345818660924962364809827466003133739605764572994499405528071644485356377356515351540842630796265508155279057322487214518303113741515604416373519696916165094207187964650777379699962960166237344687354908308837749873574619923096843473644319860968102491282882905610810860180170219580722592373166318968931259060373089795123947687858694752223534019162596449958541884024546647823426840218262234710408142130696889144049984711291258399511717089154520576344231360530734297118818072797476431843217489034471772380974879253883554435758242395809467981292203877466680413020775031728981931377867158279801214313394614124819855784040189967265279223764985624970488272278277011437309138013066903166459012981536461144879937494950910430930116857880472329971057570082180455025311460628602084947502113787587715424313302338042269742958161607529852007333705424355986332220659465660816492314834611244540742683469328142957283467783868566947983977102244362291826040889994703701068993135404079483403522380745925299254547876869308462427618617077337985832503714684717341900854697832087950521868960801528253797687963855850561033570015389652940824282601161960161512168286319576975362224601021545044241757487623305320642284607241134287631579058072105249257452902762455275360451075482421814310848273310257093319538305892046015312336434803557984299400967693321329914671976264254264738851438390385031320030053957304397827179831083588349588934805934343043688802382441848674160993090982312982654524626774433636903131665453510633909231200652935704500932350513057691485926138714105589297252782629950719828606426812947050151939623367815245835499395498969901211919669756967740577361567715298802574710535858741947303567451126047571476931497288156073318198949224715593343835423067614522706370748284892774619400537071930806508048353761982892418427930331620456587511";
  string m_D=Alice.descifrado(m_C);
  cout<<m_D<<endl;

}
