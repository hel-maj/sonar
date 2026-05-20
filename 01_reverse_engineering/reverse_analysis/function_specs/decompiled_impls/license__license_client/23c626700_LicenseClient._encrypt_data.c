/* ===== 23c626700 license.license_client:97 ===== */
/* ghidra_name=FUN_23c626700 entry=23c626700 size=14569 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

code * FUN_23c626700(longlong param_1,undefined8 param_2,undefined8 *param_3,int param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  code *pcVar12;
  longlong **pplVar13;
  longlong **pplVar14;
  longlong *plVar15;
  longlong lVar16;
  longlong **pplVar17;
  longlong **pplVar18;
  undefined1 auVar19 [8];
  uint uVar20;
  longlong *plVar21;
  undefined8 *puVar22;
  longlong *unaff_R14;
  longlong *plStack_160;
  longlong *plStack_158;
  longlong *plStack_150;
  undefined1 auStack_118 [16];
  longlong **applStack_108 [2];
  code *pcStack_f8;
  longlong **pplStack_f0;
  longlong **pplStack_e8;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  longlong *plStack_c8;
  undefined1 auStack_b8 [8];
  longlong **pplStack_b0;
  longlong **applStack_a8 [2];
  longlong *plStack_98;
  longlong lStack_90;
  longlong **pplStack_88;
  longlong **pplStack_80;
  undefined8 uStack_78;
  
  plVar7 = _DAT_23ee29cc0;
  plVar1 = (longlong *)*param_3;
  applStack_a8[0] = (longlong **)0x0;
  auStack_b8 = (undefined1  [8])0x0;
  pplStack_b0 = (longlong **)0x0;
  if (_DAT_23ee29cc0 == (longlong *)0x0) {
LAB_23c626765:
    param_4 = 0x38;
    _DAT_23ee29cc0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23ee29cb8,DAT_23ee29d18);
  }
  else {
    lVar6 = *_DAT_23ee29cc0;
    if (1 < lVar6) {
      *_DAT_23ee29cc0 = lVar6 + -1;
      goto LAB_23c626765;
    }
    if (_DAT_23ee29cc0[2] != 0) {
      *_DAT_23ee29cc0 = lVar6 + -1;
      if (lVar6 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23c626765;
    }
  }
  plVar2 = _DAT_23ee29cc0;
  lVar6 = *(longlong *)(param_1 + 0x38);
  plVar7 = _DAT_23ee29cc0 + 9;
  lVar16 = *(longlong *)(lVar6 + 8);
  _DAT_23ee29cc0[0xf] = lVar16;
  *(longlong **)(lVar6 + 8) = plVar7;
  if ((lVar16 != 0) &&
     (((*(char *)(lVar16 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar16 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar16 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar16 + 0x38))) && (plVar2[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar16 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  *(undefined4 *)(plVar2 + 8) = 0;
  lVar6 = FUN_23ead5f40();
  if (lVar6 == 0) {
    FUN_23e915740(param_1,auStack_b8,DAT_23ee283f8);
LAB_23c626fc5:
    puVar22 = (undefined8 *)0x64;
LAB_23c626fcb:
    plStack_160 = (longlong *)0x0;
    unaff_R14 = (longlong *)0x0;
    plVar7 = (longlong *)0x0;
    plStack_158 = (longlong *)0x0;
    pplVar18 = (longlong **)_Py_NoneStruct_exref;
  }
  else {
    plVar7 = (longlong *)FUN_23e8bc2f0(lVar6,DAT_23ee28400);
    plVar8 = _DAT_23ee284d8;
    if (plVar7 == (longlong *)0x0) {
LAB_23c627c30:
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23c626fc5;
    }
    lVar6 = *(longlong *)(param_1 + 0x10);
    pplVar18 = *(longlong ***)(lVar6 + 0xe20);
    if (pplVar18 == (longlong **)0x0) {
      pplVar18 = (longlong **)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      plVar9 = pplVar18[3];
      *(int *)(lVar6 + 0xebc) = *(int *)(lVar6 + 0xebc) + -1;
      *(longlong **)(lVar6 + 0xe20) = plVar9;
      *pplVar18 = (longlong *)0x1;
    }
    pcVar12 = _PyRuntime_exref;
    pplVar18[4] = (longlong *)0x0;
    plVar9 = *(longlong **)(*(longlong *)(*(longlong *)(pcVar12 + 0x1f8) + 0x10) + 0x2e8);
    plVar10 = pplVar18[-1];
    puVar22 = (undefined8 *)plVar9[1];
    *puVar22 = pplVar18 + -2;
    pplVar18[-2] = plVar9;
    pplVar18[-1] = (longlong *)((ulonglong)((uint)plVar10 & 3) | (ulonglong)puVar22);
    plVar9[1] = (longlong)(pplVar18 + -2);
    uVar3 = DAT_23ee28358;
    *plVar8 = *plVar8 + 1;
    pplVar18[3] = plVar8;
    plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar3);
    lVar6 = DAT_23ed6cd28;
    if (plVar8 == (longlong *)0x0) {
LAB_23c626f80:
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))();
      }
      *pplVar18 = (longlong *)((longlong)*pplVar18 + -1);
      if (*pplVar18 == (longlong *)0x0) {
        (*(code *)pplVar18[1][6])();
      }
      goto LAB_23c626fc5;
    }
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar9 == (longlong *)0x0) goto LAB_23c628580;
      *plVar9 = *plVar9 + 1;
      DAT_23ed6a4c0 = plVar9;
    }
    lStack_90 = lVar6;
    plStack_98 = plVar8;
    unaff_R14 = (longlong *)FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))();
    }
    if (unaff_R14 == (longlong *)0x0) goto LAB_23c626f80;
    pplVar18[4] = unaff_R14;
    plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,pplVar18);
    *pplVar18 = (longlong *)((longlong)*pplVar18 + -1);
    if (*pplVar18 == (longlong *)0x0) {
      (*(code *)pplVar18[1][6])();
    }
    if (plVar8 == (longlong *)0x0) {
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))();
      }
      goto LAB_23c626fc5;
    }
    *(undefined4 *)(plVar2 + 5) = 100;
    plVar9 = (longlong *)FUN_23e914090(param_1,plVar7,plVar8);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))();
    }
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))();
    }
    if (plVar9 == (longlong *)0x0) goto LAB_23c627c30;
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    lVar6 = FUN_23ead5f40();
    if (lVar6 == 0) {
      FUN_23e915740(param_1,auStack_b8,DAT_23ee283f8);
      goto LAB_23c62837b;
    }
    plVar7 = (longlong *)FUN_23e8bc2f0(lVar6,DAT_23ee28400);
    plVar8 = _DAT_23ee284e0;
    if (plVar7 == (longlong *)0x0) {
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
      plStack_160 = (longlong *)0x0;
      unaff_R14 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pplVar18 = (longlong **)_Py_NoneStruct_exref;
      puVar22 = (undefined8 *)0x65;
      plStack_158 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23c626fea;
    }
    lVar6 = *(longlong *)(param_1 + 0x10);
    pplVar18 = *(longlong ***)(lVar6 + 0xe20);
    if (pplVar18 == (longlong **)0x0) {
      pplVar18 = (longlong **)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      plVar9 = pplVar18[3];
      *(int *)(lVar6 + 0xebc) = *(int *)(lVar6 + 0xebc) + -1;
      *(longlong **)(lVar6 + 0xe20) = plVar9;
      *pplVar18 = (longlong *)0x1;
    }
    pplVar18[4] = (longlong *)0x0;
    plVar9 = *(longlong **)(*(longlong *)(*(longlong *)(pcVar12 + 0x1f8) + 0x10) + 0x2e8);
    plVar10 = pplVar18[-1];
    puVar22 = (undefined8 *)plVar9[1];
    *puVar22 = pplVar18 + -2;
    pplVar18[-2] = plVar9;
    pplVar18[-1] = (longlong *)((ulonglong)((uint)plVar10 & 3) | (ulonglong)puVar22);
    plVar9[1] = (longlong)(pplVar18 + -2);
    uVar3 = _DAT_23ee28348;
    *plVar8 = *plVar8 + 1;
    pplVar18[3] = plVar8;
    plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar3);
    lVar6 = DAT_23ed6cd28;
    if (plVar8 == (longlong *)0x0) {
LAB_23c628330:
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))();
      }
      *pplVar18 = (longlong *)((longlong)*pplVar18 + -1);
      if (*pplVar18 == (longlong *)0x0) {
        (*(code *)pplVar18[1][6])();
      }
LAB_23c62837b:
      puVar22 = (undefined8 *)0x65;
      goto LAB_23c626fcb;
    }
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar9 == (longlong *)0x0) goto LAB_23c628580;
      *plVar9 = *plVar9 + 1;
      DAT_23ed6a4c0 = plVar9;
    }
    lStack_90 = lVar6;
    plStack_98 = plVar8;
    plVar9 = (longlong *)FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))();
    }
    if (plVar9 == (longlong *)0x0) goto LAB_23c628330;
    pplVar18[4] = plVar9;
    plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,pplVar18);
    *pplVar18 = (longlong *)((longlong)*pplVar18 + -1);
    if (*pplVar18 == (longlong *)0x0) {
      (*(code *)pplVar18[1][6])();
    }
    if (plVar8 == (longlong *)0x0) {
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))();
      }
      goto LAB_23c62837b;
    }
    *(undefined4 *)(plVar2 + 5) = 0x65;
    plVar9 = (longlong *)FUN_23e914090(param_1,plVar7,plVar8);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))();
    }
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))();
    }
    if (plVar9 == (longlong *)0x0) {
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23c62837b;
    }
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    lVar6 = FUN_23ead5f40();
    if (lVar6 == 0) {
      FUN_23e915740(param_1,auStack_b8,DAT_23ee283f8);
      goto LAB_23c628832;
    }
    plVar7 = (longlong *)FUN_23e8bc2f0(lVar6,DAT_23ee28400);
    plVar8 = _DAT_23ee284e8;
    if (plVar7 == (longlong *)0x0) {
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
      plStack_160 = (longlong *)0x0;
      unaff_R14 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pplVar18 = (longlong **)_Py_NoneStruct_exref;
      puVar22 = (undefined8 *)0x66;
      plStack_158 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23c626fea;
    }
    lVar6 = *(longlong *)(param_1 + 0x10);
    pplVar18 = *(longlong ***)(lVar6 + 0xe20);
    if (pplVar18 == (longlong **)0x0) {
      pplVar18 = (longlong **)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      plVar9 = pplVar18[3];
      *(int *)(lVar6 + 0xebc) = *(int *)(lVar6 + 0xebc) + -1;
      *(longlong **)(lVar6 + 0xe20) = plVar9;
      *pplVar18 = (longlong *)0x1;
    }
    pplVar18[4] = (longlong *)0x0;
    plVar9 = *(longlong **)(*(longlong *)(*(longlong *)(pcVar12 + 0x1f8) + 0x10) + 0x2e8);
    plVar10 = pplVar18[-1];
    puVar22 = (undefined8 *)plVar9[1];
    *puVar22 = pplVar18 + -2;
    pplVar18[-2] = plVar9;
    pplVar18[-1] = (longlong *)((ulonglong)((uint)plVar10 & 3) | (ulonglong)puVar22);
    plVar9[1] = (longlong)(pplVar18 + -2);
    uVar3 = DAT_23ee28358;
    *plVar8 = *plVar8 + 1;
    pplVar18[3] = plVar8;
    plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar3);
    if (plVar8 == (longlong *)0x0) {
LAB_23c6287e7:
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))();
      }
      *pplVar18 = (longlong *)((longlong)*pplVar18 + -1);
      if (*pplVar18 == (longlong *)0x0) {
        (*(code *)pplVar18[1][6])();
      }
LAB_23c628832:
      puVar22 = (undefined8 *)0x66;
      goto LAB_23c626fcb;
    }
    *(undefined4 *)(plVar2 + 5) = 0x66;
    unaff_R14 = (longlong *)FUN_23e91bfe0(param_1,plVar8,DAT_23ed6cee0);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))();
    }
    lVar6 = DAT_23ed6cd28;
    if (unaff_R14 == (longlong *)0x0) goto LAB_23c6287e7;
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar8 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar8 == (longlong *)0x0) goto LAB_23c628580;
      *plVar8 = *plVar8 + 1;
      DAT_23ed6a4c0 = plVar8;
    }
    lStack_90 = lVar6;
    plStack_98 = unaff_R14;
    plVar8 = (longlong *)FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
    *unaff_R14 = *unaff_R14 + -1;
    if (*unaff_R14 == 0) {
      (**(code **)(unaff_R14[1] + 0x30))();
    }
    if (plVar8 == (longlong *)0x0) goto LAB_23c6287e7;
    pplVar18[4] = plVar8;
    plVar8 = (longlong *)PyUnicode_Join();
    *pplVar18 = (longlong *)((longlong)*pplVar18 + -1);
    if (*pplVar18 == (longlong *)0x0) {
      (*(code *)pplVar18[1][6])();
    }
    if (plVar8 == (longlong *)0x0) {
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        FUN_23a334bc0();
      }
      goto LAB_23c628832;
    }
    *(undefined4 *)(plVar2 + 5) = 0x66;
    plVar9 = (longlong *)FUN_23e914090(param_1,plVar7,plVar8);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      FUN_23a334bc0();
    }
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      FUN_23a334bc0();
    }
    if (plVar9 == (longlong *)0x0) {
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23c628832;
    }
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      FUN_23a334bc0(plVar9);
    }
    lVar6 = FUN_23ead5f40();
    if (lVar6 == 0) {
      FUN_23e915740(param_1,auStack_b8,DAT_23ee283f8);
      goto LAB_23c6289a7;
    }
    plVar8 = (longlong *)FUN_23e8bc2f0(lVar6,DAT_23ee28400);
    pplVar18 = (longlong **)_Py_NoneStruct_exref;
    plVar7 = _DAT_23ee284f0;
    if (plVar8 == (longlong *)0x0) {
      applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      unaff_R14 = (longlong *)0x0;
      puVar22 = (undefined8 *)0x67;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_160 = (longlong *)0x0;
      plStack_158 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar7 = (longlong *)0x0;
      goto LAB_23c626fea;
    }
    plVar9 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
    *plVar7 = *plVar7 + 1;
    uVar3 = DAT_23ee28358;
    plVar9[3] = (longlong)plVar7;
    plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,uVar3);
    if (plVar7 == (longlong *)0x0) {
LAB_23c628963:
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        FUN_23a334bc0();
      }
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        FUN_23a334bc0();
      }
LAB_23c6289a7:
      puVar22 = (undefined8 *)0x67;
      goto LAB_23c626fcb;
    }
    *(undefined4 *)(plVar2 + 5) = 0x67;
    plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar7,_DAT_23ee284f8);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      FUN_23a334bc0();
    }
    if (plVar10 == (longlong *)0x0) goto LAB_23c628963;
    lVar6 = FUN_23e94f9d0(param_1,plVar10,DAT_23ed6cd28);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      FUN_23a334bc0();
    }
    if (lVar6 == 0) goto LAB_23c628963;
    plVar9[4] = lVar6;
    plVar7 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar9);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      FUN_23a334bc0();
    }
    if (plVar7 == (longlong *)0x0) {
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        FUN_23a334bc0();
      }
      goto LAB_23c6289a7;
    }
    *(undefined4 *)(plVar2 + 5) = 0x67;
    plVar9 = (longlong *)FUN_23e914090(param_1,plVar8,plVar7);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      FUN_23a334bc0();
    }
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      FUN_23a334bc0();
    }
    if (plVar9 == (longlong *)0x0) {
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23c6289a7;
    }
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      FUN_23a334bc0(plVar9);
    }
    plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee28358);
    if (plVar7 == (longlong *)0x0) {
LAB_23c628a81:
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
      puVar22 = (undefined8 *)0x69;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23c626fcb;
    }
    *(undefined4 *)(plVar2 + 5) = 0x69;
    plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar7,DAT_23ed6cee0);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      FUN_23a334bc0();
    }
    if (plVar8 == (longlong *)0x0) {
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pplVar18 = (longlong **)_Py_NoneStruct_exref;
      unaff_R14 = (longlong *)0x0;
      puVar22 = (undefined8 *)0x69;
      plStack_160 = (longlong *)0x0;
      plStack_158 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar7 = (longlong *)0x0;
      goto LAB_23c626fea;
    }
    iVar5 = FUN_23a35f020();
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      FUN_23a334bc0();
    }
    if (iVar5 == -1) goto LAB_23c628a81;
    if (iVar5 == 0) {
      lVar6 = FUN_23ead5f40();
      if (lVar6 == 0) {
        FUN_23e915740(param_1,auStack_b8,DAT_23ee283f8);
      }
      else {
        *(undefined4 *)(plVar2 + 5) = 0x6a;
        plVar7 = (longlong *)FUN_23e915840(param_1,lVar6);
        if (plVar7 != (longlong *)0x0) {
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            FUN_23a334bc0();
          }
          pcVar12 = _Py_FalseStruct_exref;
          pplVar18 = (longlong **)0x0;
          plStack_160 = (longlong *)0x0;
          unaff_R14 = (longlong *)0x0;
          plVar7 = (longlong *)0x0;
          *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
          plStack_158 = (longlong *)0x0;
          goto LAB_23c62775c;
        }
        applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pplStack_b0 = *(longlong ***)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      plVar7 = (longlong *)0x0;
      unaff_R14 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      puVar22 = (undefined8 *)0x6a;
      plStack_158 = (longlong *)0x0;
      pplVar18 = (longlong **)_Py_NoneStruct_exref;
      goto LAB_23c626fea;
    }
    lVar6 = FUN_23ead5f40();
    if (lVar6 == 0) {
      FUN_23e915740(param_1,auStack_b8,DAT_23ee283f8);
      goto LAB_23c629fe3;
    }
    plVar8 = (longlong *)FUN_23e8bc2f0();
    pplVar18 = (longlong **)_Py_NoneStruct_exref;
    plVar7 = _DAT_23ee28508;
    if (plVar8 == (longlong *)0x0) {
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
      unaff_R14 = (longlong *)0x0;
      plStack_158 = (longlong *)0x0;
      puVar22 = (undefined8 *)0x6d;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_160 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar7 = (longlong *)0x0;
      goto LAB_23c626fea;
    }
    plVar9 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
    *plVar7 = *plVar7 + 1;
    uVar3 = DAT_23ee28358;
    plVar9[3] = (longlong)plVar7;
    plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,uVar3);
    if (plVar7 == (longlong *)0x0) {
LAB_23c62a026:
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        FUN_23a334bc0();
      }
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        FUN_23a334bc0();
      }
LAB_23c629fe3:
      puVar22 = (undefined8 *)0x6d;
      goto LAB_23c626fcb;
    }
    lVar6 = FUN_23e94f9d0(param_1,plVar7,DAT_23ed6cd28);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      FUN_23a334bc0();
    }
    if (lVar6 == 0) goto LAB_23c62a026;
    plVar9[4] = lVar6;
    plVar7 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar9);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      FUN_23a334bc0();
    }
    if (plVar7 == (longlong *)0x0) {
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        FUN_23a334bc0();
      }
      goto LAB_23c629fe3;
    }
    *(undefined4 *)(plVar2 + 5) = 0x6d;
    plVar9 = (longlong *)FUN_23e914090(param_1,plVar8);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      FUN_23a334bc0();
    }
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      FUN_23a334bc0();
    }
    if (plVar9 == (longlong *)0x0) {
      applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23c629fe3;
    }
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      FUN_23a334bc0(plVar9);
    }
    plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee28358);
    if (plVar7 == (longlong *)0x0) {
LAB_23c629f8e:
      auVar19 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplVar13 = *(longlong ***)(param_1 + 0x68);
      pplVar14 = *(longlong ***)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      puVar22 = (undefined8 *)0x6f;
      plVar7 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_158 = (longlong *)0x0;
LAB_23c629ae3:
      plStack_160 = (longlong *)0x0;
      unaff_R14 = (longlong *)0x0;
      pplVar18 = (longlong **)_Py_NoneStruct_exref;
      applStack_a8[0] = pplVar14;
      auStack_b8 = auVar19;
      pplStack_b0 = pplVar13;
    }
    else {
      plVar8 = (longlong *)FUN_23e91c870(param_1,plVar7);
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        FUN_23a334bc0();
      }
      if (plVar8 == (longlong *)0x0) goto LAB_23c629f8e;
      plVar9 = (longlong *)FUN_23e8d9880(plVar8,DAT_23ed6cd90);
      if (plVar9 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pplStack_b0 = *(longlong ***)(param_1 + 0x68);
        applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
        plVar10 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar7 = (longlong *)0x0;
        puVar22 = (undefined8 *)0x6f;
        plStack_158 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar9 = (longlong *)0x0;
LAB_23c629a67:
        pplVar14 = applStack_a8[0];
        pplVar13 = pplStack_b0;
        auVar19 = auStack_b8;
        auStack_b8 = (undefined1  [8])0x0;
        pplStack_b0 = (longlong **)0x0;
        applStack_a8[0] = (longlong **)0x0;
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          FUN_23a334bc0();
        }
        if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
          FUN_23a334bc0();
        }
        plVar7 = plVar9;
        if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
          FUN_23a334bc0();
        }
        goto LAB_23c629ae3;
      }
      *(undefined4 *)(plVar2 + 5) = 0x6f;
      plVar7 = (longlong *)FUN_23e91a870(param_1,plVar9);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        FUN_23a334bc0();
      }
      if (plVar7 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pplStack_b0 = *(longlong ***)(param_1 + 0x68);
        applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
        plStack_158 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        puVar22 = (undefined8 *)0x6f;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23c629a67;
      }
      plVar10 = (longlong *)FUN_23e8d9880(plVar8,DAT_23ed6cd98);
      if (plVar10 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pplStack_b0 = *(longlong ***)(param_1 + 0x68);
        applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
        plVar9 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        puVar22 = (undefined8 *)0x6f;
        plStack_158 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23c629a67;
      }
      *plVar7 = *plVar7 + 1;
      uVar3 = DAT_23ed6ce70;
      *(undefined4 *)(plVar2 + 5) = 0x70;
      plStack_158 = (longlong *)FUN_23e91bfe0(param_1,plVar7,uVar3);
      plVar9 = plVar7;
      if (plStack_158 == (longlong *)0x0) {
        uStack_d8 = *(undefined8 *)(param_1 + 0x60);
        uStack_d0 = *(undefined8 *)(param_1 + 0x68);
        plVar11 = *(longlong **)(param_1 + 0x70);
        plVar21 = *(longlong **)(param_1 + 0x138);
        *(undefined8 *)(param_1 + 0x70) = 0;
        applStack_a8[0] = (longlong **)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        auStack_b8 = (undefined1  [8])0x0;
        pplStack_b0 = (longlong **)0x0;
        if (plVar21 != (longlong *)0x0) {
          *plVar21 = *plVar21 + 1;
        }
        plStack_c8 = plVar11;
        if (plVar11 == (longlong *)0x0) {
          lVar6 = FUN_23e8d6280(plVar2,0x70);
        }
        else {
          lVar6 = FUN_23e8d6280(plVar2,0x70);
          *(longlong **)(lVar6 + 0x10) = plVar11;
          *plVar11 = *plVar11 + 1;
        }
        if ((plStack_c8 != (longlong *)0x0) && (*plStack_c8 = *plStack_c8 + -1, *plStack_c8 == 0)) {
          FUN_23a334bc0();
        }
        plStack_c8 = (longlong *)lVar6;
        FUN_23a35ef40(param_1,&uStack_d8);
        iVar5 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                              *(undefined8 *)PyExc_BaseException_exref);
        if (iVar5 == 0) {
          cVar4 = FUN_23e8ba320(*(undefined8 *)(param_1 + 0x138));
          pplStack_e8 = applStack_a8[0];
          pplStack_f0 = pplStack_b0;
          pcStack_f8 = (code *)auStack_b8;
          uVar20 = 0;
          if (cVar4 == '\0') {
            uVar20 = 0x6f;
          }
          if ((applStack_a8[0] != (longlong **)0x0) && (applStack_a8[0][3] == plVar2)) {
            *(undefined4 *)(plVar2 + 5) = *(undefined4 *)((longlong)applStack_a8[0] + 0x24);
          }
          applStack_a8[0] = (longlong **)0x0;
          _auStack_b8 = (undefined1  [16])0x0;
          FUN_23ebf6ae0(param_1,plVar21);
          *(undefined4 *)(plVar2 + 5) = 0x6f;
          applStack_a8[0] = (longlong **)0x0;
          _auStack_b8 = (undefined1  [16])0x0;
          plVar11 = (longlong *)FUN_23e957a30(param_1,plVar10,_DAT_23ee284b0);
          puVar22 = (undefined8 *)(ulonglong)uVar20;
          if (plVar11 == (longlong *)0x0) {
            applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
            auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
            pplStack_b0 = *(longlong ***)(param_1 + 0x68);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            FUN_23a35d6b0();
            plStack_158 = (longlong *)0x0;
            puVar22 = (undefined8 *)0x6f;
            goto LAB_23c629a67;
          }
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            FUN_23a334bc0();
            puVar22 = (undefined8 *)(ulonglong)uVar20;
          }
        }
        else {
          lStack_90 = *(longlong *)(param_1 + 0x138);
          plStack_98 = *(longlong **)(lStack_90 + 8);
          pplStack_88 = *(longlong ***)(lStack_90 + 0x28);
          if (*(longlong ***)(lStack_90 + 0x28) == (longlong **)0x0) {
            pplStack_88 = (longlong **)_Py_NoneStruct_exref;
          }
          *(undefined4 *)(plVar2 + 5) = 0x6f;
          plVar11 = (longlong *)FUN_23e956150(param_1,plVar10);
          if (plVar11 == (longlong *)0x0) {
LAB_23c629d3c:
            auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
            pplStack_b0 = *(longlong ***)(param_1 + 0x68);
            pplVar18 = *(longlong ***)(param_1 + 0x70);
            uVar20 = 0x6f;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          else {
            iVar5 = FUN_23a35f020(plVar11);
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              FUN_23a334bc0();
            }
            if (iVar5 == -1) goto LAB_23c629d3c;
            if (iVar5 != 0) {
              FUN_23ebf6ae0(param_1,plVar21);
              goto LAB_23c628da3;
            }
            cVar4 = FUN_23e8ba320(*(undefined8 *)(param_1 + 0x138),auStack_b8);
            uVar20 = 0;
            if (cVar4 == '\0') {
              uVar20 = 0x6f;
            }
            pplVar18 = applStack_a8[0];
            if ((applStack_a8[0] != (longlong **)0x0) && (applStack_a8[0][3] == plVar2)) {
              *(undefined4 *)(plVar2 + 5) = *(undefined4 *)((longlong)applStack_a8[0] + 0x24);
            }
          }
          pplVar14 = pplStack_b0;
          auVar19 = auStack_b8;
          applStack_a8[0] = (longlong **)0x0;
          _auStack_b8 = (undefined1  [16])0x0;
          FUN_23ebf6ae0(param_1,plVar21);
          puVar22 = (undefined8 *)(ulonglong)uVar20;
          pcStack_f8 = (code *)auVar19;
          pplStack_f0 = pplVar14;
          pplStack_e8 = pplVar18;
        }
        applStack_a8[0] = pplStack_e8;
        auStack_b8 = (undefined1  [8])pcStack_f8;
        pplStack_b0 = pplStack_f0;
        goto LAB_23c629a67;
      }
      *(undefined4 *)(plVar2 + 5) = 0x6f;
      plVar11 = (longlong *)FUN_23e957a30(param_1,plVar10);
      if (plVar11 == (longlong *)0x0) {
        applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pplStack_b0 = *(longlong ***)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        puVar22 = (undefined8 *)0x6f;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23c629a67;
      }
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        FUN_23a334bc0();
      }
LAB_23c628da3:
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        FUN_23a334bc0(plVar8);
      }
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        FUN_23a334bc0(plVar7);
      }
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        FUN_23a334bc0(plVar10);
      }
      lVar6 = FUN_23ead5f40();
      if (lVar6 == 0) {
        FUN_23e915740(param_1,auStack_b8);
        pplVar18 = (longlong **)_Py_NoneStruct_exref;
        goto LAB_23c629212;
      }
      plVar9 = (longlong *)FUN_23e8bc2f0(lVar6,DAT_23ee28400);
      plVar8 = _DAT_23ee28510;
      if (plVar9 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
        puVar22 = (undefined8 *)0x72;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pplVar18 = (longlong **)_Py_NoneStruct_exref;
        plStack_160 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        unaff_R14 = (longlong *)0x0;
        pplStack_b0 = *(longlong ***)(param_1 + 0x68);
        goto LAB_23c626fea;
      }
      plVar10 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
      *plVar8 = *plVar8 + 1;
      plVar10[3] = (longlong)plVar8;
      if (plStack_158 == (longlong *)0x0) {
        FUN_23e8ba2b0(auStack_b8,_DAT_23ee28518);
        pplVar18 = (longlong **)_Py_NoneStruct_exref;
        if ((auStack_b8 != (undefined1  [8])_Py_NoneStruct_exref) &&
           (auStack_b8 != (undefined1  [8])0x0)) {
          FUN_23e91b1b0(param_1,auStack_b8,auStack_b8 + 8,applStack_a8);
        }
        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pplStack_b0);
LAB_23c62994b:
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          FUN_23a334bc0();
        }
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          FUN_23a334bc0();
        }
LAB_23c629212:
        puVar22 = (undefined8 *)0x72;
        unaff_R14 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
      }
      else {
        plVar8 = (longlong *)FUN_23e8bd600();
        if (plVar8 == (longlong *)0x0) {
LAB_23c62991d:
          applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
          auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
          pplStack_b0 = *(longlong ***)(param_1 + 0x68);
          *(undefined8 *)(param_1 + 0x70) = 0;
          pplVar18 = (longlong **)_Py_NoneStruct_exref;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23c62994b;
        }
        lVar6 = FUN_23e94f9d0();
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          FUN_23a334bc0();
        }
        if (lVar6 == 0) goto LAB_23c62991d;
        plVar10[4] = lVar6;
        plVar8 = _DAT_23ee28520;
        *_DAT_23ee28520 = *_DAT_23ee28520 + 1;
        plVar10[5] = (longlong)plVar8;
        plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar10);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          FUN_23a334bc0();
        }
        if (plVar8 == (longlong *)0x0) {
          auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
          pplStack_b0 = *(longlong ***)(param_1 + 0x68);
          applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar9 = *plVar9 + -1;
          pplVar18 = (longlong **)_Py_NoneStruct_exref;
          if (*plVar9 == 0) {
            FUN_23a334bc0();
            pplVar18 = (longlong **)_Py_NoneStruct_exref;
          }
          goto LAB_23c629212;
        }
        *(undefined4 *)(plVar2 + 5) = 0x72;
        plVar10 = (longlong *)FUN_23e914090(param_1,plVar9);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          FUN_23a334bc0();
        }
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          FUN_23a334bc0();
        }
        pplVar18 = (longlong **)_Py_NoneStruct_exref;
        if (plVar10 == (longlong *)0x0) {
          applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
          auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
          pplStack_b0 = *(longlong ***)(param_1 + 0x68);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23c629212;
        }
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          FUN_23a334bc0(plVar10);
        }
        plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23ee28528);
        if (plVar8 == (longlong *)0x0) {
LAB_23c6291a1:
          pplVar18 = (longlong **)_Py_NoneStruct_exref;
          applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
          auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
          puVar22 = (undefined8 *)0x74;
          unaff_R14 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plStack_160 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pplStack_b0 = *(longlong ***)(param_1 + 0x68);
        }
        else {
          *(undefined4 *)(plVar2 + 5) = 0x74;
          unaff_R14 = (longlong *)FUN_23e914090(param_1,plVar8,plStack_158);
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            FUN_23a334bc0();
          }
          if (unaff_R14 == (longlong *)0x0) goto LAB_23c6291a1;
          lVar6 = FUN_23ead5b50();
          if (lVar6 == 0) {
            FUN_23e915740(param_1,auStack_b8,_DAT_23ee28488);
            puVar22 = (undefined8 *)0x75;
            plStack_160 = (longlong *)0x0;
            pplVar18 = (longlong **)_Py_NoneStruct_exref;
          }
          else {
            *(undefined4 *)(plVar2 + 5) = 0x75;
            plStack_160 = (longlong *)FUN_23e915840(param_1,lVar6,_DAT_23ee28530,unaff_R14);
            pplVar18 = (longlong **)_Py_NoneStruct_exref;
            if (plStack_160 == (longlong *)0x0) {
              auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
              applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
              puVar22 = (undefined8 *)0x75;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pplStack_b0 = *(longlong ***)(param_1 + 0x68);
            }
            else {
              lVar6 = FUN_23ead5f40();
              if (lVar6 == 0) {
                FUN_23e915740(param_1,auStack_b8,DAT_23ee283f8);
                puVar22 = (undefined8 *)0x77;
                pplVar18 = (longlong **)_Py_NoneStruct_exref;
              }
              else {
                *(undefined4 *)(plVar2 + 5) = 0x77;
                plVar8 = (longlong *)FUN_23e915840(param_1,lVar6,DAT_23ee28400);
                if (plVar8 == (longlong *)0x0) {
                  auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                  applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
                  puVar22 = (undefined8 *)0x77;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pplVar18 = (longlong **)_Py_NoneStruct_exref;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                }
                else {
                  *plVar8 = *plVar8 + -1;
                  if (*plVar8 == 0) {
                    FUN_23a334bc0();
                  }
                  plVar8 = (longlong *)FUN_23e8bc2f0(plStack_160,DAT_23ed6ce40);
                  if (plVar8 == (longlong *)0x0) {
LAB_23c629115:
                    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                    applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  else {
                    *(undefined4 *)(plVar2 + 5) = 0x7a;
                    plVar9 = (longlong *)FUN_23e94bb80(param_1,plVar8,_DAT_23ee28540);
                    *plVar8 = *plVar8 + -1;
                    if (*plVar8 == 0) {
                      FUN_23a334bc0();
                    }
                    if (plVar9 == (longlong *)0x0) goto LAB_23c629115;
                    plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee283a0);
                    if (plVar8 != (longlong *)0x0) {
                      iVar5 = FUN_23e983ac0(plVar9,plVar8);
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 == 0) {
                        FUN_23a334bc0();
                      }
                      *plVar8 = *plVar8 + -1;
                      if (*plVar8 == 0) {
                        FUN_23a334bc0();
                      }
                      if (iVar5 != -1) {
                        if (iVar5 == 1) {
                          lVar16 = FUN_23ead5f40();
                          lVar6 = _DAT_23ee28550;
                          if (lVar16 == 0) {
                            FUN_23e915740(param_1,auStack_b8,DAT_23ee283f8);
                            puVar22 = (undefined8 *)0x7b;
                            pplVar18 = (longlong **)_Py_NoneStruct_exref;
                          }
                          else {
                            *(undefined4 *)(plVar2 + 5) = 0x7b;
                            plVar8 = (longlong *)
                                     FUN_23e915840(param_1,lVar16,_DAT_23ee28548,
                                                   *(undefined8 *)(lVar6 + 0x18));
                            if (plVar8 == (longlong *)0x0) {
                              auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                              applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
                              puVar22 = (undefined8 *)0x7b;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              pplVar18 = (longlong **)_Py_NoneStruct_exref;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                            }
                            else {
                              *plVar8 = *plVar8 + -1;
                              if (*plVar8 == 0) {
                                FUN_23a334bc0();
                              }
                              *(undefined4 *)(plVar2 + 5) = 0x7c;
                              plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar1,_DAT_23ee28558);
                              if (plVar8 != (longlong *)0x0) {
LAB_23c6294d3:
                                *plVar8 = *plVar8 + -1;
                                if (*plVar8 == 0) {
                                  FUN_23a334bc0();
                                }
                                pcVar12 = _Py_FalseStruct_exref;
                                pplVar18 = (longlong **)0x0;
                                *(longlong *)_Py_FalseStruct_exref =
                                     *(longlong *)_Py_FalseStruct_exref + 1;
                                goto LAB_23c62775c;
                              }
                              auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                              applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
                              puVar22 = (undefined8 *)0x7c;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              pplVar18 = (longlong **)_Py_NoneStruct_exref;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                            }
                          }
                        }
                        else {
                          cVar4 = FUN_23e8d9ac0(plVar1,DAT_23ee283a8);
                          if (cVar4 == '\0') {
                            auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                            applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            pplVar18 = (longlong **)_Py_NoneStruct_exref;
                            puVar22 = (undefined8 *)0x7f;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                          }
                          else {
                            plVar8 = (longlong *)FUN_23e8bc2f0(plStack_160,DAT_23ed6ce40);
                            if (plVar8 != (longlong *)0x0) {
                              *(undefined4 *)(plVar2 + 5) = 0x80;
                              plVar9 = (longlong *)FUN_23e94bb80(param_1,plVar8);
                              *plVar8 = *plVar8 + -1;
                              if (*plVar8 == 0) {
                                FUN_23a334bc0();
                              }
                              if (plVar9 != (longlong *)0x0) {
                                cVar4 = FUN_23e8d9ac0(plVar1,DAT_23ee28390);
                                *plVar9 = *plVar9 + -1;
                                if (*plVar9 == 0) {
                                  FUN_23a334bc0();
                                }
                                if (cVar4 != '\0') {
                                  *(undefined4 *)(plVar2 + 5) = 0x83;
                                  plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23ee28568);
                                  if (plVar8 == (longlong *)0x0) {
                                    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                                    applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  }
                                  else {
                                    iVar5 = FUN_23a35f020();
                                    lVar6 = *plVar8 + -1;
                                    if (iVar5 != -1) {
                                      *plVar8 = lVar6;
                                      if (lVar6 == 0) {
                                        FUN_23a334bc0(plVar8);
                                      }
                                      pcVar12 = _Py_TrueStruct_exref;
                                      if (iVar5 == 0) {
                                        lVar16 = FUN_23ead5f40();
                                        lVar6 = _DAT_23ee28580;
                                        if (lVar16 == 0) {
                                          FUN_23e915740(param_1,auStack_b8,DAT_23ee283f8);
                                          puVar22 = (undefined8 *)0x88;
                                          pplVar18 = (longlong **)_Py_NoneStruct_exref;
                                        }
                                        else {
                                          *(undefined4 *)(plVar2 + 5) = 0x88;
                                          plVar8 = (longlong *)
                                                   FUN_23e915840(param_1,lVar16,_DAT_23ee28548,
                                                                 *(undefined8 *)(lVar6 + 0x18));
                                          if (plVar8 == (longlong *)0x0) {
                                            auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                            applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
                                            puVar22 = (undefined8 *)0x88;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            pplVar18 = (longlong **)_Py_NoneStruct_exref;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                                          }
                                          else {
                                            *plVar8 = *plVar8 + -1;
                                            if (*plVar8 == 0) {
                                              FUN_23a334bc0();
                                            }
                                            *(undefined4 *)(plVar2 + 5) = 0x89;
                                            plVar8 = (longlong *)
                                                     FUN_23e91bfe0(param_1,plVar1,_DAT_23ee28558);
                                            if (plVar8 != (longlong *)0x0) goto LAB_23c6294d3;
                                            auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                            applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
                                            puVar22 = (undefined8 *)0x89;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            pplVar18 = (longlong **)_Py_NoneStruct_exref;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                                          }
                                        }
                                      }
                                      else {
                                        cVar4 = FUN_23e8d9ac0(plVar1,DAT_23ee283b0,
                                                              _Py_TrueStruct_exref);
                                        pplVar18 = (longlong **)_Py_NoneStruct_exref;
                                        if (cVar4 == '\0') {
                                          auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                          applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
                                          puVar22 = (undefined8 *)0x84;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                                        }
                                        else {
                                          lVar6 = FUN_23ead5f40();
                                          if (lVar6 == 0) {
                                            FUN_23e915740(param_1,auStack_b8,DAT_23ee283f8);
                                          }
                                          else {
                                            plVar9 = (longlong *)FUN_23e8bc2f0(lVar6,DAT_23ee28400);
                                            plVar8 = _DAT_23ee28570;
                                            if (plVar9 == (longlong *)0x0) {
LAB_23c62978e:
                                              auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                              pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                                              applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                            }
                                            else {
                                              plVar10 = (longlong *)
                                                        FUN_23e916ad0(*(undefined8 *)
                                                                       (param_1 + 0x10),2);
                                              *plVar8 = *plVar8 + 1;
                                              plVar10[3] = (longlong)plVar8;
                                              plVar8 = (longlong *)
                                                       FUN_23e8bc2f0(plStack_160,DAT_23ed6ce40);
                                              if (plVar8 != (longlong *)0x0) {
                                                *(undefined4 *)(plVar2 + 5) = 0x85;
                                                plVar11 = (longlong *)
                                                          FUN_23e94bb80(param_1,plVar8,DAT_23ee28578
                                                                       );
                                                *plVar8 = *plVar8 + -1;
                                                if (*plVar8 == 0) {
                                                  FUN_23a334bc0();
                                                }
                                                if (plVar11 != (longlong *)0x0) {
                                                  lVar6 = FUN_23e94f9d0(param_1,plVar11,
                                                                        DAT_23ed6cd28);
                                                  *plVar11 = *plVar11 + -1;
                                                  if (*plVar11 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  if (lVar6 != 0) {
                                                    plVar10[4] = lVar6;
                                                    plVar8 = (longlong *)
                                                             PyUnicode_Join(DAT_23ed6cd28,plVar10);
                                                    *plVar10 = *plVar10 + -1;
                                                    if (*plVar10 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    if (plVar8 == (longlong *)0x0) {
                                                      auStack_b8 = *(undefined1 (*) [8])
                                                                    (param_1 + 0x60);
                                                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                                                      applStack_a8[0] =
                                                           *(longlong ***)(param_1 + 0x70);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *plVar9 = *plVar9 + -1;
                                                      if (*plVar9 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      goto LAB_23c629736;
                                                    }
                                                    *(undefined4 *)(plVar2 + 5) = 0x85;
                                                    plVar10 = (longlong *)
                                                              FUN_23e914090(param_1,plVar9,plVar8);
                                                    *plVar9 = *plVar9 + -1;
                                                    if (*plVar9 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    *plVar8 = *plVar8 + -1;
                                                    if (*plVar8 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    if (plVar10 != (longlong *)0x0) {
                                                      *plVar10 = *plVar10 + -1;
                                                      if (*plVar10 == 0) {
                                                        FUN_23a334bc0(plVar10);
                                                      }
                                                      pplVar18 = (longlong **)0x0;
                                                      *(longlong *)pcVar12 =
                                                           *(longlong *)pcVar12 + 1;
                                                      goto LAB_23c62775c;
                                                    }
                                                    goto LAB_23c62978e;
                                                  }
                                                }
                                              }
                                              auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                              pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                                              applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              *plVar9 = *plVar9 + -1;
                                              if (*plVar9 == 0) {
                                                FUN_23a334bc0();
                                              }
                                              *plVar10 = *plVar10 + -1;
                                              if (*plVar10 == 0) {
                                                FUN_23a334bc0();
                                              }
                                            }
                                          }
LAB_23c629736:
                                          puVar22 = (undefined8 *)0x85;
                                          pplVar18 = (longlong **)_Py_NoneStruct_exref;
                                        }
                                      }
                                      goto LAB_23c626fea;
                                    }
                                    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                                    applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    *plVar8 = lVar6;
                                    if (lVar6 == 0) {
                                      FUN_23a334bc0();
                                    }
                                  }
                                  puVar22 = (undefined8 *)0x83;
                                  pplVar18 = (longlong **)_Py_NoneStruct_exref;
                                  goto LAB_23c626fea;
                                }
                              }
                            }
                            auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                            applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
                            puVar22 = (undefined8 *)0x80;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            pplVar18 = (longlong **)_Py_NoneStruct_exref;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                          }
                        }
                        goto LAB_23c626fea;
                      }
                      goto LAB_23c629115;
                    }
                    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                    applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      FUN_23a334bc0();
                    }
                  }
                  puVar22 = (undefined8 *)0x7a;
                  pplVar18 = (longlong **)_Py_NoneStruct_exref;
                }
              }
            }
          }
        }
      }
    }
  }
LAB_23c626fea:
  pplVar14 = applStack_a8[0];
  auStack_118._8_8_ = pplStack_b0;
  auStack_118._0_8_ = auStack_b8;
  param_4 = (int)puVar22;
  applStack_a8[0] = (longlong **)0x0;
  auStack_b8 = (undefined1  [8])0x0;
  pplStack_b0 = (longlong **)0x0;
  applStack_108[0] = pplVar14;
  plStack_150 = *(longlong **)(param_1 + 0x138);
  if (plStack_150 != (longlong *)0x0) {
    *plStack_150 = *plStack_150 + 1;
  }
  pplVar13 = (longlong **)DAT_23ed6a4f8;
  if (pplVar14 == (longlong **)0x0) {
    if (param_4 == 0) {
      param_4 = (int)plVar2[5];
    }
    if (DAT_23ed6a4f8 == (code *)0x0) goto LAB_23c628598;
    pplVar14 = (longlong **)0x0;
    pcVar12 = *(code **)DAT_23ed6a4f8;
    *(undefined8 *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar12;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    goto LAB_23c628037;
  }
  pplVar17 = pplVar18;
  pplVar18 = applStack_108[0];
  if (param_4 != 0) {
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pplVar13 = (longlong **)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar12 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar12;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar12 = _PyRuntime_exref;
    pplVar13[3] = plVar2;
    *plVar2 = *plVar2 + 1;
    lVar6 = *(longlong *)(pcVar12 + 0x1f8);
    *(int *)((longlong)pplVar13 + 0x24) = param_4;
    *(undefined4 *)(pplVar13 + 4) = 0xffffffff;
    plVar8 = *(longlong **)(*(longlong *)(lVar6 + 0x10) + 0x2e8);
    plVar9 = pplVar13[-1];
    puVar22 = (undefined8 *)plVar8[1];
    *puVar22 = pplVar13 + -2;
    pplVar13[-2] = plVar8;
    pplVar13[-1] = (longlong *)((ulonglong)((uint)plVar9 & 3) | (ulonglong)puVar22);
    plVar8[1] = (longlong)(pplVar13 + -2);
    pplVar13[2] = (longlong *)pplVar14;
    *pplVar14 = (longlong *)((longlong)*pplVar14 + 1);
    pplVar18 = pplVar13;
    if ((applStack_108[0] != (longlong **)0x0) &&
       (*applStack_108[0] = (longlong *)((longlong)*applStack_108[0] + -1),
       *applStack_108[0] == (longlong *)0x0)) {
      (*(code *)applStack_108[0][1][6])();
    }
  }
  while( true ) {
    applStack_108[0] = pplVar18;
    param_4 = (int)puVar22;
    if (((longlong **)auStack_118._0_8_ != (longlong **)0x0) &&
       ((longlong **)auStack_118._0_8_ != pplVar17)) {
      param_4 = (int)applStack_108;
      FUN_23e91b1b0(param_1,auStack_118,auStack_118 + 8);
    }
    plVar8 = *(longlong **)(auStack_118._8_8_ + 0x28);
    if (applStack_108[0] == pplVar17) {
      pplVar18 = (longlong **)0x0;
    }
    else {
      pplVar18 = applStack_108[0];
      if (applStack_108[0] != (longlong **)0x0) {
        *applStack_108[0] = (longlong *)((longlong)*applStack_108[0] + 1);
      }
    }
    *(longlong ***)(auStack_118._8_8_ + 0x28) = pplVar18;
    if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
      (**(code **)(plVar8[1] + 0x30))();
    }
    plVar8 = *(longlong **)(param_1 + 0x138);
    *(undefined8 *)(param_1 + 0x138) = auStack_118._8_8_;
    if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
      (**(code **)(plVar8[1] + 0x30))();
    }
    *(longlong *)auStack_118._0_8_ = *(longlong *)auStack_118._0_8_ + -1;
    if (*(longlong *)auStack_118._0_8_ == 0) {
      (**(code **)(*(longlong *)(auStack_118._0_8_ + 8) + 0x30))();
    }
    if ((applStack_108[0] != (longlong **)0x0) &&
       (*applStack_108[0] = (longlong *)((longlong)*applStack_108[0] + -1),
       *applStack_108[0] == (longlong *)0x0)) {
      (*(code *)applStack_108[0][1][6])();
    }
    applStack_108[0] = (longlong **)0x0;
    auStack_118 = (undefined1  [16])0x0;
    iVar5 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                          *(undefined8 *)PyExc_Exception_exref);
    plVar8 = _DAT_23ee28588;
    lVar6 = _DAT_23ee28338;
    if (iVar5 == 0) {
      pplVar14 = *(longlong ***)(param_1 + 0x138);
      pplStack_b0 = pplVar14;
      if ((pplVar14 == pplVar17) || (pplVar14 == (longlong **)0x0)) {
        pplVar17 = (longlong **)0x0;
        pplVar18 = (longlong **)0x0;
        auVar19 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
        pplVar14 = (longlong **)PyUnicode_FromString("No active exception to reraise");
        iVar5 = 99;
        pplVar13 = *(longlong ***)(param_1 + 0x138);
        *(longlong *)auVar19 = *(longlong *)auVar19 + 1;
        goto LAB_23c627993;
      }
      auVar19 = (undefined1  [8])pplVar14[1];
      pplVar17 = (longlong **)pplVar14[5];
      *pplVar14 = (longlong *)((longlong)*pplVar14 + 1);
      *(longlong *)auVar19 = *(longlong *)auVar19 + 1;
      iVar5 = 0;
      pplVar13 = pplVar14;
      if (pplVar17 == (longlong **)0x0) {
        *(longlong **)(param_1 + 0x138) = plStack_150;
        pplVar18 = (longlong **)0x0;
      }
      else {
        *pplVar17 = (longlong *)((longlong)*pplVar17 + 1);
        if (pplVar17[3] == plVar2) {
          *(undefined4 *)(plVar2 + 5) = *(undefined4 *)((longlong)pplVar17 + 0x24);
        }
        *(longlong **)(param_1 + 0x138) = plStack_150;
        pplVar18 = (longlong **)0x0;
      }
      goto LAB_23c627ce9;
    }
    plVar9 = *(longlong **)(param_1 + 0x138);
    *plVar9 = *plVar9 + 1;
    *(undefined4 *)(plVar2 + 5) = 0x8d;
    plStack_98 = plVar8;
    lStack_90 = lVar6;
    pplVar18 = &DAT_23ed6a498;
    uStack_78 = DAT_23ed6ccf0;
    pplStack_88 = pplVar17;
    pplStack_80 = pplVar17;
    if (DAT_23ed6a498 != (longlong *)0x0) break;
    plVar8 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"__import__");
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
      DAT_23ed6a498 = plVar8;
      break;
    }
LAB_23c628580:
    PyErr_PrintEx(0);
    Py_Exit(1);
LAB_23c628598:
    pplVar13 = (longlong **)FUN_23a33a530(PyTraceBack_Type_exref);
    pplVar14 = applStack_108[0];
LAB_23c628037:
    pcVar12 = _PyRuntime_exref;
    pplVar13[2] = (longlong *)0x0;
    pplVar13[3] = plVar2;
    *plVar2 = *plVar2 + 1;
    lVar6 = *(longlong *)(pcVar12 + 0x1f8);
    *(int *)((longlong)pplVar13 + 0x24) = param_4;
    lVar6 = *(longlong *)(lVar6 + 0x10);
    *(undefined4 *)(pplVar13 + 4) = 0xffffffff;
    plVar8 = *(longlong **)(lVar6 + 0x2e8);
    plVar9 = pplVar13[-1];
    puVar22 = (undefined8 *)plVar8[1];
    *puVar22 = pplVar13 + -2;
    pplVar13[-2] = plVar8;
    pplVar13[-1] = (longlong *)((ulonglong)((uint)plVar9 & 3) | (ulonglong)puVar22);
    plVar8[1] = (longlong)(pplVar13 + -2);
    pplVar17 = pplVar18;
    pplVar18 = pplVar13;
    if ((pplVar14 != (longlong **)0x0) &&
       (*pplVar14 = (longlong *)((longlong)*pplVar14 + -1), *pplVar14 == (longlong *)0x0)) {
      (*(code *)pplVar14[1][6])();
    }
  }
  pplVar18 = (longlong **)FUN_23e95b390(param_1,DAT_23ed6a498,&plStack_98);
  if (pplVar18 == (longlong **)0x0) {
    auVar19 = *(undefined1 (*) [8])(param_1 + 0x60);
    pplVar14 = *(longlong ***)(param_1 + 0x68);
    iVar5 = 0x8d;
    pplVar17 = *(longlong ***)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23c627940;
  }
  lVar6 = FUN_23ead5f40();
  if (lVar6 == 0) {
    FUN_23e915740(param_1,auStack_b8,DAT_23ee283f8);
    iVar5 = 0x8e;
    pplVar14 = pplStack_b0;
    auVar19 = auStack_b8;
    pplVar17 = applStack_a8[0];
    goto LAB_23c627940;
  }
  plVar8 = (longlong *)FUN_23e8bc2f0(lVar6,DAT_23ee284c0);
  plVar10 = _DAT_23ee28590;
  if (plVar8 == (longlong *)0x0) {
LAB_23c628180:
    auVar19 = *(undefined1 (*) [8])(param_1 + 0x60);
    iVar5 = 0x8e;
    pplVar17 = *(longlong ***)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    pplVar14 = *(longlong ***)(param_1 + 0x68);
    goto LAB_23c627940;
  }
  lVar6 = *(longlong *)(param_1 + 0x10);
  plVar11 = *(longlong **)(lVar6 + 0xe30);
  if (plVar11 == (longlong *)0x0) {
    plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,4);
  }
  else {
    lVar16 = plVar11[3];
    *(int *)(lVar6 + 0xec4) = *(int *)(lVar6 + 0xec4) + -1;
    *(longlong *)(lVar6 + 0xe30) = lVar16;
    *plVar11 = 1;
  }
  pcVar12 = _PyRuntime_exref;
  plVar11[6] = 0;
  *(undefined1 (*) [16])(plVar11 + 4) = (undefined1  [16])0x0;
  lVar6 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar12 + 0x1f8) + 0x10) + 0x2e8);
  lVar16 = plVar11[-1];
  puVar22 = *(undefined8 **)(lVar6 + 8);
  *puVar22 = plVar11 + -2;
  plVar11[-2] = lVar6;
  plVar11[-1] = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar22;
  *(longlong **)(lVar6 + 8) = plVar11 + -2;
  plVar21 = (longlong *)plVar9[1];
  *plVar10 = *plVar10 + 1;
  plVar11[3] = (longlong)plVar10;
  uVar3 = DAT_23ed6cd48;
  *plVar21 = *plVar21 + 1;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar21,uVar3);
  *plVar21 = *plVar21 + -1;
  if (*plVar21 == 0) {
    (**(code **)(plVar21[1] + 0x30))();
  }
  lVar6 = DAT_23ed6cd28;
  if (plVar10 == (longlong *)0x0) {
LAB_23c6278b0:
    applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
    lVar6 = *plVar8;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar8 = lVar6 + -1;
    if (lVar6 + -1 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
      iVar5 = 0x8e;
      pplVar14 = pplStack_b0;
      auVar19 = auStack_b8;
      pplVar17 = applStack_a8[0];
    }
    else {
      iVar5 = 0x8e;
      pplVar14 = pplStack_b0;
      auVar19 = auStack_b8;
      pplVar17 = applStack_a8[0];
    }
  }
  else {
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar21 = plVar11;
      plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      param_4 = (int)plVar21;
      if (plVar15 == (longlong *)0x0) goto LAB_23c628580;
      *plVar15 = *plVar15 + 1;
      DAT_23ed6a4c0 = plVar15;
    }
    lStack_90 = lVar6;
    plStack_98 = plVar10;
    lVar6 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (lVar6 == 0) goto LAB_23c6278b0;
    plVar11[4] = lVar6;
    plVar10 = _DAT_23ee28598;
    *_DAT_23ee28598 = *_DAT_23ee28598 + 1;
    plVar11[5] = (longlong)plVar10;
    plVar10 = (longlong *)FUN_23e8bd350(plVar9);
    lVar6 = DAT_23ed6cd28;
    if (plVar10 == (longlong *)0x0) goto LAB_23c6278b0;
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar21 = plVar11;
      plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      param_4 = (int)plVar21;
      if (plVar15 == (longlong *)0x0) goto LAB_23c628580;
      *plVar15 = *plVar15 + 1;
      DAT_23ed6a4c0 = plVar15;
    }
    lStack_90 = lVar6;
    plStack_98 = plVar10;
    lVar6 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (lVar6 == 0) goto LAB_23c6278b0;
    plVar11[6] = lVar6;
    plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar11);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (plVar10 == (longlong *)0x0) {
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      iVar5 = 0x8e;
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      lVar6 = *plVar8 + -1;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar8 = lVar6;
      goto joined_r0x00023c628610;
    }
    *(undefined4 *)(plVar2 + 5) = 0x8e;
    plVar11 = (longlong *)FUN_23e914090(param_1,plVar8);
    lVar6 = *plVar8;
    *plVar8 = lVar6 + -1;
    if (lVar6 + -1 == 0) {
      (**(code **)(plVar8[1] + 0x30))();
    }
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar11 == (longlong *)0x0) goto LAB_23c628180;
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    lVar6 = FUN_23ead5f40();
    if (lVar6 == 0) {
      FUN_23e915740(param_1,auStack_b8,DAT_23ee283f8);
      iVar5 = 0x8f;
      pplVar14 = pplStack_b0;
      auVar19 = auStack_b8;
      pplVar17 = applStack_a8[0];
      goto LAB_23c627940;
    }
    plVar8 = (longlong *)FUN_23e8bc2f0(lVar6,DAT_23ee284c0);
    plVar10 = _DAT_23ee285a0;
    if (plVar8 == (longlong *)0x0) goto LAB_23c6283c0;
    lVar6 = *(longlong *)(param_1 + 0x10);
    plVar11 = *(longlong **)(lVar6 + 0xe20);
    if (plVar11 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar16 = plVar11[3];
      *(int *)(lVar6 + 0xebc) = *(int *)(lVar6 + 0xebc) + -1;
      *(longlong *)(lVar6 + 0xe20) = lVar16;
      *plVar11 = 1;
    }
    plVar11[4] = 0;
    lVar6 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar12 + 0x1f8) + 0x10) + 0x2e8);
    lVar16 = plVar11[-1];
    puVar22 = *(undefined8 **)(lVar6 + 8);
    *puVar22 = plVar11 + -2;
    plVar11[-2] = lVar6;
    plVar11[-1] = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar22;
    *(longlong **)(lVar6 + 8) = plVar11 + -2;
    *plVar10 = *plVar10 + 1;
    plVar11[3] = (longlong)plVar10;
    uVar3 = _DAT_23ee285a8;
    *(undefined4 *)(plVar2 + 5) = 0x8f;
    plVar10 = (longlong *)FUN_23e91bfe0(param_1,pplVar18,uVar3);
    lVar6 = DAT_23ed6cd28;
    if (plVar10 == (longlong *)0x0) goto LAB_23c628478;
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar21 = plVar11;
      plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      param_4 = (int)plVar21;
      if (plVar15 == (longlong *)0x0) goto LAB_23c628580;
      *plVar15 = *plVar15 + 1;
      DAT_23ed6a4c0 = plVar15;
    }
    lStack_90 = lVar6;
    plStack_98 = plVar10;
    lVar6 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (lVar6 == 0) {
LAB_23c628478:
      applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      _auStack_b8 = *(undefined1 (*) [16])(param_1 + 0x60);
      lVar6 = *plVar8;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar8 = lVar6 + -1;
      if (lVar6 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      iVar5 = 0x8f;
      pplVar14 = pplStack_b0;
      auVar19 = auStack_b8;
      pplVar17 = applStack_a8[0];
    }
    else {
      plVar11[4] = lVar6;
      plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar11);
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (plVar10 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        iVar5 = 0x8f;
        pplStack_b0 = *(longlong ***)(param_1 + 0x68);
        applStack_a8[0] = *(longlong ***)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        lVar6 = *plVar8 + -1;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar8 = lVar6;
joined_r0x00023c628610:
        pplVar14 = pplStack_b0;
        auVar19 = auStack_b8;
        pplVar17 = applStack_a8[0];
        if (lVar6 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
          pplVar14 = pplStack_b0;
          auVar19 = auStack_b8;
          pplVar17 = applStack_a8[0];
        }
      }
      else {
        *(undefined4 *)(plVar2 + 5) = 0x8f;
        plVar11 = (longlong *)FUN_23e914090(param_1,plVar8);
        lVar6 = *plVar8;
        *plVar8 = lVar6 + -1;
        if (lVar6 + -1 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (plVar11 != (longlong *)0x0) {
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          pcVar12 = _Py_FalseStruct_exref;
          *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          plVar2 = *(longlong **)(param_1 + 0x138);
          *(longlong **)(param_1 + 0x138) = plStack_150;
          if ((plVar2 != (longlong *)0x0) && (*plVar2 = *plVar2 + -1, *plVar2 == 0)) {
            (**(code **)(plVar2[1] + 0x30))();
          }
LAB_23c62775c:
          lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
          plVar2 = *(longlong **)(lVar6 + 0x28);
          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar6 + 0x30);
          plVar8 = (longlong *)plVar2[2];
          *(undefined4 *)(plVar2 + 8) = 0xffffffff;
          if (plVar8 != (longlong *)0x0) {
            plVar2[2] = 0;
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))();
            }
          }
          *plVar2 = *plVar2 + -1;
          if (*plVar2 == 0) {
            (**(code **)(plVar2[1] + 0x30))(plVar2);
          }
          plVar2[0xf] = 0;
          if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          if ((plStack_158 != (longlong *)0x0) &&
             (lVar6 = *plStack_158, *plStack_158 = lVar6 + -1, lVar6 + -1 == 0)) {
            (**(code **)(plStack_158[1] + 0x30))(plStack_158);
          }
          if ((unaff_R14 != (longlong *)0x0) && (*unaff_R14 = *unaff_R14 + -1, *unaff_R14 == 0)) {
            (**(code **)(unaff_R14[1] + 0x30))(unaff_R14);
          }
          if ((plStack_160 != (longlong *)0x0) &&
             (lVar6 = *plStack_160, *plStack_160 = lVar6 + -1, lVar6 + -1 == 0)) {
            (**(code **)(plStack_160[1] + 0x30))(plStack_160);
          }
          if ((pplVar18 != (longlong **)0x0) &&
             (*pplVar18 = (longlong *)((longlong)*pplVar18 + -1), *pplVar18 == (longlong *)0x0)) {
            (*(code *)pplVar18[1][6])(pplVar18);
          }
          *plVar1 = *plVar1 + -1;
          if (*plVar1 == 0) {
            (**(code **)(plVar1[1] + 0x30))(plVar1);
            return pcVar12;
          }
          return pcVar12;
        }
LAB_23c6283c0:
        auVar19 = *(undefined1 (*) [8])(param_1 + 0x60);
        iVar5 = 0x8f;
        pplVar17 = *(longlong ***)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pplVar14 = *(longlong ***)(param_1 + 0x68);
      }
    }
  }
LAB_23c627940:
  applStack_a8[0] = (longlong **)0x0;
  _auStack_b8 = (undefined1  [16])0x0;
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  pplVar13 = *(longlong ***)(param_1 + 0x138);
LAB_23c627993:
  *(longlong **)(param_1 + 0x138) = plStack_150;
  if (pplVar13 == (longlong **)0x0) {
    pplStack_b0 = pplVar14;
    auStack_b8 = auVar19;
    applStack_a8[0] = pplVar17;
    if (pplVar17 != (longlong **)0x0) goto LAB_23c627d34;
LAB_23c6279e1:
    pplVar14 = (longlong **)DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pplVar14 = (longlong **)FUN_23a33a530(PyTraceBack_Type_exref);
      pplVar13 = applStack_a8[0];
    }
    else {
      pcVar12 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar12;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      pplVar13 = (longlong **)0x0;
    }
    pcVar12 = _PyRuntime_exref;
    pplVar14[2] = (longlong *)0x0;
    pplVar14[3] = plVar2;
    *plVar2 = *plVar2 + 1;
    lVar6 = *(longlong *)(pcVar12 + 0x1f8);
    *(int *)((longlong)pplVar14 + 0x24) = iVar5;
    lVar6 = *(longlong *)(lVar6 + 0x10);
    *(undefined4 *)(pplVar14 + 4) = 0xffffffff;
    plVar8 = *(longlong **)(lVar6 + 0x2e8);
    plVar9 = pplVar14[-1];
    puVar22 = (undefined8 *)plVar8[1];
    *puVar22 = pplVar14 + -2;
    pplVar14[-2] = plVar8;
    pplVar14[-1] = (longlong *)((ulonglong)((uint)plVar9 & 3) | (ulonglong)puVar22);
    plVar8[1] = (longlong)(pplVar14 + -2);
  }
  else {
LAB_23c627ce9:
    applStack_a8[0] = (longlong **)0x0;
    _auStack_b8 = (undefined1  [16])0x0;
    *pplVar13 = (longlong *)((longlong)*pplVar13 + -1);
    if (*pplVar13 == (longlong *)0x0) {
      (*(code *)pplVar13[1][6])();
    }
    pplStack_b0 = pplVar14;
    auStack_b8 = auVar19;
    if (pplVar17 == (longlong **)0x0) {
      applStack_a8[0] = pplVar17;
      if (iVar5 == 0) {
        iVar5 = (int)plVar2[5];
      }
      goto LAB_23c6279e1;
    }
LAB_23c627d34:
    pplVar14 = (longlong **)DAT_23ed6a4f8;
    if (pplVar17[3] == plVar2) goto LAB_23c627a88;
    if (iVar5 == 0) {
      iVar5 = (int)plVar2[5];
    }
    applStack_a8[0] = pplVar17;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pplVar14 = (longlong **)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar12 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar12;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar12 = _PyRuntime_exref;
    pplVar14[3] = plVar2;
    *plVar2 = *plVar2 + 1;
    lVar6 = *(longlong *)(pcVar12 + 0x1f8);
    *(int *)((longlong)pplVar14 + 0x24) = iVar5;
    *(undefined4 *)(pplVar14 + 4) = 0xffffffff;
    plVar8 = *(longlong **)(*(longlong *)(lVar6 + 0x10) + 0x2e8);
    plVar9 = pplVar14[-1];
    puVar22 = (undefined8 *)plVar8[1];
    *puVar22 = pplVar14 + -2;
    pplVar14[-2] = plVar8;
    pplVar14[-1] = (longlong *)((ulonglong)((uint)plVar9 & 3) | (ulonglong)puVar22);
    plVar8[1] = (longlong)(pplVar14 + -2);
    pplVar14[2] = (longlong *)pplVar17;
    *pplVar17 = (longlong *)((longlong)*pplVar17 + 1);
    pplVar13 = applStack_a8[0];
  }
  pplVar17 = pplVar14;
  if ((pplVar13 != (longlong **)0x0) &&
     (*pplVar13 = (longlong *)((longlong)*pplVar13 + -1), *pplVar13 == (longlong *)0x0)) {
    (*(code *)pplVar13[1][6])();
  }
LAB_23c627a88:
  applStack_a8[0] = pplVar17;
  FUN_23e8bba40(plVar2,"ooooooo",plVar1,plVar7,plStack_158,unaff_R14,plStack_160,0,pplVar18);
  if (_DAT_23ee29cc0 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    _DAT_23ee29cc0 = (longlong *)0x0;
  }
  lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar2 = *(longlong **)(lVar6 + 0x28);
  plVar8 = (longlong *)plVar2[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar6 + 0x30);
  *(undefined4 *)(plVar2 + 8) = 0xffffffff;
  if (plVar8 != (longlong *)0x0) {
    plVar2[2] = 0;
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))();
    }
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  pplVar13 = applStack_a8[0];
  plVar2[0xf] = 0;
  auVar19 = auStack_b8;
  pplVar14 = pplStack_b0;
  _auStack_b8 = (undefined1  [16])0x0;
  applStack_a8[0] = (longlong **)0x0;
  if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  if ((plStack_158 != (longlong *)0x0) &&
     (lVar6 = *plStack_158, *plStack_158 = lVar6 + -1, lVar6 + -1 == 0)) {
    (**(code **)(plStack_158[1] + 0x30))(plStack_158);
  }
  if ((unaff_R14 != (longlong *)0x0) && (*unaff_R14 = *unaff_R14 + -1, *unaff_R14 == 0)) {
    (**(code **)(unaff_R14[1] + 0x30))(unaff_R14);
  }
  if ((plStack_160 != (longlong *)0x0) &&
     (lVar6 = *plStack_160, *plStack_160 = lVar6 + -1, lVar6 + -1 == 0)) {
    (**(code **)(plStack_160[1] + 0x30))();
  }
  if ((pplVar18 != (longlong **)0x0) &&
     (*pplVar18 = (longlong *)((longlong)*pplVar18 + -1), *pplVar18 == (longlong *)0x0)) {
    (*(code *)pplVar18[1][6])(pplVar18);
  }
  *plVar1 = *plVar1 + -1;
  applStack_a8[0] = pplVar13;
  auStack_b8 = auVar19;
  pplStack_b0 = pplVar14;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,auStack_b8,pplStack_b0,applStack_a8[0]);
  return (code *)0x0;
}
