#include <stdint.h>

const char html_login[] = R"=====(
<!DOCTYPE html>
<html>
<head>
    <meta charset='utf-8'>
    <meta http-equiv='X-UA-Compatible' content='IE=edge'>
    <title>Wifi Config</title>
    <meta name='viewport' content='width=device-width, initial-scale=1'>
</head>
<body>
    <h2>Welcome to WIFI connection and OTA</h2>
<form action="/data" method="POST">
  <label for="ssid">WIFI SSID:</label>
  <input type="text" id="ssid" name="ssid"><br><br>
  <label for="password">WIFI password:</label>
  <input type="password" id="password" name="password" ><br><br>
  <input type="submit" value="Submit">
</form>
</body>
</html>
)=====";

const char html_menu[] = R"=====(
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>menu</title>
</head>

<body>
    <h2>Welcome to esp server</h2>
    <form action="/wifi">
        <input type="submit" value="wifi config" />
    </form>
    <div id="temp">
        124243
    </div>
    <script>
        setInterval(function () {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    var temp = this.responseText;
                    document.getElementById("temp").textContent = temp;
                }
            };
            xhttp.open("GET", "/temp", true);
            xhttp.send();
        }, 1000);
    </script>
</body>

</html>

)=====";

const char html_IRController[] = R"=====(
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>IR controller</title>
</head>

<body>
    <form action="/irSend" method="GET">
        <label for="protocol">protocol</label>
        <input type="number" id="protocol" name="protocol" value="18"><br><br>
        <label for="model">model</label>
        <input type="number" id="model" name="model" value="1"><br><br>
        <label for="mode">mode</label>
        <select id="mode" name="mode">
            <option value="-1">kOff</option>
            <option value="0" selected="selected">kAuto</option>
            <option value="1">kCool</option>
            <option value="2">kHeat</option>
            <option value="3">kDry</option>
            <option value="4">kFan</option>
        </select><br><br>
        <label for="celsius">celsius</label>
        <input type="hidden" name="celsius" value="1"><input type="checkbox"
            onclick="this.previousSibling.value=1-this.previousSibling.value" checked><br><br>
        <label for="degrees">degrees</label>
        <input type="number" id="degrees" name="degrees" value="23"><br><br>
        <label for="fanspeed">fanspeed</label>
        <select id="fanspeed" name="fanspeed">
            <option value="0">kAuto</option>
            <option value="1">kMin</option>
            <option value="2">kLow</option>
            <option value="3">kMedium</option>
            <option value="4">kHigh</option>
            <option value="5">kMax</option>
        </select><br><br>
        <label for="swingv">swingv</label>
        <select id="swingv" name="swingv">
            <option value="-1">kOff</option>
            <option value="0">kAuto</option>
            <option value="1">kHighest</option>
            <option value="2">kHigh</option>
            <option value="3">kMiddle</option>
            <option value="4">kLow</option>
            <option value="5">kLowest</option>
        </select><br><br>
        <label for="swingh">swingh</label>
        <select id="swingh" name="swingh">
            <option value="-1">kOff</option>
            <option value="0">kAuto</option>
            <option value="1">kLeftMax</option>
            <option value="2">kLeft</option>
            <option value="3">kMiddle</option>
            <option value="4">kRight</option>
            <option value="5">kRightMax</option>
            <option value="5">kWide</option>
        </select><br><br>
        <label for="light">light</label>
        <input type="hidden" name="light" value="1"><input type="checkbox"
            onclick="this.previousSibling.value=1-this.previousSibling.value" checked><br><br>
        <label for="beep">beep</label>
        <input type="hidden" name="beep" value="1"><input type="checkbox"
            onclick="this.previousSibling.value=1-this.previousSibling.value" checked><br><br>
        <label for="econo">econo</label>
        <input type="hidden" name="econo" value="1"><input type="checkbox"
            onclick="this.previousSibling.value=1-this.previousSibling.value" checked><br><br>
        <label for="filter">filter</label>
        <input type="hidden" name="filter" value="1"><input type="checkbox"
            onclick="this.previousSibling.value=1-this.previousSibling.value" checked><br><br>
        <label for="turbo">turbo</label>
        <input type="hidden" name="turbo" value="0"><input type="checkbox"
            onclick="this.previousSibling.value=1-this.previousSibling.value"><br><br>
        <label for="quiet">quiet</label>
        <input type="hidden" name="quiet" value="0"><input type="checkbox"
            onclick="this.previousSibling.value=1-this.previousSibling.value"><br><br>
        <label for="sleep">sleep</label>
        <input type="number" id="sleep" name="sleep" value="-1"><br><br>
        <label for="clean">clean</label>
        <input type="hidden" name="clean" value="1"><input type="checkbox"
            onclick="this.previousSibling.value=1-this.previousSibling.value" checked><br><br>
        <label for="clock">clock</label>
        <input type="number" id="clock" name="clock" value="-1"><br><br>
        <label for="power">power</label>
        <input type="hidden" name="power" value="1"><input type="checkbox"
            onclick="this.previousSibling.value=1-this.previousSibling.value" checked><br><br>
        <input type="submit" value="Submit">
    </form><br><br>
    <div>
    Temp sensor (mockup)
    </div>
    <div id="temp">
        
    </div>
    <script>
        setInterval(function () {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    var temp = this.responseText;
                    document.getElementById("temp").textContent = temp;
                }
            };
            xhttp.open("GET", "/temp", true);
            xhttp.send();
        }, 1000);
    </script>
</body>

</html>
)=====";

