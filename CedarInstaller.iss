[Setup]
AppName=CedarLang
AppVersion=1.0
DefaultDirName={pf}\CedarLang
DefaultGroupName=CedarLang
UninstallDisplayIcon={app}\cedarc.exe
Compression=lzma
SolidCompression=yes
OutputDir=.
OutputBaseFilename=CedarLangInstaller_Inno

[Files]
Source: "CedarLang\*"; DestDir: "{app}"; Flags: recursesubdirs createallsubdirs

[Icons]
Name: "{group}\CedarLang Compiler"; Filename: "{app}\cedarc.exe"

[Run]
Filename: "{app}\cedarc.exe"; Description: "Run Cedar Compiler"; Flags: nowait postinstall skipifsilent