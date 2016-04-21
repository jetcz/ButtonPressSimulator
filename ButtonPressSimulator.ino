#include <ESP8266WiFi.h>

int term1 = 14; //radion
int term2 = 12; //dock

WiFiServer server(80);

void setup()
{
	Serial.begin(115200);
	pinMode(term1, OUTPUT);
	pinMode(term2, OUTPUT);

	switchterm(1, true);
	switchterm(2, true);

	Serial.println("connecting to wifi");

	WiFi.begin("x", "x");

	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}

	WiFi.printDiag(Serial);

	server.begin();
}

void loop()
{
	// Check if a client has connected
	WiFiClient client = server.available();
	if (!client) {
		return;
	}

	// Read the first line of the request
	String req = client.readStringUntil('\r');
	Serial.println(req);
	client.flush();

	String response;
	// Match the request
	if (req.indexOf("/?T1=1") != -1)
	{
		switchterm(1, true);
		response = createwww(1, true);
	}
	else if (req.indexOf("/?T1=0") != -1)
	{
		switchterm(1, false);
		response = createwww(1, false);
	}
	else if (req.indexOf("/?T2=1") != -1)
	{
		switchterm(2, true);
		response = createwww(2, true);
	}
	else if (req.indexOf("/?T2=0") != -1)
	{
		switchterm(2, false);
		response = createwww(2, false);
	}
	else {
		response = createwww(0, false);
	}

	client.flush();

	// Send the response to the client
	client.print(response);
	delay(1);
}


void switchterm(int term, bool state) {

	if (state)
	{
		if (term == 1) //radion
		{
			Serial.println("switching term 1 on");
			digitalWrite(term1, LOW); //low active
			delay(1300);
			digitalWrite(term1, HIGH);
		}

		if (term == 2) //dock
		{
			Serial.println("switching term 2 on");
			digitalWrite(term2, LOW); //low active
			delay(100);
			digitalWrite(term2, HIGH);
		}

	}
	else {

		if (term == 1)
		{
			Serial.println("switching term 1 off");
			digitalWrite(term1, LOW); //low active
			delay(5000);
			digitalWrite(term1, HIGH);
		}

		if (term == 2)
		{
			Serial.println("switching term 2 off");
			digitalWrite(term2, LOW); //low active
			delay(3000);
			digitalWrite(term2, HIGH);
		}
	}
}