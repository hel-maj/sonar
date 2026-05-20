/* ===== 23e764e30 workers.fishing.fishing_bot:FishingBot._do_meal_routine ===== */
/* ghidra_name=FUN_23e764e30 entry=23e764e30 size=18767 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e764e30(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 auVar7 [16];
  char cVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  code *pcVar17;
  code *pcVar18;
  longlong *plVar19;
  undefined4 uVar20;
  undefined8 uVar21;
  undefined1 uVar22;
  undefined8 uVar23;
  longlong *plStack_130;
  code *pcStack_128;
  longlong *plStack_120;
  longlong *plStack_118;
  longlong *plStack_110;
  longlong *plStack_108;
  code *pcStack_100;
  code *pcStack_f8;
  undefined1 auStack_d8 [16];
  longlong *plStack_c8;
  undefined8 uStack_b8;
  longlong *plStack_b0;
  code *pcStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_88;
  longlong *plStack_80;
  code *pcStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  
  plVar10 = _DAT_23eedada8;
  plVar1 = (longlong *)*param_3;
  plStack_c8 = (longlong *)0x0;
  auStack_d8 = (undefined1  [16])0x0;
  if (_DAT_23eedada8 == (longlong *)0x0) {
LAB_23e764e8d:
    _DAT_23eedada8 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedaf70,DAT_23eedaeb8,0x74);
  }
  else {
    lVar12 = *_DAT_23eedada8;
    if (1 < lVar12) {
      *_DAT_23eedada8 = lVar12 + -1;
      goto LAB_23e764e8d;
    }
    if (_DAT_23eedada8[2] != 0) {
      *_DAT_23eedada8 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e764e8d;
    }
  }
  plVar3 = _DAT_23eedada8;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eedada8 + 9;
  lVar2 = *(longlong *)(lVar12 + 8);
  _DAT_23eedada8[0xf] = lVar2;
  *(longlong **)(lVar12 + 8) = plVar10;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar21 = DAT_23eed89b0;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,uVar21);
  if (plVar10 == (longlong *)0x0) {
    auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_c8 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (plStack_c8 == (longlong *)0x0) goto LAB_23e766038;
    if ((longlong *)plStack_c8[3] != plVar3) {
      pcStack_128 = (code *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      pcVar17 = (code *)0x0;
      pcStack_100 = (code *)0x0;
      plVar14 = (longlong *)0x0;
      uVar22 = 2;
      uVar20 = 0x479;
      plStack_118 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      goto LAB_23e765f60;
    }
LAB_23e765b10:
    pcStack_128 = (code *)0x0;
    plVar11 = (longlong *)0x0;
    uVar22 = 2;
    plVar10 = (longlong *)0x0;
    pcStack_100 = (code *)0x0;
    pcVar17 = (code *)0x0;
    plVar14 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plVar15 = plStack_c8;
    goto LAB_23e765b77;
  }
  *(undefined4 *)(plVar3 + 5) = 0x479;
  plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar10,DAT_23eed8d38);
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))();
  }
  if (plVar11 == (longlong *)0x0) {
    auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_c8 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (plStack_c8 != (longlong *)0x0) {
      if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e765b10;
      pcStack_128 = (code *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      pcVar17 = (code *)0x0;
      pcStack_100 = (code *)0x0;
      plVar13 = (longlong *)0x0;
      uVar22 = 2;
      uVar20 = 0x479;
      plStack_118 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      goto LAB_23e765f60;
    }
LAB_23e766038:
    pcStack_128 = (code *)0x0;
    plVar11 = (longlong *)0x0;
    uVar22 = 2;
    plVar10 = (longlong *)0x0;
    pcStack_100 = (code *)0x0;
    pcVar17 = (code *)0x0;
    plVar14 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    uVar20 = 0x479;
    plStack_110 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    goto LAB_23e7660a5;
  }
  iVar9 = FUN_23a35f020();
  lVar12 = *plVar11 + -1;
  if (iVar9 == -1) {
    auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_c8 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar11 = lVar12;
    if (lVar12 == 0) {
      (**(code **)(plVar11[1] + 0x30))();
      if (plStack_c8 == (longlong *)0x0) goto LAB_23e766038;
      plVar10 = (longlong *)plStack_c8[3];
    }
    else {
      if (plStack_c8 == (longlong *)0x0) goto LAB_23e766038;
      plVar10 = (longlong *)plStack_c8[3];
    }
    if (plVar3 != plVar10) {
      pcStack_128 = (code *)0x0;
      plVar11 = (longlong *)0x0;
      uVar22 = 2;
      plVar10 = (longlong *)0x0;
      pcStack_100 = (code *)0x0;
      pcVar17 = (code *)0x0;
      plVar14 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      uVar20 = 0x479;
      plStack_110 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      goto LAB_23e765f60;
    }
    goto LAB_23e765b10;
  }
  *plVar11 = lVar12;
  if (lVar12 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  pcStack_100 = _Py_TrueStruct_exref;
  if (iVar9 != 0) {
    plVar14 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    pcStack_f8 = _Py_NoneStruct_exref;
    lVar12 = *(longlong *)_Py_NoneStruct_exref;
    plStack_130 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
LAB_23e764fe8:
    *(longlong *)pcStack_f8 = lVar12 + 1;
    lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar10 = *(longlong **)(lVar12 + 0x28);
    plVar3 = (longlong *)plVar10[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
    *(undefined4 *)(plVar10 + 8) = 0xffffffff;
    if (plVar3 != (longlong *)0x0) {
      plVar10[2] = 0;
      *plVar3 = *plVar3 + -1;
      if (*plVar3 == 0) {
        (**(code **)(plVar3[1] + 0x30))();
      }
    }
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    plVar10[0xf] = 0;
    plVar11 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    pcVar17 = (code *)0x0;
    pcStack_128 = (code *)0x0;
    pcStack_100 = (code *)0x0;
    if (plVar13 == (longlong *)0x0) goto LAB_23e76507d;
    pcStack_100 = (code *)0x0;
LAB_23e765065:
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
LAB_23e76507d:
    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
    if ((plStack_108 != (longlong *)0x0) &&
       (lVar12 = *plStack_108, *plStack_108 = lVar12 + -1, lVar12 + -1 == 0)) {
      (**(code **)(plStack_108[1] + 0x30))(plStack_108);
    }
    if ((plStack_120 != (longlong *)0x0) &&
       (lVar12 = *plStack_120, *plStack_120 = lVar12 + -1, lVar12 + -1 == 0)) {
      (**(code **)(plStack_120[1] + 0x30))(plStack_120);
    }
    if ((plStack_130 != (longlong *)0x0) &&
       (lVar12 = *plStack_130, *plStack_130 = lVar12 + -1, lVar12 + -1 == 0)) {
      (**(code **)(plStack_130[1] + 0x30))(plStack_130);
    }
    if ((plStack_110 != (longlong *)0x0) &&
       (lVar12 = *plStack_110, *plStack_110 = lVar12 + -1, lVar12 + -1 == 0)) {
      (**(code **)(plStack_110[1] + 0x30))(plStack_110);
    }
    if ((plStack_118 != (longlong *)0x0) &&
       (lVar12 = *plStack_118, *plStack_118 = lVar12 + -1, lVar12 + -1 == 0)) {
      (**(code **)(plStack_118[1] + 0x30))(plStack_118);
    }
    if ((pcStack_100 != (code *)0x0) &&
       (*(longlong *)pcStack_100 = *(longlong *)pcStack_100 + -1, *(longlong *)pcStack_100 == 0)) {
      (**(code **)(*(longlong *)(pcStack_100 + 8) + 0x30))(pcStack_100);
    }
    if ((pcVar17 != (code *)0x0) &&
       (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1, *(longlong *)pcVar17 == 0)) {
      (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
    }
    if ((pcStack_128 != (code *)0x0) &&
       (lVar12 = *(longlong *)pcStack_128, *(longlong *)pcStack_128 = lVar12 + -1, lVar12 + -1 == 0)
       ) {
      (**(code **)(*(longlong *)(pcStack_128 + 8) + 0x30))(pcStack_128);
    }
    if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    *plVar1 = *plVar1 + -1;
    if (*plVar1 != 0) {
      return pcStack_f8;
    }
    (**(code **)(plVar1[1] + 0x30))(plVar1);
    return pcStack_f8;
  }
  cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eed89b8,_Py_TrueStruct_exref);
  if (cVar8 == '\0') {
    auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_c8 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (plStack_c8 == (longlong *)0x0) {
      pcStack_128 = (code *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      pcVar17 = (code *)0x0;
      pcStack_100 = (code *)0x0;
      plVar14 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      uVar22 = 2;
      plStack_118 = (longlong *)0x0;
      uVar20 = 0x47b;
      plStack_110 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      goto LAB_23e7660a5;
    }
    if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e765b10;
    pcStack_128 = (code *)0x0;
    plVar11 = (longlong *)0x0;
    uVar22 = 2;
    plVar10 = (longlong *)0x0;
    pcStack_100 = (code *)0x0;
    pcVar17 = (code *)0x0;
    plVar14 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    uVar20 = 0x47b;
    plStack_110 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    goto LAB_23e765f60;
  }
  lVar12 = FUN_23e8e0e20();
  if (lVar12 == 0) {
    FUN_23e915740(param_1,auStack_d8,DAT_23eed8988);
    if (plStack_c8 != (longlong *)0x0) {
      plVar10 = (longlong *)plStack_c8[3];
joined_r0x00023e7664c4:
      if (plVar3 == plVar10) goto LAB_23e765b10;
      plVar13 = (longlong *)0x0;
      pcStack_128 = (code *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      pcVar17 = (code *)0x0;
      pcStack_100 = (code *)0x0;
      plVar14 = (longlong *)0x0;
      uVar22 = 2;
      uVar20 = 0x47c;
      plStack_118 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      goto LAB_23e765f60;
    }
LAB_23e766898:
    pcStack_128 = (code *)0x0;
    plVar11 = (longlong *)0x0;
    uVar22 = 2;
    plVar10 = (longlong *)0x0;
    pcStack_100 = (code *)0x0;
    pcVar17 = (code *)0x0;
    plVar14 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    uVar20 = 0x47c;
    plStack_110 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
LAB_23e7660a5:
    plVar15 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      plVar16 = plStack_c8;
    }
    else {
      plVar16 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar16;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar16 = (longlong *)0x0;
    }
    pcVar18 = _PyRuntime_exref;
    plVar15[2] = 0;
    plVar15[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar12 = *(longlong *)(pcVar18 + 0x1f8);
    *(undefined4 *)((longlong)plVar15 + 0x24) = uVar20;
    lVar12 = *(longlong *)(lVar12 + 0x10);
    *(undefined4 *)(plVar15 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(lVar12 + 0x2e8);
    lVar2 = plVar15[-1];
    puVar4 = *(undefined8 **)(lVar12 + 8);
    *puVar4 = plVar15 + -2;
    plVar15[-2] = lVar12;
    plVar15[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar12 + 8) = plVar15 + -2;
  }
  else {
    plVar10 = (longlong *)FUN_23e8bc2f0(lVar12,_DAT_23eed9328);
    if (plVar10 == (longlong *)0x0) {
      auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_c8 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plStack_c8 != (longlong *)0x0) {
        plVar10 = (longlong *)plStack_c8[3];
        goto joined_r0x00023e7664c4;
      }
      goto LAB_23e766898;
    }
    cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eed8998,plVar10);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))();
    }
    if (cVar8 == '\0') {
      auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_c8 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plStack_c8 == (longlong *)0x0) goto LAB_23e766898;
      if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e765b10;
      pcStack_128 = (code *)0x0;
      plVar11 = (longlong *)0x0;
      uVar22 = 2;
      plVar10 = (longlong *)0x0;
      pcStack_100 = (code *)0x0;
      pcVar17 = (code *)0x0;
      plVar14 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      uVar20 = 0x47c;
      plStack_110 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      goto LAB_23e765f60;
    }
    *(undefined4 *)(plVar3 + 5) = 0x47d;
    plVar10 = (longlong *)FUN_23e915840(param_1,plVar1,DAT_23eed8b40);
    if (plVar10 == (longlong *)0x0) {
      auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_c8 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plStack_c8 != (longlong *)0x0) {
        if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e765b10;
        pcStack_128 = (code *)0x0;
        plVar11 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        pcVar17 = (code *)0x0;
        pcStack_100 = (code *)0x0;
        plVar14 = (longlong *)0x0;
        uVar22 = 2;
        uVar20 = 0x47d;
        plStack_118 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        goto LAB_23e765f60;
      }
      pcStack_128 = (code *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      pcVar17 = (code *)0x0;
      pcStack_100 = (code *)0x0;
      plVar14 = (longlong *)0x0;
      uVar22 = 2;
      uVar20 = 0x47d;
      plStack_118 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      goto LAB_23e7660a5;
    }
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    *(undefined4 *)(plVar3 + 5) = 0x47f;
    plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eed9318);
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      *(undefined4 *)(plVar3 + 5) = 0x480;
      plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eed9320);
      if (plVar10 == (longlong *)0x0) {
        auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_c8 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (plStack_c8 == (longlong *)0x0) {
          plVar11 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          pcStack_128 = (code *)0x0;
          pcVar17 = (code *)0x0;
          plVar14 = (longlong *)0x0;
          uVar22 = 2;
          pcStack_100 = (code *)0x0;
          uVar20 = 0x480;
          plStack_118 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          goto LAB_23e7660a5;
        }
        if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e765b10;
        pcStack_128 = (code *)0x0;
        plVar11 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        pcVar17 = (code *)0x0;
        pcStack_100 = (code *)0x0;
        plVar14 = (longlong *)0x0;
        uVar22 = 2;
        uVar20 = 0x480;
        plStack_118 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        goto LAB_23e765f60;
      }
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      lVar12 = FUN_23e8e0120();
      if (lVar12 == 0) {
        FUN_23e915740(param_1,auStack_d8,_DAT_23eed9380);
        if (plStack_c8 == (longlong *)0x0) {
LAB_23e76722f:
          pcStack_128 = (code *)0x0;
          plVar11 = (longlong *)0x0;
          uVar22 = 2;
          plVar10 = (longlong *)0x0;
          pcStack_100 = (code *)0x0;
          pcVar17 = (code *)0x0;
          plVar14 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          uVar20 = 0x483;
          plStack_110 = (longlong *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          goto LAB_23e7660a5;
        }
        plVar10 = (longlong *)plStack_c8[3];
        plVar13 = (longlong *)0x0;
joined_r0x00023e766936:
        if (plVar3 == plVar10) goto LAB_23e765b10;
        pcStack_128 = (code *)0x0;
        plVar11 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        pcVar17 = (code *)0x0;
        pcStack_100 = (code *)0x0;
        plVar14 = (longlong *)0x0;
        uVar22 = 2;
        uVar20 = 0x483;
        plStack_118 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        goto LAB_23e765f60;
      }
      *(undefined4 *)(plVar3 + 5) = 0x483;
      plVar13 = (longlong *)FUN_23e91a870(param_1,lVar12);
      if (plVar13 == (longlong *)0x0) {
        auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_c8 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (plStack_c8 == (longlong *)0x0) goto LAB_23e76722f;
        plVar10 = (longlong *)plStack_c8[3];
        goto joined_r0x00023e766936;
      }
      plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a98);
      if (plVar10 == (longlong *)0x0) {
        auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_c8 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (plStack_c8 != (longlong *)0x0) {
          if (plVar3 == (longlong *)plStack_c8[3]) goto LAB_23e7666d5;
          pcStack_128 = (code *)0x0;
          plVar11 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          pcVar17 = (code *)0x0;
          pcStack_100 = (code *)0x0;
          uVar22 = 2;
          uVar20 = 0x486;
          plStack_118 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          goto LAB_23e765f60;
        }
LAB_23e7671c0:
        pcStack_128 = (code *)0x0;
        plVar11 = (longlong *)0x0;
        uVar22 = 2;
        plVar10 = (longlong *)0x0;
        pcStack_100 = (code *)0x0;
        pcVar17 = (code *)0x0;
        plVar14 = (longlong *)0x0;
        uVar20 = 0x486;
        plStack_118 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        goto LAB_23e7660a5;
      }
      cVar8 = FUN_23e8d9ac0(plVar13,DAT_23eed8a98,plVar10);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))();
      }
      if (cVar8 == '\0') {
        auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_c8 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (plStack_c8 == (longlong *)0x0) goto LAB_23e7671c0;
        plVar11 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        plVar16 = (longlong *)plStack_c8[3];
        uVar22 = 2;
        pcStack_128 = (code *)0x0;
        uVar20 = 0x486;
        pcVar17 = (code *)0x0;
        plVar14 = (longlong *)0x0;
        pcStack_100 = (code *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        goto joined_r0x00023e76916c;
      }
      plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8aa8);
      if (plVar10 == (longlong *)0x0) {
        auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_c8 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (plStack_c8 != (longlong *)0x0) {
          if (plVar3 == (longlong *)plStack_c8[3]) goto LAB_23e7666d5;
          pcStack_128 = (code *)0x0;
          plVar11 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          pcVar17 = (code *)0x0;
          pcStack_100 = (code *)0x0;
          uVar22 = 2;
          uVar20 = 0x487;
          plStack_118 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          goto LAB_23e765f60;
        }
LAB_23e767503:
        pcStack_128 = (code *)0x0;
        plVar11 = (longlong *)0x0;
        uVar22 = 2;
        plVar10 = (longlong *)0x0;
        pcStack_100 = (code *)0x0;
        pcVar17 = (code *)0x0;
        plVar14 = (longlong *)0x0;
        uVar20 = 0x487;
        plStack_118 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
      }
      else {
        iVar9 = FUN_23e913250(plVar10,DAT_23eed90d8);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))();
        }
        if (iVar9 == -1) {
          auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_c8 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (plStack_c8 != (longlong *)0x0) {
            plVar10 = (longlong *)plStack_c8[3];
joined_r0x00023e7666cf:
            if (plVar10 != plVar3) {
              pcStack_128 = (code *)0x0;
              plVar11 = (longlong *)0x0;
              uVar22 = 2;
              plVar10 = (longlong *)0x0;
              pcStack_100 = (code *)0x0;
              pcVar17 = (code *)0x0;
              plVar14 = (longlong *)0x0;
              uVar20 = 0x487;
              plStack_118 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              goto LAB_23e765f60;
            }
LAB_23e7666d5:
            pcStack_128 = (code *)0x0;
            plVar11 = (longlong *)0x0;
            uVar22 = 2;
            plVar10 = (longlong *)0x0;
            pcStack_100 = (code *)0x0;
            pcVar17 = (code *)0x0;
            plVar14 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plVar15 = plStack_c8;
            goto LAB_23e765b77;
          }
          goto LAB_23e767503;
        }
        cVar8 = FUN_23e8d9ac0(plVar13,DAT_23eed9390);
        if (cVar8 == '\0') {
          auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_c8 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (plStack_c8 != (longlong *)0x0) {
            plVar10 = (longlong *)plStack_c8[3];
            goto joined_r0x00023e7666cf;
          }
          goto LAB_23e767503;
        }
        plVar14 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8aa8);
        if (plVar14 == (longlong *)0x0) {
          auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_c8 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (plStack_c8 != (longlong *)0x0) {
            if (plVar3 != (longlong *)plStack_c8[3]) {
              pcStack_128 = (code *)0x0;
              plVar11 = (longlong *)0x0;
              plVar10 = (longlong *)0x0;
              pcVar17 = (code *)0x0;
              pcStack_100 = (code *)0x0;
              uVar22 = 2;
              uVar20 = 0x48a;
              plStack_118 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              goto LAB_23e765f60;
            }
            goto LAB_23e7666d5;
          }
LAB_23e7684ef:
          uVar22 = 2;
          plVar11 = (longlong *)0x0;
          pcStack_128 = (code *)0x0;
          plVar10 = (longlong *)0x0;
          pcVar17 = (code *)0x0;
          plVar14 = (longlong *)0x0;
          pcStack_100 = (code *)0x0;
          uVar20 = 0x48a;
          plStack_118 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
        }
        else {
          iVar9 = FUN_23e913250(plVar14,DAT_23eed90d8);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))();
          }
          pcStack_f8 = _Py_NoneStruct_exref;
          uVar6 = _DAT_23eed93e0;
          uVar5 = _DAT_23eed93a0;
          uVar23 = _DAT_23eed9398;
          plVar11 = DAT_23eed8950;
          uVar21 = DAT_23ed6ccf0;
          plVar10 = DAT_23ed6a498;
          if (iVar9 == -1) {
            auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
            plStack_c8 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (plStack_c8 != (longlong *)0x0) {
              if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e7666d5;
              uVar22 = 2;
              plVar11 = (longlong *)0x0;
              pcStack_128 = (code *)0x0;
              plVar10 = (longlong *)0x0;
              pcVar17 = (code *)0x0;
              plVar14 = (longlong *)0x0;
              pcStack_100 = (code *)0x0;
              uVar20 = 0x48a;
              plStack_118 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              goto LAB_23e765f60;
            }
            goto LAB_23e7684ef;
          }
          if (iVar9 != 1) {
            *(undefined4 *)(plVar3 + 5) = 0x491;
            uStack_68 = uVar21;
            pcStack_78 = pcStack_f8;
            uStack_70 = uVar6;
            uStack_88 = uVar23;
            plStack_80 = plVar11;
            if (plVar10 == (longlong *)0x0) {
              plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"__import__");
              if (plVar10 != (longlong *)0x0) {
                *plVar10 = *plVar10 + 1;
                DAT_23ed6a498 = plVar10;
                goto LAB_23e765585;
              }
LAB_23e7682c4:
              PyErr_PrintEx(0,0);
              Py_Exit();
LAB_23e7682d7:
              plVar11 = (longlong *)0x0;
              plVar10 = (longlong *)0x0;
              pcVar17 = (code *)0x0;
              pcStack_128 = (code *)0x0;
              uVar22 = 2;
              uVar20 = 0x48b;
              pcStack_100 = (code *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              goto LAB_23e7660a5;
            }
LAB_23e765585:
            plVar10 = (longlong *)FUN_23e95b390(param_1,plVar10,&uStack_88);
            pcVar17 = PyModule_Type_exref;
            if (plVar10 != (longlong *)0x0) {
              if (((code *)plVar10[1] == PyModule_Type_exref) ||
                 (iVar9 = PyType_IsSubtype((code *)plVar10[1],PyModule_Type_exref),
                 pcVar18 = PyObject_GetAttr_exref, uVar21 = _DAT_23eed93e8, iVar9 != 0)) {
                pcVar18 = PyObject_GetAttr_exref;
                uVar23 = _DAT_23eed93e8;
                plVar11 = DAT_23eed8950;
                uVar21 = DAT_23ed6ccf0;
                plStack_130 = (longlong *)PyObject_GetAttr(plVar10,_DAT_23eed93e8);
                if (plStack_130 != (longlong *)0x0) goto LAB_23e7655fe;
                plStack_130 = (longlong *)FUN_23e970390(param_1,plVar10,plVar11,uVar23,uVar21);
LAB_23e766b17:
                if (plStack_130 != (longlong *)0x0) goto LAB_23e7655fe;
                uVar21 = *(undefined8 *)(param_1 + 0x60);
                uVar23 = *(undefined8 *)(param_1 + 0x68);
                plVar15 = *(longlong **)(param_1 + 0x70);
                plStack_110 = (longlong *)0x0;
              }
              else {
                plStack_130 = (longlong *)PyObject_GetAttr(plVar10,_DAT_23eed93e8);
                if (plStack_130 == (longlong *)0x0) {
                  plStack_130 = (longlong *)FUN_23e8d2cf0(param_1,plVar10,uVar21);
                  goto LAB_23e766b17;
                }
LAB_23e7655fe:
                if (((code *)plVar10[1] != pcVar17) &&
                   (iVar9 = PyType_IsSubtype((code *)plVar10[1],pcVar17), uVar21 = _DAT_23eed93f0,
                   iVar9 == 0)) {
                  plStack_110 = (longlong *)(*pcVar18)(plVar10,_DAT_23eed93f0);
                  if (plStack_110 == (longlong *)0x0) {
                    plStack_110 = (longlong *)FUN_23e8d2cf0(param_1,plVar10,uVar21);
                    goto LAB_23e766c53;
                  }
LAB_23e76564d:
                  if (((code *)plVar10[1] == pcVar17) ||
                     (iVar9 = PyType_IsSubtype((code *)plVar10[1],pcVar17), uVar21 = _DAT_23eed93f8,
                     iVar9 != 0)) {
                    uVar23 = _DAT_23eed93f8;
                    plVar11 = DAT_23eed8950;
                    uVar21 = DAT_23ed6ccf0;
                    plStack_118 = (longlong *)(*pcVar18)(plVar10,_DAT_23eed93f8);
                    if (plStack_118 == (longlong *)0x0) {
                      plStack_118 = (longlong *)FUN_23e970390(param_1,plVar10,plVar11,uVar23,uVar21)
                      ;
                      goto LAB_23e766d85;
                    }
                  }
                  else {
                    plStack_118 = (longlong *)(*pcVar18)(plVar10,_DAT_23eed93f8);
                    if (plStack_118 == (longlong *)0x0) {
                      plStack_118 = (longlong *)FUN_23e8d2cf0(param_1,plVar10,uVar21);
LAB_23e766d85:
                      if (plStack_118 == (longlong *)0x0) goto LAB_23e766c62;
                    }
                  }
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  cVar8 = FUN_23e8d9ac0(plVar13,_DAT_23eed93c0,plStack_130);
                  if (cVar8 == '\0') {
                    auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_c8 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (plStack_c8 == (longlong *)0x0) {
                      plVar10 = (longlong *)0x0;
                      uVar22 = 2;
                      pcStack_128 = (code *)0x0;
                      uVar20 = 0x492;
                      pcVar17 = (code *)0x0;
                      pcStack_100 = (code *)0x0;
                      plStack_120 = (longlong *)0x0;
                      plStack_108 = (longlong *)0x0;
                      plVar14 = (longlong *)0x0;
                      plVar11 = (longlong *)0x0;
                      goto LAB_23e7660a5;
                    }
                    if ((longlong *)plStack_c8[3] == plVar3) {
LAB_23e7673e0:
                      pcStack_128 = (code *)0x0;
                      plVar11 = (longlong *)0x0;
                      uVar22 = 2;
                      plVar10 = (longlong *)0x0;
                      pcStack_100 = (code *)0x0;
                      pcVar17 = (code *)0x0;
                      plVar14 = (longlong *)0x0;
                      plStack_120 = (longlong *)0x0;
                      plStack_108 = (longlong *)0x0;
                      plVar15 = plStack_c8;
                      goto LAB_23e765b77;
                    }
                    uVar22 = 2;
                    plVar11 = (longlong *)0x0;
                    pcStack_128 = (code *)0x0;
                    plVar10 = (longlong *)0x0;
                    pcVar17 = (code *)0x0;
                    pcStack_100 = (code *)0x0;
                    plVar14 = (longlong *)0x0;
                    uVar20 = 0x492;
                    plStack_120 = (longlong *)0x0;
                    plStack_108 = (longlong *)0x0;
                  }
                  else {
                    cVar8 = FUN_23e8d9ac0(plVar13,_DAT_23eed93c8,plStack_110);
                    if (cVar8 == '\0') {
                      auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                      plStack_c8 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      if (plStack_c8 == (longlong *)0x0) {
                        plVar10 = (longlong *)0x0;
                        pcVar17 = (code *)0x0;
                        pcStack_100 = (code *)0x0;
                        plVar14 = (longlong *)0x0;
                        uVar20 = 0x493;
                        plStack_120 = (longlong *)0x0;
                        plStack_108 = (longlong *)0x0;
                        uVar22 = 2;
                        pcStack_128 = (code *)0x0;
                        plVar11 = (longlong *)0x0;
                        goto LAB_23e7660a5;
                      }
                      if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e7673e0;
                      uVar22 = 2;
                      pcStack_100 = (code *)0x0;
                      plVar11 = (longlong *)0x0;
                      plVar10 = (longlong *)0x0;
                      pcVar17 = (code *)0x0;
                      plStack_120 = (longlong *)0x0;
                      plVar14 = (longlong *)0x0;
                      plStack_108 = (longlong *)0x0;
                      uVar20 = 0x493;
                      pcStack_128 = (code *)0x0;
                    }
                    else {
                      cVar8 = FUN_23e8d9ac0(plVar13,_DAT_23eed93d0);
                      if (cVar8 == '\0') {
                        auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                        plStack_c8 = *(longlong **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        if (plStack_c8 == (longlong *)0x0) {
                          plVar10 = (longlong *)0x0;
                          pcVar17 = (code *)0x0;
                          pcStack_128 = (code *)0x0;
                          plVar14 = (longlong *)0x0;
                          uVar22 = 2;
                          uVar20 = 0x494;
                          pcStack_100 = (code *)0x0;
                          plStack_120 = (longlong *)0x0;
                          plStack_108 = (longlong *)0x0;
                          plVar11 = (longlong *)0x0;
                          goto LAB_23e7660a5;
                        }
                        if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e7673e0;
                        uVar22 = 2;
                        pcStack_128 = (code *)0x0;
                        plVar11 = (longlong *)0x0;
                        plVar10 = (longlong *)0x0;
                        pcVar17 = (code *)0x0;
                        pcStack_100 = (code *)0x0;
                        plVar14 = (longlong *)0x0;
                        uVar20 = 0x494;
                        plStack_120 = (longlong *)0x0;
                        plStack_108 = (longlong *)0x0;
                      }
                      else {
                        cVar8 = FUN_23e8d9ac0(plVar13,_DAT_23eed93d8,DAT_23ed6cd28);
                        if (cVar8 != '\0') {
                          plStack_120 = (longlong *)0x0;
                          plVar14 = (longlong *)0x0;
                          plStack_108 = (longlong *)0x0;
                          goto LAB_23e765736;
                        }
                        auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                        plStack_c8 = *(longlong **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        if (plStack_c8 == (longlong *)0x0) {
                          plVar10 = (longlong *)0x0;
                          pcVar17 = (code *)0x0;
                          pcStack_128 = (code *)0x0;
                          plVar14 = (longlong *)0x0;
                          uVar22 = 2;
                          uVar20 = 0x495;
                          pcStack_100 = (code *)0x0;
                          plStack_120 = (longlong *)0x0;
                          plStack_108 = (longlong *)0x0;
                          plVar11 = (longlong *)0x0;
                          goto LAB_23e7660a5;
                        }
                        if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e7673e0;
                        uVar22 = 2;
                        pcStack_100 = (code *)0x0;
                        plVar11 = (longlong *)0x0;
                        plVar10 = (longlong *)0x0;
                        pcVar17 = (code *)0x0;
                        plStack_120 = (longlong *)0x0;
                        uVar20 = 0x495;
                        plStack_108 = (longlong *)0x0;
                        plVar14 = (longlong *)0x0;
                        pcStack_128 = (code *)0x0;
                      }
                    }
                  }
                  goto LAB_23e765f60;
                }
                uVar23 = _DAT_23eed93f0;
                plVar11 = DAT_23eed8950;
                uVar21 = DAT_23ed6ccf0;
                plStack_110 = (longlong *)(*pcVar18)(plVar10,_DAT_23eed93f0);
                if (plStack_110 != (longlong *)0x0) goto LAB_23e76564d;
                plStack_110 = (longlong *)FUN_23e970390(param_1,plVar10,plVar11,uVar23,uVar21);
LAB_23e766c53:
                if (plStack_110 != (longlong *)0x0) goto LAB_23e76564d;
LAB_23e766c62:
                uVar21 = *(undefined8 *)(param_1 + 0x60);
                uVar23 = *(undefined8 *)(param_1 + 0x68);
                plVar15 = *(longlong **)(param_1 + 0x70);
              }
              *(undefined8 *)(param_1 + 0x70) = 0;
              plStack_c8 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              auStack_d8 = (undefined1  [16])0x0;
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                FUN_23a334bc0();
              }
              auStack_d8._8_8_ = uVar23;
              auStack_d8._0_8_ = uVar21;
              plStack_c8 = plVar15;
              if (plVar15 == (longlong *)0x0) {
                plVar11 = (longlong *)0x0;
                plVar10 = (longlong *)0x0;
                pcVar17 = (code *)0x0;
                pcStack_128 = (code *)0x0;
                uVar22 = 2;
                uVar20 = 0x491;
                pcStack_100 = (code *)0x0;
                plStack_118 = (longlong *)0x0;
                plStack_120 = (longlong *)0x0;
                plStack_108 = (longlong *)0x0;
                plVar14 = (longlong *)0x0;
                goto LAB_23e7660a5;
              }
              if ((longlong *)plVar15[3] == plVar3) {
                uVar22 = 2;
                plVar11 = (longlong *)0x0;
                plVar10 = (longlong *)0x0;
                pcStack_128 = (code *)0x0;
                pcVar17 = (code *)0x0;
                plVar14 = (longlong *)0x0;
                pcStack_100 = (code *)0x0;
                plStack_118 = (longlong *)0x0;
                plStack_120 = (longlong *)0x0;
                plStack_108 = (longlong *)0x0;
                goto LAB_23e765b77;
              }
              uVar22 = 2;
              plVar11 = (longlong *)0x0;
              pcStack_128 = (code *)0x0;
              plVar10 = (longlong *)0x0;
              pcVar17 = (code *)0x0;
              pcStack_100 = (code *)0x0;
              plVar14 = (longlong *)0x0;
              uVar20 = 0x491;
              plStack_118 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              goto LAB_23e765f60;
            }
            auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
            plStack_c8 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (plStack_c8 == (longlong *)0x0) {
              plVar10 = (longlong *)0x0;
              pcVar17 = (code *)0x0;
              uVar22 = 2;
              pcStack_128 = (code *)0x0;
              uVar20 = 0x491;
              pcStack_100 = (code *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plVar11 = (longlong *)0x0;
              plVar14 = (longlong *)0x0;
              goto LAB_23e7660a5;
            }
            if ((longlong *)plStack_c8[3] != plVar3) {
              plVar10 = (longlong *)0x0;
              pcStack_128 = (code *)0x0;
              pcVar17 = (code *)0x0;
              uVar22 = 2;
              uVar20 = 0x491;
              pcStack_100 = (code *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plVar14 = (longlong *)0x0;
              plVar11 = (longlong *)0x0;
              goto LAB_23e765f60;
            }
            plVar10 = (longlong *)0x0;
            pcVar17 = (code *)0x0;
            plVar14 = (longlong *)0x0;
            pcStack_128 = (code *)0x0;
            pcStack_100 = (code *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
LAB_23e7683e2:
            uVar22 = 2;
            plVar15 = plStack_c8;
            goto LAB_23e765b77;
          }
          *(undefined4 *)(plVar3 + 5) = 0x48b;
          uStack_98 = uVar21;
          pcStack_a8 = pcStack_f8;
          uStack_a0 = uVar5;
          uStack_b8 = uVar23;
          plStack_b0 = plVar11;
          if (plVar10 == (longlong *)0x0) {
            plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"__import__");
            if (plVar10 == (longlong *)0x0) goto LAB_23e7682c4;
            *plVar10 = *plVar10 + 1;
            DAT_23ed6a498 = plVar10;
          }
          plVar10 = (longlong *)FUN_23e95b390(param_1,plVar10,&uStack_b8);
          pcVar17 = PyModule_Type_exref;
          if (plVar10 == (longlong *)0x0) {
            auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
            plStack_c8 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (plStack_c8 == (longlong *)0x0) {
              plVar11 = (longlong *)0x0;
              plVar10 = (longlong *)0x0;
              pcVar17 = (code *)0x0;
              pcStack_128 = (code *)0x0;
              uVar22 = 2;
              uVar20 = 0x48b;
              pcStack_100 = (code *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              plVar14 = (longlong *)0x0;
              goto LAB_23e7660a5;
            }
            if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e7666d5;
            plVar11 = (longlong *)0x0;
            pcStack_100 = (code *)0x0;
            plVar10 = (longlong *)0x0;
            pcVar17 = (code *)0x0;
            plVar14 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            uVar20 = 0x48b;
            plStack_110 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            uVar22 = 2;
            pcStack_128 = (code *)0x0;
            plStack_130 = (longlong *)0x0;
            goto LAB_23e765f60;
          }
          if (((code *)plVar10[1] != PyModule_Type_exref) &&
             (iVar9 = PyType_IsSubtype((code *)plVar10[1],PyModule_Type_exref), iVar9 == 0)) {
            plVar14 = (longlong *)FUN_23e8d2f70();
LAB_23e766e46:
            if (plVar14 != (longlong *)0x0) goto LAB_23e766e4f;
            plStack_120 = *(longlong **)(param_1 + 0x70);
            uVar21 = *(undefined8 *)(param_1 + 0x60);
            uVar23 = *(undefined8 *)(param_1 + 0x68);
            plStack_108 = (longlong *)0x0;
LAB_23e767795:
            *(undefined8 *)(param_1 + 0x70) = 0;
            plStack_c8 = (longlong *)0x0;
            lVar12 = *plVar10;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            auStack_d8 = (undefined1  [16])0x0;
            *plVar10 = lVar12 + -1;
            if (lVar12 + -1 == 0) {
              FUN_23a334bc0();
            }
            auStack_d8._8_8_ = uVar23;
            auStack_d8._0_8_ = uVar21;
            plStack_c8 = plStack_120;
            if (plStack_120 != (longlong *)0x0) {
              if ((longlong *)plStack_120[3] == plVar3) {
                uVar22 = 2;
                plVar11 = (longlong *)0x0;
                pcStack_128 = (code *)0x0;
                plVar10 = (longlong *)0x0;
                pcVar17 = (code *)0x0;
                pcStack_100 = (code *)0x0;
                plStack_118 = (longlong *)0x0;
                plStack_110 = (longlong *)0x0;
                plStack_130 = (longlong *)0x0;
                plStack_120 = (longlong *)0x0;
                plVar15 = plStack_c8;
                goto LAB_23e765b77;
              }
              plVar11 = (longlong *)0x0;
              pcStack_128 = (code *)0x0;
              uVar22 = 2;
              plVar10 = (longlong *)0x0;
              pcVar17 = (code *)0x0;
              pcStack_100 = (code *)0x0;
              uVar20 = 0x48b;
              plStack_118 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              goto LAB_23e765f60;
            }
            goto LAB_23e7682d7;
          }
          uVar23 = _DAT_23eed93a8;
          plVar11 = DAT_23eed8950;
          uVar21 = DAT_23ed6ccf0;
          plVar14 = (longlong *)PyObject_GetAttr(plVar10,_DAT_23eed93a8);
          if (plVar14 == (longlong *)0x0) {
            plVar14 = (longlong *)FUN_23e970390(param_1,plVar10,plVar11,uVar23,uVar21);
            goto LAB_23e766e46;
          }
LAB_23e766e4f:
          if (((code *)plVar10[1] != pcVar17) &&
             (iVar9 = PyType_IsSubtype((code *)plVar10[1],pcVar17), iVar9 == 0)) {
            plStack_108 = (longlong *)FUN_23e8d2f70(param_1,plVar10);
LAB_23e766e94:
            if (plStack_108 != (longlong *)0x0) goto LAB_23e766ea3;
LAB_23e767784:
            plStack_120 = *(longlong **)(param_1 + 0x70);
            uVar21 = *(undefined8 *)(param_1 + 0x60);
            uVar23 = *(undefined8 *)(param_1 + 0x68);
            goto LAB_23e767795;
          }
          uVar23 = _DAT_23eed93b0;
          plVar11 = DAT_23eed8950;
          uVar21 = DAT_23ed6ccf0;
          plStack_108 = (longlong *)PyObject_GetAttr(plVar10,_DAT_23eed93b0);
          if (plStack_108 == (longlong *)0x0) {
            plStack_108 = (longlong *)FUN_23e970390(param_1,plVar10,plVar11,uVar23,uVar21);
            goto LAB_23e766e94;
          }
LAB_23e766ea3:
          if (((code *)plVar10[1] == pcVar17) ||
             (iVar9 = PyType_IsSubtype((code *)plVar10[1],pcVar17), iVar9 != 0)) {
            uVar23 = _DAT_23eed93b8;
            plVar11 = DAT_23eed8950;
            uVar21 = DAT_23ed6ccf0;
            plStack_120 = (longlong *)PyObject_GetAttr(plVar10,_DAT_23eed93b8);
            if (plStack_120 == (longlong *)0x0) {
              plStack_120 = (longlong *)FUN_23e970390(param_1,plVar10,plVar11,uVar23,uVar21);
              goto LAB_23e766ee8;
            }
          }
          else {
            plStack_120 = (longlong *)FUN_23e8d2f70(param_1,plVar10);
LAB_23e766ee8:
            if (plStack_120 == (longlong *)0x0) goto LAB_23e767784;
          }
          lVar12 = *plVar10;
          *plVar10 = lVar12 + -1;
          if (lVar12 + -1 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          cVar8 = FUN_23e8d9ac0(plVar13,_DAT_23eed93c0,plVar14);
          if (cVar8 == '\0') {
            auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
            plStack_c8 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (plStack_c8 != (longlong *)0x0) {
              if ((longlong *)plStack_c8[3] == plVar3) {
LAB_23e76788f:
                uVar22 = 2;
                plVar11 = (longlong *)0x0;
                pcStack_128 = (code *)0x0;
                plVar10 = (longlong *)0x0;
                pcVar17 = (code *)0x0;
                pcStack_100 = (code *)0x0;
                plStack_118 = (longlong *)0x0;
                plStack_110 = (longlong *)0x0;
                plStack_130 = (longlong *)0x0;
                plVar15 = plStack_c8;
                goto LAB_23e765b77;
              }
              uVar22 = 2;
              plVar11 = (longlong *)0x0;
              pcStack_128 = (code *)0x0;
              plVar10 = (longlong *)0x0;
              pcVar17 = (code *)0x0;
              pcStack_100 = (code *)0x0;
              uVar20 = 0x48c;
              plStack_118 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              goto LAB_23e765f60;
            }
            plVar10 = (longlong *)0x0;
            pcVar17 = (code *)0x0;
            pcStack_128 = (code *)0x0;
            uVar20 = 0x48c;
            uVar22 = 2;
            pcStack_100 = (code *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_130 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            goto LAB_23e7660a5;
          }
          cVar8 = FUN_23e8d9ac0(plVar13,_DAT_23eed93c8,plStack_108);
          if (cVar8 == '\0') {
            auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
            plStack_c8 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (plStack_c8 == (longlong *)0x0) {
              plVar10 = (longlong *)0x0;
              pcVar17 = (code *)0x0;
              pcStack_128 = (code *)0x0;
              uVar22 = 2;
              uVar20 = 0x48d;
              pcStack_100 = (code *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              plVar11 = (longlong *)0x0;
              goto LAB_23e7660a5;
            }
            if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e76788f;
            uVar22 = 2;
            plVar11 = (longlong *)0x0;
            pcStack_128 = (code *)0x0;
            plVar10 = (longlong *)0x0;
            pcVar17 = (code *)0x0;
            pcStack_100 = (code *)0x0;
            uVar20 = 0x48d;
            plStack_118 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_130 = (longlong *)0x0;
            goto LAB_23e765f60;
          }
          cVar8 = FUN_23e8d9ac0();
          if (cVar8 == '\0') {
            auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
            plStack_c8 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (plStack_c8 == (longlong *)0x0) {
              plVar10 = (longlong *)0x0;
              pcVar17 = (code *)0x0;
              pcStack_100 = (code *)0x0;
              uVar22 = 2;
              plStack_118 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              uVar20 = 0x48e;
              pcStack_128 = (code *)0x0;
              plVar11 = (longlong *)0x0;
              goto LAB_23e7660a5;
            }
            if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e76788f;
            uVar22 = 2;
            pcStack_128 = (code *)0x0;
            plVar11 = (longlong *)0x0;
            plVar10 = (longlong *)0x0;
            pcVar17 = (code *)0x0;
            pcStack_100 = (code *)0x0;
            uVar20 = 0x48e;
            plStack_118 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_130 = (longlong *)0x0;
            goto LAB_23e765f60;
          }
          cVar8 = FUN_23e8d9ac0();
          if (cVar8 == '\0') {
            auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
            plStack_c8 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (plStack_c8 == (longlong *)0x0) {
              plVar10 = (longlong *)0x0;
              pcVar17 = (code *)0x0;
              pcStack_128 = (code *)0x0;
              uVar22 = 2;
              uVar20 = 0x48f;
              pcStack_100 = (code *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              plVar11 = (longlong *)0x0;
              goto LAB_23e7660a5;
            }
            if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e76788f;
            uVar22 = 2;
            pcStack_128 = (code *)0x0;
            plVar11 = (longlong *)0x0;
            plVar10 = (longlong *)0x0;
            pcVar17 = (code *)0x0;
            pcStack_100 = (code *)0x0;
            uVar20 = 0x48f;
            plStack_118 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_130 = (longlong *)0x0;
            goto LAB_23e765f60;
          }
          plStack_118 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_130 = (longlong *)0x0;
LAB_23e765736:
          lVar12 = FUN_23e8dffd0();
          if (lVar12 == 0) {
            FUN_23e915740(param_1,auStack_d8,DAT_23eed9400);
joined_r0x00023e768467:
            pcStack_100 = (code *)0x0;
            if (plStack_c8 != (longlong *)0x0) {
              if ((longlong *)plStack_c8[3] != plVar3) {
                plVar11 = (longlong *)0x0;
                plVar10 = (longlong *)0x0;
                pcVar17 = (code *)0x0;
                pcStack_128 = (code *)0x0;
                uVar20 = 0x498;
                uVar22 = 2;
                goto LAB_23e765f60;
              }
LAB_23e767b0f:
              uVar22 = 2;
              plVar11 = (longlong *)0x0;
              pcStack_128 = (code *)0x0;
              plVar10 = (longlong *)0x0;
              pcVar17 = (code *)0x0;
              pcStack_100 = (code *)0x0;
              plVar15 = plStack_c8;
              goto LAB_23e765b77;
            }
LAB_23e768469:
            uVar22 = 2;
            plVar11 = (longlong *)0x0;
            plVar10 = (longlong *)0x0;
            pcStack_128 = (code *)0x0;
            pcVar17 = (code *)0x0;
            uVar20 = 0x498;
            pcStack_100 = (code *)0x0;
          }
          else {
            *(undefined4 *)(plVar3 + 5) = 0x498;
            plVar10 = (longlong *)FUN_23e91a870();
            if (plVar10 == (longlong *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (plStack_c8 != (longlong *)0x0) {
                if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e767b0f;
                plVar11 = (longlong *)0x0;
                plVar10 = (longlong *)0x0;
                uVar22 = 2;
                pcStack_128 = (code *)0x0;
                uVar20 = 0x498;
                pcStack_100 = (code *)0x0;
                pcVar17 = (code *)0x0;
                goto LAB_23e765f60;
              }
              goto LAB_23e768469;
            }
            plVar11 = (longlong *)FUN_23e8c6f80();
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              FUN_23a334bc0();
            }
            if (plVar11 == (longlong *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto joined_r0x00023e768467;
            }
            cVar8 = FUN_23e8d9ac0(plVar13,DAT_23eed9410,plVar11);
            lVar12 = *plVar11;
            *plVar11 = lVar12 + -1;
            if (lVar12 + -1 == 0) {
              FUN_23a334bc0();
            }
            if (cVar8 == '\0') {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (plStack_c8 == (longlong *)0x0) goto LAB_23e768469;
              if ((longlong *)plStack_c8[3] != plVar3) {
                uVar22 = 2;
                plVar11 = (longlong *)0x0;
                pcStack_128 = (code *)0x0;
                plVar10 = (longlong *)0x0;
                pcVar17 = (code *)0x0;
                uVar20 = 0x498;
                pcStack_100 = (code *)0x0;
                goto LAB_23e765f60;
              }
              goto LAB_23e767b0f;
            }
            *(undefined4 *)(plVar3 + 5) = 0x49b;
            plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar13,DAT_23eed9418);
            if (plVar10 == (longlong *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (plStack_c8 == (longlong *)0x0) {
LAB_23e768f31:
                uVar22 = 2;
                plVar11 = (longlong *)0x0;
                pcStack_128 = (code *)0x0;
                plVar10 = (longlong *)0x0;
                pcVar17 = (code *)0x0;
                uVar20 = 0x49b;
                pcStack_100 = (code *)0x0;
                goto LAB_23e7660a5;
              }
              if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e767b0f;
              plVar11 = (longlong *)0x0;
              plVar10 = (longlong *)0x0;
              pcVar17 = (code *)0x0;
              pcStack_128 = (code *)0x0;
              uVar22 = 2;
              uVar20 = 0x49b;
              pcStack_100 = (code *)0x0;
              goto LAB_23e765f60;
            }
            iVar9 = FUN_23a35f020();
            lVar12 = *plVar10;
            *plVar10 = lVar12 + -1;
            if (lVar12 + -1 == 0) {
              FUN_23a334bc0();
            }
            if (iVar9 == -1) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (plStack_c8 == (longlong *)0x0) goto LAB_23e768f31;
              if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e767b0f;
              uVar22 = 2;
              plVar11 = (longlong *)0x0;
              plVar10 = (longlong *)0x0;
              pcStack_128 = (code *)0x0;
              pcVar17 = (code *)0x0;
              uVar20 = 0x49b;
              pcStack_100 = (code *)0x0;
              goto LAB_23e765f60;
            }
            if (iVar9 == 0) {
              *(undefined4 *)(plVar3 + 5) = 0x49c;
              plVar10 = (longlong *)FUN_23e915840(param_1,plVar1,DAT_23eed8b40);
              if (plVar10 == (longlong *)0x0) {
                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_c8 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_c8 == (longlong *)0x0) {
                  plVar11 = (longlong *)0x0;
                  plVar10 = (longlong *)0x0;
                  uVar22 = 2;
                  pcStack_128 = (code *)0x0;
                  uVar20 = 0x49c;
                  pcVar17 = (code *)0x0;
                  pcStack_100 = (code *)0x0;
                  goto LAB_23e7660a5;
                }
                if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e767b0f;
                plVar11 = (longlong *)0x0;
                plVar10 = (longlong *)0x0;
                pcStack_128 = (code *)0x0;
                uVar22 = 2;
                uVar20 = 0x49c;
                pcStack_100 = (code *)0x0;
                pcVar17 = (code *)0x0;
              }
              else {
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  FUN_23a334bc0(plVar10);
                }
                *(undefined4 *)(plVar3 + 5) = 0x49d;
                plVar10 = (longlong *)FUN_23e91bfe0();
                if (plVar10 == (longlong *)0x0) {
                  auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                  plStack_c8 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  if (plStack_c8 == (longlong *)0x0) {
                    plVar11 = (longlong *)0x0;
                    plVar10 = (longlong *)0x0;
                    uVar22 = 2;
                    pcStack_128 = (code *)0x0;
                    uVar20 = 0x49d;
                    pcVar17 = (code *)0x0;
                    pcStack_100 = (code *)0x0;
                    goto LAB_23e7660a5;
                  }
                  if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e767b0f;
                  plVar11 = (longlong *)0x0;
                  plVar10 = (longlong *)0x0;
                  pcStack_128 = (code *)0x0;
                  uVar22 = 2;
                  uVar20 = 0x49d;
                  pcStack_100 = (code *)0x0;
                  pcVar17 = (code *)0x0;
                }
                else {
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    FUN_23a334bc0(plVar10);
                  }
                  lVar12 = DAT_23eed9090;
                  *(undefined4 *)(plVar3 + 5) = 0x49e;
                  plVar10 = (longlong *)
                            FUN_23e915840(param_1,plVar1,DAT_23eed8c50,
                                          *(undefined8 *)(lVar12 + 0x18));
                  if (plVar10 == (longlong *)0x0) {
                    auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_c8 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (plStack_c8 == (longlong *)0x0) {
                      plVar11 = (longlong *)0x0;
                      plVar10 = (longlong *)0x0;
                      uVar22 = 2;
                      pcStack_128 = (code *)0x0;
                      uVar20 = 0x49e;
                      pcVar17 = (code *)0x0;
                      pcStack_100 = (code *)0x0;
                      goto LAB_23e7660a5;
                    }
                    if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e767b0f;
                    plVar11 = (longlong *)0x0;
                    plVar10 = (longlong *)0x0;
                    pcStack_128 = (code *)0x0;
                    uVar22 = 2;
                    pcStack_100 = (code *)0x0;
                    uVar20 = 0x49e;
                    pcVar17 = (code *)0x0;
                  }
                  else {
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      FUN_23a334bc0(plVar10);
                    }
                    cVar8 = FUN_23e8d9ac0();
                    if (cVar8 != '\0') {
                      lVar12 = *(longlong *)pcStack_f8;
                      goto LAB_23e764fe8;
                    }
                    auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_c8 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (plStack_c8 == (longlong *)0x0) {
                      plVar11 = (longlong *)0x0;
                      plVar10 = (longlong *)0x0;
                      pcVar17 = (code *)0x0;
                      pcStack_128 = (code *)0x0;
                      uVar22 = 2;
                      uVar20 = 0x49f;
                      pcStack_100 = (code *)0x0;
                      goto LAB_23e7660a5;
                    }
                    if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e767b0f;
                    plVar11 = (longlong *)0x0;
                    uVar22 = 2;
                    plVar10 = (longlong *)0x0;
                    pcVar17 = (code *)0x0;
                    uVar20 = 0x49f;
                    pcStack_128 = (code *)0x0;
                    pcStack_100 = (code *)0x0;
                  }
                }
              }
              goto LAB_23e765f60;
            }
            *(undefined4 *)(plVar3 + 5) = 0x4a5;
            *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
            plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar13);
            if (plVar10 == (longlong *)0x0) {
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              auStack_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
              auStack_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e76890c:
              uVar21 = 0x4a5;
              pcVar17 = (code *)0x0;
              pcStack_128 = (code *)0x0;
LAB_23e76891f:
              plVar11 = plStack_c8;
              plStack_c8 = (longlong *)0x0;
              pcStack_78 = (code *)plVar11;
              plVar10 = *(longlong **)(param_1 + 0x138);
              uStack_88 = auStack_d8._0_8_;
              plStack_80 = (longlong *)auStack_d8._8_8_;
              auStack_d8 = (undefined1  [16])0x0;
              if (plVar10 != (longlong *)0x0) {
                *plVar10 = *plVar10 + 1;
              }
              if (plVar11 == (longlong *)0x0) {
                pcVar18 = (code *)FUN_23e8d6280(plVar3,uVar21);
              }
              else {
                pcVar18 = (code *)FUN_23e8d6280(plVar3,uVar21);
                *(longlong **)(pcVar18 + 0x10) = plVar11;
                *plVar11 = *plVar11 + 1;
              }
              if ((pcStack_78 != (code *)0x0) &&
                 (*(longlong *)pcStack_78 = *(longlong *)pcStack_78 + -1,
                 *(longlong *)pcStack_78 == 0)) {
                FUN_23a334bc0();
              }
              pcStack_78 = pcVar18;
              FUN_23a35ef40(param_1,&uStack_88);
              iVar9 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                                    *(undefined8 *)PyExc_Exception_exref);
              uVar21 = DAT_23eed8b40;
              if (iVar9 == 0) {
                cVar8 = FUN_23e8ba320(*(undefined8 *)(param_1 + 0x138));
                plVar11 = plStack_c8;
                auVar7 = auStack_d8;
                iVar9 = 0;
                if (cVar8 == '\0') {
                  iVar9 = 0x4a4;
                }
                if (plStack_c8 == (longlong *)0x0) {
                  auStack_d8 = (undefined1  [16])0x0;
                  FUN_23ebf6ae0(param_1,plVar10);
                  plStack_c8 = (longlong *)0x0;
                  if (iVar9 == 0) {
                    uVar20 = (undefined4)plVar3[5];
                    plVar11 = (longlong *)0x0;
                    plVar10 = (longlong *)0x0;
                    uVar22 = 2;
                    pcStack_100 = _Py_FalseStruct_exref;
                    auStack_d8 = auVar7;
                  }
                  else {
                    plVar11 = (longlong *)0x0;
                    plVar10 = (longlong *)0x0;
                    uVar22 = 2;
                    uVar20 = 0x4a4;
                    pcStack_100 = _Py_FalseStruct_exref;
                    auStack_d8 = auVar7;
                  }
                  goto LAB_23e7660a5;
                }
                if ((longlong *)plStack_c8[3] == plVar3) {
                  *(undefined4 *)(plVar3 + 5) = *(undefined4 *)((longlong)plStack_c8 + 0x24);
                }
                plStack_c8 = (longlong *)0x0;
                auStack_d8 = (undefined1  [16])0x0;
                FUN_23ebf6ae0(param_1,plVar10);
                auStack_d8 = auVar7;
                plStack_c8 = plVar11;
                if ((longlong *)plVar11[3] != plVar3) {
                  if (iVar9 == 0) {
                    uVar20 = (undefined4)plVar3[5];
                    plVar11 = (longlong *)0x0;
                    plVar10 = (longlong *)0x0;
                    uVar22 = 2;
                    pcStack_100 = _Py_FalseStruct_exref;
                  }
                  else {
                    plVar11 = (longlong *)0x0;
                    plVar10 = (longlong *)0x0;
                    uVar20 = 0x4a4;
                    uVar22 = 2;
                    pcStack_100 = _Py_FalseStruct_exref;
                  }
                  goto LAB_23e765f60;
                }
              }
              else {
                plVar11 = *(longlong **)(param_1 + 0x138);
                *plVar11 = *plVar11 + 1;
                plVar15 = (longlong *)FUN_23e8bc2f0(plVar1,uVar21);
                plVar16 = _DAT_23eed9440;
                if (plVar15 == (longlong *)0x0) {
LAB_23e768e32:
                  auStack_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                  auStack_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                  plStack_c8 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                }
                else {
                  plVar19 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                  *plVar16 = *plVar16 + 1;
                  plVar19[3] = (longlong)plVar16;
                  lVar12 = FUN_23e94f9d0(param_1,plVar11,DAT_23ed6cd28);
                  if (lVar12 == 0) {
                    auStack_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                    auStack_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    plStack_c8 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar15 = *plVar15 + -1;
                    if (*plVar15 == 0) {
                      FUN_23a334bc0(plVar15);
                    }
                    *plVar19 = *plVar19 + -1;
                    if (*plVar19 == 0) {
                      FUN_23a334bc0(plVar19);
                    }
                  }
                  else {
                    plVar19[4] = lVar12;
                    plVar16 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar19);
                    *plVar19 = *plVar19 + -1;
                    if (*plVar19 == 0) {
                      FUN_23a334bc0(plVar19);
                    }
                    if (plVar16 != (longlong *)0x0) {
                      *(undefined4 *)(plVar3 + 5) = 0x4ad;
                      plVar19 = (longlong *)FUN_23e914090(param_1,plVar15);
                      *plVar15 = *plVar15 + -1;
                      if (*plVar15 == 0) {
                        FUN_23a334bc0(plVar15);
                      }
                      *plVar16 = *plVar16 + -1;
                      if (*plVar16 == 0) {
                        FUN_23a334bc0(plVar16);
                      }
                      if (plVar19 != (longlong *)0x0) {
                        *plVar19 = *plVar19 + -1;
                        if (*plVar19 == 0) {
                          FUN_23a334bc0(plVar19);
                        }
                        lVar12 = *plVar11;
                        *plVar11 = lVar12 + -1;
                        if (lVar12 + -1 == 0) {
                          FUN_23a334bc0(plVar11);
                        }
                        FUN_23ebf6ae0(param_1,plVar10);
                        pcStack_100 = _Py_FalseStruct_exref;
                        goto LAB_23e767bde;
                      }
                      goto LAB_23e768e32;
                    }
                    auStack_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                    auStack_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    plStack_c8 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar15 = *plVar15 + -1;
                    if (*plVar15 == 0) {
                      FUN_23a334bc0(plVar15);
                    }
                  }
                }
                plVar16 = plStack_c8;
                uVar23 = auStack_d8._8_8_;
                uVar21 = auStack_d8._0_8_;
                plStack_c8 = (longlong *)0x0;
                lVar12 = *plVar11;
                auStack_d8 = (undefined1  [16])0x0;
                *plVar11 = lVar12 + -1;
                if (lVar12 + -1 == 0) {
                  FUN_23a334bc0(plVar11);
                }
                plStack_c8 = (longlong *)0x0;
                auStack_d8 = (undefined1  [16])0x0;
                FUN_23ebf6ae0(param_1,plVar10);
                auStack_d8 = CONCAT88(uVar23,uVar21);
                plStack_c8 = plVar16;
                if (plVar16 == (longlong *)0x0) {
                  plVar11 = (longlong *)0x0;
                  uVar22 = 2;
                  uVar20 = 0x4ad;
                  pcStack_100 = _Py_FalseStruct_exref;
                  plVar10 = (longlong *)0x0;
                  goto LAB_23e7660a5;
                }
                if ((longlong *)plVar16[3] != plVar3) {
                  pcStack_100 = _Py_FalseStruct_exref;
                  plVar11 = (longlong *)0x0;
                  plVar10 = (longlong *)0x0;
                  uVar22 = 2;
                  uVar20 = 0x4ad;
                  goto LAB_23e765f60;
                }
              }
              pcStack_100 = _Py_FalseStruct_exref;
              uVar22 = 2;
              plVar11 = (longlong *)0x0;
              plVar10 = (longlong *)0x0;
              plVar15 = plStack_c8;
              goto LAB_23e765b77;
            }
            iVar9 = FUN_23a35f020();
            lVar12 = *plVar10 + -1;
            if (iVar9 == -1) {
              auStack_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
              auStack_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar10 = lVar12;
              if (lVar12 == 0) {
                FUN_23a334bc0();
              }
              goto LAB_23e76890c;
            }
            *plVar10 = lVar12;
            if (lVar12 == 0) {
              FUN_23a334bc0(plVar10);
            }
            pcVar17 = _Py_FalseStruct_exref;
            if (iVar9 == 0) {
              *(undefined4 *)(plVar3 + 5) = 0x4a9;
              pcVar17 = (code *)FUN_23e91bfe0(param_1,plVar13,_DAT_23eed9430);
              if (pcVar17 == (code *)0x0) {
                auStack_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                plStack_c8 = *(longlong **)(param_1 + 0x70);
                uVar21 = 0x4a9;
                *(undefined8 *)(param_1 + 0x70) = 0;
                pcStack_128 = (code *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              else {
                *(undefined4 *)(plVar3 + 5) = 0x4aa;
                pcStack_128 = (code *)FUN_23e91bfe0(param_1,plVar13,_DAT_23eed9438);
                if (pcStack_128 == (code *)0x0) {
                  auStack_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                  auStack_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                  plStack_c8 = *(longlong **)(param_1 + 0x70);
                  uVar21 = 0x4aa;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                }
                else {
                  iVar9 = FUN_23a35f020();
                  pcVar18 = _Py_FalseStruct_exref;
                  if (iVar9 != -1) {
                    pcStack_100 = pcStack_128;
                    if (iVar9 == 1) {
                      pcStack_100 = pcVar17;
                    }
                    *(longlong *)pcStack_100 = *(longlong *)pcStack_100 + 1;
                    lVar12 = *(longlong *)_Py_FalseStruct_exref;
                    *(longlong *)pcVar18 = lVar12 + -1;
                    if (lVar12 + -1 == 0) {
                      FUN_23a334bc0(pcVar18);
                    }
                    goto LAB_23e767bde;
                  }
                  auStack_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                  auStack_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                  plStack_c8 = *(longlong **)(param_1 + 0x70);
                  uVar21 = 0x4ab;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                }
              }
              goto LAB_23e76891f;
            }
            *(longlong *)pcStack_100 = *(longlong *)pcStack_100 + 1;
            lVar12 = *(longlong *)pcVar17;
            *(longlong *)pcVar17 = lVar12 + -1;
            if (lVar12 + -1 == 0) {
              FUN_23a334bc0(pcVar17);
            }
            pcVar17 = (code *)0x0;
            pcStack_128 = (code *)0x0;
LAB_23e767bde:
            lVar12 = FUN_23e8e07b0();
            if (lVar12 == 0) {
              FUN_23e915740(param_1,auStack_d8,DAT_23eed8f68);
              plVar10 = (longlong *)0x0;
joined_r0x00023e769453:
              if (plStack_c8 != (longlong *)0x0) {
                plVar11 = (longlong *)0x0;
                uVar20 = 0x4b0;
                plVar16 = (longlong *)plStack_c8[3];
joined_r0x00023e769302:
                uVar22 = 2;
joined_r0x00023e76916c:
                plVar15 = plStack_c8;
                if (plVar16 == plVar3) goto LAB_23e765b77;
                goto LAB_23e765f60;
              }
              uVar22 = 2;
              plVar11 = (longlong *)0x0;
              plVar10 = (longlong *)0x0;
              uVar20 = 0x4b0;
            }
            else {
              *(undefined4 *)(plVar3 + 5) = 0x4b0;
              plVar10 = (longlong *)FUN_23e91a870(param_1,lVar12);
              if (plVar10 == (longlong *)0x0) {
                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_c8 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto joined_r0x00023e769453;
              }
              iVar9 = FUN_23a35f020();
              if (iVar9 == -1) {
                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_c8 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_c8 == (longlong *)0x0) {
                  uVar22 = 2;
                  uVar20 = 0x4b1;
                  plVar11 = (longlong *)0x0;
                  goto LAB_23e7660a5;
                }
                if ((longlong *)plStack_c8[3] != plVar3) {
                  uVar22 = 2;
                  plVar11 = (longlong *)0x0;
                  uVar20 = 0x4b1;
                  goto LAB_23e765f60;
                }
LAB_23e769540:
                uVar22 = 2;
                plVar11 = (longlong *)0x0;
                plVar15 = plStack_c8;
                goto LAB_23e765b77;
              }
              if (iVar9 == 0) {
                *(undefined4 *)(plVar3 + 5) = 0x4b4;
                plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar10);
                if (plVar11 != (longlong *)0x0) goto LAB_23e767c50;
                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_c8 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_c8 == (longlong *)0x0) {
                  uVar22 = 2;
                  uVar20 = 0x4b4;
                  plVar11 = (longlong *)0x0;
                  goto LAB_23e7660a5;
                }
                if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e769540;
                uVar22 = 2;
                plVar11 = (longlong *)0x0;
                uVar20 = 0x4b4;
                goto LAB_23e765f60;
              }
              *(undefined4 *)(plVar3 + 5) = 0x4b2;
              plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar10);
              if (plVar11 == (longlong *)0x0) {
                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_c8 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_c8 == (longlong *)0x0) {
                  uVar22 = 2;
                  uVar20 = 0x4b2;
                  plVar11 = (longlong *)0x0;
                  goto LAB_23e7660a5;
                }
                if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e769540;
                uVar22 = 2;
                plVar11 = (longlong *)0x0;
                uVar20 = 0x4b2;
                goto LAB_23e765f60;
              }
LAB_23e767c50:
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                FUN_23a334bc0();
              }
              plVar16 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8978);
              plVar11 = (longlong *)0x0;
              if (plVar16 == (longlong *)0x0) {
LAB_23e76950e:
                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_c8 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_c8 == (longlong *)0x0) {
LAB_23e7695a6:
                  uVar22 = 2;
                  plVar11 = (longlong *)0x0;
                  uVar20 = 0x4b7;
                  goto LAB_23e7660a5;
                }
                plVar16 = (longlong *)plStack_c8[3];
joined_r0x00023e7694fc:
                if (plVar16 == plVar3) goto LAB_23e769540;
                uVar22 = 2;
                uVar20 = 0x4b7;
                goto LAB_23e765f60;
              }
              plVar15 = (longlong *)FUN_23e8bc2f0(plVar16,DAT_23ed6ce40);
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                FUN_23a334bc0();
              }
              uVar21 = DAT_23eed8b60;
              if (plVar15 == (longlong *)0x0) {
                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_c8 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_c8 == (longlong *)0x0) goto LAB_23e7695a6;
                plVar11 = (longlong *)0x0;
                plVar16 = (longlong *)plStack_c8[3];
                goto joined_r0x00023e7694fc;
              }
              plVar16 = (longlong *)FUN_23e8d6ad0(param_1);
              *(undefined4 *)(plVar3 + 5) = 0x4b7;
              uStack_b8 = uVar21;
              plStack_b0 = plVar16;
              plVar11 = (longlong *)FUN_23e94ed00(param_1,plVar15,&uStack_b8);
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                FUN_23a334bc0();
              }
              lVar12 = *plVar16;
              *plVar16 = lVar12 + -1;
              if (lVar12 + -1 == 0) {
                FUN_23a334bc0();
              }
              if (plVar11 == (longlong *)0x0) goto LAB_23e76950e;
              plVar16 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23eed9350);
              if (plVar16 == (longlong *)0x0) goto LAB_23e76947b;
              *(undefined4 *)(plVar3 + 5) = 0x4b8;
              plVar15 = (longlong *)FUN_23e91a870(param_1,plVar16);
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                FUN_23a334bc0();
              }
              if (plVar15 != (longlong *)0x0) {
                plVar16 = (longlong *)FUN_23ebf7180();
                *plVar15 = *plVar15 + -1;
                if (*plVar15 == 0) {
                  FUN_23a334bc0();
                }
                if (plVar16 == (longlong *)0x0) {
LAB_23e76947b:
                  auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                  plStack_c8 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  if (plStack_c8 != (longlong *)0x0) {
                    if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e7683e2;
                    uVar22 = 2;
                    uVar20 = 0x4b8;
                    goto LAB_23e765f60;
                  }
                  goto LAB_23e76934f;
                }
                uStack_b8 = FUN_23e8d6950(plVar16);
                plVar15 = (longlong *)
                          FUN_23e91ecd0(FUN_23e769800,DAT_23eedaeb8,DAT_23eed90c0,DAT_23eed9508,
                                        DAT_23eedaff0,&uStack_b8,1,0x78);
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  FUN_23a334bc0(plVar16);
                }
                plVar16 = (longlong *)FUN_23e8bd690();
                *plVar15 = *plVar15 + -1;
                if (*plVar15 == 0) {
                  FUN_23a334bc0();
                }
                if (plVar16 == (longlong *)0x0) goto LAB_23e76947b;
                iVar9 = FUN_23a35f020(plVar16);
                uVar22 = iVar9 != 0;
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  FUN_23a334bc0(plVar16);
                }
                lVar12 = DAT_23eed9358;
                if (iVar9 != 0) {
                  *(undefined4 *)(plVar3 + 5) = 0x4ba;
                  plVar16 = (longlong *)
                            FUN_23e915840(param_1,plVar1,DAT_23eed8b40,
                                          *(undefined8 *)(lVar12 + 0x18));
                  if (plVar16 == (longlong *)0x0) {
                    auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_c8 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (plStack_c8 == (longlong *)0x0) {
                      uVar22 = 1;
                      uVar20 = 0x4ba;
                      goto LAB_23e7660a5;
                    }
                    if ((longlong *)plStack_c8[3] == plVar3) {
LAB_23e769371:
                      uVar22 = 1;
                      plVar15 = plStack_c8;
                      goto LAB_23e765b77;
                    }
                    uVar22 = 1;
                    uVar20 = 0x4ba;
                  }
                  else {
                    *plVar16 = *plVar16 + -1;
                    if (*plVar16 == 0) {
                      FUN_23a334bc0();
                    }
                    *(undefined4 *)(plVar3 + 5) = 0x4bb;
                    plVar16 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eed9360);
                    if (plVar16 != (longlong *)0x0) {
                      *plVar16 = *plVar16 + -1;
                      if (*plVar16 == 0) {
                        FUN_23a334bc0();
                      }
                      goto LAB_23e767f24;
                    }
                    auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_c8 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (plStack_c8 == (longlong *)0x0) {
                      uVar22 = 1;
                      uVar20 = 0x4bb;
                      goto LAB_23e7660a5;
                    }
                    if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e769371;
                    uVar22 = 1;
                    uVar20 = 0x4bb;
                  }
                  goto LAB_23e765f60;
                }
LAB_23e767f24:
                *(undefined4 *)(plVar3 + 5) = 0x4be;
                plVar16 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eed9368);
                if (plVar16 == (longlong *)0x0) {
                  auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                  plStack_c8 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  if (plStack_c8 != (longlong *)0x0) {
                    uVar20 = 0x4be;
                    plVar16 = (longlong *)plStack_c8[3];
                    goto joined_r0x00023e76916c;
                  }
                  uVar20 = 0x4be;
                  goto LAB_23e7660a5;
                }
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  FUN_23a334bc0();
                }
                lVar12 = DAT_23eed9090;
                *(undefined4 *)(plVar3 + 5) = 0x4c1;
                plVar16 = (longlong *)
                          FUN_23e915840(param_1,plVar1,DAT_23eed8c50,*(undefined8 *)(lVar12 + 0x18))
                ;
                if (plVar16 == (longlong *)0x0) {
                  auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                  plStack_c8 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  if (plStack_c8 != (longlong *)0x0) {
                    uVar20 = 0x4c1;
                    plVar16 = (longlong *)plStack_c8[3];
                    goto joined_r0x00023e76916c;
                  }
                  uVar20 = 0x4c1;
                  goto LAB_23e7660a5;
                }
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  FUN_23a334bc0();
                }
                cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eed89b8,_Py_FalseStruct_exref);
                if (cVar8 != '\0') {
                  lVar12 = FUN_23e8e0e20();
                  if (lVar12 == 0) {
                    FUN_23e915740(param_1,auStack_d8,DAT_23eed8988);
                  }
                  else {
                    plVar16 = (longlong *)FUN_23e8bc2f0(lVar12,DAT_23eed8990);
                    if (plVar16 != (longlong *)0x0) {
                      cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eed8998);
                      *plVar16 = *plVar16 + -1;
                      if (*plVar16 == 0) {
                        FUN_23a334bc0();
                      }
                      if (cVar8 != '\0') {
                        FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                        *(longlong *)pcStack_f8 = *(longlong *)pcStack_f8 + 1;
                        goto LAB_23e765065;
                      }
                    }
                    auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_c8 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  if (plStack_c8 != (longlong *)0x0) {
                    uVar20 = 0x4c4;
                    plVar16 = (longlong *)plStack_c8[3];
                    goto joined_r0x00023e76916c;
                  }
                  uVar20 = 0x4c4;
                  goto LAB_23e7660a5;
                }
                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_c8 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_c8 == (longlong *)0x0) {
                  uVar20 = 0x4c3;
                  goto LAB_23e7660a5;
                }
                uVar20 = 0x4c3;
                plVar16 = (longlong *)plStack_c8[3];
                goto joined_r0x00023e76916c;
              }
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (plStack_c8 != (longlong *)0x0) {
                uVar20 = 0x4b8;
                plVar16 = (longlong *)plStack_c8[3];
                goto joined_r0x00023e769302;
              }
LAB_23e76934f:
              uVar22 = 2;
              uVar20 = 0x4b8;
            }
          }
        }
      }
      goto LAB_23e7660a5;
    }
    auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_c8 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (plStack_c8 == (longlong *)0x0) {
      pcStack_128 = (code *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      pcVar17 = (code *)0x0;
      pcStack_100 = (code *)0x0;
      plVar14 = (longlong *)0x0;
      uVar22 = 2;
      uVar20 = 0x47f;
      plStack_118 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      goto LAB_23e7660a5;
    }
    if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e765b10;
    pcStack_128 = (code *)0x0;
    plVar11 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    pcVar17 = (code *)0x0;
    pcStack_100 = (code *)0x0;
    plVar14 = (longlong *)0x0;
    uVar22 = 2;
    uVar20 = 0x47f;
    plStack_118 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
LAB_23e765f60:
    plVar16 = plStack_c8;
    plVar15 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar19 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar19;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar18 = _PyRuntime_exref;
    plVar15[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar12 = *(longlong *)(pcVar18 + 0x1f8);
    *(undefined4 *)((longlong)plVar15 + 0x24) = uVar20;
    *(undefined4 *)(plVar15 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
    lVar2 = plVar15[-1];
    puVar4 = *(undefined8 **)(lVar12 + 8);
    *puVar4 = plVar15 + -2;
    plVar15[-2] = lVar12;
    plVar15[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar12 + 8) = plVar15 + -2;
    plVar15[2] = (longlong)plVar16;
    *plVar16 = *plVar16 + 1;
    plVar16 = plStack_c8;
  }
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))();
  }
LAB_23e765b77:
  plStack_c8 = plVar15;
  FUN_23e8bba40(plVar3,"oooooooooooooob",plVar1,plVar13,plVar14,plStack_108,plStack_120,plStack_130,
                plStack_110,plStack_118,pcStack_100,pcVar17,pcStack_128,0,plVar10,plVar11,uVar22);
  if (_DAT_23eedada8 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eedada8 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar12 + 0x28);
  plVar16 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar16 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      (**(code **)(plVar16[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar16 = plStack_c8;
  plVar3[0xf] = 0;
  uVar21 = auStack_d8._0_8_;
  uVar23 = auStack_d8._8_8_;
  auStack_d8 = (undefined1  [16])0x0;
  plStack_c8 = (longlong *)0x0;
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((plStack_108 != (longlong *)0x0) &&
     (lVar12 = *plStack_108, *plStack_108 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_108[1] + 0x30))(plStack_108);
  }
  if ((plStack_120 != (longlong *)0x0) &&
     (lVar12 = *plStack_120, *plStack_120 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_120[1] + 0x30))();
  }
  if ((plStack_130 != (longlong *)0x0) &&
     (lVar12 = *plStack_130, *plStack_130 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_130[1] + 0x30))(plStack_130);
  }
  if ((plStack_110 != (longlong *)0x0) &&
     (lVar12 = *plStack_110, *plStack_110 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_110[1] + 0x30))(plStack_110);
  }
  if ((plStack_118 != (longlong *)0x0) &&
     (lVar12 = *plStack_118, *plStack_118 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_118[1] + 0x30))();
  }
  if ((pcStack_100 != (code *)0x0) &&
     (lVar12 = *(longlong *)pcStack_100, *(longlong *)pcStack_100 = lVar12 + -1, lVar12 + -1 == 0))
  {
    (**(code **)(*(longlong *)(pcStack_100 + 8) + 0x30))(pcStack_100);
  }
  if ((pcVar17 != (code *)0x0) &&
     (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1, *(longlong *)pcVar17 == 0)) {
    (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
  }
  if ((pcStack_128 != (code *)0x0) &&
     (lVar12 = *(longlong *)pcStack_128, *(longlong *)pcStack_128 = lVar12 + -1, lVar12 + -1 == 0))
  {
    (**(code **)(*(longlong *)(pcStack_128 + 8) + 0x30))(pcStack_128);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  *plVar1 = *plVar1 + -1;
  plStack_c8 = plVar16;
  auStack_d8._0_8_ = uVar21;
  auStack_d8._8_8_ = uVar23;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,auStack_d8._0_8_,auStack_d8._8_8_,plStack_c8);
  return (code *)0x0;
}
