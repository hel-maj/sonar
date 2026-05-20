/* ===== 23e79c1b0 workers.fishing.garbage_disposal:326 ===== */
/* ghidra_name=FUN_23e79c1b0 entry=23e79c1b0 size=11449 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e79c1b0(longlong param_1,undefined8 param_2,longlong *param_3)

{
  double dVar1;
  double dVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  code *pcVar5;
  longlong *plVar6;
  longlong *plVar7;
  code *pcVar8;
  undefined4 uVar9;
  undefined1 auVar10 [16];
  char cVar11;
  int iVar12;
  undefined8 uVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong lVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong *plVar20;
  longlong *plVar21;
  longlong *plVar22;
  longlong lVar23;
  code *pcVar24;
  longlong *plVar25;
  code *pcVar26;
  longlong *plStack_148;
  longlong *plStack_140;
  longlong *plStack_138;
  longlong *plStack_130;
  code *pcStack_128;
  longlong *plStack_120;
  longlong *plStack_118;
  longlong *plStack_f8;
  longlong *plStack_f0;
  longlong *plStack_e8;
  longlong *plStack_e0;
  longlong *plStack_d8;
  longlong *plStack_d0;
  code *pcStack_c8;
  longlong *plStack_c0;
  longlong *plStack_a0;
  longlong *plStack_98;
  code *pcStack_90;
  undefined1 auStack_88 [16];
  longlong *plStack_78;
  
  plVar14 = _DAT_23eedac10;
  plVar7 = (longlong *)param_3[2];
  pcVar8 = (code *)param_3[3];
  plVar3 = (longlong *)*param_3;
  plStack_f8 = (longlong *)param_3[1];
  plStack_78 = (longlong *)0x0;
  auStack_88 = (undefined1  [16])0x0;
  if (_DAT_23eedac10 == (longlong *)0x0) {
LAB_23e79c23a:
    _DAT_23eedac10 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedac08,DAT_23eedacf8);
  }
  else {
    lVar17 = *_DAT_23eedac10;
    if (1 < lVar17) {
      *_DAT_23eedac10 = lVar17 + -1;
      goto LAB_23e79c23a;
    }
    if (_DAT_23eedac10[2] != 0) {
      *_DAT_23eedac10 = lVar17 + -1;
      if (lVar17 + -1 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      goto LAB_23e79c23a;
    }
  }
  plVar6 = _DAT_23eedac10;
  lVar17 = *(longlong *)(param_1 + 0x38);
  plVar14 = _DAT_23eedac10 + 9;
  lVar23 = *(longlong *)(lVar17 + 8);
  _DAT_23eedac10[0xf] = lVar23;
  *(longlong **)(lVar17 + 8) = plVar14;
  if ((lVar23 != 0) &&
     (((*(char *)(lVar23 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar23 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar23 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar23 + 0x38))) && (plVar6[0xe] != 0)))) {
    plVar14 = *(longlong **)(lVar23 + 0x28);
    *(longlong **)(plVar6[0xe] + 0x10) = plVar14;
    if (plVar14 != (longlong *)0x0) {
      *plVar14 = *plVar14 + 1;
    }
  }
  *plVar6 = *plVar6 + 1;
  *(undefined4 *)(plVar6 + 8) = 0;
  iVar12 = FUN_23a35f020(plStack_f8);
  if (iVar12 == -1) {
    plStack_78 = *(longlong **)(param_1 + 0x70);
    auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar14 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_e0 = (longlong *)0x0;
    pcVar26 = (code *)0x0;
    plStack_118._0_4_ = 0x14a;
    plStack_140 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    pcStack_128 = (code *)0x0;
    plStack_148 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e79d3a0;
  }
  if (iVar12 == 0) {
    lVar17 = *(longlong *)(param_1 + 0x10);
    if (*(int *)(lVar17 + 0x1188) == 0) {
      plVar14 = (longlong *)FUN_23a33a530(PyList_Type_exref);
    }
    else {
      iVar12 = *(int *)(lVar17 + 0x1188) + -1;
      *(int *)(lVar17 + 0x1188) = iVar12;
      plVar14 = *(longlong **)(lVar17 + 0xf08 + (longlong)iVar12 * 8);
      *plVar14 = 1;
    }
    pcVar24 = _PyRuntime_exref;
    plStack_e8 = (longlong *)0x0;
    pcVar26 = (code *)0x0;
    plVar14[2] = 0;
    plVar15 = (longlong *)0x0;
    plVar14[4] = 0;
    lVar17 = *(longlong *)(pcVar24 + 0x1f8);
    plVar14[3] = 0;
    plStack_140 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    lVar17 = *(longlong *)(*(longlong *)(lVar17 + 0x10) + 0x2e8);
    lVar23 = plVar14[-1];
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    puVar4 = *(undefined8 **)(lVar17 + 8);
    plStack_c0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    *puVar4 = plVar14 + -2;
    pcStack_c8 = (code *)0x0;
    plStack_138 = (longlong *)0x0;
    plVar14[-2] = lVar17;
    plVar14[-1] = (ulonglong)((uint)lVar23 & 3) | (ulonglong)puVar4;
    plStack_130 = (longlong *)0x0;
    *(longlong **)(lVar17 + 8) = plVar14 + -2;
LAB_23e79ccdd:
    lVar17 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar6 = *(longlong **)(lVar17 + 0x28);
    plVar16 = (longlong *)plVar6[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar17 + 0x30);
    *(undefined4 *)(plVar6 + 8) = 0xffffffff;
    if (plVar16 != (longlong *)0x0) {
      plVar6[2] = 0;
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        (**(code **)(plVar16[1] + 0x30))();
      }
    }
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    plVar6[0xf] = 0;
    if ((plStack_f8 != (longlong *)0x0) && (*plStack_f8 = *plStack_f8 + -1, *plStack_f8 == 0)) {
      (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
    }
    if ((plStack_130 != (longlong *)0x0) &&
       (lVar17 = *plStack_130, *plStack_130 = lVar17 + -1, lVar17 + -1 == 0)) {
      (**(code **)(plStack_130[1] + 0x30))(plStack_130);
    }
    if ((plStack_138 != (longlong *)0x0) &&
       (lVar17 = *plStack_138, *plStack_138 = lVar17 + -1, lVar17 + -1 == 0)) {
      (**(code **)(plStack_138[1] + 0x30))(plStack_138);
    }
    if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    if ((pcStack_c8 != (code *)0x0) &&
       (lVar17 = *(longlong *)pcStack_c8, *(longlong *)pcStack_c8 = lVar17 + -1, lVar17 + -1 == 0))
    {
      (**(code **)(*(longlong *)(pcStack_c8 + 8) + 0x30))(pcStack_c8);
    }
    if ((plStack_d0 != (longlong *)0x0) &&
       (lVar17 = *plStack_d0, *plStack_d0 = lVar17 + -1, lVar17 + -1 == 0)) {
      (**(code **)(plStack_d0[1] + 0x30))(plStack_d0);
    }
    if ((plStack_c0 != (longlong *)0x0) &&
       (lVar17 = *plStack_c0, *plStack_c0 = lVar17 + -1, lVar17 + -1 == 0)) {
      (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
    }
    if ((pcVar26 != (code *)0x0) &&
       (*(longlong *)pcVar26 = *(longlong *)pcVar26 + -1, *(longlong *)pcVar26 == 0)) {
      (**(code **)(*(longlong *)(pcVar26 + 8) + 0x30))(pcVar26);
    }
    if ((plStack_e8 != (longlong *)0x0) && (*plStack_e8 = *plStack_e8 + -1, *plStack_e8 == 0)) {
      (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
    }
    if ((plStack_e0 != (longlong *)0x0) &&
       (lVar17 = *plStack_e0, *plStack_e0 = lVar17 + -1, lVar17 + -1 == 0)) {
      (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
    }
    if ((plStack_d8 != (longlong *)0x0) &&
       (lVar17 = *plStack_d8, *plStack_d8 = lVar17 + -1, lVar17 + -1 == 0)) {
      (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
    }
    if ((plStack_118 != (longlong *)0x0) &&
       (lVar17 = *plStack_118, *plStack_118 = lVar17 + -1, lVar17 + -1 == 0)) {
      (**(code **)(plStack_118[1] + 0x30))(plStack_118);
    }
    if ((plStack_140 != (longlong *)0x0) &&
       (lVar17 = *plStack_140, *plStack_140 = lVar17 + -1, lVar17 + -1 == 0)) {
      (**(code **)(plStack_140[1] + 0x30))(plStack_140);
    }
    lVar17 = *plVar3;
    *plVar3 = lVar17 + -1;
    if (lVar17 + -1 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    lVar17 = *plVar7;
    *plVar7 = lVar17 + -1;
    if (lVar17 + -1 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    lVar17 = *(longlong *)pcVar8;
    *(longlong *)pcVar8 = lVar17 + -1;
    if (lVar17 + -1 != 0) {
      return plVar14;
    }
    (**(code **)(*(longlong *)(pcVar8 + 8) + 0x30))(pcVar8);
    return plVar14;
  }
  uVar13 = FUN_23a3a0d40(_DAT_23eed8498);
  plVar14 = (longlong *)
            FUN_23e93e1e0(FUN_23e79ef70,_DAT_23eed84a0,_DAT_23eed84a8,_DAT_23eedac00,0,0,
                          DAT_23eedacf8,0,0,0);
  *(undefined4 *)(plVar6 + 5) = 0x14e;
  pcStack_90 = _Py_TrueStruct_exref;
  plStack_a0 = plStack_f8;
  plStack_98 = plVar14;
  plVar15 = (longlong *)FUN_23e939900(param_1,uVar13,&plStack_a0,&plStack_98,_DAT_23eed84b0);
  *plVar14 = *plVar14 + -1;
  if (*plVar14 == 0) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if (plVar15 == (longlong *)0x0) {
    auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_78 = *(longlong **)(param_1 + 0x70);
    plVar14 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_e0 = (longlong *)0x0;
    pcVar26 = (code *)0x0;
    plStack_140 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    pcStack_128 = (code *)0x0;
    plStack_148 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_118._0_4_ = 0x14e;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e79d3a0;
  }
  *plStack_f8 = *plStack_f8 + -1;
  if (*plStack_f8 == 0) {
    (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
  }
  lVar17 = *(longlong *)(param_1 + 0x10);
  if (*(int *)(lVar17 + 0x1188) == 0) {
    plVar14 = (longlong *)FUN_23a33a530(PyList_Type_exref);
  }
  else {
    iVar12 = *(int *)(lVar17 + 0x1188) + -1;
    *(int *)(lVar17 + 0x1188) = iVar12;
    plVar14 = *(longlong **)(lVar17 + 0xf08 + (longlong)iVar12 * 8);
    *plVar14 = 1;
  }
  pcVar24 = _PyRuntime_exref;
  plVar14[2] = 0;
  plVar14[4] = 0;
  lVar17 = *(longlong *)(pcVar24 + 0x1f8);
  plVar14[3] = 0;
  lVar17 = *(longlong *)(*(longlong *)(lVar17 + 0x10) + 0x2e8);
  lVar23 = plVar14[-1];
  puVar4 = *(undefined8 **)(lVar17 + 8);
  *puVar4 = plVar14 + -2;
  plVar14[-2] = lVar17;
  plVar14[-1] = (ulonglong)((uint)lVar23 & 3) | (ulonglong)puVar4;
  *(longlong **)(lVar17 + 8) = plVar14 + -2;
  uVar13 = FUN_23a3a0d40(_DAT_23eed84b8);
  *(undefined4 *)(plVar6 + 5) = 0x151;
  plStack_98 = plVar7;
  pcStack_90 = pcVar8;
  plVar16 = (longlong *)FUN_23e94ed00(param_1,uVar13,&plStack_98);
  pcVar26 = PyFloat_Type_exref;
  plStack_f8 = plVar15;
  plStack_130 = plVar14;
  if (plVar16 == (longlong *)0x0) {
    auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_78 = *(longlong **)(param_1 + 0x70);
    plVar14 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_e0 = (longlong *)0x0;
    pcVar26 = (code *)0x0;
    plStack_140 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    pcStack_128 = (code *)0x0;
    plStack_138 = (longlong *)0x0;
    plStack_118._0_4_ = 0x151;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_148 = (longlong *)0x0;
    goto LAB_23e79d3a0;
  }
  if ((code *)plVar16[1] == PyFloat_Type_exref) {
    dVar1 = (double)plVar16[2];
    dVar2 = *(double *)(_DAT_23eed84c0 + 0x10);
    lVar17 = *(longlong *)(*(longlong *)(pcVar24 + 0x1f8) + 0x10);
    plStack_138 = *(longlong **)(lVar17 + 0xe08);
    if (plStack_138 == (longlong *)0x0) {
      plStack_138 = (longlong *)(*DAT_23ed6ccd0)(0,0x18);
    }
    else {
      lVar23 = plStack_138[1];
      *(int *)(lVar17 + 0xe00) = *(int *)(lVar17 + 0xe00) + -1;
      *(longlong *)(lVar17 + 0xe08) = lVar23;
    }
    plStack_138[1] = (longlong)pcVar26;
    *plStack_138 = 1;
    plStack_138[2] = (longlong)(dVar2 * dVar1);
    lVar17 = *plVar16;
    *plVar16 = lVar17 + -1;
    if (lVar17 + -1 == 0) {
      (**(code **)(plVar16[1] + 0x30))(plVar16);
    }
  }
  else {
    plStack_138 = (longlong *)FUN_23e8c35b0(plVar16);
    lVar17 = *plVar16;
    *plVar16 = lVar17 + -1;
    if (lVar17 + -1 == 0) {
      (**(code **)(plVar16[1] + 0x30))(plVar16);
    }
    if (plStack_138 == (longlong *)0x0) {
      auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_78 = *(longlong **)(param_1 + 0x70);
      plVar14 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_e0 = (longlong *)0x0;
      pcVar26 = (code *)0x0;
      plStack_140 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      pcStack_128 = (code *)0x0;
      plStack_148 = (longlong *)0x0;
      plStack_118._0_4_ = 0x151;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e79d3a0;
    }
  }
  plVar16 = (longlong *)FUN_23ebf7180(plVar15);
  if (plVar16 == (longlong *)0x0) {
    auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_78 = *(longlong **)(param_1 + 0x70);
    plVar14 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_e0 = (longlong *)0x0;
    pcVar26 = (code *)0x0;
    plStack_140 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    pcStack_128 = (code *)0x0;
    plStack_148 = (longlong *)0x0;
    plStack_118._0_4_ = 0x153;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e79d3a0;
  }
  plStack_e8 = (longlong *)0x0;
  pcVar26 = (code *)0x0;
  plStack_140 = (longlong *)0x0;
  plStack_118 = (longlong *)0x0;
  plStack_d8 = (longlong *)0x0;
  plStack_e0 = (longlong *)0x0;
  plStack_d0 = (longlong *)0x0;
  plVar15 = (longlong *)0x0;
  pcVar24 = pcVar26;
  plStack_c0 = plStack_e8;
  while( true ) {
    pcVar5 = *(code **)(plVar16[1] + 0xe0);
    pcStack_128 = pcVar24;
    plStack_f0 = plStack_c0;
    if (pcVar5 == (code *)0x0) break;
    plStack_148 = (longlong *)(*pcVar5)(plVar16);
    if (plStack_148 == (longlong *)0x0) goto LAB_23e79e0b1;
    if (plVar15 == (longlong *)0x0) {
      *plStack_148 = *plStack_148 + 1;
    }
    else {
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
        lVar17 = *plStack_148;
      }
      else {
        lVar17 = *plStack_148;
      }
      *plStack_148 = lVar17 + 1;
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
    }
    plVar15 = (longlong *)FUN_23a388310(plStack_148);
    if (plVar15 == (longlong *)0x0) {
      lVar17 = *(longlong *)(param_1 + 0x60);
      uVar13 = *(undefined8 *)(param_1 + 0x68);
      plVar18 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e79e2d3:
      plStack_120 = plStack_d0;
      uVar9 = 0x154;
      pcStack_128 = pcVar24;
      plStack_f0 = plStack_c0;
      goto LAB_23e79ddad;
    }
    pcStack_128 = (code *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
    if ((pcStack_128 == (code *)0x0) &&
       (pcStack_128 = (code *)FUN_23a3c1b70(param_1,auStack_88,0,3), pcStack_128 == (code *)0x0)) {
      lVar23 = *plVar15;
      plStack_f0 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
LAB_23e79e1be:
      plVar18 = plStack_78;
      lVar17 = auStack_88._0_8_;
      uVar13 = auStack_88._8_8_;
      auStack_88 = (undefined1  [16])0x0;
      plStack_78 = (longlong *)0x0;
      *plVar15 = lVar23 + -1;
      if (lVar23 + -1 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      plStack_78 = (longlong *)0x0;
      auStack_88 = (undefined1  [16])0x0;
      if ((pcStack_128 != (code *)0x0) &&
         (lVar23 = *(longlong *)pcStack_128, *(longlong *)pcStack_128 = lVar23 + -1,
         lVar23 + -1 == 0)) {
        (**(code **)(*(longlong *)(pcStack_128 + 8) + 0x30))(pcStack_128);
      }
      if ((plStack_120 != (longlong *)0x0) &&
         (lVar23 = *plStack_120, *plStack_120 = lVar23 + -1, lVar23 + -1 == 0)) {
        (**(code **)(plStack_120[1] + 0x30))(plStack_120);
      }
      if ((plStack_f0 != (longlong *)0x0) &&
         (lVar23 = *plStack_f0, *plStack_f0 = lVar23 + -1, lVar23 + -1 == 0)) {
        (**(code **)(plStack_f0[1] + 0x30))(plStack_f0);
      }
      goto LAB_23e79e2d3;
    }
    pcStack_c8 = (code *)auStack_88;
    plStack_120 = (longlong *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
    if ((plStack_120 == (longlong *)0x0) &&
       (plStack_120 = (longlong *)FUN_23a3c1b70(param_1,pcStack_c8,1,3),
       plStack_120 == (longlong *)0x0)) {
      lVar23 = *plVar15;
      plStack_f0 = (longlong *)0x0;
      goto LAB_23e79e1be;
    }
    plStack_f0 = (longlong *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
    if ((plStack_f0 == (longlong *)0x0) &&
       (plStack_f0 = (longlong *)FUN_23a3c1b70(param_1,pcStack_c8,2,3),
       plStack_f0 == (longlong *)0x0)) {
      lVar23 = *plVar15;
      goto LAB_23e79e1be;
    }
    cVar11 = FUN_23a3884a0(param_1,pcStack_c8,plVar15,3);
    lVar23 = *plVar15;
    if (cVar11 == '\0') goto LAB_23e79e1be;
    *plVar15 = lVar23 + -1;
    if (lVar23 + -1 == 0) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    lVar17 = *(longlong *)pcStack_128;
    *(longlong *)pcStack_128 = lVar17 + 1;
    if (pcVar24 != (code *)0x0) {
      *(longlong *)pcVar24 = *(longlong *)pcVar24 + -1;
      if (*(longlong *)pcVar24 == 0) {
        (**(code **)(*(longlong *)(pcVar24 + 8) + 0x30))(pcVar24);
        lVar17 = *(longlong *)pcStack_128 + -1;
      }
      else {
        lVar17 = *(longlong *)pcStack_128 + -1;
      }
    }
    *(longlong *)pcStack_128 = lVar17;
    if (lVar17 == 0) {
      (**(code **)(*(longlong *)(pcStack_128 + 8) + 0x30))();
    }
    lVar17 = *plStack_120;
    *plStack_120 = lVar17 + 1;
    if (plStack_d0 != (longlong *)0x0) {
      lVar17 = *plStack_d0;
      *plStack_d0 = lVar17 + -1;
      if (lVar17 + -1 == 0) {
        (**(code **)(plStack_d0[1] + 0x30))(plStack_d0);
        lVar17 = *plStack_120 + -1;
      }
      else {
        lVar17 = *plStack_120 + -1;
      }
    }
    *plStack_120 = lVar17;
    if (lVar17 == 0) {
      (**(code **)(plStack_120[1] + 0x30))();
    }
    lVar17 = *plStack_f0;
    *plStack_f0 = lVar17 + 1;
    if (plStack_c0 != (longlong *)0x0) {
      *plStack_c0 = *plStack_c0 + -1;
      if (*plStack_c0 == 0) {
        (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
        lVar17 = *plStack_f0 + -1;
      }
      else {
        lVar17 = *plStack_f0 + -1;
      }
    }
    *plStack_f0 = lVar17;
    if (lVar17 == 0) {
      (**(code **)(plStack_f0[1] + 0x30))();
    }
    *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
    if ((pcVar26 != (code *)0x0) &&
       (*(longlong *)pcVar26 = *(longlong *)pcVar26 + -1, *(longlong *)pcVar26 == 0)) {
      (**(code **)(*(longlong *)(pcVar26 + 8) + 0x30))(pcVar26);
    }
    plVar15 = (longlong *)FUN_23ebf7180(plVar14);
    if (plVar15 == (longlong *)0x0) {
      plVar18 = *(longlong **)(param_1 + 0x70);
      lVar17 = *(longlong *)(param_1 + 0x60);
      uVar13 = *(undefined8 *)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar26 = _Py_FalseStruct_exref;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar9 = 0x158;
      goto LAB_23e79ddad;
    }
    plVar25 = (longlong *)0x0;
LAB_23e79c7ed:
    plVar18 = (longlong *)(**(code **)(plVar15[1] + 0xe0))();
    if (plVar18 != (longlong *)0x0) {
      if ((plVar25 != (longlong *)0x0) && (*plVar25 = *plVar25 + -1, *plVar25 == 0)) {
        (**(code **)(plVar25[1] + 0x30))(plVar25);
      }
      *plVar18 = *plVar18 + 1;
      if ((plStack_e8 != (longlong *)0x0) && (*plStack_e8 = *plStack_e8 + -1, *plStack_e8 == 0)) {
        (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
      }
      plVar19 = (longlong *)FUN_23a388310(plVar18);
      plStack_e8 = plVar18;
      plVar25 = plVar18;
      if (plVar19 != (longlong *)0x0) {
        plVar20 = (longlong *)(**(code **)(plVar19[1] + 0xe0))(plVar19);
        if ((plVar20 == (longlong *)0x0) &&
           (plVar20 = (longlong *)FUN_23a3c1b70(param_1,pcStack_c8,0,3), plVar20 == (longlong *)0x0)
           ) {
          lVar23 = *plVar19;
          plVar22 = (longlong *)0x0;
          plVar21 = (longlong *)0x0;
LAB_23e79da15:
          plVar18 = plStack_78;
          lVar17 = auStack_88._0_8_;
          uVar13 = auStack_88._8_8_;
          auStack_88 = (undefined1  [16])0x0;
          plStack_78 = (longlong *)0x0;
          *plVar19 = lVar23 + -1;
          if (lVar23 + -1 == 0) {
            (**(code **)(plVar19[1] + 0x30))(plVar19);
          }
          plStack_78 = (longlong *)0x0;
          auStack_88 = (undefined1  [16])0x0;
          if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
            (**(code **)(plVar20[1] + 0x30))(plVar20);
          }
          if ((plVar21 != (longlong *)0x0) && (*plVar21 = *plVar21 + -1, *plVar21 == 0)) {
            (**(code **)(plVar21[1] + 0x30))(plVar21);
          }
          if ((plVar22 != (longlong *)0x0) && (*plVar22 = *plVar22 + -1, *plVar22 == 0)) {
            (**(code **)(plVar22[1] + 0x30))(plVar22);
          }
          goto LAB_23e79db2a;
        }
        plVar21 = (longlong *)(**(code **)(plVar19[1] + 0xe0))(plVar19);
        if ((plVar21 == (longlong *)0x0) &&
           (plVar21 = (longlong *)FUN_23a3c1b70(param_1,pcStack_c8,1,3), plVar21 == (longlong *)0x0)
           ) {
          lVar23 = *plVar19;
          plVar22 = (longlong *)0x0;
          goto LAB_23e79da15;
        }
        plVar22 = (longlong *)(**(code **)(plVar19[1] + 0xe0))(plVar19);
        if ((plVar22 == (longlong *)0x0) &&
           (plVar22 = (longlong *)FUN_23a3c1b70(param_1,pcStack_c8,2,3), plVar22 == (longlong *)0x0)
           ) {
          lVar23 = *plVar19;
          goto LAB_23e79da15;
        }
        cVar11 = FUN_23a3884a0(param_1,pcStack_c8,plVar19,3);
        lVar23 = *plVar19;
        if (cVar11 == '\0') goto LAB_23e79da15;
        *plVar19 = lVar23 + -1;
        if (lVar23 + -1 == 0) {
          (**(code **)(plVar19[1] + 0x30))(plVar19);
        }
        lVar17 = *plVar20;
        *plVar20 = lVar17 + 1;
        if (plStack_e0 != (longlong *)0x0) {
          *plStack_e0 = *plStack_e0 + -1;
          if (*plStack_e0 == 0) {
            (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
          }
          lVar17 = *plVar20 + -1;
        }
        *plVar20 = lVar17;
        if (lVar17 == 0) {
          (**(code **)(plVar20[1] + 0x30))(plVar20);
        }
        lVar17 = *plVar21;
        *plVar21 = lVar17 + 1;
        if (plStack_d8 != (longlong *)0x0) {
          *plStack_d8 = *plStack_d8 + -1;
          if (*plStack_d8 == 0) {
            (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
          }
          lVar17 = *plVar21 + -1;
        }
        *plVar21 = lVar17;
        if (lVar17 == 0) {
          (**(code **)(plVar21[1] + 0x30))(plVar21);
        }
        lVar17 = *plVar22;
        *plVar22 = lVar17 + 1;
        if (plStack_118 != (longlong *)0x0) {
          lVar17 = *plStack_118;
          *plStack_118 = lVar17 + -1;
          if (lVar17 + -1 == 0) {
            (**(code **)(plStack_118[1] + 0x30))(plStack_118);
          }
          lVar17 = *plVar22 + -1;
        }
        *plVar22 = lVar17;
        if (lVar17 == 0) {
          (**(code **)(plVar22[1] + 0x30))(plVar22);
        }
        lVar17 = FUN_23e8df420();
        plStack_e0 = plVar20;
        plStack_d8 = plVar21;
        plStack_118 = plVar22;
        if (lVar17 == 0) {
          FUN_23e915740(param_1,pcStack_c8,DAT_23eed81a0);
          uVar9 = 0x15a;
          plVar18 = plStack_78;
          lVar17 = auStack_88._0_8_;
          uVar13 = auStack_88._8_8_;
          goto LAB_23e79dd3e;
        }
        plVar19 = (longlong *)FUN_23e8bc2f0(lVar17,_DAT_23eed84d0);
        if (plVar19 == (longlong *)0x0) {
          plVar18 = *(longlong **)(param_1 + 0x70);
          lVar17 = *(longlong *)(param_1 + 0x60);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uVar9 = 0x15a;
          uVar13 = *(undefined8 *)(param_1 + 0x68);
          goto LAB_23e79dd3e;
        }
        plVar20 = (longlong *)FUN_23e8c6640(pcStack_128,plVar20);
        if (plVar20 == (longlong *)0x0) {
LAB_23e79e498:
          auStack_88._0_8_ = *(longlong *)(param_1 + 0x60);
          auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
          plStack_78 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar19 = *plVar19 + -1;
          if (*plVar19 == 0) {
            (**(code **)(plVar19[1] + 0x30))(plVar19);
            uVar9 = 0x15a;
            plVar18 = plStack_78;
            lVar17 = auStack_88._0_8_;
            uVar13 = auStack_88._8_8_;
          }
          else {
            uVar9 = 0x15a;
            plVar18 = plStack_78;
            lVar17 = auStack_88._0_8_;
            uVar13 = auStack_88._8_8_;
          }
          goto LAB_23e79dd3e;
        }
        if ((code *)plVar20[1] == PyLong_Type_exref) {
          plVar22 = (longlong *)
                    (**(code **)(*(longlong *)(PyLong_Type_exref + 0x60) + 0x28))
                              (plVar20,DAT_23eed8230,_Py_NoneStruct_exref);
          lVar17 = *plVar20 + -1;
          if (plVar22 == (longlong *)0x0) {
            *plVar20 = lVar17;
            if (lVar17 == 0) {
              (**(code **)(plVar20[1] + 0x30))(plVar20);
            }
            goto LAB_23e79e57a;
          }
          *plVar20 = lVar17;
          if (lVar17 == 0) {
            (**(code **)(plVar20[1] + 0x30))(plVar20);
          }
        }
        else {
          plVar22 = (longlong *)FUN_23e8c51f0(plVar20);
          *plVar20 = *plVar20 + -1;
          if (*plVar20 == 0) {
            (**(code **)(plVar20[1] + 0x30))(plVar20);
          }
          if (plVar22 == (longlong *)0x0) {
LAB_23e79e57a:
            auStack_88._0_8_ = *(longlong *)(param_1 + 0x60);
            auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
            plStack_78 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar19 = *plVar19 + -1;
            if (*plVar19 == 0) {
              (**(code **)(plVar19[1] + 0x30))(plVar19);
              uVar9 = 0x15a;
              plVar18 = plStack_78;
              lVar17 = auStack_88._0_8_;
              uVar13 = auStack_88._8_8_;
            }
            else {
              uVar9 = 0x15a;
              plVar18 = plStack_78;
              lVar17 = auStack_88._0_8_;
              uVar13 = auStack_88._8_8_;
            }
            goto LAB_23e79dd3e;
          }
        }
        plVar20 = (longlong *)FUN_23e8c6640(plStack_120,plVar21);
        if (plVar20 == (longlong *)0x0) {
LAB_23e79e66a:
          auStack_88._0_8_ = *(longlong *)(param_1 + 0x60);
          auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
          plStack_78 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar19 = *plVar19 + -1;
          if (*plVar19 == 0) {
            (**(code **)(plVar19[1] + 0x30))(plVar19);
          }
          *plVar22 = *plVar22 + -1;
          if (*plVar22 == 0) {
            (**(code **)(plVar22[1] + 0x30))(plVar22);
            uVar9 = 0x15a;
            plVar18 = plStack_78;
            lVar17 = auStack_88._0_8_;
            uVar13 = auStack_88._8_8_;
          }
          else {
            uVar9 = 0x15a;
            plVar18 = plStack_78;
            lVar17 = auStack_88._0_8_;
            uVar13 = auStack_88._8_8_;
          }
        }
        else {
          if ((code *)plVar20[1] == PyLong_Type_exref) {
            plVar21 = (longlong *)
                      (**(code **)(*(longlong *)(PyLong_Type_exref + 0x60) + 0x28))
                                (plVar20,DAT_23eed8230,_Py_NoneStruct_exref);
            lVar17 = *plVar20 + -1;
            if (plVar21 == (longlong *)0x0) {
              *plVar20 = lVar17;
              if (lVar17 == 0) {
                (**(code **)(plVar20[1] + 0x30))(plVar20);
              }
              goto LAB_23e79e66a;
            }
            *plVar20 = lVar17;
            if (lVar17 == 0) {
              (**(code **)(plVar20[1] + 0x30))(plVar20);
            }
          }
          else {
            plVar21 = (longlong *)FUN_23e8c51f0(plVar20);
            *plVar20 = *plVar20 + -1;
            if (*plVar20 == 0) {
              (**(code **)(plVar20[1] + 0x30))(plVar20);
            }
            if (plVar21 == (longlong *)0x0) goto LAB_23e79e66a;
          }
          plVar20 = (longlong *)FUN_23e8c09e0(plVar22);
          *plVar22 = *plVar22 + -1;
          if (*plVar22 == 0) {
            (**(code **)(plVar22[1] + 0x30))(plVar22);
          }
          *plVar21 = *plVar21 + -1;
          if (*plVar21 == 0) {
            (**(code **)(plVar21[1] + 0x30))(plVar21);
          }
          if (plVar20 == (longlong *)0x0) goto LAB_23e79e498;
          *(undefined4 *)(plVar6 + 5) = 0x15a;
          plVar21 = (longlong *)FUN_23e914090(param_1,plVar19,plVar20);
          *plVar19 = *plVar19 + -1;
          if (*plVar19 == 0) {
            (**(code **)(plVar19[1] + 0x30))(plVar19);
          }
          *plVar20 = *plVar20 + -1;
          if (*plVar20 == 0) {
            (**(code **)(plVar20[1] + 0x30))(plVar20);
          }
          if (plVar21 == (longlong *)0x0) {
            lVar17 = *(longlong *)(param_1 + 0x60);
            plVar18 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            uVar9 = 0x15a;
            uVar13 = *(undefined8 *)(param_1 + 0x68);
          }
          else {
            if ((plStack_140 != (longlong *)0x0) &&
               (lVar17 = *plStack_140, *plStack_140 = lVar17 + -1, lVar17 + -1 == 0)) {
              (**(code **)(plStack_140[1] + 0x30))(plStack_140);
            }
            iVar12 = FUN_23e97c060(plVar21,plStack_138);
            pcVar24 = _Py_FalseStruct_exref;
            plStack_140 = plVar21;
            if (iVar12 != -1) {
              if (iVar12 != 1) {
                lVar23 = *(longlong *)(param_1 + 0x10);
                if ((((*(int *)(*(longlong *)(lVar23 + 0x28) + 0x160) == 0) &&
                     (*(int *)(lVar23 + 0x78) == 0)) ||
                    (iVar12 = Py_MakePendingCalls(), -1 < iVar12)) ||
                   (lVar17 = *(longlong *)(param_1 + 0x60), lVar17 == 0)) goto LAB_23e79cb9e;
                goto LAB_23e79d25e;
              }
              *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
              lVar17 = *(longlong *)_Py_FalseStruct_exref;
              *(longlong *)pcVar24 = lVar17 + -1;
              pcVar26 = _Py_TrueStruct_exref;
              if (lVar17 + -1 == 0) {
                (**(code **)(*(longlong *)(pcVar24 + 8) + 0x30))(pcVar24);
                pcVar26 = _Py_TrueStruct_exref;
              }
              goto LAB_23e79e77e;
            }
            lVar17 = *(longlong *)(param_1 + 0x60);
            plVar18 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar9 = 0x15b;
            uVar13 = *(undefined8 *)(param_1 + 0x68);
          }
        }
        goto LAB_23e79dd3e;
      }
      plVar18 = *(longlong **)(param_1 + 0x70);
      lVar17 = *(longlong *)(param_1 + 0x60);
      uVar13 = *(undefined8 *)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e79db2a:
      uVar9 = 0x159;
      goto LAB_23e79dd3e;
    }
    cVar11 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
    if (cVar11 == '\0') goto LAB_23e79ee73;
    plVar18 = plStack_e8;
    pcVar26 = _Py_FalseStruct_exref;
    if (plVar25 != (longlong *)0x0) {
LAB_23e79e77e:
      *plVar25 = *plVar25 + -1;
      plStack_e8 = plVar18;
      if (*plVar25 == 0) {
        (**(code **)(plVar25[1] + 0x30))(plVar25);
      }
    }
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    iVar12 = FUN_23a35f020();
    if (iVar12 == 0) {
      plVar15 = (longlong *)FUN_23e8bc2f0(plVar14,DAT_23eed8108);
      if (plVar15 != (longlong *)0x0) {
        *(undefined4 *)(plVar6 + 5) = 0x160;
        plVar18 = (longlong *)FUN_23e914090(param_1,plVar15,plStack_148);
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) {
          (**(code **)(plVar15[1] + 0x30))();
        }
        if (plVar18 != (longlong *)0x0) {
          *plVar18 = *plVar18 + -1;
          if (*plVar18 == 0) {
            (**(code **)(plVar18[1] + 0x30))();
          }
          goto LAB_23e79e7be;
        }
      }
      lVar17 = *(longlong *)(param_1 + 0x60);
      uVar13 = *(undefined8 *)(param_1 + 0x68);
      plVar18 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar9 = 0x160;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e79ddad;
    }
LAB_23e79e7be:
    lVar17 = *(longlong *)(param_1 + 0x10);
    if ((((*(int *)(*(longlong *)(lVar17 + 0x28) + 0x160) != 0) || (*(int *)(lVar17 + 0x78) != 0))
        && (iVar12 = Py_MakePendingCalls(), iVar12 < 0)) && (*(longlong *)(param_1 + 0x60) != 0)) {
LAB_23e79ec15:
      lVar17 = *(longlong *)(param_1 + 0x60);
      uVar13 = *(undefined8 *)(param_1 + 0x68);
      plVar18 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar9 = 0x153;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e79ddad;
    }
    if (*(int *)(lVar17 + 0x68) == 0) {
      plVar15 = *(longlong **)(param_1 + 0x90);
    }
    else {
      PyEval_SaveThread();
      PyEval_AcquireThread(param_1);
      plVar15 = *(longlong **)(param_1 + 0x90);
    }
    if (plVar15 != (longlong *)0x0) {
      plVar14 = *(longlong **)(param_1 + 0x60);
      plVar18 = *(longlong **)(param_1 + 0x70);
      *(longlong **)(param_1 + 0x60) = plVar15;
      plVar25 = *(longlong **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x90) = 0;
      *plVar15 = *plVar15 + 1;
      *(undefined8 *)(param_1 + 0x68) = 0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
        (**(code **)(plVar14[1] + 0x30))();
      }
      if ((plVar25 != (longlong *)0x0) && (*plVar25 = *plVar25 + -1, *plVar25 == 0)) {
        (**(code **)(plVar25[1] + 0x30))();
      }
      if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
        (**(code **)(plVar18[1] + 0x30))();
      }
      goto LAB_23e79ec15;
    }
    plStack_d0 = plStack_120;
    plVar15 = plStack_148;
    pcVar24 = pcStack_128;
    plStack_c0 = plStack_f0;
  }
  PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
               *(undefined8 *)(plVar16[1] + 0x18));
LAB_23e79e0b1:
  cVar11 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
  if (cVar11 != '\0') {
    if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    lVar17 = *plVar16;
    *plVar16 = lVar17 + -1;
    if (lVar17 + -1 == 0) {
      (**(code **)(plVar16[1] + 0x30))(plVar16);
    }
    *plVar14 = *plVar14 + 1;
    pcStack_c8 = pcVar24;
    goto LAB_23e79ccdd;
  }
  plVar18 = *(longlong **)(param_1 + 0x70);
  plStack_78 = (longlong *)0x0;
  lVar17 = *(longlong *)(param_1 + 0x60);
  uVar13 = *(undefined8 *)(param_1 + 0x68);
  *(undefined8 *)(param_1 + 0x70) = 0;
  plStack_120 = plStack_d0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  auStack_88 = (undefined1  [16])0x0;
  if (plVar15 != (longlong *)0x0) {
    uVar9 = 0x153;
    plStack_148 = plVar15;
    goto LAB_23e79ddad;
  }
  plStack_148 = (longlong *)0x0;
  uVar9 = 0x153;
  goto LAB_23e79dde0;
LAB_23e79cb9e:
  if (*(int *)(lVar23 + 0x68) == 0) {
    plVar18 = *(longlong **)(param_1 + 0x90);
  }
  else {
    PyEval_SaveThread();
    PyEval_AcquireThread(param_1);
    plVar18 = *(longlong **)(param_1 + 0x90);
  }
  if (plVar18 != (longlong *)0x0) {
    plVar14 = *(longlong **)(param_1 + 0x60);
    plVar19 = *(longlong **)(param_1 + 0x68);
    plVar20 = *(longlong **)(param_1 + 0x70);
    *(longlong **)(param_1 + 0x60) = plVar18;
    *(undefined8 *)(param_1 + 0x90) = 0;
    *plVar18 = *plVar18 + 1;
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
      (**(code **)(plVar14[1] + 0x30))();
    }
    if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
      (**(code **)(plVar19[1] + 0x30))(plVar19);
    }
    if ((plVar20 == (longlong *)0x0) || (*plVar20 = *plVar20 + -1, *plVar20 != 0)) {
      lVar17 = *(longlong *)(param_1 + 0x60);
    }
    else {
      (**(code **)(plVar20[1] + 0x30))(plVar20);
      lVar17 = *(longlong *)(param_1 + 0x60);
    }
LAB_23e79d25e:
    plVar18 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar9 = 0x158;
    uVar13 = *(undefined8 *)(param_1 + 0x68);
    goto LAB_23e79dd3e;
  }
  goto LAB_23e79c7ed;
LAB_23e79ee73:
  plVar18 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  lVar17 = *(longlong *)(param_1 + 0x60);
  uVar13 = *(undefined8 *)(param_1 + 0x68);
  plStack_78 = (longlong *)0x0;
  uVar9 = 0x158;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  auStack_88 = (undefined1  [16])0x0;
  if (plVar25 != (longlong *)0x0) {
LAB_23e79dd3e:
    plStack_78 = (longlong *)0x0;
    auStack_88 = (undefined1  [16])0x0;
    *plVar25 = *plVar25 + -1;
    if (*plVar25 == 0) {
      (**(code **)(plVar25[1] + 0x30))(plVar25);
    }
  }
  *plVar15 = *plVar15 + -1;
  pcVar26 = _Py_FalseStruct_exref;
  if (*plVar15 == 0) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
    pcVar26 = _Py_FalseStruct_exref;
  }
LAB_23e79ddad:
  plStack_78 = (longlong *)0x0;
  auStack_88 = (undefined1  [16])0x0;
  lVar23 = *plStack_148;
  *plStack_148 = lVar23 + -1;
  if (lVar23 + -1 == 0) {
    (**(code **)(plStack_148[1] + 0x30))();
  }
LAB_23e79dde0:
  lVar23 = *plVar16;
  *plVar16 = lVar23 + -1;
  if (lVar23 + -1 == 0) {
    (**(code **)(plVar16[1] + 0x30))();
  }
  auStack_88._8_8_ = uVar13;
  auStack_88._0_8_ = lVar17;
  plVar14 = plStack_118;
  plStack_78 = plVar18;
  plStack_118._0_4_ = uVar9;
LAB_23e79d3a0:
  plVar16 = plStack_78;
  plVar15 = DAT_23ed6a4f8;
  if (plStack_78 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar16 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar16;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar15[3] = (longlong)plVar6;
    plVar15[2] = 0;
    *plVar6 = *plVar6 + 1;
    *(undefined4 *)((longlong)plVar15 + 0x24) = plStack_118._0_4_;
    pcVar24 = _PyRuntime_exref;
    *(undefined4 *)(plVar15 + 4) = 0xffffffff;
    lVar17 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar24 + 0x1f8) + 0x10) + 0x2e8);
    lVar23 = plVar15[-1];
    puVar4 = *(undefined8 **)(lVar17 + 8);
    *puVar4 = plVar15 + -2;
    plVar15[-2] = lVar17;
    plVar15[-1] = (ulonglong)((uint)lVar23 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar17 + 8) = plVar15 + -2;
    plVar16 = plVar15;
    if ((plStack_78 != (longlong *)0x0) && (*plStack_78 = *plStack_78 + -1, *plStack_78 == 0)) {
      (**(code **)(plStack_78[1] + 0x30))(plStack_78);
    }
  }
  else if ((longlong *)plStack_78[3] != plVar6) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar18 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar18;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar15[3] = (longlong)plVar6;
    *plVar6 = *plVar6 + 1;
    *(undefined4 *)((longlong)plVar15 + 0x24) = plStack_118._0_4_;
    pcVar24 = _PyRuntime_exref;
    *(undefined4 *)(plVar15 + 4) = 0xffffffff;
    lVar17 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar24 + 0x1f8) + 0x10) + 0x2e8);
    lVar23 = plVar15[-1];
    puVar4 = *(undefined8 **)(lVar17 + 8);
    *puVar4 = plVar15 + -2;
    plVar15[-2] = lVar17;
    plVar15[-1] = (ulonglong)((uint)lVar23 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar17 + 8) = plVar15 + -2;
    plVar15[2] = (longlong)plVar16;
    *plVar16 = *plVar16 + 1;
    plVar16 = plVar15;
    if ((plStack_78 != (longlong *)0x0) && (*plStack_78 = *plStack_78 + -1, *plStack_78 == 0)) {
      (**(code **)(plStack_78[1] + 0x30))();
    }
  }
  plStack_78 = plVar16;
  FUN_23e8bba40(plVar6,"oooooooooooooooo",plVar3,plStack_f8,plVar7,pcVar8,plStack_130,plStack_138,
                plStack_148,pcStack_128,plStack_120,plStack_f0,pcVar26,plStack_e8,plStack_e0,
                plStack_d8,plVar14,plStack_140);
  if (_DAT_23eedac10 == plVar6) {
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    _DAT_23eedac10 = (longlong *)0x0;
  }
  lVar17 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar6 = *(longlong **)(lVar17 + 0x28);
  plVar15 = (longlong *)plVar6[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar17 + 0x30);
  *(undefined4 *)(plVar6 + 8) = 0xffffffff;
  if (plVar15 != (longlong *)0x0) {
    plVar6[2] = 0;
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      (**(code **)(plVar15[1] + 0x30))();
    }
  }
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  plVar15 = plStack_78;
  auVar10 = auStack_88;
  plVar6[0xf] = 0;
  auStack_88 = (undefined1  [16])0x0;
  plStack_78 = (longlong *)0x0;
  if ((plStack_f8 != (longlong *)0x0) &&
     (lVar17 = *plStack_f8, *plStack_f8 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
  }
  if ((plStack_130 != (longlong *)0x0) &&
     (lVar17 = *plStack_130, *plStack_130 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_130[1] + 0x30))();
  }
  if ((plStack_138 != (longlong *)0x0) &&
     (lVar17 = *plStack_138, *plStack_138 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_138[1] + 0x30))(plStack_138);
  }
  if ((plStack_148 != (longlong *)0x0) &&
     (lVar17 = *plStack_148, *plStack_148 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_148[1] + 0x30))(plStack_148);
  }
  if ((pcStack_128 != (code *)0x0) &&
     (lVar17 = *(longlong *)pcStack_128, *(longlong *)pcStack_128 = lVar17 + -1, lVar17 + -1 == 0))
  {
    (**(code **)(*(longlong *)(pcStack_128 + 8) + 0x30))();
  }
  if ((plStack_120 != (longlong *)0x0) &&
     (lVar17 = *plStack_120, *plStack_120 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_120[1] + 0x30))(plStack_120);
  }
  if ((plStack_f0 != (longlong *)0x0) &&
     (lVar17 = *plStack_f0, *plStack_f0 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_f0[1] + 0x30))(plStack_f0);
  }
  if ((pcVar26 != (code *)0x0) &&
     (*(longlong *)pcVar26 = *(longlong *)pcVar26 + -1, *(longlong *)pcVar26 == 0)) {
    (**(code **)(*(longlong *)(pcVar26 + 8) + 0x30))(pcVar26);
  }
  if ((plStack_e8 != (longlong *)0x0) &&
     (lVar17 = *plStack_e8, *plStack_e8 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_e8[1] + 0x30))();
  }
  if ((plStack_e0 != (longlong *)0x0) && (*plStack_e0 = *plStack_e0 + -1, *plStack_e0 == 0)) {
    (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
  }
  if ((plStack_d8 != (longlong *)0x0) && (*plStack_d8 = *plStack_d8 + -1, *plStack_d8 == 0)) {
    (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((plStack_140 != (longlong *)0x0) &&
     (lVar17 = *plStack_140, *plStack_140 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_140[1] + 0x30))(plStack_140);
  }
  lVar17 = *plVar3;
  *plVar3 = lVar17 + -1;
  auStack_88 = auVar10;
  plStack_78 = plVar15;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  lVar17 = *plVar7;
  *plVar7 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  lVar17 = *(longlong *)pcVar8;
  *(longlong *)pcVar8 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    (**(code **)(*(longlong *)(pcVar8 + 8) + 0x30))(pcVar8);
  }
  FUN_23a33aa70(param_1,auStack_88._0_8_,auStack_88._8_8_,plStack_78);
  return (longlong *)0x0;
}
