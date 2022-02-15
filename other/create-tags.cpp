#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define vb vector<bool>
#define vs vector<string>
#define newline(n) for(int i = 0; i < (n); i++ )cout<<endl;
#define infor(vect) for(auto it : (vect)) { cout<<it<<endl; }
#define ump unordered_map
#define mp map
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))
#define MOD 1000000007

/*
problem statement -> create-tags.cpp
Problem link -> source
*/

string getId(string tag) {

	string id(tag.size(), ' ');

	for(int i = 0; i < tag.size(); i++) {

		if(tag[i] == ' ') {

			id[i] = '_';
		}
		else {

			id[i] = tolower(tag[i]);
		}
	}

	return id;

}


vector<string> breakLine(string str) {

	stringstream stream(str);
  	string temp;
  	vector<string> tags(5);
  	int counter = 0;
  	while(getline(stream, temp, '-')) {

  		if(counter == 0) {

  			tags[counter++] = getId(temp);

  		}
  		tags[counter] = temp;
  		counter++;
  	}
  	return tags;
}


string getTagObject(vector<string> &tags) {

	string obj;

 	obj = string("{") + 
	string("\n\t\"id\": \"") + tags[0] + "\"," +
	string("\n\t\"english\": \"") + tags[1] + "\"," + 
	string("\n\t\"marathi\": \"") + tags[2] + "\"," + 
	string("\n\t\"gujrati\": \"") + tags[3] + "\"," +
 	string("\n\t\"hindi\": \"") + tags[4] + "\"\n}," ;
	return obj;
}



int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        freopen("../io/err.txt", "w", stderr);
        auto start = high_resolution_clock::now();
    #endif

  
  	int t;
  	cin>>t;


  	while(t--) {

  		string str;
  		getline(cin, str, '\n');
  		
  		if(str.size() == 0)
  			continue;

  		vector<string> tags = breakLine(str);
  		cout<<getTagObject(tags)<<endl;




  	}

    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
        fclose(stderr);
    #endif
}

/*

	{
		"id": ,
		"english" : "",
		"marathi" : "",
		"gujrati" : "",
		"hindi" : ""
	}


162
All Crops-सर्व पिके-તમામ પાકો-सभी फसलें
All village ponds-सर्व गाव तलाव-ગામ તળાવો-सभी गाँव के तालाब
Annual Crop-वार्षिक पिके-વાર્ષિક પાકો-वार्षिक फसल
Annual Kharif-खरीप-વાર્ષિક ચોમાસું પાકો-वार्षिक खरीफ
Any changes-सुधारणा-કોઈ પરિવર્તન-कोई बदलाव
April-एप्रिल-એપ્રિલ-अप्रैल
Aug-ऑगस्ट-ઓગસ્ટ-अगस्त
Average Rainfall-सरासरी पाऊसमान-સરેરાશ વરસાદ-औसत वर्षा
Canal-कालवा-નહેર-नहर
canal water-कालवा पाणी-નહેર નું પાણી-नहर का पानी
Cattles-गुरे ढोरे-પશુઓ-पशु
CCT-सी.सी.टी.-સી.સી. ટી-सीसीटी
Cement Nala Bund-सिमेंट नाला बांध-સિમેન્ટ નાલા બંડ-	सीमेंट नाला बूँद
Change Password-पासवर्ड बदला-પાસવર્ડ માં બદલાવ-पासवर्ड बदलें
Check Dam-बंधारा-ચેકડેમ-चेक डैम
Contact Details-संपर्कासाठी ची माहिती-સંપર્ક ની વિગત-सम्पर्क करने का विवरण"
Contact us-आमच्याशी संपर्क साधा-અમારો સંપર્ક કરો-संपर्क करें
Count-मोजणे-ગણો-	गिनती
Cr. Lit-कोटी लिटर-કરોડ લીટર-करोड़ ज्योतिर्मय
Credit-तुमच्याकडे आले-જમા-श्रेय
Crop Requirement-पिकाची मागणी	-પાક ની જરૂરીયાત-फसल की आवश्यकता
Crop water Requirement-पिकांची पाण्याची गरज-પાક ની પાણી ની જરૂરીયાત-फसल पानी की आवश्यकता
Crop water usage-पीक पाणी वापर-પાક નો  પાણી ની વપરાશ-फसल के पानी का उपयोग
Crop Water Usage-पीक पाणी वापर-પાક નો  પાણી ની વપરાશ-फसल जल उपयोग
Crops-पीक	પાકો-फसलों
Dam-धरण	ડેમ-बांध
Debit-तुमच्याकडून खर्च झाले-ઉધાર-नामे
Dec-डिसेंबर-ડીસેમ્બર-दिसम्बर
Deviation-बदल-વિચલન-विचलन
Domestic Requirement-घरगुती पाण्याची गरज-ઘરેલું જરૂરીયાત-घरेलू आवश्यकता
Domestic usage-घरगुती वापर-ઘરેલું આવશ્યકતા-घरेलू उपयोग
Done-पूर्ण-પૂર્ણ-किया हुआ
English-इंग्लिश-અંગ્રેજી-अंग्रेज़ी
Evaporation-बाष्पीभवन-	બાષ્પીભવન-वाष्पीकरण
FAQ's-शंका-ત્વરિત પુછવા લાયક પ્રશ્નો-अक्सर पूछे जाने वाले प्रश्न
Farm pond-शेततले-	ખેત તલાવડી-खेत तालाब
Feb-फेब्रु.-ફેબ્રુઆરી-फ़रवरी
Fetch data-डेटा बघा-આંકાડા લેવા-डेटा प्राप्त करें
ground water-भूजल-ભૂગર્ભ જળ-भूजल
Groundwater-भूजल	-ભૂગર્ભ જળ-भूजल
Groundwater Available-भूगर्भात उपस्थित पाणी-ઉપલબ્ધ ભૂગર્ભ જળ-भूजल उपलब्ध
Gujrati-गुजराती-ગુજરાતી-गुजराती
Ha.-हे.-હેક્ટર-हा.
Home-मुख्यपान	-ઘર-घर
Household usage-घरगुती वापर-ઘરેલું વપરાશ-घरेलू उपयोग
How to use water budget-पाण्याचे बजेट कसे केले जातात ?-જળ અંદાજપત્ર નો ઉપયોગ કેમ કરશો-जल बजट का उपयोग कैसे करें
Humans-माणसं-માનવીય-इंसानों
Jan-जानेवारी-જાન્યુઆરી-जनवरी
Jul-जुलै-જુલાઈ-जुलाई
Jun-जून-જુન-	जून
Kharif-खरीप-ચોમાસું-खरीफ
Kharif season-खरीप	ચોમાસું ઋતુ-खरीफ मौसम
langauge-भाषा-ભાષા-भाषा
log Out-लॉग आउट-બહાર નીકળવું-लॉग आउट
Mar-मार्च	-માર્ચ-मार्च
Marathi-मराठी-મરાઠી-मराठी
May-मे-મે-मई
Mobile No.-मोबाईल नंबर-મોબાઈલ નંબર-मोबाइल संख्या
Month-महिना-મહિનો-महीना
no-नाही-નંબર-नहीं
No info-माहिती नाही-માહિતી નથી-कोई सूचना नहीं
No information-माहिती नाही-માહિતી નથી-कोई सूचना नहीं
Non plastic farm pond-प्लास्टिक विरहित  शेततळे-નોન પ્લાસ્ટિક ખેત તલાવડી-गैर प्लास्टिक खेत तालाब
Nov-नोव्हें.-નવેમ્બર-नवम्बर
Oct-ऑक्टो.-ઓક્ટોબર-अक्टूबर
Our-आपले-અમારું-हमारी
Our planning-आपले नियोजन-અમારું આયોજન-हमारी योजना
Password-पासवर्ड-પાસવર્ડ-	कुंजिका
Percolation Tank-पाझर तलाव-અનુશ્રવણ તળાવ-परकोलेशन टैंक
planning-नियोजन-આયોજન-	योजना
Plastic farm pond-प्लास्टिकयुक्त  शेततळे-પ્લાસ્ટિક ખેત તલાવડી-प्लास्टिक फार्म तालाब
Platic Ponds-प्लास्टिकयुक्त  शेततळे-પ્લાસ્ટિક તલાવ-प्लेटिक तालाब
Please fill in your information-कृपया आपली माहिती भरा	-મહેરબાની કરી તમારી માહિતી ભરો-कृपया अपनी जानकारी भरें
Please select your langauge-कृपया आपली भाषा निवडा	-મહેરબાની કરી ભાષા  પસંદ કરો-कृपया अपनी भाषा चुनें
Profile-प्रोफाईल-પ્રોફાઈલ-प्रोफ़ाइल
Rabbi Season-रब्बी हंगाम-શિયાળુ પાક-रब्बी का मौसम
Rainfall-पर्जन्यमान-વરસાદ-वर्षा
Rainfall comparison-पावसाची तुलना-વરસાદ ની સરખામણી-वर्षा तुलना
Rainfall(mm)-पाऊस (मि.मि.)-વરસાદ  મી.મી.-वर्षा (मिमी)
Remaining-उरलेले-બાકી-बचा हुआ
Reserved water-आरक्षित केलेले पाणी-અનામત પાણી-आरक्षित जल
Reset-रिसेट	પુનઃ-સ્થાપિત-रीसेट
Run off-अपधाव-વરસાદ-भाग जाना
Select Recommendation-उपाययोजना निवडा-ભાલામાણો પસંદ કરો-सिफारिश का चयन करें
Selected Recommendations-निवडलेल्या उपाययोजना-પસંદ કરેલી  ભાલામાણો-चयनित सिफारिशें
Sept-सप्टें.-સપ્ટેમ્બર-घराना
Sheeps-शेळ्या-ઘેટાં-भेड़
Sign In-साइन इन-પ્રવેશ-दाखिल करना
Soil Moistore-जमिनीतील  आद्रता-જમીન ની ભેજ-मिट्टी की नमी
storage structure-संचयन संरचना-સંગ્રહ નું માળખું-	भंडारण संरचना
Stored water-साठलेल पाणी-સંગ્રહાયેલું જળ-संग्रहित पानी
Submit-सबमिट-રજુ કર્યું-प्रस्तुत करना
Summary-सारांश-સારાંશ-सारांश
Summer season-उन्हाळी हंगाम-ઉનાળુ મોસમ-गर्मी का मौसम
Surface water-भू-पृस्ठभागवरील पाणी-સપાટી પરનાં પાણી 	सतही जल
Surface water structures-पृष्ठभागावरील पाणी साठवण्याची रचना-સપાટી પરનાં પાણી નું માળખું-	सतही जल संरचनाएं
Surfacewater-भू-पृष्ठभागावरील पाणी-સપાટી પરનાં પાણી-सतही जल
Total Rainfall-संपूर्ण अडवलेलं पाणी (टी. सी. म)-કુલ વરસાદ-कुल वर्षा
Total storage TCM-एकूण साठा-टी.सी.एम-કુલ સંગ્રહ ટી. સી. એમ-कुल संग्रहण टीसीएम
Total water available for rabi season-एकूण रब्बी साठी उपलब्ध पाणी-શિયાળુ પાક માટે ઉપલબ્ધ કુલ પાણી-रबी मौसम के लिए उपलब्ध कुल पानी
Total water consumption-एकूण वापरलेल पाणी-પાણી નો કુલ વપરાશ-कुल पानी की खपत
Total water requirement-एकूण पाणी गरज-પાણી નો કુલ જરૂરીયાત-कुल पानी की आवश्यकता
Total water stored in surface structure-एकूण जमिनीवरील पाणी-સપાટી પર સંગ્રાહાયેલું પાણીનો કુલ જથ્થો-सतह संरचना में संग्रहित कुल पानी
upcoming water demand-आगामी पाण्याची मागणी-પાણીની માંગ-आने वाली पानी की मांग
Update-अपडेट	-અદ્યતન કર્યું-अपडेट
Update account details-अकाऊंट डिटेल्स बदला-હિસાબી અદ્યતન કર્યું-खाता विवरण अपडेट करें
Update mobile number-मोबाईल नंबर बदला-મોબાઈલ નંબર  અદ્યતન કર્યા-मोबाइल नंबर अपडेट करें
Usage-वापरलेले-વપરાશ-प्रयोग
User name-युजर नेम-ઉપયોગકર્તા  નામ-उपयोगकर्ता नाम
Village Pond-गावतलाव-ગામ તળાવ-गांव पोंडो
Water available-एकूण शिल्लक पाणी-ઉપલબ્ધ પાણી-पानी उपलब्ध
water available after kharif-खरीपानंतर पाणी उपलब्ध	-ખરીફ  પછી ઉપલબ્ધ પાણી-	खरीफ के बाद पानी उपलब्ध
Water available at Month End-महिन्याच्या शेवटी उपलब्ध पाणी-મહિના નાં અંતે  ઉપલબ્ધ પાણી -माह के अंत में उपलब्ध पानी
water available through Rainfall-पाऊसामुळे उपलब्ध पाणी-વરસાદ દ્વારા ઉપલબ્ધ પાણી-	वर्षा के माध्यम से उपलब्ध पानी
Water Balance-पाण्याचा समतोल-જળ સંતુલન-शेष पानी
Water Budget-पाणी बजेट-જળ અંદાજપત્ર-जल बजट
Water Budget Information-पाणी बजेट माहिती-જળ અંદાજપત્ર ની માહિતી-जल बजट की जानकारी
water conservation structures-जलसंधारण रचना-જળ સંરક્ષણ માળખું-जल संरक्षण संरचनाएं
Water Consumed during Month-महिन्यात वापरण्यात येणारे पाणी-મહિના દરમ્યાન પાણી  નો વપરાશ-महीने के दौरान खपत पानी
Water consumption-पाणी वापर-પાણી નો વપરાશ-पानी की खपत
water present for rabbi season-रब्बी साठी उपलब्ध पाणी-રબી માટે પાણી ની ઉપલબ્ધિ-रब्बी के मौसम के लिए मौजूद पानी
Water saved-पाणी बचत	-પાણી બચાવ્યું-पानी बचाया
water Seepage-झिरपा-પાણી નું ગળતર-पानी टपका
Water storage-पाणी साठा-જળ સંગ્રહ-पानी का भंडारण
Water structures-पाणी संरचना-પાણીનું માળખું-जल संरचना
Water usage-पाणी वापर-પાણી નો વપરાશ-पानी के उपयोग
Water usage status-पाणी वापरासंबंधीची स्थिती-પાણી ના વપરાશ ની સ્થિતી-जल उपयोग की स्थिति
Water use-पाणी वापर-જળ વપરાશ-पानी का उपयोग
Welcome-स्वागत-આવકાર-स्वागत
Without Plastic-प्लास्टिक विरहित शेततळे	-પ્લાસ્ટિક વિના-प्लास्टिक के बिना
Year-वर्ष-વર્ષ-वर्ष
yes-होय-હા-हां
*/