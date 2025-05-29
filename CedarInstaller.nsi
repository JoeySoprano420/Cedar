!define PRODUCT_NAME "CedarLang"
!define PRODUCT_VERSION "1.0"
!define PRODUCT_PUBLISHER "Violet Aura Creations"
!define PRODUCT_DIR_REGKEY "Software\CedarLang"
!define PRODUCT_UNINST_KEY "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}"
!define PRODUCT_UNINST_ROOT_KEY "HKLM"

SetCompressor lzma

Name "${PRODUCT_NAME} ${PRODUCT_VERSION}"
OutFile "CedarLangInstaller.exe"
InstallDir "$PROGRAMFILES\CedarLang"
InstallDirRegKey HKLM "${PRODUCT_DIR_REGKEY}" "Install_Dir"
ShowInstDetails show
ShowUnInstDetails show

Section "MainSection" SEC01
  SetOutPath "$INSTDIR"
  File /r "CedarLang\*.*"
  WriteRegStr HKLM "${PRODUCT_DIR_REGKEY}" "Install_Dir" "$INSTDIR"
  WriteUninstaller "$INSTDIR\Uninstall.exe"
SectionEnd

Section "Uninstall"
  Delete "$INSTDIR\Uninstall.exe"
  RMDir /r "$INSTDIR"
  DeleteRegKey HKLM "${PRODUCT_DIR_REGKEY}"
SectionEnd