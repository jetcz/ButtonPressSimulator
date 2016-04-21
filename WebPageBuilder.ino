String createwww(int term, bool state) {

	String www =
		"<html>"
		"<head>"
		"<meta http-equiv=\"content-type\"content=\"text/html;charset=utf-8\">"
		"<title>Button-press Simulator</title>"
		"</head>"
		"<body>"
		"<form action=\"\" method=\"get\">"
		"<div style=\"padding-bottom:0.5em\">"
		"<span style=\"width:6em; float:left\">Radio Cam</span>"
		"<button name=\"T1\"type=\"submit\"value=\"1\">ON</button>"
		"<button name=\"T1\"type=\"submit\"value=\"0\">OFF</button>";

	if (term == 1)
	{
		www += "&nbsp;Radio was turned ";
		if (state)
		{
			www += "ON";
		}
		else
		{
			www += "OFF";
		}
	}

	www +=
		"</div>"
		"<div>"
		"<span style=\"width:6em;float:left\">HDD Dock</span>"
		"<button name=\"T2\"type=\"submit\"value=\"1\">ON</button>"
		"<button name=\"T2\"type=\"submit\"value=\"0\">OFF</button>";

	if (term == 2)
	{
		www += "&nbsp;Dock was turned ";
		if (state)
		{
			www += "ON";
		}
		else
		{
			www += "OFF";
		}
	}

	www +=
		"</div>"
		"</form>"
		"</body>"
		"</html>";

	return www;
}
