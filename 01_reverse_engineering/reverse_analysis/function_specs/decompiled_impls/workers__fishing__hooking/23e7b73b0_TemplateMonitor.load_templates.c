/* ===== 23e7b73b0 workers.fishing.hooking:246 ===== */
/* ghidra_name=FUN_23e7b73b0 entry=23e7b73b0 size=37651 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e7b73b0(longlong param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong *plVar3;
  char cVar4;
  int iVar5;
  undefined8 uVar6;
  longlong *plVar7;
  longlong lVar8;
  longlong *plVar9;
  longlong *plVar10;
  code *pcVar11;
  longlong *plVar12;
  code *pcVar13;
  code *pcVar14;
  longlong *plVar15;
  longlong *plVar16;
  undefined8 uVar17;
  longlong lVar18;
  longlong lVar19;
  code *pcVar20;
  code *pcVar21;
  undefined4 uVar22;
  undefined1 auVar23 [8];
  undefined8 in_stack_fffffffffffffdb8;
  longlong *plStack_1a0;
  longlong *plStack_198;
  longlong *plStack_190;
  longlong *plStack_188;
  longlong *plStack_180;
  longlong *plStack_178;
  longlong *plStack_170;
  longlong *plStack_168;
  longlong *plStack_160;
  longlong *plStack_158;
  longlong *plStack_150;
  code *pcStack_148;
  code *pcStack_140;
  longlong *plStack_138;
  longlong *plStack_130;
  longlong *plStack_128;
  int iStack_120;
  longlong *plStack_e0;
  longlong *plStack_d8;
  longlong *plStack_d0;
  longlong *plStack_c8;
  longlong *plStack_c0;
  longlong *plStack_b8;
  longlong *plStack_b0;
  longlong *plStack_a8;
  longlong *plStack_a0;
  undefined1 auStack_98 [8];
  longlong *plStack_90;
  longlong *plStack_88;
  code *pcStack_78;
  longlong *plStack_70;
  longlong *plStack_68;
  
  plVar7 = _DAT_23eedaaa0;
  plStack_88 = (longlong *)0x0;
  auStack_98 = (undefined1  [8])0x0;
  plStack_90 = (longlong *)0x0;
  if (_DAT_23eedaaa0 == (longlong *)0x0) {
LAB_23e7b740a:
    _DAT_23eedaaa0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedaa98,DAT_23eedab78,0xa8);
  }
  else {
    lVar8 = *_DAT_23eedaaa0;
    if (1 < lVar8) {
      *_DAT_23eedaaa0 = lVar8 + -1;
      goto LAB_23e7b740a;
    }
    if (_DAT_23eedaaa0[2] != 0) {
      *_DAT_23eedaaa0 = lVar8 + -1;
      if (lVar8 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23e7b740a;
    }
  }
  plVar2 = _DAT_23eedaaa0;
  lVar8 = *(longlong *)(param_1 + 0x38);
  plVar7 = _DAT_23eedaaa0 + 9;
  lVar19 = *(longlong *)(lVar8 + 8);
  _DAT_23eedaaa0[0xf] = lVar19;
  *(longlong **)(lVar8 + 8) = plVar7;
  if ((lVar19 != 0) &&
     (((*(char *)(lVar19 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar19 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar19 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar19 + 0x38))) && (plVar2[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar19 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  *(undefined4 *)(plVar2 + 8) = 0;
  uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
  *(undefined4 *)(plVar2 + 5) = 0xf8;
  plVar7 = (longlong *)FUN_23e94bb80(param_1,uVar6,_DAT_23eed7cb8);
  if (plVar7 == (longlong *)0x0) {
    auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
    plStack_90 = *(longlong **)(param_1 + 0x68);
    plStack_88 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar20 = _PyRuntime_exref;
    if (plStack_88 == (longlong *)0x0) {
      plStack_150 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcVar13 = (code *)0x0;
      pcVar11 = (code *)0x0;
      uVar22 = 0xf8;
      plStack_158 = (longlong *)0x0;
      plStack_198 = (longlong *)0x0;
      plStack_190 = (longlong *)0x0;
      plStack_188 = (longlong *)0x0;
      plStack_180 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_178 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      pcStack_148 = (code *)0x0;
      pcStack_140 = (code *)0x0;
      plStack_1a0 = (longlong *)0x0;
      plVar7 = (longlong *)0x0;
      goto LAB_23e7baa40;
    }
    if ((longlong *)plStack_88[3] != plVar2) {
      plStack_150 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcVar13 = (code *)0x0;
      pcVar11 = (code *)0x0;
      uVar22 = 0xf8;
      plStack_158 = (longlong *)0x0;
      plStack_198 = (longlong *)0x0;
      plStack_190 = (longlong *)0x0;
      plStack_188 = (longlong *)0x0;
      plStack_180 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_178 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      pcStack_148 = (code *)0x0;
      pcStack_140 = (code *)0x0;
      plStack_1a0 = (longlong *)0x0;
      plVar7 = (longlong *)0x0;
      goto LAB_23e7b9b10;
    }
LAB_23e7ba2e0:
    plStack_150 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    pcVar13 = (code *)0x0;
    plStack_160 = (longlong *)0x0;
    pcVar11 = (code *)0x0;
    plVar7 = (longlong *)0x0;
    plStack_158 = (longlong *)0x0;
    plStack_198 = (longlong *)0x0;
    plStack_190 = (longlong *)0x0;
    plStack_188 = (longlong *)0x0;
    plStack_180 = (longlong *)0x0;
    plStack_170 = (longlong *)0x0;
    plStack_168 = (longlong *)0x0;
    plStack_178 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    pcStack_148 = (code *)0x0;
    pcStack_140 = (code *)0x0;
    plStack_1a0 = (longlong *)0x0;
    plVar10 = plStack_88;
    goto LAB_23e7b9bc3;
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
  *(undefined4 *)(plVar2 + 5) = 0xf9;
  plVar7 = (longlong *)FUN_23e94bb80(param_1,uVar6,_DAT_23eed7cc0);
  if (plVar7 == (longlong *)0x0) {
    auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
    plStack_90 = *(longlong **)(param_1 + 0x68);
    plStack_88 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar20 = _PyRuntime_exref;
    if (plStack_88 == (longlong *)0x0) {
      plStack_150 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcVar13 = (code *)0x0;
      pcVar11 = (code *)0x0;
      uVar22 = 0xf9;
      plStack_158 = (longlong *)0x0;
      plStack_198 = (longlong *)0x0;
      plStack_190 = (longlong *)0x0;
      plStack_188 = (longlong *)0x0;
      plStack_180 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_178 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      pcStack_148 = (code *)0x0;
      pcStack_140 = (code *)0x0;
      plStack_1a0 = (longlong *)0x0;
      plVar7 = (longlong *)0x0;
      goto LAB_23e7baa40;
    }
    if ((longlong *)plStack_88[3] == plVar2) goto LAB_23e7ba2e0;
    plStack_150 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_160 = (longlong *)0x0;
    pcVar13 = (code *)0x0;
    pcVar11 = (code *)0x0;
    uVar22 = 0xf9;
    plStack_158 = (longlong *)0x0;
    plStack_198 = (longlong *)0x0;
    plStack_190 = (longlong *)0x0;
    plStack_188 = (longlong *)0x0;
    plStack_180 = (longlong *)0x0;
    plStack_170 = (longlong *)0x0;
    plStack_168 = (longlong *)0x0;
    plStack_178 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    pcStack_148 = (code *)0x0;
    pcStack_140 = (code *)0x0;
    plStack_1a0 = (longlong *)0x0;
    plVar7 = (longlong *)0x0;
LAB_23e7b9b10:
    plVar12 = plStack_88;
    plVar10 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar15 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar15;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar10[3] = (longlong)plVar2;
    *plVar2 = *plVar2 + 1;
    lVar8 = *(longlong *)(pcVar20 + 0x1f8);
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar22;
    lVar8 = *(longlong *)(lVar8 + 0x10);
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar8 = *(longlong *)(lVar8 + 0x2e8);
    lVar19 = plVar10[-1];
    puVar1 = *(undefined8 **)(lVar8 + 8);
    *puVar1 = plVar10 + -2;
    plVar10[-2] = lVar8;
    plVar10[-1] = (ulonglong)((uint)lVar19 & 3) | (ulonglong)puVar1;
    *(longlong **)(lVar8 + 8) = plVar10 + -2;
    plVar10[2] = (longlong)plVar12;
    *plVar12 = *plVar12 + 1;
    plVar12 = plStack_88;
  }
  else {
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
    *(undefined4 *)(plVar2 + 5) = 0xfa;
    plVar7 = (longlong *)FUN_23e94bb80(param_1,uVar6,_DAT_23eed7cc8);
    if (plVar7 == (longlong *)0x0) {
      auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_90 = *(longlong **)(param_1 + 0x68);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcVar20 = _PyRuntime_exref;
      if (plStack_88 == (longlong *)0x0) {
        plStack_150 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
        pcVar13 = (code *)0x0;
        pcVar11 = (code *)0x0;
        uVar22 = 0xfa;
        plStack_158 = (longlong *)0x0;
        plStack_198 = (longlong *)0x0;
        plStack_190 = (longlong *)0x0;
        plStack_188 = (longlong *)0x0;
        plStack_180 = (longlong *)0x0;
        plStack_170 = (longlong *)0x0;
        plStack_168 = (longlong *)0x0;
        plStack_178 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        pcStack_148 = (code *)0x0;
        pcStack_140 = (code *)0x0;
        plStack_1a0 = (longlong *)0x0;
        plVar7 = (longlong *)0x0;
        goto LAB_23e7baa40;
      }
      if ((longlong *)plStack_88[3] == plVar2) goto LAB_23e7ba2e0;
      plStack_150 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcVar13 = (code *)0x0;
      pcVar11 = (code *)0x0;
      uVar22 = 0xfa;
      plStack_158 = (longlong *)0x0;
      plStack_198 = (longlong *)0x0;
      plStack_190 = (longlong *)0x0;
      plStack_188 = (longlong *)0x0;
      plStack_180 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_178 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      pcStack_148 = (code *)0x0;
      pcStack_140 = (code *)0x0;
      plStack_1a0 = (longlong *)0x0;
      plVar7 = (longlong *)0x0;
      goto LAB_23e7b9b10;
    }
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    uVar6 = DAT_23ed6cd08;
    lVar8 = FUN_23e8def00();
    if (lVar8 == 0) {
      FUN_23e915740(param_1,auStack_98,_DAT_23eed7b00);
      if (plStack_88 == (longlong *)0x0) {
LAB_23e7ba960:
        plStack_150 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
        pcVar13 = (code *)0x0;
        pcVar11 = (code *)0x0;
        plVar7 = (longlong *)0x0;
        plStack_158 = (longlong *)0x0;
        uVar22 = 0xfd;
        plStack_198 = (longlong *)0x0;
        plStack_190 = (longlong *)0x0;
        plStack_188 = (longlong *)0x0;
        plStack_180 = (longlong *)0x0;
        plStack_170 = (longlong *)0x0;
        plStack_168 = (longlong *)0x0;
        plStack_178 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        pcStack_148 = (code *)0x0;
        pcStack_140 = (code *)0x0;
        plStack_1a0 = (longlong *)0x0;
        pcVar20 = _PyRuntime_exref;
        goto LAB_23e7baa40;
      }
      if ((longlong *)plStack_88[3] == plVar2) goto LAB_23e7ba2e0;
      plStack_150 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcVar13 = (code *)0x0;
      pcVar11 = (code *)0x0;
      uVar22 = 0xfd;
      plStack_158 = (longlong *)0x0;
      plStack_198 = (longlong *)0x0;
      plStack_190 = (longlong *)0x0;
      plStack_188 = (longlong *)0x0;
      plStack_180 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_178 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      pcStack_148 = (code *)0x0;
      pcStack_140 = (code *)0x0;
      plStack_1a0 = (longlong *)0x0;
      plVar7 = (longlong *)0x0;
      pcVar20 = _PyRuntime_exref;
      goto LAB_23e7b9b10;
    }
    cVar4 = FUN_23e8d9ac0(lVar8,_DAT_23eed7b08,uVar6);
    if (cVar4 == '\0') {
      auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_90 = *(longlong **)(param_1 + 0x68);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plStack_88 == (longlong *)0x0) goto LAB_23e7ba960;
      if ((longlong *)plStack_88[3] == plVar2) goto LAB_23e7ba2e0;
      plStack_150 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcVar13 = (code *)0x0;
      pcVar11 = (code *)0x0;
      plVar7 = (longlong *)0x0;
      plStack_158 = (longlong *)0x0;
      uVar22 = 0xfd;
      plStack_198 = (longlong *)0x0;
      plStack_190 = (longlong *)0x0;
      plStack_188 = (longlong *)0x0;
      plStack_180 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_178 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      pcStack_148 = (code *)0x0;
      pcStack_140 = (code *)0x0;
      plStack_1a0 = (longlong *)0x0;
      pcVar20 = _PyRuntime_exref;
      goto LAB_23e7b9b10;
    }
    lVar8 = FUN_23e8def00();
    if (lVar8 == 0) {
      FUN_23e915740(param_1,auStack_98,_DAT_23eed7b00);
      if (plStack_88 == (longlong *)0x0) {
LAB_23e7bb450:
        plStack_150 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
        pcVar13 = (code *)0x0;
        pcVar11 = (code *)0x0;
        plVar7 = (longlong *)0x0;
        plStack_158 = (longlong *)0x0;
        uVar22 = 0xfe;
        plStack_198 = (longlong *)0x0;
        plStack_190 = (longlong *)0x0;
        plStack_188 = (longlong *)0x0;
        plStack_180 = (longlong *)0x0;
        plStack_170 = (longlong *)0x0;
        plStack_168 = (longlong *)0x0;
        plStack_178 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        pcStack_148 = (code *)0x0;
        pcStack_140 = (code *)0x0;
        plStack_1a0 = (longlong *)0x0;
        pcVar20 = _PyRuntime_exref;
        goto LAB_23e7baa40;
      }
      if (plVar2 == (longlong *)plStack_88[3]) goto LAB_23e7ba2e0;
      plStack_150 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcVar13 = (code *)0x0;
      pcVar11 = (code *)0x0;
      uVar22 = 0xfe;
      plStack_158 = (longlong *)0x0;
      plStack_198 = (longlong *)0x0;
      plStack_190 = (longlong *)0x0;
      plStack_188 = (longlong *)0x0;
      plStack_180 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_178 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      pcStack_148 = (code *)0x0;
      pcStack_140 = (code *)0x0;
      plStack_1a0 = (longlong *)0x0;
      plVar7 = (longlong *)0x0;
      pcVar20 = _PyRuntime_exref;
      goto LAB_23e7b9b10;
    }
    cVar4 = FUN_23e8d9ac0(lVar8,_DAT_23eed7b10,_Py_FalseStruct_exref);
    if (cVar4 == '\0') {
      auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_90 = *(longlong **)(param_1 + 0x68);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plStack_88 == (longlong *)0x0) goto LAB_23e7bb450;
      if ((longlong *)plStack_88[3] == plVar2) goto LAB_23e7ba2e0;
      plStack_150 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcVar13 = (code *)0x0;
      pcVar11 = (code *)0x0;
      plVar7 = (longlong *)0x0;
      plStack_158 = (longlong *)0x0;
      uVar22 = 0xfe;
      plStack_198 = (longlong *)0x0;
      plStack_190 = (longlong *)0x0;
      plStack_188 = (longlong *)0x0;
      plStack_180 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_178 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      pcStack_148 = (code *)0x0;
      pcStack_140 = (code *)0x0;
      plStack_1a0 = (longlong *)0x0;
      pcVar20 = _PyRuntime_exref;
      goto LAB_23e7b9b10;
    }
    uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
    *(undefined4 *)(plVar2 + 5) = 0x101;
    plVar7 = (longlong *)FUN_23e94bb80(param_1,uVar6,_DAT_23eed7cd0);
    if (plVar7 == (longlong *)0x0) {
      auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_90 = *(longlong **)(param_1 + 0x68);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcVar20 = _PyRuntime_exref;
      if (plStack_88 == (longlong *)0x0) {
        plStack_150 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
        pcVar13 = (code *)0x0;
        pcVar11 = (code *)0x0;
        uVar22 = 0x101;
        plStack_158 = (longlong *)0x0;
        plStack_198 = (longlong *)0x0;
        plStack_190 = (longlong *)0x0;
        plStack_188 = (longlong *)0x0;
        plStack_180 = (longlong *)0x0;
        plStack_170 = (longlong *)0x0;
        plStack_168 = (longlong *)0x0;
        plStack_178 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        pcStack_148 = (code *)0x0;
        pcStack_140 = (code *)0x0;
        plStack_1a0 = (longlong *)0x0;
        plVar7 = (longlong *)0x0;
        goto LAB_23e7baa40;
      }
      if ((longlong *)plStack_88[3] == plVar2) goto LAB_23e7ba2e0;
      plStack_150 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcVar13 = (code *)0x0;
      pcVar11 = (code *)0x0;
      uVar22 = 0x101;
      plStack_158 = (longlong *)0x0;
      plStack_198 = (longlong *)0x0;
      plStack_190 = (longlong *)0x0;
      plStack_188 = (longlong *)0x0;
      plStack_180 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_178 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      pcStack_148 = (code *)0x0;
      pcStack_140 = (code *)0x0;
      plStack_1a0 = (longlong *)0x0;
      plVar7 = (longlong *)0x0;
      goto LAB_23e7b9b10;
    }
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    lVar8 = *(longlong *)(_DAT_23eed7948 + 0x20);
    if (*(char *)(lVar8 + 10) != '\0') {
      iVar5 = *(int *)(lVar8 + 0xc);
      if (*(int *)(lVar8 + 0xc) == 0) {
        *(int *)(lVar8 + 0xc) = _DAT_23ec153f4;
        iVar5 = _DAT_23ec153f4;
        _DAT_23ec153f4 = _DAT_23ec153f4 + 1;
      }
      if (_DAT_23ec153d0 != iVar5) {
        _DAT_23ec153d0 = iVar5;
        _DAT_23eedaa80 = FUN_23e8cbd60(lVar8,_DAT_23eed7cd8,*(undefined8 *)(_DAT_23eed7cd8 + 0x18));
      }
      if (-1 < _DAT_23eedaa80) {
        lVar19 = lVar8 + 0x20 + (1L << (*(byte *)(lVar8 + 9) & 0x3f));
        lVar18 = *(longlong *)(lVar19 + 8 + _DAT_23eedaa80 * 0x10);
        if (lVar18 != 0) goto LAB_23e7b764b;
        _DAT_23eedaa80 = FUN_23e8cbd60(lVar8,_DAT_23eed7cd8,*(undefined8 *)(_DAT_23eed7cd8 + 0x18));
        if (-1 < _DAT_23eedaa80) {
          lVar18 = *(longlong *)(lVar19 + 8 + _DAT_23eedaa80 * 0x10);
          goto LAB_23e7bb318;
        }
      }
LAB_23e7ba139:
      plVar7 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eed7cd8);
      if ((plVar7 != (longlong *)0x0) && (lVar18 = *plVar7, lVar18 != 0)) goto LAB_23e7b764b;
      FUN_23e915740(param_1,auStack_98,_DAT_23eed7cd8);
      if (plStack_88 != (longlong *)0x0) {
        if ((longlong *)plStack_88[3] == plVar2) goto LAB_23e7ba2e0;
        plStack_150 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
        pcVar13 = (code *)0x0;
        pcVar11 = (code *)0x0;
        plVar7 = (longlong *)0x0;
        plStack_158 = (longlong *)0x0;
        uVar22 = 0x102;
        plStack_198 = (longlong *)0x0;
        plStack_190 = (longlong *)0x0;
        plStack_188 = (longlong *)0x0;
        plStack_180 = (longlong *)0x0;
        plStack_170 = (longlong *)0x0;
        plStack_168 = (longlong *)0x0;
        plStack_178 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        pcStack_148 = (code *)0x0;
        pcStack_140 = (code *)0x0;
        plStack_1a0 = (longlong *)0x0;
        pcVar20 = _PyRuntime_exref;
        goto LAB_23e7b9b10;
      }
LAB_23e7bc1f0:
      plStack_150 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcVar13 = (code *)0x0;
      pcVar11 = (code *)0x0;
      plVar7 = (longlong *)0x0;
      plStack_158 = (longlong *)0x0;
      uVar22 = 0x102;
      plStack_198 = (longlong *)0x0;
      plStack_190 = (longlong *)0x0;
      plStack_188 = (longlong *)0x0;
      plStack_180 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_178 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      pcStack_148 = (code *)0x0;
      pcStack_140 = (code *)0x0;
      plStack_1a0 = (longlong *)0x0;
      pcVar20 = _PyRuntime_exref;
      goto LAB_23e7baa40;
    }
    plVar7 = (longlong *)FUN_23a37a020(_DAT_23eed7948,_DAT_23eed7cd8);
    if (plVar7 == (longlong *)0x0) goto LAB_23e7ba139;
    lVar18 = *plVar7;
LAB_23e7bb318:
    if (lVar18 == 0) goto LAB_23e7ba139;
LAB_23e7b764b:
    *(undefined4 *)(plVar2 + 5) = 0x102;
    plVar7 = (longlong *)FUN_23e94bb80(param_1,lVar18,_DAT_23eed7ce0);
    if (plVar7 == (longlong *)0x0) {
      auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_90 = *(longlong **)(param_1 + 0x68);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plStack_88 == (longlong *)0x0) goto LAB_23e7bc1f0;
      if ((longlong *)plStack_88[3] == plVar2) goto LAB_23e7ba2e0;
      plStack_150 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcVar13 = (code *)0x0;
      pcVar11 = (code *)0x0;
      uVar22 = 0x102;
      plStack_158 = (longlong *)0x0;
      plStack_198 = (longlong *)0x0;
      plStack_190 = (longlong *)0x0;
      plStack_188 = (longlong *)0x0;
      plStack_180 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_178 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      pcStack_148 = (code *)0x0;
      pcStack_140 = (code *)0x0;
      plStack_1a0 = (longlong *)0x0;
      pcVar20 = _PyRuntime_exref;
      goto LAB_23e7b9b10;
    }
    *(undefined4 *)(plVar2 + 5) = 0x104;
    plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar7,_DAT_23eed7ce8);
    if (plVar9 == (longlong *)0x0) {
      auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_90 = *(longlong **)(param_1 + 0x68);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plStack_88 == (longlong *)0x0) {
LAB_23e7bc69d:
        plStack_150 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
        pcVar13 = (code *)0x0;
        pcVar11 = (code *)0x0;
        uVar22 = 0x104;
        plStack_158 = (longlong *)0x0;
        plStack_198 = (longlong *)0x0;
        plStack_190 = (longlong *)0x0;
        plStack_188 = (longlong *)0x0;
        plStack_180 = (longlong *)0x0;
        plStack_170 = (longlong *)0x0;
        plStack_168 = (longlong *)0x0;
        plStack_178 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        pcStack_148 = (code *)0x0;
        pcStack_140 = (code *)0x0;
        plStack_1a0 = (longlong *)0x0;
        pcVar20 = _PyRuntime_exref;
        goto LAB_23e7baa40;
      }
      if (plVar2 == (longlong *)plStack_88[3]) goto LAB_23e7bb0b0;
      plStack_150 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      pcVar13 = (code *)0x0;
      plStack_160 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      uVar22 = 0x104;
      plStack_158 = (longlong *)0x0;
      plStack_198 = (longlong *)0x0;
      plStack_190 = (longlong *)0x0;
      plStack_188 = (longlong *)0x0;
      plStack_180 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_178 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      pcStack_148 = (code *)0x0;
      pcStack_140 = (code *)0x0;
      plStack_1a0 = (longlong *)0x0;
      pcVar11 = (code *)0x0;
      pcVar20 = _PyRuntime_exref;
      goto LAB_23e7b9b10;
    }
    iVar5 = FUN_23a35f020();
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))();
    }
    if (iVar5 == -1) {
      auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_90 = *(longlong **)(param_1 + 0x68);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plStack_88 == (longlong *)0x0) goto LAB_23e7bc69d;
      if ((longlong *)plStack_88[3] == plVar2) goto LAB_23e7bb0b0;
      plStack_150 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcVar13 = (code *)0x0;
      pcVar11 = (code *)0x0;
      uVar22 = 0x104;
      plStack_158 = (longlong *)0x0;
      plStack_198 = (longlong *)0x0;
      plStack_190 = (longlong *)0x0;
      plStack_188 = (longlong *)0x0;
      plStack_180 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_178 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      pcStack_148 = (code *)0x0;
      pcStack_140 = (code *)0x0;
      plStack_1a0 = (longlong *)0x0;
      pcVar20 = _PyRuntime_exref;
      goto LAB_23e7b9b10;
    }
    if (iVar5 == 0) {
      uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
      *(undefined4 *)(plVar2 + 5) = 0x105;
      plVar9 = (longlong *)FUN_23e94bb80(param_1,uVar6,_DAT_23eed7cf0);
      if (plVar9 == (longlong *)0x0) {
        auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
        plStack_90 = *(longlong **)(param_1 + 0x68);
        plStack_88 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar20 = _PyRuntime_exref;
        if (plStack_88 != (longlong *)0x0) {
          if ((longlong *)plStack_88[3] == plVar2) goto LAB_23e7bb0b0;
          plStack_150 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          pcVar13 = (code *)0x0;
          plStack_160 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          uVar22 = 0x105;
          plStack_158 = (longlong *)0x0;
          plStack_198 = (longlong *)0x0;
          plStack_190 = (longlong *)0x0;
          plStack_188 = (longlong *)0x0;
          plStack_180 = (longlong *)0x0;
          plStack_170 = (longlong *)0x0;
          plStack_168 = (longlong *)0x0;
          plStack_178 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
          pcStack_148 = (code *)0x0;
          pcStack_140 = (code *)0x0;
          plStack_1a0 = (longlong *)0x0;
          pcVar11 = (code *)0x0;
          goto LAB_23e7b9b10;
        }
        plStack_150 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        pcVar13 = (code *)0x0;
        plStack_160 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        uVar22 = 0x105;
        plStack_158 = (longlong *)0x0;
        plStack_198 = (longlong *)0x0;
        plStack_190 = (longlong *)0x0;
        plStack_188 = (longlong *)0x0;
        plStack_180 = (longlong *)0x0;
        plStack_170 = (longlong *)0x0;
        plStack_168 = (longlong *)0x0;
        plStack_178 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        pcStack_148 = (code *)0x0;
        pcStack_140 = (code *)0x0;
        plStack_1a0 = (longlong *)0x0;
        pcVar11 = (code *)0x0;
      }
      else {
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
        *(undefined4 *)(plVar2 + 5) = 0x106;
        plVar9 = (longlong *)FUN_23e94bb80(param_1,uVar6,_DAT_23eed7cf8);
        if (plVar9 == (longlong *)0x0) {
          auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
          plStack_90 = *(longlong **)(param_1 + 0x68);
          plStack_88 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar20 = _PyRuntime_exref;
          if (plStack_88 != (longlong *)0x0) {
            if ((longlong *)plStack_88[3] == plVar2) goto LAB_23e7bb0b0;
            plStack_150 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            pcVar13 = (code *)0x0;
            plStack_160 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            uVar22 = 0x106;
            plStack_158 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_190 = (longlong *)0x0;
            plStack_188 = (longlong *)0x0;
            plStack_180 = (longlong *)0x0;
            plStack_170 = (longlong *)0x0;
            plStack_168 = (longlong *)0x0;
            plStack_178 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_130 = (longlong *)0x0;
            plStack_138 = (longlong *)0x0;
            pcStack_148 = (code *)0x0;
            pcStack_140 = (code *)0x0;
            plStack_1a0 = (longlong *)0x0;
            pcVar11 = (code *)0x0;
            goto LAB_23e7b9b10;
          }
          plStack_150 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          pcVar13 = (code *)0x0;
          plStack_160 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          uVar22 = 0x106;
          plStack_158 = (longlong *)0x0;
          plStack_198 = (longlong *)0x0;
          plStack_190 = (longlong *)0x0;
          plStack_188 = (longlong *)0x0;
          plStack_180 = (longlong *)0x0;
          plStack_170 = (longlong *)0x0;
          plStack_168 = (longlong *)0x0;
          plStack_178 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
          pcStack_148 = (code *)0x0;
          pcStack_140 = (code *)0x0;
          plStack_1a0 = (longlong *)0x0;
          pcVar11 = (code *)0x0;
        }
        else {
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          plVar9 = (longlong *)FUN_23e935de0(param_1,_DAT_23eed7d00);
          if (plVar9 == (longlong *)0x0) {
            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
            plStack_90 = *(longlong **)(param_1 + 0x68);
            plStack_88 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcVar20 = _PyRuntime_exref;
            if (plStack_88 == (longlong *)0x0) {
              plStack_150 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              pcVar13 = (code *)0x0;
              plStack_160 = (longlong *)0x0;
              plStack_d8 = (longlong *)0x0;
              uVar22 = 0x107;
              plStack_158 = (longlong *)0x0;
              plStack_198 = (longlong *)0x0;
              plStack_190 = (longlong *)0x0;
              plStack_188 = (longlong *)0x0;
              plStack_180 = (longlong *)0x0;
              plStack_170 = (longlong *)0x0;
              plStack_168 = (longlong *)0x0;
              plStack_178 = (longlong *)0x0;
              plStack_128 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_138 = (longlong *)0x0;
              pcStack_148 = (code *)0x0;
              pcStack_140 = (code *)0x0;
              plStack_1a0 = (longlong *)0x0;
              pcVar11 = (code *)0x0;
              goto LAB_23e7baa40;
            }
            if ((longlong *)plStack_88[3] != plVar2) {
              plStack_150 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              pcVar13 = (code *)0x0;
              plStack_160 = (longlong *)0x0;
              plStack_d8 = (longlong *)0x0;
              uVar22 = 0x107;
              plStack_158 = (longlong *)0x0;
              plStack_198 = (longlong *)0x0;
              plStack_190 = (longlong *)0x0;
              plStack_188 = (longlong *)0x0;
              plStack_180 = (longlong *)0x0;
              plStack_170 = (longlong *)0x0;
              plStack_168 = (longlong *)0x0;
              plStack_178 = (longlong *)0x0;
              plStack_128 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_138 = (longlong *)0x0;
              pcStack_148 = (code *)0x0;
              pcStack_140 = (code *)0x0;
              plStack_1a0 = (longlong *)0x0;
              pcVar11 = (code *)0x0;
              goto LAB_23e7b9b10;
            }
            goto LAB_23e7bb0b0;
          }
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          auStack_98 = (undefined1  [8])
                       FUN_23e91b0f0(param_1,*(undefined8 *)PyExc_SystemExit_exref,DAT_23ed6ccf8);
          FUN_23e91b7d0(param_1,auStack_98);
          pcVar20 = _PyRuntime_exref;
          if (plStack_88 != (longlong *)0x0) {
            if ((longlong *)plStack_88[3] == plVar2) goto LAB_23e7bb0b0;
            plStack_150 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            plStack_160 = (longlong *)0x0;
            pcVar13 = (code *)0x0;
            pcVar11 = (code *)0x0;
            uVar22 = 0x108;
            plStack_158 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_190 = (longlong *)0x0;
            plStack_188 = (longlong *)0x0;
            plStack_180 = (longlong *)0x0;
            plStack_170 = (longlong *)0x0;
            plStack_168 = (longlong *)0x0;
            plStack_178 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_130 = (longlong *)0x0;
            plStack_138 = (longlong *)0x0;
            pcStack_148 = (code *)0x0;
            pcStack_140 = (code *)0x0;
            plStack_1a0 = (longlong *)0x0;
            goto LAB_23e7b9b10;
          }
          plStack_150 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          plStack_160 = (longlong *)0x0;
          pcVar13 = (code *)0x0;
          pcVar11 = (code *)0x0;
          uVar22 = 0x108;
          plStack_158 = (longlong *)0x0;
          plStack_198 = (longlong *)0x0;
          plStack_190 = (longlong *)0x0;
          plStack_188 = (longlong *)0x0;
          plStack_180 = (longlong *)0x0;
          plStack_170 = (longlong *)0x0;
          plStack_168 = (longlong *)0x0;
          plStack_178 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
          pcStack_148 = (code *)0x0;
          pcStack_140 = (code *)0x0;
          plStack_1a0 = (longlong *)0x0;
        }
      }
    }
    else {
      uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
      *(undefined4 *)(plVar2 + 5) = 0x10a;
      plVar9 = (longlong *)FUN_23e94bb80(param_1,uVar6,_DAT_23eed7d08);
      if (plVar9 == (longlong *)0x0) {
        auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
        plStack_90 = *(longlong **)(param_1 + 0x68);
        plStack_88 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar20 = _PyRuntime_exref;
        if (plStack_88 != (longlong *)0x0) {
          if ((longlong *)plStack_88[3] == plVar2) goto LAB_23e7bb0b0;
          plStack_150 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          pcVar13 = (code *)0x0;
          plStack_160 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          uVar22 = 0x10a;
          plStack_158 = (longlong *)0x0;
          plStack_198 = (longlong *)0x0;
          plStack_190 = (longlong *)0x0;
          plStack_188 = (longlong *)0x0;
          plStack_180 = (longlong *)0x0;
          plStack_170 = (longlong *)0x0;
          plStack_168 = (longlong *)0x0;
          plStack_178 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
          pcStack_148 = (code *)0x0;
          pcStack_140 = (code *)0x0;
          plStack_1a0 = (longlong *)0x0;
          pcVar11 = (code *)0x0;
          goto LAB_23e7b9b10;
        }
        plStack_150 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        pcVar13 = (code *)0x0;
        plStack_160 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        uVar22 = 0x10a;
        plStack_158 = (longlong *)0x0;
        plStack_198 = (longlong *)0x0;
        plStack_190 = (longlong *)0x0;
        plStack_188 = (longlong *)0x0;
        plStack_180 = (longlong *)0x0;
        plStack_170 = (longlong *)0x0;
        plStack_168 = (longlong *)0x0;
        plStack_178 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        pcStack_148 = (code *)0x0;
        pcStack_140 = (code *)0x0;
        plStack_1a0 = (longlong *)0x0;
        pcVar11 = (code *)0x0;
        goto LAB_23e7baa40;
      }
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      *(undefined4 *)(plVar2 + 5) = 0x10d;
      plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar7,_DAT_23eed7d10);
      if (plVar9 == (longlong *)0x0) {
LAB_23e7bb298:
        auVar23 = *(undefined1 (*) [8])(param_1 + 0x60);
        plVar12 = *(longlong **)(param_1 + 0x68);
        plVar9 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        plVar10 = (longlong *)FUN_23a388310();
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))();
        }
        if (plVar10 == (longlong *)0x0) goto LAB_23e7bb298;
        pcVar11 = (code *)(**(code **)(plVar10[1] + 0xe0))(plVar10);
        if ((pcVar11 == (code *)0x0) &&
           (pcVar11 = (code *)FUN_23a3c1b70(param_1,auStack_98,0,2), pcVar11 == (code *)0x0)) {
          plStack_1a0 = (longlong *)0x0;
        }
        else {
          plStack_1a0 = (longlong *)(**(code **)(plVar10[1] + 0xe0))(plVar10);
          if (((plStack_1a0 != (longlong *)0x0) ||
              (plStack_1a0 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,1,2),
              plStack_1a0 != (longlong *)0x0)) &&
             (cVar4 = FUN_23a3884a0(param_1,auStack_98,plVar10,2), cVar4 != '\0')) {
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            if (*(longlong *)pcVar11 == 0) {
              (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
            }
            if (*plStack_1a0 == 0) {
              (**(code **)(plStack_1a0[1] + 0x30))();
            }
            lVar8 = *(longlong *)(_DAT_23eed7948 + 0x20);
            if (*(char *)(lVar8 + 10) == '\0') {
              plVar9 = (longlong *)FUN_23a37a020(_DAT_23eed7948,_DAT_23eed7d18);
              if (plVar9 == (longlong *)0x0) goto LAB_23e7bb950;
              lVar19 = *plVar9;
LAB_23e7bb941:
              if (lVar19 == 0) goto LAB_23e7bb950;
LAB_23e7b7898:
              *(undefined4 *)(plVar2 + 5) = 0x10e;
              plStack_70 = plStack_1a0;
              pcStack_78 = pcVar11;
              plVar9 = (longlong *)FUN_23e94ed00(param_1,lVar19,&pcStack_78);
              if (plVar9 != (longlong *)0x0) {
                plVar12 = (longlong *)FUN_23a388310();
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))();
                }
                if (plVar12 != (longlong *)0x0) {
                  pcStack_140 = (code *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
                  if ((pcStack_140 == (code *)0x0) &&
                     (pcStack_140 = (code *)FUN_23a3c1b70(param_1,auStack_98,0,4),
                     pcStack_140 == (code *)0x0)) {
                    plStack_130 = (longlong *)0x0;
                    plStack_138 = (longlong *)0x0;
                    pcStack_148 = (code *)0x0;
                  }
                  else {
                    pcStack_148 = (code *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
                    if ((pcStack_148 == (code *)0x0) &&
                       (pcStack_148 = (code *)FUN_23a3c1b70(param_1,auStack_98,1,4),
                       pcStack_148 == (code *)0x0)) {
                      plStack_130 = (longlong *)0x0;
                      plStack_138 = (longlong *)0x0;
                    }
                    else {
                      plStack_138 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
                      if ((plStack_138 == (longlong *)0x0) &&
                         (plStack_138 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,2,4),
                         plStack_138 == (longlong *)0x0)) {
                        plStack_130 = (longlong *)0x0;
                      }
                      else {
                        plStack_130 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
                        if (((plStack_130 != (longlong *)0x0) ||
                            (plStack_130 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,3,4),
                            plStack_130 != (longlong *)0x0)) &&
                           (cVar4 = FUN_23a3884a0(param_1,auStack_98,plVar12), cVar4 != '\0')) {
                          *plVar12 = *plVar12 + -1;
                          if (*plVar12 == 0) {
                            (**(code **)(plVar12[1] + 0x30))(plVar12);
                          }
                          if (*(longlong *)pcStack_140 == 0) {
                            (**(code **)(*(longlong *)(pcStack_140 + 8) + 0x30))();
                          }
                          if (*(longlong *)pcStack_148 == 0) {
                            (**(code **)(*(longlong *)(pcStack_148 + 8) + 0x30))();
                          }
                          if (*plStack_138 == 0) {
                            (**(code **)(plStack_138[1] + 0x30))();
                          }
                          if (*plStack_130 == 0) {
                            (**(code **)(plStack_130[1] + 0x30))();
                          }
                          uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                          pcVar13 = _DAT_23eed7d20;
                          lVar8 = *(longlong *)(param_1 + 0x10);
                          plVar9 = *(longlong **)(lVar8 + 0xe20);
                          if (plVar9 == (longlong *)0x0) {
                            plVar9 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                          }
                          else {
                            lVar19 = plVar9[3];
                            *(int *)(lVar8 + 0xebc) = *(int *)(lVar8 + 0xebc) + -1;
                            *(longlong *)(lVar8 + 0xe20) = lVar19;
                            *plVar9 = 1;
                          }
                          pcVar20 = _PyRuntime_exref;
                          plVar9[4] = 0;
                          lVar8 = *(longlong *)
                                   (*(longlong *)(*(longlong *)(pcVar20 + 0x1f8) + 0x10) + 0x2e8);
                          lVar19 = plVar9[-1];
                          puVar1 = *(undefined8 **)(lVar8 + 8);
                          *puVar1 = plVar9 + -2;
                          plVar9[-2] = lVar8;
                          plVar9[-1] = (ulonglong)((uint)lVar19 & 3) | (ulonglong)puVar1;
                          *(longlong **)(lVar8 + 8) = plVar9 + -2;
                          plVar10 = DAT_23ed6a4c0;
                          *(longlong *)pcVar13 = *(longlong *)pcVar13 + 1;
                          plVar9[3] = (longlong)pcVar13;
                          plVar12 = DAT_23ed6cd28;
                          pcVar14 = pcVar20;
                          pcVar21 = pcVar11;
                          if (plVar10 == (longlong *)0x0) {
                            plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                            if (plVar10 != (longlong *)0x0) {
                              *plVar10 = *plVar10 + 1;
                              DAT_23ed6a4c0 = plVar10;
                              goto LAB_23e7b7b8d;
                            }
LAB_23e7bd24e:
                            pcVar11 = pcVar21;
                            pcVar20 = pcVar14;
                            PyErr_PrintEx(0);
                            Py_Exit();
LAB_23e7bd261:
                            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                            plStack_90 = *(longlong **)(param_1 + 0x68);
                            plStack_88 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            if (plStack_88 != (longlong *)0x0) {
                              if ((longlong *)plStack_88[3] == plVar2) goto LAB_23e7bc7b6;
                              plVar9 = (longlong *)0x0;
                              plStack_d8 = (longlong *)0x0;
                              uVar22 = 0x111;
                              plStack_150 = (longlong *)0x0;
                              plStack_160 = (longlong *)0x0;
                              plStack_158 = (longlong *)0x0;
                              plStack_198 = (longlong *)0x0;
                              plStack_190 = (longlong *)0x0;
                              plStack_188 = (longlong *)0x0;
                              plStack_180 = (longlong *)0x0;
                              plStack_170 = (longlong *)0x0;
                              plStack_168 = (longlong *)0x0;
                              plStack_178 = (longlong *)0x0;
                              plStack_128 = (longlong *)0x0;
                              goto LAB_23e7b9b10;
                            }
LAB_23e7bc9dc:
                            plVar9 = (longlong *)0x0;
                            plStack_d8 = (longlong *)0x0;
                            plStack_150 = (longlong *)0x0;
                            pcVar13 = (code *)0x0;
                            uVar22 = 0x111;
                            plStack_160 = (longlong *)0x0;
                            plStack_158 = (longlong *)0x0;
                            plStack_198 = (longlong *)0x0;
                            plStack_190 = (longlong *)0x0;
                            plStack_188 = (longlong *)0x0;
                            plStack_180 = (longlong *)0x0;
                            plStack_170 = (longlong *)0x0;
                            plStack_168 = (longlong *)0x0;
                            plStack_178 = (longlong *)0x0;
                            plStack_128 = (longlong *)0x0;
                            goto LAB_23e7baa40;
                          }
LAB_23e7b7b8d:
                          pcStack_78 = pcStack_140;
                          plStack_70 = plVar12;
                          lVar8 = FUN_23e94ed00();
                          if (lVar8 == 0) {
                            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                            plStack_90 = *(longlong **)(param_1 + 0x68);
                            plStack_88 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *plVar9 = *plVar9 + -1;
                            if (*plVar9 == 0) {
                              (**(code **)(plVar9[1] + 0x30))();
                            }
                            if (plStack_88 == (longlong *)0x0) goto LAB_23e7bcde8;
LAB_23e7bc8b7:
                            plStack_128 = (longlong *)0x0;
                            if (plVar2 != (longlong *)plStack_88[3]) {
                              plStack_150 = (longlong *)0x0;
                              plVar9 = (longlong *)0x0;
                              pcVar13 = (code *)0x0;
                              plStack_d8 = (longlong *)0x0;
                              plStack_160 = (longlong *)0x0;
                              uVar22 = 0x110;
                              plStack_158 = (longlong *)0x0;
                              plStack_198 = (longlong *)0x0;
                              plStack_190 = (longlong *)0x0;
                              plStack_188 = (longlong *)0x0;
                              plStack_180 = (longlong *)0x0;
                              plStack_170 = (longlong *)0x0;
                              plStack_168 = (longlong *)0x0;
                              plStack_178 = (longlong *)0x0;
                              goto LAB_23e7b9b10;
                            }
LAB_23e7bc7b6:
                            plStack_150 = (longlong *)0x0;
                            plVar9 = (longlong *)0x0;
                            pcVar13 = (code *)0x0;
                            plStack_d8 = (longlong *)0x0;
                            plStack_160 = (longlong *)0x0;
                            plStack_158 = (longlong *)0x0;
                            plStack_198 = (longlong *)0x0;
                            plStack_190 = (longlong *)0x0;
                            plStack_188 = (longlong *)0x0;
                            plStack_180 = (longlong *)0x0;
                            plStack_170 = (longlong *)0x0;
                            plStack_168 = (longlong *)0x0;
                            plStack_178 = (longlong *)0x0;
                            plStack_128 = (longlong *)0x0;
                            plVar10 = plStack_88;
                            goto LAB_23e7b9bc3;
                          }
                          plVar9[4] = lVar8;
                          plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar9);
                          *plVar9 = *plVar9 + -1;
                          if (*plVar9 == 0) {
                            (**(code **)(plVar9[1] + 0x30))();
                          }
                          if (plVar10 == (longlong *)0x0) {
                            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                            plStack_90 = *(longlong **)(param_1 + 0x68);
                            plStack_88 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            if (plStack_88 != (longlong *)0x0) {
                              if ((longlong *)plStack_88[3] != plVar2) {
                                plVar9 = (longlong *)0x0;
                                plStack_150 = (longlong *)0x0;
                                plStack_d8 = (longlong *)0x0;
                                uVar22 = 0x110;
                                plStack_160 = (longlong *)0x0;
                                plStack_158 = (longlong *)0x0;
                                plStack_198 = (longlong *)0x0;
                                plStack_190 = (longlong *)0x0;
                                plStack_188 = (longlong *)0x0;
                                plStack_180 = (longlong *)0x0;
                                plStack_170 = (longlong *)0x0;
                                plStack_168 = (longlong *)0x0;
                                plStack_178 = (longlong *)0x0;
                                plStack_128 = (longlong *)0x0;
                                pcVar13 = (code *)0x0;
                                goto LAB_23e7b9b10;
                              }
                              goto LAB_23e7bc7b6;
                            }
                          }
                          else {
                            *(undefined4 *)(plVar2 + 5) = 0x110;
                            plVar9 = (longlong *)FUN_23e914090(param_1,uVar6);
                            *plVar10 = *plVar10 + -1;
                            if (*plVar10 == 0) {
                              (**(code **)(plVar10[1] + 0x30))();
                            }
                            if (plVar9 != (longlong *)0x0) {
                              lVar8 = *plVar9;
                              *plVar9 = lVar8 + -1;
                              if (lVar8 + -1 == 0) {
                                (**(code **)(plVar9[1] + 0x30))();
                              }
                              uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                              plVar10 = _DAT_23eed7d28;
                              lVar8 = *(longlong *)(param_1 + 0x10);
                              plVar9 = *(longlong **)(lVar8 + 0xe50);
                              if (plVar9 == (longlong *)0x0) {
                                plVar9 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,8);
                              }
                              else {
                                lVar19 = plVar9[3];
                                *(int *)(lVar8 + 0xed4) = *(int *)(lVar8 + 0xed4) + -1;
                                *(longlong *)(lVar8 + 0xe50) = lVar19;
                                *plVar9 = 1;
                              }
                              *(undefined1 (*) [16])(plVar9 + 3) = (undefined1  [16])0x0;
                              *(undefined1 (*) [16])(plVar9 + 5) = (undefined1  [16])0x0;
                              *(undefined1 (*) [16])(plVar9 + 7) = (undefined1  [16])0x0;
                              *(undefined1 (*) [16])(plVar9 + 9) = (undefined1  [16])0x0;
                              lVar8 = *(longlong *)
                                       (*(longlong *)(*(longlong *)(pcVar20 + 0x1f8) + 0x10) + 0x2e8
                                       );
                              lVar19 = plVar9[-1];
                              puVar1 = *(undefined8 **)(lVar8 + 8);
                              *puVar1 = plVar9 + -2;
                              uVar17 = DAT_23ed6ccf0;
                              plVar9[-2] = lVar8;
                              plVar9[-1] = (ulonglong)((uint)lVar19 & 3) | (ulonglong)puVar1;
                              *(longlong **)(lVar8 + 8) = plVar9 + -2;
                              *plVar10 = *plVar10 + 1;
                              plVar9[3] = (longlong)plVar10;
                              pcVar13 = (code *)FUN_23a388650(param_1,pcStack_148,uVar17,0);
                              plVar10 = DAT_23ed6cd28;
                              if (pcVar13 != (code *)0x0) {
                                if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                  plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format")
                                  ;
                                  if (plVar12 == (longlong *)0x0) goto LAB_23e7bd24e;
                                  *plVar12 = *plVar12 + 1;
                                  DAT_23ed6a4c0 = plVar12;
                                }
                                plStack_70 = plVar10;
                                pcStack_78 = pcVar13;
                                lVar8 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_78);
                                *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
                                if (*(longlong *)pcVar13 == 0) {
                                  (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))();
                                }
                                if (lVar8 != 0) {
                                  plVar9[4] = lVar8;
                                  plVar10 = _DAT_23eed7d30;
                                  uVar17 = DAT_23ed6ccf8;
                                  *_DAT_23eed7d30 = *_DAT_23eed7d30 + 1;
                                  plVar9[5] = (longlong)plVar10;
                                  pcVar13 = (code *)FUN_23a388650(param_1,pcStack_148,uVar17,1);
                                  plVar10 = DAT_23ed6cd28;
                                  if (pcVar13 != (code *)0x0) {
                                    if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                      pcVar14 = pcVar20;
                                      pcVar21 = pcVar11;
                                      plVar12 = (longlong *)
                                                PyDict_GetItemString(DAT_23ed6ccc0,"format");
                                      if (plVar12 == (longlong *)0x0) goto LAB_23e7bd24e;
                                      *plVar12 = *plVar12 + 1;
                                      DAT_23ed6a4c0 = plVar12;
                                    }
                                    plStack_70 = plVar10;
                                    pcStack_78 = pcVar13;
                                    lVar8 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_78);
                                    *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
                                    if (*(longlong *)pcVar13 == 0) {
                                      (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))();
                                    }
                                    if (lVar8 != 0) {
                                      plVar9[6] = lVar8;
                                      uVar17 = _DAT_23eed7d40;
                                      plVar10 = _DAT_23eed7d38;
                                      *_DAT_23eed7d38 = *_DAT_23eed7d38 + 1;
                                      plVar9[7] = (longlong)plVar10;
                                      pcVar13 = (code *)FUN_23a388650(param_1,pcStack_148,uVar17,2);
                                      plVar10 = DAT_23ed6cd28;
                                      if (pcVar13 != (code *)0x0) {
                                        if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                          pcVar14 = pcVar20;
                                          pcVar21 = pcVar11;
                                          plVar12 = (longlong *)
                                                    PyDict_GetItemString(DAT_23ed6ccc0,"format");
                                          if (plVar12 == (longlong *)0x0) goto LAB_23e7bd24e;
                                          *plVar12 = *plVar12 + 1;
                                          DAT_23ed6a4c0 = plVar12;
                                        }
                                        plStack_70 = plVar10;
                                        pcStack_78 = pcVar13;
                                        lVar8 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_78);
                                        *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
                                        if (*(longlong *)pcVar13 == 0) {
                                          (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))();
                                        }
                                        if (lVar8 != 0) {
                                          plVar9[8] = lVar8;
                                          uVar17 = _DAT_23eed7d50;
                                          plVar10 = _DAT_23eed7d48;
                                          *_DAT_23eed7d48 = *_DAT_23eed7d48 + 1;
                                          plVar9[9] = (longlong)plVar10;
                                          pcVar13 = (code *)FUN_23a388650(param_1,pcStack_148,uVar17
                                                                         );
                                          plVar10 = DAT_23ed6cd28;
                                          if (pcVar13 != (code *)0x0) {
                                            if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                              pcVar14 = pcVar20;
                                              pcVar21 = pcVar11;
                                              plVar12 = (longlong *)
                                                        PyDict_GetItemString(DAT_23ed6ccc0,"format")
                                              ;
                                              if (plVar12 == (longlong *)0x0) goto LAB_23e7bd24e;
                                              *plVar12 = *plVar12 + 1;
                                              DAT_23ed6a4c0 = plVar12;
                                            }
                                            plStack_70 = plVar10;
                                            pcStack_78 = pcVar13;
                                            lVar8 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_78)
                                            ;
                                            *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
                                            if (*(longlong *)pcVar13 == 0) {
                                              FUN_23a334bc0();
                                            }
                                            if (lVar8 != 0) {
                                              plVar9[10] = lVar8;
                                              plVar10 = (longlong *)PyUnicode_Join();
                                              *plVar9 = *plVar9 + -1;
                                              if (*plVar9 == 0) {
                                                FUN_23a334bc0();
                                              }
                                              pcVar13 = (code *)0x0;
                                              if (plVar10 == (longlong *)0x0) goto LAB_23e7bd261;
                                              *(undefined4 *)(plVar2 + 5) = 0x111;
                                              plVar9 = (longlong *)
                                                       FUN_23e914090(param_1,uVar6,plVar10);
                                              *plVar10 = *plVar10 + -1;
                                              if (*plVar10 == 0) {
                                                FUN_23a334bc0();
                                              }
                                              if (plVar9 == (longlong *)0x0) {
                                                auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                                                plStack_90 = *(longlong **)(param_1 + 0x68);
                                                plStack_88 = *(longlong **)(param_1 + 0x70);
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                if (plStack_88 != (longlong *)0x0) {
                                                  if (plVar2 == (longlong *)plStack_88[3])
                                                  goto LAB_23e7bc7b6;
                                                  plVar9 = (longlong *)0x0;
                                                  pcVar13 = (code *)0x0;
                                                  plStack_150 = (longlong *)0x0;
                                                  uVar22 = 0x111;
                                                  plStack_160 = (longlong *)0x0;
                                                  plStack_d8 = (longlong *)0x0;
                                                  plStack_158 = (longlong *)0x0;
                                                  plStack_198 = (longlong *)0x0;
                                                  plStack_190 = (longlong *)0x0;
                                                  plStack_188 = (longlong *)0x0;
                                                  plStack_180 = (longlong *)0x0;
                                                  plStack_170 = (longlong *)0x0;
                                                  plStack_168 = (longlong *)0x0;
                                                  plStack_178 = (longlong *)0x0;
                                                  plStack_128 = (longlong *)0x0;
                                                  goto LAB_23e7b9b10;
                                                }
                                                goto LAB_23e7bc9dc;
                                              }
                                              lVar8 = *plVar9;
                                              *plVar9 = lVar8 + -1;
                                              if (lVar8 + -1 == 0) {
                                                FUN_23a334bc0();
                                              }
                                              uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                                              plVar9 = _DAT_23eed7d58;
                                              plVar10 = (longlong *)
                                                        FUN_23e916ad0(*(undefined8 *)
                                                                       (param_1 + 0x10),9);
                                              *plVar9 = *plVar9 + 1;
                                              plVar10[3] = (longlong)plVar9;
                                              plVar9 = (longlong *)
                                                       FUN_23a388650(param_1,plStack_138);
                                              if (plVar9 == (longlong *)0x0) {
LAB_23e7bd036:
                                                auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                                                plStack_90 = *(longlong **)(param_1 + 0x68);
                                                plStack_88 = *(longlong **)(param_1 + 0x70);
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                *plVar10 = *plVar10 + -1;
                                                if (*plVar10 == 0) {
                                                  FUN_23a334bc0();
                                                  if (plStack_88 != (longlong *)0x0) {
                                                    plVar9 = (longlong *)plStack_88[3];
joined_r0x00023e7bc7b0:
                                                    if (plVar2 != plVar9) {
                                                      plVar9 = (longlong *)0x0;
                                                      plStack_150 = (longlong *)0x0;
                                                      plStack_d8 = (longlong *)0x0;
                                                      pcVar13 = (code *)0x0;
                                                      uVar22 = 0x112;
                                                      plStack_160 = (longlong *)0x0;
                                                      plStack_158 = (longlong *)0x0;
                                                      plStack_198 = (longlong *)0x0;
                                                      plStack_190 = (longlong *)0x0;
                                                      plStack_188 = (longlong *)0x0;
                                                      plStack_180 = (longlong *)0x0;
                                                      plStack_170 = (longlong *)0x0;
                                                      plStack_168 = (longlong *)0x0;
                                                      plStack_178 = (longlong *)0x0;
                                                      plStack_128 = (longlong *)0x0;
                                                      goto LAB_23e7b9b10;
                                                    }
                                                    goto LAB_23e7bc7b6;
                                                  }
                                                }
                                                else if (plStack_88 != (longlong *)0x0) {
                                                  plVar9 = (longlong *)plStack_88[3];
                                                  goto joined_r0x00023e7bc7b0;
                                                }
                                              }
                                              else {
                                                lVar8 = FUN_23e94f9d0(param_1,plVar9);
                                                *plVar9 = *plVar9 + -1;
                                                if (*plVar9 == 0) {
                                                  FUN_23a334bc0();
                                                }
                                                plVar9 = _DAT_23eed7d30;
                                                if (lVar8 == 0) goto LAB_23e7bd036;
                                                plVar10[4] = lVar8;
                                                *plVar9 = *plVar9 + 1;
                                                plVar10[5] = (longlong)plVar9;
                                                plVar9 = (longlong *)
                                                         FUN_23a388650(param_1,plStack_138);
                                                if (plVar9 == (longlong *)0x0) goto LAB_23e7bd036;
                                                lVar8 = FUN_23e94f9d0(param_1,plVar9);
                                                *plVar9 = *plVar9 + -1;
                                                if (*plVar9 == 0) {
                                                  FUN_23a334bc0();
                                                }
                                                plVar9 = _DAT_23eed7d38;
                                                if (lVar8 == 0) goto LAB_23e7bd036;
                                                plVar10[6] = lVar8;
                                                *plVar9 = *plVar9 + 1;
                                                plVar10[7] = (longlong)plVar9;
                                                plVar9 = (longlong *)
                                                         FUN_23a388650(param_1,plStack_138);
                                                if (plVar9 == (longlong *)0x0) goto LAB_23e7bd036;
                                                lVar8 = FUN_23e94f9d0(param_1,plVar9);
                                                *plVar9 = *plVar9 + -1;
                                                if (*plVar9 == 0) {
                                                  FUN_23a334bc0();
                                                }
                                                plVar9 = _DAT_23eed7d48;
                                                if (lVar8 == 0) goto LAB_23e7bd036;
                                                plVar10[8] = lVar8;
                                                *plVar9 = *plVar9 + 1;
                                                plVar10[9] = (longlong)plVar9;
                                                plVar9 = (longlong *)
                                                         FUN_23a388650(param_1,plStack_138);
                                                if (plVar9 == (longlong *)0x0) goto LAB_23e7bd036;
                                                lVar8 = FUN_23e94f9d0(param_1,plVar9);
                                                *plVar9 = *plVar9 + -1;
                                                if (*plVar9 == 0) {
                                                  FUN_23a334bc0();
                                                }
                                                plVar9 = _DAT_23eed7d60;
                                                if (lVar8 == 0) goto LAB_23e7bd036;
                                                plVar10[10] = lVar8;
                                                *plVar9 = *plVar9 + 1;
                                                plVar10[0xb] = (longlong)plVar9;
                                                plVar9 = (longlong *)PyUnicode_Join();
                                                *plVar10 = *plVar10 + -1;
                                                if (*plVar10 == 0) {
                                                  FUN_23a334bc0();
                                                }
                                                if (plVar9 == (longlong *)0x0) {
                                                  auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  plStack_90 = *(longlong **)(param_1 + 0x68);
                                                  plStack_88 = *(longlong **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  if (plStack_88 != (longlong *)0x0) {
                                                    if ((longlong *)plStack_88[3] != plVar2) {
                                                      plVar9 = (longlong *)0x0;
                                                      plStack_158 = (longlong *)0x0;
                                                      plStack_d8 = (longlong *)0x0;
                                                      plStack_198 = (longlong *)0x0;
                                                      plStack_190 = (longlong *)0x0;
                                                      plStack_188 = (longlong *)0x0;
                                                      plStack_180 = (longlong *)0x0;
                                                      plStack_170 = (longlong *)0x0;
                                                      plStack_168 = (longlong *)0x0;
                                                      plStack_178 = (longlong *)0x0;
                                                      uVar22 = 0x112;
                                                      plStack_150 = (longlong *)0x0;
                                                      plStack_160 = (longlong *)0x0;
                                                      plStack_128 = (longlong *)0x0;
                                                      pcVar13 = (code *)0x0;
                                                      goto LAB_23e7b9b10;
                                                    }
                                                    goto LAB_23e7bc7b6;
                                                  }
                                                }
                                                else {
                                                  *(undefined4 *)(plVar2 + 5) = 0x112;
                                                  plVar10 = (longlong *)
                                                            FUN_23e914090(param_1,uVar6,plVar9);
                                                  *plVar9 = *plVar9 + -1;
                                                  if (*plVar9 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  if (plVar10 != (longlong *)0x0) {
                                                    lVar8 = *plVar10;
                                                    *plVar10 = lVar8 + -1;
                                                    if (lVar8 + -1 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    lVar8 = *(longlong *)(_DAT_23eed7948 + 0x20);
                                                    if (*(char *)(lVar8 + 10) == '\0') {
                                                      plVar9 = (longlong *)
                                                               FUN_23a37a020(_DAT_23eed7948,
                                                                             _DAT_23eed7d68);
                                                      if (plVar9 == (longlong *)0x0)
                                                      goto LAB_23e7bd46d;
                                                      lVar8 = *plVar9;
LAB_23e7bd464:
                                                      if (lVar8 == 0) goto LAB_23e7bd46d;
LAB_23e7b87bf:
                                                      *(undefined4 *)(plVar2 + 5) = 0x115;
                                                      pcStack_78 = pcStack_148;
                                                      plStack_70 = plStack_138;
                                                      plStack_68 = plStack_130;
                                                      plStack_128 = (longlong *)FUN_23e956150();
                                                      if (plStack_128 != (longlong *)0x0) {
                                                        uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                        *(undefined4 *)(plVar2 + 5) = 0x117;
                                                        plVar9 = (longlong *)
                                                                 FUN_23e94bb80(param_1,uVar6);
                                                        if (plVar9 == (longlong *)0x0) {
                                                          auStack_98 = *(undefined1 (*) [8])
                                                                        (param_1 + 0x60);
                                                          plStack_90 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                          plStack_88 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          if (plStack_88 == (longlong *)0x0) {
                                                            plVar9 = (longlong *)0x0;
                                                            uVar22 = 0x117;
                                                            plStack_150 = (longlong *)0x0;
                                                            plStack_160 = (longlong *)0x0;
                                                            plStack_158 = (longlong *)0x0;
                                                            plStack_198 = (longlong *)0x0;
                                                            plStack_190 = (longlong *)0x0;
                                                            plStack_188 = (longlong *)0x0;
                                                            plStack_180 = (longlong *)0x0;
                                                            plStack_170 = (longlong *)0x0;
                                                            plStack_168 = (longlong *)0x0;
                                                            plStack_178 = (longlong *)0x0;
                                                            plStack_d8 = (longlong *)0x0;
                                                            pcVar13 = (code *)0x0;
                                                            goto LAB_23e7baa40;
                                                          }
                                                          if ((longlong *)plStack_88[3] != plVar2) {
                                                            plVar9 = (longlong *)0x0;
                                                            plStack_158 = (longlong *)0x0;
                                                            uVar22 = 0x117;
                                                            plStack_198 = (longlong *)0x0;
                                                            plStack_190 = (longlong *)0x0;
                                                            plStack_188 = (longlong *)0x0;
                                                            plStack_180 = (longlong *)0x0;
                                                            plStack_170 = (longlong *)0x0;
                                                            plStack_168 = (longlong *)0x0;
                                                            plStack_178 = (longlong *)0x0;
                                                            pcVar13 = (code *)0x0;
                                                            plStack_150 = (longlong *)0x0;
                                                            plStack_160 = (longlong *)0x0;
                                                            plStack_d8 = (longlong *)0x0;
                                                            goto LAB_23e7b9b10;
                                                          }
LAB_23e7be815:
                                                          plVar9 = (longlong *)0x0;
                                                          plStack_d8 = (longlong *)0x0;
                                                          plStack_150 = (longlong *)0x0;
                                                          pcVar13 = (code *)0x0;
                                                          plStack_160 = (longlong *)0x0;
                                                          plStack_158 = (longlong *)0x0;
                                                          plStack_198 = (longlong *)0x0;
                                                          plStack_190 = (longlong *)0x0;
                                                          plStack_188 = (longlong *)0x0;
                                                          plStack_180 = (longlong *)0x0;
                                                          plStack_170 = (longlong *)0x0;
                                                          plStack_168 = (longlong *)0x0;
                                                          plStack_178 = (longlong *)0x0;
                                                          plVar10 = plStack_88;
                                                          goto LAB_23e7b9bc3;
                                                        }
                                                        *plVar9 = *plVar9 + -1;
                                                        if (*plVar9 == 0) {
                                                          FUN_23a334bc0(plVar9);
                                                        }
                                                        uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                        *(undefined4 *)(plVar2 + 5) = 0x118;
                                                        plVar9 = (longlong *)
                                                                 FUN_23e94bb80(param_1,uVar6,
                                                                               _DAT_23eed7d78);
                                                        if (plVar9 == (longlong *)0x0) {
                                                          auStack_98 = *(undefined1 (*) [8])
                                                                        (param_1 + 0x60);
                                                          plStack_90 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                          plStack_88 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          if (plStack_88 != (longlong *)0x0) {
                                                            if ((longlong *)plStack_88[3] == plVar2)
                                                            goto LAB_23e7be815;
                                                            uVar22 = 0x118;
                                                            plStack_150 = (longlong *)0x0;
                                                            pcVar13 = (code *)0x0;
                                                            plStack_160 = (longlong *)0x0;
                                                            plVar9 = (longlong *)0x0;
                                                            plStack_158 = (longlong *)0x0;
                                                            plStack_198 = (longlong *)0x0;
                                                            plStack_190 = (longlong *)0x0;
                                                            plStack_188 = (longlong *)0x0;
                                                            plStack_180 = (longlong *)0x0;
                                                            plStack_170 = (longlong *)0x0;
                                                            plStack_168 = (longlong *)0x0;
                                                            plStack_178 = (longlong *)0x0;
                                                            plStack_d8 = (longlong *)0x0;
                                                            goto LAB_23e7b9b10;
                                                          }
                                                          plVar9 = (longlong *)0x0;
                                                          uVar22 = 0x118;
                                                          plStack_150 = (longlong *)0x0;
                                                          plStack_160 = (longlong *)0x0;
                                                          plStack_158 = (longlong *)0x0;
                                                          plStack_198 = (longlong *)0x0;
                                                          plStack_190 = (longlong *)0x0;
                                                          plStack_188 = (longlong *)0x0;
                                                          plStack_180 = (longlong *)0x0;
                                                          plStack_170 = (longlong *)0x0;
                                                          plStack_168 = (longlong *)0x0;
                                                          plStack_178 = (longlong *)0x0;
                                                          plStack_d8 = (longlong *)0x0;
                                                          pcVar13 = (code *)0x0;
                                                        }
                                                        else {
                                                          *plVar9 = *plVar9 + -1;
                                                          if (*plVar9 == 0) {
                                                            FUN_23a334bc0(plVar9);
                                                          }
                                                          uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                          *(undefined4 *)(plVar2 + 5) = 0x119;
                                                          plVar9 = (longlong *)
                                                                   FUN_23e94bb80(param_1,uVar6,
                                                                                 _DAT_23eed7d70);
                                                          if (plVar9 == (longlong *)0x0) {
                                                            auStack_98 = *(undefined1 (*) [8])
                                                                          (param_1 + 0x60);
                                                            plStack_90 = *(longlong **)
                                                                          (param_1 + 0x68);
                                                            plStack_88 = *(longlong **)
                                                                          (param_1 + 0x70);
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            if (plStack_88 != (longlong *)0x0) {
                                                              if ((longlong *)plStack_88[3] ==
                                                                  plVar2) goto LAB_23e7be815;
                                                              plVar9 = (longlong *)0x0;
                                                              pcVar13 = (code *)0x0;
                                                              plStack_150 = (longlong *)0x0;
                                                              uVar22 = 0x119;
                                                              plStack_160 = (longlong *)0x0;
                                                              plStack_158 = (longlong *)0x0;
                                                              plStack_198 = (longlong *)0x0;
                                                              plStack_190 = (longlong *)0x0;
                                                              plStack_188 = (longlong *)0x0;
                                                              plStack_180 = (longlong *)0x0;
                                                              plStack_170 = (longlong *)0x0;
                                                              plStack_168 = (longlong *)0x0;
                                                              plStack_178 = (longlong *)0x0;
                                                              plStack_d8 = (longlong *)0x0;
                                                              goto LAB_23e7b9b10;
                                                            }
                                                            plVar9 = (longlong *)0x0;
                                                            uVar22 = 0x119;
                                                            plStack_150 = (longlong *)0x0;
                                                            plStack_160 = (longlong *)0x0;
                                                            plStack_158 = (longlong *)0x0;
                                                            plStack_198 = (longlong *)0x0;
                                                            plStack_190 = (longlong *)0x0;
                                                            plStack_188 = (longlong *)0x0;
                                                            plStack_180 = (longlong *)0x0;
                                                            plStack_170 = (longlong *)0x0;
                                                            plStack_168 = (longlong *)0x0;
                                                            plStack_178 = (longlong *)0x0;
                                                            plStack_d8 = (longlong *)0x0;
                                                            pcVar13 = (code *)0x0;
                                                          }
                                                          else {
                                                            *plVar9 = *plVar9 + -1;
                                                            if (*plVar9 == 0) {
                                                              FUN_23a334bc0(plVar9);
                                                            }
                                                            uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                            *(undefined4 *)(plVar2 + 5) = 0x11a;
                                                            plVar9 = (longlong *)
                                                                     FUN_23e94bb80(param_1,uVar6,
                                                                                   _DAT_23eed7d80);
                                                            if (plVar9 == (longlong *)0x0) {
                                                              auStack_98 = *(undefined1 (*) [8])
                                                                            (param_1 + 0x60);
                                                              plStack_90 = *(longlong **)
                                                                            (param_1 + 0x68);
                                                              plStack_88 = *(longlong **)
                                                                            (param_1 + 0x70);
                                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                                              *(undefined1 (*) [16])(param_1 + 0x60)
                                                                   = (undefined1  [16])0x0;
                                                              if (plStack_88 != (longlong *)0x0) {
                                                                if ((longlong *)plStack_88[3] ==
                                                                    plVar2) goto LAB_23e7be815;
                                                                plVar9 = (longlong *)0x0;
                                                                pcVar13 = (code *)0x0;
                                                                plStack_150 = (longlong *)0x0;
                                                                uVar22 = 0x11a;
                                                                plStack_160 = (longlong *)0x0;
                                                                plStack_158 = (longlong *)0x0;
                                                                plStack_198 = (longlong *)0x0;
                                                                plStack_190 = (longlong *)0x0;
                                                                plStack_188 = (longlong *)0x0;
                                                                plStack_180 = (longlong *)0x0;
                                                                plStack_170 = (longlong *)0x0;
                                                                plStack_168 = (longlong *)0x0;
                                                                plStack_178 = (longlong *)0x0;
                                                                plStack_d8 = (longlong *)0x0;
                                                                goto LAB_23e7b9b10;
                                                              }
                                                              plVar9 = (longlong *)0x0;
                                                              uVar22 = 0x11a;
                                                              plStack_150 = (longlong *)0x0;
                                                              plStack_160 = (longlong *)0x0;
                                                              plStack_158 = (longlong *)0x0;
                                                              plStack_198 = (longlong *)0x0;
                                                              plStack_190 = (longlong *)0x0;
                                                              plStack_188 = (longlong *)0x0;
                                                              plStack_180 = (longlong *)0x0;
                                                              plStack_170 = (longlong *)0x0;
                                                              plStack_168 = (longlong *)0x0;
                                                              plStack_178 = (longlong *)0x0;
                                                              plStack_d8 = (longlong *)0x0;
                                                              pcVar13 = (code *)0x0;
                                                            }
                                                            else {
                                                              *plVar9 = *plVar9 + -1;
                                                              if (*plVar9 == 0) {
                                                                FUN_23a334bc0(plVar9);
                                                              }
                                                              uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                              plVar9 = _DAT_23eed7d88;
                                                              plVar10 = (longlong *)
                                                                        FUN_23e916ad0(*(undefined8 *
                                                                                       )(param_1 +
                                                                                        0x10),3);
                                                              *plVar9 = *plVar9 + 1;
                                                              plVar10[3] = (longlong)plVar9;
                                                              lVar8 = FUN_23e8dec60();
                                                              if (lVar8 == 0) {
                                                                FUN_23e915740(param_1,auStack_98,
                                                                              _DAT_23eed7be8);
LAB_23e7bf943:
                                                                *plVar10 = *plVar10 + -1;
                                                                if (*plVar10 == 0) {
                                                                  FUN_23a334bc0();
                                                                }
                                                                if (plStack_88 != (longlong *)0x0) {
                                                                  if ((longlong *)plStack_88[3] !=
                                                                      plVar2) {
                                                                    plStack_d8 = (longlong *)0x0;
                                                                    pcVar13 = (code *)0x0;
                                                                    plStack_150 = (longlong *)0x0;
                                                                    uVar22 = 0x11b;
                                                                    plStack_160 = (longlong *)0x0;
                                                                    plVar9 = (longlong *)0x0;
                                                                    plStack_158 = (longlong *)0x0;
                                                                    plStack_198 = (longlong *)0x0;
                                                                    plStack_190 = (longlong *)0x0;
                                                                    plStack_188 = (longlong *)0x0;
                                                                    plStack_180 = (longlong *)0x0;
                                                                    plStack_170 = (longlong *)0x0;
                                                                    plStack_168 = (longlong *)0x0;
                                                                    plStack_178 = (longlong *)0x0;
                                                                    goto LAB_23e7b9b10;
                                                                  }
                                                                  goto LAB_23e7be815;
                                                                }
                                                              }
                                                              else {
                                                                lVar8 = FUN_23e94f9d0(param_1,lVar8,
                                                                                      DAT_23ed6cd28)
                                                                ;
                                                                if (lVar8 == 0) {
                                                                  plStack_88 = *(longlong **)
                                                                                (param_1 + 0x70);
                                                                  auStack_98 = *(undefined1 (*) [8])
                                                                                (param_1 + 0x60);
                                                                  plStack_90 = *(longlong **)
                                                                                (param_1 + 0x68);
                                                                  *(undefined8 *)(param_1 + 0x70) =
                                                                       0;
                                                                  *(undefined1 (*) [16])
                                                                   (param_1 + 0x60) =
                                                                       (undefined1  [16])0x0;
                                                                  goto LAB_23e7bf943;
                                                                }
                                                                plVar10[4] = lVar8;
                                                                plVar9 = _DAT_23eed7d90;
                                                                *_DAT_23eed7d90 =
                                                                     *_DAT_23eed7d90 + 1;
                                                                plVar10[5] = (longlong)plVar9;
                                                                plVar9 = (longlong *)
                                                                         PyUnicode_Join();
                                                                *plVar10 = *plVar10 + -1;
                                                                if (*plVar10 == 0) {
                                                                  FUN_23a334bc0();
                                                                }
                                                                if (plVar9 != (longlong *)0x0) {
                                                                  *(undefined4 *)(plVar2 + 5) =
                                                                       0x11b;
                                                                  plVar10 = (longlong *)
                                                                            FUN_23e914090(param_1,
                                                  uVar6,plVar9);
                                                  *plVar9 = *plVar9 + -1;
                                                  if (*plVar9 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  if (plVar10 == (longlong *)0x0) {
                                                    auStack_98 = *(undefined1 (*) [8])
                                                                  (param_1 + 0x60);
                                                    plStack_90 = *(longlong **)(param_1 + 0x68);
                                                    plStack_88 = *(longlong **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    if (plStack_88 == (longlong *)0x0)
                                                    goto LAB_23e7bf815;
                                                    if ((longlong *)plStack_88[3] == plVar2)
                                                    goto LAB_23e7be815;
                                                    plVar9 = (longlong *)0x0;
                                                    plStack_d8 = (longlong *)0x0;
                                                    uVar22 = 0x11b;
                                                    plStack_150 = (longlong *)0x0;
                                                    plStack_160 = (longlong *)0x0;
                                                    plStack_158 = (longlong *)0x0;
                                                    plStack_198 = (longlong *)0x0;
                                                    plStack_190 = (longlong *)0x0;
                                                    plStack_188 = (longlong *)0x0;
                                                    plStack_180 = (longlong *)0x0;
                                                    plStack_170 = (longlong *)0x0;
                                                    plStack_168 = (longlong *)0x0;
                                                    plStack_178 = (longlong *)0x0;
                                                    pcVar13 = (code *)0x0;
                                                    goto LAB_23e7b9b10;
                                                  }
                                                  *plVar10 = *plVar10 + -1;
                                                  if (*plVar10 == 0) {
                                                    FUN_23a334bc0(plVar10);
                                                  }
                                                  uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                  plVar9 = _DAT_23eed7d98;
                                                  plVar10 = (longlong *)
                                                            FUN_23e916ad0(*(undefined8 *)
                                                                           (param_1 + 0x10),3);
                                                  *plVar9 = *plVar9 + 1;
                                                  plVar10[3] = (longlong)plVar9;
                                                  lVar8 = FUN_23e8dec60();
                                                  if (lVar8 == 0) {
                                                    FUN_23e915740(param_1,auStack_98);
LAB_23e7bf67d:
                                                    *plVar10 = *plVar10 + -1;
                                                    if (*plVar10 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    if (plStack_88 != (longlong *)0x0) {
                                                      if ((longlong *)plStack_88[3] != plVar2) {
                                                        plVar9 = (longlong *)0x0;
                                                        plStack_d8 = (longlong *)0x0;
                                                        plStack_150 = (longlong *)0x0;
                                                        pcVar13 = (code *)0x0;
                                                        uVar22 = 0x11c;
                                                        plStack_160 = (longlong *)0x0;
                                                        plStack_158 = (longlong *)0x0;
                                                        plStack_198 = (longlong *)0x0;
                                                        plStack_190 = (longlong *)0x0;
                                                        plStack_188 = (longlong *)0x0;
                                                        plStack_180 = (longlong *)0x0;
                                                        plStack_170 = (longlong *)0x0;
                                                        plStack_168 = (longlong *)0x0;
                                                        plStack_178 = (longlong *)0x0;
                                                        goto LAB_23e7b9b10;
                                                      }
                                                      goto LAB_23e7be815;
                                                    }
                                                  }
                                                  else {
                                                    lVar8 = FUN_23e94f9d0(param_1,lVar8);
                                                    if (lVar8 == 0) {
                                                      plStack_88 = *(longlong **)(param_1 + 0x70);
                                                      auStack_98 = *(undefined1 (*) [8])
                                                                    (param_1 + 0x60);
                                                      plStack_90 = *(longlong **)(param_1 + 0x68);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      goto LAB_23e7bf67d;
                                                    }
                                                    plVar10[4] = lVar8;
                                                    plVar9 = _DAT_23eed7d90;
                                                    *_DAT_23eed7d90 = *_DAT_23eed7d90 + 1;
                                                    plVar10[5] = (longlong)plVar9;
                                                    plVar9 = (longlong *)
                                                             PyUnicode_Join(DAT_23ed6cd28,plVar10);
                                                    *plVar10 = *plVar10 + -1;
                                                    if (*plVar10 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    if (plVar9 != (longlong *)0x0) {
                                                      *(undefined4 *)(plVar2 + 5) = 0x11c;
                                                      plVar10 = (longlong *)
                                                                FUN_23e914090(param_1,uVar6,plVar9);
                                                      *plVar9 = *plVar9 + -1;
                                                      if (*plVar9 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      if (plVar10 != (longlong *)0x0) {
                                                        *plVar10 = *plVar10 + -1;
                                                        if (*plVar10 == 0) {
                                                          FUN_23a334bc0(plVar10);
                                                        }
                                                        uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                        *(undefined4 *)(plVar2 + 5) = 0x11d;
                                                        plVar9 = (longlong *)
                                                                 FUN_23e94bb80(param_1,uVar6,
                                                                               _DAT_23eed7da0);
                                                        if (plVar9 == (longlong *)0x0) {
                                                          auStack_98 = *(undefined1 (*) [8])
                                                                        (param_1 + 0x60);
                                                          plStack_90 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                          plStack_88 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          if (plStack_88 != (longlong *)0x0) {
                                                            if ((longlong *)plStack_88[3] == plVar2)
                                                            goto LAB_23e7be815;
                                                            plVar9 = (longlong *)0x0;
                                                            plStack_158 = (longlong *)0x0;
                                                            uVar22 = 0x11d;
                                                            plStack_198 = (longlong *)0x0;
                                                            plStack_190 = (longlong *)0x0;
                                                            plStack_188 = (longlong *)0x0;
                                                            plStack_180 = (longlong *)0x0;
                                                            plStack_170 = (longlong *)0x0;
                                                            plStack_168 = (longlong *)0x0;
                                                            plStack_178 = (longlong *)0x0;
                                                            pcVar13 = (code *)0x0;
                                                            plStack_150 = (longlong *)0x0;
                                                            plStack_160 = (longlong *)0x0;
                                                            plStack_d8 = (longlong *)0x0;
                                                            goto LAB_23e7b9b10;
                                                          }
                                                          plVar9 = (longlong *)0x0;
                                                          plStack_158 = (longlong *)0x0;
                                                          plStack_198 = (longlong *)0x0;
                                                          plStack_190 = (longlong *)0x0;
                                                          plStack_188 = (longlong *)0x0;
                                                          plStack_180 = (longlong *)0x0;
                                                          plStack_170 = (longlong *)0x0;
                                                          plStack_168 = (longlong *)0x0;
                                                          plStack_178 = (longlong *)0x0;
                                                          uVar22 = 0x11d;
                                                          plStack_150 = (longlong *)0x0;
                                                          plStack_160 = (longlong *)0x0;
                                                          plStack_d8 = (longlong *)0x0;
                                                          pcVar13 = (code *)0x0;
                                                        }
                                                        else {
                                                          *plVar9 = *plVar9 + -1;
                                                          if (*plVar9 == 0) {
                                                            FUN_23a334bc0(plVar9);
                                                          }
                                                          uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                          *(undefined4 *)(plVar2 + 5) = 0x11e;
                                                          plVar9 = (longlong *)
                                                                   FUN_23e94bb80(param_1,uVar6);
                                                          if (plVar9 == (longlong *)0x0) {
                                                            auStack_98 = *(undefined1 (*) [8])
                                                                          (param_1 + 0x60);
                                                            plStack_90 = *(longlong **)
                                                                          (param_1 + 0x68);
                                                            plStack_88 = *(longlong **)
                                                                          (param_1 + 0x70);
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            if (plStack_88 != (longlong *)0x0) {
                                                              if ((longlong *)plStack_88[3] ==
                                                                  plVar2) goto LAB_23e7be815;
                                                              uVar22 = 0x11e;
                                                              plStack_150 = (longlong *)0x0;
                                                              pcVar13 = (code *)0x0;
                                                              plStack_160 = (longlong *)0x0;
                                                              plVar9 = (longlong *)0x0;
                                                              plStack_158 = (longlong *)0x0;
                                                              plStack_198 = (longlong *)0x0;
                                                              plStack_190 = (longlong *)0x0;
                                                              plStack_188 = (longlong *)0x0;
                                                              plStack_180 = (longlong *)0x0;
                                                              plStack_170 = (longlong *)0x0;
                                                              plStack_168 = (longlong *)0x0;
                                                              plStack_178 = (longlong *)0x0;
                                                              plStack_d8 = (longlong *)0x0;
                                                              goto LAB_23e7b9b10;
                                                            }
                                                            plVar9 = (longlong *)0x0;
                                                            uVar22 = 0x11e;
                                                            plStack_150 = (longlong *)0x0;
                                                            plStack_160 = (longlong *)0x0;
                                                            plStack_158 = (longlong *)0x0;
                                                            plStack_198 = (longlong *)0x0;
                                                            plStack_190 = (longlong *)0x0;
                                                            plStack_188 = (longlong *)0x0;
                                                            plStack_180 = (longlong *)0x0;
                                                            plStack_170 = (longlong *)0x0;
                                                            plStack_168 = (longlong *)0x0;
                                                            plStack_178 = (longlong *)0x0;
                                                            plStack_d8 = (longlong *)0x0;
                                                            pcVar13 = (code *)0x0;
                                                          }
                                                          else {
                                                            *plVar9 = *plVar9 + -1;
                                                            if (*plVar9 == 0) {
                                                              FUN_23a334bc0(plVar9);
                                                            }
                                                            uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                            *(undefined4 *)(plVar2 + 5) = 0x11f;
                                                            plVar9 = (longlong *)
                                                                     FUN_23e94bb80(param_1,uVar6,
                                                                                   _DAT_23eed7db0);
                                                            if (plVar9 == (longlong *)0x0) {
                                                              auStack_98 = *(undefined1 (*) [8])
                                                                            (param_1 + 0x60);
                                                              plStack_90 = *(longlong **)
                                                                            (param_1 + 0x68);
                                                              plStack_88 = *(longlong **)
                                                                            (param_1 + 0x70);
                                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                                              *(undefined1 (*) [16])(param_1 + 0x60)
                                                                   = (undefined1  [16])0x0;
                                                              if (plStack_88 != (longlong *)0x0) {
                                                                if ((longlong *)plStack_88[3] ==
                                                                    plVar2) goto LAB_23e7be815;
                                                                plVar9 = (longlong *)0x0;
                                                                pcVar13 = (code *)0x0;
                                                                plStack_150 = (longlong *)0x0;
                                                                uVar22 = 0x11f;
                                                                plStack_160 = (longlong *)0x0;
                                                                plStack_158 = (longlong *)0x0;
                                                                plStack_198 = (longlong *)0x0;
                                                                plStack_190 = (longlong *)0x0;
                                                                plStack_188 = (longlong *)0x0;
                                                                plStack_180 = (longlong *)0x0;
                                                                plStack_170 = (longlong *)0x0;
                                                                plStack_168 = (longlong *)0x0;
                                                                plStack_178 = (longlong *)0x0;
                                                                plStack_d8 = (longlong *)0x0;
                                                                goto LAB_23e7b9b10;
                                                              }
                                                              plVar9 = (longlong *)0x0;
                                                              uVar22 = 0x11f;
                                                              plStack_150 = (longlong *)0x0;
                                                              plStack_160 = (longlong *)0x0;
                                                              plStack_158 = (longlong *)0x0;
                                                              plStack_198 = (longlong *)0x0;
                                                              plStack_190 = (longlong *)0x0;
                                                              plStack_188 = (longlong *)0x0;
                                                              plStack_180 = (longlong *)0x0;
                                                              plStack_170 = (longlong *)0x0;
                                                              plStack_168 = (longlong *)0x0;
                                                              plStack_178 = (longlong *)0x0;
                                                              plStack_d8 = (longlong *)0x0;
                                                              pcVar13 = (code *)0x0;
                                                            }
                                                            else {
                                                              *plVar9 = *plVar9 + -1;
                                                              if (*plVar9 == 0) {
                                                                FUN_23a334bc0(plVar9);
                                                              }
                                                              uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                              *(undefined4 *)(plVar2 + 5) = 0x120;
                                                              plVar9 = (longlong *)
                                                                       FUN_23e94bb80(param_1,uVar6,
                                                                                     _DAT_23eed7db8)
                                                              ;
                                                              if (plVar9 == (longlong *)0x0) {
                                                                auStack_98 = *(undefined1 (*) [8])
                                                                              (param_1 + 0x60);
                                                                plStack_90 = *(longlong **)
                                                                              (param_1 + 0x68);
                                                                plStack_88 = *(longlong **)
                                                                              (param_1 + 0x70);
                                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                                *(undefined1 (*) [16])
                                                                 (param_1 + 0x60) =
                                                                     (undefined1  [16])0x0;
                                                                if (plStack_88 != (longlong *)0x0) {
                                                                  if ((longlong *)plStack_88[3] ==
                                                                      plVar2) goto LAB_23e7be815;
                                                                  plVar9 = (longlong *)0x0;
                                                                  pcVar13 = (code *)0x0;
                                                                  plStack_150 = (longlong *)0x0;
                                                                  uVar22 = 0x120;
                                                                  plStack_160 = (longlong *)0x0;
                                                                  plStack_158 = (longlong *)0x0;
                                                                  plStack_198 = (longlong *)0x0;
                                                                  plStack_190 = (longlong *)0x0;
                                                                  plStack_188 = (longlong *)0x0;
                                                                  plStack_180 = (longlong *)0x0;
                                                                  plStack_170 = (longlong *)0x0;
                                                                  plStack_168 = (longlong *)0x0;
                                                                  plStack_178 = (longlong *)0x0;
                                                                  plStack_d8 = (longlong *)0x0;
                                                                  goto LAB_23e7b9b10;
                                                                }
                                                                plVar9 = (longlong *)0x0;
                                                                uVar22 = 0x120;
                                                                plStack_150 = (longlong *)0x0;
                                                                plStack_160 = (longlong *)0x0;
                                                                plStack_158 = (longlong *)0x0;
                                                                plStack_198 = (longlong *)0x0;
                                                                plStack_190 = (longlong *)0x0;
                                                                plStack_188 = (longlong *)0x0;
                                                                plStack_180 = (longlong *)0x0;
                                                                plStack_170 = (longlong *)0x0;
                                                                plStack_168 = (longlong *)0x0;
                                                                plStack_178 = (longlong *)0x0;
                                                                plStack_d8 = (longlong *)0x0;
                                                                pcVar13 = (code *)0x0;
                                                              }
                                                              else {
                                                                *plVar9 = *plVar9 + -1;
                                                                if (*plVar9 == 0) {
                                                                  FUN_23a334bc0(plVar9);
                                                                }
                                                                uVar6 = FUN_23a3a0d40(DAT_23ed6cf28)
                                                                ;
                                                                *(undefined4 *)(plVar2 + 5) = 0x121;
                                                                plVar9 = (longlong *)
                                                                         FUN_23e94bb80(param_1,uVar6
                                                                                       ,
                                                  _DAT_23eed7cc8);
                                                  if (plVar9 == (longlong *)0x0) {
                                                    auStack_98 = *(undefined1 (*) [8])
                                                                  (param_1 + 0x60);
                                                    plStack_90 = *(longlong **)(param_1 + 0x68);
                                                    plStack_88 = *(longlong **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    if (plStack_88 != (longlong *)0x0) {
                                                      if ((longlong *)plStack_88[3] == plVar2)
                                                      goto LAB_23e7be815;
                                                      plVar9 = (longlong *)0x0;
                                                      plStack_150 = (longlong *)0x0;
                                                      pcVar13 = (code *)0x0;
                                                      plStack_160 = (longlong *)0x0;
                                                      uVar22 = 0x121;
                                                      plStack_158 = (longlong *)0x0;
                                                      plStack_198 = (longlong *)0x0;
                                                      plStack_190 = (longlong *)0x0;
                                                      plStack_188 = (longlong *)0x0;
                                                      plStack_180 = (longlong *)0x0;
                                                      plStack_170 = (longlong *)0x0;
                                                      plStack_168 = (longlong *)0x0;
                                                      plStack_178 = (longlong *)0x0;
                                                      plStack_d8 = (longlong *)0x0;
                                                      goto LAB_23e7b9b10;
                                                    }
                                                    plVar9 = (longlong *)0x0;
                                                    uVar22 = 0x121;
                                                    plStack_150 = (longlong *)0x0;
                                                    plStack_160 = (longlong *)0x0;
                                                    plStack_158 = (longlong *)0x0;
                                                    plStack_198 = (longlong *)0x0;
                                                    plStack_190 = (longlong *)0x0;
                                                    plStack_188 = (longlong *)0x0;
                                                    plStack_180 = (longlong *)0x0;
                                                    plStack_170 = (longlong *)0x0;
                                                    plStack_168 = (longlong *)0x0;
                                                    plStack_178 = (longlong *)0x0;
                                                    plStack_d8 = (longlong *)0x0;
                                                    pcVar13 = (code *)0x0;
                                                  }
                                                  else {
                                                    *plVar9 = *plVar9 + -1;
                                                    if (*plVar9 == 0) {
                                                      FUN_23a334bc0(plVar9);
                                                    }
                                                    plStack_150 = (longlong *)0x0;
                                                    plVar9 = (longlong *)0x0;
                                                    plStack_160 = (longlong *)0x0;
                                                    plStack_e0 = (longlong *)0x0;
                                                    plStack_a0 = (longlong *)0x0;
                                                    plStack_a8 = (longlong *)0x0;
                                                    plStack_b0 = (longlong *)0x0;
                                                    plStack_b8 = (longlong *)0x0;
                                                    plStack_c0 = (longlong *)0x0;
                                                    plStack_c8 = (longlong *)0x0;
                                                    plStack_d0 = (longlong *)0x0;
                                                    plStack_d8 = (longlong *)0x0;
                                                    pcVar13 = (code *)0x0;
                                                    while( true ) {
                                                      uVar6 = _DAT_23eed7dc0;
                                                      *(undefined4 *)(plVar2 + 5) = 0x125;
                                                      pcVar14 = (code *)FUN_23e91bfe0(param_1,plVar7
                                                                                      ,uVar6);
                                                      if (pcVar14 == (code *)0x0) break;
                                                      if ((pcVar13 != (code *)0x0) &&
                                                         (*(longlong *)pcVar13 =
                                                               *(longlong *)pcVar13 + -1,
                                                         *(longlong *)pcVar13 == 0)) {
                                                        FUN_23a334bc0(pcVar13);
                                                      }
                                                      uVar6 = _DAT_23eed7df0;
                                                      uVar22 = (undefined4)
                                                               ((ulonglong)in_stack_fffffffffffffdb8
                                                               >> 0x20);
                                                      pcVar13 = pcVar14;
                                                      if (pcVar14 != _Py_NoneStruct_exref) {
                                                        *(undefined4 *)(plVar2 + 5) = 300;
                                                        plVar10 = (longlong *)
                                                                  FUN_23e915840(param_1,plStack_128,
                                                                                uVar6,pcVar14);
                                                        if (plVar10 == (longlong *)0x0) {
LAB_23e7beea4:
                                                          plStack_158 = *(longlong **)
                                                                         (param_1 + 0x70);
                                                          auVar23 = *(undefined1 (*) [8])
                                                                     (param_1 + 0x60);
                                                          plVar10 = *(longlong **)(param_1 + 0x68);
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          plStack_88 = (longlong *)0x0;
                                                          plStack_198 = (longlong *)0x0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          _auStack_98 = (undefined1  [16])0x0;
                                                        }
                                                        else {
                                                          plVar12 = (longlong *)FUN_23a388310();
                                                          *plVar10 = *plVar10 + -1;
                                                          if (*plVar10 == 0) {
                                                            FUN_23a334bc0();
                                                          }
                                                          if (plVar12 == (longlong *)0x0)
                                                          goto LAB_23e7beea4;
                                                          uVar6 = CONCAT44(uVar22,8);
                                                          plVar15 = (longlong *)
                                                                    FUN_23a3c1d30(param_1,auStack_98
                                                                                  ,plVar12,0,uVar6);
                                                          if (plVar15 == (longlong *)0x0) {
                                                            plStack_198 = (longlong *)0x0;
                                                            plStack_190 = (longlong *)0x0;
                                                            plStack_188 = (longlong *)0x0;
                                                            plStack_180 = (longlong *)0x0;
                                                            plStack_170 = (longlong *)0x0;
                                                            plStack_168 = (longlong *)0x0;
                                                            plStack_178 = (longlong *)0x0;
                                                            lVar8 = *plVar12;
                                                          }
                                                          else {
                                                            uVar6 = CONCAT44((int)((ulonglong)uVar6
                                                                                  >> 0x20),8);
                                                            plStack_178 = (longlong *)
                                                                          FUN_23a3c1d30(param_1,
                                                  auStack_98,plVar12,1,uVar6);
                                                  if (plStack_178 == (longlong *)0x0) {
                                                    plStack_198 = (longlong *)0x0;
                                                    plStack_190 = (longlong *)0x0;
                                                    plStack_188 = (longlong *)0x0;
                                                    plStack_180 = (longlong *)0x0;
                                                    plStack_170 = (longlong *)0x0;
                                                    plStack_168 = (longlong *)0x0;
                                                    lVar8 = *plVar12;
                                                  }
                                                  else {
                                                    uVar6 = CONCAT44((int)((ulonglong)uVar6 >> 0x20)
                                                                     ,8);
                                                    plStack_168 = (longlong *)
                                                                  FUN_23a3c1d30(param_1,auStack_98,
                                                                                plVar12,2,uVar6);
                                                    if (plStack_168 == (longlong *)0x0) {
                                                      plStack_198 = (longlong *)0x0;
                                                      plStack_190 = (longlong *)0x0;
                                                      plStack_188 = (longlong *)0x0;
                                                      plStack_180 = (longlong *)0x0;
                                                      plStack_170 = (longlong *)0x0;
                                                      lVar8 = *plVar12;
                                                    }
                                                    else {
                                                      uVar6 = CONCAT44((int)((ulonglong)uVar6 >>
                                                                            0x20),8);
                                                      plStack_170 = (longlong *)
                                                                    FUN_23a3c1d30(param_1,auStack_98
                                                                                  ,plVar12,3,uVar6);
                                                      if (plStack_170 == (longlong *)0x0) {
                                                        plStack_198 = (longlong *)0x0;
                                                        plStack_190 = (longlong *)0x0;
                                                        plStack_188 = (longlong *)0x0;
                                                        plStack_180 = (longlong *)0x0;
                                                        lVar8 = *plVar12;
                                                      }
                                                      else {
                                                        uVar6 = CONCAT44((int)((ulonglong)uVar6 >>
                                                                              0x20),8);
                                                        plStack_180 = (longlong *)
                                                                      FUN_23a3c1d30(param_1,
                                                  auStack_98,plVar12,4,uVar6);
                                                  if (plStack_180 == (longlong *)0x0) {
                                                    plStack_198 = (longlong *)0x0;
                                                    plStack_190 = (longlong *)0x0;
                                                    plStack_188 = (longlong *)0x0;
                                                    lVar8 = *plVar12;
                                                  }
                                                  else {
                                                    uVar6 = CONCAT44((int)((ulonglong)uVar6 >> 0x20)
                                                                     ,8);
                                                    plStack_188 = (longlong *)
                                                                  FUN_23a3c1d30(param_1,auStack_98,
                                                                                plVar12,5,uVar6);
                                                    if (plStack_188 == (longlong *)0x0) {
                                                      plStack_198 = (longlong *)0x0;
                                                      plStack_190 = (longlong *)0x0;
                                                      lVar8 = *plVar12;
                                                    }
                                                    else {
                                                      uVar6 = CONCAT44((int)((ulonglong)uVar6 >>
                                                                            0x20),8);
                                                      plStack_190 = (longlong *)
                                                                    FUN_23a3c1d30(param_1,auStack_98
                                                                                  ,plVar12,6,uVar6);
                                                      if (plStack_190 == (longlong *)0x0) {
                                                        plStack_198 = (longlong *)0x0;
                                                        lVar8 = *plVar12;
                                                      }
                                                      else {
                                                        in_stack_fffffffffffffdb8 =
                                                             CONCAT44((int)((ulonglong)uVar6 >> 0x20
                                                                           ),8);
                                                        plStack_198 = (longlong *)
                                                                      FUN_23a3c1d30(param_1,
                                                  auStack_98,plVar12,7,in_stack_fffffffffffffdb8);
                                                  if (plStack_198 == (longlong *)0x0) {
                                                    lVar8 = *plVar12;
                                                  }
                                                  else {
                                                    cVar4 = FUN_23a3884a0(param_1,auStack_98,plVar12
                                                                          ,8);
                                                    lVar8 = *plVar12;
                                                    if (cVar4 != '\0') {
                                                      *plVar12 = lVar8 + -1;
                                                      if (lVar8 + -1 == 0) {
                                                        FUN_23a334bc0(plVar12);
                                                      }
                                                      *plVar15 = *plVar15 + 1;
                                                      if ((plStack_d8 != (longlong *)0x0) &&
                                                         (lVar8 = *plStack_d8,
                                                         *plStack_d8 = lVar8 + -1, lVar8 + -1 == 0))
                                                      {
                                                        FUN_23a334bc0(plStack_d8);
                                                      }
                                                      *plVar15 = *plVar15 + -1;
                                                      if (*plVar15 == 0) {
                                                        FUN_23a334bc0(plVar15);
                                                      }
                                                      *plStack_178 = *plStack_178 + 1;
                                                      if ((plStack_d0 != (longlong *)0x0) &&
                                                         (lVar8 = *plStack_d0,
                                                         *plStack_d0 = lVar8 + -1, lVar8 + -1 == 0))
                                                      {
                                                        FUN_23a334bc0(plStack_d0);
                                                      }
                                                      lVar8 = *plStack_178;
                                                      *plStack_178 = lVar8 + -1;
                                                      if (lVar8 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_178);
                                                      }
                                                      *plStack_168 = *plStack_168 + 1;
                                                      if ((plStack_c8 != (longlong *)0x0) &&
                                                         (lVar8 = *plStack_c8,
                                                         *plStack_c8 = lVar8 + -1, lVar8 + -1 == 0))
                                                      {
                                                        FUN_23a334bc0(plStack_c8);
                                                      }
                                                      lVar8 = *plStack_168;
                                                      *plStack_168 = lVar8 + -1;
                                                      if (lVar8 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_168);
                                                      }
                                                      *plStack_170 = *plStack_170 + 1;
                                                      if ((plStack_c0 != (longlong *)0x0) &&
                                                         (lVar8 = *plStack_c0,
                                                         *plStack_c0 = lVar8 + -1, lVar8 + -1 == 0))
                                                      {
                                                        FUN_23a334bc0(plStack_c0);
                                                      }
                                                      lVar8 = *plStack_170;
                                                      *plStack_170 = lVar8 + -1;
                                                      if (lVar8 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_170);
                                                      }
                                                      *plStack_180 = *plStack_180 + 1;
                                                      if ((plStack_b8 != (longlong *)0x0) &&
                                                         (lVar8 = *plStack_b8,
                                                         *plStack_b8 = lVar8 + -1, lVar8 + -1 == 0))
                                                      {
                                                        FUN_23a334bc0(plStack_b8);
                                                      }
                                                      lVar8 = *plStack_180;
                                                      *plStack_180 = lVar8 + -1;
                                                      if (lVar8 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_180);
                                                      }
                                                      *plStack_188 = *plStack_188 + 1;
                                                      if ((plStack_b0 != (longlong *)0x0) &&
                                                         (lVar8 = *plStack_b0,
                                                         *plStack_b0 = lVar8 + -1, lVar8 + -1 == 0))
                                                      {
                                                        FUN_23a334bc0(plStack_b0);
                                                      }
                                                      lVar8 = *plStack_188;
                                                      *plStack_188 = lVar8 + -1;
                                                      if (lVar8 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_188);
                                                      }
                                                      *plStack_190 = *plStack_190 + 1;
                                                      if ((plStack_a8 != (longlong *)0x0) &&
                                                         (lVar8 = *plStack_a8,
                                                         *plStack_a8 = lVar8 + -1, lVar8 + -1 == 0))
                                                      {
                                                        FUN_23a334bc0(plStack_a8);
                                                      }
                                                      lVar8 = *plStack_190;
                                                      *plStack_190 = lVar8 + -1;
                                                      if (lVar8 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_190);
                                                      }
                                                      *plStack_198 = *plStack_198 + 1;
                                                      if ((plStack_a0 != (longlong *)0x0) &&
                                                         (lVar8 = *plStack_a0,
                                                         *plStack_a0 = lVar8 + -1, lVar8 + -1 == 0))
                                                      {
                                                        FUN_23a334bc0(plStack_a0);
                                                      }
                                                      lVar8 = *plStack_198;
                                                      *plStack_198 = lVar8 + -1;
                                                      if (lVar8 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_198);
                                                      }
                                                      lVar8 = FUN_23e8dedb0();
                                                      uVar6 = _DAT_23eed7df8;
                                                      plStack_d8 = plVar15;
                                                      if (lVar8 == 0) {
                                                        FUN_23e915740(param_1,auStack_98,
                                                                      _DAT_23eed7b38);
                                                      }
                                                      else {
                                                        *(undefined4 *)(plVar2 + 5) = 0x12e;
                                                        plStack_158 = (longlong *)
                                                                      FUN_23e915840(param_1,lVar8,
                                                                                    uVar6);
                                                        if (plStack_158 != (longlong *)0x0) {
                                                          if ((plStack_e0 != (longlong *)0x0) &&
                                                             (lVar8 = *plStack_e0,
                                                             *plStack_e0 = lVar8 + -1,
                                                             lVar8 + -1 == 0)) {
                                                            FUN_23a334bc0(plStack_e0);
                                                          }
                                                          iVar5 = FUN_23e97de20(plStack_198,
                                                                                DAT_23ed6ccf0);
                                                          plVar10 = _DAT_23eed7e08;
                                                          if (iVar5 == -1) {
                                                            auStack_98 = *(undefined1 (*) [8])
                                                                          (param_1 + 0x60);
                                                            plStack_88 = *(longlong **)
                                                                          (param_1 + 0x70);
                                                            uVar6 = 0x131;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            plStack_90 = *(longlong **)
                                                                          (param_1 + 0x68);
                                                          }
                                                          else if (iVar5 == 1) {
                                                            plVar12 = (longlong *)
                                                                      FUN_23e916ad0(*(undefined8 *)
                                                                                     (param_1 + 0x10
                                                                                     ),7);
                                                            *plVar10 = *plVar10 + 1;
                                                            plVar12[3] = (longlong)plVar10;
                                                            lVar8 = FUN_23e94f9d0(param_1,
                                                  plStack_158,DAT_23ed6cd28);
                                                  if (lVar8 == 0) {
LAB_23e7bfe48:
                                                    auStack_98 = *(undefined1 (*) [8])
                                                                  (param_1 + 0x60);
                                                    plStack_90 = *(longlong **)(param_1 + 0x68);
                                                    plStack_88 = *(longlong **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *plVar12 = *plVar12 + -1;
                                                    if (*plVar12 == 0) {
                                                      FUN_23a334bc0(plVar12);
                                                    }
                                                  }
                                                  else {
                                                    plVar12[4] = lVar8;
                                                    plVar10 = _DAT_23eed7e10;
                                                    *_DAT_23eed7e10 = *_DAT_23eed7e10 + 1;
                                                    plVar12[5] = (longlong)plVar10;
                                                    lVar8 = FUN_23e94f9d0(param_1,plStack_198,
                                                                          DAT_23ed6cd28);
                                                    if (lVar8 == 0) goto LAB_23e7bfe48;
                                                    plVar12[6] = lVar8;
                                                    plVar10 = _DAT_23eed7e18;
                                                    *_DAT_23eed7e18 = *_DAT_23eed7e18 + 1;
                                                    plVar12[7] = (longlong)plVar10;
                                                    lVar8 = FUN_23e94f9d0(param_1,plStack_190);
                                                    if (lVar8 == 0) goto LAB_23e7bfe48;
                                                    plVar12[8] = lVar8;
                                                    plVar10 = _DAT_23eed7e28;
                                                    *_DAT_23eed7e28 = *_DAT_23eed7e28 + 1;
                                                    plVar12[9] = (longlong)plVar10;
                                                    plVar10 = (longlong *)
                                                              PyUnicode_Join(DAT_23ed6cd28,plVar12);
                                                    *plVar12 = *plVar12 + -1;
                                                    if (*plVar12 == 0) {
                                                      FUN_23a334bc0(plVar12);
                                                    }
                                                    if (plVar10 != (longlong *)0x0) {
                                                      if ((plVar9 != (longlong *)0x0) &&
                                                         (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
                                                        FUN_23a334bc0(plVar9);
                                                      }
                                                      uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                      plVar9 = _DAT_23eed7e30;
                                                      plVar12 = (longlong *)
                                                                FUN_23e916ad0(*(undefined8 *)
                                                                               (param_1 + 0x10),2);
                                                      *plVar9 = *plVar9 + 1;
                                                      plVar12[3] = (longlong)plVar9;
                                                      *plVar10 = *plVar10 + 1;
                                                      plVar12[4] = (longlong)plVar10;
                                                      lVar8 = PyUnicode_Join(DAT_23ed6cd28,plVar12);
                                                      *plVar12 = *plVar12 + -1;
                                                      if (*plVar12 == 0) {
                                                        FUN_23a334bc0(plVar12);
                                                      }
                                                      if (lVar8 != 0) {
                                                        plVar9 = (longlong *)
                                                                 FUN_23e916ad0(*(undefined8 *)
                                                                                (param_1 + 0x10),1);
                                                        uVar17 = _DAT_23eed7e38;
                                                        plVar9[3] = lVar8;
                                                        plVar12 = (longlong *)
                                                                  FUN_23e8d7870(param_1,uVar17);
                                                        *(undefined4 *)(plVar2 + 5) = 0x133;
                                                        plVar15 = (longlong *)
                                                                  FUN_23a334c60(param_1,uVar6,plVar9
                                                                                ,plVar12);
                                                        *plVar9 = *plVar9 + -1;
                                                        if (*plVar9 == 0) {
                                                          FUN_23a334bc0(plVar9);
                                                        }
                                                        *plVar12 = *plVar12 + -1;
                                                        if (*plVar12 == 0) {
                                                          FUN_23a334bc0(plVar12);
                                                        }
                                                        if (plVar15 != (longlong *)0x0) {
                                                          *plVar15 = *plVar15 + -1;
                                                          if (*plVar15 == 0) {
                                                            FUN_23a334bc0(plVar15);
                                                          }
LAB_23e7b98d4:
                                                          cVar4 = FUN_23a3a5fe0(param_1);
                                                          plVar9 = plVar10;
                                                          if (cVar4 != '\0') goto LAB_23e7b98e4;
                                                          auStack_98 = *(undefined1 (*) [8])
                                                                        (param_1 + 0x60);
                                                          plStack_88 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          uVar6 = 0x124;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          plStack_90 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                          goto LAB_23e7bd8ee;
                                                        }
                                                      }
                                                      auStack_98 = *(undefined1 (*) [8])
                                                                    (param_1 + 0x60);
                                                      plStack_88 = *(longlong **)(param_1 + 0x70);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      uVar6 = 0x133;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      plVar9 = plVar10;
                                                      plStack_90 = *(longlong **)(param_1 + 0x68);
                                                      goto LAB_23e7bd8ee;
                                                    }
                                                    plStack_88 = *(longlong **)(param_1 + 0x70);
                                                    auStack_98 = *(undefined1 (*) [8])
                                                                  (param_1 + 0x60);
                                                    plStack_90 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  uVar6 = 0x132;
                                                  }
                                                  else {
                                                    iVar5 = FUN_23a35f020(plStack_168);
                                                    if (iVar5 == -1) {
                                                      auStack_98 = *(undefined1 (*) [8])
                                                                    (param_1 + 0x60);
                                                      plStack_88 = *(longlong **)(param_1 + 0x70);
                                                      uVar6 = 0x136;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      plStack_90 = *(longlong **)(param_1 + 0x68);
                                                    }
                                                    else {
                                                      plVar10 = DAT_23ed6cd28;
                                                      if (iVar5 != 0) {
                                                        plVar10 = _DAT_23eed7e40;
                                                      }
                                                      *plVar10 = *plVar10 + 1;
                                                      if ((plStack_160 != (longlong *)0x0) &&
                                                         (lVar8 = *plStack_160,
                                                         *plStack_160 = lVar8 + -1, lVar8 + -1 == 0)
                                                         ) {
                                                        FUN_23a334bc0(plStack_160);
                                                      }
                                                      iVar5 = FUN_23a35f020(plStack_170);
                                                      plStack_160 = plVar10;
                                                      if (iVar5 == -1) {
                                                        auStack_98 = *(undefined1 (*) [8])
                                                                      (param_1 + 0x60);
                                                        plStack_88 = *(longlong **)(param_1 + 0x70);
                                                        uVar6 = 0x137;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        plStack_90 = *(longlong **)(param_1 + 0x68);
                                                      }
                                                      else {
                                                        plVar12 = DAT_23ed6cd28;
                                                        if (iVar5 != 0) {
                                                          plVar12 = _DAT_23eed7e48;
                                                        }
                                                        *plVar12 = *plVar12 + 1;
                                                        if ((plStack_150 != (longlong *)0x0) &&
                                                           (lVar8 = *plStack_150,
                                                           *plStack_150 = lVar8 + -1,
                                                           lVar8 + -1 == 0)) {
                                                          FUN_23a334bc0(plStack_150);
                                                        }
                                                        iVar5 = FUN_23a35f020(plStack_180);
                                                        plVar3 = _DAT_23eed7e08;
                                                        plStack_150 = plVar12;
                                                        if (iVar5 == -1) {
                                                          auStack_98 = *(undefined1 (*) [8])
                                                                        (param_1 + 0x60);
                                                          plStack_88 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                          uVar6 = 0x139;
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          plStack_90 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                        }
                                                        else if (iVar5 == 0) {
                                                          plVar16 = (longlong *)
                                                                    FUN_23e916ad0(*(undefined8 *)
                                                                                   (param_1 + 0x10),
                                                                                  0xc);
                                                          *plVar3 = *plVar3 + 1;
                                                          plVar16[3] = (longlong)plVar3;
                                                          lVar8 = FUN_23e94f9d0(param_1,plStack_158)
                                                          ;
                                                          if (lVar8 == 0) {
LAB_23e7c03db:
                                                            auStack_98 = *(undefined1 (*) [8])
                                                                          (param_1 + 0x60);
                                                            plStack_90 = *(longlong **)
                                                                          (param_1 + 0x68);
                                                            plStack_88 = *(longlong **)
                                                                          (param_1 + 0x70);
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            *plVar16 = *plVar16 + -1;
                                                            if (*plVar16 == 0) {
                                                              FUN_23a334bc0(plVar16);
                                                            }
                                                          }
                                                          else {
                                                            plVar16[4] = lVar8;
                                                            plVar3 = _DAT_23eed7e50;
                                                            *_DAT_23eed7e50 = *_DAT_23eed7e50 + 1;
                                                            plVar16[5] = (longlong)plVar3;
                                                            lVar8 = FUN_23e94f9d0(param_1,plVar15);
                                                            if (lVar8 == 0) goto LAB_23e7c03db;
                                                            plVar16[6] = lVar8;
                                                            plVar15 = _DAT_23eed7e60;
                                                            *_DAT_23eed7e60 = *_DAT_23eed7e60 + 1;
                                                            plVar16[7] = (longlong)plVar15;
                                                            lVar8 = FUN_23e94f9d0(param_1,
                                                  plStack_178);
                                                  if (lVar8 == 0) goto LAB_23e7c03db;
                                                  plVar16[8] = lVar8;
                                                  plVar15 = _DAT_23eed7e68;
                                                  *_DAT_23eed7e68 = *_DAT_23eed7e68 + 1;
                                                  plVar16[9] = (longlong)plVar15;
                                                  plVar15 = _DAT_23eed7e70;
                                                  *plVar10 = *plVar10 + 1;
                                                  plVar16[10] = (longlong)plVar10;
                                                  *plVar12 = *plVar12 + 1;
                                                  plVar16[0xb] = (longlong)plVar12;
                                                  *plVar15 = *plVar15 + 1;
                                                  plVar16[0xc] = (longlong)plVar15;
                                                  lVar8 = FUN_23e94f9d0(param_1,plStack_190);
                                                  if (lVar8 == 0) goto LAB_23e7c03db;
                                                  plVar16[0xd] = lVar8;
                                                  plVar12 = _DAT_23eed7e88;
                                                  plVar10 = DAT_23ed6cd28;
                                                  *_DAT_23eed7e88 = *_DAT_23eed7e88 + 1;
                                                  plVar16[0xe] = (longlong)plVar12;
                                                  plVar10 = (longlong *)
                                                            PyUnicode_Join(plVar10,plVar16);
                                                  *plVar16 = *plVar16 + -1;
                                                  if (*plVar16 == 0) {
                                                    FUN_23a334bc0(plVar16);
                                                  }
                                                  if (plVar10 != (longlong *)0x0) {
                                                    if ((plVar9 != (longlong *)0x0) &&
                                                       (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
                                                      FUN_23a334bc0(plVar9);
                                                    }
                                                    uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                    plVar9 = _DAT_23eed7e30;
                                                    plVar12 = (longlong *)
                                                              FUN_23e916ad0(*(undefined8 *)
                                                                             (param_1 + 0x10),2);
                                                    *plVar9 = *plVar9 + 1;
                                                    plVar12[3] = (longlong)plVar9;
                                                    *plVar10 = *plVar10 + 1;
                                                    plVar12[4] = (longlong)plVar10;
                                                    lVar8 = PyUnicode_Join(DAT_23ed6cd28,plVar12);
                                                    *plVar12 = *plVar12 + -1;
                                                    if (*plVar12 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    if (lVar8 != 0) {
                                                      plVar12 = (longlong *)
                                                                FUN_23e916ad0(*(undefined8 *)
                                                                               (param_1 + 0x10),1);
                                                      uVar17 = _DAT_23eed7e38;
                                                      plVar12[3] = lVar8;
                                                      plVar15 = (longlong *)
                                                                FUN_23e8d7870(param_1,uVar17);
                                                      *(undefined4 *)(plVar2 + 5) = 0x13e;
                                                      plVar9 = (longlong *)
                                                               FUN_23a334c60(param_1,uVar6,plVar12,
                                                                             plVar15);
                                                      *plVar12 = *plVar12 + -1;
                                                      if (*plVar12 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      *plVar15 = *plVar15 + -1;
                                                      if (*plVar15 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      if (plVar9 != (longlong *)0x0) {
LAB_23e7b98c5:
                                                        *plVar9 = *plVar9 + -1;
                                                        if (*plVar9 == 0) {
                                                          FUN_23a334bc0(plVar9);
                                                        }
                                                        goto LAB_23e7b98d4;
                                                      }
                                                    }
                                                    auStack_98 = *(undefined1 (*) [8])
                                                                  (param_1 + 0x60);
                                                    plStack_88 = *(longlong **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    uVar6 = 0x13e;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plVar9 = plVar10;
                                                    plStack_90 = *(longlong **)(param_1 + 0x68);
                                                    goto LAB_23e7bd8ee;
                                                  }
                                                  plStack_88 = *(longlong **)(param_1 + 0x70);
                                                  auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  plStack_90 = *(longlong **)(param_1 + 0x68);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  }
                                                  uVar6 = 0x13d;
                                                  }
                                                  else {
                                                    plVar16 = (longlong *)
                                                              FUN_23e916ad0(*(undefined8 *)
                                                                             (param_1 + 0x10),0xe);
                                                    *plVar3 = *plVar3 + 1;
                                                    plVar16[3] = (longlong)plVar3;
                                                    lVar8 = FUN_23e94f9d0(param_1,plStack_158,
                                                                          DAT_23ed6cd28);
                                                    if (lVar8 == 0) {
LAB_23e7c06c8:
                                                      auStack_98 = *(undefined1 (*) [8])
                                                                    (param_1 + 0x60);
                                                      plStack_90 = *(longlong **)(param_1 + 0x68);
                                                      plStack_88 = *(longlong **)(param_1 + 0x70);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *plVar16 = *plVar16 + -1;
                                                      if (*plVar16 == 0) {
                                                        FUN_23a334bc0(plVar16);
                                                      }
                                                    }
                                                    else {
                                                      plVar16[4] = lVar8;
                                                      uVar6 = _DAT_23eed7e58;
                                                      plVar3 = _DAT_23eed7e50;
                                                      *_DAT_23eed7e50 = *_DAT_23eed7e50 + 1;
                                                      plVar16[5] = (longlong)plVar3;
                                                      lVar8 = FUN_23e94f9d0(param_1,plVar15,uVar6);
                                                      if (lVar8 == 0) goto LAB_23e7c06c8;
                                                      plVar16[6] = lVar8;
                                                      plVar15 = _DAT_23eed7e60;
                                                      uVar6 = _DAT_23eed7e58;
                                                      *_DAT_23eed7e60 = *_DAT_23eed7e60 + 1;
                                                      plVar16[7] = (longlong)plVar15;
                                                      lVar8 = FUN_23e94f9d0(param_1,plStack_178,
                                                                            uVar6);
                                                      if (lVar8 == 0) goto LAB_23e7c06c8;
                                                      plVar16[8] = lVar8;
                                                      plVar15 = _DAT_23eed7e68;
                                                      uVar6 = _DAT_23eed7e20;
                                                      *_DAT_23eed7e68 = *_DAT_23eed7e68 + 1;
                                                      plVar16[9] = (longlong)plVar15;
                                                      plVar15 = _DAT_23eed7e70;
                                                      *plVar10 = *plVar10 + 1;
                                                      plVar16[10] = (longlong)plVar10;
                                                      *plVar12 = *plVar12 + 1;
                                                      plVar16[0xb] = (longlong)plVar12;
                                                      *plVar15 = *plVar15 + 1;
                                                      plVar16[0xc] = (longlong)plVar15;
                                                      lVar8 = FUN_23e94f9d0(param_1,plStack_190,
                                                                            uVar6);
                                                      if (lVar8 == 0) goto LAB_23e7c06c8;
                                                      plVar16[0xd] = lVar8;
                                                      plVar12 = _DAT_23eed7e78;
                                                      plVar10 = DAT_23ed6cd28;
                                                      *_DAT_23eed7e78 = *_DAT_23eed7e78 + 1;
                                                      plVar16[0xe] = (longlong)plVar12;
                                                      lVar8 = FUN_23e94f9d0(param_1,plStack_188,
                                                                            plVar10);
                                                      if (lVar8 == 0) goto LAB_23e7c06c8;
                                                      plVar16[0xf] = lVar8;
                                                      plVar12 = _DAT_23eed7e80;
                                                      plVar10 = DAT_23ed6cd28;
                                                      *_DAT_23eed7e80 = *_DAT_23eed7e80 + 1;
                                                      plVar16[0x10] = (longlong)plVar12;
                                                      plVar10 = (longlong *)
                                                                PyUnicode_Join(plVar10,plVar16);
                                                      *plVar16 = *plVar16 + -1;
                                                      if (*plVar16 == 0) {
                                                        FUN_23a334bc0(plVar16);
                                                      }
                                                      if (plVar10 != (longlong *)0x0) {
                                                        if ((plVar9 != (longlong *)0x0) &&
                                                           (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
                                                          FUN_23a334bc0(plVar9);
                                                        }
                                                        uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                        plVar9 = _DAT_23eed7e30;
                                                        plVar12 = (longlong *)
                                                                  FUN_23e916ad0(*(undefined8 *)
                                                                                 (param_1 + 0x10),2)
                                                        ;
                                                        *plVar9 = *plVar9 + 1;
                                                        plVar12[3] = (longlong)plVar9;
                                                        *plVar10 = *plVar10 + 1;
                                                        plVar12[4] = (longlong)plVar10;
                                                        plVar15 = (longlong *)
                                                                  PyUnicode_Join(DAT_23ed6cd28,
                                                                                 plVar12);
                                                        *plVar12 = *plVar12 + -1;
                                                        if (*plVar12 == 0) {
                                                          FUN_23a334bc0(plVar12);
                                                        }
                                                        if (plVar15 != (longlong *)0x0) {
                                                          *(undefined4 *)(plVar2 + 5) = 0x13b;
                                                          plVar9 = (longlong *)
                                                                   FUN_23e914090(param_1,uVar6,
                                                                                 plVar15);
                                                          *plVar15 = *plVar15 + -1;
                                                          if (*plVar15 == 0) {
                                                            FUN_23a334bc0(plVar15);
                                                          }
                                                          if (plVar9 != (longlong *)0x0)
                                                          goto LAB_23e7b98c5;
                                                        }
                                                        auStack_98 = *(undefined1 (*) [8])
                                                                      (param_1 + 0x60);
                                                        plStack_88 = *(longlong **)(param_1 + 0x70);
                                                        uVar6 = 0x13b;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        plVar9 = plVar10;
                                                        plStack_90 = *(longlong **)(param_1 + 0x68);
                                                        goto LAB_23e7bd8ee;
                                                      }
                                                      plStack_88 = *(longlong **)(param_1 + 0x70);
                                                      auStack_98 = *(undefined1 (*) [8])
                                                                    (param_1 + 0x60);
                                                      plStack_90 = *(longlong **)(param_1 + 0x68);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                    }
                                                    uVar6 = 0x13a;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_23e7bd8ee;
                                                  }
                                                  plStack_88 = *(longlong **)(param_1 + 0x70);
                                                  auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  plStack_90 = *(longlong **)(param_1 + 0x68);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  }
                                                  uVar6 = 0x12e;
                                                  plStack_158 = plStack_e0;
                                                  goto LAB_23e7bd8ee;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  plVar10 = plStack_90;
                                                  auVar23 = auStack_98;
                                                  _auStack_98 = (undefined1  [16])0x0;
                                                  plStack_158 = plStack_88;
                                                  plStack_88 = (longlong *)0x0;
                                                  *plVar12 = lVar8 + -1;
                                                  if (lVar8 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  plStack_88 = (longlong *)0x0;
                                                  _auStack_98 = (undefined1  [16])0x0;
                                                  if ((plVar15 != (longlong *)0x0) &&
                                                     (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                                                    FUN_23a334bc0(plVar15);
                                                  }
                                                  if ((plStack_178 != (longlong *)0x0) &&
                                                     (lVar8 = *plStack_178,
                                                     *plStack_178 = lVar8 + -1, lVar8 + -1 == 0)) {
                                                    FUN_23a334bc0();
                                                  }
                                                  if ((plStack_168 != (longlong *)0x0) &&
                                                     (lVar8 = *plStack_168,
                                                     *plStack_168 = lVar8 + -1, lVar8 + -1 == 0)) {
                                                    FUN_23a334bc0();
                                                  }
                                                  if ((plStack_170 != (longlong *)0x0) &&
                                                     (lVar8 = *plStack_170,
                                                     *plStack_170 = lVar8 + -1, lVar8 + -1 == 0)) {
                                                    FUN_23a334bc0();
                                                  }
                                                  if ((plStack_180 != (longlong *)0x0) &&
                                                     (lVar8 = *plStack_180,
                                                     *plStack_180 = lVar8 + -1, lVar8 + -1 == 0)) {
                                                    FUN_23a334bc0();
                                                  }
                                                  if ((plStack_188 != (longlong *)0x0) &&
                                                     (lVar8 = *plStack_188,
                                                     *plStack_188 = lVar8 + -1, lVar8 + -1 == 0)) {
                                                    FUN_23a334bc0();
                                                  }
                                                  if ((plStack_190 != (longlong *)0x0) &&
                                                     (lVar8 = *plStack_190,
                                                     *plStack_190 = lVar8 + -1, lVar8 + -1 == 0)) {
                                                    FUN_23a334bc0();
                                                  }
                                                  }
                                                  if ((plStack_198 != (longlong *)0x0) &&
                                                     (lVar8 = *plStack_198,
                                                     *plStack_198 = lVar8 + -1, lVar8 + -1 == 0)) {
                                                    FUN_23a334bc0();
                                                  }
                                                  uVar6 = 300;
                                                  plStack_88 = plStack_158;
                                                  plStack_158 = plStack_e0;
                                                  plStack_198 = plStack_a0;
                                                  plStack_190 = plStack_a8;
                                                  plStack_188 = plStack_b0;
                                                  plStack_180 = plStack_b8;
                                                  plStack_170 = plStack_c0;
                                                  plStack_168 = plStack_c8;
                                                  plStack_178 = plStack_d0;
                                                  auStack_98 = auVar23;
                                                  plStack_90 = plVar10;
                                                  goto LAB_23e7bd8ee;
                                                  }
                                                  uVar17 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                  uVar6 = _DAT_23eed7dd0;
                                                  *(undefined4 *)(plVar2 + 5) = 0x128;
                                                  plVar10 = (longlong *)
                                                            FUN_23e939610(param_1,uVar17,
                                                                          _DAT_23eed7dc8 + 0x18,
                                                                          uVar6);
                                                  if (plVar10 == (longlong *)0x0) {
                                                    plStack_88 = *(longlong **)(param_1 + 0x70);
                                                    auStack_98 = *(undefined1 (*) [8])
                                                                  (param_1 + 0x60);
                                                    plStack_90 = *(longlong **)(param_1 + 0x68);
                                                    uVar6 = 0x128;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    plStack_158 = plStack_e0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plStack_198 = plStack_a0;
                                                    plStack_190 = plStack_a8;
                                                    plStack_188 = plStack_b0;
                                                    plStack_180 = plStack_b8;
                                                    plStack_170 = plStack_c0;
                                                    plStack_168 = plStack_c8;
                                                    plStack_178 = plStack_d0;
                                                    goto LAB_23e7bd8ee;
                                                  }
                                                  *plVar10 = *plVar10 + -1;
                                                  if (*plVar10 == 0) {
                                                    FUN_23a334bc0(plVar10);
                                                  }
                                                  lVar8 = FUN_23e8dedb0();
                                                  uVar6 = _DAT_23eed7dd8;
                                                  if (lVar8 == 0) {
                                                    FUN_23e915740(param_1,auStack_98,_DAT_23eed7b38)
                                                    ;
LAB_23e7be410:
                                                    uVar6 = 0x129;
                                                    plStack_158 = plStack_e0;
                                                    plStack_198 = plStack_a0;
                                                    plStack_190 = plStack_a8;
                                                    plStack_188 = plStack_b0;
                                                    plStack_180 = plStack_b8;
                                                    plStack_170 = plStack_c0;
                                                    plStack_168 = plStack_c8;
                                                    plStack_178 = plStack_d0;
                                                    pcVar13 = _Py_NoneStruct_exref;
                                                    goto LAB_23e7bd8ee;
                                                  }
                                                  *(undefined4 *)(plVar2 + 5) = 0x129;
                                                  plVar10 = (longlong *)
                                                            FUN_23e915840(param_1,lVar8,uVar6,
                                                                          *(undefined8 *)
                                                                           (_DAT_23eed7de0 + 0x18));
                                                  if (plVar10 == (longlong *)0x0) {
                                                    plStack_88 = *(longlong **)(param_1 + 0x70);
                                                    auStack_98 = *(undefined1 (*) [8])
                                                                  (param_1 + 0x60);
                                                    plStack_90 = *(longlong **)(param_1 + 0x68);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    goto LAB_23e7be410;
                                                  }
                                                  *plVar10 = *plVar10 + -1;
                                                  if (*plVar10 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  plStack_158 = plStack_e0;
                                                  plStack_198 = plStack_a0;
                                                  plStack_190 = plStack_a8;
                                                  plStack_188 = plStack_b0;
                                                  plStack_180 = plStack_b8;
                                                  plStack_170 = plStack_c0;
                                                  plStack_168 = plStack_c8;
                                                  plStack_178 = plStack_d0;
LAB_23e7b98e4:
                                                  plStack_e0 = plStack_158;
                                                  plStack_a0 = plStack_198;
                                                  plStack_a8 = plStack_190;
                                                  plStack_b0 = plStack_188;
                                                  plStack_b8 = plStack_180;
                                                  plStack_c0 = plStack_170;
                                                  plStack_c8 = plStack_168;
                                                  plStack_d0 = plStack_178;
                                                  }
                                                  plStack_88 = *(longlong **)(param_1 + 0x70);
                                                  auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  plStack_90 = *(longlong **)(param_1 + 0x68);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  uVar6 = 0x125;
                                                  plStack_158 = plStack_e0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  plStack_198 = plStack_a0;
                                                  plStack_190 = plStack_a8;
                                                  plStack_188 = plStack_b0;
                                                  plStack_180 = plStack_b8;
                                                  plStack_170 = plStack_c0;
                                                  plStack_168 = plStack_c8;
                                                  plStack_178 = plStack_d0;
LAB_23e7bd8ee:
                                                  plVar10 = plStack_88;
                                                  plStack_70 = plStack_90;
                                                  pcStack_78 = (code *)auStack_98;
                                                  _auStack_98 = (undefined1  [16])0x0;
                                                  plStack_68 = plStack_88;
                                                  plStack_88 = (longlong *)0x0;
                                                  plVar12 = *(longlong **)(param_1 + 0x138);
                                                  if (plVar12 != (longlong *)0x0) {
                                                    *plVar12 = *plVar12 + 1;
                                                  }
                                                  if (plVar10 == (longlong *)0x0) {
                                                    plVar15 = (longlong *)
                                                              FUN_23e8d6280(plVar2,uVar6);
                                                    if ((plStack_68 != (longlong *)0x0) &&
                                                       (*plStack_68 = *plStack_68 + -1,
                                                       *plStack_68 == 0)) {
                                                      FUN_23a334bc0();
                                                    }
                                                  }
                                                  else {
                                                    plVar15 = (longlong *)
                                                              FUN_23e8d6280(plVar2,uVar6);
                                                    plVar15[2] = (longlong)plVar10;
                                                    *plVar10 = *plVar10 + 1;
                                                    if ((plStack_68 != (longlong *)0x0) &&
                                                       (*plStack_68 = *plStack_68 + -1,
                                                       *plStack_68 == 0)) {
                                                      FUN_23a334bc0();
                                                    }
                                                  }
                                                  plStack_68 = plVar15;
                                                  FUN_23a35ef40(param_1,&pcStack_78);
                                                  iVar5 = FUN_23a35ebd0(param_1,*(undefined8 *)
                                                                                 (*(longlong *)
                                                                                   (param_1 + 0x138)
                                                                                 + 8),
                                                                        *(undefined8 *)
                                                                                                                                                  
                                                  PyExc_KeyboardInterrupt_exref);
                                                  if (iVar5 == 0) {
                                                    cVar4 = FUN_23e8ba320(*(undefined8 *)
                                                                           (param_1 + 0x138),
                                                                          auStack_98);
                                                    plVar10 = plStack_88;
                                                    iStack_120 = 0;
                                                    if (cVar4 == '\0') {
                                                      iStack_120 = 0x123;
                                                    }
                                                    if (plStack_88 != (longlong *)0x0) {
                                                      if ((longlong *)plStack_88[3] == plVar2) {
                                                        *(undefined4 *)(plVar2 + 5) =
                                                             *(undefined4 *)
                                                              ((longlong)plStack_88 + 0x24);
                                                      }
                                                      plStack_88 = (longlong *)0x0;
                                                      _auStack_98 = (undefined1  [16])0x0;
                                                      FUN_23ebf6ae0(param_1,plVar12);
                                                      if ((longlong *)plVar10[3] == plVar2)
                                                      goto LAB_23e7b9bc3;
                                                      plStack_88 = plVar10;
                                                      if (iStack_120 == 0) {
                                                        uVar22 = (undefined4)plVar2[5];
                                                      }
                                                      else {
                                                        uVar22 = 0x123;
                                                      }
                                                      goto LAB_23e7b9b10;
                                                    }
                                                    uVar22 = 0x123;
                                                    _auStack_98 = (undefined1  [16])0x0;
                                                    FUN_23ebf6ae0();
                                                    plStack_88 = (longlong *)0x0;
                                                    if (iStack_120 == 0) {
                                                      uVar22 = (undefined4)plVar2[5];
                                                    }
                                                  }
                                                  else {
                                                    uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                    *(undefined4 *)(plVar2 + 5) = 0x143;
                                                    plVar10 = (longlong *)
                                                              FUN_23e94bb80(param_1,uVar6,
                                                                            _DAT_23eed7e90);
                                                    if (plVar10 == (longlong *)0x0) {
                                                      plVar10 = *(longlong **)(param_1 + 0x70);
                                                      pcVar14 = *(code **)(param_1 + 0x60);
                                                      plVar15 = *(longlong **)(param_1 + 0x68);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      plStack_88 = (longlong *)0x0;
                                                      _auStack_98 = (undefined1  [16])0x0;
                                                      FUN_23ebf6ae0(param_1,plVar12);
                                                      plStack_88 = plVar10;
                                                      auStack_98 = (undefined1  [8])pcVar14;
                                                      plStack_90 = plVar15;
                                                      if (plVar10 != (longlong *)0x0) {
                                                        if ((longlong *)plVar10[3] == plVar2)
                                                        goto LAB_23e7b9bc3;
                                                        uVar22 = 0x143;
                                                        goto LAB_23e7b9b10;
                                                      }
                                                      uVar22 = 0x143;
                                                    }
                                                    else {
                                                      *plVar10 = *plVar10 + -1;
                                                      if (*plVar10 == 0) {
                                                        FUN_23a334bc0(plVar10);
                                                      }
                                                      FUN_23ebf6ae0(param_1,plVar12);
                                                      uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                      *(undefined4 *)(plVar2 + 5) = 0x145;
                                                      plVar10 = (longlong *)
                                                                FUN_23e94bb80(param_1,uVar6,
                                                                              _DAT_23eed7cb8);
                                                      if (plVar10 == (longlong *)0x0) {
                                                        auStack_98 = *(undefined1 (*) [8])
                                                                      (param_1 + 0x60);
                                                        plStack_90 = *(longlong **)(param_1 + 0x68);
                                                        plStack_88 = *(longlong **)(param_1 + 0x70);
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        if (plStack_88 != (longlong *)0x0) {
                                                          uVar22 = 0x145;
                                                          plVar12 = (longlong *)plStack_88[3];
                                                          goto joined_r0x00023e7bdff6;
                                                        }
                                                        uVar22 = 0x145;
                                                      }
                                                      else {
                                                        *plVar10 = *plVar10 + -1;
                                                        if (*plVar10 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                        uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                        *(undefined4 *)(plVar2 + 5) = 0x146;
                                                        plVar10 = (longlong *)
                                                                  FUN_23e94bb80(param_1,uVar6,
                                                                                _DAT_23eed7e98);
                                                        if (plVar10 == (longlong *)0x0) {
                                                          auStack_98 = *(undefined1 (*) [8])
                                                                        (param_1 + 0x60);
                                                          plStack_90 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                          plStack_88 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          if (plStack_88 != (longlong *)0x0) {
                                                            uVar22 = 0x146;
                                                            plVar12 = (longlong *)plStack_88[3];
joined_r0x00023e7bdff6:
                                                            plVar10 = plStack_88;
                                                            if (plVar12 == plVar2)
                                                            goto LAB_23e7b9bc3;
                                                            goto LAB_23e7b9b10;
                                                          }
                                                          uVar22 = 0x146;
                                                        }
                                                        else {
                                                          *plVar10 = *plVar10 + -1;
                                                          if (*plVar10 == 0) {
                                                            FUN_23a334bc0();
                                                          }
                                                          uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                          *(undefined4 *)(plVar2 + 5) = 0x147;
                                                          plVar10 = (longlong *)
                                                                    FUN_23e94bb80(param_1,uVar6,
                                                                                  _DAT_23eed7cc8);
                                                          if (plVar10 != (longlong *)0x0) {
                                                            *plVar10 = *plVar10 + -1;
                                                            if (*plVar10 == 0) {
                                                              FUN_23a334bc0();
                                                            }
                                                            FUN_23ebf6b20(*(undefined8 *)
                                                                           (param_1 + 0x38));
                                                            pcVar20 = _Py_NoneStruct_exref;
                                                            *(longlong *)_Py_NoneStruct_exref =
                                                                 *(longlong *)_Py_NoneStruct_exref +
                                                                 1;
                                                            *plVar7 = *plVar7 + -1;
                                                            if (*plVar7 == 0) {
                                                              FUN_23a334bc0(plVar7);
                                                            }
                                                            *(longlong *)pcVar11 =
                                                                 *(longlong *)pcVar11 + -1;
                                                            if (*(longlong *)pcVar11 == 0) {
                                                              FUN_23a334bc0(pcVar11);
                                                            }
                                                            lVar8 = *plStack_1a0;
                                                            *plStack_1a0 = lVar8 + -1;
                                                            if (lVar8 + -1 == 0) {
                                                              FUN_23a334bc0(plStack_1a0);
                                                            }
                                                            lVar8 = *(longlong *)pcStack_140;
                                                            *(longlong *)pcStack_140 = lVar8 + -1;
                                                            if (lVar8 + -1 == 0) {
                                                              FUN_23a334bc0(pcStack_140);
                                                            }
                                                            lVar8 = *(longlong *)pcStack_148;
                                                            *(longlong *)pcStack_148 = lVar8 + -1;
                                                            if (lVar8 + -1 == 0) {
                                                              FUN_23a334bc0(pcStack_148);
                                                            }
                                                            lVar8 = *plStack_138;
                                                            *plStack_138 = lVar8 + -1;
                                                            if (lVar8 + -1 == 0) {
                                                              FUN_23a334bc0(plStack_138);
                                                            }
                                                            lVar8 = *plStack_130;
                                                            *plStack_130 = lVar8 + -1;
                                                            if (lVar8 + -1 == 0) {
                                                              FUN_23a334bc0(plStack_130);
                                                            }
                                                            lVar8 = *plStack_128;
                                                            *plStack_128 = lVar8 + -1;
                                                            if (lVar8 + -1 == 0) {
                                                              FUN_23a334bc0(plStack_128);
                                                            }
                                                            if ((pcVar13 != (code *)0x0) &&
                                                               (*(longlong *)pcVar13 =
                                                                     *(longlong *)pcVar13 + -1,
                                                               *(longlong *)pcVar13 == 0)) {
                                                              FUN_23a334bc0(pcVar13);
                                                            }
                                                            if ((plStack_d8 != (longlong *)0x0) &&
                                                               (*plStack_d8 = *plStack_d8 + -1,
                                                               *plStack_d8 == 0)) {
                                                              FUN_23a334bc0(plStack_d8);
                                                            }
                                                            if ((plStack_178 != (longlong *)0x0) &&
                                                               (lVar8 = *plStack_178,
                                                               *plStack_178 = lVar8 + -1,
                                                               lVar8 + -1 == 0)) {
                                                              FUN_23a334bc0(plStack_178);
                                                            }
                                                            if ((plStack_168 != (longlong *)0x0) &&
                                                               (lVar8 = *plStack_168,
                                                               *plStack_168 = lVar8 + -1,
                                                               lVar8 + -1 == 0)) {
                                                              FUN_23a334bc0(plStack_168);
                                                            }
                                                            if ((plStack_170 != (longlong *)0x0) &&
                                                               (lVar8 = *plStack_170,
                                                               *plStack_170 = lVar8 + -1,
                                                               lVar8 + -1 == 0)) {
                                                              FUN_23a334bc0(plStack_170);
                                                            }
                                                            if ((plStack_180 != (longlong *)0x0) &&
                                                               (lVar8 = *plStack_180,
                                                               *plStack_180 = lVar8 + -1,
                                                               lVar8 + -1 == 0)) {
                                                              FUN_23a334bc0(plStack_180);
                                                            }
                                                            if ((plStack_188 != (longlong *)0x0) &&
                                                               (lVar8 = *plStack_188,
                                                               *plStack_188 = lVar8 + -1,
                                                               lVar8 + -1 == 0)) {
                                                              FUN_23a334bc0(plStack_188);
                                                            }
                                                            if ((plStack_190 != (longlong *)0x0) &&
                                                               (lVar8 = *plStack_190,
                                                               *plStack_190 = lVar8 + -1,
                                                               lVar8 + -1 == 0)) {
                                                              FUN_23a334bc0(plStack_190);
                                                            }
                                                            if ((plStack_198 != (longlong *)0x0) &&
                                                               (lVar8 = *plStack_198,
                                                               *plStack_198 = lVar8 + -1,
                                                               lVar8 + -1 == 0)) {
                                                              FUN_23a334bc0(plStack_198);
                                                            }
                                                            if ((plStack_158 != (longlong *)0x0) &&
                                                               (lVar8 = *plStack_158,
                                                               *plStack_158 = lVar8 + -1,
                                                               lVar8 + -1 == 0)) {
                                                              FUN_23a334bc0(plStack_158);
                                                            }
                                                            if ((plVar9 != (longlong *)0x0) &&
                                                               (lVar8 = *plVar9,
                                                               *plVar9 = lVar8 + -1, lVar8 + -1 == 0
                                                               )) {
                                                              FUN_23a334bc0(plVar9);
                                                            }
                                                            if ((plStack_160 != (longlong *)0x0) &&
                                                               (lVar8 = *plStack_160,
                                                               *plStack_160 = lVar8 + -1,
                                                               lVar8 + -1 == 0)) {
                                                              FUN_23a334bc0(plStack_160);
                                                            }
                                                            if (plStack_150 != (longlong *)0x0) {
                                                              lVar8 = *plStack_150;
                                                              *plStack_150 = lVar8 + -1;
                                                              if (lVar8 + -1 == 0) {
                                                                FUN_23a334bc0(plStack_150);
                                                                return pcVar20;
                                                              }
                                                              return pcVar20;
                                                            }
                                                            return pcVar20;
                                                          }
                                                          auStack_98 = *(undefined1 (*) [8])
                                                                        (param_1 + 0x60);
                                                          plStack_90 = *(longlong **)
                                                                        (param_1 + 0x68);
                                                          plStack_88 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          if (plStack_88 != (longlong *)0x0) {
                                                            uVar22 = 0x147;
                                                            plVar12 = (longlong *)plStack_88[3];
                                                            goto joined_r0x00023e7bdff6;
                                                          }
                                                          uVar22 = 0x147;
                                                        }
                                                      }
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_23e7baa40;
                                                  }
                                                  auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  plStack_90 = *(longlong **)(param_1 + 0x68);
                                                  plStack_88 = *(longlong **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  if (plStack_88 == (longlong *)0x0)
                                                  goto LAB_23e7becf6;
                                                  if ((longlong *)plStack_88[3] == plVar2)
                                                  goto LAB_23e7be815;
                                                  plVar9 = (longlong *)0x0;
                                                  uVar22 = 0x11c;
                                                  plStack_158 = (longlong *)0x0;
                                                  plStack_198 = (longlong *)0x0;
                                                  plStack_190 = (longlong *)0x0;
                                                  plStack_188 = (longlong *)0x0;
                                                  plStack_180 = (longlong *)0x0;
                                                  plStack_170 = (longlong *)0x0;
                                                  plStack_168 = (longlong *)0x0;
                                                  plStack_178 = (longlong *)0x0;
                                                  plStack_d8 = (longlong *)0x0;
                                                  plStack_150 = (longlong *)0x0;
                                                  plStack_160 = (longlong *)0x0;
                                                  pcVar13 = (code *)0x0;
                                                  goto LAB_23e7b9b10;
                                                  }
                                                  auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  plStack_90 = *(longlong **)(param_1 + 0x68);
                                                  plStack_88 = *(longlong **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  if (plStack_88 != (longlong *)0x0) {
                                                    if ((longlong *)plStack_88[3] == plVar2)
                                                    goto LAB_23e7be815;
                                                    plVar9 = (longlong *)0x0;
                                                    pcVar13 = (code *)0x0;
                                                    plStack_150 = (longlong *)0x0;
                                                    uVar22 = 0x11c;
                                                    plStack_160 = (longlong *)0x0;
                                                    plStack_158 = (longlong *)0x0;
                                                    plStack_198 = (longlong *)0x0;
                                                    plStack_190 = (longlong *)0x0;
                                                    plStack_188 = (longlong *)0x0;
                                                    plStack_180 = (longlong *)0x0;
                                                    plStack_170 = (longlong *)0x0;
                                                    plStack_168 = (longlong *)0x0;
                                                    plStack_178 = (longlong *)0x0;
                                                    plStack_d8 = (longlong *)0x0;
                                                    goto LAB_23e7b9b10;
                                                  }
                                                  }
LAB_23e7becf6:
                                                  plVar9 = (longlong *)0x0;
                                                  plStack_d8 = (longlong *)0x0;
                                                  plStack_158 = (longlong *)0x0;
                                                  uVar22 = 0x11c;
                                                  plStack_198 = (longlong *)0x0;
                                                  plStack_190 = (longlong *)0x0;
                                                  plStack_188 = (longlong *)0x0;
                                                  plStack_180 = (longlong *)0x0;
                                                  plStack_170 = (longlong *)0x0;
                                                  plStack_168 = (longlong *)0x0;
                                                  plStack_178 = (longlong *)0x0;
                                                  pcVar13 = (code *)0x0;
                                                  plStack_150 = (longlong *)0x0;
                                                  plStack_160 = (longlong *)0x0;
                                                  goto LAB_23e7baa40;
                                                  }
                                                  auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  plStack_90 = *(longlong **)(param_1 + 0x68);
                                                  plStack_88 = *(longlong **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  if (plStack_88 != (longlong *)0x0) {
                                                    if ((longlong *)plStack_88[3] == plVar2)
                                                    goto LAB_23e7be815;
                                                    plVar9 = (longlong *)0x0;
                                                    pcVar13 = (code *)0x0;
                                                    plStack_150 = (longlong *)0x0;
                                                    plStack_160 = (longlong *)0x0;
                                                    uVar22 = 0x11b;
                                                    plStack_158 = (longlong *)0x0;
                                                    plStack_198 = (longlong *)0x0;
                                                    plStack_190 = (longlong *)0x0;
                                                    plStack_188 = (longlong *)0x0;
                                                    plStack_180 = (longlong *)0x0;
                                                    plStack_170 = (longlong *)0x0;
                                                    plStack_168 = (longlong *)0x0;
                                                    plStack_178 = (longlong *)0x0;
                                                    plStack_d8 = (longlong *)0x0;
                                                    goto LAB_23e7b9b10;
                                                  }
                                                  }
LAB_23e7bf815:
                                                  plVar9 = (longlong *)0x0;
                                                  pcVar13 = (code *)0x0;
                                                  plStack_150 = (longlong *)0x0;
                                                  plStack_160 = (longlong *)0x0;
                                                  plStack_d8 = (longlong *)0x0;
                                                  plStack_158 = (longlong *)0x0;
                                                  plStack_198 = (longlong *)0x0;
                                                  plStack_190 = (longlong *)0x0;
                                                  plStack_188 = (longlong *)0x0;
                                                  plStack_180 = (longlong *)0x0;
                                                  plStack_170 = (longlong *)0x0;
                                                  plStack_168 = (longlong *)0x0;
                                                  plStack_178 = (longlong *)0x0;
                                                  uVar22 = 0x11b;
                                                  }
                                                  }
                                                  }
                                                  goto LAB_23e7baa40;
                                                  }
                                                  auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  plStack_90 = *(longlong **)(param_1 + 0x68);
                                                  plStack_88 = *(longlong **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  if (plStack_88 != (longlong *)0x0) {
                                                    if ((longlong *)plStack_88[3] == plVar2)
                                                    goto LAB_23e7bc7b6;
                                                    plVar9 = (longlong *)0x0;
                                                    plStack_d8 = (longlong *)0x0;
                                                    plStack_150 = (longlong *)0x0;
                                                    pcVar13 = (code *)0x0;
                                                    uVar22 = 0x115;
                                                    plStack_160 = (longlong *)0x0;
                                                    plStack_158 = (longlong *)0x0;
                                                    plStack_198 = (longlong *)0x0;
                                                    plStack_190 = (longlong *)0x0;
                                                    plStack_188 = (longlong *)0x0;
                                                    plStack_180 = (longlong *)0x0;
                                                    plStack_170 = (longlong *)0x0;
                                                    plStack_168 = (longlong *)0x0;
                                                    plStack_178 = (longlong *)0x0;
                                                    goto LAB_23e7b9b10;
                                                  }
                                                  }
                                                  else {
                                                    iVar5 = *(int *)(lVar8 + 0xc);
                                                    if (*(int *)(lVar8 + 0xc) == 0) {
                                                      *(int *)(lVar8 + 0xc) = _DAT_23ec153f4;
                                                      iVar5 = _DAT_23ec153f4;
                                                      _DAT_23ec153f4 = _DAT_23ec153f4 + 1;
                                                    }
                                                    if (_DAT_23ec153d8 != iVar5) {
                                                      _DAT_23ec153d8 = iVar5;
                                                      _DAT_23eedaa90 =
                                                           FUN_23e8cbd60(lVar8,_DAT_23eed7d68,
                                                                         *(undefined8 *)
                                                                          (_DAT_23eed7d68 + 0x18));
                                                    }
                                                    if (-1 < _DAT_23eedaa90) {
                                                      lVar19 = lVar8 + 0x20 +
                                                               (1L << (*(byte *)(lVar8 + 9) & 0x3f))
                                                      ;
                                                      if (*(longlong *)
                                                           (lVar19 + 8 + _DAT_23eedaa90 * 0x10) != 0
                                                         ) goto LAB_23e7b87bf;
                                                      _DAT_23eedaa90 =
                                                           FUN_23e8cbd60(lVar8,_DAT_23eed7d68,
                                                                         *(undefined8 *)
                                                                          (_DAT_23eed7d68 + 0x18));
                                                      if (-1 < _DAT_23eedaa90) {
                                                        lVar8 = *(longlong *)
                                                                 (lVar19 + 8 + _DAT_23eedaa90 * 0x10
                                                                 );
                                                        goto LAB_23e7bd464;
                                                      }
                                                    }
LAB_23e7bd46d:
                                                    plVar9 = (longlong *)
                                                             FUN_23a37a020(DAT_23ed6ccc0,
                                                                           _DAT_23eed7d68);
                                                    if ((plVar9 != (longlong *)0x0) &&
                                                       (*plVar9 != 0)) goto LAB_23e7b87bf;
                                                    FUN_23e915740(param_1,auStack_98,_DAT_23eed7d68)
                                                    ;
                                                    if (plStack_88 != (longlong *)0x0) {
                                                      if ((longlong *)plStack_88[3] != plVar2) {
                                                        plVar9 = (longlong *)0x0;
                                                        plStack_d8 = (longlong *)0x0;
                                                        plStack_150 = (longlong *)0x0;
                                                        pcVar13 = (code *)0x0;
                                                        plStack_160 = (longlong *)0x0;
                                                        plStack_128 = (longlong *)0x0;
                                                        uVar22 = 0x115;
                                                        plStack_158 = (longlong *)0x0;
                                                        plStack_198 = (longlong *)0x0;
                                                        plStack_190 = (longlong *)0x0;
                                                        plStack_188 = (longlong *)0x0;
                                                        plStack_180 = (longlong *)0x0;
                                                        plStack_170 = (longlong *)0x0;
                                                        plStack_168 = (longlong *)0x0;
                                                        plStack_178 = (longlong *)0x0;
                                                        goto LAB_23e7b9b10;
                                                      }
                                                      goto LAB_23e7bc7b6;
                                                    }
                                                  }
                                                  plVar9 = (longlong *)0x0;
                                                  plStack_d8 = (longlong *)0x0;
                                                  plStack_150 = (longlong *)0x0;
                                                  pcVar13 = (code *)0x0;
                                                  uVar22 = 0x115;
                                                  plStack_160 = (longlong *)0x0;
                                                  plStack_158 = (longlong *)0x0;
                                                  plStack_198 = (longlong *)0x0;
                                                  plStack_190 = (longlong *)0x0;
                                                  plStack_188 = (longlong *)0x0;
                                                  plStack_180 = (longlong *)0x0;
                                                  plStack_170 = (longlong *)0x0;
                                                  plStack_168 = (longlong *)0x0;
                                                  plStack_178 = (longlong *)0x0;
                                                  plStack_128 = (longlong *)0x0;
                                                  goto LAB_23e7baa40;
                                                  }
                                                  auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  plStack_90 = *(longlong **)(param_1 + 0x68);
                                                  plStack_88 = *(longlong **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  if (plStack_88 != (longlong *)0x0) {
                                                    if ((longlong *)plStack_88[3] == plVar2)
                                                    goto LAB_23e7bc7b6;
                                                    plVar9 = (longlong *)0x0;
                                                    plStack_d8 = (longlong *)0x0;
                                                    plStack_158 = (longlong *)0x0;
                                                    uVar22 = 0x112;
                                                    plStack_198 = (longlong *)0x0;
                                                    plStack_190 = (longlong *)0x0;
                                                    plStack_188 = (longlong *)0x0;
                                                    plStack_180 = (longlong *)0x0;
                                                    plStack_170 = (longlong *)0x0;
                                                    plStack_168 = (longlong *)0x0;
                                                    plStack_178 = (longlong *)0x0;
                                                    pcVar13 = (code *)0x0;
                                                    plStack_150 = (longlong *)0x0;
                                                    plStack_160 = (longlong *)0x0;
                                                    plStack_128 = (longlong *)0x0;
                                                    goto LAB_23e7b9b10;
                                                  }
                                                }
                                              }
                                              plVar9 = (longlong *)0x0;
                                              plStack_d8 = (longlong *)0x0;
                                              pcVar13 = (code *)0x0;
                                              plStack_150 = (longlong *)0x0;
                                              uVar22 = 0x112;
                                              plStack_160 = (longlong *)0x0;
                                              plStack_158 = (longlong *)0x0;
                                              plStack_198 = (longlong *)0x0;
                                              plStack_190 = (longlong *)0x0;
                                              plStack_188 = (longlong *)0x0;
                                              plStack_180 = (longlong *)0x0;
                                              plStack_170 = (longlong *)0x0;
                                              plStack_168 = (longlong *)0x0;
                                              plStack_178 = (longlong *)0x0;
                                              plStack_128 = (longlong *)0x0;
                                              goto LAB_23e7baa40;
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                              auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                              plStack_90 = *(longlong **)(param_1 + 0x68);
                              plStack_88 = *(longlong **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              *plVar9 = *plVar9 + -1;
                              if (*plVar9 == 0) {
                                (**(code **)(plVar9[1] + 0x30))();
                              }
                              if (plStack_88 == (longlong *)0x0) goto LAB_23e7bc9dc;
                              if (plVar2 != (longlong *)plStack_88[3]) {
                                plStack_150 = (longlong *)0x0;
                                plVar9 = (longlong *)0x0;
                                pcVar13 = (code *)0x0;
                                plStack_d8 = (longlong *)0x0;
                                plStack_160 = (longlong *)0x0;
                                uVar22 = 0x111;
                                plStack_158 = (longlong *)0x0;
                                plStack_198 = (longlong *)0x0;
                                plStack_190 = (longlong *)0x0;
                                plStack_188 = (longlong *)0x0;
                                plStack_180 = (longlong *)0x0;
                                plStack_170 = (longlong *)0x0;
                                plStack_168 = (longlong *)0x0;
                                plStack_178 = (longlong *)0x0;
                                plStack_128 = (longlong *)0x0;
                                goto LAB_23e7b9b10;
                              }
                              goto LAB_23e7bc7b6;
                            }
                            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                            plStack_90 = *(longlong **)(param_1 + 0x68);
                            plStack_88 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            if (plStack_88 != (longlong *)0x0) goto LAB_23e7bc8b7;
                          }
LAB_23e7bcde8:
                          plVar9 = (longlong *)0x0;
                          plStack_150 = (longlong *)0x0;
                          plStack_d8 = (longlong *)0x0;
                          pcVar13 = (code *)0x0;
                          uVar22 = 0x110;
                          plStack_160 = (longlong *)0x0;
                          plStack_158 = (longlong *)0x0;
                          plStack_198 = (longlong *)0x0;
                          plStack_190 = (longlong *)0x0;
                          plStack_188 = (longlong *)0x0;
                          plStack_180 = (longlong *)0x0;
                          plStack_170 = (longlong *)0x0;
                          plStack_168 = (longlong *)0x0;
                          plStack_178 = (longlong *)0x0;
                          plStack_128 = (longlong *)0x0;
                          goto LAB_23e7baa40;
                        }
                      }
                    }
                  }
                  plVar10 = plStack_88;
                  plVar9 = plStack_90;
                  auVar23 = auStack_98;
                  plStack_88 = (longlong *)0x0;
                  _auStack_98 = (undefined1  [16])0x0;
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))();
                  }
                  plStack_88 = (longlong *)0x0;
                  auStack_98 = (undefined1  [8])0x0;
                  plStack_90 = (longlong *)0x0;
                  if ((pcStack_140 != (code *)0x0) &&
                     (lVar8 = *(longlong *)pcStack_140, *(longlong *)pcStack_140 = lVar8 + -1,
                     lVar8 + -1 == 0)) {
                    (**(code **)(*(longlong *)(pcStack_140 + 8) + 0x30))();
                  }
                  if ((pcStack_148 != (code *)0x0) &&
                     (lVar8 = *(longlong *)pcStack_148, *(longlong *)pcStack_148 = lVar8 + -1,
                     lVar8 + -1 == 0)) {
                    (**(code **)(*(longlong *)(pcStack_148 + 8) + 0x30))();
                  }
                  if ((plStack_138 != (longlong *)0x0) &&
                     (lVar8 = *plStack_138, *plStack_138 = lVar8 + -1, lVar8 + -1 == 0)) {
                    (**(code **)(plStack_138[1] + 0x30))();
                  }
                  if ((plStack_130 != (longlong *)0x0) &&
                     (lVar8 = *plStack_130, *plStack_130 = lVar8 + -1, lVar8 + -1 == 0)) {
                    (**(code **)(plStack_130[1] + 0x30))();
                  }
                  goto LAB_23e7bb824;
                }
              }
              auVar23 = *(undefined1 (*) [8])(param_1 + 0x60);
              plVar10 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar9 = *(longlong **)(param_1 + 0x68);
            }
            else {
              iVar5 = *(int *)(lVar8 + 0xc);
              if (*(int *)(lVar8 + 0xc) == 0) {
                *(int *)(lVar8 + 0xc) = _DAT_23ec153f4;
                iVar5 = _DAT_23ec153f4;
                _DAT_23ec153f4 = _DAT_23ec153f4 + 1;
              }
              if (_DAT_23ec153d4 != iVar5) {
                _DAT_23ec153d4 = iVar5;
                _DAT_23eedaa88 =
                     FUN_23e8cbd60(lVar8,_DAT_23eed7d18,*(undefined8 *)(_DAT_23eed7d18 + 0x18));
              }
              if (-1 < _DAT_23eedaa88) {
                lVar18 = lVar8 + 0x20 + (1L << (*(byte *)(lVar8 + 9) & 0x3f));
                lVar19 = *(longlong *)(lVar18 + 8 + _DAT_23eedaa88 * 0x10);
                if (lVar19 != 0) goto LAB_23e7b7898;
                _DAT_23eedaa88 =
                     FUN_23e8cbd60(lVar8,_DAT_23eed7d18,*(undefined8 *)(_DAT_23eed7d18 + 0x18));
                if (-1 < _DAT_23eedaa88) {
                  lVar19 = *(longlong *)(lVar18 + 8 + _DAT_23eedaa88 * 0x10);
                  goto LAB_23e7bb941;
                }
              }
LAB_23e7bb950:
              plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eed7d18);
              if ((plVar9 != (longlong *)0x0) && (lVar19 = *plVar9, lVar19 != 0))
              goto LAB_23e7b7898;
              FUN_23e915740(param_1,auStack_98,_DAT_23eed7d18);
              plVar10 = plStack_88;
              auVar23 = auStack_98;
              plVar9 = plStack_90;
            }
LAB_23e7bb824:
            pcVar20 = _PyRuntime_exref;
            plStack_88 = plVar10;
            auStack_98 = auVar23;
            plStack_90 = plVar9;
            if (plVar10 != (longlong *)0x0) {
              plStack_150 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              plStack_d8 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              pcVar13 = (code *)0x0;
              plStack_158 = (longlong *)0x0;
              plStack_198 = (longlong *)0x0;
              plStack_190 = (longlong *)0x0;
              plStack_188 = (longlong *)0x0;
              plStack_180 = (longlong *)0x0;
              plStack_170 = (longlong *)0x0;
              plStack_168 = (longlong *)0x0;
              plStack_178 = (longlong *)0x0;
              plStack_128 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_138 = (longlong *)0x0;
              pcStack_148 = (code *)0x0;
              pcStack_140 = (code *)0x0;
              if ((longlong *)plVar10[3] == plVar2) goto LAB_23e7b9bc3;
              uVar22 = 0x10e;
              goto LAB_23e7b9b10;
            }
            plStack_150 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            pcVar13 = (code *)0x0;
            plStack_160 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            uVar22 = 0x10e;
            plStack_158 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_190 = (longlong *)0x0;
            plStack_188 = (longlong *)0x0;
            plStack_180 = (longlong *)0x0;
            plStack_170 = (longlong *)0x0;
            plStack_168 = (longlong *)0x0;
            plStack_178 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_130 = (longlong *)0x0;
            plStack_138 = (longlong *)0x0;
            pcStack_148 = (code *)0x0;
            pcStack_140 = (code *)0x0;
            goto LAB_23e7baa40;
          }
        }
        plVar9 = plStack_88;
        plVar12 = plStack_90;
        auVar23 = auStack_98;
        plStack_88 = (longlong *)0x0;
        _auStack_98 = (undefined1  [16])0x0;
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))();
        }
        plStack_88 = (longlong *)0x0;
        auStack_98 = (undefined1  [8])0x0;
        plStack_90 = (longlong *)0x0;
        if ((pcVar11 != (code *)0x0) &&
           (*(longlong *)pcVar11 = *(longlong *)pcVar11 + -1, *(longlong *)pcVar11 == 0)) {
          (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))();
        }
        if ((plStack_1a0 != (longlong *)0x0) &&
           (lVar8 = *plStack_1a0, *plStack_1a0 = lVar8 + -1, lVar8 + -1 == 0)) {
          (**(code **)(plStack_1a0[1] + 0x30))();
        }
      }
      pcVar20 = _PyRuntime_exref;
      plStack_88 = plVar9;
      auStack_98 = auVar23;
      plStack_90 = plVar12;
      if (plVar9 != (longlong *)0x0) {
        if ((longlong *)plVar9[3] == plVar2) {
LAB_23e7bb0b0:
          plStack_150 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          pcVar13 = (code *)0x0;
          plStack_160 = (longlong *)0x0;
          pcVar11 = (code *)0x0;
          plStack_158 = (longlong *)0x0;
          plStack_198 = (longlong *)0x0;
          plStack_190 = (longlong *)0x0;
          plStack_188 = (longlong *)0x0;
          plStack_180 = (longlong *)0x0;
          plStack_170 = (longlong *)0x0;
          plStack_168 = (longlong *)0x0;
          plStack_178 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
          pcStack_148 = (code *)0x0;
          pcStack_140 = (code *)0x0;
          plStack_1a0 = (longlong *)0x0;
          plVar10 = plStack_88;
          goto LAB_23e7b9bc3;
        }
        plStack_150 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
        pcVar13 = (code *)0x0;
        pcVar11 = (code *)0x0;
        uVar22 = 0x10d;
        plStack_158 = (longlong *)0x0;
        plStack_198 = (longlong *)0x0;
        plStack_190 = (longlong *)0x0;
        plStack_188 = (longlong *)0x0;
        plStack_180 = (longlong *)0x0;
        plStack_170 = (longlong *)0x0;
        plStack_168 = (longlong *)0x0;
        plStack_178 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        pcStack_148 = (code *)0x0;
        pcStack_140 = (code *)0x0;
        plStack_1a0 = (longlong *)0x0;
        goto LAB_23e7b9b10;
      }
      plStack_150 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcVar13 = (code *)0x0;
      pcVar11 = (code *)0x0;
      uVar22 = 0x10d;
      plStack_158 = (longlong *)0x0;
      plStack_198 = (longlong *)0x0;
      plStack_190 = (longlong *)0x0;
      plStack_188 = (longlong *)0x0;
      plStack_180 = (longlong *)0x0;
      plStack_170 = (longlong *)0x0;
      plStack_168 = (longlong *)0x0;
      plStack_178 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      pcStack_148 = (code *)0x0;
      pcStack_140 = (code *)0x0;
      plStack_1a0 = (longlong *)0x0;
    }
LAB_23e7baa40:
    plVar10 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      plVar12 = plStack_88;
    }
    else {
      plVar12 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar12;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar12 = (longlong *)0x0;
    }
    plVar10[2] = 0;
    plVar10[3] = (longlong)plVar2;
    *plVar2 = *plVar2 + 1;
    lVar8 = *(longlong *)(pcVar20 + 0x1f8);
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar8 = *(longlong *)(lVar8 + 0x10);
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar22;
    lVar8 = *(longlong *)(lVar8 + 0x2e8);
    lVar19 = plVar10[-1];
    puVar1 = *(undefined8 **)(lVar8 + 8);
    *puVar1 = plVar10 + -2;
    plVar10[-2] = lVar8;
    plVar10[-1] = (ulonglong)((uint)lVar19 & 3) | (ulonglong)puVar1;
    *(longlong **)(lVar8 + 8) = plVar10 + -2;
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))();
  }
LAB_23e7b9bc3:
  plStack_88 = plVar10;
  FUN_23e8bba40(plVar2,"ooooooooooooooooooooo",plVar7,pcVar11,plStack_1a0,pcStack_140,pcStack_148,
                plStack_138,plStack_130,plStack_128,pcVar13,plStack_d8,plStack_178,plStack_168,
                plStack_170,plStack_180,plStack_188,plStack_190,plStack_198,plStack_158,plVar9,
                plStack_160,plStack_150);
  if (_DAT_23eedaaa0 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    _DAT_23eedaaa0 = (longlong *)0x0;
  }
  lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar2 = *(longlong **)(lVar8 + 0x28);
  plVar10 = (longlong *)plVar2[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar8 + 0x30);
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
  plVar12 = plStack_88;
  plVar10 = plStack_90;
  auVar23 = auStack_98;
  plVar2[0xf] = 0;
  _auStack_98 = (undefined1  [16])0x0;
  plStack_88 = (longlong *)0x0;
  if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  if ((pcVar11 != (code *)0x0) &&
     (*(longlong *)pcVar11 = *(longlong *)pcVar11 + -1, *(longlong *)pcVar11 == 0)) {
    (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
  }
  if ((plStack_1a0 != (longlong *)0x0) &&
     (lVar8 = *plStack_1a0, *plStack_1a0 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_1a0[1] + 0x30))(plStack_1a0);
  }
  if ((pcStack_140 != (code *)0x0) &&
     (lVar8 = *(longlong *)pcStack_140, *(longlong *)pcStack_140 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(*(longlong *)(pcStack_140 + 8) + 0x30))();
  }
  if ((pcStack_148 != (code *)0x0) &&
     (lVar8 = *(longlong *)pcStack_148, *(longlong *)pcStack_148 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(*(longlong *)(pcStack_148 + 8) + 0x30))(pcStack_148);
  }
  if ((plStack_138 != (longlong *)0x0) &&
     (lVar8 = *plStack_138, *plStack_138 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_138[1] + 0x30))(plStack_138);
  }
  if ((plStack_130 != (longlong *)0x0) &&
     (lVar8 = *plStack_130, *plStack_130 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_130[1] + 0x30))(plStack_130);
  }
  if ((plStack_128 != (longlong *)0x0) &&
     (lVar8 = *plStack_128, *plStack_128 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_128[1] + 0x30))();
  }
  if ((pcVar13 != (code *)0x0) &&
     (*(longlong *)pcVar13 = *(longlong *)pcVar13 + -1, *(longlong *)pcVar13 == 0)) {
    (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
  }
  if ((plStack_d8 != (longlong *)0x0) && (*plStack_d8 = *plStack_d8 + -1, *plStack_d8 == 0)) {
    (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
  }
  if ((plStack_178 != (longlong *)0x0) &&
     (lVar8 = *plStack_178, *plStack_178 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_178[1] + 0x30))(plStack_178);
  }
  if ((plStack_168 != (longlong *)0x0) &&
     (lVar8 = *plStack_168, *plStack_168 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_168[1] + 0x30))(plStack_168);
  }
  if ((plStack_170 != (longlong *)0x0) &&
     (lVar8 = *plStack_170, *plStack_170 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_170[1] + 0x30))();
  }
  if ((plStack_180 != (longlong *)0x0) &&
     (lVar8 = *plStack_180, *plStack_180 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_180[1] + 0x30))(plStack_180);
  }
  if ((plStack_188 != (longlong *)0x0) &&
     (lVar8 = *plStack_188, *plStack_188 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_188[1] + 0x30))(plStack_188);
  }
  if ((plStack_190 != (longlong *)0x0) &&
     (lVar8 = *plStack_190, *plStack_190 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_190[1] + 0x30))();
  }
  if ((plStack_198 != (longlong *)0x0) &&
     (lVar8 = *plStack_198, *plStack_198 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_198[1] + 0x30))(plStack_198);
  }
  if ((plStack_158 != (longlong *)0x0) &&
     (lVar8 = *plStack_158, *plStack_158 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_158[1] + 0x30))(plStack_158);
  }
  if ((plVar9 != (longlong *)0x0) && (lVar8 = *plVar9, *plVar9 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((plStack_160 != (longlong *)0x0) &&
     (lVar8 = *plStack_160, *plStack_160 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_160[1] + 0x30))(plStack_160);
  }
  if ((plStack_150 != (longlong *)0x0) &&
     (lVar8 = *plStack_150, *plStack_150 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_150[1] + 0x30))(plStack_150);
  }
  _auStack_98 = CONCAT88(plVar10,auVar23);
  plStack_88 = plVar12;
  FUN_23a33aa70(param_1,auVar23,plVar10,plVar12);
  return (code *)0x0;
}
