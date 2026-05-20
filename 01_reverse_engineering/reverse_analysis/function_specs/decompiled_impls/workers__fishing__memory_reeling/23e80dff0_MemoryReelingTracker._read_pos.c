/* ===== 23e80dff0 workers.fishing.memory_reeling:MemoryReelingTracker._read_pos ===== */
/* ghidra_name=FUN_23e80dff0 entry=23e80dff0 size=10291 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e80dff0(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong *plVar20;
  code *pcVar21;
  undefined4 uVar22;
  code *pcVar23;
  code *pcVar24;
  longlong lVar25;
  longlong *plStack_c8;
  code *pcStack_c0;
  longlong *plStack_b8;
  undefined1 auStack_98 [16];
  code *apcStack_88 [2];
  undefined1 auStack_78 [8];
  code *pcStack_70;
  code *pcStack_68;
  
  plVar12 = _DAT_23eede8a0;
  plVar2 = (longlong *)*param_3;
  plVar3 = (longlong *)param_3[1];
  pcStack_68 = (code *)0x0;
  auStack_78 = (undefined1  [8])0x0;
  pcStack_70 = (code *)0x0;
  if (_DAT_23eede8a0 == (longlong *)0x0) {
LAB_23e80e05b:
    _DAT_23eede8a0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede9b8,DAT_23eedd0f8,0x40);
  }
  else {
    lVar9 = *_DAT_23eede8a0;
    if (1 < lVar9) {
      *_DAT_23eede8a0 = lVar9 + -1;
      goto LAB_23e80e05b;
    }
    if (_DAT_23eede8a0[2] != 0) {
      *_DAT_23eede8a0 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      goto LAB_23e80e05b;
    }
  }
  plVar20 = _DAT_23eede8a0;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar12 = _DAT_23eede8a0 + 9;
  lVar25 = *(longlong *)(lVar9 + 8);
  _DAT_23eede8a0[0xf] = lVar25;
  *(longlong **)(lVar9 + 8) = plVar12;
  if ((lVar25 != 0) &&
     (((*(char *)(lVar25 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar25 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar25 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar25 + 0x38))) && (plVar20[0xe] != 0)))) {
    plVar12 = *(longlong **)(lVar25 + 0x28);
    *(longlong **)(plVar20[0xe] + 0x10) = plVar12;
    if (plVar12 != (longlong *)0x0) {
      *plVar12 = *plVar12 + 1;
    }
  }
  *plVar20 = *plVar20 + 1;
  *(undefined4 *)(plVar20 + 8) = 0;
  lVar9 = FUN_23e8dcc30();
  if (lVar9 == 0) {
    FUN_23e915740(param_1,auStack_78,DAT_23eedd200);
    plVar12 = (longlong *)0x0;
    pcVar23 = pcStack_68;
    plStack_b8 = (longlong *)auStack_78;
    pcStack_c0 = pcStack_70;
joined_r0x00023e80f33c:
    pcVar24 = _PyRuntime_exref;
    auStack_78 = (undefined1  [8])plStack_b8;
    pcStack_70 = pcStack_c0;
    if (pcVar23 != (code *)0x0) {
      pcStack_68 = pcVar23;
      if (plVar20 != *(longlong **)(pcVar23 + 0x18)) {
        plVar14 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plStack_c8 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        iVar8 = 299;
        goto LAB_23e80ed70;
      }
LAB_23e80f408:
      plVar14 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      pcVar21 = pcStack_68;
      pcStack_c0 = pcStack_70;
      plStack_b8 = (longlong *)auStack_78;
      pcVar6 = pcStack_68;
      goto LAB_23e80ee11;
    }
    plVar14 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    iVar8 = 299;
    pcStack_68 = (code *)0x0;
    goto LAB_23e80f490;
  }
  plVar10 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eedd410);
  if (plVar10 == (longlong *)0x0) {
    plStack_b8 = *(longlong **)(param_1 + 0x60);
    pcVar23 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_c0 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = (longlong *)0x0;
    pcVar24 = _PyRuntime_exref;
    auStack_78 = (undefined1  [8])plStack_b8;
    pcStack_70 = pcStack_c0;
    if (pcVar23 != (code *)0x0) {
      if (plVar20 == *(longlong **)(pcVar23 + 0x18)) {
        plVar14 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plStack_c8 = (longlong *)0x0;
        plVar12 = (longlong *)0x0;
        pcVar21 = pcVar23;
        pcVar6 = pcVar23;
        goto LAB_23e80ee11;
      }
      plVar14 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      iVar8 = 299;
      pcStack_68 = pcVar23;
      goto LAB_23e80ed70;
    }
    plVar14 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    iVar8 = 299;
    pcStack_68 = (code *)0x0;
    goto LAB_23e80f490;
  }
  lVar9 = *(longlong *)(DAT_23eedd0f0 + 0x20);
  if (*(char *)(lVar9 + 10) != '\0') {
    iVar8 = *(int *)(lVar9 + 0xc);
    if (*(int *)(lVar9 + 0xc) == 0) {
      *(int *)(lVar9 + 0xc) = DAT_23ec155d8;
      iVar8 = DAT_23ec155d8;
      DAT_23ec155d8 = DAT_23ec155d8 + 1;
    }
    if (_DAT_23ec155bc != iVar8) {
      _DAT_23ec155bc = iVar8;
      _DAT_23eede890 = FUN_23e8cbd60(lVar9,_DAT_23eedd418,*(undefined8 *)(_DAT_23eedd418 + 0x18));
    }
    if (-1 < _DAT_23eede890) {
      lVar1 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
      lVar25 = *(longlong *)(lVar1 + 8 + _DAT_23eede890 * 0x10);
      if (lVar25 != 0) goto LAB_23e80e177;
      _DAT_23eede890 = FUN_23e8cbd60(lVar9,_DAT_23eedd418,*(undefined8 *)(_DAT_23eedd418 + 0x18));
      if (-1 < _DAT_23eede890) {
        lVar25 = *(longlong *)(lVar1 + 8 + _DAT_23eede890 * 0x10);
        goto LAB_23e80f588;
      }
    }
LAB_23e80ecb1:
    plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedd418);
    lVar9 = _DAT_23eedd418;
    if ((plVar12 != (longlong *)0x0) && (lVar25 = *plVar12, lVar25 != 0)) goto LAB_23e80e177;
LAB_23e80ece7:
    FUN_23e915740(param_1,auStack_78,lVar9);
    pcVar23 = pcStack_68;
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
      if (pcVar23 == (code *)0x0) {
LAB_23e80fa50:
        plStack_c8 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        plVar12 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        iVar8 = 299;
        pcVar24 = _PyRuntime_exref;
        pcStack_c0 = pcStack_70;
        plStack_b8 = (longlong *)auStack_78;
        goto LAB_23e80f490;
      }
      plVar12 = *(longlong **)(pcVar23 + 0x18);
      plStack_b8 = (longlong *)auStack_78;
      pcStack_c0 = pcStack_70;
    }
    else {
      if (pcStack_68 == (code *)0x0) goto LAB_23e80fa50;
      plVar12 = *(longlong **)(pcStack_68 + 0x18);
      plStack_b8 = (longlong *)auStack_78;
      pcStack_c0 = pcStack_70;
    }
    auStack_78 = (undefined1  [8])plStack_b8;
    pcStack_70 = pcStack_c0;
    if (plVar12 == plVar20) {
      plStack_c8 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      pcVar21 = pcVar23;
      pcVar6 = pcStack_68;
      goto LAB_23e80ee11;
    }
    plStack_c8 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    iVar8 = 299;
    pcVar24 = _PyRuntime_exref;
    goto LAB_23e80ed70;
  }
  plVar12 = (longlong *)FUN_23a37a020(DAT_23eedd0f0,_DAT_23eedd418);
  if (plVar12 == (longlong *)0x0) goto LAB_23e80ecb1;
  lVar25 = *plVar12;
LAB_23e80f588:
  if (lVar25 == 0) goto LAB_23e80ecb1;
LAB_23e80e177:
  lVar9 = *(longlong *)(DAT_23eedd0f0 + 0x20);
  if (*(char *)(lVar9 + 10) == '\0') {
    plVar12 = (longlong *)FUN_23a37a020(DAT_23eedd0f0,_DAT_23eedd420);
    if (plVar12 == (longlong *)0x0) goto LAB_23e80f029;
    lVar9 = *plVar12;
LAB_23e80f5b8:
    if (lVar9 == 0) goto LAB_23e80f029;
  }
  else {
    iVar8 = *(int *)(lVar9 + 0xc);
    if (*(int *)(lVar9 + 0xc) == 0) {
      *(int *)(lVar9 + 0xc) = DAT_23ec155d8;
      iVar8 = DAT_23ec155d8;
      DAT_23ec155d8 = DAT_23ec155d8 + 1;
    }
    if (_DAT_23ec155c0 != iVar8) {
      _DAT_23ec155c0 = iVar8;
      _DAT_23eede898 = FUN_23e8cbd60(lVar9,_DAT_23eedd420,*(undefined8 *)(_DAT_23eedd420 + 0x18));
    }
    if (-1 < _DAT_23eede898) {
      lVar1 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
      if (*(longlong *)(lVar1 + 8 + _DAT_23eede898 * 0x10) != 0) goto LAB_23e80e1e4;
      _DAT_23eede898 = FUN_23e8cbd60(lVar9,_DAT_23eedd420,*(undefined8 *)(_DAT_23eedd420 + 0x18));
      if (-1 < _DAT_23eede898) {
        lVar9 = *(longlong *)(lVar1 + 8 + _DAT_23eede898 * 0x10);
        goto LAB_23e80f5b8;
      }
    }
LAB_23e80f029:
    plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedd420);
    lVar9 = _DAT_23eedd420;
    if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) goto LAB_23e80ece7;
  }
LAB_23e80e1e4:
  plVar11 = (longlong *)FUN_23e8c1360(lVar25);
  if (plVar11 == (longlong *)0x0) {
    plStack_b8 = *(longlong **)(param_1 + 0x60);
    pcVar23 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_c0 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar10 = *plVar10 + -1;
    plVar11 = (longlong *)0x0;
    pcStack_68 = pcVar23;
    auStack_78 = (undefined1  [8])plStack_b8;
    pcStack_70 = pcStack_c0;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
      if (pcVar23 == (code *)0x0) {
LAB_23e80fef0:
        plStack_c8 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        plVar12 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        iVar8 = 299;
        pcVar24 = _PyRuntime_exref;
        goto LAB_23e80f490;
      }
      plVar12 = *(longlong **)(pcVar23 + 0x18);
    }
    else {
      if (pcVar23 == (code *)0x0) goto LAB_23e80fef0;
      plVar12 = *(longlong **)(pcVar23 + 0x18);
    }
    if (plVar12 == plVar20) {
      plStack_c8 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      pcVar21 = pcVar23;
      pcVar6 = pcStack_68;
      goto LAB_23e80ee11;
    }
    plStack_c8 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    iVar8 = 299;
    pcVar24 = _PyRuntime_exref;
    goto LAB_23e80ed70;
  }
  *(undefined4 *)(plVar20 + 5) = 299;
  auStack_98._8_8_ = plVar3;
  auStack_98._0_8_ = plVar11;
  plVar12 = (longlong *)FUN_23e94ed00(param_1,plVar10,auStack_98);
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if (plVar12 == (longlong *)0x0) {
    plStack_b8 = *(longlong **)(param_1 + 0x60);
    pcVar23 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_c0 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto joined_r0x00023e80f33c;
  }
  if ((DAT_23edf9790 == 0) &&
     (DAT_23edf9790 = PyImport_ImportModule("ctypes.wintypes"), DAT_23edf9790 == 0)) {
    FUN_23e9364c0("%s : %s\n","IMPORT_HARD_CTYPES__WINTYPES",
                  "\"Unexpected failure of hard import of \'ctypes.wintypes\'\"");
                    /* WARNING: Subroutine does not return */
    abort();
  }
  lVar25 = _DAT_23eedd430;
  lVar9 = DAT_23edf9790;
  *(undefined4 *)(plVar20 + 5) = 300;
  plVar10 = (longlong *)FUN_23e915840(param_1,lVar9,_DAT_23eedd428,*(undefined8 *)(lVar25 + 0x18));
  if (plVar10 == (longlong *)0x0) {
    plStack_b8 = *(longlong **)(param_1 + 0x60);
    pcVar23 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_c0 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar24 = _PyRuntime_exref;
    auStack_78 = (undefined1  [8])plStack_b8;
    pcStack_70 = pcStack_c0;
    if (pcVar23 == (code *)0x0) {
      plVar14 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      iVar8 = 300;
      plVar10 = (longlong *)0x0;
      pcStack_68 = (code *)0x0;
      goto LAB_23e80f490;
    }
    plVar10 = (longlong *)0x0;
    pcStack_68 = pcVar23;
    if (*(longlong **)(pcVar23 + 0x18) != plVar20) {
      plVar14 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      iVar8 = 300;
      plVar10 = (longlong *)0x0;
      goto LAB_23e80ed70;
    }
LAB_23e80f688:
    plVar14 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    pcVar21 = pcStack_68;
    pcStack_c0 = pcStack_70;
    plStack_b8 = (longlong *)auStack_78;
    pcVar6 = pcStack_68;
    goto LAB_23e80ee11;
  }
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar10,DAT_23eedd370);
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if (plVar11 == (longlong *)0x0) {
    plStack_b8 = *(longlong **)(param_1 + 0x60);
    pcVar23 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_c0 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = (longlong *)0x0;
    pcVar24 = _PyRuntime_exref;
    auStack_78 = (undefined1  [8])plStack_b8;
    pcStack_70 = pcStack_c0;
    if (pcVar23 != (code *)0x0) {
      if (*(longlong **)(pcVar23 + 0x18) == plVar20) {
        plVar14 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        plStack_c8 = (longlong *)0x0;
        pcVar21 = pcVar23;
        pcVar6 = pcVar23;
        goto LAB_23e80ee11;
      }
      plVar14 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      iVar8 = 300;
      pcStack_68 = pcVar23;
      goto LAB_23e80ed70;
    }
    plVar14 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    iVar8 = 300;
    pcStack_68 = (code *)0x0;
  }
  else {
    iVar8 = FUN_23e912620(plVar12,plVar11);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    lVar9 = DAT_23ed6cce8;
    if (iVar8 != -1) {
      if (iVar8 == 1) {
        lVar25 = *(longlong *)(param_1 + 0x10);
        iVar8 = *(int *)(lVar25 + 0x1410);
        plVar20 = *(longlong **)(DAT_23ed6cce8 + 0x20);
        *plVar20 = *plVar20 + 1;
        if (iVar8 == 0) {
          plVar11 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
          plVar20 = *(longlong **)(lVar9 + 0x20);
        }
        else {
          iVar8 = iVar8 + -1;
          *(int *)(lVar25 + 0x1410) = iVar8;
          plVar11 = *(longlong **)(lVar25 + 0x1190 + (longlong)iVar8 * 8);
          *plVar11 = 1;
        }
        plVar14 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        plVar15 = (longlong *)0x0;
        plStack_c8 = (longlong *)0x0;
        lVar9 = *(longlong *)(lVar9 + 0x28);
        plVar10 = (longlong *)0x0;
        plVar11[2] = 0;
        plVar11[3] = 1;
        plVar11[4] = (longlong)plVar20;
        plVar11[5] = lVar9;
LAB_23e80f101:
        lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar20 = *(longlong **)(lVar9 + 0x28);
        plVar16 = (longlong *)plVar20[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
        *(undefined4 *)(plVar20 + 8) = 0xffffffff;
        if (plVar16 != (longlong *)0x0) {
          plVar20[2] = 0;
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))();
          }
        }
        *plVar20 = *plVar20 + -1;
        if (*plVar20 == 0) {
          (**(code **)(plVar20[1] + 0x30))(plVar20);
        }
        plVar20[0xf] = 0;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
        }
        if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        if ((plStack_c8 != (longlong *)0x0) &&
           (lVar9 = *plStack_c8, *plStack_c8 = lVar9 + -1, lVar9 + -1 == 0)) {
          (**(code **)(plStack_c8[1] + 0x30))(plStack_c8);
        }
        if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        lVar9 = *plVar2;
        *plVar2 = lVar9 + -1;
        if (lVar9 + -1 == 0) {
          (**(code **)(plVar2[1] + 0x30))(plVar2);
        }
        lVar9 = *plVar3;
        *plVar3 = lVar9 + -1;
        if (lVar9 + -1 == 0) {
          (**(code **)(plVar3[1] + 0x30))(plVar3);
          return plVar11;
        }
        return plVar11;
      }
      lVar9 = FUN_23e8dc5a0();
      if (lVar9 == 0) {
        FUN_23e915740(param_1,auStack_78,_DAT_23eedd438);
        plVar10 = (longlong *)0x0;
        pcVar23 = pcStack_68;
        plStack_b8 = (longlong *)auStack_78;
        pcStack_c0 = pcStack_70;
joined_r0x00023e80fcfc:
        pcVar24 = _PyRuntime_exref;
        auStack_78 = (undefined1  [8])plStack_b8;
        pcStack_70 = pcStack_c0;
        if (pcVar23 == (code *)0x0) {
          plVar14 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          iVar8 = 0x12e;
          pcStack_68 = (code *)0x0;
          goto LAB_23e80f490;
        }
        pcStack_68 = pcVar23;
        if (*(longlong **)(pcVar23 + 0x18) == plVar20) goto LAB_23e80f688;
        plVar14 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plStack_c8 = (longlong *)0x0;
        iVar8 = 0x12e;
      }
      else {
        *(undefined4 *)(plVar20 + 5) = 0x12e;
        plVar10 = (longlong *)FUN_23e91a870(param_1,lVar9);
        if (plVar10 == (longlong *)0x0) {
          plStack_b8 = *(longlong **)(param_1 + 0x60);
          pcVar23 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcStack_c0 = *(code **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto joined_r0x00023e80fcfc;
        }
        if ((DAT_23ed8fb50 == 0) &&
           (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0)) {
LAB_23e80faa3:
          FUN_23e9364c0("%s : %s\n","IMPORT_HARD_CTYPES",
                        "\"Unexpected failure of hard import of \'ctypes\'\"");
                    /* WARNING: Subroutine does not return */
          abort();
        }
        plVar11 = (longlong *)FUN_23e8bc2f0(DAT_23ed8fb50,DAT_23eedd440);
        if (plVar11 == (longlong *)0x0) {
          plStack_b8 = *(longlong **)(param_1 + 0x60);
          pcVar23 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcStack_c0 = *(code **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar11 = (longlong *)0x0;
          pcVar24 = _PyRuntime_exref;
          auStack_78 = (undefined1  [8])plStack_b8;
          pcStack_70 = pcStack_c0;
          if (pcVar23 == (code *)0x0) {
            plStack_c8 = (longlong *)0x0;
            plVar14 = (longlong *)0x0;
            plVar13 = (longlong *)0x0;
            iVar8 = 0x12f;
            pcStack_68 = (code *)0x0;
            goto LAB_23e80f490;
          }
          if (plVar20 == *(longlong **)(pcVar23 + 0x18)) {
            plStack_c8 = (longlong *)0x0;
            plVar14 = (longlong *)0x0;
            plVar13 = (longlong *)0x0;
            pcVar21 = pcVar23;
            pcVar6 = pcVar23;
            goto LAB_23e80ee11;
          }
          plStack_c8 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          iVar8 = 0x12f;
          pcStack_68 = pcVar23;
          goto LAB_23e80ed70;
        }
        lVar9 = FUN_23e8dc5a0();
        if (lVar9 == 0) {
          FUN_23e915740(param_1,auStack_78,_DAT_23eedd438);
          pcVar23 = pcStack_68;
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
            if (pcVar23 != (code *)0x0) goto LAB_23e80ff5f;
          }
          else if (pcStack_68 != (code *)0x0) {
            plVar11 = *(longlong **)(pcStack_68 + 0x18);
            plStack_b8 = (longlong *)auStack_78;
            pcStack_c0 = pcStack_70;
            goto joined_r0x00023e810198;
          }
LAB_23e810154:
          plVar13 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          iVar8 = 0x12f;
          pcVar24 = _PyRuntime_exref;
          pcStack_c0 = pcStack_70;
          plStack_b8 = (longlong *)auStack_78;
          goto LAB_23e80f490;
        }
        *(undefined4 *)(plVar20 + 5) = 0x12f;
        plVar13 = (longlong *)FUN_23e914090(param_1,plVar11,lVar9);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (plVar13 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcVar23 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcStack_70 = *(code **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcStack_68 = pcVar23;
          if (pcVar23 == (code *)0x0) goto LAB_23e810154;
LAB_23e80ff5f:
          plVar11 = *(longlong **)(pcVar23 + 0x18);
          plStack_b8 = (longlong *)auStack_78;
          pcStack_c0 = pcStack_70;
joined_r0x00023e810198:
          plVar13 = (longlong *)0x0;
          auStack_78 = (undefined1  [8])plStack_b8;
          pcStack_70 = pcStack_c0;
          if (plVar20 == plVar11) {
            plVar13 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            plVar14 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            pcVar21 = pcVar23;
            pcVar6 = pcStack_68;
            goto LAB_23e80ee11;
          }
          plStack_c8 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          iVar8 = 0x12f;
          pcVar24 = _PyRuntime_exref;
        }
        else {
          cVar7 = FUN_23e8d9ac0(plVar10,_DAT_23eedd448,plVar13);
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          lVar9 = DAT_23ed6cce8;
          if (cVar7 == '\0') {
            plStack_b8 = *(longlong **)(param_1 + 0x60);
            pcVar23 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcStack_c0 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcVar24 = _PyRuntime_exref;
            auStack_78 = (undefined1  [8])plStack_b8;
            pcStack_70 = pcStack_c0;
            if (pcVar23 == (code *)0x0) {
              plVar14 = (longlong *)0x0;
              plVar13 = (longlong *)0x0;
              plVar11 = (longlong *)0x0;
              plStack_c8 = (longlong *)0x0;
              iVar8 = 0x12f;
              pcStack_68 = (code *)0x0;
              goto LAB_23e80f490;
            }
            pcStack_68 = pcVar23;
            if (plVar20 == *(longlong **)(pcVar23 + 0x18)) goto LAB_23e80f688;
            plVar14 = (longlong *)0x0;
            plVar13 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            iVar8 = 0x12f;
          }
          else {
            lVar25 = *(longlong *)(param_1 + 0x10);
            iVar8 = *(int *)(lVar25 + 0x1410);
            plVar13 = *(longlong **)(DAT_23ed6cce8 + 0x20);
            *plVar13 = *plVar13 + 1;
            if (iVar8 == 0) {
              plVar11 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
              plVar13 = *(longlong **)(lVar9 + 0x20);
            }
            else {
              iVar8 = iVar8 + -1;
              *(int *)(lVar25 + 0x1410) = iVar8;
              plVar11 = *(longlong **)(lVar25 + 0x1190 + (longlong)iVar8 * 8);
              *plVar11 = 1;
            }
            lVar9 = *(longlong *)(lVar9 + 0x28);
            plVar11[2] = 0;
            plVar11[3] = 1;
            plVar11[4] = (longlong)plVar13;
            plVar11[5] = lVar9;
            lVar9 = FUN_23e8dcc30();
            if (lVar9 == 0) {
              FUN_23e915740(param_1,auStack_78,DAT_23eedd200);
LAB_23e8100a9:
              plStack_c8 = (longlong *)0x0;
              plVar14 = (longlong *)0x0;
              plVar13 = (longlong *)0x0;
              uVar22 = 0x132;
              pcVar24 = _PyRuntime_exref;
            }
            else {
              plVar14 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eedd450);
              if (plVar14 == (longlong *)0x0) {
LAB_23e810080:
                pcStack_68 = *(code **)(param_1 + 0x70);
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcStack_70 = *(code **)(param_1 + 0x68);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e8100a9;
              }
              if ((DAT_23ed8fb50 == 0) &&
                 (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0)) {
                DAT_23ed8fb50 = 0;
                goto LAB_23e80faa3;
              }
              lVar9 = DAT_23ed8fb50;
              *(undefined4 *)(plVar20 + 5) = 0x132;
              plVar15 = (longlong *)FUN_23e915840(param_1,lVar9,DAT_23eedd360);
              if (plVar15 == (longlong *)0x0) {
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcStack_70 = *(code **)(param_1 + 0x68);
                pcStack_68 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                goto LAB_23e8100a9;
              }
              *(undefined4 *)(plVar20 + 5) = 0x132;
              auStack_98._8_8_ = plVar15;
              auStack_98._0_8_ = plVar12;
              plVar13 = (longlong *)FUN_23e94ed00(param_1,plVar14,auStack_98);
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
              }
              if (plVar13 == (longlong *)0x0) goto LAB_23e810080;
              iVar8 = FUN_23a35f020(plVar13);
              plVar14 = (longlong *)0x0;
              plStack_c8 = (longlong *)0x0;
              while (iVar8 != -1) {
                if (iVar8 == 0) {
                  lVar9 = FUN_23e8dcc30();
                  if (lVar9 == 0) {
                    FUN_23e915740(param_1,auStack_78,DAT_23eedd200);
                    pcVar23 = pcStack_68;
                    plStack_b8 = (longlong *)auStack_78;
                    pcStack_c0 = pcStack_70;
                  }
                  else {
                    plVar15 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eedd260);
                    if (plVar15 != (longlong *)0x0) {
                      *(undefined4 *)(plVar20 + 5) = 0x13a;
                      plVar16 = (longlong *)FUN_23e914090(param_1,plVar15,plVar12);
                      *plVar15 = *plVar15 + -1;
                      if (*plVar15 == 0) {
                        FUN_23a334bc0(plVar15);
                      }
                      if (plVar16 != (longlong *)0x0) {
                        *plVar16 = *plVar16 + -1;
                        if (*plVar16 == 0) {
                          FUN_23a334bc0(plVar16);
                        }
                        *plVar11 = *plVar11 + 1;
                        plVar15 = plVar11;
                        goto LAB_23e80f101;
                      }
                    }
                    plStack_b8 = *(longlong **)(param_1 + 0x60);
                    pcVar23 = *(code **)(param_1 + 0x70);
                    pcStack_c0 = *(code **)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  pcVar24 = _PyRuntime_exref;
                  auStack_78 = (undefined1  [8])plStack_b8;
                  pcStack_70 = pcStack_c0;
                  if (pcVar23 == (code *)0x0) {
                    iVar8 = 0x13a;
                    pcStack_68 = (code *)0x0;
                    goto LAB_23e80f490;
                  }
                  pcVar21 = pcVar23;
                  pcVar6 = pcVar23;
                  if (plVar20 == *(longlong **)(pcVar23 + 0x18)) goto LAB_23e80ee11;
                  iVar8 = 0x13a;
                  pcStack_68 = pcVar23;
                  goto LAB_23e80ed70;
                }
                plVar15 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23eedd468);
                if (plVar15 == (longlong *)0x0) {
LAB_23e81044d:
                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_70 = *(code **)(param_1 + 0x68);
                  pcStack_68 = *(code **)(param_1 + 0x70);
                  uVar22 = 0x134;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pcVar24 = _PyRuntime_exref;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e80e8b0;
                }
                plVar16 = (longlong *)FUN_23e8bc2f0(plVar15,DAT_23ed6ce98);
                *plVar15 = *plVar15 + -1;
                if (*plVar15 == 0) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                if (plVar16 == (longlong *)0x0) goto LAB_23e81044d;
                *(undefined4 *)(plVar20 + 5) = 0x134;
                plVar15 = (longlong *)FUN_23e91a870(param_1,plVar16);
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                if (plVar15 == (longlong *)0x0) goto LAB_23e81044d;
                if ((plStack_c8 != (longlong *)0x0) &&
                   (*plStack_c8 = *plStack_c8 + -1, *plStack_c8 == 0)) {
                  (**(code **)(plStack_c8[1] + 0x30))(plStack_c8);
                }
                if ((DAT_23ed8fb50 == 0) &&
                   (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0)) {
                  DAT_23ed8fb50 = 0;
                  goto LAB_23e80faa3;
                }
                plVar16 = (longlong *)FUN_23e8bc2f0(DAT_23ed8fb50,_DAT_23eedd470);
                plStack_c8 = plVar15;
                if (plVar16 == (longlong *)0x0) goto LAB_23e8104c2;
                plVar17 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23eedd478);
                if (plVar17 == (longlong *)0x0) {
                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_70 = *(code **)(param_1 + 0x68);
                  pcStack_68 = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar16 = *plVar16 + -1;
                  if (*plVar16 == 0) {
                    FUN_23a334bc0(plVar16);
                  }
LAB_23e8104fd:
                  uVar22 = 0x135;
                  pcVar24 = _PyRuntime_exref;
                  goto LAB_23e80e8b0;
                }
                if ((DAT_23ed8fb50 == 0) &&
                   (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0)) {
                  DAT_23ed8fb50 = 0;
                  goto LAB_23e80faa3;
                }
                plVar18 = (longlong *)FUN_23e8bc2f0(DAT_23ed8fb50,DAT_23eedd358);
                if (plVar18 == (longlong *)0x0) {
                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_70 = *(code **)(param_1 + 0x68);
                  pcStack_68 = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar16 = *plVar16 + -1;
                  if (*plVar16 == 0) {
                    FUN_23a334bc0(plVar16);
                  }
                  *plVar17 = *plVar17 + -1;
                  if (*plVar17 == 0) {
                    FUN_23a334bc0(plVar17);
                  }
                  goto LAB_23e8104fd;
                }
                *(undefined4 *)(plVar20 + 5) = 0x135;
                auStack_98._8_8_ = plVar18;
                auStack_98._0_8_ = plVar17;
                plVar19 = (longlong *)FUN_23e94ed00(param_1,plVar16,auStack_98);
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                *plVar17 = *plVar17 + -1;
                if (*plVar17 == 0) {
                  (**(code **)(plVar17[1] + 0x30))(plVar17);
                }
                *plVar18 = *plVar18 + -1;
                if (*plVar18 == 0) {
                  (**(code **)(plVar18[1] + 0x30))(plVar18);
                }
                if (plVar19 == (longlong *)0x0) {
LAB_23e8104c2:
                  pcStack_68 = *(code **)(param_1 + 0x70);
                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_70 = *(code **)(param_1 + 0x68);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e8104fd;
                }
                plVar16 = (longlong *)FUN_23e8bc2f0(plVar19,DAT_23eedd370);
                *plVar19 = *plVar19 + -1;
                if (*plVar19 == 0) {
                  (**(code **)(plVar19[1] + 0x30))(plVar19);
                }
                if (plVar16 == (longlong *)0x0) goto LAB_23e8104c2;
                iVar8 = FUN_23a35f020(plVar16);
                if (iVar8 == -1) {
                  pcStack_68 = *(code **)(param_1 + 0x70);
                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_70 = *(code **)(param_1 + 0x68);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  lVar9 = *plVar16;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar16 = lVar9 + -1;
                  if (lVar9 + -1 == 0) {
                    FUN_23a334bc0(plVar16);
                  }
                  goto LAB_23e8104fd;
                }
                if (iVar8 != 1) {
                  *plVar16 = *plVar16 + -1;
                  if (*plVar16 == 0) {
                    (**(code **)(plVar16[1] + 0x30))(plVar16);
                  }
                  plVar16 = DAT_23ed6ccf0;
                  *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
                }
                if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                iVar8 = FUN_23a35f020(plVar16);
                plVar14 = plVar16;
                if (iVar8 == -1) {
                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_70 = *(code **)(param_1 + 0x68);
                  pcStack_68 = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pcVar24 = _PyRuntime_exref;
                  uVar22 = 0x136;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e80e8b0;
                }
                if (iVar8 != 0) {
                  lVar9 = *(longlong *)(param_1 + 0x10);
                  plVar17 = *(longlong **)(lVar9 + 0xe20);
                  if (plVar17 == (longlong *)0x0) {
                    plVar17 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                  }
                  else {
                    lVar25 = plVar17[3];
                    *(int *)(lVar9 + 0xebc) = *(int *)(lVar9 + 0xebc) + -1;
                    *(longlong *)(lVar9 + 0xe20) = lVar25;
                    *plVar17 = 1;
                  }
                  pcVar24 = _PyRuntime_exref;
                  plVar17[4] = 0;
                  lVar9 = *(longlong *)
                           (*(longlong *)(*(longlong *)(pcVar24 + 0x1f8) + 0x10) + 0x2e8);
                  lVar25 = plVar17[-1];
                  puVar4 = *(undefined8 **)(lVar9 + 8);
                  *puVar4 = plVar17 + -2;
                  plVar17[-2] = lVar9;
                  plVar17[-1] = (ulonglong)((uint)lVar25 & 3) | (ulonglong)puVar4;
                  *(longlong **)(lVar9 + 8) = plVar17 + -2;
                  uVar5 = _DAT_23eedd480;
                  *plVar16 = *plVar16 + 1;
                  plVar17[3] = (longlong)plVar16;
                  lVar9 = FUN_23e8bc2f0(plVar10,uVar5);
                  if (lVar9 == 0) {
                    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcStack_70 = *(code **)(param_1 + 0x68);
                    pcStack_68 = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar17 = *plVar17 + -1;
                    if (*plVar17 == 0) {
                      FUN_23a334bc0(plVar17);
                    }
                  }
                  else {
                    plVar17[4] = lVar9;
                    iVar8 = PyDict_SetItem(plVar11,plVar15,plVar17);
                    *plVar17 = *plVar17 + -1;
                    if (*plVar17 == 0) {
                      (**(code **)(plVar17[1] + 0x30))(plVar17);
                    }
                    if (iVar8 == 0) goto LAB_23e80e6fd;
                    pcStack_68 = *(code **)(param_1 + 0x70);
                    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcStack_70 = *(code **)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  uVar22 = 0x137;
                  goto LAB_23e80e8b0;
                }
LAB_23e80e6fd:
                lVar9 = FUN_23e8dcc30();
                if (lVar9 == 0) {
                  FUN_23e915740(param_1,auStack_78,DAT_23eedd200);
LAB_23e81032b:
                  uVar22 = 0x138;
                  pcVar24 = _PyRuntime_exref;
                  goto LAB_23e80e8b0;
                }
                plVar15 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eedd490);
                if (plVar15 == (longlong *)0x0) {
LAB_23e81058d:
                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_70 = *(code **)(param_1 + 0x68);
                  pcStack_68 = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e81032b;
                }
                if ((DAT_23ed8fb50 == 0) &&
                   (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0)) {
                  DAT_23ed8fb50 = 0;
                  goto LAB_23e80faa3;
                }
                plVar16 = (longlong *)FUN_23e8bc2f0(DAT_23ed8fb50,DAT_23eedd360);
                if (plVar16 == (longlong *)0x0) {
LAB_23e8105d5:
                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_70 = *(code **)(param_1 + 0x68);
                  pcStack_68 = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar15 = *plVar15 + -1;
                  if (*plVar15 == 0) {
                    FUN_23a334bc0(plVar15);
                  }
                  goto LAB_23e81032b;
                }
                *(undefined4 *)(plVar20 + 5) = 0x138;
                plVar17 = (longlong *)FUN_23e914090(param_1,plVar16,plVar10);
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                if (plVar17 == (longlong *)0x0) goto LAB_23e8105d5;
                *(undefined4 *)(plVar20 + 5) = 0x138;
                auStack_98._8_8_ = plVar17;
                auStack_98._0_8_ = plVar12;
                plVar16 = (longlong *)FUN_23e94ed00(param_1,plVar15,auStack_98);
                *plVar15 = *plVar15 + -1;
                if (*plVar15 == 0) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                *plVar17 = *plVar17 + -1;
                if (*plVar17 == 0) {
                  (**(code **)(plVar17[1] + 0x30))(plVar17);
                }
                if (plVar16 == (longlong *)0x0) goto LAB_23e81058d;
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                lVar9 = *(longlong *)(param_1 + 0x10);
                plVar13 = plVar16;
                if ((((*(int *)(*(longlong *)(lVar9 + 0x28) + 0x160) != 0) ||
                     (*(int *)(lVar9 + 0x78) != 0)) && (iVar8 = Py_MakePendingCalls(), iVar8 < 0))
                   && (*(longlong *)(param_1 + 0x60) != 0)) {
LAB_23e80fdd5:
                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_70 = *(code **)(param_1 + 0x68);
                  pcStack_68 = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pcVar24 = _PyRuntime_exref;
                  uVar22 = 0x133;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e80e8b0;
                }
                if (*(int *)(lVar9 + 0x68) == 0) {
                  plVar15 = *(longlong **)(param_1 + 0x90);
                }
                else {
                  PyEval_SaveThread();
                  PyEval_AcquireThread(param_1);
                  plVar15 = *(longlong **)(param_1 + 0x90);
                }
                if (plVar15 != (longlong *)0x0) {
                  plVar16 = *(longlong **)(param_1 + 0x60);
                  plVar17 = *(longlong **)(param_1 + 0x68);
                  plVar18 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x90) = 0;
                  *(longlong **)(param_1 + 0x60) = plVar15;
                  *plVar15 = *plVar15 + 1;
                  *(undefined8 *)(param_1 + 0x68) = 0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
                    (**(code **)(plVar16[1] + 0x30))();
                  }
                  if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
                    (**(code **)(plVar17[1] + 0x30))(plVar17);
                  }
                  if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
                    (**(code **)(plVar18[1] + 0x30))(plVar18);
                  }
                  goto LAB_23e80fdd5;
                }
                iVar8 = FUN_23a35f020(plVar16);
              }
              pcStack_68 = *(code **)(param_1 + 0x70);
              auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
              pcStack_70 = *(code **)(param_1 + 0x68);
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar24 = _PyRuntime_exref;
              uVar22 = 0x133;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
LAB_23e80e8b0:
            pcVar23 = pcStack_68;
            auStack_98._8_8_ = pcStack_70;
            auStack_98._0_8_ = auStack_78;
            pcStack_68 = (code *)0x0;
            _auStack_78 = (undefined1  [16])0x0;
            apcStack_88[0] = pcVar23;
            plVar15 = *(longlong **)(param_1 + 0x138);
            if (plVar15 != (longlong *)0x0) {
              *plVar15 = *plVar15 + 1;
            }
            pcVar21 = DAT_23ed6a4f8;
            if (pcVar23 == (code *)0x0) {
              if (DAT_23ed6a4f8 == (code *)0x0) {
                pcVar21 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
              }
              else {
                pcVar23 = *(code **)DAT_23ed6a4f8;
                *(longlong *)DAT_23ed6a4f8 = 1;
                DAT_23ed6a4f8 = pcVar23;
                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              }
              *(longlong *)(pcVar21 + 0x10) = 0;
              *(longlong **)(pcVar21 + 0x18) = plVar20;
              *plVar20 = *plVar20 + 1;
              lVar9 = *(longlong *)(pcVar24 + 0x1f8);
              *(undefined4 *)(pcVar21 + 0x24) = uVar22;
              lVar9 = *(longlong *)(lVar9 + 0x10);
              *(undefined4 *)(pcVar21 + 0x20) = 0xffffffff;
              lVar9 = *(longlong *)(lVar9 + 0x2e8);
              lVar25 = *(longlong *)(pcVar21 + -8);
              puVar4 = *(undefined8 **)(lVar9 + 8);
              *puVar4 = pcVar21 + -0x10;
              *(longlong *)(pcVar21 + -0x10) = lVar9;
              *(ulonglong *)(pcVar21 + -8) = (ulonglong)((uint)lVar25 & 3) | (ulonglong)puVar4;
              *(code **)(lVar9 + 8) = pcVar21 + -0x10;
              if ((apcStack_88[0] != (code *)0x0) &&
                 (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
                 *(longlong *)apcStack_88[0] == 0)) {
                (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))(apcStack_88[0]);
              }
            }
            else {
              if (DAT_23ed6a4f8 == (code *)0x0) {
                pcVar21 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
              }
              else {
                pcVar6 = *(code **)DAT_23ed6a4f8;
                *(longlong *)DAT_23ed6a4f8 = 1;
                DAT_23ed6a4f8 = pcVar6;
                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              }
              *(longlong **)(pcVar21 + 0x18) = plVar20;
              *plVar20 = *plVar20 + 1;
              lVar9 = *(longlong *)(pcVar24 + 0x1f8);
              *(undefined4 *)(pcVar21 + 0x24) = uVar22;
              lVar9 = *(longlong *)(lVar9 + 0x10);
              *(undefined4 *)(pcVar21 + 0x20) = 0xffffffff;
              lVar9 = *(longlong *)(lVar9 + 0x2e8);
              lVar25 = *(longlong *)(pcVar21 + -8);
              puVar4 = *(undefined8 **)(lVar9 + 8);
              *puVar4 = pcVar21 + -0x10;
              *(longlong *)(pcVar21 + -0x10) = lVar9;
              *(ulonglong *)(pcVar21 + -8) = (ulonglong)((uint)lVar25 & 3) | (ulonglong)puVar4;
              *(code **)(lVar9 + 8) = pcVar21 + -0x10;
              *(code **)(pcVar21 + 0x10) = pcVar23;
              *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
              if ((apcStack_88[0] != (code *)0x0) &&
                 (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
                 *(longlong *)apcStack_88[0] == 0)) {
                (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
              }
            }
            pcVar23 = _Py_NoneStruct_exref;
            apcStack_88[0] = pcVar21;
            if (((code *)auStack_98._0_8_ != _Py_NoneStruct_exref) &&
               ((code *)auStack_98._0_8_ != (code *)0x0)) {
              FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
            }
            plVar16 = *(longlong **)(auStack_98._8_8_ + 0x28);
            if (apcStack_88[0] == pcVar23) {
              pcVar21 = (code *)0x0;
            }
            else {
              pcVar21 = apcStack_88[0];
              if (apcStack_88[0] != (code *)0x0) {
                *(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + 1;
              }
            }
            *(code **)(auStack_98._8_8_ + 0x28) = pcVar21;
            if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
              (**(code **)(plVar16[1] + 0x30))();
            }
            plVar16 = *(longlong **)(param_1 + 0x138);
            *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
            if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
              (**(code **)(plVar16[1] + 0x30))();
            }
            *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + -1;
            if (*(longlong *)auStack_98._0_8_ == 0) {
              (**(code **)(*(longlong *)(auStack_98._0_8_ + 8) + 0x30))();
            }
            if ((apcStack_88[0] != (code *)0x0) &&
               (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
               *(longlong *)apcStack_88[0] == 0)) {
              (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
            }
            apcStack_88[0] = (code *)0x0;
            auStack_98 = (undefined1  [16])0x0;
            lVar9 = FUN_23e8dcc30();
            if (lVar9 == 0) {
              FUN_23e915740(param_1,auStack_78,DAT_23eedd200);
              iVar8 = 0x13a;
              pcVar21 = *(code **)(param_1 + 0x138);
              pcStack_c0 = pcStack_70;
              plStack_b8 = (longlong *)auStack_78;
              pcVar23 = pcStack_68;
LAB_23e80ffbf:
              pcStack_68 = (code *)0x0;
              _auStack_78 = (undefined1  [16])0x0;
              *(longlong **)(param_1 + 0x138) = plVar15;
              if (pcVar21 != (code *)0x0) goto LAB_23e80ec00;
              auStack_78 = (undefined1  [8])plStack_b8;
              pcStack_70 = pcStack_c0;
              if (pcVar23 == (code *)0x0) {
                pcStack_68 = (code *)0x0;
                goto LAB_23e80f490;
              }
            }
            else {
              plVar16 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eedd260);
              if (plVar16 == (longlong *)0x0) {
                plStack_b8 = *(longlong **)(param_1 + 0x60);
                pcVar23 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                iVar8 = 0x13a;
                pcVar21 = *(code **)(param_1 + 0x138);
                pcStack_c0 = *(code **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e80ffbf;
              }
              *(undefined4 *)(plVar20 + 5) = 0x13a;
              plVar17 = (longlong *)FUN_23e914090(param_1,plVar16);
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                (**(code **)(plVar16[1] + 0x30))(plVar16);
              }
              if (plVar17 == (longlong *)0x0) {
                plStack_b8 = *(longlong **)(param_1 + 0x60);
                pcVar23 = *(code **)(param_1 + 0x70);
                iVar8 = 0x13a;
                *(undefined8 *)(param_1 + 0x70) = 0;
                pcVar21 = *(code **)(param_1 + 0x138);
                pcStack_c0 = *(code **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e80ffbf;
              }
              *plVar17 = *plVar17 + -1;
              if (*plVar17 == 0) {
                (**(code **)(plVar17[1] + 0x30))(plVar17);
              }
              pcVar21 = *(code **)(param_1 + 0x138);
              pcStack_70 = pcVar21;
              if ((pcVar21 == pcVar23) || (pcVar21 == (code *)0x0)) {
                plStack_b8 = *(longlong **)PyExc_RuntimeError_exref;
                pcStack_c0 = (code *)PyUnicode_FromString("No active exception to reraise");
                *plStack_b8 = *plStack_b8 + 1;
                pcVar21 = *(code **)(param_1 + 0x138);
                iVar8 = 0x131;
                pcVar23 = (code *)0x0;
                goto LAB_23e80ffbf;
              }
              plStack_b8 = *(longlong **)(pcVar21 + 8);
              *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
              *plStack_b8 = *plStack_b8 + 1;
              auStack_78 = (undefined1  [8])plStack_b8;
              pcVar23 = *(code **)(pcVar21 + 0x28);
              pcStack_c0 = pcVar21;
              pcStack_68 = pcVar23;
              if (pcVar23 == (code *)0x0) {
                iVar8 = 0;
                *(longlong **)(param_1 + 0x138) = plVar15;
              }
              else {
                *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
                if (*(longlong **)(pcVar23 + 0x18) == plVar20) {
                  *(undefined4 *)(plVar20 + 5) = *(undefined4 *)(pcVar23 + 0x24);
                }
                iVar8 = 0;
                *(longlong **)(param_1 + 0x138) = plVar15;
              }
LAB_23e80ec00:
              *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
              if (*(longlong *)pcVar21 == 0) {
                (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))();
              }
              auStack_78 = (undefined1  [8])plStack_b8;
              pcStack_70 = pcStack_c0;
              if (pcVar23 == (code *)0x0) {
                pcStack_68 = (code *)0x0;
                if (iVar8 == 0) {
                  iVar8 = (int)plVar20[5];
                }
                goto LAB_23e80f490;
              }
            }
            pcVar21 = pcVar23;
            pcVar6 = pcVar23;
            auStack_78 = (undefined1  [8])plStack_b8;
            pcStack_70 = pcStack_c0;
            if (*(longlong **)(pcVar23 + 0x18) == plVar20) goto LAB_23e80ee11;
            pcStack_68 = pcVar23;
            if (iVar8 == 0) {
              iVar8 = (int)plVar20[5];
            }
          }
        }
      }
LAB_23e80ed70:
      pcVar21 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar21 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar6 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar6;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong **)(pcVar21 + 0x18) = plVar20;
      *plVar20 = *plVar20 + 1;
      lVar9 = *(longlong *)(pcVar24 + 0x1f8);
      *(int *)(pcVar21 + 0x24) = iVar8;
      *(undefined4 *)(pcVar21 + 0x20) = 0xffffffff;
      lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
      lVar25 = *(longlong *)(pcVar21 + -8);
      puVar4 = *(undefined8 **)(lVar9 + 8);
      *puVar4 = pcVar21 + -0x10;
      *(longlong *)(pcVar21 + -0x10) = lVar9;
      *(ulonglong *)(pcVar21 + -8) = (ulonglong)((uint)lVar25 & 3) | (ulonglong)puVar4;
      lVar25 = *(longlong *)pcVar23;
      *(code **)(lVar9 + 8) = pcVar21 + -0x10;
      *(code **)(pcVar21 + 0x10) = pcVar23;
      pcVar6 = pcVar21;
      if (lVar25 == 0) {
        (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
      }
      goto LAB_23e80ee11;
    }
    plStack_b8 = *(longlong **)(param_1 + 0x60);
    pcVar23 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_c0 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar24 = _PyRuntime_exref;
    auStack_78 = (undefined1  [8])plStack_b8;
    pcStack_70 = pcStack_c0;
    if (pcVar23 != (code *)0x0) {
      pcStack_68 = pcVar23;
      if (plVar20 != *(longlong **)(pcVar23 + 0x18)) {
        plVar14 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plStack_c8 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        iVar8 = 300;
        goto LAB_23e80ed70;
      }
      goto LAB_23e80f408;
    }
    plVar14 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    iVar8 = 300;
    pcStack_68 = (code *)0x0;
  }
LAB_23e80f490:
  pcVar21 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar21 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar23 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar23;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong *)(pcVar21 + 0x10) = 0;
  *(longlong **)(pcVar21 + 0x18) = plVar20;
  *plVar20 = *plVar20 + 1;
  lVar9 = *(longlong *)(pcVar24 + 0x1f8);
  *(int *)(pcVar21 + 0x24) = iVar8;
  lVar9 = *(longlong *)(lVar9 + 0x10);
  *(undefined4 *)(pcVar21 + 0x20) = 0xffffffff;
  lVar9 = *(longlong *)(lVar9 + 0x2e8);
  lVar25 = *(longlong *)(pcVar21 + -8);
  puVar4 = *(undefined8 **)(lVar9 + 8);
  *puVar4 = pcVar21 + -0x10;
  *(longlong *)(pcVar21 + -0x10) = lVar9;
  *(ulonglong *)(pcVar21 + -8) = (ulonglong)((uint)lVar25 & 3) | (ulonglong)puVar4;
  *(code **)(lVar9 + 8) = pcVar21 + -0x10;
  pcVar6 = pcVar21;
LAB_23e80ee11:
  pcStack_68 = pcVar6;
  FUN_23e8bba40(plVar20,"oooooooo",plVar2,plVar3,plVar12,plVar10,plVar11,plVar13,plStack_c8,plVar14)
  ;
  if (_DAT_23eede8a0 == plVar20) {
    *plVar20 = *plVar20 + -1;
    if (*plVar20 == 0) {
      (**(code **)(plVar20[1] + 0x30))(plVar20);
    }
    _DAT_23eede8a0 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar20 = *(longlong **)(lVar9 + 0x28);
  plVar15 = (longlong *)plVar20[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
  *(undefined4 *)(plVar20 + 8) = 0xffffffff;
  if (plVar15 != (longlong *)0x0) {
    plVar20[2] = 0;
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      (**(code **)(plVar15[1] + 0x30))();
    }
  }
  *plVar20 = *plVar20 + -1;
  if (*plVar20 == 0) {
    (**(code **)(plVar20[1] + 0x30))(plVar20);
  }
  plVar20[0xf] = 0;
  pcStack_68 = (code *)0x0;
  _auStack_78 = (undefined1  [16])0x0;
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plStack_c8 != (longlong *)0x0) &&
     (lVar9 = *plStack_c8, *plStack_c8 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_c8[1] + 0x30))(plStack_c8);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  lVar9 = *plVar2;
  *plVar2 = lVar9 + -1;
  if (lVar9 + -1 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  lVar9 = *plVar3;
  *plVar3 = lVar9 + -1;
  if (lVar9 + -1 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  FUN_23a33aa70(param_1,plStack_b8,pcStack_c0,pcVar21);
  return (longlong *)0x0;
}
