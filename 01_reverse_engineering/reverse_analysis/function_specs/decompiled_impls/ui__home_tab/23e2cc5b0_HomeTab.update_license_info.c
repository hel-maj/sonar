/* ===== 23e2cc5b0 ui.home_tab:375 ===== */
/* ghidra_name=FUN_23e2cc5b0 entry=23e2cc5b0 size=12882 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2cc5b0(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  code *pcVar4;
  code *pcVar5;
  undefined8 uVar6;
  int iVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  code *pcVar12;
  longlong lVar13;
  undefined8 uVar14;
  longlong *plVar15;
  longlong *plVar16;
  code *pcVar17;
  code *pcVar18;
  code *pcVar19;
  code **unaff_R13;
  undefined4 uVar20;
  undefined8 *unaff_R14;
  code *pcVar21;
  longlong *plStack_168;
  code *pcStack_160;
  longlong *plStack_158;
  longlong *plStack_148;
  longlong *plStack_140;
  longlong *plStack_138;
  longlong *plStack_130;
  longlong *plStack_128;
  code *pcStack_118;
  undefined1 auStack_f8 [16];
  code *apcStack_e8 [2];
  longlong *plStack_d8;
  code *pcStack_d0;
  code *pcStack_c8;
  undefined8 uStack_b8;
  code *pcStack_b0;
  code *pcStack_a8;
  code *pcStack_a0;
  undefined8 uStack_98;
  code *pcStack_88;
  code *pcStack_80;
  code *pcStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  
  pcVar17 = _Py_NoneStruct_exref;
  plVar8 = _DAT_23eeb02c0;
  param_3 = (longlong *)*param_3;
  if (_DAT_23eeb02c0 == (longlong *)0x0) {
LAB_23e2cc612:
    _DAT_23eeb02c0 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeb02b8,DAT_23eeb0380,0x50);
  }
  else {
    lVar9 = *_DAT_23eeb02c0;
    if (1 < lVar9) {
      *_DAT_23eeb02c0 = lVar9 + -1;
      goto LAB_23e2cc612;
    }
    if (_DAT_23eeb02c0[2] != 0) {
      *_DAT_23eeb02c0 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e2cc612;
    }
  }
  plVar3 = _DAT_23eeb02c0;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eeb02c0 + 9;
  lVar13 = *(longlong *)(lVar9 + 8);
  _DAT_23eeb02c0[0xf] = lVar13;
  *(longlong **)(lVar9 + 8) = plVar8;
  if ((lVar13 != 0) &&
     (((*(char *)(lVar13 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar13 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar13 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar13 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar13 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  pcVar18 = (code *)&DAT_23ed6a498;
  *(undefined4 *)(plVar3 + 8) = 0;
  uStack_b8 = _DAT_23eeade70;
  *plVar3 = *plVar3 + 1;
  uStack_98 = DAT_23ed6ccf0;
  plVar8 = DAT_23ed6a498;
  *(undefined4 *)(plVar3 + 5) = 0x17a;
  pcStack_a8 = pcVar17;
  pcStack_a0 = pcVar17;
  pcStack_b0 = DAT_23eeae258;
  pcVar19 = pcVar17;
  pcVar12 = pcVar17;
  if (plVar8 == (longlong *)0x0) {
    plVar8 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"__import__");
    if (plVar8 == (longlong *)0x0) goto LAB_23e2cea10;
    *plVar8 = *plVar8 + 1;
    DAT_23ed6a498 = plVar8;
  }
  plStack_130 = (longlong *)FUN_23e95b390(param_1,plVar8,&uStack_b8);
  pcStack_160 = _PyRuntime_exref;
  uVar6 = _DAT_23eeade80;
  pcVar21 = _DAT_23eeade78;
  uVar14 = DAT_23ed6ccf0;
  if (plStack_130 == (longlong *)0x0) {
    pcVar19 = *(code **)(param_1 + 0x70);
    plVar8 = *(longlong **)(param_1 + 0x60);
    pcVar12 = *(code **)(param_1 + 0x68);
    pcVar18 = (code *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar20 = 0x17a;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_128 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    plStack_140 = (longlong *)0x0;
    plStack_148 = (longlong *)0x0;
    plStack_168 = (longlong *)0x0;
    plStack_158 = (longlong *)0x0;
    goto LAB_23e2cd3e2;
  }
  *(undefined4 *)(plVar3 + 5) = 0x17b;
  uStack_70 = uVar6;
  pcStack_78 = pcVar17;
  uStack_68 = uVar14;
  pcStack_88 = pcVar21;
  pcStack_80 = DAT_23eeae258;
  if (DAT_23ed6a498 == (longlong *)0x0) {
    plVar8 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"__import__");
    if (plVar8 == (longlong *)0x0) goto LAB_23e2cea10;
    *plVar8 = *plVar8 + 1;
    DAT_23ed6a498 = plVar8;
  }
  unaff_R13 = &pcStack_88;
  plVar8 = (longlong *)FUN_23e95b390(param_1,DAT_23ed6a498,unaff_R13);
  pcStack_160 = _PyRuntime_exref;
  if (plVar8 == (longlong *)0x0) {
    plVar8 = *(longlong **)(param_1 + 0x60);
    pcVar12 = *(code **)(param_1 + 0x68);
    plStack_128 = (longlong *)0x0;
    pcVar19 = *(code **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar20 = 0x17b;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_138 = (longlong *)0x0;
    plStack_140 = (longlong *)0x0;
    plStack_148 = (longlong *)0x0;
    plStack_168 = (longlong *)0x0;
    plStack_158 = (longlong *)0x0;
    pcVar18 = (code *)0x0;
    goto LAB_23e2cd3e2;
  }
  if (((code *)plVar8[1] == PyModule_Type_exref) ||
     (iVar7 = PyType_IsSubtype(), uVar14 = _DAT_23eeade88, iVar7 != 0)) {
    pcVar18 = DAT_23eeae258;
    uVar6 = _DAT_23eeade88;
    uVar14 = DAT_23ed6ccf0;
    plStack_158 = (longlong *)PyObject_GetAttr(plVar8,_DAT_23eeade88);
    if (plStack_158 == (longlong *)0x0) {
      plStack_158 = (longlong *)FUN_23e970390(param_1,plVar8,pcVar18,uVar6,uVar14);
      goto LAB_23e2ce18a;
    }
LAB_23e2cc7c0:
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
  }
  else {
    plStack_158 = (longlong *)PyObject_GetAttr(plVar8,_DAT_23eeade88);
    if (plStack_158 != (longlong *)0x0) goto LAB_23e2cc7c0;
    plStack_158 = (longlong *)FUN_23e8d2cf0(param_1,plVar8,uVar14);
LAB_23e2ce18a:
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    pcStack_160 = _PyRuntime_exref;
    if (plStack_158 == (longlong *)0x0) {
      plVar8 = *(longlong **)(param_1 + 0x60);
      pcVar12 = *(code **)(param_1 + 0x68);
      pcVar19 = *(code **)(param_1 + 0x70);
      pcVar18 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar20 = 0x17b;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_128 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      plStack_148 = (longlong *)0x0;
      plStack_168 = (longlong *)0x0;
      goto LAB_23e2cd3e2;
    }
  }
  pcVar18 = (code *)FUN_23e8bc2f0(plStack_158,_DAT_23eeade90);
  pcStack_160 = _PyRuntime_exref;
  if (pcVar18 == (code *)0x0) {
    plVar8 = *(longlong **)(param_1 + 0x60);
    pcVar12 = *(code **)(param_1 + 0x68);
    plStack_128 = (longlong *)0x0;
    pcVar19 = *(code **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar20 = 0x17d;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_138 = (longlong *)0x0;
    plStack_140 = (longlong *)0x0;
    plStack_148 = (longlong *)0x0;
    plStack_168 = (longlong *)0x0;
    goto LAB_23e2cd3e2;
  }
  unaff_R14 = &DAT_23ed6a4c0;
  plVar8 = DAT_23ed6a4c0;
  pcVar12 = pcVar18;
  pcVar19 = DAT_23ed6cd28;
  if (DAT_23ed6a4c0 == (longlong *)0x0) goto LAB_23e2cea28;
LAB_23e2cc80c:
  pcStack_88 = pcVar12;
  pcStack_80 = pcVar19;
  lVar9 = FUN_23e94ed00(param_1,plVar8,unaff_R13);
  *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
  if (*(longlong *)pcVar18 == 0) {
    (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
  }
  if (lVar9 == 0) {
    plVar8 = *(longlong **)(param_1 + 0x60);
    pcVar12 = *(code **)(param_1 + 0x68);
    pcVar19 = *(code **)(param_1 + 0x70);
    pcVar18 = (code *)0x0;
    pcStack_160 = _PyRuntime_exref;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar20 = 0x17d;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_128 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    plStack_140 = (longlong *)0x0;
    plStack_148 = (longlong *)0x0;
    plStack_168 = (longlong *)0x0;
  }
  else {
    lVar13 = *(longlong *)(param_1 + 0x10);
    plVar8 = *(longlong **)(lVar13 + 0xe20);
    if (plVar8 == (longlong *)0x0) {
      plVar8 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar1 = plVar8[3];
      *(int *)(lVar13 + 0xebc) = *(int *)(lVar13 + 0xebc) + -1;
      *(longlong *)(lVar13 + 0xe20) = lVar1;
      *plVar8 = 1;
    }
    pcVar21 = _PyRuntime_exref;
    pcStack_160 = _PyRuntime_exref;
    lVar13 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
    lVar1 = plVar8[-1];
    puVar2 = *(undefined8 **)(lVar13 + 8);
    *puVar2 = plVar8 + -2;
    plVar8[-2] = lVar13;
    plVar8[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar13 + 8) = plVar8 + -2;
    plVar8[3] = lVar9;
    plVar10 = _DAT_23eeade98;
    *_DAT_23eeade98 = *_DAT_23eeade98 + 1;
    plVar8[4] = (longlong)plVar10;
    pcVar18 = (code *)PyUnicode_Join(DAT_23ed6cd28,plVar8);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (pcVar18 == (code *)0x0) {
      pcVar19 = *(code **)(param_1 + 0x70);
      plVar8 = *(longlong **)(param_1 + 0x60);
      pcVar12 = *(code **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_128 = (longlong *)0x0;
      uVar20 = 0x17d;
      plStack_138 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      plStack_148 = (longlong *)0x0;
      plStack_168 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e2cd3e2;
    }
    lVar9 = FUN_23e8f6a70();
    if (lVar9 == 0) {
      FUN_23e915740(param_1,&plStack_d8,DAT_23eeadcf8);
      pcVar19 = pcStack_c8;
      plVar8 = plStack_d8;
      pcVar12 = pcStack_d0;
LAB_23e2ceb67:
      plStack_168 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      uVar20 = 0x17e;
      plStack_138 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      plStack_148 = (longlong *)0x0;
      goto LAB_23e2cd3e2;
    }
    plVar10 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eeadd00);
    plVar8 = _DAT_23eeadea0;
    if (plVar10 == (longlong *)0x0) {
      pcVar19 = *(code **)(param_1 + 0x70);
      plVar8 = *(longlong **)(param_1 + 0x60);
      pcVar12 = *(code **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_168 = (longlong *)0x0;
      uVar20 = 0x17e;
      plStack_128 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plStack_148 = (longlong *)0x0;
      goto LAB_23e2cd3e2;
    }
    lVar9 = *(longlong *)(param_1 + 0x10);
    plVar11 = *(longlong **)(lVar9 + 0xe20);
    if (plVar11 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar13 = plVar11[3];
      *(int *)(lVar9 + 0xebc) = *(int *)(lVar9 + 0xebc) + -1;
      *(longlong *)(lVar9 + 0xe20) = lVar13;
      *plVar11 = 1;
    }
    lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar21 + 0x1f8) + 0x10) + 0x2e8);
    lVar13 = plVar11[-1];
    puVar2 = *(undefined8 **)(lVar9 + 8);
    *puVar2 = plVar11 + -2;
    plVar11[-2] = lVar9;
    plVar11[-1] = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar9 + 8) = plVar11 + -2;
    *plVar8 = *plVar8 + 1;
    plVar11[3] = (longlong)plVar8;
    *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
    plVar11[4] = (longlong)pcVar18;
    plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar11);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (plVar8 == (longlong *)0x0) {
      plVar8 = *(longlong **)(param_1 + 0x60);
      pcVar12 = *(code **)(param_1 + 0x68);
      pcVar19 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      lVar9 = *plVar10;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar10 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e2ceb67;
    }
    *(undefined4 *)(plVar3 + 5) = 0x17e;
    plVar11 = (longlong *)FUN_23e914090(param_1,plVar10,plVar8);
    lVar9 = *plVar10;
    *plVar10 = lVar9 + -1;
    if (lVar9 + -1 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    lVar9 = *plVar8;
    *plVar8 = lVar9 + -1;
    if (lVar9 + -1 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (plVar11 == (longlong *)0x0) {
      pcVar19 = *(code **)(param_1 + 0x70);
      plVar8 = *(longlong **)(param_1 + 0x60);
      pcVar12 = *(code **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_168 = (longlong *)0x0;
      uVar20 = 0x17e;
      plStack_128 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_148 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plStack_140 = (longlong *)0x0;
      goto LAB_23e2cd3e2;
    }
    lVar9 = *plVar11;
    *plVar11 = lVar9 + -1;
    if (lVar9 + -1 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    plVar8 = (longlong *)FUN_23e8bc2f0(plStack_130,DAT_23ed6ce40);
    if (plVar8 == (longlong *)0x0) {
      pcVar19 = *(code **)(param_1 + 0x70);
      plVar8 = *(longlong **)(param_1 + 0x60);
      pcVar12 = *(code **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_168 = (longlong *)0x0;
      uVar20 = 0x181;
      plStack_128 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plStack_148 = (longlong *)0x0;
      goto LAB_23e2cd3e2;
    }
    lVar9 = *(longlong *)(param_1 + 0x10);
    plVar10 = *(longlong **)(lVar9 + 0xe18);
    if (plVar10 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,1);
    }
    else {
      lVar13 = plVar10[3];
      *(int *)(lVar9 + 0xeb8) = *(int *)(lVar9 + 0xeb8) + -1;
      *(longlong *)(lVar9 + 0xe18) = lVar13;
      *plVar10 = 1;
    }
    lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar21 + 0x1f8) + 0x10) + 0x2e8);
    lVar13 = plVar10[-1];
    puVar2 = *(undefined8 **)(lVar9 + 8);
    *puVar2 = plVar10 + -2;
    plVar10[-2] = lVar9;
    plVar10[-1] = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar9 + 8) = plVar10 + -2;
    uVar14 = _DAT_23eeadea8;
    *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
    plVar10[3] = (longlong)pcVar18;
    plVar11 = (longlong *)FUN_23e8d7870(param_1,uVar14);
    *(undefined4 *)(plVar3 + 5) = 0x181;
    plStack_168 = (longlong *)FUN_23a334c60(param_1,plVar8,plVar10,plVar11);
    lVar9 = *plVar8;
    *plVar8 = lVar9 + -1;
    if (lVar9 + -1 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (plStack_168 == (longlong *)0x0) {
      pcVar19 = *(code **)(param_1 + 0x70);
      plVar8 = *(longlong **)(param_1 + 0x60);
      pcVar12 = *(code **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_128 = (longlong *)0x0;
      uVar20 = 0x181;
      plStack_138 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      plStack_148 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e2cd3e2;
    }
    lVar9 = FUN_23e8f6a70();
    if (lVar9 == 0) {
      uVar20 = 0x183;
      FUN_23e915740(param_1,&plStack_d8,DAT_23eeadcf8);
      plStack_128 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      plStack_148 = (longlong *)0x0;
      pcVar19 = pcStack_c8;
      plVar8 = plStack_d8;
      pcVar12 = pcStack_d0;
      goto LAB_23e2cd3e2;
    }
    plVar10 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eeadd00);
    plVar8 = _DAT_23eeadeb0;
    if (plVar10 == (longlong *)0x0) {
      pcVar19 = *(code **)(param_1 + 0x70);
      plVar8 = *(longlong **)(param_1 + 0x60);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar20 = 0x183;
      plStack_128 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      plStack_148 = (longlong *)0x0;
      pcVar12 = *(code **)(param_1 + 0x68);
      goto LAB_23e2cd3e2;
    }
    lVar9 = *(longlong *)(param_1 + 0x10);
    plVar11 = *(longlong **)(lVar9 + 0xe20);
    if (plVar11 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar13 = plVar11[3];
      *(int *)(lVar9 + 0xebc) = *(int *)(lVar9 + 0xebc) + -1;
      *(longlong *)(lVar9 + 0xe20) = lVar13;
      *plVar11 = 1;
    }
    plVar11[4] = 0;
    lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar21 + 0x1f8) + 0x10) + 0x2e8);
    lVar13 = plVar11[-1];
    puVar2 = *(undefined8 **)(lVar9 + 8);
    *puVar2 = plVar11 + -2;
    plVar11[-2] = lVar9;
    plVar11[-1] = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar9 + 8) = plVar11 + -2;
    uVar14 = _DAT_23eeadeb8;
    *plVar8 = *plVar8 + 1;
    plVar11[3] = (longlong)plVar8;
    pcVar12 = (code *)FUN_23e8bc2f0(plStack_168,uVar14);
    pcVar19 = DAT_23ed6cd28;
    if (pcVar12 == (code *)0x0) {
LAB_23e2ced8e:
      plVar8 = *(longlong **)(param_1 + 0x60);
      pcVar12 = *(code **)(param_1 + 0x68);
      pcVar19 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      lVar9 = *plVar10;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar10 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      plStack_128 = (longlong *)0x0;
      uVar20 = 0x183;
      plStack_138 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      plStack_148 = (longlong *)0x0;
      goto LAB_23e2cd3e2;
    }
    plVar8 = (longlong *)*unaff_R14;
    if (plVar8 == (longlong *)0x0) {
      plVar8 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar8 != (longlong *)0x0) {
        *plVar8 = *plVar8 + 1;
        *unaff_R14 = plVar8;
        goto LAB_23e2cccb2;
      }
LAB_23e2cea10:
      do {
        PyErr_PrintEx(0,0);
        Py_Exit(1);
LAB_23e2cea28:
        plVar8 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      } while (plVar8 == (longlong *)0x0);
      *plVar8 = *plVar8 + 1;
      *unaff_R14 = plVar8;
      goto LAB_23e2cc80c;
    }
LAB_23e2cccb2:
    pcStack_80 = pcVar19;
    pcStack_88 = pcVar12;
    lVar9 = FUN_23e94ed00(param_1,plVar8,unaff_R13);
    *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
    if (*(longlong *)pcVar12 == 0) {
      (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
    }
    if (lVar9 == 0) goto LAB_23e2ced8e;
    plVar11[4] = lVar9;
    plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar11);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (plVar8 == (longlong *)0x0) {
      plVar8 = *(longlong **)(param_1 + 0x60);
      pcVar12 = *(code **)(param_1 + 0x68);
      pcVar19 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      lVar9 = *plVar10;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar10 = lVar9 + -1;
      plStack_140 = (longlong *)0x0;
      if (lVar9 + -1 == 0) {
        uVar20 = 0x183;
        FUN_23a334bc0(plVar10);
        plStack_128 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        plStack_148 = (longlong *)0x0;
      }
      else {
        uVar20 = 0x183;
        plStack_128 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        plStack_148 = (longlong *)0x0;
      }
    }
    else {
      *(undefined4 *)(plVar3 + 5) = 0x183;
      plVar11 = (longlong *)FUN_23e914090(param_1,plVar10,plVar8);
      lVar9 = *plVar10;
      *plVar10 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      lVar9 = *plVar8;
      *plVar8 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (plVar11 == (longlong *)0x0) {
        plVar8 = *(longlong **)(param_1 + 0x60);
        pcVar19 = *(code **)(param_1 + 0x70);
        plStack_128 = (longlong *)0x0;
        uVar20 = 0x183;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_140 = (longlong *)0x0;
        plStack_148 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plStack_138 = (longlong *)0x0;
        pcVar12 = *(code **)(param_1 + 0x68);
      }
      else {
        lVar9 = *plVar11;
        *plVar11 = lVar9 + -1;
        if (lVar9 + -1 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        plVar8 = (longlong *)FUN_23e8bc2f0(plStack_168,_DAT_23eeadeb8);
        if (plVar8 == (longlong *)0x0) {
          plVar8 = *(longlong **)(param_1 + 0x60);
          pcVar19 = *(code **)(param_1 + 0x70);
          plStack_128 = (longlong *)0x0;
          uVar20 = 0x185;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plStack_138 = (longlong *)0x0;
          plStack_140 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plStack_148 = (longlong *)0x0;
          pcVar12 = *(code **)(param_1 + 0x68);
        }
        else {
          iVar7 = FUN_23e97a530(plVar8,_DAT_23eeadec0);
          lVar9 = *plVar8;
          *plVar8 = lVar9 + -1;
          if (lVar9 + -1 == 0) {
            FUN_23a334bc0(plVar8);
          }
          plVar8 = _DAT_23eeadef0;
          if (iVar7 == -1) {
            pcVar19 = *(code **)(param_1 + 0x70);
            plVar8 = *(longlong **)(param_1 + 0x60);
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar20 = 0x185;
            plStack_128 = (longlong *)0x0;
            plStack_138 = (longlong *)0x0;
            plStack_140 = (longlong *)0x0;
            plStack_148 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcVar12 = *(code **)(param_1 + 0x68);
          }
          else {
            if (iVar7 != 1) {
              lVar9 = *(longlong *)(param_1 + 0x10);
              plVar10 = *(longlong **)(lVar9 + 0xe20);
              if (plVar10 == (longlong *)0x0) {
                plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
              }
              else {
                lVar13 = plVar10[3];
                *(int *)(lVar9 + 0xebc) = *(int *)(lVar9 + 0xebc) + -1;
                *(longlong *)(lVar9 + 0xe20) = lVar13;
                *plVar10 = 1;
              }
              plVar10[4] = 0;
              lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar21 + 0x1f8) + 0x10) + 0x2e8);
              lVar13 = plVar10[-1];
              puVar2 = *(undefined8 **)(lVar9 + 8);
              *puVar2 = plVar10 + -2;
              plVar10[-2] = lVar9;
              plVar10[-1] = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar2;
              *(longlong **)(lVar9 + 8) = plVar10 + -2;
              uVar14 = _DAT_23eeadeb8;
              *plVar8 = *plVar8 + 1;
              plVar10[3] = (longlong)plVar8;
              plVar8 = (longlong *)FUN_23e8bc2f0(plStack_168,uVar14);
              if (plVar8 != (longlong *)0x0) {
                lVar9 = FUN_23e94f9d0(param_1,plVar8,DAT_23ed6cd28);
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  FUN_23a334bc0(plVar8);
                }
                if (lVar9 != 0) {
                  plVar10[4] = lVar9;
                  plStack_128 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar10);
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    FUN_23a334bc0(plVar10);
                  }
                  if (plStack_128 == (longlong *)0x0) {
                    plVar8 = *(longlong **)(param_1 + 0x60);
                    pcVar19 = *(code **)(param_1 + 0x70);
                    plStack_138 = (longlong *)0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plStack_140 = (longlong *)0x0;
                    plStack_148 = (longlong *)0x0;
                    uVar20 = 0x18e;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    pcVar12 = *(code **)(param_1 + 0x68);
                  }
                  else {
                    lVar9 = FUN_23e8f6a70();
                    if (lVar9 == 0) {
                      uVar20 = 399;
                      FUN_23e915740(param_1,&plStack_d8,DAT_23eeadcf8);
                      plStack_138 = (longlong *)0x0;
                      plStack_140 = (longlong *)0x0;
                      plStack_148 = (longlong *)0x0;
                      pcVar19 = pcStack_c8;
                      plVar8 = plStack_d8;
                      pcVar12 = pcStack_d0;
                    }
                    else {
                      *(undefined4 *)(plVar3 + 5) = 399;
                      plVar8 = (longlong *)FUN_23e915840(param_1,lVar9,_DAT_23eeadef8);
                      if (plVar8 == (longlong *)0x0) {
                        plVar8 = *(longlong **)(param_1 + 0x60);
                        pcVar19 = *(code **)(param_1 + 0x70);
                        plStack_138 = (longlong *)0x0;
                        uVar20 = 399;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        plStack_140 = (longlong *)0x0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        plStack_148 = (longlong *)0x0;
                        pcVar12 = *(code **)(param_1 + 0x68);
                      }
                      else {
                        lVar9 = *plVar8;
                        *plVar8 = lVar9 + -1;
                        if (lVar9 + -1 == 0) {
                          FUN_23a334bc0(plVar8);
                        }
                        plVar8 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eead9f0);
                        if (plVar8 == (longlong *)0x0) {
                          plVar8 = *(longlong **)(param_1 + 0x60);
                          pcVar19 = *(code **)(param_1 + 0x70);
                          plStack_138 = (longlong *)0x0;
                          uVar20 = 400;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          plStack_140 = (longlong *)0x0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          plStack_148 = (longlong *)0x0;
                          pcVar12 = *(code **)(param_1 + 0x68);
                        }
                        else {
                          plVar10 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eeada60);
                          lVar9 = *plVar8;
                          *plVar8 = lVar9 + -1;
                          if (lVar9 + -1 == 0) {
                            FUN_23a334bc0(plVar8);
                          }
                          plVar8 = _DAT_23eeadf00;
                          if (plVar10 != (longlong *)0x0) {
                            plVar11 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),5);
                            *plVar8 = *plVar8 + 1;
                            plVar11[3] = (longlong)plVar8;
                            lVar9 = FUN_23e8f6920();
                            if (lVar9 == 0) {
                              FUN_23e915740(param_1,&plStack_d8,DAT_23eeadd50);
                              pcVar19 = pcStack_c8;
                              plVar8 = plStack_d8;
                              pcVar12 = pcStack_d0;
                            }
                            else {
                              lVar9 = FUN_23e94f9d0(param_1,lVar9);
                              if (lVar9 != 0) {
                                plVar11[4] = lVar9;
                                plVar8 = _DAT_23eeadf08;
                                *_DAT_23eeadf08 = *_DAT_23eeadf08 + 1;
                                plVar11[5] = (longlong)plVar8;
                                *plStack_128 = *plStack_128 + 1;
                                plVar11[6] = (longlong)plStack_128;
                                plVar8 = _DAT_23eeadf10;
                                *_DAT_23eeadf10 = *_DAT_23eeadf10 + 1;
                                plVar11[7] = (longlong)plVar8;
                                plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28);
                                *plVar11 = *plVar11 + -1;
                                if (*plVar11 == 0) {
                                  FUN_23a334bc0(plVar11);
                                }
                                if (plVar8 == (longlong *)0x0) {
                                  pcVar19 = *(code **)(param_1 + 0x70);
                                  plVar8 = *(longlong **)(param_1 + 0x60);
                                  pcVar12 = *(code **)(param_1 + 0x68);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  lVar9 = *plVar10;
                                  *plVar10 = lVar9 + -1;
                                  plStack_148 = (longlong *)0x0;
                                  if (lVar9 + -1 == 0) {
                                    uVar20 = 400;
                                    FUN_23a334bc0(plVar10);
                                    plStack_138 = (longlong *)0x0;
                                    plStack_140 = (longlong *)0x0;
                                  }
                                  else {
                                    uVar20 = 400;
                                    plStack_138 = (longlong *)0x0;
                                    plStack_140 = (longlong *)0x0;
                                  }
                                  goto LAB_23e2cd3e2;
                                }
                                *(undefined4 *)(plVar3 + 5) = 400;
                                plVar11 = (longlong *)FUN_23e914090(param_1,plVar10,plVar8);
                                lVar9 = *plVar10;
                                *plVar10 = lVar9 + -1;
                                if (lVar9 + -1 == 0) {
                                  FUN_23a334bc0();
                                }
                                lVar9 = *plVar8;
                                *plVar8 = lVar9 + -1;
                                if (lVar9 + -1 == 0) {
                                  FUN_23a334bc0();
                                }
                                if (plVar11 != (longlong *)0x0) {
                                  lVar9 = *plVar11;
                                  *plVar11 = lVar9 + -1;
                                  if (lVar9 + -1 == 0) {
                                    FUN_23a334bc0(plVar11);
                                    plStack_138 = (longlong *)0x0;
                                    plStack_140 = (longlong *)0x0;
                                    plStack_148 = (longlong *)0x0;
                                  }
                                  else {
                                    plStack_138 = (longlong *)0x0;
                                    plStack_140 = (longlong *)0x0;
                                    plStack_148 = (longlong *)0x0;
                                  }
                                  goto LAB_23e2cd190;
                                }
                                plVar8 = *(longlong **)(param_1 + 0x60);
                                pcVar19 = *(code **)(param_1 + 0x70);
                                plStack_138 = (longlong *)0x0;
                                uVar20 = 400;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_148 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plStack_140 = (longlong *)0x0;
                                pcVar12 = *(code **)(param_1 + 0x68);
                                goto LAB_23e2cd3e2;
                              }
                              pcVar19 = *(code **)(param_1 + 0x70);
                              plVar8 = *(longlong **)(param_1 + 0x60);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              pcVar12 = *(code **)(param_1 + 0x68);
                            }
                            lVar9 = *plVar10;
                            *plVar10 = lVar9 + -1;
                            if (lVar9 + -1 == 0) {
                              FUN_23a334bc0(plVar10);
                            }
                            *plVar11 = *plVar11 + -1;
                            if (*plVar11 == 0) {
                              uVar20 = 400;
                              FUN_23a334bc0();
                              plStack_138 = (longlong *)0x0;
                              plStack_140 = (longlong *)0x0;
                              plStack_148 = (longlong *)0x0;
                            }
                            else {
                              uVar20 = 400;
                              plStack_138 = (longlong *)0x0;
                              plStack_140 = (longlong *)0x0;
                              plStack_148 = (longlong *)0x0;
                            }
                            goto LAB_23e2cd3e2;
                          }
                          plVar8 = *(longlong **)(param_1 + 0x60);
                          pcVar19 = *(code **)(param_1 + 0x70);
                          plStack_140 = (longlong *)0x0;
                          uVar20 = 400;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          plStack_148 = (longlong *)0x0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          plStack_138 = (longlong *)0x0;
                          pcVar12 = *(code **)(param_1 + 0x68);
                        }
                      }
                    }
                  }
                  goto LAB_23e2cd3e2;
                }
              }
              plVar8 = *(longlong **)(param_1 + 0x60);
              pcVar12 = *(code **)(param_1 + 0x68);
              pcVar19 = *(code **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                FUN_23a334bc0(plVar10);
              }
              uVar20 = 0x18e;
              plStack_128 = (longlong *)0x0;
              plStack_138 = (longlong *)0x0;
              plStack_140 = (longlong *)0x0;
              plStack_148 = (longlong *)0x0;
              goto LAB_23e2cd3e2;
            }
            *(undefined4 *)(plVar3 + 5) = 0x186;
            plStack_148 = (longlong *)FUN_23e91bfe0(param_1,plStack_168,_DAT_23eeadec8);
            if (plStack_148 == (longlong *)0x0) {
              plVar8 = *(longlong **)(param_1 + 0x60);
              pcVar19 = *(code **)(param_1 + 0x70);
              plStack_128 = (longlong *)0x0;
              uVar20 = 0x186;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plStack_138 = (longlong *)0x0;
              plStack_140 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pcVar12 = *(code **)(param_1 + 0x68);
            }
            else {
              plVar8 = (longlong *)FUN_23e8bc2f0(plStack_148,DAT_23ed6ce40);
              if (plVar8 == (longlong *)0x0) {
                plVar8 = *(longlong **)(param_1 + 0x60);
                pcVar19 = *(code **)(param_1 + 0x70);
                plStack_128 = (longlong *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                plStack_140 = (longlong *)0x0;
                uVar20 = 0x187;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plStack_138 = (longlong *)0x0;
                pcVar12 = *(code **)(param_1 + 0x68);
              }
              else {
                *(undefined4 *)(plVar3 + 5) = 0x187;
                plStack_140 = (longlong *)FUN_23e9557e0(param_1,plVar8);
                lVar9 = *plVar8;
                *plVar8 = lVar9 + -1;
                if (lVar9 + -1 == 0) {
                  FUN_23a334bc0(plVar8);
                }
                if (plStack_140 == (longlong *)0x0) {
                  plVar8 = *(longlong **)(param_1 + 0x60);
                  pcVar19 = *(code **)(param_1 + 0x70);
                  plStack_128 = (longlong *)0x0;
                  uVar20 = 0x187;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  plStack_138 = (longlong *)0x0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  pcVar12 = *(code **)(param_1 + 0x68);
                }
                else {
                  lVar9 = FUN_23e8f6a70();
                  if (lVar9 == 0) {
                    uVar20 = 0x188;
                    FUN_23e915740(param_1,&plStack_d8,DAT_23eeadcf8);
                    plStack_128 = (longlong *)0x0;
                    plStack_138 = (longlong *)0x0;
                    pcVar19 = pcStack_c8;
                    plVar8 = plStack_d8;
                    pcVar12 = pcStack_d0;
                  }
                  else {
                    plVar10 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eeadd00);
                    plVar8 = _DAT_23eeaded8;
                    if (plVar10 == (longlong *)0x0) {
                      plVar8 = *(longlong **)(param_1 + 0x60);
                      pcVar19 = *(code **)(param_1 + 0x70);
                      plStack_138 = (longlong *)0x0;
                      uVar20 = 0x188;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plStack_128 = (longlong *)0x0;
                      pcVar12 = *(code **)(param_1 + 0x68);
                    }
                    else {
                      plVar11 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
                      *plVar8 = *plVar8 + 1;
                      plVar11[3] = (longlong)plVar8;
                      plVar8 = (longlong *)FUN_23e8bd600(param_1,plStack_140);
                      if (plVar8 != (longlong *)0x0) {
                        lVar9 = FUN_23e94f9d0(param_1,plVar8);
                        *plVar8 = *plVar8 + -1;
                        if (*plVar8 == 0) {
                          FUN_23a334bc0(plVar8);
                        }
                        plVar8 = _DAT_23eeadee0;
                        if (lVar9 != 0) {
                          plVar11[4] = lVar9;
                          *plVar8 = *plVar8 + 1;
                          plVar11[5] = (longlong)plVar8;
                          plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar11);
                          *plVar11 = *plVar11 + -1;
                          if (*plVar11 == 0) {
                            FUN_23a334bc0();
                          }
                          if (plVar8 == (longlong *)0x0) {
                            plVar8 = *(longlong **)(param_1 + 0x60);
                            pcVar12 = *(code **)(param_1 + 0x68);
                            pcVar19 = *(code **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            lVar9 = *plVar10;
                            *plVar10 = lVar9 + -1;
                            plStack_138 = (longlong *)0x0;
                            if (lVar9 + -1 == 0) {
                              uVar20 = 0x188;
                              FUN_23a334bc0(plVar10);
                              plStack_128 = (longlong *)0x0;
                            }
                            else {
                              uVar20 = 0x188;
                              plStack_128 = (longlong *)0x0;
                            }
                          }
                          else {
                            *(undefined4 *)(plVar3 + 5) = 0x188;
                            plVar11 = (longlong *)FUN_23e914090(param_1,plVar10,plVar8);
                            lVar9 = *plVar10;
                            *plVar10 = lVar9 + -1;
                            if (lVar9 + -1 == 0) {
                              FUN_23a334bc0(plVar10);
                            }
                            lVar9 = *plVar8;
                            *plVar8 = lVar9 + -1;
                            if (lVar9 + -1 == 0) {
                              FUN_23a334bc0(plVar8);
                            }
                            if (plVar11 == (longlong *)0x0) {
                              plVar8 = *(longlong **)(param_1 + 0x60);
                              pcVar19 = *(code **)(param_1 + 0x70);
                              plStack_128 = (longlong *)0x0;
                              uVar20 = 0x188;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              plStack_138 = (longlong *)0x0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              pcVar12 = *(code **)(param_1 + 0x68);
                            }
                            else {
                              *plVar11 = *plVar11 + -1;
                              if (*plVar11 == 0) {
                                FUN_23a334bc0(plVar11);
                              }
                              *(undefined4 *)(plVar3 + 5) = 0x18b;
                              plStack_138 = (longlong *)
                                            FUN_23e915840(param_1,param_3,DAT_23eeadee8,plStack_140)
                              ;
                              if (plStack_138 == (longlong *)0x0) {
                                plVar8 = *(longlong **)(param_1 + 0x60);
                                pcVar19 = *(code **)(param_1 + 0x70);
                                plStack_128 = (longlong *)0x0;
                                uVar20 = 0x18b;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                pcVar12 = *(code **)(param_1 + 0x68);
                              }
                              else {
                                plVar8 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eead9f0);
                                if (plVar8 == (longlong *)0x0) {
                                  plVar8 = *(longlong **)(param_1 + 0x60);
                                  pcVar19 = *(code **)(param_1 + 0x70);
                                  plStack_128 = (longlong *)0x0;
                                  uVar20 = 0x18c;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  pcVar12 = *(code **)(param_1 + 0x68);
                                  goto LAB_23e2cd3e2;
                                }
                                *(undefined4 *)(plVar3 + 5) = 0x18c;
                                plVar10 = (longlong *)
                                          FUN_23e915840(param_1,plVar8,_DAT_23eeada60,plStack_138);
                                *plVar8 = *plVar8 + -1;
                                if (*plVar8 == 0) {
                                  FUN_23a334bc0(plVar8);
                                }
                                if (plVar10 != (longlong *)0x0) {
                                  lVar9 = *plVar10;
                                  *plVar10 = lVar9 + -1;
                                  if (lVar9 + -1 == 0) {
                                    FUN_23a334bc0(plVar10);
                                    plStack_128 = (longlong *)0x0;
                                  }
                                  else {
                                    plStack_128 = (longlong *)0x0;
                                  }
                                  goto LAB_23e2cd190;
                                }
                                plVar8 = *(longlong **)(param_1 + 0x60);
                                pcVar19 = *(code **)(param_1 + 0x70);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                uVar20 = 0x18c;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_128 = (longlong *)0x0;
                                pcVar12 = *(code **)(param_1 + 0x68);
                              }
                            }
                          }
                          goto LAB_23e2cd3e2;
                        }
                      }
                      plVar8 = *(longlong **)(param_1 + 0x60);
                      pcVar12 = *(code **)(param_1 + 0x68);
                      pcVar19 = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      lVar9 = *plVar10;
                      *plVar10 = lVar9 + -1;
                      if (lVar9 + -1 == 0) {
                        FUN_23a334bc0(plVar10);
                      }
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        uVar20 = 0x188;
                        FUN_23a334bc0(plVar11);
                        plStack_128 = (longlong *)0x0;
                        plStack_138 = (longlong *)0x0;
                      }
                      else {
                        uVar20 = 0x188;
                        plStack_128 = (longlong *)0x0;
                        plStack_138 = (longlong *)0x0;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_23e2cd3e2:
  plVar10 = *(longlong **)(param_1 + 0x138);
  auStack_f8._8_8_ = pcVar12;
  auStack_f8._0_8_ = plVar8;
  if (plVar10 != (longlong *)0x0) {
    *plVar10 = *plVar10 + 1;
  }
  pcVar12 = DAT_23ed6a4f8;
  apcStack_e8[0] = pcVar19;
  if (pcVar19 == (code *)0x0) {
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar12 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar19 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar19;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar12 + 0x18) = plVar3;
    *(longlong *)(pcVar12 + 0x10) = 0;
    *plVar3 = *plVar3 + 1;
    lVar9 = *(longlong *)(pcStack_160 + 0x1f8);
    *(undefined4 *)(pcVar12 + 0x20) = 0xffffffff;
    lVar9 = *(longlong *)(lVar9 + 0x10);
    *(undefined4 *)(pcVar12 + 0x24) = uVar20;
    lVar9 = *(longlong *)(lVar9 + 0x2e8);
    lVar13 = *(longlong *)(pcVar12 + -8);
    puVar2 = *(undefined8 **)(lVar9 + 8);
    *puVar2 = pcVar12 + -0x10;
    *(longlong *)(pcVar12 + -0x10) = lVar9;
    *(ulonglong *)(pcVar12 + -8) = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar2;
    *(code **)(lVar9 + 8) = pcVar12 + -0x10;
    if ((apcStack_e8[0] != (code *)0x0) &&
       (*(longlong *)apcStack_e8[0] = *(longlong *)apcStack_e8[0] + -1,
       *(longlong *)apcStack_e8[0] == 0)) {
      (**(code **)(*(longlong *)(apcStack_e8[0] + 8) + 0x30))(apcStack_e8[0]);
    }
  }
  else {
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar12 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar21 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar21;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar12 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar9 = *(longlong *)(pcStack_160 + 0x1f8);
    *(undefined4 *)(pcVar12 + 0x24) = uVar20;
    *(undefined4 *)(pcVar12 + 0x20) = 0xffffffff;
    lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
    lVar13 = *(longlong *)(pcVar12 + -8);
    puVar2 = *(undefined8 **)(lVar9 + 8);
    *puVar2 = pcVar12 + -0x10;
    *(longlong *)(pcVar12 + -0x10) = lVar9;
    *(ulonglong *)(pcVar12 + -8) = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar2;
    *(code **)(lVar9 + 8) = pcVar12 + -0x10;
    *(code **)(pcVar12 + 0x10) = pcVar19;
    *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
    if ((apcStack_e8[0] != (code *)0x0) &&
       (*(longlong *)apcStack_e8[0] = *(longlong *)apcStack_e8[0] + -1,
       *(longlong *)apcStack_e8[0] == 0)) {
      (**(code **)(*(longlong *)(apcStack_e8[0] + 8) + 0x30))();
    }
  }
  apcStack_e8[0] = pcVar12;
  if (((code *)auStack_f8._0_8_ != pcVar17) && ((code *)auStack_f8._0_8_ != (code *)0x0)) {
    FUN_23e91b1b0(param_1,auStack_f8,auStack_f8 + 8,apcStack_e8);
  }
  plVar8 = *(longlong **)(auStack_f8._8_8_ + 0x28);
  if (apcStack_e8[0] == pcVar17) {
    pcVar19 = (code *)0x0;
  }
  else {
    pcVar19 = apcStack_e8[0];
    if (apcStack_e8[0] != (code *)0x0) {
      *(longlong *)apcStack_e8[0] = *(longlong *)apcStack_e8[0] + 1;
    }
  }
  *(code **)(auStack_f8._8_8_ + 0x28) = pcVar19;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))();
  }
  plVar8 = *(longlong **)(param_1 + 0x138);
  *(undefined8 *)(param_1 + 0x138) = auStack_f8._8_8_;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))();
  }
  *(longlong *)auStack_f8._0_8_ = *(longlong *)auStack_f8._0_8_ + -1;
  if (*(longlong *)auStack_f8._0_8_ == 0) {
    (**(code **)(*(longlong *)(auStack_f8._0_8_ + 8) + 0x30))();
  }
  if ((apcStack_e8[0] != (code *)0x0) &&
     (*(longlong *)apcStack_e8[0] = *(longlong *)apcStack_e8[0] + -1,
     *(longlong *)apcStack_e8[0] == 0)) {
    (**(code **)(*(longlong *)(apcStack_e8[0] + 8) + 0x30))();
  }
  pcVar21 = *(code **)(param_1 + 0x138);
  apcStack_e8[0] = (code *)0x0;
  auStack_f8 = (undefined1  [16])0x0;
  pcVar19 = *(code **)PyExc_Exception_exref;
  pcVar12 = *(code **)(pcVar21 + 8);
  if ((*(uint *)(*(longlong *)(pcVar19 + 8) + 0xa8) & 0x4000000) == 0) {
    if (((int)*(uint *)(*(longlong *)(pcVar19 + 8) + 0xa8) < 0) &&
       (((byte)pcVar19[0xab] & 0x40) != 0)) {
      pcVar4 = *(code **)(pcVar12 + 8);
      if ((*(uint *)(pcVar4 + 0xa8) & 0x40000000) == 0) {
        pcVar5 = pcVar12;
        if (((int)*(uint *)(pcVar4 + 0xa8) < 0) && (((byte)pcVar12[0xab] & 0x40) != 0))
        goto LAB_23e2cdfb2;
      }
      else {
        pcVar12 = pcVar4;
        pcVar5 = pcVar4;
        if (*(int *)(*(longlong *)(pcVar4 + 8) + 0xa8) < 0) {
LAB_23e2cdfb2:
          lVar9 = *(longlong *)(pcVar12 + 0x158);
          if (lVar9 != 0) {
            if (*(longlong *)(lVar9 + 0x10) < 1) goto LAB_23e2cd648;
            lVar13 = 0;
            while (pcVar19 != *(code **)(lVar9 + 0x18 + lVar13 * 8)) {
              lVar13 = lVar13 + 1;
              if (*(longlong *)(lVar9 + 0x10) == lVar13) goto LAB_23e2cd648;
            }
            goto LAB_23e2cda4d;
          }
          do {
            if (pcVar19 == pcVar12) goto LAB_23e2cda4d;
            pcVar12 = *(code **)(pcVar12 + 0x100);
            pcVar5 = PyBaseObject_Type_exref;
          } while (pcVar12 != (code *)0x0);
        }
      }
      if (pcVar19 != pcVar5) goto LAB_23e2cd648;
    }
    else {
LAB_23e2cd9e0:
      plVar8 = *(longlong **)PyExc_TypeError_exref;
      uVar14 = PyUnicode_FromString
                         ("catching classes that do not inherit from BaseException is not allowed");
      plVar11 = *(longlong **)(param_1 + 0x60);
      plVar15 = *(longlong **)(param_1 + 0x68);
      plVar16 = *(longlong **)(param_1 + 0x70);
      *(longlong **)(param_1 + 0x60) = plVar8;
      *plVar8 = *plVar8 + 1;
      *(undefined8 *)(param_1 + 0x68) = uVar14;
      *(undefined8 *)(param_1 + 0x70) = 0;
      if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
        (**(code **)(plVar11[1] + 0x30))();
      }
      if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      if ((plVar16 == (longlong *)0x0) || (*plVar16 = *plVar16 + -1, *plVar16 != 0))
      goto LAB_23e2cda46;
      (**(code **)(plVar16[1] + 0x30))(plVar16);
      pcVar21 = *(code **)(param_1 + 0x138);
    }
  }
  else {
    lVar9 = *(longlong *)(pcVar19 + 0x10);
    if (lVar9 < 1) {
LAB_23e2cd648:
      if ((pcVar21 == (code *)0x0) || (pcVar21 == pcVar17)) {
        plVar8 = *(longlong **)PyExc_RuntimeError_exref;
        pcStack_118 = (code *)PyUnicode_FromString("No active exception to reraise");
        pcVar21 = *(code **)(param_1 + 0x138);
        *plVar8 = *plVar8 + 1;
        *(longlong **)(param_1 + 0x138) = plVar10;
        if ((pcVar21 == (code *)0x0) ||
           (*(longlong *)pcVar21 = *(longlong *)pcVar21 + -1, *(longlong *)pcVar21 != 0)) {
          iVar7 = 0x179;
          goto LAB_23e2ce308;
        }
        iVar7 = 0x179;
        pcVar17 = (code *)0x0;
        goto LAB_23e2ce2ec;
      }
      plVar8 = *(longlong **)(pcVar21 + 8);
      pcVar17 = *(code **)(pcVar21 + 0x28);
      *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
      *plVar8 = *plVar8 + 1;
      pcStack_118 = pcVar21;
      if (pcVar17 == (code *)0x0) {
        *(longlong **)(param_1 + 0x138) = plVar10;
        *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
        if (*(longlong *)pcVar21 != 0) goto LAB_23e2ce304;
LAB_23e2ce2e1:
        iVar7 = 0;
        goto LAB_23e2ce2ec;
      }
      *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
      if (plVar3 == *(longlong **)(pcVar17 + 0x18)) {
        *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar17 + 0x24);
        *(longlong **)(param_1 + 0x138) = plVar10;
        *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
        if (*(longlong *)pcVar21 == 0) goto LAB_23e2ce2e1;
      }
      else {
        *(longlong **)(param_1 + 0x138) = plVar10;
        *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
        if (*(longlong *)pcVar21 != 0) {
          if (plVar3 == *(longlong **)(pcVar17 + 0x18)) goto LAB_23e2cd780;
          goto LAB_23e2cd6d2;
        }
        (*(code *)plVar8[6])(pcVar21);
      }
      iVar7 = 0;
      goto LAB_23e2cd6c0;
    }
    lVar13 = 0;
    do {
      if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar19 + lVar13 * 8 + 0x18) + 8) + 0xa8)) ||
         ((*(byte *)(*(longlong *)(pcVar19 + lVar13 * 8 + 0x18) + 0xab) & 0x40) == 0))
      goto LAB_23e2cd9e0;
      lVar13 = lVar13 + 1;
    } while (lVar9 != lVar13);
    lVar13 = 0;
    while (iVar7 = FUN_23a35ebd0(param_1,pcVar12,*(undefined8 *)(pcVar19 + lVar13 * 8 + 0x18)),
          iVar7 == 0) {
      lVar13 = lVar13 + 1;
      if (lVar9 == lVar13) {
        pcVar21 = *(code **)(param_1 + 0x138);
        goto LAB_23e2cd648;
      }
    }
LAB_23e2cda46:
    pcVar21 = *(code **)(param_1 + 0x138);
  }
LAB_23e2cda4d:
  *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
  lVar9 = FUN_23e8f6a70();
  if (lVar9 == 0) {
    iVar7 = 0x193;
    FUN_23e915740(param_1,&plStack_d8,DAT_23eeadcf8);
    pcStack_118 = pcStack_d0;
    pcVar17 = pcStack_c8;
    plVar8 = plStack_d8;
    goto LAB_23e2ce470;
  }
  plVar11 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eeade28);
  unaff_R13 = _DAT_23eeadf18;
  if (plVar11 != (longlong *)0x0) {
    lVar9 = *(longlong *)(param_1 + 0x10);
    plVar15 = *(longlong **)(lVar9 + 0xe20);
    if (plVar15 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar13 = plVar15[3];
      *(int *)(lVar9 + 0xebc) = *(int *)(lVar9 + 0xebc) + -1;
      *(longlong *)(lVar9 + 0xe20) = lVar13;
      *plVar15 = 1;
    }
    unaff_R14 = &DAT_23ed6a4c0;
    plVar15[4] = 0;
    lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_160 + 0x1f8) + 0x10) + 0x2e8);
    lVar13 = plVar15[-1];
    puVar2 = *(undefined8 **)(lVar9 + 8);
    *puVar2 = plVar15 + -2;
    plVar15[-2] = lVar9;
    plVar15[-1] = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar9 + 8) = plVar15 + -2;
    plVar8 = DAT_23ed6a4c0;
    *unaff_R13 = *unaff_R13 + 1;
    plVar15[3] = (longlong)unaff_R13;
    pcVar19 = DAT_23ed6cd28;
    if (plVar8 == (longlong *)0x0) {
      plVar8 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      pcVar12 = pcVar21;
      if (plVar8 == (longlong *)0x0) goto LAB_23e2cea10;
      *plVar8 = *plVar8 + 1;
      DAT_23ed6a4c0 = plVar8;
    }
    unaff_R13 = &pcStack_88;
    pcStack_80 = pcVar19;
    pcStack_88 = pcVar21;
    lVar9 = FUN_23e94ed00(param_1,plVar8,unaff_R13);
    if (lVar9 == 0) {
      pcStack_118 = *(code **)(param_1 + 0x68);
      plVar8 = *(longlong **)(param_1 + 0x60);
      pcVar17 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      *plVar15 = *plVar15 + -1;
      iVar7 = 0x193;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      goto LAB_23e2ce470;
    }
    plVar15[4] = lVar9;
    lVar9 = PyUnicode_Join(DAT_23ed6cd28,plVar15);
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    if (lVar9 == 0) {
      pcStack_118 = *(code **)(param_1 + 0x68);
      plVar8 = *(longlong **)(param_1 + 0x60);
      iVar7 = 0x193;
      pcVar17 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar11 = *plVar11 + -1;
      lVar9 = *plVar11;
      goto joined_r0x00023e2ce857;
    }
    lVar13 = *(longlong *)(param_1 + 0x10);
    plVar8 = *(longlong **)(lVar13 + 0xe18);
    if (plVar8 == (longlong *)0x0) {
      plVar8 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,1);
    }
    else {
      lVar1 = plVar8[3];
      *(int *)(lVar13 + 0xeb8) = *(int *)(lVar13 + 0xeb8) + -1;
      *(longlong *)(lVar13 + 0xe18) = lVar1;
      *plVar8 = 1;
    }
    lVar13 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_160 + 0x1f8) + 0x10) + 0x2e8);
    lVar1 = plVar8[-1];
    puVar2 = *(undefined8 **)(lVar13 + 8);
    *puVar2 = plVar8 + -2;
    plVar8[-2] = lVar13;
    plVar8[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar13 + 8) = plVar8 + -2;
    uVar14 = _DAT_23eeade60;
    plVar8[3] = lVar9;
    plVar15 = (longlong *)FUN_23e8d7870(param_1,uVar14);
    *(undefined4 *)(plVar3 + 5) = 0x193;
    plVar16 = (longlong *)FUN_23a334c60(param_1,plVar11,plVar8,plVar15);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    if (plVar16 != (longlong *)0x0) goto code_r0x00023e2cdcd9;
  }
  pcStack_118 = *(code **)(param_1 + 0x68);
  plVar8 = *(longlong **)(param_1 + 0x60);
  iVar7 = 0x193;
  pcVar17 = *(code **)(param_1 + 0x70);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  goto LAB_23e2ce470;
code_r0x00023e2cdcd9:
  *plVar16 = *plVar16 + -1;
  if (*plVar16 == 0) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  plVar8 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eead9f0);
  if (plVar8 == (longlong *)0x0) goto LAB_23e2ce670;
  plVar15 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eeada60);
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar8 = _DAT_23eeadf00;
  if (plVar15 == (longlong *)0x0) goto LAB_23e2ce670;
  lVar9 = *(longlong *)(param_1 + 0x10);
  plVar11 = *(longlong **)(lVar9 + 0xe38);
  if (plVar11 == (longlong *)0x0) {
    plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,5);
  }
  else {
    lVar13 = plVar11[3];
    *(int *)(lVar9 + 0xec8) = *(int *)(lVar9 + 0xec8) + -1;
    *(longlong *)(lVar9 + 0xe38) = lVar13;
    *plVar11 = 1;
  }
  *(undefined1 (*) [16])(plVar11 + 4) = (undefined1  [16])0x0;
  lVar9 = *(longlong *)(pcStack_160 + 0x1f8);
  *(undefined1 (*) [16])(plVar11 + 6) = (undefined1  [16])0x0;
  lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
  lVar13 = plVar11[-1];
  puVar2 = *(undefined8 **)(lVar9 + 8);
  *puVar2 = plVar11 + -2;
  plVar11[-2] = lVar9;
  plVar11[-1] = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar2;
  *(longlong **)(lVar9 + 8) = plVar11 + -2;
  *plVar8 = *plVar8 + 1;
  plVar11[3] = (longlong)plVar8;
  pcVar12 = (code *)FUN_23e8f6530();
  pcVar19 = DAT_23ed6cd28;
  if (pcVar12 == (code *)0x0) {
    FUN_23e915740(param_1,&plStack_d8,DAT_23eeadd28);
    pcStack_118 = pcStack_d0;
    pcVar17 = pcStack_c8;
    plVar8 = plStack_d8;
    goto LAB_23e2ce704;
  }
  if (DAT_23ed6a4c0 == (longlong *)0x0) {
    plVar8 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
    if (plVar8 == (longlong *)0x0) goto LAB_23e2cea10;
    *plVar8 = *plVar8 + 1;
    DAT_23ed6a4c0 = plVar8;
  }
  pcStack_80 = pcVar19;
  pcStack_88 = pcVar12;
  lVar9 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,unaff_R13);
  if (lVar9 == 0) goto LAB_23e2ce6e0;
  plVar11[4] = lVar9;
  plVar8 = _DAT_23eeadf20;
  *_DAT_23eeadf20 = *_DAT_23eeadf20 + 1;
  plVar11[5] = (longlong)plVar8;
  pcVar12 = (code *)FUN_23e8bd350(pcVar21);
  pcVar19 = DAT_23ed6cd28;
  if (pcVar12 == (code *)0x0) goto LAB_23e2ce6e0;
  if (DAT_23ed6a4c0 == (longlong *)0x0) {
    plVar8 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
    if (plVar8 == (longlong *)0x0) goto LAB_23e2cea10;
    *plVar8 = *plVar8 + 1;
    DAT_23ed6a4c0 = plVar8;
  }
  pcStack_80 = pcVar19;
  pcStack_88 = pcVar12;
  lVar9 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,unaff_R13);
  *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
  if (*(longlong *)pcVar12 == 0) {
    (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
  }
  plVar8 = _DAT_23eeadf10;
  if (lVar9 == 0) {
LAB_23e2ce6e0:
    pcStack_118 = *(code **)(param_1 + 0x68);
    pcVar17 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar8 = *(longlong **)(param_1 + 0x60);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e2ce704:
    lVar9 = *plVar15;
    *plVar15 = lVar9 + -1;
    if (lVar9 + -1 == 0) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    *plVar11 = *plVar11 + -1;
    lVar9 = *plVar11;
    iVar7 = 0x194;
joined_r0x00023e2ce857:
    if (lVar9 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
  }
  else {
    plVar11[6] = lVar9;
    *plVar8 = *plVar8 + 1;
    plVar11[7] = (longlong)plVar8;
    plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar11);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (plVar8 == (longlong *)0x0) {
      pcStack_118 = *(code **)(param_1 + 0x68);
      iVar7 = 0x194;
      plVar8 = *(longlong **)(param_1 + 0x60);
      pcVar17 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      lVar9 = *plVar15;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar15 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
    }
    else {
      *(undefined4 *)(plVar3 + 5) = 0x194;
      plVar11 = (longlong *)FUN_23e914090(param_1,plVar15,plVar8);
      lVar9 = *plVar15;
      *plVar15 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (plVar11 != (longlong *)0x0) {
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
        if (*(longlong *)pcVar21 == 0) {
          (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))(pcVar21);
        }
        plVar8 = *(longlong **)(param_1 + 0x138);
        *(longlong **)(param_1 + 0x138) = plVar10;
        if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
          (**(code **)(plVar8[1] + 0x30))();
        }
LAB_23e2cd190:
        lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar8 = *(longlong **)(lVar9 + 0x28);
        plVar3 = (longlong *)plVar8[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
        *(undefined4 *)(plVar8 + 8) = 0xffffffff;
        if (plVar3 != (longlong *)0x0) {
          plVar8[2] = 0;
          *plVar3 = *plVar3 + -1;
          if (*plVar3 == 0) {
            (**(code **)(plVar3[1] + 0x30))();
          }
        }
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        plVar8[0xf] = 0;
        *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
        if ((plStack_130 != (longlong *)0x0) &&
           (lVar9 = *plStack_130, *plStack_130 = lVar9 + -1, lVar9 + -1 == 0)) {
          (**(code **)(plStack_130[1] + 0x30))(plStack_130);
        }
        if ((plStack_158 != (longlong *)0x0) &&
           (lVar9 = *plStack_158, *plStack_158 = lVar9 + -1, lVar9 + -1 == 0)) {
          (**(code **)(plStack_158[1] + 0x30))(plStack_158);
        }
        if ((pcVar18 != (code *)0x0) &&
           (*(longlong *)pcVar18 = *(longlong *)pcVar18 + -1, *(longlong *)pcVar18 == 0)) {
          (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
        }
        if ((plStack_168 != (longlong *)0x0) &&
           (lVar9 = *plStack_168, *plStack_168 = lVar9 + -1, lVar9 + -1 == 0)) {
          (**(code **)(plStack_168[1] + 0x30))(plStack_168);
        }
        if ((plStack_148 != (longlong *)0x0) &&
           (lVar9 = *plStack_148, *plStack_148 = lVar9 + -1, lVar9 + -1 == 0)) {
          (**(code **)(plStack_148[1] + 0x30))(plStack_148);
        }
        if ((plStack_140 != (longlong *)0x0) &&
           (lVar9 = *plStack_140, *plStack_140 = lVar9 + -1, lVar9 + -1 == 0)) {
          (**(code **)(plStack_140[1] + 0x30))(plStack_140);
        }
        if ((plStack_138 != (longlong *)0x0) &&
           (lVar9 = *plStack_138, *plStack_138 = lVar9 + -1, lVar9 + -1 == 0)) {
          (**(code **)(plStack_138[1] + 0x30))(plStack_138);
        }
        if ((plStack_128 != (longlong *)0x0) &&
           (lVar9 = *plStack_128, *plStack_128 = lVar9 + -1, lVar9 + -1 == 0)) {
          (**(code **)(plStack_128[1] + 0x30))(plStack_128);
        }
        lVar9 = *param_3;
        *param_3 = lVar9 + -1;
        if (lVar9 + -1 != 0) {
          return pcVar17;
        }
        (**(code **)(param_3[1] + 0x30))(param_3);
        return pcVar17;
      }
LAB_23e2ce670:
      pcStack_118 = *(code **)(param_1 + 0x68);
      plVar8 = *(longlong **)(param_1 + 0x60);
      iVar7 = 0x194;
      pcVar17 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
    }
  }
LAB_23e2ce470:
  *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
  if (*(longlong *)pcVar21 == 0) {
    (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))(pcVar21);
  }
  pcVar21 = *(code **)(param_1 + 0x138);
  *(longlong **)(param_1 + 0x138) = plVar10;
  if (pcVar21 == (code *)0x0) {
    if (pcVar17 == (code *)0x0) goto LAB_23e2ce308;
    pcVar19 = pcVar17;
    if (plVar3 == *(longlong **)(pcVar17 + 0x18)) goto LAB_23e2cd780;
LAB_23e2cd6d9:
    pcVar17 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar12 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar12;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar17 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar9 = *(longlong *)(pcStack_160 + 0x1f8);
    *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
    *(int *)(pcVar17 + 0x24) = iVar7;
    lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
    lVar13 = *(longlong *)(pcVar17 + -8);
    puVar2 = *(undefined8 **)(lVar9 + 8);
    *puVar2 = pcVar17 + -0x10;
    *(longlong *)(pcVar17 + -0x10) = lVar9;
    *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar2;
    lVar13 = *(longlong *)pcVar19;
    *(code **)(lVar9 + 8) = pcVar17 + -0x10;
    *(code **)(pcVar17 + 0x10) = pcVar19;
    if (lVar13 == 0) {
      (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
    }
  }
  else {
    *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
    if (*(longlong *)pcVar21 == 0) {
LAB_23e2ce2ec:
      (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))(pcVar21);
      if (pcVar17 != (code *)0x0) goto LAB_23e2cd6c0;
      if (iVar7 == 0) {
LAB_23e2ce304:
        iVar7 = (int)plVar3[5];
      }
    }
    else if (pcVar17 != (code *)0x0) {
LAB_23e2cd6c0:
      if (*(longlong **)(pcVar17 + 0x18) == plVar3) goto LAB_23e2cd780;
      pcVar19 = pcVar17;
      if (iVar7 == 0) {
LAB_23e2cd6d2:
        iVar7 = (int)plVar3[5];
        pcVar19 = pcVar17;
      }
      goto LAB_23e2cd6d9;
    }
LAB_23e2ce308:
    pcVar17 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar19 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar19;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong *)(pcVar17 + 0x10) = 0;
    *(longlong **)(pcVar17 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar9 = *(longlong *)(pcStack_160 + 0x1f8);
    *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
    lVar9 = *(longlong *)(lVar9 + 0x10);
    *(int *)(pcVar17 + 0x24) = iVar7;
    lVar9 = *(longlong *)(lVar9 + 0x2e8);
    lVar13 = *(longlong *)(pcVar17 + -8);
    puVar2 = *(undefined8 **)(lVar9 + 8);
    *puVar2 = pcVar17 + -0x10;
    *(longlong *)(pcVar17 + -0x10) = lVar9;
    *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar2;
    *(code **)(lVar9 + 8) = pcVar17 + -0x10;
  }
LAB_23e2cd780:
  FUN_23e8bba40(plVar3,"oooooooooo",param_3,plStack_130,plStack_158,pcVar18,plStack_168,plStack_148,
                plStack_140,plStack_138,plStack_128,0);
  if (_DAT_23eeb02c0 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eeb02c0 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar9 + 0x28);
  plVar10 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar10 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar3[0xf] = 0;
  if ((plStack_130 != (longlong *)0x0) &&
     (lVar9 = *plStack_130, *plStack_130 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_130[1] + 0x30))(plStack_130);
  }
  if ((plStack_158 != (longlong *)0x0) &&
     (lVar9 = *plStack_158, *plStack_158 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_158[1] + 0x30))(plStack_158);
  }
  if ((pcVar18 != (code *)0x0) &&
     (*(longlong *)pcVar18 = *(longlong *)pcVar18 + -1, *(longlong *)pcVar18 == 0)) {
    (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
  }
  if ((plStack_168 != (longlong *)0x0) &&
     (lVar9 = *plStack_168, *plStack_168 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_168[1] + 0x30))(plStack_168);
  }
  if ((plStack_148 != (longlong *)0x0) &&
     (lVar9 = *plStack_148, *plStack_148 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_148[1] + 0x30))(plStack_148);
  }
  if ((plStack_140 != (longlong *)0x0) &&
     (lVar9 = *plStack_140, *plStack_140 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_140[1] + 0x30))(plStack_140);
  }
  if ((plStack_138 != (longlong *)0x0) &&
     (lVar9 = *plStack_138, *plStack_138 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_138[1] + 0x30))(plStack_138);
  }
  if ((plStack_128 != (longlong *)0x0) &&
     (lVar9 = *plStack_128, *plStack_128 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_128[1] + 0x30))(plStack_128);
  }
  lVar9 = *param_3;
  *param_3 = lVar9 + -1;
  if (lVar9 + -1 == 0) {
    (**(code **)(param_3[1] + 0x30))(param_3);
  }
  FUN_23a33aa70(param_1,plVar8,pcStack_118,pcVar17);
  return (code *)0x0;
}
