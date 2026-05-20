/* ===== 23c65e4c0 license.hwid_generator:48 ===== */
/* ghidra_name=FUN_23c65e4c0 entry=23c65e4c0 size=14725 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

longlong * FUN_23c65e4c0(longlong param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  char cVar3;
  int iVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong lVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined8 uVar13;
  code *pcVar14;
  longlong *plVar15;
  longlong *plVar16;
  code *pcVar17;
  longlong *plVar18;
  code *pcVar19;
  undefined4 uVar20;
  undefined1 auVar21 [8];
  code *pcVar22;
  longlong *plStack_130;
  longlong *plStack_128;
  longlong *plStack_120;
  longlong *plStack_118;
  longlong *plStack_110;
  longlong *plStack_108;
  code *pcStack_100;
  longlong *plStack_d8;
  longlong *plStack_d0;
  longlong *plStack_c8;
  undefined8 uStack_c0;
  undefined1 auStack_b8 [8];
  code *pcStack_b0;
  code *apcStack_a8 [2];
  undefined1 auStack_98 [16];
  code *pcStack_88;
  longlong *plStack_80;
  code *pcStack_78;
  code *pcStack_70;
  code *pcStack_68;
  code *pcStack_60;
  
  plVar5 = _DAT_23ee29d88;
  apcStack_a8[0] = (code *)0x0;
  auStack_b8 = (undefined1  [8])0x0;
  pcStack_b0 = (code *)0x0;
  if (_DAT_23ee29d88 == (longlong *)0x0) {
LAB_23c65e51c:
    _DAT_23ee29d88 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23ee29d80,_DAT_23ee29d98);
  }
  else {
    lVar7 = *_DAT_23ee29d88;
    if (1 < lVar7) {
      *_DAT_23ee29d88 = lVar7 + -1;
      goto LAB_23c65e51c;
    }
    if (_DAT_23ee29d88[2] != 0) {
      *_DAT_23ee29d88 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar5[1] + 0x30))(plVar5);
      }
      goto LAB_23c65e51c;
    }
  }
  plVar2 = _DAT_23ee29d88;
  lVar7 = *(longlong *)(param_1 + 0x38);
  plVar5 = _DAT_23ee29d88 + 9;
  lVar8 = *(longlong *)(lVar7 + 8);
  _DAT_23ee29d88[0xf] = lVar8;
  *(longlong **)(lVar7 + 8) = plVar5;
  if ((lVar8 != 0) &&
     (((*(char *)(lVar8 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar8 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar8 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar8 + 0x38))
       ) && (plVar2[0xe] != 0)))) {
    plVar5 = *(longlong **)(lVar8 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar5;
    if (plVar5 != (longlong *)0x0) {
      *plVar5 = *plVar5 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  *(undefined4 *)(plVar2 + 8) = 0;
  if ((DAT_23ed8fb50 == 0) && (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0))
  {
    DAT_23ed8fb50 = 0;
    goto LAB_23c65f100;
  }
  plVar5 = (longlong *)FUN_23e8bc2f0(DAT_23ed8fb50,_DAT_23ee28ce0);
  if (plVar5 == (longlong *)0x0) {
    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_b0 = *(code **)(param_1 + 0x68);
    apcStack_a8[0] = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (apcStack_a8[0] != (code *)0x0) {
      if (plVar2 == *(longlong **)(apcStack_a8[0] + 0x18)) {
LAB_23c65f7a0:
        plStack_128 = (longlong *)0x0;
        plStack_d0 = (longlong *)0x0;
        plVar5 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plVar6 = (longlong *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        pcVar14 = apcStack_a8[0];
        goto LAB_23c65f310;
      }
      plStack_128 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x0;
      plVar5 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plVar6 = (longlong *)0x0;
      iVar4 = 0x32;
      plStack_118 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      pcVar22 = _PyRuntime_exref;
      goto LAB_23c65f275;
    }
LAB_23c65fc30:
    plStack_128 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plVar5 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    plVar6 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    iVar4 = 0x32;
    plStack_118 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    pcVar22 = _PyRuntime_exref;
LAB_23c65fa89:
    pcVar14 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar14 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      pcVar17 = apcStack_a8[0];
    }
    else {
      pcVar17 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar17;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      pcVar17 = (code *)0x0;
    }
    *(longlong *)(pcVar14 + 0x10) = 0;
    *(longlong **)(pcVar14 + 0x18) = plVar2;
    *plVar2 = *plVar2 + 1;
    lVar7 = *(longlong *)(pcVar22 + 0x1f8);
    *(int *)(pcVar14 + 0x24) = iVar4;
    lVar7 = *(longlong *)(lVar7 + 0x10);
    *(undefined4 *)(pcVar14 + 0x20) = 0xffffffff;
    lVar7 = *(longlong *)(lVar7 + 0x2e8);
    lVar8 = *(longlong *)(pcVar14 + -8);
    plVar10 = *(longlong **)(lVar7 + 8);
    *plVar10 = (longlong)(pcVar14 + -0x10);
    *(longlong *)(pcVar14 + -0x10) = lVar7;
    *(ulonglong *)(pcVar14 + -8) = (ulonglong)((uint)lVar8 & 3) | (ulonglong)plVar10;
    *(code **)(lVar7 + 8) = pcVar14 + -0x10;
  }
  else {
    plVar6 = (longlong *)FUN_23e8bc2f0(plVar5,_DAT_23ee28ce8);
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))();
    }
    if (plVar6 == (longlong *)0x0) {
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_b0 = *(code **)(param_1 + 0x68);
      apcStack_a8[0] = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (apcStack_a8[0] == (code *)0x0) goto LAB_23c65fc30;
      if (plVar2 == *(longlong **)(apcStack_a8[0] + 0x18)) goto LAB_23c65f7a0;
      plStack_128 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x0;
      plVar5 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      iVar4 = 0x32;
      plStack_118 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      pcVar22 = _PyRuntime_exref;
    }
    else {
      plStack_130 = (longlong *)FUN_23e8bc2f0(plVar6,_DAT_23ee28cf0);
      if (plStack_130 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        apcStack_a8[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar22 = _PyRuntime_exref;
        if (apcStack_a8[0] != (code *)0x0) {
          plStack_128 = (longlong *)0x0;
          plStack_d0 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plVar5 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          pcVar14 = apcStack_a8[0];
          if (plVar2 == *(longlong **)(apcStack_a8[0] + 0x18)) goto LAB_23c65f310;
          iVar4 = 0x33;
          goto LAB_23c65f275;
        }
        plStack_128 = (longlong *)0x0;
        plStack_d0 = (longlong *)0x0;
        plVar5 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        iVar4 = 0x33;
        plStack_118 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        goto LAB_23c65fa89;
      }
      if ((DAT_23ed8fb50 == 0) &&
         (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0)) {
LAB_23c65f100:
        FUN_23e9364c0("%s : %s\n","IMPORT_HARD_CTYPES",
                      "\"Unexpected failure of hard import of \'ctypes\'\"");
                    /* WARNING: Subroutine does not return */
        abort();
      }
      lVar7 = FUN_23e8bc2f0(DAT_23ed8fb50,_DAT_23ee28cf8);
      if (lVar7 == 0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        apcStack_a8[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar22 = _PyRuntime_exref;
        if (apcStack_a8[0] == (code *)0x0) {
          plStack_128 = (longlong *)0x0;
          plStack_d0 = (longlong *)0x0;
          plVar5 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          iVar4 = 0x35;
          plStack_118 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          goto LAB_23c65fa89;
        }
        if (*(longlong **)(apcStack_a8[0] + 0x18) == plVar2) goto LAB_23c65f5bb;
        plStack_128 = (longlong *)0x0;
        plStack_d0 = (longlong *)0x0;
        plVar5 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        iVar4 = 0x35;
        plStack_118 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        goto LAB_23c65f275;
      }
      plVar5 = (longlong *)FUN_23e8d6340(*(undefined8 *)(param_1 + 0x10),8);
      *(longlong *)plVar5[3] = lVar7;
      if ((DAT_23ed8fb50 == 0) &&
         (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0)) {
        DAT_23ed8fb50 = 0;
        goto LAB_23c65f100;
      }
      lVar8 = FUN_23e8bc2f0(DAT_23ed8fb50,_DAT_23ee28cf8);
      lVar7 = DAT_23ed8fb50;
      if (lVar8 != 0) {
        *(longlong *)(plVar5[3] + 8) = lVar8;
        if ((lVar7 == 0) &&
           (lVar7 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 = lVar7, lVar7 == 0)) {
          DAT_23ed8fb50 = 0;
          goto LAB_23c65f100;
        }
        lVar8 = FUN_23e8bc2f0(lVar7,_DAT_23ee28d00);
        lVar7 = DAT_23ed8fb50;
        if (lVar8 == 0) {
          auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_b0 = *(code **)(param_1 + 0x68);
          apcStack_a8[0] = *(code **)(param_1 + 0x70);
          iVar4 = 0x37;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23c65f1e6;
        }
        *(longlong *)(plVar5[3] + 0x10) = lVar8;
        if ((lVar7 == 0) &&
           (lVar7 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 = lVar7, lVar7 == 0)) {
          DAT_23ed8fb50 = 0;
          goto LAB_23c65f100;
        }
        plVar9 = (longlong *)FUN_23e8bc2f0(lVar7,_DAT_23ee28d08);
        if (plVar9 == (longlong *)0x0) {
LAB_23c65f1b8:
          apcStack_a8[0] = *(code **)(param_1 + 0x70);
          auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_b0 = *(code **)(param_1 + 0x68);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23c65f1e1:
          iVar4 = 0x38;
          goto LAB_23c65f1e6;
        }
        if ((DAT_23ed8fb50 == 0) &&
           (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0)) {
          DAT_23ed8fb50 = 0;
          goto LAB_23c65f100;
        }
        plVar10 = (longlong *)FUN_23e8bc2f0(DAT_23ed8fb50,_DAT_23ee28d10);
        if (plVar10 == (longlong *)0x0) {
          auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_b0 = *(code **)(param_1 + 0x68);
          apcStack_a8[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))();
          }
          goto LAB_23c65f1e1;
        }
        *(undefined4 *)(plVar2 + 5) = 0x38;
        lVar7 = FUN_23e914090(param_1,plVar9,plVar10);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))();
        }
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))();
        }
        lVar8 = DAT_23ed8fb50;
        if (lVar7 == 0) goto LAB_23c65f1b8;
        *(longlong *)(plVar5[3] + 0x18) = lVar7;
        if ((lVar8 == 0) &&
           (lVar8 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 = lVar8, lVar8 == 0)) {
          DAT_23ed8fb50 = 0;
          goto LAB_23c65f100;
        }
        plVar9 = (longlong *)FUN_23e8bc2f0(lVar8,_DAT_23ee28d08);
        if (plVar9 == (longlong *)0x0) {
LAB_23c65f920:
          apcStack_a8[0] = *(code **)(param_1 + 0x70);
          auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_b0 = *(code **)(param_1 + 0x68);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23c65f949:
          iVar4 = 0x39;
          goto LAB_23c65f1e6;
        }
        if ((DAT_23ed8fb50 == 0) &&
           (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0)) {
          DAT_23ed8fb50 = 0;
          goto LAB_23c65f100;
        }
        plVar10 = (longlong *)FUN_23e8bc2f0(DAT_23ed8fb50,_DAT_23ee28d10);
        if (plVar10 == (longlong *)0x0) {
          auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_b0 = *(code **)(param_1 + 0x68);
          apcStack_a8[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))();
          }
          goto LAB_23c65f949;
        }
        *(undefined4 *)(plVar2 + 5) = 0x39;
        lVar7 = FUN_23e914090(param_1,plVar9,plVar10);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))();
        }
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))();
        }
        lVar8 = DAT_23ed8fb50;
        if (lVar7 == 0) goto LAB_23c65f920;
        *(longlong *)(plVar5[3] + 0x20) = lVar7;
        if ((lVar8 == 0) &&
           (lVar8 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 = lVar8, lVar8 == 0)) {
          DAT_23ed8fb50 = 0;
          goto LAB_23c65f100;
        }
        plVar9 = (longlong *)FUN_23e8bc2f0(lVar8,_DAT_23ee28d08);
        if (plVar9 == (longlong *)0x0) {
LAB_23c65fb48:
          apcStack_a8[0] = *(code **)(param_1 + 0x70);
          auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_b0 = *(code **)(param_1 + 0x68);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23c65fb71:
          iVar4 = 0x3a;
          goto LAB_23c65f1e6;
        }
        if ((DAT_23ed8fb50 == 0) &&
           (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0)) {
          DAT_23ed8fb50 = 0;
          goto LAB_23c65f100;
        }
        plVar10 = (longlong *)FUN_23e8bc2f0(DAT_23ed8fb50,_DAT_23ee28d10);
        if (plVar10 == (longlong *)0x0) {
          auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_b0 = *(code **)(param_1 + 0x68);
          apcStack_a8[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))();
          }
          goto LAB_23c65fb71;
        }
        *(undefined4 *)(plVar2 + 5) = 0x3a;
        lVar7 = FUN_23e914090(param_1,plVar9,plVar10);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))();
        }
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))();
        }
        lVar8 = DAT_23ed8fb50;
        if (lVar7 == 0) goto LAB_23c65fb48;
        *(longlong *)(plVar5[3] + 0x28) = lVar7;
        if ((lVar8 == 0) &&
           (lVar8 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 = lVar8, lVar8 == 0)) {
          DAT_23ed8fb50 = 0;
          goto LAB_23c65f100;
        }
        lVar8 = FUN_23e8bc2f0(lVar8,_DAT_23ee28cf8);
        lVar7 = DAT_23ed8fb50;
        if (lVar8 == 0) {
          auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_b0 = *(code **)(param_1 + 0x68);
          apcStack_a8[0] = *(code **)(param_1 + 0x70);
          iVar4 = 0x3b;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23c65f1e6;
        }
        *(longlong *)(plVar5[3] + 0x30) = lVar8;
        if ((lVar7 == 0) &&
           (lVar7 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 = lVar7, lVar7 == 0)) {
          DAT_23ed8fb50 = 0;
          goto LAB_23c65f100;
        }
        lVar7 = FUN_23e8bc2f0(lVar7,_DAT_23ee28d00);
        if (lVar7 == 0) {
          auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_b0 = *(code **)(param_1 + 0x68);
          apcStack_a8[0] = *(code **)(param_1 + 0x70);
          iVar4 = 0x3c;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23c65f1e6;
        }
        *(longlong *)(plVar5[3] + 0x38) = lVar7;
        cVar3 = FUN_23e8d9ac0(plStack_130,_DAT_23ee28d18,plVar5);
        *plVar5 = *plVar5 + -1;
        if (*plVar5 == 0) {
          (**(code **)(plVar5[1] + 0x30))();
        }
        if (cVar3 == '\0') {
          auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_b0 = *(code **)(param_1 + 0x68);
          apcStack_a8[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar22 = _PyRuntime_exref;
          if (apcStack_a8[0] == (code *)0x0) {
            plStack_128 = (longlong *)0x0;
            plStack_d0 = (longlong *)0x0;
            plVar5 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            iVar4 = 0x34;
            plStack_118 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            goto LAB_23c65fa89;
          }
          if (plVar2 == *(longlong **)(apcStack_a8[0] + 0x18)) goto LAB_23c65f5bb;
          plStack_128 = (longlong *)0x0;
          plStack_d0 = (longlong *)0x0;
          plVar5 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          iVar4 = 0x34;
          plStack_118 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          goto LAB_23c65f275;
        }
        if ((DAT_23ed8fb50 == 0) &&
           (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0)) {
          DAT_23ed8fb50 = 0;
          goto LAB_23c65f100;
        }
        plVar5 = (longlong *)FUN_23e8bc2f0(DAT_23ed8fb50,_DAT_23ee28d20);
        if (plVar5 == (longlong *)0x0) {
          auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_b0 = *(code **)(param_1 + 0x68);
          apcStack_a8[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (apcStack_a8[0] != (code *)0x0) {
            if (*(longlong **)(apcStack_a8[0] + 0x18) != plVar2) {
              plStack_128 = (longlong *)0x0;
              plStack_d0 = (longlong *)0x0;
              plVar5 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              iVar4 = 0x3e;
              plStack_118 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              pcVar22 = _PyRuntime_exref;
              goto LAB_23c65f275;
            }
            goto LAB_23c65f5bb;
          }
        }
        else {
          cVar3 = FUN_23e8d9ac0(plStack_130,_DAT_23ee28d28,plVar5);
          *plVar5 = *plVar5 + -1;
          if (*plVar5 == 0) {
            (**(code **)(plVar5[1] + 0x30))();
          }
          if (cVar3 != '\0') {
            lVar7 = *(longlong *)(param_1 + 0x10);
            if (*(int *)(lVar7 + 0x1188) == 0) {
              plVar5 = (longlong *)FUN_23a33a530(PyList_Type_exref);
            }
            else {
              iVar4 = *(int *)(lVar7 + 0x1188) + -1;
              *(int *)(lVar7 + 0x1188) = iVar4;
              plVar5 = *(longlong **)(lVar7 + 0xf08 + (longlong)iVar4 * 8);
              *plVar5 = 1;
            }
            pcVar22 = _PyRuntime_exref;
            plVar5[2] = 0;
            plVar5[4] = 0;
            lVar7 = *(longlong *)(pcVar22 + 0x1f8);
            plVar5[3] = 0;
            lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
            lVar8 = plVar5[-1];
            puVar1 = *(undefined8 **)(lVar7 + 8);
            *puVar1 = plVar5 + -2;
            plVar5[-2] = lVar7;
            plVar5[-1] = (ulonglong)((uint)lVar8 & 3) | (ulonglong)puVar1;
            *(longlong **)(lVar7 + 8) = plVar5 + -2;
            if ((DAT_23ed6a4b8 == 0) &&
               (DAT_23ed6a4b8 = PyImport_ImportModule(&DAT_23ec47932), DAT_23ed6a4b8 == 0))
            goto LAB_23c660b4a;
            plVar9 = (longlong *)FUN_23e8bc2f0(DAT_23ed6a4b8,_DAT_23ee28d30);
            if (plVar9 != (longlong *)0x0) {
              plVar10 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23ed6ce40);
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              if (plVar10 != (longlong *)0x0) {
                *(undefined4 *)(plVar2 + 5) = 0x43;
                plVar9 = (longlong *)FUN_23e9557e0(param_1,plVar10);
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                if (plVar9 != (longlong *)0x0) {
                  plVar10 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23ee28ca8);
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  if (plVar10 != (longlong *)0x0) {
                    *(undefined4 *)(plVar2 + 5) = 0x43;
                    plVar9 = (longlong *)FUN_23e91a870(param_1,plVar10);
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                    }
                    if (plVar9 != (longlong *)0x0) {
                      iVar4 = FUN_23a35f020(plVar9);
                      if (iVar4 == -1) {
                        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_b0 = *(code **)(param_1 + 0x68);
                        apcStack_a8[0] = *(code **)(param_1 + 0x70);
                        uVar20 = 0x44;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      }
                      else if (iVar4 == 0) {
LAB_23c65eb3c:
                        if ((DAT_23ed6a4b8 == 0) &&
                           (DAT_23ed6a4b8 = PyImport_ImportModule(&DAT_23ec47932),
                           DAT_23ed6a4b8 == 0)) {
                          DAT_23ed6a4b8 = 0;
LAB_23c660b4a:
                          FUN_23e9364c0("%s : %s\n","IMPORT_HARD_OS",
                                        "\"Unexpected failure of hard import of \'os\'\"");
                    /* WARNING: Subroutine does not return */
                          abort();
                        }
                        plVar10 = (longlong *)FUN_23e8bc2f0(DAT_23ed6a4b8,_DAT_23ee28d30);
                        if (plVar10 != (longlong *)0x0) {
                          plVar11 = (longlong *)FUN_23e8bc2f0(plVar10,DAT_23ed6ce40);
                          *plVar10 = *plVar10 + -1;
                          if (*plVar10 == 0) {
                            FUN_23a334bc0(plVar10);
                          }
                          if (plVar11 == (longlong *)0x0) {
                            pcVar14 = *(code **)(param_1 + 0x70);
                            auVar21 = *(undefined1 (*) [8])(param_1 + 0x60);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            plStack_d0 = (longlong *)0x0;
                            uVar20 = 0x47;
                            plStack_128 = (longlong *)0x0;
                            plStack_120 = (longlong *)0x0;
                            plStack_118 = (longlong *)0x0;
                            plStack_110 = (longlong *)0x0;
                            pcStack_100 = _Py_NoneStruct_exref;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plStack_108 = (longlong *)0x0;
                            pcVar17 = *(code **)(param_1 + 0x68);
                            goto LAB_23c65fe76;
                          }
                          *(undefined4 *)(plVar2 + 5) = 0x47;
                          plVar10 = (longlong *)FUN_23e9557e0(param_1,plVar11);
                          lVar7 = *plVar11;
                          *plVar11 = lVar7 + -1;
                          if (lVar7 + -1 == 0) {
                            FUN_23a334bc0(plVar11);
                          }
                          if (plVar10 != (longlong *)0x0) {
                            plVar11 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23ee28ca8);
                            *plVar10 = *plVar10 + -1;
                            if (*plVar10 == 0) {
                              FUN_23a334bc0(plVar10);
                            }
                            if (plVar11 != (longlong *)0x0) {
                              *(undefined4 *)(plVar2 + 5) = 0x47;
                              plStack_108 = (longlong *)FUN_23e91a870(param_1,plVar11);
                              *plVar11 = *plVar11 + -1;
                              if (*plVar11 == 0) {
                                FUN_23a334bc0(plVar11);
                              }
                              if (plStack_108 != (longlong *)0x0) {
                                plVar10 = (longlong *)FUN_23e8bd600(param_1,plStack_108);
                                if (plVar10 == (longlong *)0x0) goto LAB_23c6614e7;
                                cVar3 = FUN_23e8d1960(plVar10,2);
                                *plVar10 = *plVar10 + -1;
                                if (*plVar10 == 0) {
                                  FUN_23a334bc0(plVar10);
                                }
                                if (cVar3 != '\0') goto LAB_23c66137e;
                                goto LAB_23c65ed2a;
                              }
                            }
                          }
                        }
                        apcStack_a8[0] = *(code **)(param_1 + 0x70);
                        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_b0 = *(code **)(param_1 + 0x68);
                        uVar20 = 0x47;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      }
                      else {
                        plVar10 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23ee28d40);
                        if (plVar10 != (longlong *)0x0) {
                          *(undefined4 *)(plVar2 + 5) = 0x45;
                          plVar11 = (longlong *)FUN_23e94bb80(param_1,plVar10);
                          *plVar10 = *plVar10 + -1;
                          if (*plVar10 == 0) {
                            FUN_23a334bc0(plVar10);
                          }
                          if (plVar11 == (longlong *)0x0) {
                            pcVar14 = *(code **)(param_1 + 0x70);
                            auVar21 = *(undefined1 (*) [8])(param_1 + 0x60);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uVar20 = 0x45;
                            plStack_128 = (longlong *)0x0;
                            plStack_d0 = (longlong *)0x0;
                            plStack_120 = (longlong *)0x0;
                            plStack_118 = (longlong *)0x0;
                            plStack_110 = (longlong *)0x0;
                            pcStack_100 = _Py_NoneStruct_exref;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plStack_108 = (longlong *)0x0;
                            pcVar17 = *(code **)(param_1 + 0x68);
                            goto LAB_23c65fe76;
                          }
                          lVar8 = FUN_23e8c0500(plVar11,DAT_23ed6cea8);
                          lVar7 = *plVar11;
                          *plVar11 = lVar7 + -1;
                          if (lVar7 + -1 == 0) {
                            FUN_23a334bc0(plVar11);
                          }
                          if (lVar8 != 0) {
                            FUN_23e8ba4b0(plVar5,lVar8);
                            goto LAB_23c65eb3c;
                          }
                        }
                        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_b0 = *(code **)(param_1 + 0x68);
                        apcStack_a8[0] = *(code **)(param_1 + 0x70);
                        uVar20 = 0x45;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      }
                      plStack_d0 = (longlong *)0x0;
                      plStack_128 = (longlong *)0x0;
                      plStack_120 = (longlong *)0x0;
                      plStack_118 = (longlong *)0x0;
                      plStack_110 = (longlong *)0x0;
                      plStack_108 = (longlong *)0x0;
                      pcStack_100 = _Py_NoneStruct_exref;
                      pcVar14 = apcStack_a8[0];
                      auVar21 = auStack_b8;
                      pcVar17 = pcStack_b0;
                      goto LAB_23c65fe76;
                    }
                  }
                }
              }
            }
            pcVar14 = *(code **)(param_1 + 0x70);
            auVar21 = *(undefined1 (*) [8])(param_1 + 0x60);
            uVar20 = 0x43;
            plStack_d0 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar9 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            pcStack_100 = _Py_NoneStruct_exref;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcVar17 = *(code **)(param_1 + 0x68);
LAB_23c65fe76:
            pcStack_b0 = pcVar17;
            auStack_b8 = auVar21;
            apcStack_a8[0] = pcVar14;
            pcVar14 = apcStack_a8[0];
            auStack_98._8_8_ = pcStack_b0;
            auStack_98._0_8_ = auStack_b8;
            apcStack_a8[0] = (code *)0x0;
            auStack_b8 = (undefined1  [8])0x0;
            pcStack_b0 = (code *)0x0;
            pcStack_88 = pcVar14;
            plVar10 = *(longlong **)(param_1 + 0x138);
            if (plVar10 != (longlong *)0x0) {
              *plVar10 = *plVar10 + 1;
            }
            pcVar17 = DAT_23ed6a4f8;
            if (pcVar14 == (code *)0x0) {
              if (DAT_23ed6a4f8 == (code *)0x0) {
                pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
              }
              else {
                pcVar14 = *(code **)DAT_23ed6a4f8;
                *(undefined8 *)DAT_23ed6a4f8 = 1;
                DAT_23ed6a4f8 = pcVar14;
                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              }
              *(longlong *)(pcVar17 + 0x10) = 0;
              *(longlong **)(pcVar17 + 0x18) = plVar2;
              *plVar2 = *plVar2 + 1;
              lVar7 = *(longlong *)(pcVar22 + 0x1f8);
              *(undefined4 *)(pcVar17 + 0x24) = uVar20;
              lVar7 = *(longlong *)(lVar7 + 0x10);
              *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
              lVar7 = *(longlong *)(lVar7 + 0x2e8);
              lVar8 = *(longlong *)(pcVar17 + -8);
              plVar11 = *(longlong **)(lVar7 + 8);
              *plVar11 = (longlong)(pcVar17 + -0x10);
              *(longlong *)(pcVar17 + -0x10) = lVar7;
              *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar8 & 3) | (ulonglong)plVar11;
              *(code **)(lVar7 + 8) = pcVar17 + -0x10;
              if ((pcStack_88 != (code *)0x0) &&
                 (*(longlong *)pcStack_88 = *(longlong *)pcStack_88 + -1,
                 *(longlong *)pcStack_88 == 0)) {
                (**(code **)(*(longlong *)(pcStack_88 + 8) + 0x30))(pcStack_88);
              }
            }
            else {
              if (DAT_23ed6a4f8 == (code *)0x0) {
                pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
              }
              else {
                pcVar19 = *(code **)DAT_23ed6a4f8;
                *(undefined8 *)DAT_23ed6a4f8 = 1;
                DAT_23ed6a4f8 = pcVar19;
                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              }
              *(longlong **)(pcVar17 + 0x18) = plVar2;
              *plVar2 = *plVar2 + 1;
              lVar7 = *(longlong *)(pcVar22 + 0x1f8);
              *(undefined4 *)(pcVar17 + 0x24) = uVar20;
              lVar7 = *(longlong *)(lVar7 + 0x10);
              *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
              lVar7 = *(longlong *)(lVar7 + 0x2e8);
              lVar8 = *(longlong *)(pcVar17 + -8);
              plVar11 = *(longlong **)(lVar7 + 8);
              *plVar11 = (longlong)(pcVar17 + -0x10);
              *(longlong *)(pcVar17 + -0x10) = lVar7;
              *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar8 & 3) | (ulonglong)plVar11;
              *(code **)(lVar7 + 8) = pcVar17 + -0x10;
              *(code **)(pcVar17 + 0x10) = pcVar14;
              *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
              if ((pcStack_88 != (code *)0x0) &&
                 (*(longlong *)pcStack_88 = *(longlong *)pcStack_88 + -1,
                 *(longlong *)pcStack_88 == 0)) {
                (**(code **)(*(longlong *)(pcStack_88 + 8) + 0x30))(pcStack_88);
              }
            }
            pcStack_88 = pcVar17;
            if (((code *)auStack_98._0_8_ != pcStack_100) &&
               ((code *)auStack_98._0_8_ != (code *)0x0)) {
              FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,&pcStack_88);
            }
            plVar11 = *(longlong **)(auStack_98._8_8_ + 0x28);
            if (pcStack_88 == pcStack_100) {
              pcVar14 = (code *)0x0;
            }
            else {
              pcVar14 = pcStack_88;
              if (pcStack_88 != (code *)0x0) {
                *(longlong *)pcStack_88 = *(longlong *)pcStack_88 + 1;
              }
            }
            *(code **)(auStack_98._8_8_ + 0x28) = pcVar14;
            if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
              (**(code **)(plVar11[1] + 0x30))();
            }
            plVar11 = *(longlong **)(param_1 + 0x138);
            *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
            if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
              (**(code **)(plVar11[1] + 0x30))();
            }
            *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + -1;
            if (*(longlong *)auStack_98._0_8_ == 0) {
              (**(code **)(*(longlong *)(auStack_98._0_8_ + 8) + 0x30))();
            }
            if ((pcStack_88 != (code *)0x0) &&
               (*(longlong *)pcStack_88 = *(longlong *)pcStack_88 + -1, *(longlong *)pcStack_88 == 0
               )) {
              (**(code **)(*(longlong *)(pcStack_88 + 8) + 0x30))();
            }
            pcStack_88 = (code *)0x0;
            auStack_98 = (undefined1  [16])0x0;
            iVar4 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                                  *(undefined8 *)PyExc_Exception_exref);
            if (iVar4 == 0) {
              pcVar17 = *(code **)(param_1 + 0x138);
              pcStack_b0 = pcVar17;
              if ((pcVar17 == pcStack_100) || (pcVar17 == (code *)0x0)) {
                pcVar14 = (code *)0x0;
                auVar21 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
                pcVar19 = (code *)PyUnicode_FromString("No active exception to reraise");
                pcVar17 = *(code **)(param_1 + 0x138);
                iVar4 = 0x41;
                *(longlong *)auVar21 = *(longlong *)auVar21 + 1;
                goto LAB_23c660cd1;
              }
              auVar21 = *(undefined1 (*) [8])(pcVar17 + 8);
              pcVar14 = *(code **)(pcVar17 + 0x28);
              *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
              *(longlong *)auVar21 = *(longlong *)auVar21 + 1;
              iVar4 = 0;
              pcVar19 = pcVar17;
              if (pcVar14 == (code *)0x0) {
                *(longlong **)(param_1 + 0x138) = plVar10;
              }
              else {
                *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
                if (*(longlong **)(pcVar14 + 0x18) == plVar2) {
                  *(undefined4 *)(plVar2 + 5) = *(undefined4 *)(pcVar14 + 0x24);
                }
                *(longlong **)(param_1 + 0x138) = plVar10;
              }
LAB_23c6609fc:
              apcStack_a8[0] = (code *)0x0;
              _auStack_b8 = (undefined1  [16])0x0;
              *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
              if (*(longlong *)pcVar17 == 0) {
                (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))();
              }
              auStack_b8 = auVar21;
              pcStack_b0 = pcVar19;
              if (pcVar14 == (code *)0x0) {
                apcStack_a8[0] = pcVar14;
                if (iVar4 == 0) {
                  iVar4 = (int)plVar2[5];
                }
                goto LAB_23c65fa89;
              }
LAB_23c660a68:
              if (*(longlong **)(pcVar14 + 0x18) == plVar2) goto LAB_23c65f310;
              apcStack_a8[0] = pcVar14;
              if (iVar4 == 0) {
                iVar4 = (int)plVar2[5];
              }
              goto LAB_23c65f275;
            }
            plVar11 = *(longlong **)(param_1 + 0x138);
            *plVar11 = *plVar11 + 1;
            lVar7 = FUN_23ead6850();
            if (lVar7 == 0) {
              FUN_23e915740(param_1,auStack_b8,_DAT_23ee28cb8);
              auVar21 = auStack_b8;
              pcVar19 = pcStack_b0;
              pcVar14 = apcStack_a8[0];
LAB_23c660c57:
              apcStack_a8[0] = (code *)0x0;
              _auStack_b8 = (undefined1  [16])0x0;
              lVar7 = *plVar11;
              *plVar11 = lVar7 + -1;
              if (lVar7 + -1 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              pcVar17 = *(code **)(param_1 + 0x138);
              iVar4 = 99;
LAB_23c660cd1:
              *(longlong **)(param_1 + 0x138) = plVar10;
              if (pcVar17 != (code *)0x0) goto LAB_23c6609fc;
              apcStack_a8[0] = pcVar14;
              auStack_b8 = auVar21;
              pcStack_b0 = pcVar19;
              if (pcVar14 != (code *)0x0) goto LAB_23c660a68;
              goto LAB_23c65fa89;
            }
            plVar12 = (longlong *)FUN_23e8bc2f0(lVar7,_DAT_23ee28cc0);
            plVar15 = _DAT_23ee28da8;
            if (plVar12 == (longlong *)0x0) {
              auVar21 = *(undefined1 (*) [8])(param_1 + 0x60);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pcVar14 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar19 = *(code **)(param_1 + 0x68);
              goto LAB_23c660c57;
            }
            lVar7 = *(longlong *)(param_1 + 0x10);
            plVar16 = *(longlong **)(lVar7 + 0xe20);
            if (plVar16 == (longlong *)0x0) {
              plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
            }
            else {
              lVar8 = plVar16[3];
              *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
              *(longlong *)(lVar7 + 0xe20) = lVar8;
              *plVar16 = 1;
            }
            lVar7 = *(longlong *)(pcVar22 + 0x1f8);
            plVar16[4] = 0;
            lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
            lVar8 = plVar16[-1];
            puVar1 = *(undefined8 **)(lVar7 + 8);
            *puVar1 = plVar16 + -2;
            plVar16[-2] = lVar7;
            plVar16[-1] = (ulonglong)((uint)lVar8 & 3) | (ulonglong)puVar1;
            *(longlong **)(lVar7 + 8) = plVar16 + -2;
            plVar18 = DAT_23ed6a4c0;
            *plVar15 = *plVar15 + 1;
            plVar16[3] = (longlong)plVar15;
            uVar13 = DAT_23ed6cd28;
            if (plVar18 != (longlong *)0x0) {
LAB_23c660277:
              uStack_c0 = uVar13;
              plStack_c8 = plVar11;
              lVar7 = FUN_23e94ed00(param_1,plVar18,&plStack_c8);
              if (lVar7 == 0) {
                auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcStack_b0 = *(code **)(param_1 + 0x68);
                apcStack_a8[0] = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                *plVar16 = *plVar16 + -1;
                auVar21 = auStack_b8;
                pcVar19 = pcStack_b0;
                pcVar14 = apcStack_a8[0];
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                  auVar21 = auStack_b8;
                  pcVar19 = pcStack_b0;
                  pcVar14 = apcStack_a8[0];
                }
                goto LAB_23c660c57;
              }
              plVar16[4] = lVar7;
              plVar15 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                (**(code **)(plVar16[1] + 0x30))(plVar16);
              }
              if (plVar15 == (longlong *)0x0) {
                auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcStack_b0 = *(code **)(param_1 + 0x68);
                apcStack_a8[0] = *(code **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *plVar12 = *plVar12 + -1;
                auVar21 = auStack_b8;
                pcVar19 = pcStack_b0;
                pcVar14 = apcStack_a8[0];
                if (*plVar12 == 0) {
                  FUN_23a334bc0(plVar12);
                  auVar21 = auStack_b8;
                  pcVar19 = pcStack_b0;
                  pcVar14 = apcStack_a8[0];
                }
                goto LAB_23c660c57;
              }
              *(undefined4 *)(plVar2 + 5) = 99;
              plVar16 = (longlong *)FUN_23e914090(param_1,plVar12,plVar15);
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))();
              }
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                (**(code **)(plVar15[1] + 0x30))();
              }
              if (plVar16 == (longlong *)0x0) {
                auVar21 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcVar14 = *(code **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                pcVar19 = *(code **)(param_1 + 0x68);
                goto LAB_23c660c57;
              }
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                (**(code **)(plVar16[1] + 0x30))(plVar16);
              }
              lVar7 = *plVar11;
              *plVar11 = lVar7 + -1;
              if (lVar7 + -1 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              plVar11 = *(longlong **)(param_1 + 0x138);
              *(longlong **)(param_1 + 0x138) = plVar10;
              if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                (**(code **)(plVar11[1] + 0x30))();
              }
LAB_23c66047d:
              lVar8 = FUN_23ead6850();
              lVar7 = _DAT_23ee28db0;
              if (lVar8 == 0) {
                FUN_23e915740(param_1,auStack_b8,_DAT_23ee28cb8);
              }
              else {
                *(undefined4 *)(plVar2 + 5) = 0x65;
                plVar10 = (longlong *)
                          FUN_23e915840(param_1,lVar8,_DAT_23ee28cc0,*(undefined8 *)(lVar7 + 0x18));
                if (plVar10 != (longlong *)0x0) {
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))();
                  }
                  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                  plVar2 = *(longlong **)(lVar7 + 0x28);
                  plVar10 = (longlong *)plVar2[2];
                  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30)
                  ;
                  *(undefined4 *)(plVar2 + 8) = 0xffffffff;
                  if (plVar10 != (longlong *)0x0) {
                    plVar2[2] = 0;
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))();
                    }
                  }
                  *plVar2 = *plVar2 + -1;
                  if (*plVar2 == 0) {
                    (**(code **)(plVar2[1] + 0x30))(plVar2);
                  }
                  plVar11 = _DAT_23ee28db8;
                  plVar2[0xf] = 0;
                  *plVar11 = *plVar11 + 1;
LAB_23c66053d:
                  *plVar6 = *plVar6 + -1;
                  if (*plVar6 == 0) {
                    (**(code **)(plVar6[1] + 0x30))(plVar6);
                  }
                  lVar7 = *plStack_130;
                  *plStack_130 = lVar7 + -1;
                  if (lVar7 + -1 == 0) {
                    (**(code **)(plStack_130[1] + 0x30))(plStack_130);
                  }
                  *plVar5 = *plVar5 + -1;
                  if (*plVar5 == 0) {
                    (**(code **)(plVar5[1] + 0x30))(plVar5);
                  }
                  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  if ((plStack_108 != (longlong *)0x0) &&
                     (lVar7 = *plStack_108, *plStack_108 = lVar7 + -1, lVar7 + -1 == 0)) {
                    (**(code **)(plStack_108[1] + 0x30))(plStack_108);
                  }
                  if ((plStack_110 != (longlong *)0x0) &&
                     (lVar7 = *plStack_110, *plStack_110 = lVar7 + -1, lVar7 + -1 == 0)) {
                    (**(code **)(plStack_110[1] + 0x30))(plStack_110);
                  }
                  if ((plStack_118 != (longlong *)0x0) &&
                     (lVar7 = *plStack_118, *plStack_118 = lVar7 + -1, lVar7 + -1 == 0)) {
                    (**(code **)(plStack_118[1] + 0x30))(plStack_118);
                  }
                  if ((plStack_120 != (longlong *)0x0) &&
                     (lVar7 = *plStack_120, *plStack_120 = lVar7 + -1, lVar7 + -1 == 0)) {
                    (**(code **)(plStack_120[1] + 0x30))(plStack_120);
                  }
                  if ((plStack_d0 != (longlong *)0x0) &&
                     (*plStack_d0 = *plStack_d0 + -1, *plStack_d0 == 0)) {
                    (**(code **)(plStack_d0[1] + 0x30))(plStack_d0);
                  }
                  if (plStack_128 == (longlong *)0x0) {
                    return plVar11;
                  }
                  lVar7 = *plStack_128;
                  *plStack_128 = lVar7 + -1;
                  if (lVar7 + -1 != 0) {
                    return plVar11;
                  }
                  (**(code **)(plStack_128[1] + 0x30))(plStack_128);
                  return plVar11;
                }
                auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcStack_b0 = *(code **)(param_1 + 0x68);
                apcStack_a8[0] = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              if (apcStack_a8[0] == (code *)0x0) {
                iVar4 = 0x65;
                goto LAB_23c65fa89;
              }
              pcVar14 = apcStack_a8[0];
              if (plVar2 == *(longlong **)(apcStack_a8[0] + 0x18)) goto LAB_23c65f310;
              iVar4 = 0x65;
              goto LAB_23c65f275;
            }
            plVar18 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar18 != (longlong *)0x0) {
              *plVar18 = *plVar18 + 1;
              DAT_23ed6a4c0 = plVar18;
              goto LAB_23c660277;
            }
            PyErr_PrintEx(0);
            Py_Exit(1);
LAB_23c66137e:
            plVar10 = (longlong *)FUN_23a388650(param_1,plStack_108);
            if (plVar10 == (longlong *)0x0) goto LAB_23c661bd0;
            iVar4 = FUN_23e913250(plVar10,_DAT_23ee28d58);
            lVar7 = *plVar10;
            *plVar10 = lVar7 + -1;
            if (lVar7 + -1 == 0) {
              FUN_23a334bc0();
            }
            if (iVar4 == -1) {
LAB_23c6614e7:
              pcVar14 = *(code **)(param_1 + 0x70);
              auVar21 = *(undefined1 (*) [8])(param_1 + 0x60);
              uVar20 = 0x48;
              plStack_120 = (longlong *)0x0;
              plStack_d0 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plStack_128 = (longlong *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              pcStack_100 = _Py_NoneStruct_exref;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pcVar17 = *(code **)(param_1 + 0x68);
              goto LAB_23c65fe76;
            }
            if (iVar4 == 1) {
              plVar10 = (longlong *)FUN_23a38cc10(param_1,plStack_108);
              if (plVar10 == (longlong *)0x0) {
                pcVar14 = *(code **)(param_1 + 0x70);
                auVar21 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_d0 = (longlong *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar20 = 0x49;
                plStack_120 = (longlong *)0x0;
                plStack_110 = (longlong *)0x0;
                plStack_128 = (longlong *)0x0;
                pcStack_100 = _Py_NoneStruct_exref;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plStack_118 = (longlong *)0x0;
                pcVar17 = *(code **)(param_1 + 0x68);
                goto LAB_23c65fe76;
              }
              lVar8 = FUN_23e8c0500(plVar10,DAT_23ed6cea8);
              lVar7 = *plVar10;
              *plVar10 = lVar7 + -1;
              if (lVar7 + -1 == 0) {
                FUN_23a334bc0(plVar10);
              }
              if (lVar8 == 0) {
                pcVar14 = *(code **)(param_1 + 0x70);
                auVar21 = *(undefined1 (*) [8])(param_1 + 0x60);
                *(undefined8 *)(param_1 + 0x70) = 0;
                plStack_d0 = (longlong *)0x0;
                uVar20 = 0x49;
                pcStack_100 = _Py_NoneStruct_exref;
                plStack_128 = (longlong *)0x0;
                plStack_120 = (longlong *)0x0;
                plStack_118 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plStack_110 = (longlong *)0x0;
                pcVar17 = *(code **)(param_1 + 0x68);
                goto LAB_23c65fe76;
              }
              FUN_23e8ba4b0(plVar5,lVar8);
            }
LAB_23c65ed2a:
            FUN_23e8bc550(plVar5);
            plStack_110 = (longlong *)PySet_New(0);
            plVar10 = (longlong *)FUN_23ebf7180();
            if (plVar10 == (longlong *)0x0) {
              pcVar14 = *(code **)(param_1 + 0x70);
              auVar21 = *(undefined1 (*) [8])(param_1 + 0x60);
              *(undefined8 *)(param_1 + 0x70) = 0;
              plStack_d0 = (longlong *)0x0;
              uVar20 = 0x4e;
              plStack_128 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              plStack_118 = (longlong *)0x0;
              pcStack_100 = _Py_NoneStruct_exref;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pcVar17 = *(code **)(param_1 + 0x68);
            }
            else {
              plStack_128 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              plVar11 = (longlong *)0x0;
              plVar15 = (longlong *)0x0;
              do {
                do {
                  plStack_118 = (longlong *)(**(code **)(plVar10[1] + 0xe0))(plVar10);
                  if (plStack_118 == (longlong *)0x0) {
                    cVar3 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
                    plStack_d0 = plVar15;
                    plStack_118 = plVar11;
                    if (cVar3 == '\0') {
                      pcVar14 = *(code **)(param_1 + 0x70);
                      auVar21 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pcVar17 = *(code **)(param_1 + 0x68);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar20 = 0x4e;
                      apcStack_a8[0] = (code *)0x0;
                      pcStack_100 = _Py_NoneStruct_exref;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      _auStack_b8 = (undefined1  [16])0x0;
                      if (plVar11 == (longlong *)0x0) goto LAB_23c6617ad;
                      goto LAB_23c66176e;
                    }
                    if ((plVar11 != (longlong *)0x0) &&
                       (lVar7 = *plVar11, *plVar11 = lVar7 + -1, lVar7 + -1 == 0)) {
                      FUN_23a334bc0(plVar11);
                    }
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      FUN_23a334bc0(plVar10);
                    }
                    goto LAB_23c66047d;
                  }
                  if (plVar11 == (longlong *)0x0) {
                    *plStack_118 = *plStack_118 + 1;
                  }
                  else {
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      FUN_23a334bc0(plVar11);
                    }
                    *plStack_118 = *plStack_118 + 1;
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      FUN_23a334bc0(plVar11);
                    }
                  }
                  if (plStack_110 == (longlong *)0x0) {
                    FUN_23e8ba2b0(auStack_b8,_DAT_23ee28d70);
                    pcStack_100 = _Py_NoneStruct_exref;
                    if ((auStack_b8 != (undefined1  [8])_Py_NoneStruct_exref) &&
                       (auStack_b8 != (undefined1  [8])0x0)) {
                      FUN_23e91b1b0(param_1,auStack_b8,auStack_b8 + 8,apcStack_a8);
                    }
                    FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_b0);
LAB_23c6619d0:
                    uVar20 = 0x4f;
                    plStack_d8 = plStack_120;
                    goto LAB_23c66172f;
                  }
                  iVar4 = PySet_Contains(plStack_110,plStack_118);
                  if (iVar4 == -1) {
                    apcStack_a8[0] = *(code **)(param_1 + 0x70);
                    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcStack_b0 = *(code **)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    pcStack_100 = _Py_NoneStruct_exref;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23c6619d0;
                  }
                  plVar11 = plStack_118;
                } while (iVar4 == 1);
                *(undefined4 *)(plVar2 + 5) = 0x51;
                plVar12 = (longlong *)FUN_23e915840(param_1,plStack_110,_DAT_23ee28d78,plStack_118);
                pcStack_100 = _Py_NoneStruct_exref;
                if (plVar12 == (longlong *)0x0) {
                  apcStack_a8[0] = *(code **)(param_1 + 0x70);
                  auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_b0 = *(code **)(param_1 + 0x68);
                  uVar20 = 0x51;
                  plStack_d8 = plStack_120;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23c66172f;
                }
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  FUN_23a334bc0(plVar12);
                }
                uVar13 = FUN_23e9373d0();
                *(undefined4 *)(plVar2 + 5) = 0x53;
                plStack_d8 = (longlong *)
                             FUN_23e915840(param_1,uVar13,_DAT_23ee28d10,
                                           *(undefined8 *)(_DAT_23ee28d80 + 0x18));
                pcStack_100 = _Py_NoneStruct_exref;
                if (plStack_d8 == (longlong *)0x0) {
                  apcStack_a8[0] = *(code **)(param_1 + 0x70);
                  auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_b0 = *(code **)(param_1 + 0x68);
                  uVar20 = 0x53;
                  plStack_d8 = plStack_120;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23c66172f;
                }
                if ((plStack_120 != (longlong *)0x0) &&
                   (lVar7 = *plStack_120, *plStack_120 = lVar7 + -1, lVar7 + -1 == 0)) {
                  FUN_23a334bc0(plStack_120);
                }
                pcVar14 = DAT_23ed6ccf0;
                uVar13 = FUN_23e9373d0();
                *(undefined4 *)(plVar2 + 5) = 0x58;
                plVar12 = (longlong *)FUN_23e915840(param_1,uVar13,_DAT_23ee28d90,plStack_d8);
                pcStack_100 = _Py_NoneStruct_exref;
                pcVar17 = DAT_23ed6ccf0;
                if (plVar12 == (longlong *)0x0) {
                  apcStack_a8[0] = *(code **)(param_1 + 0x70);
                  auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_b0 = *(code **)(param_1 + 0x68);
                  uVar20 = 0x58;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23c66172f;
                }
                *(undefined4 *)(plVar2 + 5) = 0x54;
                pcStack_88 = pcVar14;
                pcStack_78 = pcStack_100;
                pcStack_70 = pcStack_100;
                pcStack_68 = pcStack_100;
                auStack_98._8_8_ = pcStack_100;
                auStack_98._0_8_ = plStack_118;
                pcStack_60 = pcVar17;
                plStack_80 = plVar12;
                plStack_d0 = (longlong *)FUN_23e96bf90(param_1,plStack_130);
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  FUN_23a334bc0(plVar12);
                }
                if (plStack_d0 == (longlong *)0x0) {
                  auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_b0 = *(code **)(param_1 + 0x68);
                  apcStack_a8[0] = *(code **)(param_1 + 0x70);
                  uVar20 = 0x54;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23c66172f;
                }
                if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                  FUN_23a334bc0(plVar15);
                }
                iVar4 = FUN_23a35f020();
                plVar15 = plStack_d0;
                if (iVar4 == -1) {
                  auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_b0 = *(code **)(param_1 + 0x68);
                  apcStack_a8[0] = *(code **)(param_1 + 0x70);
                  uVar20 = 0x5e;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23c66172f;
                }
                plStack_120 = plStack_d8;
                if (iVar4 != 0) {
                  plVar12 = (longlong *)FUN_23e8bc2f0(plStack_d8);
                  if (plVar12 != (longlong *)0x0) {
                    plVar16 = (longlong *)PyNumber_Long(plVar12);
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      FUN_23a334bc0(plVar12);
                    }
                    if (plVar16 != (longlong *)0x0) {
                      if ((plStack_128 != (longlong *)0x0) &&
                         (*plStack_128 = *plStack_128 + -1, *plStack_128 == 0)) {
                        FUN_23a334bc0(plStack_128);
                      }
                      iVar4 = FUN_23a35f020(plVar16);
                      plStack_128 = plVar16;
                      if (iVar4 == -1) {
                        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_b0 = *(code **)(param_1 + 0x68);
                        apcStack_a8[0] = *(code **)(param_1 + 0x70);
                        uVar20 = 0x60;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23c66172f;
                      }
                      if (iVar4 == 0) goto LAB_23c65ef4a;
                      plVar11 = (longlong *)FUN_23e94f9d0(param_1,plVar16,_DAT_23ee28da0);
                      if (plVar11 == (longlong *)0x0) {
                        apcStack_a8[0] = *(code **)(param_1 + 0x70);
                        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_b0 = *(code **)(param_1 + 0x68);
                        uVar20 = 0x61;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23c66172f;
                      }
                      lVar7 = *plStack_118;
                      *plStack_118 = lVar7 + -1;
                      if (lVar7 + -1 == 0) {
                        FUN_23a334bc0();
                      }
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        FUN_23a334bc0(plVar10);
                      }
                      FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                      goto LAB_23c66053d;
                    }
                  }
                  auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_b0 = *(code **)(param_1 + 0x68);
                  apcStack_a8[0] = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar20 = 0x5f;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23c66172f;
                }
LAB_23c65ef4a:
                cVar3 = FUN_23a3a5fe0(param_1);
              } while (cVar3 != '\0');
              auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
              pcStack_b0 = *(code **)(param_1 + 0x68);
              apcStack_a8[0] = *(code **)(param_1 + 0x70);
              uVar20 = 0x4e;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23c66172f:
              plStack_120 = plStack_d8;
              pcVar14 = apcStack_a8[0];
              auVar21 = auStack_b8;
              pcVar17 = pcStack_b0;
              plStack_d0 = plVar15;
LAB_23c66176e:
              apcStack_a8[0] = (code *)0x0;
              _auStack_b8 = (undefined1  [16])0x0;
              lVar7 = *plStack_118;
              *plStack_118 = lVar7 + -1;
              if (lVar7 + -1 == 0) {
                FUN_23a334bc0();
              }
LAB_23c6617ad:
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                FUN_23a334bc0(plVar10);
              }
            }
            goto LAB_23c65fe76;
          }
          auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_b0 = *(code **)(param_1 + 0x68);
          apcStack_a8[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (apcStack_a8[0] != (code *)0x0) {
            if (plVar2 == *(longlong **)(apcStack_a8[0] + 0x18)) goto LAB_23c65f5bb;
            plStack_128 = (longlong *)0x0;
            plStack_d0 = (longlong *)0x0;
            plVar5 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            iVar4 = 0x3e;
            plStack_118 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            pcVar22 = _PyRuntime_exref;
            goto LAB_23c65f275;
          }
        }
        plStack_128 = (longlong *)0x0;
        plStack_d0 = (longlong *)0x0;
        plVar5 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        iVar4 = 0x3e;
        plStack_118 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        pcVar22 = _PyRuntime_exref;
        goto LAB_23c65fa89;
      }
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_b0 = *(code **)(param_1 + 0x68);
      apcStack_a8[0] = *(code **)(param_1 + 0x70);
      iVar4 = 0x36;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23c65f1e6:
      *plVar5 = *plVar5 + -1;
      if (*plVar5 == 0) {
        (**(code **)(plVar5[1] + 0x30))();
        if (apcStack_a8[0] == (code *)0x0) {
LAB_23c65fa38:
          plStack_128 = (longlong *)0x0;
          plStack_d0 = (longlong *)0x0;
          plVar5 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          pcVar22 = _PyRuntime_exref;
          goto LAB_23c65fa89;
        }
        plVar5 = *(longlong **)(apcStack_a8[0] + 0x18);
      }
      else {
        if (apcStack_a8[0] == (code *)0x0) goto LAB_23c65fa38;
        plVar5 = *(longlong **)(apcStack_a8[0] + 0x18);
      }
      if (plVar2 == plVar5) {
LAB_23c65f5bb:
        plStack_128 = (longlong *)0x0;
        plStack_d0 = (longlong *)0x0;
        plVar5 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        pcVar14 = apcStack_a8[0];
        goto LAB_23c65f310;
      }
      plStack_128 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x0;
      plVar5 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      pcVar22 = _PyRuntime_exref;
    }
LAB_23c65f275:
    pcVar17 = apcStack_a8[0];
    pcVar14 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar14 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar19 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar19;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar14 + 0x18) = plVar2;
    *plVar2 = *plVar2 + 1;
    lVar7 = *(longlong *)(pcVar22 + 0x1f8);
    *(int *)(pcVar14 + 0x24) = iVar4;
    lVar7 = *(longlong *)(lVar7 + 0x10);
    *(undefined4 *)(pcVar14 + 0x20) = 0xffffffff;
    lVar7 = *(longlong *)(lVar7 + 0x2e8);
    lVar8 = *(longlong *)(pcVar14 + -8);
    plVar10 = *(longlong **)(lVar7 + 8);
    *plVar10 = (longlong)(pcVar14 + -0x10);
    *(longlong *)(pcVar14 + -0x10) = lVar7;
    *(ulonglong *)(pcVar14 + -8) = (ulonglong)((uint)lVar8 & 3) | (ulonglong)plVar10;
    *(code **)(lVar7 + 8) = pcVar14 + -0x10;
    *(code **)(pcVar14 + 0x10) = pcVar17;
    *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
    pcVar17 = apcStack_a8[0];
  }
  if ((pcVar17 != (code *)0x0) &&
     (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1, *(longlong *)pcVar17 == 0)) {
    (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))();
  }
LAB_23c65f310:
  apcStack_a8[0] = pcVar14;
  FUN_23e8bba40(plVar2,"ooooooooooo",plVar6,plStack_130,plVar5,plVar9,plStack_108,plStack_110,
                plStack_118,plStack_120,plStack_d0,plStack_128,0);
  if (_DAT_23ee29d88 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    _DAT_23ee29d88 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar2 = *(longlong **)(lVar7 + 0x28);
  plVar10 = (longlong *)plVar2[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
  *(undefined4 *)(plVar2 + 8) = 0xffffffff;
  if (plVar10 != (longlong *)0x0) {
    plVar2[2] = 0;
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))();
    }
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  pcVar14 = apcStack_a8[0];
  pcVar22 = pcStack_b0;
  auVar21 = auStack_b8;
  plVar2[0xf] = 0;
  _auStack_b8 = (undefined1  [16])0x0;
  apcStack_a8[0] = (code *)0x0;
  if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  if ((plStack_130 != (longlong *)0x0) &&
     (lVar7 = *plStack_130, *plStack_130 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_130[1] + 0x30))(plStack_130);
  }
  if ((plVar5 != (longlong *)0x0) && (*plVar5 = *plVar5 + -1, *plVar5 == 0)) {
    (**(code **)(plVar5[1] + 0x30))(plVar5);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((plStack_108 != (longlong *)0x0) &&
     (lVar7 = *plStack_108, *plStack_108 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_108[1] + 0x30))(plStack_108);
  }
  if ((plStack_110 != (longlong *)0x0) &&
     (lVar7 = *plStack_110, *plStack_110 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_110[1] + 0x30))(plStack_110);
  }
  if ((plStack_118 != (longlong *)0x0) &&
     (lVar7 = *plStack_118, *plStack_118 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_118[1] + 0x30))(plStack_118);
  }
  if ((plStack_120 != (longlong *)0x0) &&
     (lVar7 = *plStack_120, *plStack_120 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_120[1] + 0x30))(plStack_120);
  }
  if ((plStack_d0 != (longlong *)0x0) && (*plStack_d0 = *plStack_d0 + -1, *plStack_d0 == 0)) {
    (**(code **)(plStack_d0[1] + 0x30))(plStack_d0);
  }
  if ((plStack_128 != (longlong *)0x0) &&
     (lVar7 = *plStack_128, *plStack_128 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_128[1] + 0x30))(plStack_128);
  }
  _auStack_b8 = CONCAT88(pcVar22,auVar21);
  apcStack_a8[0] = pcVar14;
  FUN_23a33aa70(param_1,auVar21,pcVar22,pcVar14);
  return (longlong *)0x0;
LAB_23c661bd0:
  pcVar14 = *(code **)(param_1 + 0x70);
  auVar21 = *(undefined1 (*) [8])(param_1 + 0x60);
  plStack_d0 = (longlong *)0x0;
  uVar20 = 0x48;
  *(undefined8 *)(param_1 + 0x70) = 0;
  plStack_128 = (longlong *)0x0;
  plStack_120 = (longlong *)0x0;
  plStack_118 = (longlong *)0x0;
  pcStack_100 = _Py_NoneStruct_exref;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plStack_110 = (longlong *)0x0;
  pcVar17 = *(code **)(param_1 + 0x68);
  goto LAB_23c65fe76;
}
