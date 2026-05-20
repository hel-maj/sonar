/* ===== 23e8026b0 workers.fishing.memory_reeling:MemoryReelingTracker.step ===== */
/* ghidra_name=FUN_23e8026b0 entry=23e8026b0 size=32301 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

longlong * FUN_23e8026b0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  code *pcVar11;
  undefined8 uVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong lVar15;
  longlong *plVar16;
  longlong *plVar17;
  undefined4 uVar18;
  longlong *plVar19;
  undefined8 uVar20;
  undefined8 in_stack_fffffffffffffe38;
  longlong *local_120;
  longlong *local_118;
  longlong *local_110;
  longlong *local_108;
  longlong *local_100;
  longlong *local_f8;
  longlong *local_f0;
  longlong *local_e8;
  longlong *local_e0;
  longlong *local_d8;
  longlong *local_d0;
  longlong *local_c8;
  longlong *local_c0;
  longlong *local_b8;
  longlong *local_b0;
  longlong local_90;
  longlong *local_88;
  undefined8 uStack_80;
  undefined1 local_78 [16];
  longlong *local_68;
  
  plVar8 = _DAT_23eede910;
  uVar18 = (undefined4)((ulonglong)in_stack_fffffffffffffe38 >> 0x20);
  plVar1 = (longlong *)*param_3;
  local_68 = (longlong *)0x0;
  local_78 = (undefined1  [16])0x0;
  if (_DAT_23eede910 == (longlong *)0x0) {
LAB_23e80270d:
    _DAT_23eede910 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede950,DAT_23eedd0f8);
  }
  else {
    lVar15 = *_DAT_23eede910;
    if (1 < lVar15) {
      *_DAT_23eede910 = lVar15 + -1;
      goto LAB_23e80270d;
    }
    if (_DAT_23eede910[2] != 0) {
      *_DAT_23eede910 = lVar15 + -1;
      if (lVar15 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e80270d;
    }
  }
  plVar3 = _DAT_23eede910;
  lVar15 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eede910 + 9;
  lVar2 = *(longlong *)(lVar15 + 8);
  _DAT_23eede910[0xf] = lVar2;
  *(longlong **)(lVar15 + 8) = plVar8;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar12 = DAT_23eedd138;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar12);
  if (plVar8 == (longlong *)0x0) {
    local_68 = *(longlong **)(param_1 + 0x70);
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar19 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar10 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    uVar18 = 0xa1;
    local_e0 = (longlong *)0x0;
    local_d8 = (longlong *)0x0;
    local_c8 = (longlong *)0x0;
    local_d0 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    local_b0 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    local_118 = (longlong *)0x0;
    local_120 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_f8 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar8 = (longlong *)0x0;
    goto LAB_23e802e95;
  }
  iVar6 = FUN_23a35f020(plVar8);
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if (iVar6 == -1) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    uVar18 = 0xa1;
    plVar13 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar19 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    local_e0 = (longlong *)0x0;
    local_d8 = (longlong *)0x0;
    local_c8 = (longlong *)0x0;
    local_d0 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    local_b0 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    local_118 = (longlong *)0x0;
    local_120 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_f8 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e802e95;
  }
  if (iVar6 == 0) {
LAB_23e8027d1:
    plVar9 = _DAT_23eedd268;
    plVar19 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    local_118 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    *_DAT_23eedd268 = *_DAT_23eedd268 + 1;
    local_120 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_f8 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
LAB_23e802849:
    lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar3 = *(longlong **)(lVar15 + 0x28);
    plVar16 = (longlong *)plVar3[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
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
    plVar3[0xf] = 0;
    if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    local_e0 = (longlong *)0x0;
    local_d8 = (longlong *)0x0;
    local_c8 = (longlong *)0x0;
    local_d0 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    local_b0 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    if (plVar13 != (longlong *)0x0) {
LAB_23e802908:
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
LAB_23e80290e:
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
    }
    if (plVar10 == (longlong *)0x0) goto LAB_23e80292e;
LAB_23e80291d:
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
LAB_23e80292e:
    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
    if ((local_100 != (longlong *)0x0) &&
       (lVar15 = *local_100, *local_100 = lVar15 + -1, lVar15 + -1 == 0)) {
      (**(code **)(local_100[1] + 0x30))(local_100);
    }
    if ((local_e8 != (longlong *)0x0) &&
       (lVar15 = *local_e8, *local_e8 = lVar15 + -1, lVar15 + -1 == 0)) {
      (**(code **)(local_e8[1] + 0x30))(local_e8);
    }
    if ((local_f0 != (longlong *)0x0) &&
       (lVar15 = *local_f0, *local_f0 = lVar15 + -1, lVar15 + -1 == 0)) {
      (**(code **)(local_f0[1] + 0x30))(local_f0);
    }
    if ((local_f8 != (longlong *)0x0) &&
       (lVar15 = *local_f8, *local_f8 = lVar15 + -1, lVar15 + -1 == 0)) {
      (**(code **)(local_f8[1] + 0x30))(local_f8);
    }
    if ((local_108 != (longlong *)0x0) &&
       (lVar15 = *local_108, *local_108 = lVar15 + -1, lVar15 + -1 == 0)) {
      (**(code **)(local_108[1] + 0x30))(local_108);
    }
    if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
      (**(code **)(plVar19[1] + 0x30))(plVar19);
    }
    if ((local_110 != (longlong *)0x0) &&
       (lVar15 = *local_110, *local_110 = lVar15 + -1, lVar15 + -1 == 0)) {
      (**(code **)(local_110[1] + 0x30))(local_110);
    }
    if ((local_120 != (longlong *)0x0) &&
       (lVar15 = *local_120, *local_120 = lVar15 + -1, lVar15 + -1 == 0)) {
      (**(code **)(local_120[1] + 0x30))(local_120);
    }
    if ((local_118 != (longlong *)0x0) &&
       (lVar15 = *local_118, *local_118 = lVar15 + -1, lVar15 + -1 == 0)) {
      (**(code **)(local_118[1] + 0x30))(local_118);
    }
    if ((local_b8 != (longlong *)0x0) &&
       (lVar15 = *local_b8, *local_b8 = lVar15 + -1, lVar15 + -1 == 0)) {
      (**(code **)(local_b8[1] + 0x30))(local_b8);
    }
    if ((local_b0 != (longlong *)0x0) &&
       (lVar15 = *local_b0, *local_b0 = lVar15 + -1, lVar15 + -1 == 0)) {
      (**(code **)(local_b0[1] + 0x30))(local_b0);
    }
    if ((local_c0 != (longlong *)0x0) &&
       (lVar15 = *local_c0, *local_c0 = lVar15 + -1, lVar15 + -1 == 0)) {
      (**(code **)(local_c0[1] + 0x30))(local_c0);
    }
    if ((local_d0 != (longlong *)0x0) &&
       (lVar15 = *local_d0, *local_d0 = lVar15 + -1, lVar15 + -1 == 0)) {
      (**(code **)(local_d0[1] + 0x30))(local_d0);
    }
    if ((local_c8 != (longlong *)0x0) &&
       (lVar15 = *local_c8, *local_c8 = lVar15 + -1, lVar15 + -1 == 0)) {
      (**(code **)(local_c8[1] + 0x30))(local_c8);
    }
    if ((local_d8 != (longlong *)0x0) &&
       (lVar15 = *local_d8, *local_d8 = lVar15 + -1, lVar15 + -1 == 0)) {
      (**(code **)(local_d8[1] + 0x30))(local_d8);
    }
    if ((local_e0 != (longlong *)0x0) &&
       (lVar15 = *local_e0, *local_e0 = lVar15 + -1, lVar15 + -1 == 0)) {
      (**(code **)(local_e0[1] + 0x30))(local_e0);
    }
    *plVar1 = *plVar1 + -1;
    if (*plVar1 != 0) {
      return plVar9;
    }
    (**(code **)(plVar1[1] + 0x30))(plVar1);
    return plVar9;
  }
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd150);
  if (plVar8 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    plVar19 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar10 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    uVar18 = 0xa1;
    local_e0 = (longlong *)0x0;
    local_d8 = (longlong *)0x0;
    local_c8 = (longlong *)0x0;
    local_d0 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    local_b0 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    local_118 = (longlong *)0x0;
    local_120 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_f8 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar8 = (longlong *)0x0;
    goto LAB_23e802e95;
  }
  uVar7 = FUN_23a35f020(plVar8);
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if (uVar7 == 0xffffffff) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    uVar18 = 0xa1;
    plVar13 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar19 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    local_e0 = (longlong *)0x0;
    local_d8 = (longlong *)0x0;
    local_c8 = (longlong *)0x0;
    local_d0 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    local_b0 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    local_118 = (longlong *)0x0;
    local_120 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_f8 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e802e95;
  }
  if ((uVar7 & 1) == 0) goto LAB_23e8027d1;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd270);
  if (plVar9 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    plVar19 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    uVar18 = 0xa4;
    local_e0 = (longlong *)0x0;
    local_d8 = (longlong *)0x0;
    local_c8 = (longlong *)0x0;
    local_d0 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    local_b0 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    local_118 = (longlong *)0x0;
    local_120 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_f8 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = (longlong *)0x0;
    goto LAB_23e802e95;
  }
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd150);
  if (plVar10 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar9 = *plVar9 + -1;
    plVar13 = (longlong *)0x0;
    if (*plVar9 == 0) {
      plVar19 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      (**(code **)(plVar9[1] + 0x30))(plVar9);
      uVar18 = 0xa4;
      local_e0 = (longlong *)0x0;
      local_d8 = (longlong *)0x0;
      local_c8 = (longlong *)0x0;
      local_d0 = (longlong *)0x0;
      local_c0 = (longlong *)0x0;
      local_b0 = (longlong *)0x0;
      local_b8 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_120 = (longlong *)0x0;
      local_110 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_f8 = (longlong *)0x0;
      local_f0 = (longlong *)0x0;
      local_e8 = (longlong *)0x0;
      local_100 = (longlong *)0x0;
    }
    else {
      local_e0 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      local_d8 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      uVar18 = 0xa4;
      local_c8 = (longlong *)0x0;
      local_d0 = (longlong *)0x0;
      local_c0 = (longlong *)0x0;
      local_b0 = (longlong *)0x0;
      local_b8 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_120 = (longlong *)0x0;
      local_110 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_f8 = (longlong *)0x0;
      local_f0 = (longlong *)0x0;
      local_e8 = (longlong *)0x0;
      local_100 = (longlong *)0x0;
    }
    goto LAB_23e802e95;
  }
  *(undefined4 *)(plVar3 + 5) = 0xa4;
  plVar8 = (longlong *)FUN_23e914090(param_1,plVar9,plVar10);
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if (plVar8 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    plVar19 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar10 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    uVar18 = 0xa4;
    local_e0 = (longlong *)0x0;
    local_d8 = (longlong *)0x0;
    local_c8 = (longlong *)0x0;
    local_d0 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    local_b0 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    local_118 = (longlong *)0x0;
    local_120 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_f8 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e802e95;
  }
  iVar6 = FUN_23a35f020(plVar8);
  if (iVar6 == -1) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    uVar18 = 0xa5;
    plVar13 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar19 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    local_e0 = (longlong *)0x0;
    local_d8 = (longlong *)0x0;
    local_c8 = (longlong *)0x0;
    local_d0 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    local_b0 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    local_118 = (longlong *)0x0;
    local_120 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_f8 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e802e95;
  }
  plVar9 = _DAT_23eedd268;
  if (iVar6 == 0) {
LAB_23e802d30:
    *plVar9 = *plVar9 + 1;
    plVar19 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    local_118 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    local_120 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_f8 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    goto LAB_23e802849;
  }
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd158);
  if (plVar10 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    plVar19 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar10 = (longlong *)0x0;
    uVar18 = 0xa8;
    local_e0 = (longlong *)0x0;
    local_d8 = (longlong *)0x0;
    local_c8 = (longlong *)0x0;
    local_d0 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    local_b0 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    local_118 = (longlong *)0x0;
    local_120 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_f8 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar13 = (longlong *)0x0;
    goto LAB_23e802e95;
  }
  iVar6 = FUN_23a35f020(plVar10);
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  uVar12 = _DAT_23eedd278;
  if (iVar6 == -1) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    uVar18 = 0xa8;
    plVar13 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar19 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    local_e0 = (longlong *)0x0;
    local_d8 = (longlong *)0x0;
    local_c8 = (longlong *)0x0;
    local_d0 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    local_b0 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    local_118 = (longlong *)0x0;
    local_120 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_f8 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e802e95;
  }
  if (iVar6 == 0) {
    *(undefined4 *)(plVar3 + 5) = 0xa9;
    plVar10 = (longlong *)FUN_23e915840(param_1,plVar1,uVar12);
    if (plVar10 == (longlong *)0x0) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      plVar19 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar10 = (longlong *)0x0;
      uVar18 = 0xa9;
      local_e0 = (longlong *)0x0;
      local_d8 = (longlong *)0x0;
      local_c8 = (longlong *)0x0;
      local_d0 = (longlong *)0x0;
      local_c0 = (longlong *)0x0;
      local_b0 = (longlong *)0x0;
      local_b8 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_120 = (longlong *)0x0;
      local_110 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_f8 = (longlong *)0x0;
      local_f0 = (longlong *)0x0;
      local_e8 = (longlong *)0x0;
      local_100 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar13 = (longlong *)0x0;
      goto LAB_23e802e95;
    }
    cVar5 = FUN_23e8d9ac0(plVar1,_DAT_23eedd158,plVar10);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (cVar5 == '\0') {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      uVar18 = 0xa9;
      plVar13 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar19 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      local_e0 = (longlong *)0x0;
      local_d8 = (longlong *)0x0;
      local_c8 = (longlong *)0x0;
      local_d0 = (longlong *)0x0;
      local_c0 = (longlong *)0x0;
      local_b0 = (longlong *)0x0;
      local_b8 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_120 = (longlong *)0x0;
      local_110 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_f8 = (longlong *)0x0;
      local_f0 = (longlong *)0x0;
      local_e8 = (longlong *)0x0;
      local_100 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e802e95;
    }
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd158);
    if (plVar10 == (longlong *)0x0) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      plVar19 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar10 = (longlong *)0x0;
      uVar18 = 0xaa;
      local_e0 = (longlong *)0x0;
      local_d8 = (longlong *)0x0;
      local_c8 = (longlong *)0x0;
      local_d0 = (longlong *)0x0;
      local_c0 = (longlong *)0x0;
      local_b0 = (longlong *)0x0;
      local_b8 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_120 = (longlong *)0x0;
      local_110 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_f8 = (longlong *)0x0;
      local_f0 = (longlong *)0x0;
      local_e8 = (longlong *)0x0;
      local_100 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar13 = (longlong *)0x0;
      goto LAB_23e802e95;
    }
    iVar6 = FUN_23a35f020(plVar10);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (iVar6 == -1) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      uVar18 = 0xaa;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar19 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      local_e0 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      local_d8 = (longlong *)0x0;
      local_c8 = (longlong *)0x0;
      local_d0 = (longlong *)0x0;
      local_c0 = (longlong *)0x0;
      local_b0 = (longlong *)0x0;
      local_b8 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_120 = (longlong *)0x0;
      local_110 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_f8 = (longlong *)0x0;
      local_f0 = (longlong *)0x0;
      local_e8 = (longlong *)0x0;
      local_100 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e802e95;
    }
    plVar9 = _DAT_23eedd280;
    if (iVar6 != 0) {
      plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd270);
      if (plVar10 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        plVar19 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar14 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        uVar18 = 0xac;
        local_e0 = (longlong *)0x0;
        local_d8 = (longlong *)0x0;
        local_c8 = (longlong *)0x0;
        local_d0 = (longlong *)0x0;
        local_c0 = (longlong *)0x0;
        local_b0 = (longlong *)0x0;
        local_b8 = (longlong *)0x0;
        local_118 = (longlong *)0x0;
        local_120 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        local_f8 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        local_e8 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar10 = (longlong *)0x0;
        goto LAB_23e802e95;
      }
      plVar13 = (longlong *)FUN_23e8bc2f0(plVar1);
      if (plVar13 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar10 = *plVar10 + -1;
        plVar13 = (longlong *)0x0;
        if (*plVar10 == 0) {
          plVar14 = (longlong *)0x0;
          FUN_23a334bc0(plVar10);
          local_e0 = (longlong *)0x0;
          uVar18 = 0xac;
          local_d8 = (longlong *)0x0;
          local_c8 = (longlong *)0x0;
          local_d0 = (longlong *)0x0;
          local_c0 = (longlong *)0x0;
          local_b0 = (longlong *)0x0;
          local_b8 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          local_110 = (longlong *)0x0;
          plVar19 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
          local_f8 = (longlong *)0x0;
          local_f0 = (longlong *)0x0;
          local_e8 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
        }
        else {
          plVar19 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          local_f8 = (longlong *)0x0;
          local_f0 = (longlong *)0x0;
          local_e8 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
          uVar18 = 0xac;
          local_e0 = (longlong *)0x0;
          local_d8 = (longlong *)0x0;
          local_c8 = (longlong *)0x0;
          local_d0 = (longlong *)0x0;
          local_c0 = (longlong *)0x0;
          local_b0 = (longlong *)0x0;
          local_b8 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          local_110 = (longlong *)0x0;
        }
        goto LAB_23e802e95;
      }
      *(undefined4 *)(plVar3 + 5) = 0xac;
      plVar14 = (longlong *)FUN_23e914090(param_1,plVar10,plVar13);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        FUN_23a334bc0(plVar10);
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        FUN_23a334bc0(plVar13);
      }
      if (plVar14 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        local_108 = (longlong *)0x0;
        plVar19 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        uVar18 = 0xac;
        local_f8 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        local_e8 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_e0 = (longlong *)0x0;
        local_d8 = (longlong *)0x0;
        local_c8 = (longlong *)0x0;
        local_d0 = (longlong *)0x0;
        local_c0 = (longlong *)0x0;
        local_b0 = (longlong *)0x0;
        local_b8 = (longlong *)0x0;
        local_118 = (longlong *)0x0;
        local_120 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar14 = (longlong *)0x0;
        goto LAB_23e802e95;
      }
      cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eedd160);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        FUN_23a334bc0();
      }
      if (cVar5 == '\0') {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        local_e0 = (longlong *)0x0;
        plVar19 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar18 = 0xac;
        plVar10 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        local_d8 = (longlong *)0x0;
        local_c8 = (longlong *)0x0;
        local_d0 = (longlong *)0x0;
        local_c0 = (longlong *)0x0;
        local_b0 = (longlong *)0x0;
        local_b8 = (longlong *)0x0;
        local_118 = (longlong *)0x0;
        local_120 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        local_f8 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        local_e8 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e802e95;
      }
      lVar15 = FUN_23e8dd000();
      if (lVar15 == 0) {
        plVar19 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        FUN_23e915740(param_1,local_78,_DAT_23eedd168);
        local_108 = (longlong *)0x0;
        local_f8 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        local_e8 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        uVar18 = 0xad;
        local_e0 = (longlong *)0x0;
        local_d8 = (longlong *)0x0;
        local_c8 = (longlong *)0x0;
        local_d0 = (longlong *)0x0;
        local_c0 = (longlong *)0x0;
        local_b0 = (longlong *)0x0;
        local_b8 = (longlong *)0x0;
        local_118 = (longlong *)0x0;
        local_120 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        goto LAB_23e802e95;
      }
      plVar9 = (longlong *)FUN_23e8bc2f0(lVar15,_DAT_23eedd170);
      if (plVar9 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        plVar19 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar10 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        uVar18 = 0xad;
        local_e0 = (longlong *)0x0;
        local_d8 = (longlong *)0x0;
        local_c8 = (longlong *)0x0;
        local_d0 = (longlong *)0x0;
        local_c0 = (longlong *)0x0;
        local_b0 = (longlong *)0x0;
        local_b8 = (longlong *)0x0;
        local_118 = (longlong *)0x0;
        local_120 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        local_f8 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        local_e8 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar14 = (longlong *)0x0;
        goto LAB_23e802e95;
      }
      plVar10 = (longlong *)FUN_23e8d8df0(*(undefined8 *)(param_1 + 0x10),DAT_23ed6cd08);
      lVar15 = FUN_23e8dced0();
      if (lVar15 == 0) {
        FUN_23e915740(param_1,local_78,_DAT_23eedd178);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          FUN_23a334bc0(plVar9);
        }
        *plVar10 = *plVar10 + -1;
        plVar13 = (longlong *)0x0;
        if (*plVar10 == 0) {
          plVar19 = (longlong *)0x0;
          FUN_23a334bc0(plVar10);
          local_e0 = (longlong *)0x0;
          uVar18 = 0xad;
          local_d8 = (longlong *)0x0;
          local_c8 = (longlong *)0x0;
          local_d0 = (longlong *)0x0;
          local_c0 = (longlong *)0x0;
          local_b0 = (longlong *)0x0;
          local_b8 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          local_110 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
          local_f8 = (longlong *)0x0;
          local_f0 = (longlong *)0x0;
          local_e8 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
        }
        else {
          plVar19 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          local_e0 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          uVar18 = 0xad;
          local_d8 = (longlong *)0x0;
          local_c8 = (longlong *)0x0;
          local_d0 = (longlong *)0x0;
          local_c0 = (longlong *)0x0;
          local_b0 = (longlong *)0x0;
          local_b8 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          local_110 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
          local_f8 = (longlong *)0x0;
          local_f0 = (longlong *)0x0;
          local_e8 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
        }
        goto LAB_23e802e95;
      }
      plVar16 = (longlong *)FUN_23e8c4790(plVar10,lVar15);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        FUN_23a334bc0(plVar10);
      }
      if (plVar16 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar9 = *plVar9 + -1;
        plVar13 = (longlong *)0x0;
        if (*plVar9 == 0) {
          plVar19 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          FUN_23a334bc0(plVar9);
          uVar18 = 0xad;
          local_e0 = (longlong *)0x0;
          local_d8 = (longlong *)0x0;
          local_c8 = (longlong *)0x0;
          local_d0 = (longlong *)0x0;
          local_c0 = (longlong *)0x0;
          local_b0 = (longlong *)0x0;
          local_b8 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          local_110 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
          local_f8 = (longlong *)0x0;
          local_f0 = (longlong *)0x0;
          local_e8 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
        }
        else {
          plVar19 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          local_e0 = (longlong *)0x0;
          uVar18 = 0xad;
          local_d8 = (longlong *)0x0;
          local_c8 = (longlong *)0x0;
          local_d0 = (longlong *)0x0;
          local_c0 = (longlong *)0x0;
          local_b0 = (longlong *)0x0;
          local_b8 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          local_110 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
          local_f8 = (longlong *)0x0;
          local_f0 = (longlong *)0x0;
          local_e8 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
        }
        goto LAB_23e802e95;
      }
      lVar15 = FUN_23e8dced0();
      if (lVar15 == 0) {
        FUN_23e915740();
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          FUN_23a334bc0();
        }
        *plVar16 = *plVar16 + -1;
        plVar10 = (longlong *)0x0;
        if (*plVar16 == 0) {
          plVar19 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          FUN_23a334bc0(plVar16);
          local_108 = (longlong *)0x0;
          local_f8 = (longlong *)0x0;
          local_f0 = (longlong *)0x0;
          local_e8 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
          uVar18 = 0xad;
          local_e0 = (longlong *)0x0;
          local_d8 = (longlong *)0x0;
          local_c8 = (longlong *)0x0;
          local_d0 = (longlong *)0x0;
          local_c0 = (longlong *)0x0;
          local_b0 = (longlong *)0x0;
          local_b8 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          local_110 = (longlong *)0x0;
        }
        else {
          plVar19 = (longlong *)0x0;
          local_e0 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          uVar18 = 0xad;
          local_d8 = (longlong *)0x0;
          local_c8 = (longlong *)0x0;
          local_d0 = (longlong *)0x0;
          local_c0 = (longlong *)0x0;
          local_b0 = (longlong *)0x0;
          local_b8 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          local_110 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
          local_f8 = (longlong *)0x0;
          local_f0 = (longlong *)0x0;
          local_e8 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
        }
        goto LAB_23e802e95;
      }
      *(undefined4 *)(plVar3 + 5) = 0xad;
      local_90 = lVar15;
      local_88 = plVar16;
      plVar10 = (longlong *)FUN_23e939900(param_1,plVar9,&local_88,&local_90,_DAT_23eedd180);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        FUN_23a334bc0(plVar9);
      }
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        FUN_23a334bc0(plVar16);
      }
      if (plVar10 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        plVar19 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar14 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        uVar18 = 0xad;
        local_e0 = (longlong *)0x0;
        local_d8 = (longlong *)0x0;
        local_c8 = (longlong *)0x0;
        local_d0 = (longlong *)0x0;
        local_c0 = (longlong *)0x0;
        local_b0 = (longlong *)0x0;
        local_b8 = (longlong *)0x0;
        local_118 = (longlong *)0x0;
        local_120 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        local_f8 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        local_e8 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar10 = (longlong *)0x0;
        goto LAB_23e802e95;
      }
      cVar5 = FUN_23e8d9ac0(plVar1,_DAT_23eedd188,plVar10);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        FUN_23a334bc0(plVar10);
      }
      if (cVar5 == '\0') {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        local_e0 = (longlong *)0x0;
        plVar19 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        local_d8 = (longlong *)0x0;
        uVar18 = 0xad;
        local_c8 = (longlong *)0x0;
        local_d0 = (longlong *)0x0;
        local_c0 = (longlong *)0x0;
        local_b0 = (longlong *)0x0;
        local_b8 = (longlong *)0x0;
        local_118 = (longlong *)0x0;
        local_120 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar14 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        local_f8 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        local_e8 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e802e95;
      }
      lVar15 = FUN_23e8dd000();
      if (lVar15 == 0) {
        plVar14 = (longlong *)0x0;
        FUN_23e915740(param_1,local_78,_DAT_23eedd168);
        local_e0 = (longlong *)0x0;
        uVar18 = 0xae;
        local_d8 = (longlong *)0x0;
        local_c8 = (longlong *)0x0;
        local_d0 = (longlong *)0x0;
        local_c0 = (longlong *)0x0;
        local_b0 = (longlong *)0x0;
        local_b8 = (longlong *)0x0;
        local_118 = (longlong *)0x0;
        local_120 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        plVar19 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        local_f8 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        local_e8 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        goto LAB_23e802e95;
      }
      plVar9 = (longlong *)FUN_23e8bc2f0(lVar15,_DAT_23eedd170);
      if (plVar9 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        local_108 = (longlong *)0x0;
        plVar19 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        uVar18 = 0xae;
        local_f8 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        local_e8 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_e0 = (longlong *)0x0;
        local_d8 = (longlong *)0x0;
        local_c8 = (longlong *)0x0;
        local_d0 = (longlong *)0x0;
        local_c0 = (longlong *)0x0;
        local_b0 = (longlong *)0x0;
        local_b8 = (longlong *)0x0;
        local_118 = (longlong *)0x0;
        local_120 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar14 = (longlong *)0x0;
        goto LAB_23e802e95;
      }
      plVar10 = (longlong *)FUN_23e8d8df0(*(undefined8 *)(param_1 + 0x10),DAT_23ed6cd08);
      lVar15 = FUN_23e8dced0();
      if (lVar15 == 0) {
        FUN_23e915740(param_1);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          FUN_23a334bc0(plVar9);
        }
        *plVar10 = *plVar10 + -1;
        plVar13 = (longlong *)0x0;
        if (*plVar10 == 0) {
          plVar19 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          FUN_23a334bc0();
          local_e0 = (longlong *)0x0;
          local_d8 = (longlong *)0x0;
          local_c8 = (longlong *)0x0;
          local_d0 = (longlong *)0x0;
          local_c0 = (longlong *)0x0;
          local_b0 = (longlong *)0x0;
          local_b8 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          local_110 = (longlong *)0x0;
          uVar18 = 0xae;
          local_108 = (longlong *)0x0;
          local_f8 = (longlong *)0x0;
          local_f0 = (longlong *)0x0;
          local_e8 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
        }
        else {
          plVar19 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          local_e0 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          uVar18 = 0xae;
          local_d8 = (longlong *)0x0;
          local_c8 = (longlong *)0x0;
          local_d0 = (longlong *)0x0;
          local_c0 = (longlong *)0x0;
          local_b0 = (longlong *)0x0;
          local_b8 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          local_110 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
          local_f8 = (longlong *)0x0;
          local_f0 = (longlong *)0x0;
          local_e8 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
        }
        goto LAB_23e802e95;
      }
      plVar13 = (longlong *)FUN_23e8c4790(plVar10,lVar15);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        FUN_23a334bc0(plVar10);
      }
      if (plVar13 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar9 = *plVar9 + -1;
        plVar13 = (longlong *)0x0;
        if (*plVar9 == 0) {
          plVar19 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          FUN_23a334bc0(plVar9);
          uVar18 = 0xae;
          local_e0 = (longlong *)0x0;
          local_d8 = (longlong *)0x0;
          local_c8 = (longlong *)0x0;
          local_d0 = (longlong *)0x0;
          local_c0 = (longlong *)0x0;
          local_b0 = (longlong *)0x0;
          local_b8 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          local_110 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
          local_f8 = (longlong *)0x0;
          local_f0 = (longlong *)0x0;
          local_e8 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
        }
        else {
          plVar19 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          local_e0 = (longlong *)0x0;
          uVar18 = 0xae;
          local_d8 = (longlong *)0x0;
          local_c8 = (longlong *)0x0;
          local_d0 = (longlong *)0x0;
          local_c0 = (longlong *)0x0;
          local_b0 = (longlong *)0x0;
          local_b8 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          local_110 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
          local_f8 = (longlong *)0x0;
          local_f0 = (longlong *)0x0;
          local_e8 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
        }
        goto LAB_23e802e95;
      }
      lVar15 = FUN_23e8dced0();
      if (lVar15 == 0) {
        FUN_23e915740(param_1,local_78,_DAT_23eedd178);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          FUN_23a334bc0(plVar9);
        }
        *plVar13 = *plVar13 + -1;
        plVar10 = (longlong *)0x0;
        if (*plVar13 == 0) {
          plVar19 = (longlong *)0x0;
          FUN_23a334bc0(plVar13);
          local_e0 = (longlong *)0x0;
          uVar18 = 0xae;
          local_d8 = (longlong *)0x0;
          local_c8 = (longlong *)0x0;
          local_d0 = (longlong *)0x0;
          local_c0 = (longlong *)0x0;
          local_b0 = (longlong *)0x0;
          local_b8 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          local_110 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
          local_f8 = (longlong *)0x0;
          local_f0 = (longlong *)0x0;
          local_e8 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
        }
        else {
          plVar19 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          local_e0 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          uVar18 = 0xae;
          local_d8 = (longlong *)0x0;
          local_c8 = (longlong *)0x0;
          local_d0 = (longlong *)0x0;
          local_c0 = (longlong *)0x0;
          local_b0 = (longlong *)0x0;
          local_b8 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          local_110 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
          local_f8 = (longlong *)0x0;
          local_f0 = (longlong *)0x0;
          local_e8 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
        }
        goto LAB_23e802e95;
      }
      *(undefined4 *)(plVar3 + 5) = 0xae;
      local_90 = lVar15;
      local_88 = plVar13;
      plVar10 = (longlong *)FUN_23e939900(param_1,plVar9,&local_88,&local_90,_DAT_23eedd180);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        FUN_23a334bc0(plVar9);
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        FUN_23a334bc0(plVar13);
      }
      if (plVar10 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar19 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        uVar18 = 0xae;
        local_e0 = (longlong *)0x0;
        local_d8 = (longlong *)0x0;
        local_c8 = (longlong *)0x0;
        local_d0 = (longlong *)0x0;
        local_c0 = (longlong *)0x0;
        local_b0 = (longlong *)0x0;
        local_b8 = (longlong *)0x0;
        local_118 = (longlong *)0x0;
        local_120 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        local_f8 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        local_e8 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar10 = (longlong *)0x0;
        goto LAB_23e802e95;
      }
      cVar5 = FUN_23e8d9ac0(plVar1,_DAT_23eedd190);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        FUN_23a334bc0();
      }
      if (cVar5 == '\0') {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        local_e0 = (longlong *)0x0;
        plVar19 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar18 = 0xae;
        plVar10 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        local_d8 = (longlong *)0x0;
        local_c8 = (longlong *)0x0;
        local_d0 = (longlong *)0x0;
        local_c0 = (longlong *)0x0;
        local_b0 = (longlong *)0x0;
        local_b8 = (longlong *)0x0;
        local_118 = (longlong *)0x0;
        local_120 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        local_f8 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        local_e8 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e802e95;
      }
      lVar15 = FUN_23e8dd000();
      if (lVar15 == 0) {
        plVar19 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        FUN_23e915740(param_1,local_78,_DAT_23eedd168);
        uVar18 = 0xaf;
        local_e0 = (longlong *)0x0;
        local_d8 = (longlong *)0x0;
        local_c8 = (longlong *)0x0;
        local_d0 = (longlong *)0x0;
        local_c0 = (longlong *)0x0;
        local_b0 = (longlong *)0x0;
        local_b8 = (longlong *)0x0;
        local_118 = (longlong *)0x0;
        local_120 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        local_f8 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        local_e8 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        goto LAB_23e802e95;
      }
      plVar9 = (longlong *)FUN_23e8bc2f0(lVar15,_DAT_23eedd170);
      if (plVar9 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        plVar19 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar10 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        uVar18 = 0xaf;
        local_e0 = (longlong *)0x0;
        local_d8 = (longlong *)0x0;
        local_c8 = (longlong *)0x0;
        local_d0 = (longlong *)0x0;
        local_c0 = (longlong *)0x0;
        local_b0 = (longlong *)0x0;
        local_b8 = (longlong *)0x0;
        local_118 = (longlong *)0x0;
        local_120 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        local_f8 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        local_e8 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar14 = (longlong *)0x0;
        goto LAB_23e802e95;
      }
      plVar16 = (longlong *)FUN_23e8d8df0(*(undefined8 *)(param_1 + 0x10),DAT_23ed6cd08);
      lVar15 = FUN_23e8dced0();
      if (lVar15 == 0) {
        FUN_23e915740(param_1,local_78);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          FUN_23a334bc0(plVar9);
        }
        *plVar16 = *plVar16 + -1;
        plVar13 = (longlong *)0x0;
        if (*plVar16 == 0) {
          plVar19 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          FUN_23a334bc0(plVar16);
          uVar18 = 0xaf;
          local_e0 = (longlong *)0x0;
          local_d8 = (longlong *)0x0;
          local_c8 = (longlong *)0x0;
          local_d0 = (longlong *)0x0;
          local_c0 = (longlong *)0x0;
          local_b0 = (longlong *)0x0;
          local_b8 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          local_110 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
          local_f8 = (longlong *)0x0;
          local_f0 = (longlong *)0x0;
          local_e8 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
        }
        else {
          plVar19 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
          uVar18 = 0xaf;
          local_f8 = (longlong *)0x0;
          local_f0 = (longlong *)0x0;
          local_e8 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          local_e0 = (longlong *)0x0;
          local_d8 = (longlong *)0x0;
          local_c8 = (longlong *)0x0;
          local_d0 = (longlong *)0x0;
          local_c0 = (longlong *)0x0;
          local_b0 = (longlong *)0x0;
          local_b8 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          local_110 = (longlong *)0x0;
        }
        goto LAB_23e802e95;
      }
      plVar17 = (longlong *)FUN_23e8c4790();
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        FUN_23a334bc0();
      }
      if (plVar17 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar9 = *plVar9 + -1;
        plVar13 = (longlong *)0x0;
        if (*plVar9 == 0) {
          plVar19 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          FUN_23a334bc0(plVar9);
          local_108 = (longlong *)0x0;
          local_f8 = (longlong *)0x0;
          local_f0 = (longlong *)0x0;
          local_e8 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
          uVar18 = 0xaf;
          local_e0 = (longlong *)0x0;
          local_d8 = (longlong *)0x0;
          local_c8 = (longlong *)0x0;
          local_d0 = (longlong *)0x0;
          local_c0 = (longlong *)0x0;
          local_b0 = (longlong *)0x0;
          local_b8 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          local_110 = (longlong *)0x0;
        }
        else {
          plVar19 = (longlong *)0x0;
          uVar18 = 0xaf;
          local_e0 = (longlong *)0x0;
          local_d8 = (longlong *)0x0;
          local_c8 = (longlong *)0x0;
          local_d0 = (longlong *)0x0;
          local_c0 = (longlong *)0x0;
          local_b0 = (longlong *)0x0;
          local_b8 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          local_110 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
          local_f8 = (longlong *)0x0;
          local_f0 = (longlong *)0x0;
          local_e8 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
        }
        goto LAB_23e802e95;
      }
      lVar15 = FUN_23e8dced0();
      if (lVar15 == 0) {
        FUN_23e915740(param_1,local_78,_DAT_23eedd178);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          FUN_23a334bc0(plVar9);
        }
        *plVar17 = *plVar17 + -1;
        plVar10 = (longlong *)0x0;
        if (*plVar17 == 0) {
          plVar19 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          FUN_23a334bc0(plVar17);
          uVar18 = 0xaf;
          local_e0 = (longlong *)0x0;
          local_d8 = (longlong *)0x0;
          local_c8 = (longlong *)0x0;
          local_d0 = (longlong *)0x0;
          local_c0 = (longlong *)0x0;
          local_b0 = (longlong *)0x0;
          local_b8 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          local_110 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
          local_f8 = (longlong *)0x0;
          local_f0 = (longlong *)0x0;
          local_e8 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
        }
        else {
          plVar19 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          local_e0 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          uVar18 = 0xaf;
          local_d8 = (longlong *)0x0;
          local_c8 = (longlong *)0x0;
          local_d0 = (longlong *)0x0;
          local_c0 = (longlong *)0x0;
          local_b0 = (longlong *)0x0;
          local_b8 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          local_110 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
          local_f8 = (longlong *)0x0;
          local_f0 = (longlong *)0x0;
          local_e8 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
        }
        goto LAB_23e802e95;
      }
      *(undefined4 *)(plVar3 + 5) = 0xaf;
      local_90 = lVar15;
      local_88 = plVar17;
      plVar10 = (longlong *)FUN_23e939900(param_1,plVar9,&local_88,&local_90,_DAT_23eedd180);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        FUN_23a334bc0(plVar9);
      }
      *plVar17 = *plVar17 + -1;
      if (*plVar17 == 0) {
        FUN_23a334bc0(plVar17);
      }
      if (plVar10 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar13 = (longlong *)0x0;
        uVar18 = 0xaf;
        local_e0 = (longlong *)0x0;
        local_d8 = (longlong *)0x0;
        local_c8 = (longlong *)0x0;
        local_d0 = (longlong *)0x0;
        local_c0 = (longlong *)0x0;
        local_b0 = (longlong *)0x0;
        local_b8 = (longlong *)0x0;
        local_118 = (longlong *)0x0;
        local_120 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        plVar19 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        local_f8 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        local_e8 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar10 = (longlong *)0x0;
        goto LAB_23e802e95;
      }
      cVar5 = FUN_23e8d9ac0(plVar1,_DAT_23eedd198,plVar10);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        FUN_23a334bc0(plVar10);
      }
      plVar9 = _DAT_23eedd288;
      if (cVar5 == '\0') {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        local_108 = (longlong *)0x0;
        uVar18 = 0xaf;
        plVar19 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        local_f8 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        local_e8 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_e0 = (longlong *)0x0;
        local_d8 = (longlong *)0x0;
        local_c8 = (longlong *)0x0;
        local_d0 = (longlong *)0x0;
        local_c0 = (longlong *)0x0;
        local_b0 = (longlong *)0x0;
        local_b8 = (longlong *)0x0;
        local_118 = (longlong *)0x0;
        local_120 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e802e95;
      }
    }
    goto LAB_23e802d30;
  }
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd270);
  if (plVar9 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    plVar19 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    uVar18 = 0xb2;
    local_e0 = (longlong *)0x0;
    local_d8 = (longlong *)0x0;
    local_c8 = (longlong *)0x0;
    local_d0 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    local_b0 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    local_118 = (longlong *)0x0;
    local_120 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_f8 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar14 = (longlong *)0x0;
    goto LAB_23e802e95;
  }
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd158);
  if (plVar10 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar9 = *plVar9 + -1;
    plVar10 = (longlong *)0x0;
    if (*plVar9 == 0) {
      plVar19 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      (**(code **)(plVar9[1] + 0x30))(plVar9);
      uVar18 = 0xb2;
      local_e0 = (longlong *)0x0;
      local_d8 = (longlong *)0x0;
      local_c8 = (longlong *)0x0;
      local_d0 = (longlong *)0x0;
      local_c0 = (longlong *)0x0;
      local_b0 = (longlong *)0x0;
      local_b8 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_120 = (longlong *)0x0;
      local_110 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_f8 = (longlong *)0x0;
      local_f0 = (longlong *)0x0;
      local_e8 = (longlong *)0x0;
      local_100 = (longlong *)0x0;
    }
    else {
      local_e0 = (longlong *)0x0;
      plVar19 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      local_d8 = (longlong *)0x0;
      uVar18 = 0xb2;
      local_c8 = (longlong *)0x0;
      local_d0 = (longlong *)0x0;
      local_c0 = (longlong *)0x0;
      local_b0 = (longlong *)0x0;
      local_b8 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_120 = (longlong *)0x0;
      local_110 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_f8 = (longlong *)0x0;
      local_f0 = (longlong *)0x0;
      local_e8 = (longlong *)0x0;
      local_100 = (longlong *)0x0;
    }
    goto LAB_23e802e95;
  }
  *(undefined4 *)(plVar3 + 5) = 0xb2;
  plVar13 = (longlong *)FUN_23e914090(param_1);
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if (plVar13 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    plVar19 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar10 = (longlong *)0x0;
    uVar18 = 0xb2;
    local_e0 = (longlong *)0x0;
    local_d8 = (longlong *)0x0;
    local_c8 = (longlong *)0x0;
    local_d0 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    local_b0 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    local_118 = (longlong *)0x0;
    local_120 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_f8 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e802e95;
  }
  iVar6 = FUN_23a35f020();
  if (iVar6 == -1) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    local_e0 = (longlong *)0x0;
    plVar19 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar18 = 0xb3;
    local_d8 = (longlong *)0x0;
    local_c8 = (longlong *)0x0;
    local_d0 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    local_b0 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    local_118 = (longlong *)0x0;
    local_120 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_f8 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e802e95;
  }
  if (iVar6 == 0) {
    cVar5 = FUN_23e8d9ac0(plVar1,_DAT_23eedd158,DAT_23ed6ccf0);
    if (cVar5 == '\0') {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      plVar19 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar10 = (longlong *)0x0;
      uVar18 = 0xb4;
      local_e0 = (longlong *)0x0;
      local_d8 = (longlong *)0x0;
      local_c8 = (longlong *)0x0;
      local_d0 = (longlong *)0x0;
      local_c0 = (longlong *)0x0;
      local_b0 = (longlong *)0x0;
      local_b8 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_120 = (longlong *)0x0;
      local_110 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_f8 = (longlong *)0x0;
      local_f0 = (longlong *)0x0;
      local_e8 = (longlong *)0x0;
      local_100 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e802e95;
    }
    cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eedd160,_Py_NoneStruct_exref);
    if (cVar5 == '\0') {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      uVar18 = 0xb5;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar19 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      local_e0 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      local_d8 = (longlong *)0x0;
      local_c8 = (longlong *)0x0;
      local_d0 = (longlong *)0x0;
      local_c0 = (longlong *)0x0;
      local_b0 = (longlong *)0x0;
      local_b8 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_120 = (longlong *)0x0;
      local_110 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_f8 = (longlong *)0x0;
      local_f0 = (longlong *)0x0;
      local_e8 = (longlong *)0x0;
      local_100 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e802e95;
    }
    *(undefined4 *)(plVar3 + 5) = 0xb6;
    plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eedd258);
    if (plVar10 == (longlong *)0x0) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      plVar19 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar14 = (longlong *)0x0;
      uVar18 = 0xb6;
      local_e0 = (longlong *)0x0;
      local_d8 = (longlong *)0x0;
      local_c8 = (longlong *)0x0;
      local_d0 = (longlong *)0x0;
      local_c0 = (longlong *)0x0;
      local_b0 = (longlong *)0x0;
      local_b8 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_120 = (longlong *)0x0;
      local_110 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_f8 = (longlong *)0x0;
      local_f0 = (longlong *)0x0;
      local_e8 = (longlong *)0x0;
      local_100 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar10 = (longlong *)0x0;
      goto LAB_23e802e95;
    }
    *plVar10 = *plVar10 + -1;
    plVar9 = _DAT_23eedd290;
    if (*plVar10 == 0) {
      FUN_23a334bc0(plVar10);
      plVar9 = _DAT_23eedd290;
    }
LAB_23e803d45:
    *plVar9 = *plVar9 + 1;
    plVar19 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    local_118 = (longlong *)0x0;
    local_120 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_f8 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    goto LAB_23e802849;
  }
  pcVar11 = (code *)FUN_23e8bc2f0(plVar1,DAT_23eedd160);
  if (pcVar11 == (code *)0x0) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar18 = 0xb9;
    local_e0 = (longlong *)0x0;
    local_d8 = (longlong *)0x0;
    local_c8 = (longlong *)0x0;
    local_d0 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    local_b0 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    local_118 = (longlong *)0x0;
    local_120 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    plVar19 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    local_f8 = (longlong *)0x0;
    local_f0 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = (longlong *)0x0;
    goto LAB_23e802e95;
  }
  *(longlong *)pcVar11 = *(longlong *)pcVar11 + -1;
  if (*(longlong *)pcVar11 == 0) {
    (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
  }
  pcVar4 = _Py_NoneStruct_exref;
  if (pcVar11 == _Py_NoneStruct_exref) {
    cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eedd160);
    plVar9 = _DAT_23eedd288;
    if (cVar5 == '\0') {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      local_e0 = (longlong *)0x0;
      uVar18 = 0xba;
      plVar19 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_d8 = (longlong *)0x0;
      local_c8 = (longlong *)0x0;
      local_d0 = (longlong *)0x0;
      local_c0 = (longlong *)0x0;
      local_b0 = (longlong *)0x0;
      local_b8 = (longlong *)0x0;
      local_118 = (longlong *)0x0;
      local_120 = (longlong *)0x0;
      local_110 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_f8 = (longlong *)0x0;
      local_f0 = (longlong *)0x0;
      local_e8 = (longlong *)0x0;
      local_100 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e802e95;
    }
    goto LAB_23e803d45;
  }
  plVar19 = (longlong *)FUN_23a388310();
  if (plVar19 == (longlong *)0x0) {
    uVar12 = *(undefined8 *)(param_1 + 0x60);
    uVar20 = *(undefined8 *)(param_1 + 0x68);
    plVar9 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
  }
  else {
    plVar10 = (longlong *)(**(code **)(plVar19[1] + 0xe0))(plVar19);
    if ((plVar10 == (longlong *)0x0) &&
       (plVar10 = (longlong *)FUN_23a3c1b70(param_1,local_78,0,3), plVar10 == (longlong *)0x0)) {
      plVar14 = (longlong *)0x0;
      local_100 = (longlong *)0x0;
    }
    else {
      plVar14 = (longlong *)(**(code **)(plVar19[1] + 0xe0))(plVar19);
      if ((plVar14 == (longlong *)0x0) &&
         (plVar14 = (longlong *)FUN_23a3c1b70(param_1,local_78,1,3), plVar14 == (longlong *)0x0)) {
        local_100 = (longlong *)0x0;
      }
      else {
        local_100 = (longlong *)(**(code **)(plVar19[1] + 0xe0))(plVar19);
        if (((local_100 != (longlong *)0x0) ||
            (local_100 = (longlong *)FUN_23a3c1b70(param_1,local_78,2,3),
            local_100 != (longlong *)0x0)) &&
           (cVar5 = FUN_23a3884a0(param_1,local_78,plVar19), cVar5 != '\0')) {
          *plVar19 = *plVar19 + -1;
          if (*plVar19 == 0) {
            FUN_23a334bc0(plVar19);
          }
          if (*plVar10 == 0) {
            FUN_23a334bc0(plVar10);
          }
          if (*plVar14 == 0) {
            FUN_23a334bc0(plVar14);
          }
          if (*local_100 == 0) {
            FUN_23a334bc0(local_100);
          }
          plVar19 = (longlong *)FUN_23a388310(plVar8);
          if (plVar19 == (longlong *)0x0) {
            uVar12 = *(undefined8 *)(param_1 + 0x60);
            uVar20 = *(undefined8 *)(param_1 + 0x68);
            plVar9 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
          }
          else {
            local_e8 = (longlong *)FUN_23a3c1d30(param_1,local_78,plVar19,0,CONCAT44(uVar18,3));
            if (local_e8 == (longlong *)0x0) {
              local_f8 = (longlong *)0x0;
              local_f0 = (longlong *)0x0;
            }
            else {
              local_f0 = (longlong *)FUN_23a3c1d30(param_1,local_78,plVar19,1,3);
              if (local_f0 == (longlong *)0x0) {
                local_f8 = (longlong *)0x0;
              }
              else {
                local_f8 = (longlong *)FUN_23a3c1d30(param_1,local_78,plVar19,2,3);
                if ((local_f8 != (longlong *)0x0) &&
                   (cVar5 = FUN_23a3884a0(param_1,local_78), cVar5 != '\0')) {
                  *plVar19 = *plVar19 + -1;
                  if (*plVar19 == 0) {
                    FUN_23a334bc0(plVar19);
                  }
                  if (*local_e8 == 0) {
                    FUN_23a334bc0(local_e8);
                  }
                  if (*local_f0 == 0) {
                    FUN_23a334bc0(local_f0);
                  }
                  if (*local_f8 == 0) {
                    FUN_23a334bc0(local_f8);
                  }
                  lVar15 = FUN_23e8dcae0();
                  if (lVar15 == 0) {
                    plVar19 = (longlong *)0x0;
                    FUN_23e915740(param_1,local_78);
                    uVar18 = 0xbf;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_b0 = (longlong *)0x0;
                    local_b8 = (longlong *)0x0;
                    local_118 = (longlong *)0x0;
                    local_120 = (longlong *)0x0;
                    local_110 = (longlong *)0x0;
                    local_108 = (longlong *)0x0;
                    goto LAB_23e802e95;
                  }
                  plVar19 = (longlong *)FUN_23e8bc2f0();
                  if (plVar19 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plVar19 = (longlong *)0x0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_b0 = (longlong *)0x0;
                    local_b8 = (longlong *)0x0;
                    local_118 = (longlong *)0x0;
                    local_110 = (longlong *)0x0;
                    uVar18 = 0xbf;
                    local_108 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    local_120 = (longlong *)0x0;
                    goto LAB_23e802e95;
                  }
                  plVar9 = (longlong *)FUN_23e8c6640(plVar10,local_e8);
                  if (plVar9 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    lVar15 = *plVar19;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar19 = lVar15 + -1;
                    local_108 = (longlong *)0x0;
                    if (lVar15 + -1 == 0) {
                      FUN_23a334bc0();
                      plVar19 = (longlong *)0x0;
                      uVar18 = 0xbf;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                      local_c0 = (longlong *)0x0;
                      local_b0 = (longlong *)0x0;
                      local_b8 = (longlong *)0x0;
                      local_118 = (longlong *)0x0;
                      local_120 = (longlong *)0x0;
                      local_110 = (longlong *)0x0;
                    }
                    else {
                      uVar18 = 0xbf;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                      local_c0 = (longlong *)0x0;
                      local_b0 = (longlong *)0x0;
                      local_b8 = (longlong *)0x0;
                      local_118 = (longlong *)0x0;
                      local_120 = (longlong *)0x0;
                      local_110 = (longlong *)0x0;
                      plVar19 = (longlong *)0x0;
                    }
                    goto LAB_23e802e95;
                  }
                  plVar16 = (longlong *)FUN_23e8c5300(plVar9,_DAT_23eedd2a8);
                  lVar15 = *plVar9;
                  *plVar9 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  if (plVar16 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    lVar15 = *plVar19;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar19 = lVar15 + -1;
                    plVar19 = (longlong *)0x0;
                    if (lVar15 + -1 == 0) {
                      FUN_23a334bc0();
                      uVar18 = 0xbf;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                      local_c0 = (longlong *)0x0;
                      local_b0 = (longlong *)0x0;
                      local_b8 = (longlong *)0x0;
                      local_118 = (longlong *)0x0;
                      local_120 = (longlong *)0x0;
                      local_110 = (longlong *)0x0;
                      local_108 = (longlong *)0x0;
                    }
                    else {
                      uVar18 = 0xbf;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                      local_c0 = (longlong *)0x0;
                      local_b0 = (longlong *)0x0;
                      local_b8 = (longlong *)0x0;
                      local_118 = (longlong *)0x0;
                      local_120 = (longlong *)0x0;
                      local_110 = (longlong *)0x0;
                      local_108 = (longlong *)0x0;
                    }
                    goto LAB_23e802e95;
                  }
                  plVar9 = (longlong *)FUN_23e8c6640(plVar14,local_f0);
                  if (plVar9 == (longlong *)0x0) {
                    local_68 = *(longlong **)(param_1 + 0x70);
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    lVar15 = *plVar19;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar19 = lVar15 + -1;
                    if (lVar15 + -1 == 0) {
                      FUN_23a334bc0();
                    }
                    *plVar16 = *plVar16 + -1;
                    local_108 = (longlong *)0x0;
                    if (*plVar16 == 0) {
                      plVar19 = (longlong *)0x0;
                      FUN_23a334bc0(plVar16);
                      uVar18 = 0xbf;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                      local_c0 = (longlong *)0x0;
                      local_b0 = (longlong *)0x0;
                      local_b8 = (longlong *)0x0;
                      local_118 = (longlong *)0x0;
                      local_120 = (longlong *)0x0;
                      local_110 = (longlong *)0x0;
                    }
                    else {
                      uVar18 = 0xbf;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                      local_c0 = (longlong *)0x0;
                      local_b0 = (longlong *)0x0;
                      local_b8 = (longlong *)0x0;
                      local_118 = (longlong *)0x0;
                      local_120 = (longlong *)0x0;
                      local_110 = (longlong *)0x0;
                      plVar19 = (longlong *)0x0;
                    }
                    goto LAB_23e802e95;
                  }
                  plVar17 = (longlong *)FUN_23e8c5300(plVar9);
                  lVar15 = *plVar9;
                  *plVar9 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  if (plVar17 == (longlong *)0x0) {
                    local_68 = *(longlong **)(param_1 + 0x70);
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    lVar15 = *plVar19;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar19 = lVar15 + -1;
                    if (lVar15 + -1 == 0) {
                      FUN_23a334bc0();
                    }
                    *plVar16 = *plVar16 + -1;
                    local_110 = (longlong *)0x0;
                    if (*plVar16 == 0) {
                      plVar19 = (longlong *)0x0;
                      FUN_23a334bc0(plVar16);
                      local_108 = (longlong *)0x0;
                      uVar18 = 0xbf;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                      local_c0 = (longlong *)0x0;
                      local_b0 = (longlong *)0x0;
                      local_b8 = (longlong *)0x0;
                      local_118 = (longlong *)0x0;
                      local_120 = (longlong *)0x0;
                    }
                    else {
                      plVar19 = (longlong *)0x0;
                      local_e0 = (longlong *)0x0;
                      uVar18 = 0xbf;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                      local_c0 = (longlong *)0x0;
                      local_b0 = (longlong *)0x0;
                      local_b8 = (longlong *)0x0;
                      local_118 = (longlong *)0x0;
                      local_120 = (longlong *)0x0;
                      local_108 = (longlong *)0x0;
                    }
                    goto LAB_23e802e95;
                  }
                  plVar9 = (longlong *)FUN_23e8c09e0(plVar16,plVar17);
                  *plVar16 = *plVar16 + -1;
                  if (*plVar16 == 0) {
                    FUN_23a334bc0(plVar16);
                  }
                  lVar15 = *plVar17;
                  *plVar17 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  if (plVar9 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    lVar15 = *plVar19;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar19 = lVar15 + -1;
                    local_108 = (longlong *)0x0;
                    if (lVar15 + -1 == 0) {
                      FUN_23a334bc0();
                      plVar19 = (longlong *)0x0;
                      uVar18 = 0xbf;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                      local_c0 = (longlong *)0x0;
                      local_b0 = (longlong *)0x0;
                      local_b8 = (longlong *)0x0;
                      local_118 = (longlong *)0x0;
                      local_120 = (longlong *)0x0;
                      local_110 = (longlong *)0x0;
                    }
                    else {
                      plVar19 = (longlong *)0x0;
                      uVar18 = 0xbf;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                      local_c0 = (longlong *)0x0;
                      local_b0 = (longlong *)0x0;
                      local_b8 = (longlong *)0x0;
                      local_118 = (longlong *)0x0;
                      local_120 = (longlong *)0x0;
                      local_110 = (longlong *)0x0;
                    }
                    goto LAB_23e802e95;
                  }
                  plVar16 = (longlong *)FUN_23e8c6640(local_100,local_f8);
                  if (plVar16 == (longlong *)0x0) {
                    local_68 = *(longlong **)(param_1 + 0x70);
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    lVar15 = *plVar19;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar19 = lVar15 + -1;
                    if (lVar15 + -1 == 0) {
                      FUN_23a334bc0();
                    }
                    lVar15 = *plVar9;
                    *plVar9 = lVar15 + -1;
                    plVar19 = (longlong *)0x0;
                    if (lVar15 + -1 == 0) {
                      FUN_23a334bc0(plVar9);
                      uVar18 = 0xbf;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                      local_c0 = (longlong *)0x0;
                      local_b0 = (longlong *)0x0;
                      local_b8 = (longlong *)0x0;
                      local_118 = (longlong *)0x0;
                      local_120 = (longlong *)0x0;
                      local_110 = (longlong *)0x0;
                      local_108 = (longlong *)0x0;
                    }
                    else {
                      uVar18 = 0xbf;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                      local_c0 = (longlong *)0x0;
                      local_b0 = (longlong *)0x0;
                      local_b8 = (longlong *)0x0;
                      local_118 = (longlong *)0x0;
                      local_120 = (longlong *)0x0;
                      local_110 = (longlong *)0x0;
                      local_108 = (longlong *)0x0;
                    }
                    goto LAB_23e802e95;
                  }
                  plVar17 = (longlong *)FUN_23e8c5300(plVar16);
                  *plVar16 = *plVar16 + -1;
                  if (*plVar16 == 0) {
                    FUN_23a334bc0(plVar16);
                  }
                  if (plVar17 == (longlong *)0x0) {
                    local_68 = *(longlong **)(param_1 + 0x70);
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    lVar15 = *plVar19;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar19 = lVar15 + -1;
                    if (lVar15 + -1 == 0) {
                      FUN_23a334bc0();
                    }
                    lVar15 = *plVar9;
                    *plVar9 = lVar15 + -1;
                    local_110 = (longlong *)0x0;
                    if (lVar15 + -1 == 0) {
                      plVar19 = (longlong *)0x0;
                      FUN_23a334bc0(plVar9);
                      local_108 = (longlong *)0x0;
                      uVar18 = 0xbf;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                      local_c0 = (longlong *)0x0;
                      local_b0 = (longlong *)0x0;
                      local_b8 = (longlong *)0x0;
                      local_118 = (longlong *)0x0;
                      local_120 = (longlong *)0x0;
                    }
                    else {
                      plVar19 = (longlong *)0x0;
                      local_e0 = (longlong *)0x0;
                      uVar18 = 0xbf;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                      local_c0 = (longlong *)0x0;
                      local_b0 = (longlong *)0x0;
                      local_b8 = (longlong *)0x0;
                      local_118 = (longlong *)0x0;
                      local_120 = (longlong *)0x0;
                      local_108 = (longlong *)0x0;
                    }
                    goto LAB_23e802e95;
                  }
                  plVar16 = (longlong *)FUN_23e8c09e0(plVar9,plVar17);
                  lVar15 = *plVar9;
                  *plVar9 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  lVar15 = *plVar17;
                  *plVar17 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  if (plVar16 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    lVar15 = *plVar19;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar19 = lVar15 + -1;
                    plVar19 = (longlong *)0x0;
                    if (lVar15 + -1 == 0) {
                      FUN_23a334bc0();
                      uVar18 = 0xbf;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                      local_c0 = (longlong *)0x0;
                      local_b0 = (longlong *)0x0;
                      local_b8 = (longlong *)0x0;
                      local_118 = (longlong *)0x0;
                      local_120 = (longlong *)0x0;
                      local_110 = (longlong *)0x0;
                      local_108 = (longlong *)0x0;
                    }
                    else {
                      uVar18 = 0xbf;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                      local_c0 = (longlong *)0x0;
                      local_b0 = (longlong *)0x0;
                      local_b8 = (longlong *)0x0;
                      local_118 = (longlong *)0x0;
                      local_120 = (longlong *)0x0;
                      local_110 = (longlong *)0x0;
                      local_108 = (longlong *)0x0;
                    }
                    goto LAB_23e802e95;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0xbf;
                  local_108 = (longlong *)FUN_23e914090(param_1,plVar19,plVar16);
                  lVar15 = *plVar19;
                  *plVar19 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  *plVar16 = *plVar16 + -1;
                  if (*plVar16 == 0) {
                    FUN_23a334bc0(plVar16);
                  }
                  if (local_108 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    plVar19 = (longlong *)0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar18 = 0xbf;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_b0 = (longlong *)0x0;
                    local_b8 = (longlong *)0x0;
                    local_118 = (longlong *)0x0;
                    local_120 = (longlong *)0x0;
                    local_110 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e802e95;
                  }
                  lVar15 = *(longlong *)(DAT_23eedd0f0 + 0x20);
                  if (*(char *)(lVar15 + 10) == '\0') {
                    plVar19 = (longlong *)FUN_23a37a020(DAT_23eedd0f0,_DAT_23eedd2b0);
                    if (plVar19 == (longlong *)0x0) goto LAB_23e80a198;
                    lVar15 = *plVar19;
LAB_23e80a18f:
                    if (lVar15 == 0) goto LAB_23e80a198;
                  }
                  else {
                    iVar6 = *(int *)(lVar15 + 0xc);
                    if (*(int *)(lVar15 + 0xc) == 0) {
                      *(int *)(lVar15 + 0xc) = DAT_23ec155d8;
                      iVar6 = DAT_23ec155d8;
                      DAT_23ec155d8 = DAT_23ec155d8 + 1;
                    }
                    if (_DAT_23ec155d0 != iVar6) {
                      _DAT_23ec155d0 = iVar6;
                      _DAT_23eede908 =
                           FUN_23e8cbd60(lVar15,_DAT_23eedd2b0,
                                         *(undefined8 *)(_DAT_23eedd2b0 + 0x18));
                    }
                    if (-1 < _DAT_23eede908) {
                      lVar2 = lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f));
                      if (*(longlong *)(lVar2 + 8 + _DAT_23eede908 * 0x10) != 0) goto LAB_23e8045df;
                      _DAT_23eede908 =
                           FUN_23e8cbd60(lVar15,_DAT_23eedd2b0,
                                         *(undefined8 *)(_DAT_23eedd2b0 + 0x18));
                      if (-1 < _DAT_23eede908) {
                        lVar15 = *(longlong *)(lVar2 + 8 + _DAT_23eede908 * 0x10);
                        goto LAB_23e80a18f;
                      }
                    }
LAB_23e80a198:
                    plVar19 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedd2b0);
                    if ((plVar19 == (longlong *)0x0) || (*plVar19 == 0)) {
                      plVar19 = (longlong *)0x0;
                      FUN_23e915740(param_1,local_78,_DAT_23eedd2b0);
                      uVar18 = 0xc0;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                      local_c0 = (longlong *)0x0;
                      local_b0 = (longlong *)0x0;
                      local_b8 = (longlong *)0x0;
                      local_118 = (longlong *)0x0;
                      local_120 = (longlong *)0x0;
                      local_110 = (longlong *)0x0;
                      goto LAB_23e802e95;
                    }
                  }
LAB_23e8045df:
                  iVar6 = FUN_23e97dbc0(local_108);
                  if (iVar6 == -1) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    local_e0 = (longlong *)0x0;
                    uVar18 = 0xc0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_b0 = (longlong *)0x0;
                    local_b8 = (longlong *)0x0;
                    local_118 = (longlong *)0x0;
                    local_120 = (longlong *)0x0;
                    local_110 = (longlong *)0x0;
                    plVar19 = (longlong *)0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e802e95;
                  }
                  if (iVar6 == 1) {
                    cVar5 = FUN_23e8d9ac0(plVar1,_DAT_23eedd158);
                    if (cVar5 == '\0') {
                      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_68 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar18 = 0xc1;
                      plVar19 = (longlong *)0x0;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                      local_c0 = (longlong *)0x0;
                      local_b0 = (longlong *)0x0;
                      local_b8 = (longlong *)0x0;
                      local_118 = (longlong *)0x0;
                      local_120 = (longlong *)0x0;
                      local_110 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e802e95;
                    }
                    cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eedd160,pcVar4);
                    if (cVar5 == '\0') {
                      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_68 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar18 = 0xc2;
                      plVar19 = (longlong *)0x0;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                      local_c0 = (longlong *)0x0;
                      local_b0 = (longlong *)0x0;
                      local_b8 = (longlong *)0x0;
                      local_118 = (longlong *)0x0;
                      local_120 = (longlong *)0x0;
                      local_110 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e802e95;
                    }
                    *(undefined4 *)(plVar3 + 5) = 0xc3;
                    plVar19 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eedd258);
                    if (plVar19 == (longlong *)0x0) {
                      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_68 = *(longlong **)(param_1 + 0x70);
                      uVar18 = 0xc3;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                      local_c0 = (longlong *)0x0;
                      local_b0 = (longlong *)0x0;
                      local_b8 = (longlong *)0x0;
                      local_118 = (longlong *)0x0;
                      local_120 = (longlong *)0x0;
                      local_110 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plVar19 = (longlong *)0x0;
                      goto LAB_23e802e95;
                    }
                    *plVar19 = *plVar19 + -1;
                    if (*plVar19 == 0) {
                      FUN_23a334bc0(plVar19);
                    }
                    plVar9 = _DAT_23eedd290;
                    plVar19 = (longlong *)0x0;
                    local_118 = (longlong *)0x0;
                    *_DAT_23eedd290 = *_DAT_23eedd290 + 1;
                    local_120 = (longlong *)0x0;
                    local_110 = (longlong *)0x0;
                    goto LAB_23e802849;
                  }
                  lVar15 = FUN_23e8dcd80();
                  if (lVar15 == 0) {
                    FUN_23e915740(param_1,local_78,_DAT_23eedd1a0);
                    uVar18 = 0xc6;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_b0 = (longlong *)0x0;
                    local_b8 = (longlong *)0x0;
                    local_118 = (longlong *)0x0;
                    local_120 = (longlong *)0x0;
                    local_110 = (longlong *)0x0;
                    plVar19 = (longlong *)0x0;
                    goto LAB_23e802e95;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0xc6;
                  plVar19 = (longlong *)FUN_23e91bfe0(param_1,lVar15);
                  if (plVar19 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xc6;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_b0 = (longlong *)0x0;
                    local_b8 = (longlong *)0x0;
                    local_118 = (longlong *)0x0;
                    local_120 = (longlong *)0x0;
                    local_110 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e802e95;
                  }
                  uVar12 = FUN_23a3a0d40(DAT_23eedd2b8);
                  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd1a8);
                  if (plVar9 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 199;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_b0 = (longlong *)0x0;
                    local_b8 = (longlong *)0x0;
                    local_118 = (longlong *)0x0;
                    local_120 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    local_110 = (longlong *)0x0;
                    goto LAB_23e802e95;
                  }
                  plVar16 = (longlong *)FUN_23e8c6640(plVar19,plVar9);
                  lVar15 = *plVar9;
                  *plVar9 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  uVar20 = _DAT_23eedd2c0;
                  if (plVar16 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 199;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_b0 = (longlong *)0x0;
                    local_b8 = (longlong *)0x0;
                    local_118 = (longlong *)0x0;
                    local_110 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    local_120 = (longlong *)0x0;
                    goto LAB_23e802e95;
                  }
                  *(undefined4 *)(plVar3 + 5) = 199;
                  uStack_80 = uVar20;
                  local_88 = plVar16;
                  local_110 = (longlong *)FUN_23e94ed00(param_1,uVar12);
                  lVar15 = *plVar16;
                  *plVar16 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  if (local_110 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 199;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_b0 = (longlong *)0x0;
                    local_b8 = (longlong *)0x0;
                    local_118 = (longlong *)0x0;
                    local_120 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e802e95;
                  }
                  cVar5 = FUN_23e8d9ac0(plVar1,_DAT_23eedd1a8,plVar19);
                  if (cVar5 == '\0') {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar18 = 200;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_b0 = (longlong *)0x0;
                    local_b8 = (longlong *)0x0;
                    local_118 = (longlong *)0x0;
                    local_120 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e802e95;
                  }
                  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedd160);
                  if (plVar9 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xca;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_b0 = (longlong *)0x0;
                    local_b8 = (longlong *)0x0;
                    local_118 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    local_120 = (longlong *)0x0;
                    goto LAB_23e802e95;
                  }
                  plVar16 = (longlong *)FUN_23a388650(param_1,plVar9,DAT_23ed6ccf0,0);
                  lVar15 = *plVar9;
                  *plVar9 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  if (plVar16 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xca;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_b0 = (longlong *)0x0;
                    local_b8 = (longlong *)0x0;
                    local_120 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    local_118 = (longlong *)0x0;
                    goto LAB_23e802e95;
                  }
                  local_120 = (longlong *)FUN_23e8c6640(plVar10,plVar16);
                  lVar15 = *plVar16;
                  *plVar16 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  if (local_120 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xca;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_b0 = (longlong *)0x0;
                    local_b8 = (longlong *)0x0;
                    local_118 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e802e95;
                  }
                  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedd160);
                  if (plVar9 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xcb;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_b0 = (longlong *)0x0;
                    local_b8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    local_118 = (longlong *)0x0;
                    goto LAB_23e802e95;
                  }
                  plVar16 = (longlong *)FUN_23a388650(param_1,plVar9);
                  lVar15 = *plVar9;
                  *plVar9 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  if (plVar16 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xcb;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_b0 = (longlong *)0x0;
                    local_118 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    local_b8 = (longlong *)0x0;
                    goto LAB_23e802e95;
                  }
                  local_118 = (longlong *)FUN_23e8c6640(plVar14,plVar16);
                  lVar15 = *plVar16;
                  *plVar16 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  if (local_118 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xcb;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_b0 = (longlong *)0x0;
                    local_b8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e802e95;
                  }
                  plVar9 = (longlong *)FUN_23e8bd780(local_120);
                  if (plVar9 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xcc;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_b0 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    local_b8 = (longlong *)0x0;
                    goto LAB_23e802e95;
                  }
                  iVar6 = FUN_23e983850(plVar9,_DAT_23eedd2c8);
                  lVar15 = *plVar9;
                  *plVar9 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  if (iVar6 == -1) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar18 = 0xcc;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_b0 = (longlong *)0x0;
                    local_b8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e802e95;
                  }
                  if (iVar6 == 1) {
LAB_23e8097d2:
                    cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eedd160,plVar13);
                    plVar9 = _DAT_23eedd288;
                    if (cVar5 == '\0') {
                      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_68 = *(longlong **)(param_1 + 0x70);
                      uVar18 = 0xcd;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                      local_c0 = (longlong *)0x0;
                      local_b0 = (longlong *)0x0;
                      local_b8 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e802e95;
                    }
                    *_DAT_23eedd288 = *_DAT_23eedd288 + 1;
                    goto LAB_23e802849;
                  }
                  plVar9 = (longlong *)FUN_23e8bd780(local_118);
                  if (plVar9 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xcc;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_b0 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    local_b8 = (longlong *)0x0;
                    goto LAB_23e802e95;
                  }
                  iVar6 = FUN_23e983850(plVar9,_DAT_23eedd2c8);
                  lVar15 = *plVar9;
                  *plVar9 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  if (iVar6 == -1) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xcc;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_b0 = (longlong *)0x0;
                    local_b8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e802e95;
                  }
                  if (iVar6 == 1) goto LAB_23e8097d2;
                  local_b8 = (longlong *)FUN_23e8c6f80(local_120,local_110);
                  if (local_b8 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xd0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_b0 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e802e95;
                  }
                  local_b0 = (longlong *)FUN_23e8c6f80(local_118,local_110);
                  if (local_b0 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xd1;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e802e95;
                  }
                  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd188);
                  if (plVar9 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xd2;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    local_c0 = (longlong *)0x0;
                    goto LAB_23e802e95;
                  }
                  plVar16 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23eedd2d0);
                  lVar15 = *plVar9;
                  *plVar9 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  if (plVar16 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xd2;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    local_d0 = (longlong *)0x0;
                    goto LAB_23e802e95;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0xd2;
                  plVar9 = (longlong *)FUN_23e914090(param_1,plVar16,local_b8);
                  lVar15 = *plVar16;
                  *plVar16 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  if (plVar9 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    uVar18 = 0xd2;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    local_c0 = (longlong *)0x0;
                    goto LAB_23e802e95;
                  }
                  lVar15 = *plVar9;
                  *plVar9 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd190);
                  if (plVar9 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xd3;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    local_c0 = (longlong *)0x0;
                    goto LAB_23e802e95;
                  }
                  plVar16 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23eedd2d0);
                  lVar15 = *plVar9;
                  *plVar9 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  if (plVar16 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xd3;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    local_d0 = (longlong *)0x0;
                    goto LAB_23e802e95;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0xd3;
                  plVar9 = (longlong *)FUN_23e914090(param_1,plVar16);
                  lVar15 = *plVar16;
                  *plVar16 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  if (plVar9 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xd3;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    local_c0 = (longlong *)0x0;
                    goto LAB_23e802e95;
                  }
                  lVar15 = *plVar9;
                  *plVar9 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd188);
                  if (plVar9 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xd4;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    local_c0 = (longlong *)0x0;
                    goto LAB_23e802e95;
                  }
                  plVar16 = (longlong *)FUN_23e931a30(param_1,plVar9);
                  lVar15 = *plVar9;
                  *plVar9 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  if (plVar16 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xd4;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    local_d0 = (longlong *)0x0;
                    goto LAB_23e802e95;
                  }
                  lVar15 = FUN_23e8dced0();
                  if (lVar15 == 0) {
                    FUN_23e915740(param_1,local_78,_DAT_23eedd178);
                    lVar15 = *plVar16;
                    *plVar16 = lVar15 + -1;
                    local_c0 = (longlong *)0x0;
                    if (lVar15 + -1 == 0) {
                      FUN_23a334bc0(plVar16);
                      uVar18 = 0xd4;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                    }
                    else {
                      uVar18 = 0xd4;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_d0 = (longlong *)0x0;
                    }
                    goto LAB_23e802e95;
                  }
                  local_c0 = (longlong *)FUN_23e8c6f80(plVar16,lVar15);
                  lVar15 = *plVar16;
                  *plVar16 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0(plVar16);
                  }
                  if (local_c0 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xd4;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e802e95;
                  }
                  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd190);
                  if (plVar9 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xd5;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    local_d0 = (longlong *)0x0;
                    goto LAB_23e802e95;
                  }
                  plVar16 = (longlong *)FUN_23e931a30(param_1);
                  lVar15 = *plVar9;
                  *plVar9 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  if (plVar16 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_d0 = (longlong *)0x0;
                    uVar18 = 0xd5;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    local_c8 = (longlong *)0x0;
                    goto LAB_23e802e95;
                  }
                  lVar15 = FUN_23e8dced0();
                  if (lVar15 == 0) {
                    FUN_23e915740(param_1,local_78,_DAT_23eedd178);
                    lVar15 = *plVar16;
                    *plVar16 = lVar15 + -1;
                    local_d0 = (longlong *)0x0;
                    if (lVar15 + -1 == 0) {
                      FUN_23a334bc0(plVar16);
                      uVar18 = 0xd5;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                    }
                    else {
                      uVar18 = 0xd5;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                    }
                    goto LAB_23e802e95;
                  }
                  local_d0 = (longlong *)FUN_23e8c6f80(plVar16,lVar15);
                  lVar15 = *plVar16;
                  *plVar16 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0(plVar16);
                  }
                  if (local_d0 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xd5;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e802e95;
                  }
                  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd2d8);
                  if (plVar9 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xd7;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_d8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    local_e0 = (longlong *)0x0;
                    goto LAB_23e802e95;
                  }
                  plVar16 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd150);
                  if (plVar16 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    lVar15 = *plVar9;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar9 = lVar15 + -1;
                    local_d8 = (longlong *)0x0;
                    if (lVar15 + -1 == 0) {
                      FUN_23a334bc0();
                      uVar18 = 0xd7;
                      local_e0 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                    }
                    else {
                      uVar18 = 0xd7;
                      local_e0 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                    }
                    goto LAB_23e802e95;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0xd7;
                  local_c8 = (longlong *)FUN_23e914090(param_1,plVar9);
                  lVar15 = *plVar9;
                  *plVar9 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  lVar15 = *plVar16;
                  *plVar16 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  if (local_c8 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xd7;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e802e95;
                  }
                  iVar6 = FUN_23a35f020();
                  if (iVar6 == -1) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar18 = 0xd8;
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e802e95;
                  }
                  if (iVar6 == 0) {
                    lVar15 = FUN_23e8dc990();
                    if (lVar15 == 0) {
                      FUN_23e915740(param_1,local_78);
                      uVar18 = 0xe3;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      goto LAB_23e802e95;
                    }
                    iVar6 = FUN_23e97dbc0(local_d0,lVar15);
                    lVar15 = _DAT_23eedd2f8;
                    uVar12 = _DAT_23eedd2e8;
                    if (iVar6 == -1) {
                      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_68 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar18 = 0xe3;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e802e95;
                    }
                    if (iVar6 == 1) {
                      *(undefined4 *)(plVar3 + 5) = 0xe4;
                      local_d8 = (longlong *)
                                 FUN_23e915840(param_1,plVar1,uVar12,*(undefined8 *)(lVar15 + 0x18))
                      ;
                      if (local_d8 == (longlong *)0x0) {
                        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                        local_68 = *(longlong **)(param_1 + 0x70);
                        uVar18 = 0xe4;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        local_e0 = (longlong *)0x0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        local_d8 = (longlong *)0x0;
                        goto LAB_23e802e95;
                      }
LAB_23e808e6b:
                      lVar15 = *local_d8;
                      *local_d8 = lVar15 + -1;
                      if (lVar15 + -1 == 0) {
                        FUN_23a334bc0();
                      }
                    }
                    else {
                      lVar15 = FUN_23e8dc990();
                      if (lVar15 == 0) {
                        FUN_23e915740(param_1,local_78,_DAT_23eedd2e0);
                        uVar18 = 0xe5;
                        local_e0 = (longlong *)0x0;
                        local_d8 = (longlong *)0x0;
                        goto LAB_23e802e95;
                      }
                      plVar9 = (longlong *)PyNumber_Negative(lVar15);
                      if (plVar9 == (longlong *)0x0) {
                        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                        local_68 = *(longlong **)(param_1 + 0x70);
                        uVar18 = 0xe5;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        local_e0 = (longlong *)0x0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        local_d8 = (longlong *)0x0;
                        goto LAB_23e802e95;
                      }
                      iVar6 = FUN_23e97c060(local_d0,plVar9);
                      lVar15 = *plVar9;
                      *plVar9 = lVar15 + -1;
                      if (lVar15 + -1 == 0) {
                        FUN_23a334bc0();
                      }
                      lVar15 = _DAT_23eedd2f0;
                      uVar12 = _DAT_23eedd2e8;
                      if (iVar6 == -1) {
                        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                        local_68 = *(longlong **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar18 = 0xe5;
                        local_e0 = (longlong *)0x0;
                        local_d8 = (longlong *)0x0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23e802e95;
                      }
                      if (iVar6 == 1) {
                        *(undefined4 *)(plVar3 + 5) = 0xe6;
                        local_d8 = (longlong *)
                                   FUN_23e915840(param_1,plVar1,uVar12,
                                                 *(undefined8 *)(lVar15 + 0x18));
                        if (local_d8 == (longlong *)0x0) {
                          local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                          local_68 = *(longlong **)(param_1 + 0x70);
                          uVar18 = 0xe6;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          local_e0 = (longlong *)0x0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          local_d8 = (longlong *)0x0;
                          goto LAB_23e802e95;
                        }
                        goto LAB_23e808e6b;
                      }
                    }
                    local_e0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                  }
                  else {
                    plVar9 = (longlong *)FUN_23a388650(param_1,local_c8,DAT_23ed6ccf0,0);
                    if (plVar9 == (longlong *)0x0) {
                      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_68 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_e0 = (longlong *)0x0;
                      uVar18 = 0xd9;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      local_d8 = (longlong *)0x0;
                      goto LAB_23e802e95;
                    }
                    plVar16 = (longlong *)FUN_23e8c4990(local_c0,plVar9);
                    lVar15 = *plVar9;
                    *plVar9 = lVar15 + -1;
                    if (lVar15 + -1 == 0) {
                      FUN_23a334bc0();
                    }
                    if (plVar16 == (longlong *)0x0) {
                      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_68 = *(longlong **)(param_1 + 0x70);
                      uVar18 = 0xd9;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_e0 = (longlong *)0x0;
                      local_d8 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e802e95;
                    }
                    plVar9 = (longlong *)FUN_23a388650(param_1);
                    if (plVar9 == (longlong *)0x0) {
                      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_68 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar16 = *plVar16 + -1;
                      local_d8 = (longlong *)0x0;
                      if (*plVar16 == 0) {
                        FUN_23a334bc0(plVar16);
                        uVar18 = 0xd9;
                        local_e0 = (longlong *)0x0;
                      }
                      else {
                        local_e0 = (longlong *)0x0;
                        uVar18 = 0xd9;
                      }
                      goto LAB_23e802e95;
                    }
                    plVar17 = (longlong *)FUN_23e8c4990(local_d0,plVar9);
                    lVar15 = *plVar9;
                    *plVar9 = lVar15 + -1;
                    if (lVar15 + -1 == 0) {
                      FUN_23a334bc0();
                    }
                    if (plVar17 == (longlong *)0x0) {
                      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_68 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar16 = *plVar16 + -1;
                      local_e0 = (longlong *)0x0;
                      if (*plVar16 == 0) {
                        FUN_23a334bc0(plVar16);
                        uVar18 = 0xd9;
                        local_d8 = (longlong *)0x0;
                      }
                      else {
                        uVar18 = 0xd9;
                        local_d8 = (longlong *)0x0;
                      }
                      goto LAB_23e802e95;
                    }
                    local_d8 = (longlong *)FUN_23e8c09e0(plVar16,plVar17);
                    *plVar16 = *plVar16 + -1;
                    if (*plVar16 == 0) {
                      FUN_23a334bc0(plVar16);
                    }
                    lVar15 = *plVar17;
                    *plVar17 = lVar15 + -1;
                    if (lVar15 + -1 == 0) {
                      FUN_23a334bc0();
                    }
                    if (local_d8 == (longlong *)0x0) {
                      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_68 = *(longlong **)(param_1 + 0x70);
                      uVar18 = 0xd9;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_e0 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e802e95;
                    }
                    plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd198);
                    if (plVar9 == (longlong *)0x0) {
                      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_68 = *(longlong **)(param_1 + 0x70);
                      uVar18 = 0xda;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      local_e0 = (longlong *)0x0;
                      goto LAB_23e802e95;
                    }
                    plVar16 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23eedd2d0);
                    lVar15 = *plVar9;
                    *plVar9 = lVar15 + -1;
                    if (lVar15 + -1 == 0) {
                      FUN_23a334bc0();
                    }
                    if (plVar16 == (longlong *)0x0) {
                      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_68 = *(longlong **)(param_1 + 0x70);
                      uVar18 = 0xda;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_e0 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e802e95;
                    }
                    *(undefined4 *)(plVar3 + 5) = 0xda;
                    plVar9 = (longlong *)FUN_23e914090(param_1,plVar16,local_d8);
                    *plVar16 = *plVar16 + -1;
                    if (*plVar16 == 0) {
                      FUN_23a334bc0();
                    }
                    if (plVar9 == (longlong *)0x0) {
                      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_68 = *(longlong **)(param_1 + 0x70);
                      uVar18 = 0xda;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      local_e0 = (longlong *)0x0;
                      goto LAB_23e802e95;
                    }
                    lVar15 = *plVar9;
                    *plVar9 = lVar15 + -1;
                    if (lVar15 + -1 == 0) {
                      FUN_23a334bc0();
                    }
                    plVar9 = (longlong *)FUN_23e8bc2f0(plVar1);
                    if (plVar9 == (longlong *)0x0) {
                      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_68 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar18 = 0xdb;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      local_e0 = (longlong *)0x0;
                      goto LAB_23e802e95;
                    }
                    plVar16 = (longlong *)FUN_23e931a30(param_1,plVar9);
                    lVar15 = *plVar9;
                    *plVar9 = lVar15 + -1;
                    if (lVar15 + -1 == 0) {
                      FUN_23a334bc0();
                    }
                    if (plVar16 == (longlong *)0x0) {
                      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_68 = *(longlong **)(param_1 + 0x70);
                      uVar18 = 0xdb;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_e0 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e802e95;
                    }
                    lVar15 = FUN_23e8dced0();
                    if (lVar15 == 0) {
                      FUN_23e915740(param_1,local_78,_DAT_23eedd178);
                      *plVar16 = *plVar16 + -1;
                      local_e0 = (longlong *)0x0;
                      if (*plVar16 == 0) {
                        FUN_23a334bc0(plVar16);
                        uVar18 = 0xdb;
                      }
                      else {
                        uVar18 = 0xdb;
                      }
                      goto LAB_23e802e95;
                    }
                    local_e0 = (longlong *)FUN_23e8c6f80(plVar16,lVar15);
                    *plVar16 = *plVar16 + -1;
                    if (*plVar16 == 0) {
                      FUN_23a334bc0(plVar16);
                    }
                    if (local_e0 == (longlong *)0x0) {
                      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_68 = *(longlong **)(param_1 + 0x70);
                      uVar18 = 0xdb;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e802e95;
                    }
                    lVar15 = FUN_23e8dc990();
                    if (lVar15 == 0) {
                      FUN_23e915740(param_1,local_78,_DAT_23eedd2e0);
                      uVar18 = 0xdd;
                      goto LAB_23e802e95;
                    }
                    iVar6 = FUN_23e97dbc0(local_e0,lVar15);
                    lVar15 = _DAT_23eedd2f0;
                    uVar12 = _DAT_23eedd2e8;
                    if (iVar6 == -1) {
                      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_68 = *(longlong **)(param_1 + 0x70);
                      uVar18 = 0xdd;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e802e95;
                    }
                    if (iVar6 == 1) {
                      *(undefined4 *)(plVar3 + 5) = 0xde;
                      plVar9 = (longlong *)
                               FUN_23e915840(param_1,plVar1,uVar12,*(undefined8 *)(lVar15 + 0x18));
                      if (plVar9 == (longlong *)0x0) {
                        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                        local_68 = *(longlong **)(param_1 + 0x70);
                        uVar18 = 0xde;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23e802e95;
                      }
LAB_23e8073e4:
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 == 0) {
                        FUN_23a334bc0();
                      }
                    }
                    else {
                      lVar15 = FUN_23e8dc990();
                      if (lVar15 == 0) {
                        FUN_23e915740(param_1,local_78,_DAT_23eedd2e0);
                        uVar18 = 0xdf;
                        goto LAB_23e802e95;
                      }
                      plVar9 = (longlong *)PyNumber_Negative(lVar15);
                      if (plVar9 == (longlong *)0x0) {
                        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                        local_68 = *(longlong **)(param_1 + 0x70);
                        uVar18 = 0xdf;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23e802e95;
                      }
                      iVar6 = FUN_23e97c060(local_e0,plVar9);
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 == 0) {
                        FUN_23a334bc0(plVar9);
                      }
                      uVar12 = _DAT_23eedd2e8;
                      if (iVar6 == -1) {
                        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                        local_68 = *(longlong **)(param_1 + 0x70);
                        uVar18 = 0xdf;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23e802e95;
                      }
                      if (iVar6 == 1) {
                        *(undefined4 *)(plVar3 + 5) = 0xe0;
                        plVar9 = (longlong *)FUN_23e915840(param_1,plVar1,uVar12);
                        if (plVar9 == (longlong *)0x0) {
                          local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                          local_68 = *(longlong **)(param_1 + 0x70);
                          uVar18 = 0xe0;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          goto LAB_23e802e95;
                        }
                        goto LAB_23e8073e4;
                      }
                    }
                  }
                  cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eedd160,plVar13);
                  if (cVar5 == '\0') {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar18 = 0xe8;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e802e95;
                  }
                  FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                  plVar9 = _DAT_23eedd288;
                  *_DAT_23eedd288 = *_DAT_23eedd288 + 1;
                  *plVar8 = *plVar8 + -1;
                  if (*plVar8 == 0) {
                    (**(code **)(plVar8[1] + 0x30))(plVar8);
                    goto LAB_23e802908;
                  }
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) goto LAB_23e80290e;
                  goto LAB_23e80291d;
                }
              }
            }
            plVar9 = local_68;
            uVar12 = local_78._0_8_;
            uVar20 = local_78._8_8_;
            local_78 = (undefined1  [16])0x0;
            local_68 = (longlong *)0x0;
            *plVar19 = *plVar19 + -1;
            if (*plVar19 == 0) {
              FUN_23a334bc0(plVar19);
            }
            local_68 = (longlong *)0x0;
            local_78 = (undefined1  [16])0x0;
            if ((local_e8 != (longlong *)0x0) &&
               (lVar15 = *local_e8, *local_e8 = lVar15 + -1, lVar15 + -1 == 0)) {
              FUN_23a334bc0();
            }
            if ((local_f0 != (longlong *)0x0) &&
               (lVar15 = *local_f0, *local_f0 = lVar15 + -1, lVar15 + -1 == 0)) {
              FUN_23a334bc0();
            }
            if ((local_f8 != (longlong *)0x0) &&
               (lVar15 = *local_f8, *local_f8 = lVar15 + -1, lVar15 + -1 == 0)) {
              FUN_23a334bc0();
            }
          }
          uVar18 = 0xbe;
          plVar19 = (longlong *)0x0;
          local_e0 = (longlong *)0x0;
          local_d8 = (longlong *)0x0;
          local_c8 = (longlong *)0x0;
          local_d0 = (longlong *)0x0;
          local_c0 = (longlong *)0x0;
          local_b0 = (longlong *)0x0;
          local_b8 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
          local_120 = (longlong *)0x0;
          local_110 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
          local_f8 = (longlong *)0x0;
          local_f0 = (longlong *)0x0;
          local_e8 = (longlong *)0x0;
          local_78._8_8_ = uVar20;
          local_78._0_8_ = uVar12;
          local_68 = plVar9;
          goto LAB_23e802e95;
        }
      }
    }
    plVar9 = local_68;
    uVar12 = local_78._0_8_;
    uVar20 = local_78._8_8_;
    local_68 = (longlong *)0x0;
    local_78 = (undefined1  [16])0x0;
    *plVar19 = *plVar19 + -1;
    if (*plVar19 == 0) {
      FUN_23a334bc0(plVar19);
    }
    local_68 = (longlong *)0x0;
    local_78 = (undefined1  [16])0x0;
    if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
      FUN_23a334bc0(plVar10);
    }
    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
      FUN_23a334bc0(plVar14);
    }
    if ((local_100 != (longlong *)0x0) &&
       (lVar15 = *local_100, *local_100 = lVar15 + -1, lVar15 + -1 == 0)) {
      FUN_23a334bc0();
    }
  }
  plVar19 = (longlong *)0x0;
  uVar18 = 0xbd;
  plVar14 = (longlong *)0x0;
  local_e0 = (longlong *)0x0;
  plVar10 = (longlong *)0x0;
  local_d8 = (longlong *)0x0;
  local_c8 = (longlong *)0x0;
  local_d0 = (longlong *)0x0;
  local_c0 = (longlong *)0x0;
  local_b0 = (longlong *)0x0;
  local_b8 = (longlong *)0x0;
  local_118 = (longlong *)0x0;
  local_120 = (longlong *)0x0;
  local_110 = (longlong *)0x0;
  local_108 = (longlong *)0x0;
  local_f8 = (longlong *)0x0;
  local_f0 = (longlong *)0x0;
  local_e8 = (longlong *)0x0;
  local_100 = (longlong *)0x0;
  local_78._8_8_ = uVar20;
  local_78._0_8_ = uVar12;
  local_68 = plVar9;
LAB_23e802e95:
  plVar16 = local_68;
  plVar9 = DAT_23ed6a4f8;
  if (local_68 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar16 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar16;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar9[2] = 0;
    plVar9[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar18;
    pcVar11 = _PyRuntime_exref;
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar15 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar11 + 0x1f8) + 0x10) + 0x2e8);
    lVar2 = plVar9[-1];
    plVar16 = *(longlong **)(lVar15 + 8);
    *plVar16 = (longlong)(plVar9 + -2);
    plVar9[-2] = lVar15;
    plVar9[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)plVar16;
    *(longlong **)(lVar15 + 8) = plVar9 + -2;
    plVar16 = plVar9;
    if ((local_68 != (longlong *)0x0) && (*local_68 = *local_68 + -1, *local_68 == 0)) {
      (**(code **)(local_68[1] + 0x30))(local_68);
    }
  }
  else if ((longlong *)local_68[3] != plVar3) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar17 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar17;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar9[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar18;
    pcVar11 = _PyRuntime_exref;
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar15 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar11 + 0x1f8) + 0x10) + 0x2e8);
    lVar2 = plVar9[-1];
    plVar17 = *(longlong **)(lVar15 + 8);
    *plVar17 = (longlong)(plVar9 + -2);
    plVar9[-2] = lVar15;
    plVar9[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)plVar17;
    *(longlong **)(lVar15 + 8) = plVar9 + -2;
    plVar9[2] = (longlong)plVar16;
    *plVar16 = *plVar16 + 1;
    plVar16 = plVar9;
    if ((local_68 != (longlong *)0x0) && (*local_68 = *local_68 + -1, *local_68 == 0)) {
      (**(code **)(local_68[1] + 0x30))();
    }
  }
  local_68 = plVar16;
  FUN_23e8bba40(plVar3,"ooooooooooooooooooooo",plVar1,plVar8,plVar13,plVar10,plVar14,local_100,
                local_e8,local_f0,local_f8,local_108,plVar19,local_110,local_120,local_118,local_b8,
                local_b0,local_c0,local_d0,local_c8,local_d8,local_e0);
  if (_DAT_23eede910 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eede910 = (longlong *)0x0;
  }
  lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar15 + 0x28);
  plVar9 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar9 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar9 = local_68;
  plVar3[0xf] = 0;
  uVar12 = local_78._0_8_;
  uVar20 = local_78._8_8_;
  local_78 = (undefined1  [16])0x0;
  local_68 = (longlong *)0x0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((local_100 != (longlong *)0x0) &&
     (lVar15 = *local_100, *local_100 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(local_100[1] + 0x30))(local_100);
  }
  if ((local_e8 != (longlong *)0x0) &&
     (lVar15 = *local_e8, *local_e8 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(local_e8[1] + 0x30))(local_e8);
  }
  if ((local_f0 != (longlong *)0x0) &&
     (lVar15 = *local_f0, *local_f0 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(local_f0[1] + 0x30))(local_f0);
  }
  if ((local_f8 != (longlong *)0x0) &&
     (lVar15 = *local_f8, *local_f8 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(local_f8[1] + 0x30))(local_f8);
  }
  if ((local_108 != (longlong *)0x0) &&
     (lVar15 = *local_108, *local_108 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(local_108[1] + 0x30))(local_108);
  }
  if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
    (**(code **)(plVar19[1] + 0x30))(plVar19);
  }
  if ((local_110 != (longlong *)0x0) &&
     (lVar15 = *local_110, *local_110 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(local_110[1] + 0x30))(local_110);
  }
  if ((local_120 != (longlong *)0x0) &&
     (lVar15 = *local_120, *local_120 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(local_120[1] + 0x30))(local_120);
  }
  if ((local_118 != (longlong *)0x0) &&
     (lVar15 = *local_118, *local_118 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(local_118[1] + 0x30))(local_118);
  }
  if ((local_b8 != (longlong *)0x0) &&
     (lVar15 = *local_b8, *local_b8 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(local_b8[1] + 0x30))(local_b8);
  }
  if ((local_b0 != (longlong *)0x0) &&
     (lVar15 = *local_b0, *local_b0 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(local_b0[1] + 0x30))(local_b0);
  }
  if ((local_c0 != (longlong *)0x0) &&
     (lVar15 = *local_c0, *local_c0 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(local_c0[1] + 0x30))(local_c0);
  }
  if ((local_d0 != (longlong *)0x0) &&
     (lVar15 = *local_d0, *local_d0 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(local_d0[1] + 0x30))(local_d0);
  }
  if ((local_c8 != (longlong *)0x0) &&
     (lVar15 = *local_c8, *local_c8 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(local_c8[1] + 0x30))(local_c8);
  }
  if ((local_d8 != (longlong *)0x0) &&
     (lVar15 = *local_d8, *local_d8 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(local_d8[1] + 0x30))(local_d8);
  }
  if ((local_e0 != (longlong *)0x0) &&
     (lVar15 = *local_e0, *local_e0 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(local_e0[1] + 0x30))(local_e0);
  }
  *plVar1 = *plVar1 + -1;
  local_68 = plVar9;
  local_78._0_8_ = uVar12;
  local_78._8_8_ = uVar20;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,local_78._0_8_,local_78._8_8_,local_68);
  return (longlong *)0x0;
}
