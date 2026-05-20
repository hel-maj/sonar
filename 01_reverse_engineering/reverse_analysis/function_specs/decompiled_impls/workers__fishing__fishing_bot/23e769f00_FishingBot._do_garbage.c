/* ===== 23e769f00 workers.fishing.fishing_bot:FishingBot._do_garbage ===== */
/* ghidra_name=FUN_23e769f00 entry=23e769f00 size=18278 */

/* WARNING: Type propagation algorithm not settling */

code * FUN_23e769f00(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  code *pcVar5;
  undefined8 uVar6;
  char cVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  code *pcVar15;
  longlong *plVar16;
  undefined4 uVar17;
  undefined8 uVar18;
  longlong *plVar19;
  longlong *plVar20;
  undefined1 uVar21;
  undefined1 auVar22 [8];
  undefined8 in_stack_fffffffffffffe90;
  undefined4 uVar23;
  code *local_128;
  longlong *local_120;
  longlong *local_118;
  longlong *local_110;
  uint local_104;
  code *local_100;
  code *pcVar24;
  code **local_f0;
  undefined1 local_d8 [8];
  longlong *plStack_d0;
  longlong *local_c8 [2];
  code *local_b8;
  longlong *plStack_b0;
  code *local_a8;
  undefined8 local_a0;
  code *local_98;
  code *local_88;
  longlong *plStack_80;
  code *local_78;
  undefined8 local_70;
  code *local_68;
  
  plVar9 = DAT_23eedad98;
  plVar1 = (longlong *)*param_3;
  local_c8[0] = (longlong *)0x0;
  local_d8 = (undefined1  [8])0x0;
  plStack_d0 = (longlong *)0x0;
  if (DAT_23eedad98 == (longlong *)0x0) {
LAB_23e769f5d:
    DAT_23eedad98 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedaf68,DAT_23eedaeb8,0x68);
  }
  else {
    lVar11 = *DAT_23eedad98;
    if (1 < lVar11) {
      *DAT_23eedad98 = lVar11 + -1;
      goto LAB_23e769f5d;
    }
    if (DAT_23eedad98[2] != 0) {
      *DAT_23eedad98 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e769f5d;
    }
  }
  plVar3 = DAT_23eedad98;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar9 = DAT_23eedad98 + 9;
  lVar2 = *(longlong *)(lVar11 + 8);
  DAT_23eedad98[0xf] = lVar2;
  *(longlong **)(lVar11 + 8) = plVar9;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar18 = DAT_23eed89b0;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,uVar18);
  uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
  if (plVar9 == (longlong *)0x0) {
    local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
    plStack_d0 = *(longlong **)(param_1 + 0x68);
    local_c8[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (local_c8[0] == (longlong *)0x0) goto LAB_23e76af80;
    if ((longlong *)local_c8[0][3] != plVar3) {
      local_118 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      local_120 = (longlong *)0x0;
      plVar20 = (longlong *)0x0;
      uVar21 = 2;
      uVar17 = 0x4ca;
      local_128 = (code *)0x0;
      local_100 = (code *)0x0;
      local_110 = (longlong *)0x0;
      local_104 = 2;
      plVar10 = (longlong *)0x0;
      goto LAB_23e76aeb0;
    }
LAB_23e76aae0:
    local_118 = (longlong *)0x0;
    plVar19 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    uVar21 = 2;
    local_120 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plVar20 = (longlong *)0x0;
    local_128 = (code *)0x0;
    local_104 = 2;
    local_100 = (code *)0x0;
    local_110 = (longlong *)0x0;
    plVar12 = local_c8[0];
    goto LAB_23e76ab3a;
  }
  *(undefined4 *)(plVar3 + 5) = 0x4ca;
  plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar9,DAT_23eed8d38);
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
  if (plVar10 == (longlong *)0x0) {
    local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
    plStack_d0 = *(longlong **)(param_1 + 0x68);
    local_c8[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (local_c8[0] != (longlong *)0x0) {
      if ((longlong *)local_c8[0][3] == plVar3) goto LAB_23e76aae0;
      local_118 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      local_120 = (longlong *)0x0;
      plVar20 = (longlong *)0x0;
      uVar21 = 2;
      uVar17 = 0x4ca;
      local_128 = (code *)0x0;
      local_100 = (code *)0x0;
      local_110 = (longlong *)0x0;
      local_104 = 2;
      plVar13 = (longlong *)0x0;
      goto LAB_23e76aeb0;
    }
LAB_23e76af80:
    local_118 = (longlong *)0x0;
    plVar19 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    uVar21 = 2;
    local_120 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plVar20 = (longlong *)0x0;
    local_104 = 2;
    uVar17 = 0x4ca;
    local_128 = (code *)0x0;
    local_100 = (code *)0x0;
    local_110 = (longlong *)0x0;
    goto LAB_23e76afdf;
  }
  iVar8 = FUN_23a35f020(plVar10);
  uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
  lVar11 = *plVar10 + -1;
  if (iVar8 == -1) {
    local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
    plStack_d0 = *(longlong **)(param_1 + 0x68);
    local_c8[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar10 = lVar11;
    if (lVar11 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
      if (local_c8[0] == (longlong *)0x0) goto LAB_23e76af80;
      plVar9 = (longlong *)local_c8[0][3];
    }
    else {
      if (local_c8[0] == (longlong *)0x0) goto LAB_23e76af80;
      plVar9 = (longlong *)local_c8[0][3];
    }
    if (plVar3 != plVar9) {
      local_118 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      uVar21 = 2;
      local_120 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plVar20 = (longlong *)0x0;
      local_104 = 2;
      uVar17 = 0x4ca;
      local_128 = (code *)0x0;
      local_100 = (code *)0x0;
      local_110 = (longlong *)0x0;
      goto LAB_23e76aeb0;
    }
    goto LAB_23e76aae0;
  }
  *plVar10 = lVar11;
  if (lVar11 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if (iVar8 != 0) {
    plVar13 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    lVar11 = *(longlong *)_Py_NoneStruct_exref;
    pcVar24 = _Py_NoneStruct_exref;
LAB_23e76a09a:
    *(longlong *)pcVar24 = lVar11 + 1;
    lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar9 = *(longlong **)(lVar11 + 0x28);
    plVar3 = (longlong *)plVar9[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
    *(undefined4 *)(plVar9 + 8) = 0xffffffff;
    if (plVar3 != (longlong *)0x0) {
      plVar9[2] = 0;
      *plVar3 = *plVar3 + -1;
      if (*plVar3 == 0) {
        (**(code **)(plVar3[1] + 0x30))();
      }
    }
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    plVar9[0xf] = 0;
    if (plVar10 == (longlong *)0x0) {
      if (plVar13 == (longlong *)0x0) {
        if ((local_110 != (longlong *)0x0) &&
           (lVar11 = *local_110, *local_110 = lVar11 + -1, lVar11 + -1 == 0)) {
          (**(code **)(local_110[1] + 0x30))(local_110);
        }
        goto LAB_23e76a247;
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        local_118 = (longlong *)0x0;
        plVar19 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        plVar20 = (longlong *)0x0;
        local_120 = (longlong *)0x0;
        local_128 = (code *)0x0;
        local_100 = (code *)0x0;
        goto LAB_23e76a9cc;
      }
      if ((local_110 == (longlong *)0x0) ||
         (lVar11 = *local_110, *local_110 = lVar11 + -1, lVar11 + -1 != 0)) goto LAB_23e76a247;
      plVar19 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plVar20 = (longlong *)0x0;
      (**(code **)(local_110[1] + 0x30))(local_110);
    }
    else {
      local_118 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plVar20 = (longlong *)0x0;
      local_120 = (longlong *)0x0;
      local_128 = (code *)0x0;
      local_100 = (code *)0x0;
LAB_23e76a135:
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
LAB_23e76a9cc:
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      if ((local_110 != (longlong *)0x0) &&
         (lVar11 = *local_110, *local_110 = lVar11 + -1, lVar11 + -1 == 0)) {
        (**(code **)(local_110[1] + 0x30))(local_110);
      }
      if ((local_100 != (code *)0x0) &&
         (lVar11 = *(longlong *)local_100, *(longlong *)local_100 = lVar11 + -1, lVar11 + -1 == 0))
      {
        (**(code **)(*(longlong *)(local_100 + 8) + 0x30))(local_100);
      }
      if ((local_128 != (code *)0x0) &&
         (lVar11 = *(longlong *)local_128, *(longlong *)local_128 = lVar11 + -1, lVar11 + -1 == 0))
      {
        (**(code **)(*(longlong *)(local_128 + 8) + 0x30))(local_128);
      }
      if ((local_120 != (longlong *)0x0) &&
         (lVar11 = *local_120, *local_120 = lVar11 + -1, lVar11 + -1 == 0)) {
        (**(code **)(local_120[1] + 0x30))(local_120);
      }
      if ((local_118 != (longlong *)0x0) &&
         (lVar11 = *local_118, *local_118 = lVar11 + -1, lVar11 + -1 == 0)) {
        (**(code **)(local_118[1] + 0x30))(local_118);
      }
    }
    if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
      (**(code **)(plVar20[1] + 0x30))(plVar20);
    }
    if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
      (**(code **)(plVar19[1] + 0x30))(plVar19);
    }
LAB_23e76a247:
    *plVar1 = *plVar1 + -1;
    if (*plVar1 == 0) {
      (**(code **)(plVar1[1] + 0x30))(plVar1);
    }
    return pcVar24;
  }
  cVar7 = FUN_23e8d9ac0(plVar1,DAT_23eed89b8,_Py_TrueStruct_exref);
  uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
  if (cVar7 == '\0') {
    local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
    plStack_d0 = *(longlong **)(param_1 + 0x68);
    local_c8[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (local_c8[0] == (longlong *)0x0) {
      local_118 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      local_120 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plVar20 = (longlong *)0x0;
      uVar21 = 2;
      local_104 = 2;
      uVar17 = 0x4cc;
      local_128 = (code *)0x0;
      local_100 = (code *)0x0;
      local_110 = (longlong *)0x0;
      goto LAB_23e76afdf;
    }
    if ((longlong *)local_c8[0][3] == plVar3) goto LAB_23e76aae0;
    local_118 = (longlong *)0x0;
    plVar19 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    uVar21 = 2;
    local_120 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plVar20 = (longlong *)0x0;
    local_104 = 2;
    uVar17 = 0x4cc;
    local_128 = (code *)0x0;
    local_100 = (code *)0x0;
    local_110 = (longlong *)0x0;
    goto LAB_23e76aeb0;
  }
  lVar11 = FUN_23e8e0e20();
  uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
  if (lVar11 == 0) {
    FUN_23e915740(param_1,local_d8,DAT_23eed8988);
    if (local_c8[0] != (longlong *)0x0) {
      plVar9 = (longlong *)local_c8[0][3];
joined_r0x00023e76b44c:
      if (plVar3 == plVar9) goto LAB_23e76aae0;
      plVar10 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      local_120 = (longlong *)0x0;
      plVar20 = (longlong *)0x0;
      uVar21 = 2;
      uVar17 = 0x4cd;
      local_128 = (code *)0x0;
      local_100 = (code *)0x0;
      local_110 = (longlong *)0x0;
      local_104 = 2;
      goto LAB_23e76aeb0;
    }
LAB_23e76b748:
    local_118 = (longlong *)0x0;
    plVar19 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    uVar21 = 2;
    local_120 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plVar20 = (longlong *)0x0;
    local_104 = 2;
    uVar17 = 0x4cd;
    local_128 = (code *)0x0;
    local_100 = (code *)0x0;
    local_110 = (longlong *)0x0;
LAB_23e76afdf:
    plVar12 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      plVar14 = local_c8[0];
    }
    else {
      plVar14 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar14;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar14 = (longlong *)0x0;
    }
    plVar12[2] = 0;
    plVar12[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar17;
    pcVar24 = _PyRuntime_exref;
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar24 + 0x1f8) + 0x10) + 0x2e8);
    lVar2 = plVar12[-1];
    puVar4 = *(undefined8 **)(lVar11 + 8);
    *puVar4 = plVar12 + -2;
    plVar12[-2] = lVar11;
    plVar12[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar11 + 8) = plVar12 + -2;
  }
  else {
    plVar9 = (longlong *)FUN_23e8bc2f0(lVar11,DAT_23eed8f18);
    uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
    if (plVar9 == (longlong *)0x0) {
      local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_d0 = *(longlong **)(param_1 + 0x68);
      local_c8[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (local_c8[0] != (longlong *)0x0) {
        plVar9 = (longlong *)local_c8[0][3];
        goto joined_r0x00023e76b44c;
      }
      goto LAB_23e76b748;
    }
    cVar7 = FUN_23e8d9ac0(plVar1,DAT_23eed8998,plVar9);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
    if (cVar7 == '\0') {
      local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_d0 = *(longlong **)(param_1 + 0x68);
      local_c8[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (local_c8[0] == (longlong *)0x0) goto LAB_23e76b748;
      if (plVar3 == (longlong *)local_c8[0][3]) goto LAB_23e76aae0;
      local_118 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      uVar21 = 2;
      local_120 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plVar20 = (longlong *)0x0;
      local_104 = 2;
      uVar17 = 0x4cd;
      local_128 = (code *)0x0;
      local_100 = (code *)0x0;
      local_110 = (longlong *)0x0;
      goto LAB_23e76aeb0;
    }
    *(undefined4 *)(plVar3 + 5) = 0x4ce;
    plVar9 = (longlong *)FUN_23e915840(param_1,plVar1,DAT_23eed8b40);
    uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
    if (plVar9 == (longlong *)0x0) {
      local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_d0 = *(longlong **)(param_1 + 0x68);
      local_c8[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (local_c8[0] != (longlong *)0x0) {
        if ((longlong *)local_c8[0][3] == plVar3) goto LAB_23e76aae0;
        local_118 = (longlong *)0x0;
        plVar19 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        local_120 = (longlong *)0x0;
        plVar20 = (longlong *)0x0;
        uVar21 = 2;
        uVar17 = 0x4ce;
        local_128 = (code *)0x0;
        local_100 = (code *)0x0;
        local_110 = (longlong *)0x0;
        local_104 = 2;
        plVar10 = (longlong *)0x0;
        goto LAB_23e76aeb0;
      }
      local_118 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      local_120 = (longlong *)0x0;
      plVar20 = (longlong *)0x0;
      uVar21 = 2;
      uVar17 = 0x4ce;
      local_128 = (code *)0x0;
      local_100 = (code *)0x0;
      local_110 = (longlong *)0x0;
      local_104 = 2;
      plVar10 = (longlong *)0x0;
      goto LAB_23e76afdf;
    }
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    *(undefined4 *)(plVar3 + 5) = 0x4d0;
    plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eed9318);
    uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      *(undefined4 *)(plVar3 + 5) = 0x4d1;
      plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eed9320);
      uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
      if (plVar9 == (longlong *)0x0) {
        local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
        plStack_d0 = *(longlong **)(param_1 + 0x68);
        local_c8[0] = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (local_c8[0] == (longlong *)0x0) {
          plVar19 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          plVar20 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          uVar21 = 2;
          uVar17 = 0x4d1;
          local_120 = (longlong *)0x0;
          local_128 = (code *)0x0;
          local_100 = (code *)0x0;
          local_110 = (longlong *)0x0;
          local_104 = 2;
          plVar10 = (longlong *)0x0;
          goto LAB_23e76afdf;
        }
        if ((longlong *)local_c8[0][3] == plVar3) goto LAB_23e76aae0;
        local_118 = (longlong *)0x0;
        plVar19 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        local_120 = (longlong *)0x0;
        plVar20 = (longlong *)0x0;
        uVar21 = 2;
        uVar17 = 0x4d1;
        local_128 = (code *)0x0;
        local_100 = (code *)0x0;
        local_110 = (longlong *)0x0;
        local_104 = 2;
        plVar10 = (longlong *)0x0;
        goto LAB_23e76aeb0;
      }
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      lVar11 = FUN_23e8dfe80();
      uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
      if (lVar11 == 0) {
        FUN_23e915740(param_1,local_d8,DAT_23eed9460);
        if (local_c8[0] == (longlong *)0x0) {
LAB_23e76be58:
          local_118 = (longlong *)0x0;
          plVar19 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          uVar21 = 2;
          local_120 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          plVar20 = (longlong *)0x0;
          local_104 = 2;
          uVar17 = 0x4d4;
          local_128 = (code *)0x0;
          local_100 = (code *)0x0;
          local_110 = (longlong *)0x0;
          goto LAB_23e76afdf;
        }
        plVar9 = (longlong *)local_c8[0][3];
        plVar10 = (longlong *)0x0;
joined_r0x00023e76b7d8:
        if (plVar3 == plVar9) goto LAB_23e76aae0;
        local_118 = (longlong *)0x0;
        plVar19 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        local_120 = (longlong *)0x0;
        plVar20 = (longlong *)0x0;
        uVar21 = 2;
        uVar17 = 0x4d4;
        local_128 = (code *)0x0;
        local_100 = (code *)0x0;
        local_110 = (longlong *)0x0;
        local_104 = 2;
        goto LAB_23e76aeb0;
      }
      *(undefined4 *)(plVar3 + 5) = 0x4d4;
      plVar10 = (longlong *)FUN_23e91a870(param_1,lVar11);
      uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
      if (plVar10 == (longlong *)0x0) {
        local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
        plStack_d0 = *(longlong **)(param_1 + 0x68);
        local_c8[0] = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (local_c8[0] == (longlong *)0x0) goto LAB_23e76be58;
        plVar9 = (longlong *)local_c8[0][3];
        goto joined_r0x00023e76b7d8;
      }
      plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a98);
      uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
      if (plVar9 == (longlong *)0x0) {
        local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
        plStack_d0 = *(longlong **)(param_1 + 0x68);
        local_c8[0] = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (local_c8[0] != (longlong *)0x0) {
          if (plVar3 == (longlong *)local_c8[0][3]) goto LAB_23e76cfcb;
          local_118 = (longlong *)0x0;
          plVar19 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          plVar20 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          uVar21 = 2;
          uVar17 = 0x4d7;
          local_128 = (code *)0x0;
          local_100 = (code *)0x0;
          local_110 = (longlong *)0x0;
          local_104 = 2;
          plVar13 = (longlong *)0x0;
          goto LAB_23e76aeb0;
        }
LAB_23e76bd6c:
        local_104 = 2;
        plVar19 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        uVar21 = 2;
        local_118 = (longlong *)0x0;
        plVar20 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        uVar17 = 0x4d7;
        local_120 = (longlong *)0x0;
        local_128 = (code *)0x0;
        local_100 = (code *)0x0;
        local_110 = (longlong *)0x0;
        goto LAB_23e76afdf;
      }
      cVar7 = FUN_23e8d9ac0(plVar10,DAT_23eed8a98,plVar9);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
      if (cVar7 == '\0') {
        local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
        plStack_d0 = *(longlong **)(param_1 + 0x68);
        local_c8[0] = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (local_c8[0] == (longlong *)0x0) goto LAB_23e76bd6c;
        plVar19 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        plVar20 = (longlong *)0x0;
        plVar14 = (longlong *)local_c8[0][3];
        local_104 = 2;
        uVar17 = 0x4d7;
        plVar13 = (longlong *)0x0;
        local_118 = (longlong *)0x0;
        local_120 = (longlong *)0x0;
        local_128 = (code *)0x0;
        local_100 = (code *)0x0;
        local_110 = (longlong *)0x0;
joined_r0x00023e76b4f6:
        uVar21 = 2;
        goto joined_r0x00023e76e1db;
      }
      plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8aa8);
      uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
      if (plVar9 == (longlong *)0x0) {
        local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
        plStack_d0 = *(longlong **)(param_1 + 0x68);
        local_c8[0] = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (local_c8[0] != (longlong *)0x0) {
          if ((longlong *)local_c8[0][3] == plVar3) goto LAB_23e76cfcb;
          local_118 = (longlong *)0x0;
          plVar19 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          plVar20 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          uVar21 = 2;
          uVar17 = 0x4d8;
          local_128 = (code *)0x0;
          local_100 = (code *)0x0;
          local_110 = (longlong *)0x0;
          local_104 = 2;
          plVar13 = (longlong *)0x0;
          goto LAB_23e76aeb0;
        }
LAB_23e76c061:
        local_104 = 2;
        plVar19 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        uVar21 = 2;
        local_118 = (longlong *)0x0;
        plVar20 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        uVar17 = 0x4d8;
        local_120 = (longlong *)0x0;
        local_128 = (code *)0x0;
        local_100 = (code *)0x0;
        local_110 = (longlong *)0x0;
      }
      else {
        iVar8 = FUN_23e913250(plVar9,DAT_23eed90d8);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
        if (iVar8 == -1) {
LAB_23e76b56c:
          local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
          plStack_d0 = *(longlong **)(param_1 + 0x68);
          local_c8[0] = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (local_c8[0] != (longlong *)0x0) {
            if ((longlong *)local_c8[0][3] != plVar3) {
              local_104 = 2;
              plVar19 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              uVar21 = 2;
              local_118 = (longlong *)0x0;
              plVar20 = (longlong *)0x0;
              plVar13 = (longlong *)0x0;
              uVar17 = 0x4d8;
              local_120 = (longlong *)0x0;
              local_128 = (code *)0x0;
              local_100 = (code *)0x0;
              local_110 = (longlong *)0x0;
              goto LAB_23e76aeb0;
            }
LAB_23e76cfcb:
            uVar21 = 2;
            plVar19 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            local_118 = (longlong *)0x0;
            plVar20 = (longlong *)0x0;
            plVar13 = (longlong *)0x0;
            local_120 = (longlong *)0x0;
            local_128 = (code *)0x0;
            local_104 = 2;
            local_100 = (code *)0x0;
            local_110 = (longlong *)0x0;
            plVar12 = local_c8[0];
            goto LAB_23e76ab3a;
          }
          goto LAB_23e76c061;
        }
        uVar18 = DAT_23eed9220;
        if (iVar8 != 1) {
          uVar18 = DAT_23eed9388;
        }
        cVar7 = FUN_23e8d9ac0(plVar10,DAT_23eed9390,uVar18);
        uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
        if (cVar7 == '\0') goto LAB_23e76b56c;
        plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8aa8);
        uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
        if (plVar9 == (longlong *)0x0) {
          local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
          plStack_d0 = *(longlong **)(param_1 + 0x68);
          local_c8[0] = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (local_c8[0] == (longlong *)0x0) goto LAB_23e76d17c;
          if ((longlong *)local_c8[0][3] != plVar3) {
            local_118 = (longlong *)0x0;
            plVar19 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            plVar20 = (longlong *)0x0;
            local_120 = (longlong *)0x0;
            uVar21 = 2;
            uVar17 = 0x4db;
            local_128 = (code *)0x0;
            local_100 = (code *)0x0;
            local_110 = (longlong *)0x0;
            local_104 = 2;
            plVar13 = (longlong *)0x0;
            goto LAB_23e76aeb0;
          }
          goto LAB_23e76cfcb;
        }
        iVar8 = FUN_23e913250(plVar9,DAT_23eed90d8);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        pcVar24 = _Py_NoneStruct_exref;
        uVar6 = DAT_23eed9498;
        uVar18 = DAT_23eed9470;
        pcVar5 = DAT_23eed9468;
        plVar13 = DAT_23eed8950;
        pcVar15 = DAT_23ed6ccf0;
        plVar9 = DAT_23ed6a498;
        uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
        if (iVar8 == -1) {
          local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
          plStack_d0 = *(longlong **)(param_1 + 0x68);
          local_c8[0] = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (local_c8[0] != (longlong *)0x0) {
            if ((longlong *)local_c8[0][3] == plVar3) goto LAB_23e76cfcb;
            uVar21 = 2;
            plVar19 = (longlong *)0x0;
            local_100 = (code *)0x0;
            plVar9 = (longlong *)0x0;
            plVar20 = (longlong *)0x0;
            uVar17 = 0x4db;
            local_110 = (longlong *)0x0;
            plVar13 = (longlong *)0x0;
            local_118 = (longlong *)0x0;
            local_120 = (longlong *)0x0;
            local_128 = (code *)0x0;
            local_104 = 2;
            goto LAB_23e76aeb0;
          }
LAB_23e76d17c:
          uVar21 = 2;
          plVar19 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          plVar20 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          uVar17 = 0x4db;
          local_120 = (longlong *)0x0;
          local_128 = (code *)0x0;
          local_104 = 2;
          local_100 = (code *)0x0;
          local_110 = (longlong *)0x0;
          goto LAB_23e76afdf;
        }
        if (iVar8 == 1) {
          *(undefined4 *)(plVar3 + 5) = 0x4dc;
          local_98 = pcVar15;
          local_a8 = pcVar24;
          local_a0 = uVar18;
          local_b8 = pcVar5;
          plStack_b0 = plVar13;
          if (plVar9 == (longlong *)0x0) {
            plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"__import__");
            uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
            if (plVar9 == (longlong *)0x0) goto LAB_23e76d169;
            *plVar9 = *plVar9 + 1;
            DAT_23ed6a498 = plVar9;
          }
          plVar9 = (longlong *)FUN_23e95b390(param_1,plVar9,&local_b8);
          uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
          if (plVar9 == (longlong *)0x0) {
            local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
            plStack_d0 = *(longlong **)(param_1 + 0x68);
            local_c8[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (local_c8[0] != (longlong *)0x0) {
              if ((longlong *)local_c8[0][3] == plVar3) goto LAB_23e76cfcb;
              plVar19 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              plVar20 = (longlong *)0x0;
              local_118 = (longlong *)0x0;
              plVar13 = (longlong *)0x0;
              uVar21 = 2;
              uVar17 = 0x4dc;
              local_120 = (longlong *)0x0;
              local_128 = (code *)0x0;
              local_100 = (code *)0x0;
              local_104 = 2;
              local_110 = (longlong *)0x0;
              goto LAB_23e76aeb0;
            }
LAB_23e76d786:
            uVar21 = 2;
            plVar19 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            local_118 = (longlong *)0x0;
            plVar20 = (longlong *)0x0;
            plVar13 = (longlong *)0x0;
            uVar17 = 0x4dc;
            local_120 = (longlong *)0x0;
            local_128 = (code *)0x0;
            local_104 = 2;
            local_100 = (code *)0x0;
            local_110 = (longlong *)0x0;
            goto LAB_23e76afdf;
          }
          if (((code *)plVar9[1] == PyModule_Type_exref) || (iVar8 = PyType_IsSubtype(), iVar8 != 0)
             ) {
            uVar18 = DAT_23eed9478;
            plVar19 = DAT_23eed8950;
            pcVar15 = DAT_23ed6ccf0;
            plVar13 = (longlong *)PyObject_GetAttr(plVar9,DAT_23eed9478);
            if (plVar13 == (longlong *)0x0) {
              plVar13 = (longlong *)FUN_23e970390(param_1,plVar9,plVar19,uVar18,pcVar15);
              goto LAB_23e76bb55;
            }
            lVar11 = *plVar9;
            *plVar9 = lVar11 + -1;
            if (lVar11 + -1 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
          }
          else {
            plVar13 = (longlong *)FUN_23e8d2f70(param_1,plVar9,DAT_23eed9478);
LAB_23e76bb55:
            lVar11 = *plVar9;
            *plVar9 = lVar11 + -1;
            if (lVar11 + -1 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
            if (plVar13 == (longlong *)0x0) {
              local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
              plStack_d0 = *(longlong **)(param_1 + 0x68);
              local_c8[0] = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (local_c8[0] != (longlong *)0x0) {
                if ((longlong *)local_c8[0][3] != plVar3) {
                  plVar19 = (longlong *)0x0;
                  plVar9 = (longlong *)0x0;
                  plVar20 = (longlong *)0x0;
                  local_118 = (longlong *)0x0;
                  uVar21 = 2;
                  uVar17 = 0x4dc;
                  local_120 = (longlong *)0x0;
                  local_128 = (code *)0x0;
                  local_100 = (code *)0x0;
                  local_110 = (longlong *)0x0;
                  local_104 = 2;
                  goto LAB_23e76aeb0;
                }
                goto LAB_23e76cfcb;
              }
              goto LAB_23e76d786;
            }
          }
          cVar7 = FUN_23e8d9ac0(plVar10,DAT_23eed9480,plVar13);
          uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
          if (cVar7 == '\0') {
            local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
            plStack_d0 = *(longlong **)(param_1 + 0x68);
            local_c8[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (local_c8[0] == (longlong *)0x0) {
              plVar19 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              plVar20 = (longlong *)0x0;
              local_118 = (longlong *)0x0;
              uVar21 = 2;
              uVar17 = 0x4dd;
              local_120 = (longlong *)0x0;
              local_128 = (code *)0x0;
              local_100 = (code *)0x0;
              local_104 = 2;
              local_110 = (longlong *)0x0;
              goto LAB_23e76afdf;
            }
            if ((longlong *)local_c8[0][3] == plVar3) {
LAB_23e76d079:
              uVar21 = 2;
              plVar19 = (longlong *)0x0;
              local_118 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              plVar20 = (longlong *)0x0;
              local_120 = (longlong *)0x0;
              local_128 = (code *)0x0;
              local_104 = 2;
              local_100 = (code *)0x0;
              local_110 = (longlong *)0x0;
              plVar12 = local_c8[0];
              goto LAB_23e76ab3a;
            }
            plVar19 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            local_118 = (longlong *)0x0;
            plVar20 = (longlong *)0x0;
            uVar21 = 2;
            uVar17 = 0x4dd;
            local_120 = (longlong *)0x0;
            local_128 = (code *)0x0;
            local_104 = 2;
            local_100 = (code *)0x0;
            local_110 = (longlong *)0x0;
          }
          else {
            cVar7 = FUN_23e8d9ac0(plVar10,DAT_23eed9490,DAT_23eed9488);
            uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
            local_110 = (longlong *)0x0;
            if (cVar7 != '\0') goto LAB_23e76a6c4;
            local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
            plStack_d0 = *(longlong **)(param_1 + 0x68);
            local_c8[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (local_c8[0] == (longlong *)0x0) {
              plVar19 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              plVar20 = (longlong *)0x0;
              local_118 = (longlong *)0x0;
              uVar21 = 2;
              uVar17 = 0x4de;
              local_120 = (longlong *)0x0;
              local_128 = (code *)0x0;
              local_100 = (code *)0x0;
              local_104 = 2;
              local_110 = (longlong *)0x0;
              goto LAB_23e76afdf;
            }
            if ((longlong *)local_c8[0][3] == plVar3) goto LAB_23e76d079;
            plVar19 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            local_118 = (longlong *)0x0;
            plVar20 = (longlong *)0x0;
            uVar21 = 2;
            uVar17 = 0x4de;
            local_120 = (longlong *)0x0;
            local_128 = (code *)0x0;
            local_104 = 2;
            local_100 = (code *)0x0;
            local_110 = (longlong *)0x0;
          }
          goto LAB_23e76aeb0;
        }
        *(undefined4 *)(plVar3 + 5) = 0x4e0;
        local_68 = pcVar15;
        local_78 = pcVar24;
        local_70 = uVar6;
        local_88 = pcVar5;
        plStack_80 = plVar13;
        if (plVar9 == (longlong *)0x0) {
          plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"__import__");
          uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
          if (plVar9 == (longlong *)0x0) {
LAB_23e76d169:
            PyErr_PrintEx(0,0);
            Py_Exit(1);
            goto LAB_23e76d17c;
          }
          *plVar9 = *plVar9 + 1;
          DAT_23ed6a498 = plVar9;
        }
        plVar9 = (longlong *)FUN_23e95b390(param_1,plVar9,&local_88);
        uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
        if (plVar9 == (longlong *)0x0) {
          local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
          plStack_d0 = *(longlong **)(param_1 + 0x68);
          local_c8[0] = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (local_c8[0] != (longlong *)0x0) {
            if ((longlong *)local_c8[0][3] == plVar3) goto LAB_23e76cfcb;
            plVar19 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            plVar20 = (longlong *)0x0;
            local_118 = (longlong *)0x0;
            uVar21 = 2;
            uVar17 = 0x4e0;
            local_120 = (longlong *)0x0;
            local_128 = (code *)0x0;
            local_100 = (code *)0x0;
            local_110 = (longlong *)0x0;
            local_104 = 2;
            plVar13 = (longlong *)0x0;
            goto LAB_23e76aeb0;
          }
LAB_23e76d2f0:
          uVar21 = 2;
          plVar19 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          plVar20 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          uVar17 = 0x4e0;
          local_128 = (code *)0x0;
          local_104 = 2;
          local_100 = (code *)0x0;
          local_110 = (longlong *)0x0;
          goto LAB_23e76afdf;
        }
        if (((code *)plVar9[1] == PyModule_Type_exref) ||
           (iVar8 = PyType_IsSubtype(), uVar18 = DAT_23eed94a0, iVar8 != 0)) {
          uVar18 = DAT_23eed94a0;
          plVar13 = DAT_23eed8950;
          pcVar15 = DAT_23ed6ccf0;
          local_110 = (longlong *)PyObject_GetAttr(plVar9,DAT_23eed94a0);
          if (local_110 == (longlong *)0x0) {
            local_110 = (longlong *)FUN_23e970390(param_1,plVar9,plVar13,uVar18,pcVar15);
            goto LAB_23e76b973;
          }
LAB_23e76a675:
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
        }
        else {
          local_110 = (longlong *)PyObject_GetAttr(plVar9,DAT_23eed94a0);
          if (local_110 != (longlong *)0x0) goto LAB_23e76a675;
          local_110 = (longlong *)FUN_23e8d2cf0(param_1,plVar9,uVar18);
LAB_23e76b973:
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))();
          }
          uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
          if (local_110 == (longlong *)0x0) {
            local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
            plStack_d0 = *(longlong **)(param_1 + 0x68);
            local_c8[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (local_c8[0] != (longlong *)0x0) {
              if ((longlong *)local_c8[0][3] != plVar3) {
                plVar19 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                plVar20 = (longlong *)0x0;
                local_118 = (longlong *)0x0;
                plVar13 = (longlong *)0x0;
                uVar21 = 2;
                local_120 = (longlong *)0x0;
                local_128 = (code *)0x0;
                local_100 = (code *)0x0;
                uVar17 = 0x4e0;
                local_104 = 2;
                goto LAB_23e76aeb0;
              }
              goto LAB_23e76cfcb;
            }
            goto LAB_23e76d2f0;
          }
        }
        cVar7 = FUN_23e8d9ac0(plVar10,DAT_23eed9480);
        uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
        if (cVar7 == '\0') {
          local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
          plStack_d0 = *(longlong **)(param_1 + 0x68);
          local_c8[0] = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (local_c8[0] != (longlong *)0x0) {
            if ((longlong *)local_c8[0][3] == plVar3) {
LAB_23e76c4ee:
              uVar21 = 2;
              plVar19 = (longlong *)0x0;
              local_118 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              plVar20 = (longlong *)0x0;
              plVar13 = (longlong *)0x0;
              local_120 = (longlong *)0x0;
              local_128 = (code *)0x0;
              local_104 = 2;
              local_100 = (code *)0x0;
              plVar12 = local_c8[0];
              goto LAB_23e76ab3a;
            }
            uVar21 = 2;
            local_118 = (longlong *)0x0;
            plVar19 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            plVar13 = (longlong *)0x0;
            local_120 = (longlong *)0x0;
            plVar20 = (longlong *)0x0;
            uVar17 = 0x4e1;
            local_128 = (code *)0x0;
            local_104 = 2;
            local_100 = (code *)0x0;
            goto LAB_23e76aeb0;
          }
          plVar19 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          plVar20 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          uVar17 = 0x4e1;
          local_120 = (longlong *)0x0;
          local_128 = (code *)0x0;
          local_100 = (code *)0x0;
          uVar21 = 2;
          local_104 = 2;
          plVar13 = (longlong *)0x0;
          goto LAB_23e76afdf;
        }
        plVar13 = (longlong *)0x0;
        cVar7 = FUN_23e8d9ac0();
        uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
        if (cVar7 == '\0') {
          local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
          plStack_d0 = *(longlong **)(param_1 + 0x68);
          local_c8[0] = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (local_c8[0] == (longlong *)0x0) {
            plVar19 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            plVar20 = (longlong *)0x0;
            local_118 = (longlong *)0x0;
            uVar21 = 2;
            uVar17 = 0x4e2;
            local_120 = (longlong *)0x0;
            local_128 = (code *)0x0;
            local_100 = (code *)0x0;
            local_104 = 2;
            plVar13 = (longlong *)0x0;
            goto LAB_23e76afdf;
          }
          if ((longlong *)local_c8[0][3] == plVar3) goto LAB_23e76c4ee;
          uVar21 = 2;
          local_100 = (code *)0x0;
          plVar19 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          plVar20 = (longlong *)0x0;
          uVar17 = 0x4e2;
          local_120 = (longlong *)0x0;
          local_128 = (code *)0x0;
          local_104 = 2;
          goto LAB_23e76aeb0;
        }
LAB_23e76a6c4:
        lVar11 = FUN_23e8dffd0();
        uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
        if (lVar11 == 0) {
          FUN_23e915740(param_1,local_d8,DAT_23eed9400);
joined_r0x00023e76c5e2:
          local_100 = (code *)0x0;
          if (local_c8[0] != (longlong *)0x0) {
            if ((longlong *)local_c8[0][3] != plVar3) {
              plVar19 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              plVar20 = (longlong *)0x0;
              local_118 = (longlong *)0x0;
              uVar17 = 0x4e5;
              uVar21 = 2;
              local_120 = (longlong *)0x0;
              local_128 = (code *)0x0;
              local_104 = 2;
              goto LAB_23e76aeb0;
            }
LAB_23e76c7b2:
            uVar21 = 2;
            plVar19 = (longlong *)0x0;
            local_118 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            plVar20 = (longlong *)0x0;
            local_120 = (longlong *)0x0;
            local_128 = (code *)0x0;
            local_104 = 2;
            local_100 = (code *)0x0;
            plVar12 = local_c8[0];
            goto LAB_23e76ab3a;
          }
LAB_23e76c6e1:
          uVar21 = 2;
          plVar19 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          plVar20 = (longlong *)0x0;
          uVar17 = 0x4e5;
          local_120 = (longlong *)0x0;
          local_128 = (code *)0x0;
          local_104 = 2;
          local_100 = (code *)0x0;
        }
        else {
          *(undefined4 *)(plVar3 + 5) = 0x4e5;
          plVar9 = (longlong *)FUN_23e91a870(param_1,lVar11);
          uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
          if (plVar9 == (longlong *)0x0) {
            local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
            plStack_d0 = *(longlong **)(param_1 + 0x68);
            local_c8[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto joined_r0x00023e76c5e2;
          }
          cVar7 = FUN_23e8d9ac0(plVar10,DAT_23eed9410,plVar9);
          lVar11 = *plVar9;
          *plVar9 = lVar11 + -1;
          if (lVar11 + -1 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
          if (cVar7 == '\0') {
            local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
            plStack_d0 = *(longlong **)(param_1 + 0x68);
            local_c8[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (local_c8[0] != (longlong *)0x0) {
              if ((longlong *)local_c8[0][3] != plVar3) {
                uVar21 = 2;
                plVar19 = (longlong *)0x0;
                local_118 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                plVar20 = (longlong *)0x0;
                uVar17 = 0x4e5;
                local_120 = (longlong *)0x0;
                local_128 = (code *)0x0;
                local_104 = 2;
                local_100 = (code *)0x0;
                goto LAB_23e76aeb0;
              }
              goto LAB_23e76c7b2;
            }
            goto LAB_23e76c6e1;
          }
          *(undefined4 *)(plVar3 + 5) = 0x4e8;
          plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar10,DAT_23eed9418);
          uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
          if (plVar9 == (longlong *)0x0) {
            local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
            plStack_d0 = *(longlong **)(param_1 + 0x68);
            local_c8[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (local_c8[0] == (longlong *)0x0) {
LAB_23e76dcca:
              uVar21 = 2;
              plVar19 = (longlong *)0x0;
              local_118 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              plVar20 = (longlong *)0x0;
              uVar17 = 0x4e8;
              local_120 = (longlong *)0x0;
              local_128 = (code *)0x0;
              local_104 = 2;
              local_100 = (code *)0x0;
              goto LAB_23e76afdf;
            }
            if ((longlong *)local_c8[0][3] == plVar3) goto LAB_23e76c7b2;
            plVar19 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            plVar20 = (longlong *)0x0;
            local_118 = (longlong *)0x0;
            uVar17 = 0x4e8;
            local_120 = (longlong *)0x0;
            local_128 = (code *)0x0;
            uVar21 = 2;
            local_104 = 2;
            local_100 = (code *)0x0;
            goto LAB_23e76aeb0;
          }
          iVar8 = FUN_23a35f020(plVar9);
          lVar11 = *plVar9;
          *plVar9 = lVar11 + -1;
          if (lVar11 + -1 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          uVar18 = DAT_23eed8a98;
          local_100 = DAT_23ed6ccf0;
          uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
          if (iVar8 == -1) {
            local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
            plStack_d0 = *(longlong **)(param_1 + 0x68);
            local_c8[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (local_c8[0] == (longlong *)0x0) goto LAB_23e76dcca;
            if ((longlong *)local_c8[0][3] == plVar3) goto LAB_23e76c7b2;
            uVar21 = 2;
            plVar19 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            local_118 = (longlong *)0x0;
            plVar20 = (longlong *)0x0;
            uVar17 = 0x4e8;
            local_120 = (longlong *)0x0;
            local_128 = (code *)0x0;
            local_104 = 2;
            local_100 = (code *)0x0;
            goto LAB_23e76aeb0;
          }
          if (iVar8 == 0) {
            *(undefined4 *)(plVar3 + 5) = 0x4e9;
            plVar9 = (longlong *)FUN_23e915840(param_1,plVar1);
            if (plVar9 == (longlong *)0x0) {
              local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
              plStack_d0 = *(longlong **)(param_1 + 0x68);
              local_c8[0] = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (local_c8[0] == (longlong *)0x0) {
                plVar19 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                plVar20 = (longlong *)0x0;
                local_118 = (longlong *)0x0;
                uVar21 = 2;
                uVar17 = 0x4e9;
                local_120 = (longlong *)0x0;
                local_104 = 2;
                local_128 = (code *)0x0;
                local_100 = (code *)0x0;
                goto LAB_23e76afdf;
              }
              if ((longlong *)local_c8[0][3] == plVar3) goto LAB_23e76c7b2;
              plVar19 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              local_118 = (longlong *)0x0;
              plVar20 = (longlong *)0x0;
              uVar21 = 2;
              uVar17 = 0x4e9;
              local_120 = (longlong *)0x0;
              local_100 = (code *)0x0;
              local_104 = 2;
              local_128 = (code *)0x0;
            }
            else {
              lVar11 = *plVar9;
              *plVar9 = lVar11 + -1;
              if (lVar11 + -1 == 0) {
                FUN_23a334bc0(plVar9);
              }
              *(undefined4 *)(plVar3 + 5) = 0x4ea;
              plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar1);
              if (plVar9 == (longlong *)0x0) {
                local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_d0 = *(longlong **)(param_1 + 0x68);
                local_c8[0] = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (local_c8[0] == (longlong *)0x0) {
                  plVar19 = (longlong *)0x0;
                  plVar9 = (longlong *)0x0;
                  plVar20 = (longlong *)0x0;
                  local_118 = (longlong *)0x0;
                  uVar21 = 2;
                  uVar17 = 0x4ea;
                  local_120 = (longlong *)0x0;
                  local_104 = 2;
                  local_128 = (code *)0x0;
                  local_100 = (code *)0x0;
                  goto LAB_23e76afdf;
                }
                if ((longlong *)local_c8[0][3] == plVar3) goto LAB_23e76c7b2;
                plVar19 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                local_118 = (longlong *)0x0;
                plVar20 = (longlong *)0x0;
                uVar21 = 2;
                uVar17 = 0x4ea;
                local_120 = (longlong *)0x0;
                local_100 = (code *)0x0;
                local_104 = 2;
                local_128 = (code *)0x0;
              }
              else {
                lVar11 = *plVar9;
                *plVar9 = lVar11 + -1;
                if (lVar11 + -1 == 0) {
                  FUN_23a334bc0(plVar9);
                }
                *(undefined4 *)(plVar3 + 5) = 0x4eb;
                plVar9 = (longlong *)FUN_23e915840(param_1,plVar1,DAT_23eed8c50);
                if (plVar9 == (longlong *)0x0) {
                  local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                  plStack_d0 = *(longlong **)(param_1 + 0x68);
                  local_c8[0] = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  if (local_c8[0] == (longlong *)0x0) {
                    plVar19 = (longlong *)0x0;
                    plVar9 = (longlong *)0x0;
                    plVar20 = (longlong *)0x0;
                    local_118 = (longlong *)0x0;
                    uVar21 = 2;
                    local_120 = (longlong *)0x0;
                    uVar17 = 0x4eb;
                    local_104 = 2;
                    local_128 = (code *)0x0;
                    local_100 = (code *)0x0;
                    goto LAB_23e76afdf;
                  }
                  if ((longlong *)local_c8[0][3] == plVar3) goto LAB_23e76c7b2;
                  plVar19 = (longlong *)0x0;
                  plVar9 = (longlong *)0x0;
                  local_118 = (longlong *)0x0;
                  plVar20 = (longlong *)0x0;
                  uVar21 = 2;
                  local_120 = (longlong *)0x0;
                  local_100 = (code *)0x0;
                  uVar17 = 0x4eb;
                  local_104 = 2;
                  local_128 = (code *)0x0;
                }
                else {
                  lVar11 = *plVar9;
                  *plVar9 = lVar11 + -1;
                  if (lVar11 + -1 == 0) {
                    FUN_23a334bc0(plVar9);
                  }
                  cVar7 = FUN_23e8d9ac0(plVar1,DAT_23eed89b8,_Py_FalseStruct_exref);
                  if (cVar7 != '\0') {
                    lVar11 = *(longlong *)pcVar24;
                    goto LAB_23e76a09a;
                  }
                  local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                  plStack_d0 = *(longlong **)(param_1 + 0x68);
                  local_c8[0] = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  if (local_c8[0] == (longlong *)0x0) {
                    plVar19 = (longlong *)0x0;
                    plVar9 = (longlong *)0x0;
                    plVar20 = (longlong *)0x0;
                    local_118 = (longlong *)0x0;
                    uVar17 = 0x4ec;
                    uVar21 = 2;
                    local_120 = (longlong *)0x0;
                    local_128 = (code *)0x0;
                    local_104 = 2;
                    local_100 = (code *)0x0;
                    goto LAB_23e76afdf;
                  }
                  if ((longlong *)local_c8[0][3] == plVar3) goto LAB_23e76c7b2;
                  plVar19 = (longlong *)0x0;
                  local_118 = (longlong *)0x0;
                  plVar9 = (longlong *)0x0;
                  uVar21 = 2;
                  plVar20 = (longlong *)0x0;
                  local_120 = (longlong *)0x0;
                  uVar17 = 0x4ec;
                  local_128 = (code *)0x0;
                  local_104 = 2;
                  local_100 = (code *)0x0;
                }
              }
            }
            goto LAB_23e76aeb0;
          }
          *(longlong *)DAT_23ed6ccf0 = *(longlong *)DAT_23ed6ccf0 + 1;
          plVar9 = (longlong *)FUN_23e8bc2f0(plVar10,uVar18);
          uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
          local_104 = 0;
          if (plVar9 == (longlong *)0x0) {
LAB_23e76c7f7:
            local_c8[0] = *(longlong **)(param_1 + 0x70);
            local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
            plStack_d0 = *(longlong **)(param_1 + 0x68);
            uVar17 = 0x4f3;
            plVar20 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            local_118 = (longlong *)0x0;
            local_120 = (longlong *)0x0;
            local_128 = (code *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e76c848:
            plVar19 = local_c8[0];
            local_c8[0] = (longlong *)0x0;
            local_78 = (code *)plVar19;
            plVar9 = *(longlong **)(param_1 + 0x138);
            local_88 = (code *)local_d8;
            plStack_80 = plStack_d0;
            local_d8 = (undefined1  [8])0x0;
            plStack_d0 = (longlong *)0x0;
            if (plVar9 != (longlong *)0x0) {
              *plVar9 = *plVar9 + 1;
            }
            if (plVar19 == (longlong *)0x0) {
              pcVar15 = (code *)FUN_23e8d6280(plVar3,uVar17);
            }
            else {
              pcVar15 = (code *)FUN_23e8d6280(plVar3,uVar17);
              *(longlong **)(pcVar15 + 0x10) = plVar19;
              *plVar19 = *plVar19 + 1;
            }
            if ((local_78 != (code *)0x0) &&
               (*(longlong *)local_78 = *(longlong *)local_78 + -1, *(longlong *)local_78 == 0)) {
              FUN_23a334bc0();
            }
            local_78 = pcVar15;
            FUN_23a35ef40(param_1,&local_88);
            iVar8 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8));
            if (iVar8 == 0) {
              cVar7 = FUN_23e8ba320(*(undefined8 *)(param_1 + 0x138));
              plVar19 = local_c8[0];
              local_104 = -(uint)(cVar7 == '\0') & 0x4f2;
              if (local_c8[0] == (longlong *)0x0) {
                _local_d8 = (undefined1  [16])0x0;
                FUN_23ebf6ae0(param_1,plVar9);
                local_c8[0] = (longlong *)0x0;
                if (local_104 == 0) {
                  uVar17 = (undefined4)plVar3[5];
                  plVar19 = (longlong *)0x0;
                  plVar9 = (longlong *)0x0;
                  uVar21 = 2;
                }
                else {
                  plVar19 = (longlong *)0x0;
                  plVar9 = (longlong *)0x0;
                  uVar21 = 2;
                  local_104 = 0;
                  uVar17 = 0x4f2;
                }
                goto LAB_23e76afdf;
              }
              if ((longlong *)local_c8[0][3] == plVar3) {
                *(undefined4 *)(plVar3 + 5) = *(undefined4 *)((longlong)local_c8[0] + 0x24);
              }
              local_c8[0] = (longlong *)0x0;
              _local_d8 = (undefined1  [16])0x0;
              FUN_23ebf6ae0(param_1,plVar9);
              local_c8[0] = plVar19;
              if ((longlong *)plVar19[3] != plVar3) {
                if (local_104 == 0) {
                  uVar17 = (undefined4)plVar3[5];
                  uVar21 = 2;
                  plVar19 = (longlong *)0x0;
                  plVar9 = (longlong *)0x0;
                }
                else {
                  plVar19 = (longlong *)0x0;
                  plVar9 = (longlong *)0x0;
                  uVar17 = 0x4f2;
                  local_104 = 0;
                  uVar21 = 2;
                }
                goto LAB_23e76aeb0;
              }
              local_104 = 0;
            }
            else {
              plVar19 = *(longlong **)(param_1 + 0x138);
              *plVar19 = *plVar19 + 1;
              if (plVar1 == (longlong *)0x0) {
                FUN_23e8ba2b0(local_d8,DAT_23eed8d30);
                if ((local_d8 != (undefined1  [8])pcVar24) && (local_d8 != (undefined1  [8])0x0)) {
                  FUN_23e91b1b0(param_1,local_d8,local_d8 + 8,local_c8);
                }
                FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),plStack_d0);
              }
              else {
                plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8b40);
                plVar14 = DAT_23eed94d8;
                if (plVar12 == (longlong *)0x0) {
LAB_23e76d4f0:
                  local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                  plStack_d0 = *(longlong **)(param_1 + 0x68);
                  local_c8[0] = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                }
                else {
                  plVar16 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                  *plVar14 = *plVar14 + 1;
                  plVar16[3] = (longlong)plVar14;
                  lVar11 = FUN_23e94f9d0(param_1,plVar19,DAT_23ed6cd28);
                  if (lVar11 == 0) {
                    local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    plStack_d0 = *(longlong **)(param_1 + 0x68);
                    local_c8[0] = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      FUN_23a334bc0();
                    }
                    *plVar16 = *plVar16 + -1;
                    if (*plVar16 == 0) {
                      FUN_23a334bc0();
                    }
                  }
                  else {
                    plVar16[4] = lVar11;
                    plVar14 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
                    *plVar16 = *plVar16 + -1;
                    if (*plVar16 == 0) {
                      FUN_23a334bc0();
                    }
                    if (plVar14 != (longlong *)0x0) {
                      *(undefined4 *)(plVar3 + 5) = 0x509;
                      plVar16 = (longlong *)FUN_23e914090(param_1,plVar12);
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        FUN_23a334bc0();
                      }
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        FUN_23a334bc0();
                      }
                      if (plVar16 != (longlong *)0x0) {
                        *plVar16 = *plVar16 + -1;
                        if (*plVar16 == 0) {
                          FUN_23a334bc0(plVar16);
                        }
                        lVar11 = *plVar19;
                        *plVar19 = lVar11 + -1;
                        if (lVar11 + -1 == 0) {
                          FUN_23a334bc0(plVar19);
                        }
                        FUN_23ebf6ae0(param_1,plVar9);
                        goto LAB_23e76ca87;
                      }
                      goto LAB_23e76d4f0;
                    }
                    local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    plStack_d0 = *(longlong **)(param_1 + 0x68);
                    local_c8[0] = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      FUN_23a334bc0();
                    }
                  }
                }
              }
              plVar12 = local_c8[0];
              plVar14 = plStack_d0;
              auVar22 = local_d8;
              _local_d8 = (undefined1  [16])0x0;
              lVar11 = *plVar19;
              local_c8[0] = (longlong *)0x0;
              *plVar19 = lVar11 + -1;
              if (lVar11 + -1 == 0) {
                FUN_23a334bc0(plVar19);
              }
              local_c8[0] = (longlong *)0x0;
              _local_d8 = (undefined1  [16])0x0;
              FUN_23ebf6ae0(param_1,plVar9);
              local_c8[0] = plVar12;
              local_d8 = auVar22;
              plStack_d0 = plVar14;
              if (plVar12 == (longlong *)0x0) {
                plVar19 = (longlong *)0x0;
                uVar21 = 2;
                uVar17 = 0x509;
                plVar9 = (longlong *)0x0;
                goto LAB_23e76afdf;
              }
              if ((longlong *)plVar12[3] != plVar3) {
                plVar19 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                uVar17 = 0x509;
                uVar21 = 2;
                goto LAB_23e76aeb0;
              }
            }
LAB_23e76d491:
            uVar21 = 2;
            plVar19 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            plVar12 = local_c8[0];
            goto LAB_23e76ab3a;
          }
          *(undefined4 *)(plVar3 + 5) = 0x4f3;
          local_128 = (code *)FUN_23e91bfe0(param_1,plVar9,DAT_23eed8a98);
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            FUN_23a334bc0(plVar9);
          }
          uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
          if (local_128 == (code *)0x0) goto LAB_23e76c7f7;
          if (local_128 != pcVar24) {
            *(undefined4 *)(plVar3 + 5) = 0x4f6;
            local_120 = (longlong *)FUN_23e915840(param_1,plVar10);
            uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
            if (local_120 == (longlong *)0x0) {
              local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
              plStack_d0 = *(longlong **)(param_1 + 0x68);
              local_c8[0] = *(longlong **)(param_1 + 0x70);
              uVar17 = 0x4f6;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar20 = (longlong *)0x0;
              local_118 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            else {
              iVar8 = FUN_23a35f020(local_120);
              uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
              if (iVar8 == -1) {
                local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_d0 = *(longlong **)(param_1 + 0x68);
                local_c8[0] = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar17 = 0x4f8;
                plVar20 = (longlong *)0x0;
                local_118 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              else {
                if (iVar8 == 0) {
                  *(undefined4 *)(plVar3 + 5) = 0x4f9;
                  plVar9 = (longlong *)FUN_23e915840(param_1,plVar1);
                  uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
                  if (plVar9 == (longlong *)0x0) {
                    local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    plStack_d0 = *(longlong **)(param_1 + 0x68);
                    local_c8[0] = *(longlong **)(param_1 + 0x70);
                    plVar20 = (longlong *)0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar17 = 0x4f9;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    local_118 = (longlong *)0x0;
                    goto LAB_23e76c848;
                  }
                  lVar11 = *plVar9;
                  *plVar9 = lVar11 + -1;
                  if (lVar11 + -1 == 0) {
                    FUN_23a334bc0(plVar9);
                  }
                }
                plVar9 = (longlong *)FUN_23ebf7180(local_120);
                uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
                if (plVar9 == (longlong *)0x0) {
                  local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                  plStack_d0 = *(longlong **)(param_1 + 0x68);
                  local_c8[0] = *(longlong **)(param_1 + 0x70);
                  plVar20 = (longlong *)0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar17 = 0x4fb;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  local_118 = (longlong *)0x0;
                }
                else {
                  local_118 = (longlong *)0x0;
                  plVar20 = (longlong *)0x0;
                  do {
                    local_f0 = &local_88;
                    plVar19 = (longlong *)FUN_23a388450(plVar9);
                    uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
                    if (plVar19 == (longlong *)0x0) {
                      cVar7 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
                      if (cVar7 == '\0') {
                        local_f0 = *(code ***)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        auVar22 = *(undefined1 (*) [8])(param_1 + 0x60);
                        plVar19 = *(longlong **)(param_1 + 0x68);
                        uVar17 = 0x4fb;
                        local_c8[0] = (longlong *)0x0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        _local_d8 = (undefined1  [16])0x0;
                        if (local_118 == (longlong *)0x0) goto LAB_23e76ddc1;
                        goto LAB_23e76de92;
                      }
                      plVar19 = local_118;
                      if (local_118 != (longlong *)0x0) goto LAB_23e76dd68;
LAB_23e76dd2e:
                      lVar11 = *plVar9;
                      *plVar9 = lVar11 + -1;
                      if (lVar11 + -1 == 0) {
                        FUN_23a334bc0(plVar9);
                      }
                      goto LAB_23e76ca87;
                    }
                    if (local_118 == (longlong *)0x0) {
                      *plVar19 = *plVar19 + 1;
                    }
                    else {
                      *local_118 = *local_118 + -1;
                      if (*local_118 == 0) {
                        FUN_23a334bc0(local_118);
                      }
                      *plVar19 = *plVar19 + 1;
                      *local_118 = *local_118 + -1;
                      if (*local_118 == 0) {
                        FUN_23a334bc0(local_118);
                      }
                    }
                    uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
                    local_118 = plVar19;
                    if (plVar1 == (longlong *)0x0) {
                      FUN_23e8ba2b0(local_d8,DAT_23eed8d30);
                      if ((local_d8 != (undefined1  [8])pcVar24) &&
                         (local_d8 != (undefined1  [8])0x0)) {
                        FUN_23e91b1b0(param_1,local_d8,local_d8 + 8);
                      }
                      FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),plStack_d0);
LAB_23e76dfb3:
                      uVar17 = 0x4fc;
                      goto LAB_23e76de5c;
                    }
                    plVar14 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed89b0);
                    uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
                    if (plVar14 == (longlong *)0x0) {
LAB_23e76dfc8:
                      local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      plStack_d0 = *(longlong **)(param_1 + 0x68);
                      local_c8[0] = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e76dfb3;
                    }
                    *(undefined4 *)(plVar3 + 5) = 0x4fc;
                    plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar14,DAT_23eed8d38);
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      FUN_23a334bc0();
                    }
                    uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
                    if (plVar12 == (longlong *)0x0) goto LAB_23e76dfc8;
                    iVar8 = FUN_23a35f020(plVar12);
                    uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
                    lVar11 = *plVar12 + -1;
                    if (iVar8 == -1) {
                      local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      plStack_d0 = *(longlong **)(param_1 + 0x68);
                      local_c8[0] = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar12 = lVar11;
                      if (lVar11 == 0) {
                        FUN_23a334bc0(plVar12);
                      }
                      goto LAB_23e76dfb3;
                    }
                    *plVar12 = lVar11;
                    if (lVar11 == 0) {
                      FUN_23a334bc0(plVar12);
                    }
                    uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
                    if (iVar8 != 0) {
LAB_23e76dd68:
                      *plVar19 = *plVar19 + -1;
                      local_118 = plVar19;
                      if (*plVar19 == 0) {
                        FUN_23a334bc0(plVar19);
                      }
                      goto LAB_23e76dd2e;
                    }
                    *(undefined4 *)(plVar3 + 5) = 0x500;
                    plVar14 = (longlong *)FUN_23e915840(param_1,plVar10);
                    uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
                    if (plVar14 == (longlong *)0x0) {
                      local_c8[0] = *(longlong **)(param_1 + 0x70);
                      local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      plStack_d0 = *(longlong **)(param_1 + 0x68);
                      uVar17 = 0x500;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e76de5c;
                    }
                    if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
                      FUN_23a334bc0(plVar20);
                    }
                    iVar8 = FUN_23a35f020(plVar14);
                    uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
                    plVar20 = plVar14;
                    if (iVar8 == -1) {
                      local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      plStack_d0 = *(longlong **)(param_1 + 0x68);
                      local_c8[0] = *(longlong **)(param_1 + 0x70);
                      uVar17 = 0x501;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e76de5c;
                    }
                    if (iVar8 == 0) {
                      local_104 = 1;
                      goto LAB_23e76dd68;
                    }
                    if (local_100 == (code *)0x0) {
                      FUN_23e8ba2b0(local_d8,DAT_23eed94d0);
                      if ((local_d8 != (undefined1  [8])pcVar24) &&
                         (local_d8 != (undefined1  [8])0x0)) {
                        FUN_23e91b1b0(param_1,local_d8,local_d8 + 8);
                      }
                      FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),plStack_d0);
                      uVar17 = 0x502;
                      goto LAB_23e76de5c;
                    }
                    local_88 = local_100;
                    FUN_23e8d34a0(local_f0);
                    local_100 = local_88;
                    cVar7 = FUN_23a3a5fe0(param_1);
                    uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe90 >> 0x20);
                  } while (cVar7 != '\0');
                  local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                  plStack_d0 = *(longlong **)(param_1 + 0x68);
                  local_c8[0] = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar17 = 0x4fb;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e76de5c:
                  local_f0 = (code **)local_c8[0];
                  auVar22 = local_d8;
                  plVar19 = plStack_d0;
LAB_23e76de92:
                  local_c8[0] = (longlong *)0x0;
                  _local_d8 = (undefined1  [16])0x0;
                  *local_118 = *local_118 + -1;
                  if (*local_118 == 0) {
                    FUN_23a334bc0(local_118);
                  }
LAB_23e76ddc1:
                  lVar11 = *plVar9;
                  *plVar9 = lVar11 + -1;
                  if (lVar11 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  local_c8[0] = (longlong *)local_f0;
                  local_d8 = auVar22;
                  plStack_d0 = plVar19;
                }
              }
            }
            goto LAB_23e76c848;
          }
          plVar20 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
LAB_23e76ca87:
          lVar11 = FUN_23e8e07b0();
          if (lVar11 == 0) {
            FUN_23e915740(param_1,local_d8,DAT_23eed8f68);
            plVar9 = (longlong *)0x0;
joined_r0x00023e76dad0:
            if (local_c8[0] != (longlong *)0x0) {
              if ((longlong *)local_c8[0][3] != plVar3) {
                plVar19 = (longlong *)0x0;
                uVar21 = 2;
                uVar17 = 0x50c;
                goto LAB_23e76aeb0;
              }
              goto LAB_23e76d491;
            }
            uVar21 = 2;
            plVar19 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            uVar17 = 0x50c;
          }
          else {
            *(undefined4 *)(plVar3 + 5) = 0x50c;
            plVar9 = (longlong *)FUN_23e91a870(param_1,lVar11);
            if (plVar9 == (longlong *)0x0) {
              local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
              plStack_d0 = *(longlong **)(param_1 + 0x68);
              local_c8[0] = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto joined_r0x00023e76dad0;
            }
            if (local_104 == 1) {
              *(undefined4 *)(plVar3 + 5) = 0x50e;
              plVar19 = (longlong *)FUN_23e91bfe0(param_1,plVar9,DAT_23eed94e0);
              if (plVar19 == (longlong *)0x0) {
                local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_d0 = *(longlong **)(param_1 + 0x68);
                local_c8[0] = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (local_c8[0] != (longlong *)0x0) {
                  if ((longlong *)local_c8[0][3] == plVar3) goto LAB_23e76e164;
                  uVar21 = 2;
                  plVar19 = (longlong *)0x0;
                  uVar17 = 0x50e;
                  goto LAB_23e76aeb0;
                }
                uVar21 = 2;
                uVar17 = 0x50e;
                plVar19 = (longlong *)0x0;
                goto LAB_23e76afdf;
              }
LAB_23e76d969:
              *plVar19 = *plVar19 + -1;
              if (*plVar19 == 0) {
                FUN_23a334bc0();
              }
LAB_23e76caea:
              if (plVar1 == (longlong *)0x0) {
                FUN_23e8ba2b0(local_d8,DAT_23eed8d30);
                if ((local_d8 != (undefined1  [8])pcVar24) && (local_d8 != (undefined1  [8])0x0)) {
                  FUN_23e91b1b0(param_1,local_d8,local_d8 + 8,local_c8);
                }
                FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),plStack_d0);
joined_r0x00023e76e5c7:
                if (local_c8[0] != (longlong *)0x0) {
                  plVar19 = (longlong *)0x0;
                  plVar14 = (longlong *)local_c8[0][3];
joined_r0x00023e76e42f:
                  if (plVar14 == plVar3) {
                    uVar21 = 2;
                    plVar19 = (longlong *)0x0;
                    plVar12 = local_c8[0];
                    goto LAB_23e76ab3a;
                  }
LAB_23e76d93a:
                  uVar21 = 2;
                  uVar17 = 0x513;
                  goto LAB_23e76aeb0;
                }
              }
              else {
                plVar19 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8978);
                if (plVar19 != (longlong *)0x0) {
                  plVar14 = (longlong *)FUN_23e8bc2f0(plVar19,DAT_23ed6ce40);
                  *plVar19 = *plVar19 + -1;
                  if (*plVar19 == 0) {
                    FUN_23a334bc0(plVar19);
                  }
                  pcVar15 = DAT_23eed8b60;
                  if (plVar14 == (longlong *)0x0) {
                    local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    plStack_d0 = *(longlong **)(param_1 + 0x68);
                    local_c8[0] = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto joined_r0x00023e76e5c7;
                  }
                  plVar12 = (longlong *)FUN_23e8d6ad0(param_1);
                  *(undefined4 *)(plVar3 + 5) = 0x513;
                  local_b8 = pcVar15;
                  plStack_b0 = plVar12;
                  plVar19 = (longlong *)FUN_23e94ed00(param_1,plVar14,&local_b8);
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    FUN_23a334bc0(plVar14);
                  }
                  lVar11 = *plVar12;
                  *plVar12 = lVar11 + -1;
                  if (lVar11 + -1 == 0) {
                    FUN_23a334bc0(plVar12);
                  }
                  if (plVar19 == (longlong *)0x0) {
                    local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    plStack_d0 = *(longlong **)(param_1 + 0x68);
                    local_c8[0] = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (local_c8[0] == (longlong *)0x0) goto LAB_23e76e5cd;
                    plVar14 = (longlong *)local_c8[0][3];
                    goto joined_r0x00023e76e42f;
                  }
                  plVar14 = (longlong *)FUN_23e8bc2f0(plVar19,DAT_23eed9350);
                  if (plVar14 == (longlong *)0x0) {
LAB_23e76d869:
                    local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    plStack_d0 = *(longlong **)(param_1 + 0x68);
                    local_c8[0] = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (local_c8[0] != (longlong *)0x0) {
                      if ((longlong *)local_c8[0][3] != plVar3) {
                        uVar21 = 2;
                        uVar17 = 0x514;
                        goto LAB_23e76aeb0;
                      }
                      goto LAB_23e76e167;
                    }
                  }
                  else {
                    *(undefined4 *)(plVar3 + 5) = 0x514;
                    plVar12 = (longlong *)FUN_23e91a870(param_1,plVar14);
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      FUN_23a334bc0(plVar14);
                    }
                    if (plVar12 != (longlong *)0x0) {
                      plVar14 = (longlong *)FUN_23ebf7180();
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        FUN_23a334bc0();
                      }
                      if (plVar14 != (longlong *)0x0) {
                        local_b8 = (code *)FUN_23e8d6950(plVar14);
                        uVar23 = 0;
                        plVar12 = (longlong *)
                                  FUN_23e91ecd0(FUN_23e76e6f0,DAT_23eedaeb8,DAT_23eed90c0,
                                                DAT_23eed9528,DAT_23eedafe8,&local_b8,1,0x78);
                        *plVar14 = *plVar14 + -1;
                        if (*plVar14 == 0) {
                          FUN_23a334bc0(plVar14);
                        }
                        plVar14 = (longlong *)FUN_23e8bd690(param_1,plVar12);
                        *plVar12 = *plVar12 + -1;
                        if (*plVar12 == 0) {
                          FUN_23a334bc0();
                        }
                        if (plVar14 != (longlong *)0x0) {
                          iVar8 = FUN_23a35f020(plVar14);
                          uVar21 = iVar8 != 0;
                          *plVar14 = *plVar14 + -1;
                          if (*plVar14 == 0) {
                            FUN_23a334bc0(plVar14);
                          }
                          lVar11 = DAT_23eed9358;
                          if (iVar8 != 0) {
                            *(undefined4 *)(plVar3 + 5) = 0x516;
                            plVar14 = (longlong *)
                                      FUN_23e915840(param_1,plVar1,DAT_23eed8b40,
                                                    *(undefined8 *)(lVar11 + 0x18));
                            if (plVar14 == (longlong *)0x0) {
                              local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                              plStack_d0 = *(longlong **)(param_1 + 0x68);
                              local_c8[0] = *(longlong **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              if (local_c8[0] == (longlong *)0x0) {
                                uVar21 = 1;
                                uVar17 = 0x516;
                                goto LAB_23e76afdf;
                              }
                              if ((longlong *)local_c8[0][3] == plVar3) {
LAB_23e76e4cc:
                                uVar21 = 1;
                                plVar12 = local_c8[0];
                                goto LAB_23e76ab3a;
                              }
                              uVar21 = 1;
                              uVar17 = 0x516;
                            }
                            else {
                              *plVar14 = *plVar14 + -1;
                              if (*plVar14 == 0) {
                                FUN_23a334bc0(plVar14);
                              }
                              *(undefined4 *)(plVar3 + 5) = 0x517;
                              plVar14 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eed9360);
                              if (plVar14 != (longlong *)0x0) {
                                *plVar14 = *plVar14 + -1;
                                if (*plVar14 == 0) {
                                  FUN_23a334bc0(plVar14);
                                }
                                goto LAB_23e76cdc0;
                              }
                              local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                              plStack_d0 = *(longlong **)(param_1 + 0x68);
                              local_c8[0] = *(longlong **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              if (local_c8[0] == (longlong *)0x0) {
                                uVar21 = 1;
                                uVar17 = 0x517;
                                goto LAB_23e76afdf;
                              }
                              if ((longlong *)local_c8[0][3] == plVar3) goto LAB_23e76e4cc;
                              uVar21 = 1;
                              uVar17 = 0x517;
                            }
                            goto LAB_23e76aeb0;
                          }
LAB_23e76cdc0:
                          *(undefined4 *)(plVar3 + 5) = 0x519;
                          plVar14 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eed9368);
                          if (plVar14 == (longlong *)0x0) {
                            local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                            plStack_d0 = *(longlong **)(param_1 + 0x68);
                            local_c8[0] = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            if (local_c8[0] != (longlong *)0x0) {
                              uVar17 = 0x519;
                              plVar14 = (longlong *)local_c8[0][3];
                              goto joined_r0x00023e76e1db;
                            }
                            uVar17 = 0x519;
                          }
                          else {
                            *plVar14 = *plVar14 + -1;
                            if (*plVar14 == 0) {
                              FUN_23a334bc0(plVar14);
                            }
                            lVar11 = DAT_23eed9090;
                            *(undefined4 *)(plVar3 + 5) = 0x51c;
                            plVar14 = (longlong *)
                                      FUN_23e915840(param_1,plVar1,DAT_23eed8c50,
                                                    *(undefined8 *)(lVar11 + 0x18));
                            if (plVar14 == (longlong *)0x0) {
                              local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                              plStack_d0 = *(longlong **)(param_1 + 0x68);
                              local_c8[0] = *(longlong **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              if (local_c8[0] != (longlong *)0x0) {
                                uVar17 = 0x51c;
                                plVar14 = (longlong *)local_c8[0][3];
                                goto joined_r0x00023e76e1db;
                              }
                              uVar17 = 0x51c;
                            }
                            else {
                              *plVar14 = *plVar14 + -1;
                              if (*plVar14 == 0) {
                                FUN_23a334bc0(plVar14);
                              }
                              cVar7 = FUN_23e8d9ac0(plVar1,DAT_23eed89b8,_Py_FalseStruct_exref);
                              if (cVar7 == '\0') {
                                local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                plStack_d0 = *(longlong **)(param_1 + 0x68);
                                local_c8[0] = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                if (local_c8[0] != (longlong *)0x0) {
                                  uVar17 = 0x51e;
                                  plVar14 = (longlong *)local_c8[0][3];
                                  goto joined_r0x00023e76e1db;
                                }
                                uVar17 = 0x51e;
                              }
                              else {
                                lVar11 = FUN_23e8e0e20();
                                if (lVar11 == 0) {
                                  FUN_23e915740(param_1,local_d8,DAT_23eed8988);
                                }
                                else {
                                  plVar14 = (longlong *)FUN_23e8bc2f0(lVar11,DAT_23eed8990);
                                  if (plVar14 != (longlong *)0x0) {
                                    cVar7 = FUN_23e8d9ac0(plVar1,DAT_23eed8998,plVar14);
                                    *plVar14 = *plVar14 + -1;
                                    if (*plVar14 == 0) {
                                      FUN_23a334bc0(plVar14);
                                    }
                                    if (cVar7 != '\0') {
                                      FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                                      *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
                                      goto LAB_23e76a135;
                                    }
                                  }
                                  local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                  plStack_d0 = *(longlong **)(param_1 + 0x68);
                                  local_c8[0] = *(longlong **)(param_1 + 0x70);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                }
                                if (local_c8[0] != (longlong *)0x0) {
                                  uVar17 = 0x51f;
                                  plVar14 = (longlong *)local_c8[0][3];
joined_r0x00023e76e1db:
                                  plVar12 = local_c8[0];
                                  if (plVar14 == plVar3) goto LAB_23e76ab3a;
                                  goto LAB_23e76aeb0;
                                }
                                uVar17 = 0x51f;
                              }
                            }
                          }
                          goto LAB_23e76afdf;
                        }
                      }
                      goto LAB_23e76d869;
                    }
                    local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    plStack_d0 = *(longlong **)(param_1 + 0x68);
                    local_c8[0] = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (local_c8[0] != (longlong *)0x0) {
                      uVar17 = 0x514;
                      plVar14 = (longlong *)local_c8[0][3];
                      goto joined_r0x00023e76b4f6;
                    }
                  }
                  uVar21 = 2;
                  uVar17 = 0x514;
                  goto LAB_23e76afdf;
                }
                local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_d0 = *(longlong **)(param_1 + 0x68);
                local_c8[0] = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (local_c8[0] != (longlong *)0x0) {
                  uVar21 = 2;
                  plVar19 = (longlong *)0x0;
                  plVar12 = local_c8[0];
                  if ((longlong *)local_c8[0][3] == plVar3) goto LAB_23e76ab3a;
                  goto LAB_23e76d93a;
                }
              }
LAB_23e76e5cd:
              uVar21 = 2;
              plVar19 = (longlong *)0x0;
              uVar17 = 0x513;
            }
            else if (local_100 == (code *)0x0) {
              FUN_23e8ba2b0(local_d8,DAT_23eed94d0);
              if ((local_d8 != (undefined1  [8])pcVar24) && (local_d8 != (undefined1  [8])0x0)) {
                FUN_23e91b1b0(param_1,local_d8,local_d8 + 8,local_c8);
              }
              FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),plStack_d0);
              if (local_c8[0] != (longlong *)0x0) {
                if ((longlong *)local_c8[0][3] != plVar3) {
                  uVar21 = 2;
                  plVar19 = (longlong *)0x0;
                  uVar17 = 0x50f;
                  goto LAB_23e76aeb0;
                }
LAB_23e76e164:
                plVar19 = (longlong *)0x0;
LAB_23e76e167:
                uVar21 = 2;
                plVar12 = local_c8[0];
                goto LAB_23e76ab3a;
              }
              uVar21 = 2;
              uVar17 = 0x50f;
              local_100 = (code *)0x0;
              plVar19 = (longlong *)0x0;
            }
            else {
              cVar7 = FUN_23e8d2220(local_100,0);
              if (cVar7 == '\0') goto LAB_23e76caea;
              *(undefined4 *)(plVar3 + 5) = 0x510;
              plVar19 = (longlong *)FUN_23e91bfe0(param_1,plVar9,DAT_23eed94e8);
              if (plVar19 != (longlong *)0x0) goto LAB_23e76d969;
              local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
              plStack_d0 = *(longlong **)(param_1 + 0x68);
              local_c8[0] = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (local_c8[0] != (longlong *)0x0) {
                if ((longlong *)local_c8[0][3] == plVar3) goto LAB_23e76e164;
                uVar21 = 2;
                plVar19 = (longlong *)0x0;
                uVar17 = 0x510;
                goto LAB_23e76aeb0;
              }
              uVar21 = 2;
              uVar17 = 0x510;
              plVar19 = (longlong *)0x0;
            }
          }
        }
      }
      goto LAB_23e76afdf;
    }
    local_d8 = *(undefined1 (*) [8])(param_1 + 0x60);
    plStack_d0 = *(longlong **)(param_1 + 0x68);
    local_c8[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (local_c8[0] == (longlong *)0x0) {
      local_118 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      local_120 = (longlong *)0x0;
      plVar20 = (longlong *)0x0;
      uVar21 = 2;
      uVar17 = 0x4d0;
      local_128 = (code *)0x0;
      local_100 = (code *)0x0;
      local_110 = (longlong *)0x0;
      local_104 = 2;
      plVar10 = (longlong *)0x0;
      goto LAB_23e76afdf;
    }
    if ((longlong *)local_c8[0][3] == plVar3) goto LAB_23e76aae0;
    local_118 = (longlong *)0x0;
    plVar19 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    local_120 = (longlong *)0x0;
    plVar20 = (longlong *)0x0;
    uVar21 = 2;
    uVar17 = 0x4d0;
    local_128 = (code *)0x0;
    local_100 = (code *)0x0;
    local_110 = (longlong *)0x0;
    local_104 = 2;
    plVar10 = (longlong *)0x0;
LAB_23e76aeb0:
    plVar14 = local_c8[0];
    plVar12 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar16 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar16;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar12[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar17;
    pcVar24 = _PyRuntime_exref;
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar24 + 0x1f8) + 0x10) + 0x2e8);
    lVar2 = plVar12[-1];
    puVar4 = *(undefined8 **)(lVar11 + 8);
    *puVar4 = plVar12 + -2;
    plVar12[-2] = lVar11;
    plVar12[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar11 + 8) = plVar12 + -2;
    plVar12[2] = (longlong)plVar14;
    *plVar14 = *plVar14 + 1;
    plVar14 = local_c8[0];
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))();
  }
LAB_23e76ab3a:
  local_c8[0] = plVar12;
  FUN_23e8bba40(plVar3,"ooooobooooooob",plVar1,plVar10,plVar13,local_110,local_100,
                CONCAT44(uVar23,local_104),local_128,local_120,local_118,plVar20,0,plVar9,plVar19,
                uVar21);
  if (DAT_23eedad98 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    DAT_23eedad98 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar11 + 0x28);
  plVar14 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar14 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar12 = local_c8[0];
  plVar14 = plStack_d0;
  auVar22 = local_d8;
  plVar3[0xf] = 0;
  _local_d8 = (undefined1  [16])0x0;
  local_c8[0] = (longlong *)0x0;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((local_110 != (longlong *)0x0) &&
     (lVar11 = *local_110, *local_110 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_110[1] + 0x30))(local_110);
  }
  if ((local_100 != (code *)0x0) &&
     (lVar11 = *(longlong *)local_100, *(longlong *)local_100 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(*(longlong *)(local_100 + 8) + 0x30))(local_100);
  }
  if ((local_128 != (code *)0x0) &&
     (lVar11 = *(longlong *)local_128, *(longlong *)local_128 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(*(longlong *)(local_128 + 8) + 0x30))(local_128);
  }
  if ((local_120 != (longlong *)0x0) &&
     (lVar11 = *local_120, *local_120 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_120[1] + 0x30))(local_120);
  }
  if ((local_118 != (longlong *)0x0) &&
     (lVar11 = *local_118, *local_118 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_118[1] + 0x30))(local_118);
  }
  if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
    (**(code **)(plVar20[1] + 0x30))(plVar20);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
    (**(code **)(plVar19[1] + 0x30))(plVar19);
  }
  *plVar1 = *plVar1 + -1;
  local_c8[0] = plVar12;
  local_d8 = auVar22;
  plStack_d0 = plVar14;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,local_d8,plStack_d0,local_c8[0]);
  return (code *)0x0;
}
