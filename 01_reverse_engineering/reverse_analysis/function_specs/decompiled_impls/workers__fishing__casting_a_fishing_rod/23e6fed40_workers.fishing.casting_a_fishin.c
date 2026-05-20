/* ===== 23e6fed40 workers.fishing.casting_a_fishin:250 ===== */
/* ghidra_name=FUN_23e6fed40 entry=23e6fed40 size=35890 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e6fed40(longlong param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined8 uVar13;
  code *pcVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong lVar17;
  longlong lVar18;
  code *pcVar19;
  undefined4 uVar20;
  undefined1 auVar21 [8];
  undefined8 in_stack_fffffffffffffe08;
  longlong *plStack_170;
  longlong *plStack_168;
  longlong *plStack_160;
  code *pcStack_158;
  longlong *plStack_150;
  longlong *plStack_148;
  longlong *plStack_140;
  longlong *plStack_138;
  longlong *plStack_130;
  longlong *plStack_128;
  longlong *plStack_120;
  longlong *plStack_118;
  code *pcStack_110;
  longlong *plStack_108;
  longlong *plStack_100;
  longlong *plStack_d8;
  longlong *plStack_d0;
  longlong *plStack_c8;
  longlong *plStack_c0;
  longlong *plStack_b8;
  longlong *plStack_b0;
  longlong *plStack_a8;
  longlong *plStack_a0;
  longlong *plStack_98;
  longlong *plStack_90;
  longlong *plStack_88;
  undefined1 auStack_78 [8];
  longlong *plStack_70;
  longlong *plStack_68;
  
  plVar6 = _DAT_23eedb1a0;
  plStack_68 = (longlong *)0x0;
  auStack_78 = (undefined1  [8])0x0;
  plStack_70 = (longlong *)0x0;
  if (_DAT_23eedb1a0 == (longlong *)0x0) {
LAB_23e6fed9a:
    _DAT_23eedb1a0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedb198,DAT_23eedb268,0x90);
  }
  else {
    lVar7 = *_DAT_23eedb1a0;
    if (1 < lVar7) {
      *_DAT_23eedb1a0 = lVar7 + -1;
      goto LAB_23e6fed9a;
    }
    if (_DAT_23eedb1a0[2] != 0) {
      *_DAT_23eedb1a0 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      goto LAB_23e6fed9a;
    }
  }
  plVar2 = _DAT_23eedb1a0;
  lVar7 = *(longlong *)(param_1 + 0x38);
  plVar6 = _DAT_23eedb1a0 + 9;
  lVar18 = *(longlong *)(lVar7 + 8);
  _DAT_23eedb1a0[0xf] = lVar18;
  *(longlong **)(lVar7 + 8) = plVar6;
  if ((lVar18 != 0) &&
     (((*(char *)(lVar18 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar18 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar18 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar18 + 0x38))) && (plVar2[0xe] != 0)))) {
    plVar6 = *(longlong **)(lVar18 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar6;
    if (plVar6 != (longlong *)0x0) {
      *plVar6 = *plVar6 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  *(undefined4 *)(plVar2 + 8) = 0;
  uVar5 = FUN_23a3a0d40(DAT_23ed6cf28);
  *(undefined4 *)(plVar2 + 5) = 0xfc;
  plVar6 = (longlong *)FUN_23e94bb80(param_1,uVar5,_DAT_23eeda698);
  if (plVar6 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    plStack_70 = *(longlong **)(param_1 + 0x68);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar19 = _PyRuntime_exref;
    if (plStack_68 == (longlong *)0x0) {
      plStack_100 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      pcStack_158 = (code *)0x0;
      uVar20 = 0xfc;
      plStack_118 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_148 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcStack_110 = (code *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_150 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      plVar6 = (longlong *)0x0;
      goto LAB_23e7020b0;
    }
    if ((longlong *)plStack_68[3] != plVar2) {
      plStack_100 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      pcStack_158 = (code *)0x0;
      uVar20 = 0xfc;
      plStack_118 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_148 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcStack_110 = (code *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_150 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      plVar6 = (longlong *)0x0;
      goto LAB_23e701280;
    }
LAB_23e7019c0:
    plStack_100 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    plVar6 = (longlong *)0x0;
    pcStack_158 = (code *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_148 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plStack_160 = (longlong *)0x0;
    pcStack_110 = (code *)0x0;
    plStack_168 = (longlong *)0x0;
    plStack_150 = (longlong *)0x0;
    plStack_140 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_170 = (longlong *)0x0;
    plVar9 = plStack_68;
    goto LAB_23e701333;
  }
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  uVar5 = FUN_23a3a0d40(DAT_23ed6cf28);
  *(undefined4 *)(plVar2 + 5) = 0xfd;
  plVar6 = (longlong *)FUN_23e94bb80(param_1,uVar5,_DAT_23eeda6a0);
  if (plVar6 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    plStack_70 = *(longlong **)(param_1 + 0x68);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar19 = _PyRuntime_exref;
    if (plStack_68 == (longlong *)0x0) {
      plStack_100 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      pcStack_158 = (code *)0x0;
      uVar20 = 0xfd;
      plStack_118 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_148 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcStack_110 = (code *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_150 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      plVar6 = (longlong *)0x0;
      goto LAB_23e7020b0;
    }
    if ((longlong *)plStack_68[3] == plVar2) goto LAB_23e7019c0;
    plStack_100 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    pcStack_158 = (code *)0x0;
    uVar20 = 0xfd;
    plStack_118 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_148 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plStack_160 = (longlong *)0x0;
    pcStack_110 = (code *)0x0;
    plStack_168 = (longlong *)0x0;
    plStack_150 = (longlong *)0x0;
    plStack_140 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_170 = (longlong *)0x0;
    plVar6 = (longlong *)0x0;
LAB_23e701280:
    plVar10 = plStack_68;
    plVar9 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar11 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar11;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar9[3] = (longlong)plVar2;
    *plVar2 = *plVar2 + 1;
    lVar7 = *(longlong *)(pcVar19 + 0x1f8);
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar20;
    lVar7 = *(longlong *)(lVar7 + 0x10);
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar7 = *(longlong *)(lVar7 + 0x2e8);
    lVar18 = plVar9[-1];
    puVar1 = *(undefined8 **)(lVar7 + 8);
    *puVar1 = plVar9 + -2;
    plVar9[-2] = lVar7;
    plVar9[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar1;
    *(longlong **)(lVar7 + 8) = plVar9 + -2;
    plVar9[2] = (longlong)plVar10;
    *plVar10 = *plVar10 + 1;
    plVar10 = plStack_68;
  }
  else {
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    uVar5 = FUN_23a3a0d40(DAT_23ed6cf28);
    *(undefined4 *)(plVar2 + 5) = 0xfe;
    plVar6 = (longlong *)FUN_23e94bb80(param_1,uVar5,_DAT_23eeda6a8);
    if (plVar6 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_70 = *(longlong **)(param_1 + 0x68);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcVar19 = _PyRuntime_exref;
      if (plStack_68 == (longlong *)0x0) {
        plStack_100 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        pcStack_158 = (code *)0x0;
        uVar20 = 0xfe;
        plStack_118 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        plStack_148 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
        pcStack_110 = (code *)0x0;
        plStack_168 = (longlong *)0x0;
        plStack_150 = (longlong *)0x0;
        plStack_140 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_170 = (longlong *)0x0;
        plVar6 = (longlong *)0x0;
        goto LAB_23e7020b0;
      }
      if ((longlong *)plStack_68[3] == plVar2) goto LAB_23e7019c0;
      plStack_100 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      pcStack_158 = (code *)0x0;
      uVar20 = 0xfe;
      plStack_118 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_148 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcStack_110 = (code *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_150 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      plVar6 = (longlong *)0x0;
      goto LAB_23e701280;
    }
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    uVar5 = DAT_23ed6cd08;
    lVar7 = FUN_23e8e1b00();
    if (lVar7 == 0) {
      FUN_23e915740(param_1,auStack_78,DAT_23eeda4c8);
      if (plStack_68 == (longlong *)0x0) {
LAB_23e701fe0:
        plStack_100 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        pcStack_158 = (code *)0x0;
        plVar6 = (longlong *)0x0;
        uVar20 = 0x101;
        plStack_118 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        plStack_148 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
        pcStack_110 = (code *)0x0;
        plStack_168 = (longlong *)0x0;
        plStack_150 = (longlong *)0x0;
        plStack_140 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_170 = (longlong *)0x0;
        pcVar19 = _PyRuntime_exref;
        goto LAB_23e7020b0;
      }
      if ((longlong *)plStack_68[3] == plVar2) goto LAB_23e7019c0;
      plStack_100 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      pcStack_158 = (code *)0x0;
      uVar20 = 0x101;
      plStack_118 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_148 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcStack_110 = (code *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_150 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      plVar6 = (longlong *)0x0;
      pcVar19 = _PyRuntime_exref;
      goto LAB_23e701280;
    }
    cVar3 = FUN_23e8d9ac0(lVar7,_DAT_23eeda4d0,uVar5);
    if (cVar3 == '\0') {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_70 = *(longlong **)(param_1 + 0x68);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plStack_68 == (longlong *)0x0) goto LAB_23e701fe0;
      if ((longlong *)plStack_68[3] == plVar2) goto LAB_23e7019c0;
      plStack_100 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      pcStack_158 = (code *)0x0;
      plVar6 = (longlong *)0x0;
      uVar20 = 0x101;
      plStack_118 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_148 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcStack_110 = (code *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_150 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      pcVar19 = _PyRuntime_exref;
      goto LAB_23e701280;
    }
    lVar7 = FUN_23e8e1b00();
    if (lVar7 == 0) {
      FUN_23e915740(param_1,auStack_78,DAT_23eeda4c8);
      if (plStack_68 == (longlong *)0x0) {
LAB_23e702a40:
        plStack_100 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        pcStack_158 = (code *)0x0;
        plVar6 = (longlong *)0x0;
        uVar20 = 0x102;
        plStack_118 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        plStack_148 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
        pcStack_110 = (code *)0x0;
        plStack_168 = (longlong *)0x0;
        plStack_150 = (longlong *)0x0;
        plStack_140 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_170 = (longlong *)0x0;
        pcVar19 = _PyRuntime_exref;
        goto LAB_23e7020b0;
      }
      if ((longlong *)plStack_68[3] == plVar2) goto LAB_23e7019c0;
      plStack_100 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      pcStack_158 = (code *)0x0;
      uVar20 = 0x102;
      plStack_118 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_148 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcStack_110 = (code *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_150 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      plVar6 = (longlong *)0x0;
      pcVar19 = _PyRuntime_exref;
      goto LAB_23e701280;
    }
    cVar3 = FUN_23e8d9ac0(lVar7,_DAT_23eeda4d8,_Py_FalseStruct_exref);
    if (cVar3 == '\0') {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_70 = *(longlong **)(param_1 + 0x68);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plStack_68 == (longlong *)0x0) goto LAB_23e702a40;
      if ((longlong *)plStack_68[3] == plVar2) goto LAB_23e7019c0;
      plStack_100 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      pcStack_158 = (code *)0x0;
      plVar6 = (longlong *)0x0;
      uVar20 = 0x102;
      plStack_118 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_148 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcStack_110 = (code *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_150 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      pcVar19 = _PyRuntime_exref;
      goto LAB_23e701280;
    }
    uVar5 = FUN_23a3a0d40(DAT_23ed6cf28);
    *(undefined4 *)(plVar2 + 5) = 0x105;
    plVar6 = (longlong *)FUN_23e94bb80(param_1,uVar5,_DAT_23eeda6b0);
    if (plVar6 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_70 = *(longlong **)(param_1 + 0x68);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcVar19 = _PyRuntime_exref;
      if (plStack_68 == (longlong *)0x0) {
        plStack_100 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        pcStack_158 = (code *)0x0;
        uVar20 = 0x105;
        plStack_118 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        plStack_148 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
        pcStack_110 = (code *)0x0;
        plStack_168 = (longlong *)0x0;
        plStack_150 = (longlong *)0x0;
        plStack_140 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_170 = (longlong *)0x0;
        plVar6 = (longlong *)0x0;
        goto LAB_23e7020b0;
      }
      if ((longlong *)plStack_68[3] == plVar2) goto LAB_23e7019c0;
      plStack_100 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      pcStack_158 = (code *)0x0;
      uVar20 = 0x105;
      plStack_118 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_148 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcStack_110 = (code *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_150 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      plVar6 = (longlong *)0x0;
      goto LAB_23e701280;
    }
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    lVar7 = *(longlong *)(_DAT_23eeda318 + 0x20);
    if (*(char *)(lVar7 + 10) != '\0') {
      iVar4 = *(int *)(lVar7 + 0xc);
      if (*(int *)(lVar7 + 0xc) == 0) {
        *(int *)(lVar7 + 0xc) = _DAT_23ec154a0;
        iVar4 = _DAT_23ec154a0;
        _DAT_23ec154a0 = _DAT_23ec154a0 + 1;
      }
      if (_DAT_23ec1548c != iVar4) {
        _DAT_23ec1548c = iVar4;
        _DAT_23eedb180 = FUN_23e8cbd60(lVar7,_DAT_23eeda6b8,*(undefined8 *)(_DAT_23eeda6b8 + 0x18));
      }
      if (-1 < _DAT_23eedb180) {
        lVar18 = lVar7 + 0x20 + (1L << (*(byte *)(lVar7 + 9) & 0x3f));
        lVar17 = *(longlong *)(lVar18 + 8 + _DAT_23eedb180 * 0x10);
        if (lVar17 != 0) goto LAB_23e6fefdb;
        _DAT_23eedb180 = FUN_23e8cbd60(lVar7,_DAT_23eeda6b8,*(undefined8 *)(_DAT_23eeda6b8 + 0x18));
        if (-1 < _DAT_23eedb180) {
          lVar17 = *(longlong *)(lVar18 + 8 + _DAT_23eedb180 * 0x10);
          goto LAB_23e702918;
        }
      }
LAB_23e701829:
      plVar6 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeda6b8);
      if ((plVar6 != (longlong *)0x0) && (lVar17 = *plVar6, lVar17 != 0)) goto LAB_23e6fefdb;
      FUN_23e915740(param_1,auStack_78,_DAT_23eeda6b8);
      if (plStack_68 != (longlong *)0x0) {
        if ((longlong *)plStack_68[3] == plVar2) goto LAB_23e7019c0;
        plStack_100 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        pcStack_158 = (code *)0x0;
        plVar6 = (longlong *)0x0;
        uVar20 = 0x106;
        plStack_118 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        plStack_148 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
        pcStack_110 = (code *)0x0;
        plStack_168 = (longlong *)0x0;
        plStack_150 = (longlong *)0x0;
        plStack_140 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_170 = (longlong *)0x0;
        pcVar19 = _PyRuntime_exref;
        goto LAB_23e701280;
      }
LAB_23e7036a8:
      plStack_100 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      pcStack_158 = (code *)0x0;
      plVar6 = (longlong *)0x0;
      uVar20 = 0x106;
      plStack_118 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_148 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcStack_110 = (code *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_150 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      pcVar19 = _PyRuntime_exref;
      goto LAB_23e7020b0;
    }
    plVar6 = (longlong *)FUN_23a37a020(_DAT_23eeda318,_DAT_23eeda6b8);
    if (plVar6 == (longlong *)0x0) goto LAB_23e701829;
    lVar17 = *plVar6;
LAB_23e702918:
    if (lVar17 == 0) goto LAB_23e701829;
LAB_23e6fefdb:
    *(undefined4 *)(plVar2 + 5) = 0x106;
    plVar6 = (longlong *)FUN_23e94bb80(param_1,lVar17,_DAT_23eeda6c0);
    if (plVar6 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_70 = *(longlong **)(param_1 + 0x68);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plStack_68 == (longlong *)0x0) goto LAB_23e7036a8;
      if ((longlong *)plStack_68[3] == plVar2) goto LAB_23e7019c0;
      plStack_100 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      pcStack_158 = (code *)0x0;
      uVar20 = 0x106;
      plStack_118 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_148 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcStack_110 = (code *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_150 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      pcVar19 = _PyRuntime_exref;
      goto LAB_23e701280;
    }
    *(undefined4 *)(plVar2 + 5) = 0x108;
    plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar6,_DAT_23eeda6c8);
    if (plVar8 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_70 = *(longlong **)(param_1 + 0x68);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plStack_68 == (longlong *)0x0) {
LAB_23e703c44:
        plStack_100 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        pcStack_158 = (code *)0x0;
        uVar20 = 0x108;
        plStack_118 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        plStack_148 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
        pcStack_110 = (code *)0x0;
        plStack_168 = (longlong *)0x0;
        plStack_150 = (longlong *)0x0;
        plStack_140 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_170 = (longlong *)0x0;
        pcVar19 = _PyRuntime_exref;
        goto LAB_23e7020b0;
      }
      if ((longlong *)plStack_68[3] == plVar2) goto LAB_23e7026d0;
      plStack_100 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      uVar20 = 0x108;
      pcStack_158 = (code *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_148 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcStack_110 = (code *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_150 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      pcVar19 = _PyRuntime_exref;
      goto LAB_23e701280;
    }
    iVar4 = FUN_23a35f020();
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))();
    }
    if (iVar4 == -1) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_70 = *(longlong **)(param_1 + 0x68);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plStack_68 == (longlong *)0x0) goto LAB_23e703c44;
      if ((longlong *)plStack_68[3] == plVar2) goto LAB_23e7026d0;
      plStack_100 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      pcStack_158 = (code *)0x0;
      uVar20 = 0x108;
      plStack_118 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_148 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcStack_110 = (code *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_150 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      pcVar19 = _PyRuntime_exref;
      goto LAB_23e701280;
    }
    if (iVar4 == 0) {
      uVar5 = FUN_23a3a0d40(DAT_23ed6cf28);
      *(undefined4 *)(plVar2 + 5) = 0x109;
      plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar5,_DAT_23eeda6d0);
      if (plVar8 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        plStack_70 = *(longlong **)(param_1 + 0x68);
        plStack_68 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar19 = _PyRuntime_exref;
        if (plStack_68 != (longlong *)0x0) {
          if ((longlong *)plStack_68[3] == plVar2) goto LAB_23e7026d0;
          plStack_100 = (longlong *)0x0;
          plStack_a8 = (longlong *)0x0;
          uVar20 = 0x109;
          pcStack_158 = (code *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_148 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_160 = (longlong *)0x0;
          pcStack_110 = (code *)0x0;
          plStack_168 = (longlong *)0x0;
          plStack_150 = (longlong *)0x0;
          plStack_140 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_170 = (longlong *)0x0;
          plVar8 = (longlong *)0x0;
          goto LAB_23e701280;
        }
        plStack_100 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        uVar20 = 0x109;
        pcStack_158 = (code *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        plStack_148 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
        pcStack_110 = (code *)0x0;
        plStack_168 = (longlong *)0x0;
        plStack_150 = (longlong *)0x0;
        plStack_140 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_170 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
      }
      else {
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        uVar5 = FUN_23a3a0d40(DAT_23ed6cf28);
        *(undefined4 *)(plVar2 + 5) = 0x10a;
        plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar5,_DAT_23eeda6d8);
        if (plVar8 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
          plStack_70 = *(longlong **)(param_1 + 0x68);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar19 = _PyRuntime_exref;
          if (plStack_68 != (longlong *)0x0) {
            if ((longlong *)plStack_68[3] == plVar2) goto LAB_23e7026d0;
            plStack_100 = (longlong *)0x0;
            plStack_a8 = (longlong *)0x0;
            uVar20 = 0x10a;
            pcStack_158 = (code *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_148 = (longlong *)0x0;
            plStack_138 = (longlong *)0x0;
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_160 = (longlong *)0x0;
            pcStack_110 = (code *)0x0;
            plStack_168 = (longlong *)0x0;
            plStack_150 = (longlong *)0x0;
            plStack_140 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_170 = (longlong *)0x0;
            plVar8 = (longlong *)0x0;
            goto LAB_23e701280;
          }
          plStack_100 = (longlong *)0x0;
          plStack_a8 = (longlong *)0x0;
          uVar20 = 0x10a;
          pcStack_158 = (code *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_148 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_160 = (longlong *)0x0;
          pcStack_110 = (code *)0x0;
          plStack_168 = (longlong *)0x0;
          plStack_150 = (longlong *)0x0;
          plStack_140 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_170 = (longlong *)0x0;
          plVar8 = (longlong *)0x0;
        }
        else {
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          plVar8 = (longlong *)FUN_23e935de0(param_1,_DAT_23eeda6e0);
          if (plVar8 != (longlong *)0x0) {
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            auStack_78 = (undefined1  [8])
                         FUN_23e91b0f0(param_1,*(undefined8 *)PyExc_SystemExit_exref,DAT_23ed6ccf8);
            FUN_23e91b7d0(param_1,auStack_78);
            pcVar19 = _PyRuntime_exref;
            if (plStack_68 == (longlong *)0x0) {
              plStack_100 = (longlong *)0x0;
              plStack_a8 = (longlong *)0x0;
              plVar8 = (longlong *)0x0;
              pcStack_158 = (code *)0x0;
              uVar20 = 0x10c;
              plStack_118 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plStack_148 = (longlong *)0x0;
              plStack_138 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              pcStack_110 = (code *)0x0;
              plStack_168 = (longlong *)0x0;
              plStack_150 = (longlong *)0x0;
              plStack_140 = (longlong *)0x0;
              plStack_128 = (longlong *)0x0;
              plStack_170 = (longlong *)0x0;
              goto LAB_23e7020b0;
            }
            if ((longlong *)plStack_68[3] != plVar2) {
              plStack_100 = (longlong *)0x0;
              plStack_a8 = (longlong *)0x0;
              plVar8 = (longlong *)0x0;
              pcStack_158 = (code *)0x0;
              uVar20 = 0x10c;
              plStack_118 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plStack_148 = (longlong *)0x0;
              plStack_138 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              pcStack_110 = (code *)0x0;
              plStack_168 = (longlong *)0x0;
              plStack_150 = (longlong *)0x0;
              plStack_140 = (longlong *)0x0;
              plStack_128 = (longlong *)0x0;
              plStack_170 = (longlong *)0x0;
              goto LAB_23e701280;
            }
            goto LAB_23e7026d0;
          }
          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
          plStack_70 = *(longlong **)(param_1 + 0x68);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar19 = _PyRuntime_exref;
          if (plStack_68 != (longlong *)0x0) {
            if ((longlong *)plStack_68[3] == plVar2) goto LAB_23e7026d0;
            plStack_100 = (longlong *)0x0;
            plStack_a8 = (longlong *)0x0;
            uVar20 = 0x10b;
            pcStack_158 = (code *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_148 = (longlong *)0x0;
            plStack_138 = (longlong *)0x0;
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_160 = (longlong *)0x0;
            pcStack_110 = (code *)0x0;
            plStack_168 = (longlong *)0x0;
            plStack_150 = (longlong *)0x0;
            plStack_140 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_170 = (longlong *)0x0;
            plVar8 = (longlong *)0x0;
            goto LAB_23e701280;
          }
          plStack_100 = (longlong *)0x0;
          plStack_a8 = (longlong *)0x0;
          uVar20 = 0x10b;
          pcStack_158 = (code *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_148 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_160 = (longlong *)0x0;
          pcStack_110 = (code *)0x0;
          plStack_168 = (longlong *)0x0;
          plStack_150 = (longlong *)0x0;
          plStack_140 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_170 = (longlong *)0x0;
          plVar8 = (longlong *)0x0;
        }
      }
    }
    else {
      uVar5 = FUN_23a3a0d40(DAT_23ed6cf28);
      *(undefined4 *)(plVar2 + 5) = 0x10e;
      plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar5,_DAT_23eeda6e8);
      if (plVar8 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        plStack_70 = *(longlong **)(param_1 + 0x68);
        plStack_68 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar19 = _PyRuntime_exref;
        if (plStack_68 != (longlong *)0x0) {
          if ((longlong *)plStack_68[3] == plVar2) goto LAB_23e7026d0;
          plStack_100 = (longlong *)0x0;
          plStack_a8 = (longlong *)0x0;
          uVar20 = 0x10e;
          pcStack_158 = (code *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_148 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_160 = (longlong *)0x0;
          pcStack_110 = (code *)0x0;
          plStack_168 = (longlong *)0x0;
          plStack_150 = (longlong *)0x0;
          plStack_140 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_170 = (longlong *)0x0;
          plVar8 = (longlong *)0x0;
          goto LAB_23e701280;
        }
        plStack_100 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        uVar20 = 0x10e;
        pcStack_158 = (code *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        plStack_148 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
        pcStack_110 = (code *)0x0;
        plStack_168 = (longlong *)0x0;
        plStack_150 = (longlong *)0x0;
        plStack_140 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_170 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        goto LAB_23e7020b0;
      }
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      *(undefined4 *)(plVar2 + 5) = 0x111;
      plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar6,_DAT_23eeda6f0);
      if (plVar8 == (longlong *)0x0) {
LAB_23e702898:
        auVar21 = *(undefined1 (*) [8])(param_1 + 0x60);
        plVar11 = *(longlong **)(param_1 + 0x68);
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        plVar9 = (longlong *)FUN_23a388310();
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))();
        }
        if (plVar9 == (longlong *)0x0) goto LAB_23e702898;
        plVar8 = (longlong *)(**(code **)(plVar9[1] + 0xe0))(plVar9);
        if ((plVar8 == (longlong *)0x0) &&
           (plVar8 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,0,2), plVar8 == (longlong *)0x0))
        {
          plStack_170 = (longlong *)0x0;
        }
        else {
          plStack_170 = (longlong *)(**(code **)(plVar9[1] + 0xe0))(plVar9);
          if (((plStack_170 != (longlong *)0x0) ||
              (plStack_170 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,1,2),
              plStack_170 != (longlong *)0x0)) &&
             (cVar3 = FUN_23a3884a0(param_1,auStack_78,plVar9,2), cVar3 != '\0')) {
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            if (*plStack_170 == 0) {
              (**(code **)(plStack_170[1] + 0x30))();
            }
            lVar7 = *(longlong *)(_DAT_23eeda318 + 0x20);
            if (*(char *)(lVar7 + 10) == '\0') {
              plVar9 = (longlong *)FUN_23a37a020(_DAT_23eeda318,_DAT_23eeda6f8);
              if (plVar9 == (longlong *)0x0) goto LAB_23e702c90;
              lVar18 = *plVar9;
LAB_23e702c79:
              if (lVar18 == 0) goto LAB_23e702c90;
LAB_23e6ff228:
              *(undefined4 *)(plVar2 + 5) = 0x112;
              plStack_90 = plStack_170;
              plStack_98 = plVar8;
              plVar9 = (longlong *)FUN_23e94ed00(param_1,lVar18,&plStack_98);
              if (plVar9 != (longlong *)0x0) {
                plVar10 = (longlong *)FUN_23a388310();
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))();
                }
                if (plVar10 != (longlong *)0x0) {
                  plStack_128 = (longlong *)(**(code **)(plVar10[1] + 0xe0))(plVar10);
                  if ((plStack_128 == (longlong *)0x0) &&
                     (plStack_128 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,0,2),
                     plStack_128 == (longlong *)0x0)) {
                    plStack_140 = (longlong *)0x0;
                  }
                  else {
                    plStack_140 = (longlong *)(**(code **)(plVar10[1] + 0xe0))(plVar10);
                    if (((plStack_140 != (longlong *)0x0) ||
                        (plStack_140 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,1,2),
                        plStack_140 != (longlong *)0x0)) &&
                       (cVar3 = FUN_23a3884a0(param_1,auStack_78,plVar10), cVar3 != '\0')) {
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                      }
                      if (*plStack_128 == 0) {
                        (**(code **)(plStack_128[1] + 0x30))();
                      }
                      if (*plStack_140 == 0) {
                        (**(code **)(plStack_140[1] + 0x30))();
                      }
                      plVar9 = (longlong *)FUN_23a3a0d40(DAT_23ed6cf28);
                      plVar11 = _DAT_23eeda700;
                      lVar7 = *(longlong *)(param_1 + 0x10);
                      plVar10 = *(longlong **)(lVar7 + 0xe20);
                      if (plVar10 == (longlong *)0x0) {
                        plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                      }
                      else {
                        lVar18 = plVar10[3];
                        *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
                        *(longlong *)(lVar7 + 0xe20) = lVar18;
                        *plVar10 = 1;
                      }
                      pcVar19 = _PyRuntime_exref;
                      plVar10[4] = 0;
                      lVar7 = *(longlong *)
                               (*(longlong *)(*(longlong *)(pcVar19 + 0x1f8) + 0x10) + 0x2e8);
                      lVar18 = plVar10[-1];
                      puVar1 = *(undefined8 **)(lVar7 + 8);
                      *puVar1 = plVar10 + -2;
                      plVar10[-2] = lVar7;
                      plVar10[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar1;
                      *(longlong **)(lVar7 + 8) = plVar10 + -2;
                      plVar12 = DAT_23ed6a4c0;
                      *plVar11 = *plVar11 + 1;
                      plVar10[3] = (longlong)plVar11;
                      plVar11 = DAT_23ed6cd28;
                      pcVar14 = pcVar19;
                      plVar15 = plVar8;
                      if (plVar12 != (longlong *)0x0) {
LAB_23e6ff46f:
                        plStack_98 = plStack_128;
                        plStack_90 = plVar11;
                        lVar7 = FUN_23e94ed00();
                        if (lVar7 != 0) {
                          plVar10[4] = lVar7;
                          pcStack_158 = PyUnicode_Join_exref;
                          plVar11 = (longlong *)PyUnicode_Join();
                          *plVar10 = *plVar10 + -1;
                          if (*plVar10 == 0) {
                            (**(code **)(plVar10[1] + 0x30))();
                          }
                          if (plVar11 == (longlong *)0x0) {
                            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                            plStack_70 = *(longlong **)(param_1 + 0x68);
                            plStack_68 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            if (plStack_68 != (longlong *)0x0) {
                              if ((longlong *)plStack_68[3] != plVar2) {
                                plStack_a8 = (longlong *)0x0;
                                uVar20 = 0x114;
                                plStack_100 = (longlong *)0x0;
                                pcStack_158 = (code *)0x0;
                                plStack_118 = (longlong *)0x0;
                                plStack_108 = (longlong *)0x0;
                                plStack_148 = (longlong *)0x0;
                                plStack_138 = (longlong *)0x0;
                                plStack_130 = (longlong *)0x0;
                                plStack_120 = (longlong *)0x0;
                                plStack_160 = (longlong *)0x0;
                                pcStack_110 = (code *)0x0;
                                plStack_150 = (longlong *)0x0;
                                plStack_168 = (longlong *)0x0;
                                goto LAB_23e701280;
                              }
                              goto LAB_23e703d0f;
                            }
                          }
                          else {
                            *(undefined4 *)(plVar2 + 5) = 0x114;
                            plVar9 = (longlong *)FUN_23e914090(param_1,plVar9,plVar11);
                            lVar7 = *plVar11;
                            *plVar11 = lVar7 + -1;
                            if (lVar7 + -1 == 0) {
                              (**(code **)(plVar11[1] + 0x30))();
                            }
                            if (plVar9 != (longlong *)0x0) {
                              lVar7 = *plVar9;
                              *plVar9 = lVar7 + -1;
                              if (lVar7 + -1 == 0) {
                                (**(code **)(plVar9[1] + 0x30))(plVar9);
                              }
                              uVar5 = FUN_23a3a0d40(DAT_23ed6cf28);
                              plVar9 = _DAT_23eeda708;
                              lVar7 = *(longlong *)(param_1 + 0x10);
                              plVar10 = *(longlong **)(lVar7 + 0xe58);
                              if (plVar10 == (longlong *)0x0) {
                                plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,9);
                              }
                              else {
                                lVar18 = plVar10[3];
                                *(int *)(lVar7 + 0xed8) = *(int *)(lVar7 + 0xed8) + -1;
                                *(longlong *)(lVar7 + 0xe58) = lVar18;
                                *plVar10 = 1;
                              }
                              plVar10[0xb] = 0;
                              *(undefined1 (*) [16])(plVar10 + 3) = (undefined1  [16])0x0;
                              *(undefined1 (*) [16])(plVar10 + 5) = (undefined1  [16])0x0;
                              *(undefined1 (*) [16])(plVar10 + 7) = (undefined1  [16])0x0;
                              *(undefined1 (*) [16])(plVar10 + 9) = (undefined1  [16])0x0;
                              lVar7 = *(longlong *)
                                       (*(longlong *)(*(longlong *)(pcVar19 + 0x1f8) + 0x10) + 0x2e8
                                       );
                              lVar18 = plVar10[-1];
                              puVar1 = *(undefined8 **)(lVar7 + 8);
                              *puVar1 = plVar10 + -2;
                              uVar13 = DAT_23ed6ccf0;
                              plVar10[-2] = lVar7;
                              plVar10[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar1;
                              *(longlong **)(lVar7 + 8) = plVar10 + -2;
                              *plVar9 = *plVar9 + 1;
                              plVar10[3] = (longlong)plVar9;
                              plVar9 = (longlong *)FUN_23a388650(param_1,plStack_140,uVar13);
                              plVar11 = DAT_23ed6cd28;
                              if (plVar9 == (longlong *)0x0) {
LAB_23e7037ab:
                                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                plStack_70 = *(longlong **)(param_1 + 0x68);
                                plStack_68 = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *plVar10 = *plVar10 + -1;
                                if (*plVar10 == 0) {
                                  (**(code **)(plVar10[1] + 0x30))();
                                }
                                if (plStack_68 != (longlong *)0x0) {
                                  if (plVar2 != (longlong *)plStack_68[3]) {
                                    plStack_100 = (longlong *)0x0;
                                    plStack_a8 = (longlong *)0x0;
                                    uVar20 = 0x115;
                                    pcStack_158 = (code *)0x0;
                                    plStack_118 = (longlong *)0x0;
                                    plStack_108 = (longlong *)0x0;
                                    plStack_148 = (longlong *)0x0;
                                    plStack_138 = (longlong *)0x0;
                                    plStack_130 = (longlong *)0x0;
                                    plStack_120 = (longlong *)0x0;
                                    plStack_160 = (longlong *)0x0;
                                    pcStack_110 = (code *)0x0;
                                    plStack_168 = (longlong *)0x0;
                                    plStack_150 = (longlong *)0x0;
                                    goto LAB_23e701280;
                                  }
                                  goto LAB_23e703d0f;
                                }
                              }
                              else {
                                if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                  plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format")
                                  ;
                                  if (plVar12 == (longlong *)0x0) goto LAB_23e704442;
                                  *plVar12 = *plVar12 + 1;
                                  DAT_23ed6a4c0 = plVar12;
                                }
                                plStack_90 = plVar11;
                                plStack_98 = plVar9;
                                lVar7 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
                                *plVar9 = *plVar9 + -1;
                                if (*plVar9 == 0) {
                                  (**(code **)(plVar9[1] + 0x30))();
                                }
                                if (lVar7 == 0) goto LAB_23e7037ab;
                                plVar10[4] = lVar7;
                                plVar9 = _DAT_23eeda710;
                                uVar13 = DAT_23ed6ccf8;
                                *_DAT_23eeda710 = *_DAT_23eeda710 + 1;
                                plVar10[5] = (longlong)plVar9;
                                plVar9 = (longlong *)FUN_23a388650(param_1,plStack_140,uVar13);
                                plVar11 = DAT_23ed6cd28;
                                if (plVar9 == (longlong *)0x0) goto LAB_23e7037ab;
                                if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                  pcVar14 = pcVar19;
                                  plVar15 = plVar8;
                                  plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format")
                                  ;
                                  if (plVar12 == (longlong *)0x0) goto LAB_23e704442;
                                  *plVar12 = *plVar12 + 1;
                                  DAT_23ed6a4c0 = plVar12;
                                }
                                plStack_90 = plVar11;
                                plStack_98 = plVar9;
                                lVar7 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
                                *plVar9 = *plVar9 + -1;
                                if (*plVar9 == 0) {
                                  (**(code **)(plVar9[1] + 0x30))();
                                }
                                if (lVar7 == 0) goto LAB_23e7037ab;
                                plVar10[6] = lVar7;
                                uVar13 = _DAT_23eeda720;
                                plVar9 = _DAT_23eeda718;
                                *_DAT_23eeda718 = *_DAT_23eeda718 + 1;
                                plVar10[7] = (longlong)plVar9;
                                plVar9 = (longlong *)FUN_23a388650(param_1,plStack_140,uVar13);
                                plVar11 = DAT_23ed6cd28;
                                if (plVar9 == (longlong *)0x0) goto LAB_23e7037ab;
                                if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                  pcVar14 = pcVar19;
                                  plVar15 = plVar8;
                                  plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format")
                                  ;
                                  if (plVar12 == (longlong *)0x0) goto LAB_23e704442;
                                  *plVar12 = *plVar12 + 1;
                                  DAT_23ed6a4c0 = plVar12;
                                }
                                plStack_90 = plVar11;
                                plStack_98 = plVar9;
                                lVar7 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
                                *plVar9 = *plVar9 + -1;
                                if (*plVar9 == 0) {
                                  (**(code **)(plVar9[1] + 0x30))();
                                }
                                if (lVar7 == 0) goto LAB_23e7037ab;
                                plVar10[8] = lVar7;
                                uVar13 = _DAT_23eeda730;
                                plVar11 = _DAT_23eeda728;
                                *_DAT_23eeda728 = *_DAT_23eeda728 + 1;
                                plVar10[9] = (longlong)plVar11;
                                plVar12 = (longlong *)FUN_23a388650(param_1,plStack_140,uVar13,3);
                                plVar11 = DAT_23ed6cd28;
                                if (plVar12 == (longlong *)0x0) goto LAB_23e7037ab;
                                if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                  pcVar14 = pcVar19;
                                  plVar15 = plVar8;
                                  plVar16 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format")
                                  ;
                                  if (plVar16 == (longlong *)0x0) goto LAB_23e704442;
                                  *plVar16 = *plVar16 + 1;
                                  DAT_23ed6a4c0 = plVar16;
                                }
                                plStack_90 = plVar11;
                                plStack_98 = plVar12;
                                lVar7 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
                                *plVar12 = *plVar12 + -1;
                                if (*plVar12 == 0) {
                                  (**(code **)(plVar12[1] + 0x30))();
                                }
                                plVar11 = _DAT_23eeda738;
                                plVar9 = DAT_23ed6cd28;
                                if (lVar7 == 0) goto LAB_23e7037ab;
                                plVar10[10] = lVar7;
                                *plVar11 = *plVar11 + 1;
                                plVar10[0xb] = (longlong)plVar11;
                                plVar9 = (longlong *)PyUnicode_Join(plVar9,plVar10);
                                *plVar10 = *plVar10 + -1;
                                if (*plVar10 == 0) {
                                  FUN_23a334bc0();
                                }
                                if (plVar9 == (longlong *)0x0) {
                                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                  plStack_70 = *(longlong **)(param_1 + 0x68);
                                  plStack_68 = *(longlong **)(param_1 + 0x70);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  if (plStack_68 != (longlong *)0x0) {
                                    if ((longlong *)plStack_68[3] != plVar2) {
                                      plStack_a8 = (longlong *)0x0;
                                      uVar20 = 0x115;
                                      plStack_100 = (longlong *)0x0;
                                      pcStack_158 = (code *)0x0;
                                      plStack_118 = (longlong *)0x0;
                                      plStack_108 = (longlong *)0x0;
                                      plStack_148 = (longlong *)0x0;
                                      plStack_138 = (longlong *)0x0;
                                      plStack_130 = (longlong *)0x0;
                                      plStack_120 = (longlong *)0x0;
                                      plStack_160 = (longlong *)0x0;
                                      pcStack_110 = (code *)0x0;
                                      plStack_150 = (longlong *)0x0;
                                      plStack_168 = (longlong *)0x0;
                                      goto LAB_23e701280;
                                    }
                                    goto LAB_23e703d0f;
                                  }
                                }
                                else {
                                  *(undefined4 *)(plVar2 + 5) = 0x115;
                                  plVar10 = (longlong *)FUN_23e914090(param_1,uVar5,plVar9);
                                  lVar7 = *plVar9;
                                  *plVar9 = lVar7 + -1;
                                  if (lVar7 + -1 == 0) {
                                    FUN_23a334bc0();
                                  }
                                  if (plVar10 != (longlong *)0x0) {
                                    lVar7 = *plVar10;
                                    *plVar10 = lVar7 + -1;
                                    if (lVar7 + -1 == 0) {
                                      FUN_23a334bc0(plVar10);
                                    }
                                    plVar10 = *(longlong **)(_DAT_23eeda318 + 0x20);
                                    if (*(char *)((longlong)plVar10 + 10) == '\0') {
                                      plVar9 = (longlong *)
                                               FUN_23a37a020(_DAT_23eeda318,_DAT_23eeda740);
                                      if (plVar9 != (longlong *)0x0) {
                                        lVar7 = *plVar9;
                                        goto LAB_23e70449d;
                                      }
                                    }
                                    else {
                                      iVar4 = *(int *)((longlong)plVar10 + 0xc);
                                      if (*(int *)((longlong)plVar10 + 0xc) == 0) {
                                        *(int *)((longlong)plVar10 + 0xc) = _DAT_23ec154a0;
                                        iVar4 = _DAT_23ec154a0;
                                        _DAT_23ec154a0 = _DAT_23ec154a0 + 1;
                                      }
                                      if (_DAT_23ec15494 != iVar4) {
                                        _DAT_23ec15494 = iVar4;
                                        _DAT_23eedb190 =
                                             FUN_23e8cbd60(plVar10,_DAT_23eeda740,
                                                           *(undefined8 *)(_DAT_23eeda740 + 0x18));
                                      }
                                      if (-1 < _DAT_23eedb190) {
                                        plVar9 = (longlong *)
                                                 ((longlong)plVar10 +
                                                 (1L << (*(byte *)((longlong)plVar10 + 9) & 0x3f)) +
                                                 0x20);
                                        lVar7 = plVar9[_DAT_23eedb190 * 2 + 1];
                                        if (lVar7 == 0) goto LAB_23e704455;
                                        goto LAB_23e6ffc9c;
                                      }
                                    }
                                    goto LAB_23e7044a6;
                                  }
                                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                  plStack_70 = *(longlong **)(param_1 + 0x68);
                                  plStack_68 = *(longlong **)(param_1 + 0x70);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  if (plStack_68 != (longlong *)0x0) {
                                    if (plVar2 == (longlong *)plStack_68[3]) goto LAB_23e703d0f;
                                    plStack_a8 = (longlong *)0x0;
                                    uVar20 = 0x115;
                                    plStack_100 = (longlong *)0x0;
                                    pcStack_158 = (code *)0x0;
                                    plStack_118 = (longlong *)0x0;
                                    plStack_108 = (longlong *)0x0;
                                    plStack_148 = (longlong *)0x0;
                                    plStack_138 = (longlong *)0x0;
                                    plStack_130 = (longlong *)0x0;
                                    plStack_120 = (longlong *)0x0;
                                    plStack_160 = (longlong *)0x0;
                                    pcStack_110 = (code *)0x0;
                                    plStack_168 = (longlong *)0x0;
                                    plStack_150 = (longlong *)0x0;
                                    goto LAB_23e701280;
                                  }
                                }
                              }
                              plStack_a8 = (longlong *)0x0;
                              uVar20 = 0x115;
                              plStack_100 = (longlong *)0x0;
                              pcStack_158 = (code *)0x0;
                              plStack_118 = (longlong *)0x0;
                              plStack_108 = (longlong *)0x0;
                              plStack_148 = (longlong *)0x0;
                              plStack_138 = (longlong *)0x0;
                              plStack_130 = (longlong *)0x0;
                              plStack_120 = (longlong *)0x0;
                              plStack_160 = (longlong *)0x0;
                              pcStack_110 = (code *)0x0;
                              plStack_168 = (longlong *)0x0;
                              plStack_150 = (longlong *)0x0;
                              goto LAB_23e7020b0;
                            }
                            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                            plStack_70 = *(longlong **)(param_1 + 0x68);
                            plStack_68 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            if (plStack_68 != (longlong *)0x0) goto LAB_23e703baa;
                          }
LAB_23e7040be:
                          plStack_a8 = (longlong *)0x0;
                          uVar20 = 0x114;
                          plStack_100 = (longlong *)0x0;
                          pcStack_158 = (code *)0x0;
                          plStack_118 = (longlong *)0x0;
                          plStack_108 = (longlong *)0x0;
                          plStack_148 = (longlong *)0x0;
                          plStack_138 = (longlong *)0x0;
                          plStack_130 = (longlong *)0x0;
                          plStack_120 = (longlong *)0x0;
                          plStack_160 = (longlong *)0x0;
                          pcStack_110 = (code *)0x0;
                          plStack_168 = (longlong *)0x0;
                          plStack_150 = (longlong *)0x0;
                          goto LAB_23e7020b0;
                        }
                        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                        plStack_70 = *(longlong **)(param_1 + 0x68);
                        plStack_68 = *(longlong **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *plVar10 = *plVar10 + -1;
                        if (*plVar10 == 0) {
                          (**(code **)(plVar10[1] + 0x30))();
                        }
                        if (plStack_68 == (longlong *)0x0) goto LAB_23e7040be;
LAB_23e703baa:
                        plStack_150 = (longlong *)0x0;
                        if (plVar2 != (longlong *)plStack_68[3]) {
                          plStack_100 = (longlong *)0x0;
                          plStack_a8 = (longlong *)0x0;
                          uVar20 = 0x114;
                          pcStack_158 = (code *)0x0;
                          plStack_118 = (longlong *)0x0;
                          plStack_108 = (longlong *)0x0;
                          plStack_148 = (longlong *)0x0;
                          plStack_138 = (longlong *)0x0;
                          plStack_130 = (longlong *)0x0;
                          plStack_120 = (longlong *)0x0;
                          plStack_160 = (longlong *)0x0;
                          pcStack_110 = (code *)0x0;
                          plStack_168 = (longlong *)0x0;
                          goto LAB_23e701280;
                        }
LAB_23e703d0f:
                        plStack_100 = (longlong *)0x0;
                        plStack_a8 = (longlong *)0x0;
                        pcStack_158 = (code *)0x0;
                        plStack_118 = (longlong *)0x0;
                        plStack_108 = (longlong *)0x0;
                        plStack_148 = (longlong *)0x0;
                        plStack_138 = (longlong *)0x0;
                        plStack_130 = (longlong *)0x0;
                        plStack_120 = (longlong *)0x0;
                        plStack_160 = (longlong *)0x0;
                        pcStack_110 = (code *)0x0;
                        plStack_168 = (longlong *)0x0;
                        plStack_150 = (longlong *)0x0;
                        plVar9 = plStack_68;
                        goto LAB_23e701333;
                      }
                      plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                      if (plVar12 != (longlong *)0x0) {
                        *plVar12 = *plVar12 + 1;
                        DAT_23ed6a4c0 = plVar12;
                        goto LAB_23e6ff46f;
                      }
LAB_23e704442:
                      plVar8 = plVar15;
                      pcVar19 = pcVar14;
                      PyErr_PrintEx(0);
                      Py_Exit(1);
LAB_23e704455:
                      _DAT_23eedb190 =
                           FUN_23e8cbd60(plVar10,_DAT_23eeda740,
                                         *(undefined8 *)(_DAT_23eeda740 + 0x18));
                      if (_DAT_23eedb190 < 0) {
LAB_23e7044a6:
                        plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeda740);
                        if ((plVar9 != (longlong *)0x0) && (lVar7 = *plVar9, lVar7 != 0))
                        goto LAB_23e6ffc9c;
                        FUN_23e915740(param_1,auStack_78,_DAT_23eeda740);
                        if (plStack_68 != (longlong *)0x0) {
                          if (plVar2 != (longlong *)plStack_68[3]) {
                            plStack_a8 = (longlong *)0x0;
                            uVar20 = 0x118;
                            plStack_100 = (longlong *)0x0;
                            pcStack_158 = (code *)0x0;
                            plStack_118 = (longlong *)0x0;
                            plStack_108 = (longlong *)0x0;
                            plStack_148 = (longlong *)0x0;
                            plStack_138 = (longlong *)0x0;
                            plStack_130 = (longlong *)0x0;
                            plStack_120 = (longlong *)0x0;
                            plStack_160 = (longlong *)0x0;
                            pcStack_110 = (code *)0x0;
                            plStack_168 = (longlong *)0x0;
                            plStack_150 = (longlong *)0x0;
                            goto LAB_23e701280;
                          }
                          goto LAB_23e703d0f;
                        }
                      }
                      else {
                        lVar7 = plVar9[_DAT_23eedb190 * 2 + 1];
LAB_23e70449d:
                        if (lVar7 == 0) goto LAB_23e7044a6;
LAB_23e6ffc9c:
                        *(undefined4 *)(plVar2 + 5) = 0x118;
                        plStack_150 = (longlong *)FUN_23e914090(param_1,lVar7,plStack_140);
                        if (plStack_150 != (longlong *)0x0) {
                          uVar5 = FUN_23a3a0d40(DAT_23ed6cf28);
                          *(undefined4 *)(plVar2 + 5) = 0x11a;
                          plVar9 = (longlong *)FUN_23e94bb80(param_1,uVar5);
                          if (plVar9 == (longlong *)0x0) {
                            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                            plStack_70 = *(longlong **)(param_1 + 0x68);
                            plStack_68 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            if (plStack_68 == (longlong *)0x0) {
                              plStack_a8 = (longlong *)0x0;
                              uVar20 = 0x11a;
                              plStack_100 = (longlong *)0x0;
                              pcStack_158 = (code *)0x0;
                              plStack_118 = (longlong *)0x0;
                              plStack_108 = (longlong *)0x0;
                              plStack_148 = (longlong *)0x0;
                              plStack_138 = (longlong *)0x0;
                              plStack_130 = (longlong *)0x0;
                              plStack_120 = (longlong *)0x0;
                              plStack_160 = (longlong *)0x0;
                              pcStack_110 = (code *)0x0;
                              plStack_168 = (longlong *)0x0;
                              goto LAB_23e7020b0;
                            }
                            if ((longlong *)plStack_68[3] != plVar2) {
                              plStack_a8 = (longlong *)0x0;
                              uVar20 = 0x11a;
                              plStack_100 = (longlong *)0x0;
                              pcStack_158 = (code *)0x0;
                              plStack_118 = (longlong *)0x0;
                              plStack_108 = (longlong *)0x0;
                              plStack_148 = (longlong *)0x0;
                              plStack_138 = (longlong *)0x0;
                              plStack_130 = (longlong *)0x0;
                              plStack_120 = (longlong *)0x0;
                              plStack_160 = (longlong *)0x0;
                              plStack_168 = (longlong *)0x0;
                              pcStack_110 = (code *)0x0;
                              goto LAB_23e701280;
                            }
LAB_23e704751:
                            plStack_a8 = (longlong *)0x0;
                            plStack_100 = (longlong *)0x0;
                            pcStack_158 = (code *)0x0;
                            plStack_118 = (longlong *)0x0;
                            plStack_108 = (longlong *)0x0;
                            plStack_148 = (longlong *)0x0;
                            plStack_138 = (longlong *)0x0;
                            plStack_130 = (longlong *)0x0;
                            plStack_120 = (longlong *)0x0;
                            plStack_160 = (longlong *)0x0;
                            pcStack_110 = (code *)0x0;
                            plStack_168 = (longlong *)0x0;
                            plVar9 = plStack_68;
                            goto LAB_23e701333;
                          }
                          lVar7 = *plVar9;
                          *plVar9 = lVar7 + -1;
                          if (lVar7 + -1 == 0) {
                            FUN_23a334bc0(plVar9);
                          }
                          uVar5 = FUN_23a3a0d40(DAT_23ed6cf28);
                          *(undefined4 *)(plVar2 + 5) = 0x11b;
                          plVar9 = (longlong *)FUN_23e94bb80(param_1,uVar5,_DAT_23eeda750);
                          if (plVar9 == (longlong *)0x0) {
                            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                            plStack_70 = *(longlong **)(param_1 + 0x68);
                            plStack_68 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            if (plStack_68 != (longlong *)0x0) {
                              if ((longlong *)plStack_68[3] == plVar2) goto LAB_23e704751;
                              plStack_a8 = (longlong *)0x0;
                              uVar20 = 0x11b;
                              plStack_100 = (longlong *)0x0;
                              pcStack_158 = (code *)0x0;
                              plStack_118 = (longlong *)0x0;
                              plStack_108 = (longlong *)0x0;
                              plStack_148 = (longlong *)0x0;
                              plStack_138 = (longlong *)0x0;
                              plStack_130 = (longlong *)0x0;
                              plStack_120 = (longlong *)0x0;
                              plStack_160 = (longlong *)0x0;
                              plStack_168 = (longlong *)0x0;
                              pcStack_110 = (code *)0x0;
                              goto LAB_23e701280;
                            }
                            plStack_a8 = (longlong *)0x0;
                            uVar20 = 0x11b;
                            plStack_100 = (longlong *)0x0;
                            pcStack_158 = (code *)0x0;
                            plStack_118 = (longlong *)0x0;
                            plStack_108 = (longlong *)0x0;
                            plStack_148 = (longlong *)0x0;
                            plStack_138 = (longlong *)0x0;
                            plStack_130 = (longlong *)0x0;
                            plStack_120 = (longlong *)0x0;
                            plStack_160 = (longlong *)0x0;
                            pcStack_110 = (code *)0x0;
                            plStack_168 = (longlong *)0x0;
                          }
                          else {
                            lVar7 = *plVar9;
                            *plVar9 = lVar7 + -1;
                            if (lVar7 + -1 == 0) {
                              FUN_23a334bc0(plVar9);
                            }
                            FUN_23a3a0d40(DAT_23ed6cf28);
                            *(undefined4 *)(plVar2 + 5) = 0x11c;
                            plVar9 = (longlong *)FUN_23e94bb80();
                            if (plVar9 == (longlong *)0x0) {
                              auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                              plStack_70 = *(longlong **)(param_1 + 0x68);
                              plStack_68 = *(longlong **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              if (plStack_68 != (longlong *)0x0) {
                                if ((longlong *)plStack_68[3] == plVar2) goto LAB_23e704751;
                                plStack_a8 = (longlong *)0x0;
                                plStack_100 = (longlong *)0x0;
                                pcStack_158 = (code *)0x0;
                                plStack_118 = (longlong *)0x0;
                                plStack_108 = (longlong *)0x0;
                                plStack_148 = (longlong *)0x0;
                                uVar20 = 0x11c;
                                plStack_138 = (longlong *)0x0;
                                plStack_130 = (longlong *)0x0;
                                plStack_120 = (longlong *)0x0;
                                plStack_160 = (longlong *)0x0;
                                plStack_168 = (longlong *)0x0;
                                pcStack_110 = (code *)0x0;
                                goto LAB_23e701280;
                              }
                              plStack_a8 = (longlong *)0x0;
                              uVar20 = 0x11c;
                              plStack_100 = (longlong *)0x0;
                              pcStack_158 = (code *)0x0;
                              plStack_118 = (longlong *)0x0;
                              plStack_108 = (longlong *)0x0;
                              plStack_148 = (longlong *)0x0;
                              plStack_138 = (longlong *)0x0;
                              plStack_130 = (longlong *)0x0;
                              plStack_120 = (longlong *)0x0;
                              plStack_160 = (longlong *)0x0;
                              pcStack_110 = (code *)0x0;
                              plStack_168 = (longlong *)0x0;
                            }
                            else {
                              lVar7 = *plVar9;
                              *plVar9 = lVar7 + -1;
                              if (lVar7 + -1 == 0) {
                                FUN_23a334bc0(plVar9);
                              }
                              uVar13 = FUN_23a3a0d40(DAT_23ed6cf28);
                              plVar9 = _DAT_23eeda758;
                              plVar10 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3)
                              ;
                              *plVar9 = *plVar9 + 1;
                              uVar5 = DAT_23eeda598;
                              plVar10[3] = (longlong)plVar9;
                              plVar9 = (longlong *)FUN_23e8bc2f0(plStack_150,uVar5);
                              if (plVar9 == (longlong *)0x0) {
LAB_23e704667:
                                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                plStack_70 = *(longlong **)(param_1 + 0x68);
                                plStack_68 = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *plVar10 = *plVar10 + -1;
                                if (*plVar10 == 0) {
                                  FUN_23a334bc0();
                                  if (plStack_68 == (longlong *)0x0) goto LAB_23e706346;
                                  plVar9 = (longlong *)plStack_68[3];
                                }
                                else {
                                  if (plStack_68 == (longlong *)0x0) goto LAB_23e706346;
                                  plVar9 = (longlong *)plStack_68[3];
                                }
                                if (plVar2 != plVar9) {
                                  plStack_a8 = (longlong *)0x0;
                                  uVar20 = 0x11d;
                                  plStack_100 = (longlong *)0x0;
                                  pcStack_158 = (code *)0x0;
                                  plStack_118 = (longlong *)0x0;
                                  plStack_108 = (longlong *)0x0;
                                  plStack_148 = (longlong *)0x0;
                                  plStack_138 = (longlong *)0x0;
                                  plStack_130 = (longlong *)0x0;
                                  plStack_120 = (longlong *)0x0;
                                  plStack_160 = (longlong *)0x0;
                                  pcStack_110 = (code *)0x0;
                                  plStack_168 = (longlong *)0x0;
                                  goto LAB_23e701280;
                                }
                                goto LAB_23e704751;
                              }
                              lVar7 = FUN_23e94f9d0(param_1,plVar9);
                              *plVar9 = *plVar9 + -1;
                              if (*plVar9 == 0) {
                                FUN_23a334bc0();
                              }
                              plVar9 = _DAT_23eeda760;
                              if (lVar7 == 0) goto LAB_23e704667;
                              plVar10[4] = lVar7;
                              *plVar9 = *plVar9 + 1;
                              plVar10[5] = (longlong)plVar9;
                              plVar9 = (longlong *)(*pcStack_158)(DAT_23ed6cd28,plVar10);
                              *plVar10 = *plVar10 + -1;
                              if (*plVar10 == 0) {
                                FUN_23a334bc0();
                              }
                              if (plVar9 != (longlong *)0x0) {
                                *(undefined4 *)(plVar2 + 5) = 0x11d;
                                plVar10 = (longlong *)FUN_23e914090(param_1,uVar13,plVar9);
                                lVar7 = *plVar9;
                                *plVar9 = lVar7 + -1;
                                if (lVar7 + -1 == 0) {
                                  FUN_23a334bc0();
                                }
                                if (plVar10 == (longlong *)0x0) {
                                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                  plStack_70 = *(longlong **)(param_1 + 0x68);
                                  plStack_68 = *(longlong **)(param_1 + 0x70);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  if (plStack_68 == (longlong *)0x0) goto LAB_23e706346;
                                  if (plVar2 == (longlong *)plStack_68[3]) goto LAB_23e704751;
                                  plStack_a8 = (longlong *)0x0;
                                  uVar20 = 0x11d;
                                  plStack_100 = (longlong *)0x0;
                                  pcStack_158 = (code *)0x0;
                                  plStack_118 = (longlong *)0x0;
                                  plStack_108 = (longlong *)0x0;
                                  plStack_148 = (longlong *)0x0;
                                  plStack_138 = (longlong *)0x0;
                                  plStack_130 = (longlong *)0x0;
                                  plStack_120 = (longlong *)0x0;
                                  plStack_160 = (longlong *)0x0;
                                  pcStack_110 = (code *)0x0;
                                  plStack_168 = (longlong *)0x0;
                                  goto LAB_23e701280;
                                }
                                lVar7 = *plVar10;
                                *plVar10 = lVar7 + -1;
                                if (lVar7 + -1 == 0) {
                                  FUN_23a334bc0(plVar10);
                                }
                                uVar5 = FUN_23a3a0d40(DAT_23ed6cf28);
                                *(undefined4 *)(plVar2 + 5) = 0x11e;
                                plVar9 = (longlong *)FUN_23e94bb80(param_1,uVar5,_DAT_23eeda768);
                                if (plVar9 == (longlong *)0x0) {
                                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                  plStack_70 = *(longlong **)(param_1 + 0x68);
                                  plStack_68 = *(longlong **)(param_1 + 0x70);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  if (plStack_68 != (longlong *)0x0) {
                                    if ((longlong *)plStack_68[3] == plVar2) goto LAB_23e704751;
                                    plStack_a8 = (longlong *)0x0;
                                    plStack_100 = (longlong *)0x0;
                                    uVar20 = 0x11e;
                                    pcStack_158 = (code *)0x0;
                                    plStack_118 = (longlong *)0x0;
                                    plStack_108 = (longlong *)0x0;
                                    plStack_148 = (longlong *)0x0;
                                    plStack_138 = (longlong *)0x0;
                                    plStack_130 = (longlong *)0x0;
                                    plStack_120 = (longlong *)0x0;
                                    plStack_160 = (longlong *)0x0;
                                    plStack_168 = (longlong *)0x0;
                                    pcStack_110 = (code *)0x0;
                                    goto LAB_23e701280;
                                  }
                                  plStack_a8 = (longlong *)0x0;
                                  uVar20 = 0x11e;
                                  plStack_100 = (longlong *)0x0;
                                  pcStack_158 = (code *)0x0;
                                  plStack_118 = (longlong *)0x0;
                                  plStack_108 = (longlong *)0x0;
                                  plStack_148 = (longlong *)0x0;
                                  plStack_138 = (longlong *)0x0;
                                  plStack_130 = (longlong *)0x0;
                                  plStack_120 = (longlong *)0x0;
                                  plStack_160 = (longlong *)0x0;
                                  pcStack_110 = (code *)0x0;
                                  plStack_168 = (longlong *)0x0;
                                }
                                else {
                                  lVar7 = *plVar9;
                                  *plVar9 = lVar7 + -1;
                                  if (lVar7 + -1 == 0) {
                                    FUN_23a334bc0(plVar9);
                                  }
                                  uVar5 = FUN_23a3a0d40(DAT_23ed6cf28);
                                  *(undefined4 *)(plVar2 + 5) = 0x11f;
                                  plVar9 = (longlong *)FUN_23e94bb80(param_1,uVar5,_DAT_23eeda770);
                                  if (plVar9 == (longlong *)0x0) {
                                    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                    plStack_70 = *(longlong **)(param_1 + 0x68);
                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    if (plStack_68 != (longlong *)0x0) {
                                      if ((longlong *)plStack_68[3] == plVar2) goto LAB_23e704751;
                                      plStack_a8 = (longlong *)0x0;
                                      plStack_100 = (longlong *)0x0;
                                      uVar20 = 0x11f;
                                      pcStack_158 = (code *)0x0;
                                      plStack_118 = (longlong *)0x0;
                                      plStack_108 = (longlong *)0x0;
                                      plStack_148 = (longlong *)0x0;
                                      plStack_138 = (longlong *)0x0;
                                      plStack_130 = (longlong *)0x0;
                                      plStack_120 = (longlong *)0x0;
                                      plStack_160 = (longlong *)0x0;
                                      plStack_168 = (longlong *)0x0;
                                      pcStack_110 = (code *)0x0;
                                      goto LAB_23e701280;
                                    }
                                    plStack_a8 = (longlong *)0x0;
                                    plStack_100 = (longlong *)0x0;
                                    pcStack_158 = (code *)0x0;
                                    plStack_118 = (longlong *)0x0;
                                    plStack_108 = (longlong *)0x0;
                                    plStack_148 = (longlong *)0x0;
                                    uVar20 = 0x11f;
                                    plStack_138 = (longlong *)0x0;
                                    plStack_130 = (longlong *)0x0;
                                    plStack_120 = (longlong *)0x0;
                                    plStack_160 = (longlong *)0x0;
                                    pcStack_110 = (code *)0x0;
                                    plStack_168 = (longlong *)0x0;
                                  }
                                  else {
                                    lVar7 = *plVar9;
                                    *plVar9 = lVar7 + -1;
                                    if (lVar7 + -1 == 0) {
                                      FUN_23a334bc0(plVar9);
                                    }
                                    uVar5 = FUN_23a3a0d40(DAT_23ed6cf28);
                                    *(undefined4 *)(plVar2 + 5) = 0x120;
                                    plVar9 = (longlong *)FUN_23e94bb80(param_1,uVar5,_DAT_23eeda778)
                                    ;
                                    if (plVar9 == (longlong *)0x0) {
                                      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                      plStack_70 = *(longlong **)(param_1 + 0x68);
                                      plStack_68 = *(longlong **)(param_1 + 0x70);
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      if (plStack_68 != (longlong *)0x0) {
                                        if ((longlong *)plStack_68[3] == plVar2) goto LAB_23e704751;
                                        plStack_a8 = (longlong *)0x0;
                                        uVar20 = 0x120;
                                        plStack_100 = (longlong *)0x0;
                                        pcStack_158 = (code *)0x0;
                                        plStack_118 = (longlong *)0x0;
                                        plStack_108 = (longlong *)0x0;
                                        plStack_148 = (longlong *)0x0;
                                        plStack_138 = (longlong *)0x0;
                                        plStack_130 = (longlong *)0x0;
                                        plStack_120 = (longlong *)0x0;
                                        plStack_160 = (longlong *)0x0;
                                        plStack_168 = (longlong *)0x0;
                                        pcStack_110 = (code *)0x0;
                                        goto LAB_23e701280;
                                      }
                                      plStack_a8 = (longlong *)0x0;
                                      uVar20 = 0x120;
                                      plStack_100 = (longlong *)0x0;
                                      pcStack_158 = (code *)0x0;
                                      plStack_118 = (longlong *)0x0;
                                      plStack_108 = (longlong *)0x0;
                                      plStack_148 = (longlong *)0x0;
                                      plStack_138 = (longlong *)0x0;
                                      plStack_130 = (longlong *)0x0;
                                      plStack_120 = (longlong *)0x0;
                                      plStack_160 = (longlong *)0x0;
                                      pcStack_110 = (code *)0x0;
                                      plStack_168 = (longlong *)0x0;
                                    }
                                    else {
                                      lVar7 = *plVar9;
                                      *plVar9 = lVar7 + -1;
                                      if (lVar7 + -1 == 0) {
                                        FUN_23a334bc0(plVar9);
                                      }
                                      uVar5 = FUN_23a3a0d40(DAT_23ed6cf28);
                                      *(undefined4 *)(plVar2 + 5) = 0x121;
                                      plVar9 = (longlong *)FUN_23e94bb80(param_1,uVar5);
                                      if (plVar9 == (longlong *)0x0) {
                                        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                        plStack_70 = *(longlong **)(param_1 + 0x68);
                                        plStack_68 = *(longlong **)(param_1 + 0x70);
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        if (plStack_68 != (longlong *)0x0) {
                                          if ((longlong *)plStack_68[3] == plVar2)
                                          goto LAB_23e704751;
                                          plStack_a8 = (longlong *)0x0;
                                          uVar20 = 0x121;
                                          plStack_100 = (longlong *)0x0;
                                          pcStack_158 = (code *)0x0;
                                          plStack_118 = (longlong *)0x0;
                                          plStack_108 = (longlong *)0x0;
                                          plStack_148 = (longlong *)0x0;
                                          plStack_138 = (longlong *)0x0;
                                          plStack_130 = (longlong *)0x0;
                                          plStack_120 = (longlong *)0x0;
                                          plStack_160 = (longlong *)0x0;
                                          plStack_168 = (longlong *)0x0;
                                          pcStack_110 = (code *)0x0;
                                          goto LAB_23e701280;
                                        }
                                        plStack_a8 = (longlong *)0x0;
                                        uVar20 = 0x121;
                                        plStack_100 = (longlong *)0x0;
                                        pcStack_158 = (code *)0x0;
                                        plStack_118 = (longlong *)0x0;
                                        plStack_108 = (longlong *)0x0;
                                        plStack_148 = (longlong *)0x0;
                                        plStack_138 = (longlong *)0x0;
                                        plStack_130 = (longlong *)0x0;
                                        plStack_120 = (longlong *)0x0;
                                        plStack_160 = (longlong *)0x0;
                                        pcStack_110 = (code *)0x0;
                                        plStack_168 = (longlong *)0x0;
                                      }
                                      else {
                                        lVar7 = *plVar9;
                                        *plVar9 = lVar7 + -1;
                                        if (lVar7 + -1 == 0) {
                                          FUN_23a334bc0(plVar9);
                                        }
                                        FUN_23a3a0d40(DAT_23ed6cf28);
                                        plVar9 = _DAT_23eeda788;
                                        plVar10 = (longlong *)
                                                  FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
                                        *plVar9 = *plVar9 + 1;
                                        uVar5 = DAT_23eeda618;
                                        plVar10[3] = (longlong)plVar9;
                                        plVar9 = (longlong *)FUN_23e8bc2f0(plStack_150,uVar5);
                                        if (plVar9 == (longlong *)0x0) {
LAB_23e704c90:
                                          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                          plStack_70 = *(longlong **)(param_1 + 0x68);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          *plVar10 = *plVar10 + -1;
                                          if (*plVar10 == 0) {
                                            FUN_23a334bc0();
                                          }
                                          if (plStack_68 != (longlong *)0x0) {
                                            if ((longlong *)plStack_68[3] != plVar2) {
                                              plStack_a8 = (longlong *)0x0;
                                              uVar20 = 0x122;
                                              plStack_100 = (longlong *)0x0;
                                              pcStack_158 = (code *)0x0;
                                              plStack_118 = (longlong *)0x0;
                                              plStack_108 = (longlong *)0x0;
                                              plStack_148 = (longlong *)0x0;
                                              plStack_138 = (longlong *)0x0;
                                              plStack_130 = (longlong *)0x0;
                                              plStack_120 = (longlong *)0x0;
                                              plStack_160 = (longlong *)0x0;
                                              pcStack_110 = (code *)0x0;
                                              plStack_168 = (longlong *)0x0;
                                              goto LAB_23e701280;
                                            }
                                            goto LAB_23e704751;
                                          }
                                        }
                                        else {
                                          lVar7 = FUN_23e94f9d0(param_1,plVar9,DAT_23eeda5d8);
                                          *plVar9 = *plVar9 + -1;
                                          if (*plVar9 == 0) {
                                            FUN_23a334bc0();
                                          }
                                          plVar9 = _DAT_23eeda790;
                                          if (lVar7 == 0) goto LAB_23e704c90;
                                          plVar10[4] = lVar7;
                                          *plVar9 = *plVar9 + 1;
                                          plVar10[5] = (longlong)plVar9;
                                          plVar9 = (longlong *)(*pcStack_158)();
                                          *plVar10 = *plVar10 + -1;
                                          if (*plVar10 == 0) {
                                            FUN_23a334bc0();
                                          }
                                          if (plVar9 != (longlong *)0x0) {
                                            *(undefined4 *)(plVar2 + 5) = 0x122;
                                            plVar10 = (longlong *)FUN_23e914090(param_1);
                                            lVar7 = *plVar9;
                                            *plVar9 = lVar7 + -1;
                                            if (lVar7 + -1 == 0) {
                                              FUN_23a334bc0();
                                            }
                                            if (plVar10 != (longlong *)0x0) {
                                              lVar7 = *plVar10;
                                              *plVar10 = lVar7 + -1;
                                              if (lVar7 + -1 == 0) {
                                                FUN_23a334bc0(plVar10);
                                              }
                                              FUN_23a3a0d40(DAT_23ed6cf28);
                                              *(undefined4 *)(plVar2 + 5) = 0x123;
                                              plVar9 = (longlong *)FUN_23e94bb80();
                                              if (plVar9 == (longlong *)0x0) {
                                                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                                plStack_70 = *(longlong **)(param_1 + 0x68);
                                                plStack_68 = *(longlong **)(param_1 + 0x70);
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                if (plStack_68 != (longlong *)0x0) {
                                                  if ((longlong *)plStack_68[3] == plVar2)
                                                  goto LAB_23e704751;
                                                  plStack_a8 = (longlong *)0x0;
                                                  plStack_100 = (longlong *)0x0;
                                                  uVar20 = 0x123;
                                                  pcStack_158 = (code *)0x0;
                                                  plStack_118 = (longlong *)0x0;
                                                  plStack_108 = (longlong *)0x0;
                                                  plStack_148 = (longlong *)0x0;
                                                  plStack_138 = (longlong *)0x0;
                                                  plStack_130 = (longlong *)0x0;
                                                  plStack_120 = (longlong *)0x0;
                                                  plStack_160 = (longlong *)0x0;
                                                  plStack_168 = (longlong *)0x0;
                                                  pcStack_110 = (code *)0x0;
                                                  goto LAB_23e701280;
                                                }
                                                plStack_a8 = (longlong *)0x0;
                                                uVar20 = 0x123;
                                                plStack_100 = (longlong *)0x0;
                                                pcStack_158 = (code *)0x0;
                                                plStack_118 = (longlong *)0x0;
                                                plStack_108 = (longlong *)0x0;
                                                plStack_148 = (longlong *)0x0;
                                                plStack_138 = (longlong *)0x0;
                                                plStack_130 = (longlong *)0x0;
                                                plStack_120 = (longlong *)0x0;
                                                plStack_160 = (longlong *)0x0;
                                                pcStack_110 = (code *)0x0;
                                                plStack_168 = (longlong *)0x0;
                                              }
                                              else {
                                                lVar7 = *plVar9;
                                                *plVar9 = lVar7 + -1;
                                                if (lVar7 + -1 == 0) {
                                                  FUN_23a334bc0(plVar9);
                                                }
                                                uVar5 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                *(undefined4 *)(plVar2 + 5) = 0x124;
                                                plVar9 = (longlong *)
                                                         FUN_23e94bb80(param_1,uVar5,_DAT_23eeda6a8)
                                                ;
                                                if (plVar9 == (longlong *)0x0) {
                                                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  plStack_70 = *(longlong **)(param_1 + 0x68);
                                                  plStack_68 = *(longlong **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  if (plStack_68 != (longlong *)0x0) {
                                                    if ((longlong *)plStack_68[3] == plVar2)
                                                    goto LAB_23e704751;
                                                    plStack_a8 = (longlong *)0x0;
                                                    plStack_100 = (longlong *)0x0;
                                                    uVar20 = 0x124;
                                                    pcStack_158 = (code *)0x0;
                                                    plStack_118 = (longlong *)0x0;
                                                    plStack_108 = (longlong *)0x0;
                                                    plStack_148 = (longlong *)0x0;
                                                    plStack_138 = (longlong *)0x0;
                                                    plStack_130 = (longlong *)0x0;
                                                    plStack_120 = (longlong *)0x0;
                                                    plStack_160 = (longlong *)0x0;
                                                    plStack_168 = (longlong *)0x0;
                                                    pcStack_110 = (code *)0x0;
                                                    goto LAB_23e701280;
                                                  }
                                                  plStack_a8 = (longlong *)0x0;
                                                  uVar20 = 0x124;
                                                  plStack_100 = (longlong *)0x0;
                                                  pcStack_158 = (code *)0x0;
                                                  plStack_118 = (longlong *)0x0;
                                                  plStack_108 = (longlong *)0x0;
                                                  plStack_148 = (longlong *)0x0;
                                                  plStack_138 = (longlong *)0x0;
                                                  plStack_130 = (longlong *)0x0;
                                                  plStack_120 = (longlong *)0x0;
                                                  plStack_160 = (longlong *)0x0;
                                                  pcStack_110 = (code *)0x0;
                                                  plStack_168 = (longlong *)0x0;
                                                }
                                                else {
                                                  lVar7 = *plVar9;
                                                  *plVar9 = lVar7 + -1;
                                                  if (lVar7 + -1 == 0) {
                                                    FUN_23a334bc0(plVar9);
                                                  }
                                                  plVar9 = (longlong *)
                                                           FUN_23e8bc2f0(plStack_150,DAT_23eeda4e0);
                                                  uVar5 = _DAT_23eeda7a0;
                                                  if (plVar9 == (longlong *)0x0) {
                                                    auStack_78 = *(undefined1 (*) [8])
                                                                  (param_1 + 0x60);
                                                    plStack_70 = *(longlong **)(param_1 + 0x68);
                                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    if (plStack_68 != (longlong *)0x0) {
                                                      if ((longlong *)plStack_68[3] == plVar2)
                                                      goto LAB_23e704751;
                                                      plStack_a8 = (longlong *)0x0;
                                                      uVar20 = 0x126;
                                                      plStack_100 = (longlong *)0x0;
                                                      pcStack_158 = (code *)0x0;
                                                      plStack_118 = (longlong *)0x0;
                                                      plStack_108 = (longlong *)0x0;
                                                      plStack_148 = (longlong *)0x0;
                                                      plStack_138 = (longlong *)0x0;
                                                      plStack_130 = (longlong *)0x0;
                                                      plStack_120 = (longlong *)0x0;
                                                      plStack_160 = (longlong *)0x0;
                                                      plStack_168 = (longlong *)0x0;
                                                      pcStack_110 = (code *)0x0;
                                                      goto LAB_23e701280;
                                                    }
                                                  }
                                                  else {
                                                    plStack_168 = (longlong *)_PyDict_NewPresized(3)
                                                    ;
                                                    iVar4 = PyDict_SetItem(plStack_168,plVar9,uVar5)
                                                    ;
                                                    lVar7 = *plVar9;
                                                    *plVar9 = lVar7 + -1;
                                                    if (lVar7 + -1 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    if ((iVar4 == 0) &&
                                                       (plVar9 = (longlong *)
                                                                 FUN_23e8bc2f0(plStack_150,
                                                                               DAT_23eeda5a8),
                                                       plVar9 != (longlong *)0x0)) {
                                                      iVar4 = PyDict_SetItem(plStack_168,plVar9,
                                                                             _DAT_23eeda7a8);
                                                      *plVar9 = *plVar9 + -1;
                                                      if (*plVar9 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      if ((iVar4 == 0) &&
                                                         (plVar9 = (longlong *)
                                                                   FUN_23e8bc2f0(plStack_150,
                                                                                 DAT_23eeda580),
                                                         plVar9 != (longlong *)0x0)) {
                                                        iVar4 = PyDict_SetItem(plStack_168,plVar9,
                                                                               _DAT_23eeda7b0);
                                                        *plVar9 = *plVar9 + -1;
                                                        if (*plVar9 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                        if (iVar4 == 0) {
                                                          plVar9 = (longlong *)0x0;
                                                          plStack_100 = (longlong *)0x0;
                                                          plStack_d8 = (longlong *)0x0;
                                                          plStack_d0 = (longlong *)0x0;
                                                          plStack_a0 = (longlong *)0x0;
                                                          plStack_a8 = (longlong *)0x0;
                                                          plStack_b0 = (longlong *)0x0;
                                                          plStack_b8 = (longlong *)0x0;
                                                          plStack_c0 = (longlong *)0x0;
                                                          plStack_c8 = (longlong *)0x0;
                                                          pcStack_110 = (code *)0x0;
                                                          while( true ) {
                                                            *(undefined4 *)(plVar2 + 5) = 0x12a;
                                                            pcVar14 = (code *)FUN_23e91bfe0(param_1,
                                                  plVar6,_DAT_23eeda7b8);
                                                  if (pcVar14 == (code *)0x0) break;
                                                  if ((pcStack_110 != (code *)0x0) &&
                                                     (*(longlong *)pcStack_110 =
                                                           *(longlong *)pcStack_110 + -1,
                                                     *(longlong *)pcStack_110 == 0)) {
                                                    FUN_23a334bc0(pcStack_110);
                                                  }
                                                  uVar20 = (undefined4)
                                                           ((ulonglong)in_stack_fffffffffffffe08 >>
                                                           0x20);
                                                  pcStack_110 = pcVar14;
                                                  if (pcVar14 != _Py_NoneStruct_exref) {
                                                    *(undefined4 *)(plVar2 + 5) = 0x131;
                                                    plVar10 = (longlong *)
                                                              FUN_23e915840(param_1,plStack_150,
                                                                            _DAT_23eeda7e8);
                                                    if (plVar10 == (longlong *)0x0) {
LAB_23e707661:
                                                      auVar21 = *(undefined1 (*) [8])
                                                                 (param_1 + 0x60);
                                                      plVar12 = *(longlong **)(param_1 + 0x68);
                                                      plVar10 = *(longlong **)(param_1 + 0x70);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                    }
                                                    else {
                                                      plVar11 = (longlong *)FUN_23a388310();
                                                      *plVar10 = *plVar10 + -1;
                                                      if (*plVar10 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      if (plVar11 == (longlong *)0x0)
                                                      goto LAB_23e707661;
                                                      uVar5 = CONCAT44(uVar20,7);
                                                      plStack_160 = (longlong *)
                                                                    FUN_23a3c1d30(param_1,auStack_78
                                                                                  ,plVar11,0,uVar5);
                                                      if (plStack_160 == (longlong *)0x0) {
                                                        plVar16 = (longlong *)0x0;
                                                        plVar15 = (longlong *)0x0;
                                                        plStack_148 = (longlong *)0x0;
                                                        plStack_138 = (longlong *)0x0;
                                                        lVar7 = *plVar11;
                                                        plStack_130 = (longlong *)0x0;
                                                        plStack_120 = (longlong *)0x0;
                                                      }
                                                      else {
                                                        uVar5 = CONCAT44((int)((ulonglong)uVar5 >>
                                                                              0x20),7);
                                                        plVar15 = (longlong *)
                                                                  FUN_23a3c1d30(param_1,auStack_78,
                                                                                plVar11,1,uVar5);
                                                        if (plVar15 == (longlong *)0x0) {
                                                          plVar16 = (longlong *)0x0;
                                                          plStack_148 = (longlong *)0x0;
                                                          plStack_138 = (longlong *)0x0;
                                                          plStack_130 = (longlong *)0x0;
                                                          plStack_120 = (longlong *)0x0;
                                                          lVar7 = *plVar11;
                                                        }
                                                        else {
                                                          uVar5 = CONCAT44((int)((ulonglong)uVar5 >>
                                                                                0x20),7);
                                                          plStack_120 = (longlong *)
                                                                        FUN_23a3c1d30(param_1,
                                                  auStack_78,plVar11,2,uVar5);
                                                  if (plStack_120 == (longlong *)0x0) {
                                                    plVar16 = (longlong *)0x0;
                                                    plStack_148 = (longlong *)0x0;
                                                    plStack_138 = (longlong *)0x0;
                                                    plStack_130 = (longlong *)0x0;
                                                    lVar7 = *plVar11;
                                                  }
                                                  else {
                                                    uVar5 = CONCAT44((int)((ulonglong)uVar5 >> 0x20)
                                                                     ,7);
                                                    plStack_130 = (longlong *)
                                                                  FUN_23a3c1d30(param_1,auStack_78,
                                                                                plVar11,3,uVar5);
                                                    if (plStack_130 == (longlong *)0x0) {
                                                      plStack_148 = (longlong *)0x0;
                                                      lVar7 = *plVar11;
                                                      plVar16 = (longlong *)0x0;
                                                      plStack_138 = (longlong *)0x0;
                                                    }
                                                    else {
                                                      uVar5 = CONCAT44((int)((ulonglong)uVar5 >>
                                                                            0x20),7);
                                                      plStack_138 = (longlong *)
                                                                    FUN_23a3c1d30(param_1,auStack_78
                                                                                  ,plVar11,4,uVar5);
                                                      if (plStack_138 == (longlong *)0x0) {
                                                        plVar16 = (longlong *)0x0;
                                                        plStack_148 = (longlong *)0x0;
                                                        lVar7 = *plVar11;
                                                      }
                                                      else {
                                                        uVar5 = CONCAT44((int)((ulonglong)uVar5 >>
                                                                              0x20),7);
                                                        plVar16 = (longlong *)
                                                                  FUN_23a3c1d30(param_1,auStack_78,
                                                                                plVar11,5,uVar5);
                                                        if (plVar16 == (longlong *)0x0) {
                                                          lVar7 = *plVar11;
                                                          plStack_148 = (longlong *)0x0;
                                                        }
                                                        else {
                                                          in_stack_fffffffffffffe08 =
                                                               CONCAT44((int)((ulonglong)uVar5 >>
                                                                             0x20),7);
                                                          plStack_148 = (longlong *)
                                                                        FUN_23a3c1d30(param_1,
                                                  auStack_78,plVar11,6,in_stack_fffffffffffffe08);
                                                  if (plStack_148 == (longlong *)0x0) {
                                                    lVar7 = *plVar11;
                                                  }
                                                  else {
                                                    cVar3 = FUN_23a3884a0(param_1,auStack_78,plVar11
                                                                         );
                                                    lVar7 = *plVar11;
                                                    if (cVar3 != '\0') {
                                                      *plVar11 = lVar7 + -1;
                                                      if (lVar7 + -1 == 0) {
                                                        FUN_23a334bc0(plVar11);
                                                      }
                                                      *plStack_160 = *plStack_160 + 1;
                                                      if ((plStack_c8 != (longlong *)0x0) &&
                                                         (lVar7 = *plStack_c8,
                                                         *plStack_c8 = lVar7 + -1, lVar7 + -1 == 0))
                                                      {
                                                        FUN_23a334bc0(plStack_c8);
                                                      }
                                                      *plStack_160 = *plStack_160 + -1;
                                                      if (*plStack_160 == 0) {
                                                        FUN_23a334bc0(plStack_160);
                                                      }
                                                      *plVar15 = *plVar15 + 1;
                                                      if ((plStack_c0 != (longlong *)0x0) &&
                                                         (lVar7 = *plStack_c0,
                                                         *plStack_c0 = lVar7 + -1, lVar7 + -1 == 0))
                                                      {
                                                        FUN_23a334bc0(plStack_c0);
                                                      }
                                                      *plVar15 = *plVar15 + -1;
                                                      if (*plVar15 == 0) {
                                                        FUN_23a334bc0(plVar15);
                                                      }
                                                      *plStack_120 = *plStack_120 + 1;
                                                      *plVar15 = *plVar15 + -1;
                                                      if (*plVar15 == 0) {
                                                        FUN_23a334bc0(plVar15);
                                                      }
                                                      lVar7 = *plStack_120;
                                                      *plStack_120 = lVar7 + -1;
                                                      if (lVar7 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_120);
                                                      }
                                                      *plStack_130 = *plStack_130 + 1;
                                                      if ((plStack_b8 != (longlong *)0x0) &&
                                                         (lVar7 = *plStack_b8,
                                                         *plStack_b8 = lVar7 + -1, lVar7 + -1 == 0))
                                                      {
                                                        FUN_23a334bc0(plStack_b8);
                                                      }
                                                      lVar7 = *plStack_130;
                                                      *plStack_130 = lVar7 + -1;
                                                      if (lVar7 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_130);
                                                      }
                                                      *plStack_138 = *plStack_138 + 1;
                                                      if ((plStack_b0 != (longlong *)0x0) &&
                                                         (lVar7 = *plStack_b0,
                                                         *plStack_b0 = lVar7 + -1, lVar7 + -1 == 0))
                                                      {
                                                        FUN_23a334bc0(plStack_b0);
                                                      }
                                                      lVar7 = *plStack_138;
                                                      *plStack_138 = lVar7 + -1;
                                                      if (lVar7 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_138);
                                                      }
                                                      *plVar16 = *plVar16 + 1;
                                                      if ((plStack_a8 != (longlong *)0x0) &&
                                                         (lVar7 = *plStack_a8,
                                                         *plStack_a8 = lVar7 + -1, lVar7 + -1 == 0))
                                                      {
                                                        FUN_23a334bc0(plStack_a8);
                                                      }
                                                      *plVar16 = *plVar16 + -1;
                                                      if (*plVar16 == 0) {
                                                        FUN_23a334bc0(plVar16);
                                                      }
                                                      *plStack_148 = *plStack_148 + 1;
                                                      if ((plStack_a0 != (longlong *)0x0) &&
                                                         (lVar7 = *plStack_a0,
                                                         *plStack_a0 = lVar7 + -1, lVar7 + -1 == 0))
                                                      {
                                                        FUN_23a334bc0(plStack_a0);
                                                      }
                                                      lVar7 = *plStack_148;
                                                      *plStack_148 = lVar7 + -1;
                                                      if (lVar7 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_148);
                                                      }
                                                      lVar7 = FUN_23e8e19b0();
                                                      plStack_a8 = plVar16;
                                                      if (lVar7 == 0) {
                                                        FUN_23e915740(param_1,auStack_78,
                                                                      DAT_23eeda520);
                                                      }
                                                      else {
                                                        *(undefined4 *)(plVar2 + 5) = 0x133;
                                                        plStack_108 = (longlong *)
                                                                      FUN_23e915840(param_1,lVar7,
                                                                                    _DAT_23eeda7f0);
                                                        if (plStack_108 != (longlong *)0x0) {
                                                          if ((plStack_d0 != (longlong *)0x0) &&
                                                             (lVar7 = *plStack_d0,
                                                             *plStack_d0 = lVar7 + -1,
                                                             lVar7 + -1 == 0)) {
                                                            FUN_23a334bc0(plStack_d0);
                                                          }
                                                          plVar11 = (longlong *)
                                                                    FUN_23e8bc2f0(plStack_150,
                                                                                  DAT_23eeda4e8);
                                                          plVar10 = _DAT_23eeda800;
                                                          if (plVar11 == (longlong *)0x0) {
LAB_23e706f8a:
                                                            plStack_68 = *(longlong **)
                                                                          (param_1 + 0x70);
                                                            auStack_78 = *(undefined1 (*) [8])
                                                                          (param_1 + 0x60);
                                                            uVar5 = 0x134;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            plStack_118 = plStack_d8;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            pcStack_158 = (code *)plVar9;
                                                            plStack_70 = *(longlong **)
                                                                          (param_1 + 0x68);
                                                          }
                                                          else {
                                                            plStack_118 = (longlong *)
                                                                          FUN_23e973620(plStack_168,
                                                                                        plVar11);
                                                            if (plStack_118 == (longlong *)0x0) {
                                                              if (*(longlong *)(param_1 + 0x60) != 0
                                                                 ) {
                                                                *plVar11 = *plVar11 + -1;
                                                                if (*plVar11 == 0) {
                                                                  FUN_23a334bc0(plVar11);
                                                                }
                                                                goto LAB_23e706f8a;
                                                              }
                                                              *plVar10 = *plVar10 + 1;
                                                              plStack_118 = plVar10;
                                                            }
                                                            *plVar11 = *plVar11 + -1;
                                                            if (*plVar11 == 0) {
                                                              FUN_23a334bc0(plVar11);
                                                            }
                                                            if ((plStack_d8 != (longlong *)0x0) &&
                                                               (lVar7 = *plStack_d8,
                                                               *plStack_d8 = lVar7 + -1,
                                                               lVar7 + -1 == 0)) {
                                                              FUN_23a334bc0(plStack_d8);
                                                            }
                                                            iVar4 = FUN_23e97de20(plStack_148,
                                                                                  DAT_23ed6ccf0);
                                                            plVar10 = _DAT_23eeda808;
                                                            if (iVar4 == -1) {
                                                              auStack_78 = *(undefined1 (*) [8])
                                                                            (param_1 + 0x60);
                                                              plStack_68 = *(longlong **)
                                                                            (param_1 + 0x70);
                                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                                              uVar5 = 0x136;
                                                              *(undefined1 (*) [16])(param_1 + 0x60)
                                                                   = (undefined1  [16])0x0;
                                                              pcStack_158 = (code *)plVar9;
                                                              plStack_70 = *(longlong **)
                                                                            (param_1 + 0x68);
                                                              goto LAB_23e704f37;
                                                            }
                                                            if (iVar4 == 1) {
                                                              plVar11 = (longlong *)
                                                                        FUN_23e916ad0(*(undefined8 *
                                                                                       )(param_1 +
                                                                                        0x10),7);
                                                              *plVar10 = *plVar10 + 1;
                                                              plVar11[3] = (longlong)plVar10;
                                                              lVar7 = FUN_23e94f9d0(param_1,
                                                  plStack_108,DAT_23ed6cd28);
                                                  if (lVar7 == 0) {
LAB_23e706e52:
                                                    auStack_78 = *(undefined1 (*) [8])
                                                                  (param_1 + 0x60);
                                                    plStack_70 = *(longlong **)(param_1 + 0x68);
                                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *plVar11 = *plVar11 + -1;
                                                    if (*plVar11 == 0) {
                                                      FUN_23a334bc0(plVar11);
                                                    }
                                                  }
                                                  else {
                                                    plVar11[4] = lVar7;
                                                    plVar10 = _DAT_23eeda810;
                                                    *_DAT_23eeda810 = *_DAT_23eeda810 + 1;
                                                    plVar11[5] = (longlong)plVar10;
                                                    lVar7 = FUN_23e94f9d0(param_1,plStack_148,
                                                                          DAT_23ed6cd28);
                                                    if (lVar7 == 0) goto LAB_23e706e52;
                                                    plVar11[6] = lVar7;
                                                    plVar10 = _DAT_23eeda818;
                                                    *_DAT_23eeda818 = *_DAT_23eeda818 + 1;
                                                    plVar11[7] = (longlong)plVar10;
                                                    lVar7 = FUN_23e94f9d0(param_1,plVar16);
                                                    if (lVar7 == 0) goto LAB_23e706e52;
                                                    plVar11[8] = lVar7;
                                                    plVar10 = _DAT_23eeda820;
                                                    *_DAT_23eeda820 = *_DAT_23eeda820 + 1;
                                                    plVar11[9] = (longlong)plVar10;
                                                    plVar10 = (longlong *)
                                                              (*pcStack_158)(DAT_23ed6cd28,plVar11);
                                                    *plVar11 = *plVar11 + -1;
                                                    if (*plVar11 == 0) {
                                                      FUN_23a334bc0(plVar11);
                                                    }
                                                    if (plVar10 != (longlong *)0x0) {
                                                      if ((plVar9 != (longlong *)0x0) &&
                                                         (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
                                                        FUN_23a334bc0(plVar9);
                                                      }
                                                      uVar5 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                      plVar9 = _DAT_23eeda828;
                                                      plVar11 = (longlong *)
                                                                FUN_23e916ad0(*(undefined8 *)
                                                                               (param_1 + 0x10),2);
                                                      *plVar9 = *plVar9 + 1;
                                                      plVar11[3] = (longlong)plVar9;
                                                      *plVar10 = *plVar10 + 1;
                                                      plVar11[4] = (longlong)plVar10;
                                                      lVar7 = (*pcStack_158)(DAT_23ed6cd28,plVar11);
                                                      *plVar11 = *plVar11 + -1;
                                                      if (*plVar11 == 0) {
                                                        FUN_23a334bc0(plVar11);
                                                      }
                                                      if (lVar7 != 0) {
                                                        plVar9 = (longlong *)
                                                                 FUN_23e916ad0(*(undefined8 *)
                                                                                (param_1 + 0x10),1);
                                                        uVar13 = _DAT_23eeda830;
                                                        plVar9[3] = lVar7;
                                                        plVar11 = (longlong *)
                                                                  FUN_23e8d7870(param_1,uVar13);
                                                        *(undefined4 *)(plVar2 + 5) = 0x138;
                                                        plVar12 = (longlong *)
                                                                  FUN_23a334c60(param_1,uVar5,plVar9
                                                                               );
                                                        *plVar9 = *plVar9 + -1;
                                                        if (*plVar9 == 0) {
                                                          FUN_23a334bc0(plVar9);
                                                        }
                                                        *plVar11 = *plVar11 + -1;
                                                        if (*plVar11 == 0) {
                                                          FUN_23a334bc0(plVar11);
                                                        }
                                                        if (plVar12 != (longlong *)0x0) {
                                                          *plVar12 = *plVar12 + -1;
                                                          plVar9 = plVar10;
                                                          if (*plVar12 == 0) {
                                                            FUN_23a334bc0(plVar12);
                                                          }
LAB_23e70107e:
                                                          cVar3 = FUN_23a3a5fe0(param_1);
                                                          plStack_c8 = plStack_160;
                                                          if (cVar3 != '\0') goto LAB_23e70108e;
                                                          auStack_78 = *(undefined1 (*) [8])
                                                                        (param_1 + 0x60);
                                                          plStack_68 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          uVar5 = 0x129;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          pcStack_158 = (code *)plVar9;
                                                          plStack_70 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                          goto LAB_23e704f37;
                                                        }
                                                      }
                                                      auStack_78 = *(undefined1 (*) [8])
                                                                    (param_1 + 0x60);
                                                      plStack_68 = *(longlong **)(param_1 + 0x70);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      uVar5 = 0x138;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      pcStack_158 = (code *)plVar10;
                                                      plStack_70 = *(longlong **)(param_1 + 0x68);
                                                      goto LAB_23e704f37;
                                                    }
                                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                                    auStack_78 = *(undefined1 (*) [8])
                                                                  (param_1 + 0x60);
                                                    plStack_70 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  uVar5 = 0x137;
                                                  pcStack_158 = (code *)plVar9;
                                                  goto LAB_23e704f37;
                                                  }
                                                  iVar4 = FUN_23a35f020(plStack_138);
                                                  if (iVar4 == -1) {
                                                    auStack_78 = *(undefined1 (*) [8])
                                                                  (param_1 + 0x60);
                                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    uVar5 = 0x139;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    pcStack_158 = (code *)plVar9;
                                                    plStack_70 = *(longlong **)(param_1 + 0x68);
                                                    goto LAB_23e704f37;
                                                  }
                                                  if (iVar4 != 0) {
                                                    uVar5 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                    plVar10 = _DAT_23eeda838;
                                                    plVar11 = (longlong *)
                                                              FUN_23e916ad0(*(undefined8 *)
                                                                             (param_1 + 0x10),0xb);
                                                    *plVar10 = *plVar10 + 1;
                                                    plVar11[3] = (longlong)plVar10;
                                                    lVar7 = FUN_23e94f9d0(param_1,plStack_108,
                                                                          DAT_23ed6cd28);
                                                    if (lVar7 == 0) {
LAB_23e706410:
                                                      auStack_78 = *(undefined1 (*) [8])
                                                                    (param_1 + 0x60);
                                                      plStack_70 = *(longlong **)(param_1 + 0x68);
                                                      plStack_68 = *(longlong **)(param_1 + 0x70);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *plVar11 = *plVar11 + -1;
                                                      if (*plVar11 == 0) {
                                                        FUN_23a334bc0(plVar11);
                                                      }
                                                    }
                                                    else {
                                                      plVar11[4] = lVar7;
                                                      plVar10 = _DAT_23eeda840;
                                                      *_DAT_23eeda840 = *_DAT_23eeda840 + 1;
                                                      plVar11[5] = (longlong)plVar10;
                                                      lVar7 = FUN_23e94f9d0(param_1,plStack_118,
                                                                            DAT_23ed6cd28);
                                                      if (lVar7 == 0) goto LAB_23e706410;
                                                      plVar11[6] = lVar7;
                                                      plVar10 = _DAT_23eeda848;
                                                      *_DAT_23eeda848 = *_DAT_23eeda848 + 1;
                                                      plVar11[7] = (longlong)plVar10;
                                                      lVar7 = FUN_23e94f9d0(param_1,plStack_160,
                                                                            DAT_23ed6cd28);
                                                      if (lVar7 == 0) goto LAB_23e706410;
                                                      plVar11[8] = lVar7;
                                                      plVar10 = _DAT_23eeda850;
                                                      uVar13 = DAT_23eeda4f8;
                                                      *_DAT_23eeda850 = *_DAT_23eeda850 + 1;
                                                      plVar11[9] = (longlong)plVar10;
                                                      plVar10 = (longlong *)
                                                                FUN_23e8bc2f0(plStack_150,uVar13);
                                                      if (plVar10 == (longlong *)0x0)
                                                      goto LAB_23e706410;
                                                      lVar7 = FUN_23e94f9d0(param_1,plVar10,
                                                                            DAT_23ed6cd28);
                                                      *plVar10 = *plVar10 + -1;
                                                      if (*plVar10 == 0) {
                                                        FUN_23a334bc0(plVar10);
                                                      }
                                                      if (lVar7 == 0) goto LAB_23e706410;
                                                      plVar11[10] = lVar7;
                                                      plVar10 = _DAT_23eeda858;
                                                      uVar13 = DAT_23eeda608;
                                                      *_DAT_23eeda858 = *_DAT_23eeda858 + 1;
                                                      plVar11[0xb] = (longlong)plVar10;
                                                      lVar7 = FUN_23e94f9d0(param_1,plVar16,uVar13);
                                                      if (lVar7 == 0) goto LAB_23e706410;
                                                      plVar11[0xc] = lVar7;
                                                      plVar12 = _DAT_23eeda860;
                                                      plVar10 = DAT_23ed6cd28;
                                                      *_DAT_23eeda860 = *_DAT_23eeda860 + 1;
                                                      plVar11[0xd] = (longlong)plVar12;
                                                      plVar10 = (longlong *)
                                                                (*pcStack_158)(plVar10,plVar11);
                                                      *plVar11 = *plVar11 + -1;
                                                      if (*plVar11 == 0) {
                                                        FUN_23a334bc0(plVar11);
                                                      }
                                                      if (plVar10 != (longlong *)0x0) {
                                                        *(undefined4 *)(plVar2 + 5) = 0x13a;
                                                        plVar11 = (longlong *)
                                                                  FUN_23e914090(param_1,uVar5);
                                                        *plVar10 = *plVar10 + -1;
                                                        if (*plVar10 == 0) {
                                                          FUN_23a334bc0(plVar10);
                                                        }
                                                        if (plVar11 != (longlong *)0x0) {
                                                          *plVar11 = *plVar11 + -1;
                                                          if (*plVar11 == 0) {
                                                            FUN_23a334bc0(plVar11);
                                                          }
                                                          goto LAB_23e70107e;
                                                        }
                                                      }
                                                      plStack_68 = *(longlong **)(param_1 + 0x70);
                                                      auStack_78 = *(undefined1 (*) [8])
                                                                    (param_1 + 0x60);
                                                      plStack_70 = *(longlong **)(param_1 + 0x68);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                    }
                                                    uVar5 = 0x13a;
                                                    pcStack_158 = (code *)plVar9;
                                                    goto LAB_23e704f37;
                                                  }
                                                  plVar10 = (longlong *)
                                                            FUN_23e8bc2f0(plStack_150,DAT_23eeda4e8)
                                                  ;
                                                  if (plVar10 == (longlong *)0x0) {
LAB_23e7069bf:
                                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                                    auStack_78 = *(undefined1 (*) [8])
                                                                  (param_1 + 0x60);
                                                    plStack_70 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  else {
                                                    plVar11 = (longlong *)
                                                              FUN_23e8bc2f0(plStack_150,
                                                                            DAT_23eeda5a8);
                                                    if (plVar11 != (longlong *)0x0) {
                                                      iVar4 = FUN_23e912620(plVar10,plVar11);
                                                      *plVar10 = *plVar10 + -1;
                                                      if (*plVar10 == 0) {
                                                        FUN_23a334bc0(plVar10);
                                                      }
                                                      *plVar11 = *plVar11 + -1;
                                                      if (*plVar11 == 0) {
                                                        FUN_23a334bc0(plVar11);
                                                      }
                                                      plStack_d8 = _DAT_23eeda870;
                                                      plVar10 = _DAT_23eeda868;
                                                      if (iVar4 == -1) goto LAB_23e7069bf;
                                                      if (iVar4 == 1) {
                                                        plVar11 = (longlong *)
                                                                  FUN_23e916ad0(*(undefined8 *)
                                                                                 (param_1 + 0x10),2)
                                                        ;
                                                        *plVar10 = *plVar10 + 1;
                                                        uVar5 = DAT_23eeda4f8;
                                                        plVar11[3] = (longlong)plVar10;
                                                        plVar10 = (longlong *)
                                                                  FUN_23e8bc2f0(plStack_150,uVar5);
                                                        if (plVar10 != (longlong *)0x0) {
                                                          lVar7 = FUN_23e94f9d0(param_1,plVar10,
                                                                                DAT_23ed6cd28);
                                                          *plVar10 = *plVar10 + -1;
                                                          if (*plVar10 == 0) {
                                                            FUN_23a334bc0(plVar10);
                                                          }
                                                          if (lVar7 != 0) {
                                                            plVar11[4] = lVar7;
                                                            plStack_d8 = (longlong *)
                                                                         (*pcStack_158)(
                                                  DAT_23ed6cd28,plVar11);
                                                  *plVar11 = *plVar11 + -1;
                                                  if (*plVar11 == 0) {
                                                    FUN_23a334bc0(plVar11);
                                                  }
                                                  if (plStack_d8 == (longlong *)0x0)
                                                  goto LAB_23e7069bf;
                                                  goto LAB_23e706538;
                                                  }
                                                  }
                                                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  plStack_70 = *(longlong **)(param_1 + 0x68);
                                                  plStack_68 = *(longlong **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  *plVar11 = *plVar11 + -1;
                                                  if (*plVar11 == 0) {
                                                    FUN_23a334bc0(plVar11);
                                                  }
                                                  goto LAB_23e706a16;
                                                  }
                                                  *_DAT_23eeda870 = *_DAT_23eeda870 + 1;
LAB_23e706538:
                                                  if ((plStack_100 != (longlong *)0x0) &&
                                                     (lVar7 = *plStack_100,
                                                     *plStack_100 = lVar7 + -1, lVar7 + -1 == 0)) {
                                                    FUN_23a334bc0(plStack_100);
                                                  }
                                                  plVar10 = _DAT_23eeda808;
                                                  plVar11 = (longlong *)
                                                            FUN_23e916ad0(*(undefined8 *)
                                                                           (param_1 + 0x10),0xb);
                                                  *plVar10 = *plVar10 + 1;
                                                  plVar11[3] = (longlong)plVar10;
                                                  lVar7 = FUN_23e94f9d0(param_1,plStack_108,
                                                                        DAT_23ed6cd28);
                                                  if (lVar7 == 0) {
LAB_23e706883:
                                                    auStack_78 = *(undefined1 (*) [8])
                                                                  (param_1 + 0x60);
                                                    plStack_70 = *(longlong **)(param_1 + 0x68);
                                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *plVar11 = *plVar11 + -1;
                                                    if (*plVar11 == 0) {
                                                      FUN_23a334bc0(plVar11);
                                                    }
                                                  }
                                                  else {
                                                    plVar11[4] = lVar7;
                                                    plVar10 = _DAT_23eeda840;
                                                    *_DAT_23eeda840 = *_DAT_23eeda840 + 1;
                                                    plVar11[5] = (longlong)plVar10;
                                                    lVar7 = FUN_23e94f9d0(param_1,plStack_118,
                                                                          DAT_23ed6cd28);
                                                    if (lVar7 == 0) goto LAB_23e706883;
                                                    plVar11[6] = lVar7;
                                                    plVar10 = _DAT_23eeda848;
                                                    *_DAT_23eeda848 = *_DAT_23eeda848 + 1;
                                                    plVar11[7] = (longlong)plVar10;
                                                    lVar7 = FUN_23e94f9d0(param_1,plStack_160,
                                                                          DAT_23ed6cd28);
                                                    if (lVar7 == 0) goto LAB_23e706883;
                                                    plVar11[8] = lVar7;
                                                    plVar10 = _DAT_23eeda878;
                                                    *_DAT_23eeda878 = *_DAT_23eeda878 + 1;
                                                    plVar11[9] = (longlong)plVar10;
                                                    *plStack_d8 = *plStack_d8 + 1;
                                                    plVar11[10] = (longlong)plStack_d8;
                                                    plVar10 = _DAT_23eeda858;
                                                    *_DAT_23eeda858 = *_DAT_23eeda858 + 1;
                                                    plVar11[0xb] = (longlong)plVar10;
                                                    lVar7 = FUN_23e94f9d0(param_1,plVar16);
                                                    if (lVar7 == 0) goto LAB_23e706883;
                                                    plVar11[0xc] = lVar7;
                                                    plVar12 = _DAT_23eeda820;
                                                    plVar10 = DAT_23ed6cd28;
                                                    *_DAT_23eeda820 = *_DAT_23eeda820 + 1;
                                                    plVar11[0xd] = (longlong)plVar12;
                                                    plVar10 = (longlong *)
                                                              (*pcStack_158)(plVar10,plVar11);
                                                    *plVar11 = *plVar11 + -1;
                                                    if (*plVar11 == 0) {
                                                      FUN_23a334bc0(plVar11);
                                                    }
                                                    if (plVar10 != (longlong *)0x0) {
                                                      if ((plVar9 != (longlong *)0x0) &&
                                                         (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
                                                        FUN_23a334bc0(plVar9);
                                                      }
                                                      uVar5 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                      plVar9 = _DAT_23eeda828;
                                                      plVar11 = (longlong *)
                                                                FUN_23e916ad0(*(undefined8 *)
                                                                               (param_1 + 0x10),2);
                                                      *plVar9 = *plVar9 + 1;
                                                      plVar11[3] = (longlong)plVar9;
                                                      *plVar10 = *plVar10 + 1;
                                                      plVar11[4] = (longlong)plVar10;
                                                      lVar7 = (*pcStack_158)(DAT_23ed6cd28,plVar11);
                                                      *plVar11 = *plVar11 + -1;
                                                      if (*plVar11 == 0) {
                                                        FUN_23a334bc0(plVar11);
                                                      }
                                                      if (lVar7 != 0) {
                                                        plVar9 = (longlong *)
                                                                 FUN_23e916ad0(*(undefined8 *)
                                                                                (param_1 + 0x10),1);
                                                        uVar13 = _DAT_23eeda830;
                                                        plVar9[3] = lVar7;
                                                        plVar11 = (longlong *)
                                                                  FUN_23e8d7870(param_1,uVar13);
                                                        *(undefined4 *)(plVar2 + 5) = 0x13e;
                                                        plVar12 = (longlong *)
                                                                  FUN_23a334c60(param_1,uVar5,plVar9
                                                                               );
                                                        *plVar9 = *plVar9 + -1;
                                                        if (*plVar9 == 0) {
                                                          FUN_23a334bc0(plVar9);
                                                        }
                                                        *plVar11 = *plVar11 + -1;
                                                        if (*plVar11 == 0) {
                                                          FUN_23a334bc0(plVar11);
                                                        }
                                                        if (plVar12 != (longlong *)0x0) {
                                                          *plVar12 = *plVar12 + -1;
                                                          if (*plVar12 == 0) {
                                                            FUN_23a334bc0(plVar12);
                                                          }
                                                          plStack_100 = plStack_d8;
                                                          plVar9 = plVar10;
                                                          goto LAB_23e70107e;
                                                        }
                                                      }
                                                      plStack_68 = *(longlong **)(param_1 + 0x70);
                                                      auStack_78 = *(undefined1 (*) [8])
                                                                    (param_1 + 0x60);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      plStack_100 = plStack_d8;
                                                      uVar5 = 0x13e;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      pcStack_158 = (code *)plVar10;
                                                      plStack_70 = *(longlong **)(param_1 + 0x68);
                                                      goto LAB_23e704f37;
                                                    }
                                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                                    auStack_78 = *(undefined1 (*) [8])
                                                                  (param_1 + 0x60);
                                                    plStack_70 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  uVar5 = 0x13d;
                                                  plStack_100 = plStack_d8;
                                                  pcStack_158 = (code *)plVar9;
                                                  goto LAB_23e704f37;
                                                  }
                                                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  plStack_70 = *(longlong **)(param_1 + 0x68);
                                                  plStack_68 = *(longlong **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  *plVar10 = *plVar10 + -1;
                                                  if (*plVar10 == 0) {
                                                    FUN_23a334bc0(plVar10);
                                                  }
                                                  }
LAB_23e706a16:
                                                  uVar5 = 0x13c;
                                                  pcStack_158 = (code *)plVar9;
                                                  }
                                                  goto LAB_23e704f37;
                                                  }
                                                  plStack_68 = *(longlong **)(param_1 + 0x70);
                                                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  plStack_70 = *(longlong **)(param_1 + 0x68);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  }
                                                  uVar5 = 0x133;
                                                  plStack_118 = plStack_d8;
                                                  plStack_108 = plStack_d0;
                                                  pcStack_158 = (code *)plVar9;
                                                  goto LAB_23e704f37;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  plVar10 = plStack_68;
                                                  plVar12 = plStack_70;
                                                  auVar21 = auStack_78;
                                                  _auStack_78 = (undefined1  [16])0x0;
                                                  plStack_68 = (longlong *)0x0;
                                                  *plVar11 = lVar7 + -1;
                                                  if (lVar7 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  plStack_68 = (longlong *)0x0;
                                                  auStack_78 = (undefined1  [8])0x0;
                                                  plStack_70 = (longlong *)0x0;
                                                  if ((plStack_160 != (longlong *)0x0) &&
                                                     (lVar7 = *plStack_160,
                                                     *plStack_160 = lVar7 + -1, lVar7 + -1 == 0)) {
                                                    FUN_23a334bc0(plStack_160);
                                                  }
                                                  if ((plVar15 != (longlong *)0x0) &&
                                                     (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                                                    FUN_23a334bc0(plVar15);
                                                  }
                                                  if ((plStack_120 != (longlong *)0x0) &&
                                                     (lVar7 = *plStack_120,
                                                     *plStack_120 = lVar7 + -1, lVar7 + -1 == 0)) {
                                                    FUN_23a334bc0(plStack_120);
                                                  }
                                                  if ((plStack_130 != (longlong *)0x0) &&
                                                     (lVar7 = *plStack_130,
                                                     *plStack_130 = lVar7 + -1, lVar7 + -1 == 0)) {
                                                    FUN_23a334bc0(plStack_130);
                                                  }
                                                  if ((plStack_138 != (longlong *)0x0) &&
                                                     (lVar7 = *plStack_138,
                                                     *plStack_138 = lVar7 + -1, lVar7 + -1 == 0)) {
                                                    FUN_23a334bc0(plStack_138);
                                                  }
                                                  if ((plVar16 != (longlong *)0x0) &&
                                                     (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
                                                    FUN_23a334bc0(plVar16);
                                                  }
                                                  if ((plStack_148 != (longlong *)0x0) &&
                                                     (lVar7 = *plStack_148,
                                                     *plStack_148 = lVar7 + -1, lVar7 + -1 == 0)) {
                                                    FUN_23a334bc0(plStack_148);
                                                  }
                                                  }
                                                  uVar5 = 0x131;
                                                  plStack_118 = plStack_d8;
                                                  plStack_108 = plStack_d0;
                                                  plStack_148 = plStack_a0;
                                                  plStack_138 = plStack_b0;
                                                  plStack_130 = plStack_b8;
                                                  plStack_120 = plStack_c0;
                                                  plStack_160 = plStack_c8;
                                                  pcStack_158 = (code *)plVar9;
                                                  plStack_68 = plVar10;
                                                  auStack_78 = auVar21;
                                                  plStack_70 = plVar12;
                                                  goto LAB_23e704f37;
                                                  }
                                                  uVar5 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                  *(undefined4 *)(plVar2 + 5) = 0x12d;
                                                  plVar10 = (longlong *)
                                                            FUN_23e939610(param_1,uVar5,
                                                                          _DAT_23eeda7c0 + 0x18);
                                                  if (plVar10 == (longlong *)0x0) {
                                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                                    auStack_78 = *(undefined1 (*) [8])
                                                                  (param_1 + 0x60);
                                                    plStack_70 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    uVar5 = 0x12d;
                                                    plStack_118 = plStack_d8;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plStack_108 = plStack_d0;
                                                    plStack_148 = plStack_a0;
                                                    plStack_138 = plStack_b0;
                                                    plStack_130 = plStack_b8;
                                                    plStack_120 = plStack_c0;
                                                    plStack_160 = plStack_c8;
                                                    pcStack_158 = (code *)plVar9;
                                                    goto LAB_23e704f37;
                                                  }
                                                  *plVar10 = *plVar10 + -1;
                                                  if (*plVar10 == 0) {
                                                    FUN_23a334bc0(plVar10);
                                                  }
                                                  lVar7 = FUN_23e8e19b0();
                                                  if (lVar7 == 0) {
                                                    FUN_23e915740(param_1,auStack_78,DAT_23eeda520);
LAB_23e7077fd:
                                                    uVar5 = 0x12e;
                                                    plStack_118 = plStack_d8;
                                                    plStack_108 = plStack_d0;
                                                    plStack_148 = plStack_a0;
                                                    plStack_138 = plStack_b0;
                                                    plStack_130 = plStack_b8;
                                                    plStack_120 = plStack_c0;
                                                    plStack_160 = plStack_c8;
                                                    pcStack_110 = _Py_NoneStruct_exref;
                                                    pcStack_158 = (code *)plVar9;
                                                    goto LAB_23e704f37;
                                                  }
                                                  *(undefined4 *)(plVar2 + 5) = 0x12e;
                                                  plVar10 = (longlong *)FUN_23e915840(param_1,lVar7)
                                                  ;
                                                  if (plVar10 == (longlong *)0x0) {
                                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                                    auStack_78 = *(undefined1 (*) [8])
                                                                  (param_1 + 0x60);
                                                    plStack_70 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    goto LAB_23e7077fd;
                                                  }
                                                  *plVar10 = *plVar10 + -1;
                                                  if (*plVar10 == 0) {
                                                    FUN_23a334bc0(plVar10);
                                                  }
                                                  plStack_118 = plStack_d8;
                                                  plStack_108 = plStack_d0;
                                                  plStack_148 = plStack_a0;
                                                  plStack_138 = plStack_b0;
                                                  plStack_130 = plStack_b8;
                                                  plStack_120 = plStack_c0;
LAB_23e70108e:
                                                  plStack_d8 = plStack_118;
                                                  plStack_d0 = plStack_108;
                                                  plStack_a0 = plStack_148;
                                                  plStack_b0 = plStack_138;
                                                  plStack_b8 = plStack_130;
                                                  plStack_c0 = plStack_120;
                                                  }
                                                  plStack_68 = *(longlong **)(param_1 + 0x70);
                                                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  plStack_70 = *(longlong **)(param_1 + 0x68);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  uVar5 = 0x12a;
                                                  plStack_118 = plStack_d8;
                                                  plStack_108 = plStack_d0;
                                                  plStack_148 = plStack_a0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  plStack_138 = plStack_b0;
                                                  plStack_130 = plStack_b8;
                                                  plStack_120 = plStack_c0;
                                                  plStack_160 = plStack_c8;
                                                  pcStack_158 = (code *)plVar9;
LAB_23e704f37:
                                                  plVar9 = plStack_68;
                                                  plStack_68 = (longlong *)0x0;
                                                  plStack_88 = plVar9;
                                                  plVar10 = *(longlong **)(param_1 + 0x138);
                                                  plStack_98 = (longlong *)auStack_78;
                                                  plStack_90 = plStack_70;
                                                  _auStack_78 = (undefined1  [16])0x0;
                                                  if (plVar10 != (longlong *)0x0) {
                                                    *plVar10 = *plVar10 + 1;
                                                  }
                                                  if (plVar9 == (longlong *)0x0) {
                                                    lVar7 = FUN_23e8d6280(plVar2,uVar5);
                                                    if ((plStack_88 != (longlong *)0x0) &&
                                                       (*plStack_88 = *plStack_88 + -1,
                                                       *plStack_88 == 0)) {
                                                      FUN_23a334bc0();
                                                    }
                                                  }
                                                  else {
                                                    lVar7 = FUN_23e8d6280(plVar2,uVar5);
                                                    *(longlong **)(lVar7 + 0x10) = plVar9;
                                                    *plVar9 = *plVar9 + 1;
                                                    if ((plStack_88 != (longlong *)0x0) &&
                                                       (*plStack_88 = *plStack_88 + -1,
                                                       *plStack_88 == 0)) {
                                                      FUN_23a334bc0();
                                                    }
                                                  }
                                                  plStack_88 = (longlong *)lVar7;
                                                  FUN_23a35ef40(param_1,&plStack_98);
                                                  iVar4 = FUN_23a35ebd0(param_1,*(undefined8 *)
                                                                                 (*(longlong *)
                                                                                   (param_1 + 0x138)
                                                                                 + 8),
                                                                        *(undefined8 *)
                                                                                                                                                  
                                                  PyExc_KeyboardInterrupt_exref);
                                                  if (iVar4 == 0) {
                                                    cVar3 = FUN_23e8ba320(*(undefined8 *)
                                                                           (param_1 + 0x138),
                                                                          auStack_78);
                                                    plVar9 = plStack_68;
                                                    iVar4 = 0;
                                                    if (cVar3 == '\0') {
                                                      iVar4 = 0x128;
                                                    }
                                                    if (plStack_68 != (longlong *)0x0) {
                                                      if ((longlong *)plStack_68[3] == plVar2) {
                                                        *(undefined4 *)(plVar2 + 5) =
                                                             *(undefined4 *)
                                                              ((longlong)plStack_68 + 0x24);
                                                      }
                                                      plStack_68 = (longlong *)0x0;
                                                      _auStack_78 = (undefined1  [16])0x0;
                                                      FUN_23ebf6ae0(param_1,plVar10);
                                                      if ((longlong *)plVar9[3] == plVar2)
                                                      goto LAB_23e701333;
                                                      plStack_68 = plVar9;
                                                      if (iVar4 == 0) {
                                                        uVar20 = (undefined4)plVar2[5];
                                                      }
                                                      else {
                                                        uVar20 = 0x128;
                                                      }
                                                      goto LAB_23e701280;
                                                    }
                                                    uVar20 = 0x128;
                                                    _auStack_78 = (undefined1  [16])0x0;
                                                    FUN_23ebf6ae0();
                                                    plStack_68 = (longlong *)0x0;
                                                    if (iVar4 == 0) {
                                                      uVar20 = (undefined4)plVar2[5];
                                                    }
                                                  }
                                                  else {
                                                    uVar5 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                    *(undefined4 *)(plVar2 + 5) = 0x141;
                                                    plVar9 = (longlong *)
                                                             FUN_23e94bb80(param_1,uVar5,
                                                                           _DAT_23eeda880);
                                                    if (plVar9 == (longlong *)0x0) {
                                                      plVar9 = *(longlong **)(param_1 + 0x70);
                                                      plVar11 = *(longlong **)(param_1 + 0x60);
                                                      plVar12 = *(longlong **)(param_1 + 0x68);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      plStack_68 = (longlong *)0x0;
                                                      _auStack_78 = (undefined1  [16])0x0;
                                                      FUN_23ebf6ae0(param_1,plVar10);
                                                      plStack_68 = plVar9;
                                                      auStack_78 = (undefined1  [8])plVar11;
                                                      plStack_70 = plVar12;
                                                      if (plVar9 != (longlong *)0x0) {
                                                        if ((longlong *)plVar9[3] == plVar2)
                                                        goto LAB_23e701333;
                                                        uVar20 = 0x141;
                                                        goto LAB_23e701280;
                                                      }
                                                      uVar20 = 0x141;
                                                    }
                                                    else {
                                                      *plVar9 = *plVar9 + -1;
                                                      if (*plVar9 == 0) {
                                                        FUN_23a334bc0(plVar9);
                                                      }
                                                      FUN_23ebf6ae0(param_1,plVar10);
                                                      uVar5 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                      *(undefined4 *)(plVar2 + 5) = 0x143;
                                                      plVar9 = (longlong *)
                                                               FUN_23e94bb80(param_1,uVar5,
                                                                             _DAT_23eeda698);
                                                      if (plVar9 == (longlong *)0x0) {
                                                        auStack_78 = *(undefined1 (*) [8])
                                                                      (param_1 + 0x60);
                                                        plStack_70 = *(longlong **)(param_1 + 0x68);
                                                        plStack_68 = *(longlong **)(param_1 + 0x70);
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        if (plStack_68 != (longlong *)0x0) {
                                                          uVar20 = 0x143;
                                                          plVar10 = (longlong *)plStack_68[3];
                                                          goto joined_r0x00023e7055da;
                                                        }
                                                        uVar20 = 0x143;
                                                      }
                                                      else {
                                                        *plVar9 = *plVar9 + -1;
                                                        if (*plVar9 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                        uVar5 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                        *(undefined4 *)(plVar2 + 5) = 0x144;
                                                        plVar9 = (longlong *)
                                                                 FUN_23e94bb80(param_1,uVar5);
                                                        if (plVar9 == (longlong *)0x0) {
                                                          auStack_78 = *(undefined1 (*) [8])
                                                                        (param_1 + 0x60);
                                                          plStack_70 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                          plStack_68 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          if (plStack_68 != (longlong *)0x0) {
                                                            uVar20 = 0x144;
                                                            plVar10 = (longlong *)plStack_68[3];
joined_r0x00023e7055da:
                                                            plVar9 = plStack_68;
                                                            if (plVar10 == plVar2)
                                                            goto LAB_23e701333;
                                                            goto LAB_23e701280;
                                                          }
                                                          uVar20 = 0x144;
                                                        }
                                                        else {
                                                          *plVar9 = *plVar9 + -1;
                                                          if (*plVar9 == 0) {
                                                            FUN_23a334bc0();
                                                          }
                                                          uVar5 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                          *(undefined4 *)(plVar2 + 5) = 0x145;
                                                          plVar9 = (longlong *)
                                                                   FUN_23e94bb80(param_1,uVar5,
                                                                                 _DAT_23eeda6a8);
                                                          if (plVar9 != (longlong *)0x0) {
                                                            *plVar9 = *plVar9 + -1;
                                                            if (*plVar9 == 0) {
                                                              FUN_23a334bc0();
                                                            }
                                                            FUN_23ebf6b20(*(undefined8 *)
                                                                           (param_1 + 0x38));
                                                            pcVar19 = _Py_NoneStruct_exref;
                                                            *(longlong *)_Py_NoneStruct_exref =
                                                                 *(longlong *)_Py_NoneStruct_exref +
                                                                 1;
                                                            *plVar6 = *plVar6 + -1;
                                                            if (*plVar6 == 0) {
                                                              FUN_23a334bc0(plVar6);
                                                            }
                                                            *plVar8 = *plVar8 + -1;
                                                            if (*plVar8 == 0) {
                                                              FUN_23a334bc0(plVar8);
                                                            }
                                                            lVar7 = *plStack_170;
                                                            *plStack_170 = lVar7 + -1;
                                                            if (lVar7 + -1 == 0) {
                                                              FUN_23a334bc0(plStack_170);
                                                            }
                                                            lVar7 = *plStack_128;
                                                            *plStack_128 = lVar7 + -1;
                                                            if (lVar7 + -1 == 0) {
                                                              FUN_23a334bc0(plStack_128);
                                                            }
                                                            lVar7 = *plStack_140;
                                                            *plStack_140 = lVar7 + -1;
                                                            if (lVar7 + -1 == 0) {
                                                              FUN_23a334bc0(plStack_140);
                                                            }
                                                            lVar7 = *plStack_150;
                                                            *plStack_150 = lVar7 + -1;
                                                            if (lVar7 + -1 == 0) {
                                                              FUN_23a334bc0(plStack_150);
                                                            }
                                                            lVar7 = *plStack_168;
                                                            *plStack_168 = lVar7 + -1;
                                                            if (lVar7 + -1 == 0) {
                                                              FUN_23a334bc0(plStack_168);
                                                            }
                                                            if ((pcStack_110 != (code *)0x0) &&
                                                               (lVar7 = *(longlong *)pcStack_110,
                                                               *(longlong *)pcStack_110 = lVar7 + -1
                                                               , lVar7 + -1 == 0)) {
                                                              FUN_23a334bc0(pcStack_110);
                                                            }
                                                            if ((plStack_160 != (longlong *)0x0) &&
                                                               (lVar7 = *plStack_160,
                                                               *plStack_160 = lVar7 + -1,
                                                               lVar7 + -1 == 0)) {
                                                              FUN_23a334bc0(plStack_160);
                                                            }
                                                            if ((plStack_120 != (longlong *)0x0) &&
                                                               (lVar7 = *plStack_120,
                                                               *plStack_120 = lVar7 + -1,
                                                               lVar7 + -1 == 0)) {
                                                              FUN_23a334bc0(plStack_120);
                                                            }
                                                            if ((plStack_130 != (longlong *)0x0) &&
                                                               (lVar7 = *plStack_130,
                                                               *plStack_130 = lVar7 + -1,
                                                               lVar7 + -1 == 0)) {
                                                              FUN_23a334bc0(plStack_130);
                                                            }
                                                            if ((plStack_138 != (longlong *)0x0) &&
                                                               (lVar7 = *plStack_138,
                                                               *plStack_138 = lVar7 + -1,
                                                               lVar7 + -1 == 0)) {
                                                              FUN_23a334bc0(plStack_138);
                                                            }
                                                            if ((plStack_a8 != (longlong *)0x0) &&
                                                               (*plStack_a8 = *plStack_a8 + -1,
                                                               *plStack_a8 == 0)) {
                                                              FUN_23a334bc0(plStack_a8);
                                                            }
                                                            if ((plStack_148 != (longlong *)0x0) &&
                                                               (lVar7 = *plStack_148,
                                                               *plStack_148 = lVar7 + -1,
                                                               lVar7 + -1 == 0)) {
                                                              FUN_23a334bc0(plStack_148);
                                                            }
                                                            if ((plStack_108 != (longlong *)0x0) &&
                                                               (lVar7 = *plStack_108,
                                                               *plStack_108 = lVar7 + -1,
                                                               lVar7 + -1 == 0)) {
                                                              FUN_23a334bc0(plStack_108);
                                                            }
                                                            if ((plStack_118 != (longlong *)0x0) &&
                                                               (lVar7 = *plStack_118,
                                                               *plStack_118 = lVar7 + -1,
                                                               lVar7 + -1 == 0)) {
                                                              FUN_23a334bc0(plStack_118);
                                                            }
                                                            if ((pcStack_158 != (code *)0x0) &&
                                                               (lVar7 = *(longlong *)pcStack_158,
                                                               *(longlong *)pcStack_158 = lVar7 + -1
                                                               , lVar7 + -1 == 0)) {
                                                              FUN_23a334bc0(pcStack_158);
                                                            }
                                                            if (plStack_100 != (longlong *)0x0) {
                                                              lVar7 = *plStack_100;
                                                              *plStack_100 = lVar7 + -1;
                                                              if (lVar7 + -1 == 0) {
                                                                FUN_23a334bc0(plStack_100);
                                                                return pcVar19;
                                                              }
                                                              return pcVar19;
                                                            }
                                                            return pcVar19;
                                                          }
                                                          auStack_78 = *(undefined1 (*) [8])
                                                                        (param_1 + 0x60);
                                                          plStack_70 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                          plStack_68 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          if (plStack_68 != (longlong *)0x0) {
                                                            uVar20 = 0x145;
                                                            plVar10 = (longlong *)plStack_68[3];
                                                            goto joined_r0x00023e7055da;
                                                          }
                                                          uVar20 = 0x145;
                                                        }
                                                      }
                                                    }
                                                  }
                                                  goto LAB_23e7020b0;
                                                  }
                                                  }
                                                  }
                                                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  plStack_70 = *(longlong **)(param_1 + 0x68);
                                                  plStack_68 = *(longlong **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  lVar7 = *plStack_168;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  *plStack_168 = lVar7 + -1;
                                                  if (lVar7 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  if (plStack_68 != (longlong *)0x0) {
                                                    if ((longlong *)plStack_68[3] == plVar2)
                                                    goto LAB_23e704751;
                                                    plStack_a8 = (longlong *)0x0;
                                                    uVar20 = 0x126;
                                                    plStack_100 = (longlong *)0x0;
                                                    pcStack_158 = (code *)0x0;
                                                    plStack_118 = (longlong *)0x0;
                                                    plStack_108 = (longlong *)0x0;
                                                    plStack_148 = (longlong *)0x0;
                                                    plStack_138 = (longlong *)0x0;
                                                    plStack_130 = (longlong *)0x0;
                                                    plStack_120 = (longlong *)0x0;
                                                    plStack_160 = (longlong *)0x0;
                                                    pcStack_110 = (code *)0x0;
                                                    plStack_168 = (longlong *)0x0;
                                                    goto LAB_23e701280;
                                                  }
                                                  }
                                                  plStack_a8 = (longlong *)0x0;
                                                  uVar20 = 0x126;
                                                  plStack_100 = (longlong *)0x0;
                                                  pcStack_158 = (code *)0x0;
                                                  plStack_118 = (longlong *)0x0;
                                                  plStack_108 = (longlong *)0x0;
                                                  plStack_148 = (longlong *)0x0;
                                                  plStack_138 = (longlong *)0x0;
                                                  plStack_130 = (longlong *)0x0;
                                                  plStack_120 = (longlong *)0x0;
                                                  plStack_160 = (longlong *)0x0;
                                                  pcStack_110 = (code *)0x0;
                                                  plStack_168 = (longlong *)0x0;
                                                }
                                              }
                                              goto LAB_23e7020b0;
                                            }
                                            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                            plStack_70 = *(longlong **)(param_1 + 0x68);
                                            plStack_68 = *(longlong **)(param_1 + 0x70);
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            if (plStack_68 == (longlong *)0x0) goto LAB_23e7079c8;
                                            if ((longlong *)plStack_68[3] == plVar2)
                                            goto LAB_23e704751;
                                            plStack_a8 = (longlong *)0x0;
                                            plStack_100 = (longlong *)0x0;
                                            pcStack_158 = (code *)0x0;
                                            plStack_118 = (longlong *)0x0;
                                            plStack_108 = (longlong *)0x0;
                                            plStack_148 = (longlong *)0x0;
                                            uVar20 = 0x122;
                                            plStack_138 = (longlong *)0x0;
                                            plStack_130 = (longlong *)0x0;
                                            plStack_120 = (longlong *)0x0;
                                            plStack_160 = (longlong *)0x0;
                                            pcStack_110 = (code *)0x0;
                                            plStack_168 = (longlong *)0x0;
                                            goto LAB_23e701280;
                                          }
                                          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                          plStack_70 = *(longlong **)(param_1 + 0x68);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          if (plStack_68 != (longlong *)0x0) {
                                            if ((longlong *)plStack_68[3] == plVar2)
                                            goto LAB_23e704751;
                                            plStack_a8 = (longlong *)0x0;
                                            plStack_100 = (longlong *)0x0;
                                            pcStack_158 = (code *)0x0;
                                            plStack_118 = (longlong *)0x0;
                                            plStack_108 = (longlong *)0x0;
                                            plStack_148 = (longlong *)0x0;
                                            uVar20 = 0x122;
                                            plStack_138 = (longlong *)0x0;
                                            plStack_130 = (longlong *)0x0;
                                            plStack_120 = (longlong *)0x0;
                                            plStack_160 = (longlong *)0x0;
                                            plStack_168 = (longlong *)0x0;
                                            pcStack_110 = (code *)0x0;
                                            goto LAB_23e701280;
                                          }
                                        }
LAB_23e7079c8:
                                        plStack_a8 = (longlong *)0x0;
                                        plStack_100 = (longlong *)0x0;
                                        pcStack_158 = (code *)0x0;
                                        plStack_118 = (longlong *)0x0;
                                        plStack_108 = (longlong *)0x0;
                                        plStack_148 = (longlong *)0x0;
                                        uVar20 = 0x122;
                                        plStack_138 = (longlong *)0x0;
                                        plStack_130 = (longlong *)0x0;
                                        plStack_120 = (longlong *)0x0;
                                        plStack_160 = (longlong *)0x0;
                                        pcStack_110 = (code *)0x0;
                                        plStack_168 = (longlong *)0x0;
                                      }
                                    }
                                  }
                                }
                                goto LAB_23e7020b0;
                              }
                              auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                              plStack_70 = *(longlong **)(param_1 + 0x68);
                              plStack_68 = *(longlong **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              if (plStack_68 != (longlong *)0x0) {
                                if ((longlong *)plStack_68[3] == plVar2) goto LAB_23e704751;
                                plStack_a8 = (longlong *)0x0;
                                uVar20 = 0x11d;
                                plStack_100 = (longlong *)0x0;
                                pcStack_158 = (code *)0x0;
                                plStack_118 = (longlong *)0x0;
                                plStack_108 = (longlong *)0x0;
                                plStack_148 = (longlong *)0x0;
                                plStack_138 = (longlong *)0x0;
                                plStack_130 = (longlong *)0x0;
                                plStack_120 = (longlong *)0x0;
                                plStack_160 = (longlong *)0x0;
                                plStack_168 = (longlong *)0x0;
                                pcStack_110 = (code *)0x0;
                                goto LAB_23e701280;
                              }
LAB_23e706346:
                              plStack_a8 = (longlong *)0x0;
                              uVar20 = 0x11d;
                              plStack_100 = (longlong *)0x0;
                              pcStack_158 = (code *)0x0;
                              plStack_118 = (longlong *)0x0;
                              plStack_108 = (longlong *)0x0;
                              plStack_148 = (longlong *)0x0;
                              plStack_138 = (longlong *)0x0;
                              plStack_130 = (longlong *)0x0;
                              plStack_120 = (longlong *)0x0;
                              plStack_160 = (longlong *)0x0;
                              pcStack_110 = (code *)0x0;
                              plStack_168 = (longlong *)0x0;
                            }
                          }
                          goto LAB_23e7020b0;
                        }
                        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                        plStack_70 = *(longlong **)(param_1 + 0x68);
                        plStack_68 = *(longlong **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        if (plStack_68 != (longlong *)0x0) {
                          if ((longlong *)plStack_68[3] != plVar2) {
                            plStack_a8 = (longlong *)0x0;
                            uVar20 = 0x118;
                            plStack_100 = (longlong *)0x0;
                            pcStack_158 = (code *)0x0;
                            plStack_118 = (longlong *)0x0;
                            plStack_108 = (longlong *)0x0;
                            plStack_148 = (longlong *)0x0;
                            plStack_138 = (longlong *)0x0;
                            plStack_130 = (longlong *)0x0;
                            plStack_120 = (longlong *)0x0;
                            plStack_160 = (longlong *)0x0;
                            pcStack_110 = (code *)0x0;
                            plStack_168 = (longlong *)0x0;
                            goto LAB_23e701280;
                          }
                          goto LAB_23e703d0f;
                        }
                      }
                      plStack_a8 = (longlong *)0x0;
                      uVar20 = 0x118;
                      plStack_100 = (longlong *)0x0;
                      pcStack_158 = (code *)0x0;
                      plStack_118 = (longlong *)0x0;
                      plStack_108 = (longlong *)0x0;
                      plStack_148 = (longlong *)0x0;
                      plStack_138 = (longlong *)0x0;
                      plStack_130 = (longlong *)0x0;
                      plStack_120 = (longlong *)0x0;
                      plStack_160 = (longlong *)0x0;
                      pcStack_110 = (code *)0x0;
                      plStack_168 = (longlong *)0x0;
                      plStack_150 = (longlong *)0x0;
                      goto LAB_23e7020b0;
                    }
                  }
                  plVar9 = plStack_68;
                  plVar11 = plStack_70;
                  auVar21 = auStack_78;
                  plStack_68 = (longlong *)0x0;
                  _auStack_78 = (undefined1  [16])0x0;
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))();
                  }
                  plStack_68 = (longlong *)0x0;
                  auStack_78 = (undefined1  [8])0x0;
                  plStack_70 = (longlong *)0x0;
                  if ((plStack_128 != (longlong *)0x0) &&
                     (lVar7 = *plStack_128, *plStack_128 = lVar7 + -1, lVar7 + -1 == 0)) {
                    (**(code **)(plStack_128[1] + 0x30))();
                  }
                  if ((plStack_140 != (longlong *)0x0) &&
                     (lVar7 = *plStack_140, *plStack_140 = lVar7 + -1, lVar7 + -1 == 0)) {
                    (**(code **)(plStack_140[1] + 0x30))();
                  }
                  goto LAB_23e702d00;
                }
              }
              auVar21 = *(undefined1 (*) [8])(param_1 + 0x60);
              plVar9 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar11 = *(longlong **)(param_1 + 0x68);
            }
            else {
              iVar4 = *(int *)(lVar7 + 0xc);
              if (*(int *)(lVar7 + 0xc) == 0) {
                *(int *)(lVar7 + 0xc) = _DAT_23ec154a0;
                iVar4 = _DAT_23ec154a0;
                _DAT_23ec154a0 = _DAT_23ec154a0 + 1;
              }
              if (_DAT_23ec15490 != iVar4) {
                _DAT_23ec15490 = iVar4;
                _DAT_23eedb188 =
                     FUN_23e8cbd60(lVar7,_DAT_23eeda6f8,*(undefined8 *)(_DAT_23eeda6f8 + 0x18));
              }
              if (-1 < _DAT_23eedb188) {
                lVar17 = lVar7 + 0x20 + (1L << (*(byte *)(lVar7 + 9) & 0x3f));
                lVar18 = *(longlong *)(lVar17 + 8 + _DAT_23eedb188 * 0x10);
                if (lVar18 != 0) goto LAB_23e6ff228;
                _DAT_23eedb188 =
                     FUN_23e8cbd60(lVar7,_DAT_23eeda6f8,*(undefined8 *)(_DAT_23eeda6f8 + 0x18));
                if (-1 < _DAT_23eedb188) {
                  lVar18 = *(longlong *)(lVar17 + 8 + _DAT_23eedb188 * 0x10);
                  goto LAB_23e702c79;
                }
              }
LAB_23e702c90:
              plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeda6f8);
              if ((plVar9 != (longlong *)0x0) && (lVar18 = *plVar9, lVar18 != 0))
              goto LAB_23e6ff228;
              FUN_23e915740(param_1,auStack_78,_DAT_23eeda6f8);
              plVar9 = plStack_68;
              auVar21 = auStack_78;
              plVar11 = plStack_70;
            }
LAB_23e702d00:
            pcVar19 = _PyRuntime_exref;
            plStack_68 = plVar9;
            auStack_78 = auVar21;
            plStack_70 = plVar11;
            if (plVar9 != (longlong *)0x0) {
              plStack_100 = (longlong *)0x0;
              plStack_a8 = (longlong *)0x0;
              pcStack_158 = (code *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plStack_148 = (longlong *)0x0;
              plStack_138 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              pcStack_110 = (code *)0x0;
              plStack_168 = (longlong *)0x0;
              plStack_150 = (longlong *)0x0;
              plStack_140 = (longlong *)0x0;
              plStack_128 = (longlong *)0x0;
              if ((longlong *)plVar9[3] == plVar2) goto LAB_23e701333;
              uVar20 = 0x112;
              goto LAB_23e701280;
            }
            plStack_100 = (longlong *)0x0;
            plStack_a8 = (longlong *)0x0;
            uVar20 = 0x112;
            pcStack_158 = (code *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_148 = (longlong *)0x0;
            plStack_138 = (longlong *)0x0;
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_160 = (longlong *)0x0;
            pcStack_110 = (code *)0x0;
            plStack_168 = (longlong *)0x0;
            plStack_150 = (longlong *)0x0;
            plStack_140 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            goto LAB_23e7020b0;
          }
        }
        plVar10 = plStack_68;
        plVar11 = plStack_70;
        auVar21 = auStack_78;
        plStack_68 = (longlong *)0x0;
        _auStack_78 = (undefined1  [16])0x0;
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))();
        }
        plStack_68 = (longlong *)0x0;
        auStack_78 = (undefined1  [8])0x0;
        plStack_70 = (longlong *)0x0;
        if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
          (**(code **)(plVar8[1] + 0x30))();
        }
        if ((plStack_170 != (longlong *)0x0) &&
           (lVar7 = *plStack_170, *plStack_170 = lVar7 + -1, lVar7 + -1 == 0)) {
          (**(code **)(plStack_170[1] + 0x30))();
        }
      }
      pcVar19 = _PyRuntime_exref;
      plStack_68 = plVar10;
      auStack_78 = auVar21;
      plStack_70 = plVar11;
      if (plVar10 != (longlong *)0x0) {
        if ((longlong *)plVar10[3] == plVar2) {
LAB_23e7026d0:
          plStack_100 = (longlong *)0x0;
          plStack_a8 = (longlong *)0x0;
          plVar8 = (longlong *)0x0;
          pcStack_158 = (code *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_148 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_160 = (longlong *)0x0;
          pcStack_110 = (code *)0x0;
          plStack_168 = (longlong *)0x0;
          plStack_150 = (longlong *)0x0;
          plStack_140 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_170 = (longlong *)0x0;
          plVar9 = plStack_68;
          goto LAB_23e701333;
        }
        plStack_100 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        pcStack_158 = (code *)0x0;
        uVar20 = 0x111;
        plStack_118 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        plStack_148 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
        pcStack_110 = (code *)0x0;
        plStack_168 = (longlong *)0x0;
        plStack_150 = (longlong *)0x0;
        plStack_140 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_170 = (longlong *)0x0;
        goto LAB_23e701280;
      }
      plStack_100 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      pcStack_158 = (code *)0x0;
      uVar20 = 0x111;
      plStack_118 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_148 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcStack_110 = (code *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_150 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
    }
LAB_23e7020b0:
    plVar9 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      plVar10 = plStack_68;
    }
    else {
      plVar10 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar10;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar10 = (longlong *)0x0;
    }
    plVar9[2] = 0;
    plVar9[3] = (longlong)plVar2;
    *plVar2 = *plVar2 + 1;
    lVar7 = *(longlong *)(pcVar19 + 0x1f8);
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar7 = *(longlong *)(lVar7 + 0x10);
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar20;
    lVar7 = *(longlong *)(lVar7 + 0x2e8);
    lVar18 = plVar9[-1];
    puVar1 = *(undefined8 **)(lVar7 + 8);
    *puVar1 = plVar9 + -2;
    plVar9[-2] = lVar7;
    plVar9[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar1;
    *(longlong **)(lVar7 + 8) = plVar9 + -2;
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))();
  }
LAB_23e701333:
  plStack_68 = plVar9;
  FUN_23e8bba40(plVar2,"oooooooooooooooooo",plVar6,plVar8,plStack_170,plStack_128,plStack_140,
                plStack_150,plStack_168,pcStack_110,plStack_160,plStack_120,plStack_130,plStack_138,
                plStack_a8,plStack_148,plStack_108,plStack_118,pcStack_158,plStack_100);
  if (_DAT_23eedb1a0 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    _DAT_23eedb1a0 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar2 = *(longlong **)(lVar7 + 0x28);
  plVar9 = (longlong *)plVar2[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
  *(undefined4 *)(plVar2 + 8) = 0xffffffff;
  if (plVar9 != (longlong *)0x0) {
    plVar2[2] = 0;
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))();
    }
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  plVar10 = plStack_68;
  plVar9 = plStack_70;
  auVar21 = auStack_78;
  plVar2[0xf] = 0;
  _auStack_78 = (undefined1  [16])0x0;
  plStack_68 = (longlong *)0x0;
  if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plStack_170 != (longlong *)0x0) &&
     (lVar7 = *plStack_170, *plStack_170 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_170[1] + 0x30))(plStack_170);
  }
  if ((plStack_128 != (longlong *)0x0) &&
     (lVar7 = *plStack_128, *plStack_128 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_128[1] + 0x30))();
  }
  if ((plStack_140 != (longlong *)0x0) &&
     (lVar7 = *plStack_140, *plStack_140 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_140[1] + 0x30))(plStack_140);
  }
  if ((plStack_150 != (longlong *)0x0) &&
     (lVar7 = *plStack_150, *plStack_150 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_150[1] + 0x30))(plStack_150);
  }
  if ((plStack_168 != (longlong *)0x0) &&
     (lVar7 = *plStack_168, *plStack_168 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_168[1] + 0x30))();
  }
  if ((pcStack_110 != (code *)0x0) &&
     (lVar7 = *(longlong *)pcStack_110, *(longlong *)pcStack_110 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(*(longlong *)(pcStack_110 + 8) + 0x30))(pcStack_110);
  }
  if ((plStack_160 != (longlong *)0x0) &&
     (lVar7 = *plStack_160, *plStack_160 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_160[1] + 0x30))(plStack_160);
  }
  if ((plStack_120 != (longlong *)0x0) &&
     (lVar7 = *plStack_120, *plStack_120 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_120[1] + 0x30))();
  }
  if ((plStack_130 != (longlong *)0x0) &&
     (lVar7 = *plStack_130, *plStack_130 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_130[1] + 0x30))(plStack_130);
  }
  if ((plStack_138 != (longlong *)0x0) &&
     (lVar7 = *plStack_138, *plStack_138 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_138[1] + 0x30))(plStack_138);
  }
  if ((plStack_a8 != (longlong *)0x0) && (*plStack_a8 = *plStack_a8 + -1, *plStack_a8 == 0)) {
    (**(code **)(plStack_a8[1] + 0x30))(plStack_a8);
  }
  if ((plStack_148 != (longlong *)0x0) &&
     (lVar7 = *plStack_148, *plStack_148 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_148[1] + 0x30))();
  }
  if ((plStack_108 != (longlong *)0x0) &&
     (lVar7 = *plStack_108, *plStack_108 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_108[1] + 0x30))(plStack_108);
  }
  if ((plStack_118 != (longlong *)0x0) &&
     (lVar7 = *plStack_118, *plStack_118 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_118[1] + 0x30))(plStack_118);
  }
  if ((pcStack_158 != (code *)0x0) &&
     (lVar7 = *(longlong *)pcStack_158, *(longlong *)pcStack_158 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(*(longlong *)((longlong)pcStack_158 + 8) + 0x30))();
  }
  if ((plStack_100 != (longlong *)0x0) &&
     (lVar7 = *plStack_100, *plStack_100 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_100[1] + 0x30))(plStack_100);
  }
  _auStack_78 = CONCAT88(plVar9,auVar21);
  plStack_68 = plVar10;
  FUN_23a33aa70(param_1,auVar21,plVar9,plVar10);
  return (code *)0x0;
}
