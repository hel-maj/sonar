/* ===== 23e2b6010 ui.home_tab:54 ===== */
/* ghidra_name=FUN_23e2b6010 entry=23e2b6010 size=51868 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2b6010(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  code *pcVar3;
  undefined1 auVar4 [16];
  char cVar5;
  int iVar6;
  longlong *plVar7;
  longlong lVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 in_stack_fffffffffffffe08;
  undefined4 uVar20;
  longlong *plStack_140;
  longlong *plStack_138;
  longlong *plStack_130;
  longlong *plStack_128;
  longlong *plStack_120;
  longlong *plStack_118;
  longlong *plStack_110;
  longlong *plStack_108;
  longlong *plStack_100;
  longlong *plStack_f8;
  longlong *plStack_f0;
  longlong *plStack_e8;
  longlong *plStack_e0;
  longlong *plStack_d8;
  longlong *plStack_d0;
  longlong *plStack_c8;
  longlong *plStack_c0;
  longlong *plStack_b8;
  longlong *plStack_b0;
  undefined4 uStack_a8;
  longlong *plStack_88;
  undefined8 uStack_80;
  undefined1 auStack_78 [16];
  longlong *plStack_68;
  
  plVar17 = DAT_23ed6a4e0;
  uVar20 = (undefined4)((ulonglong)in_stack_fffffffffffffe08 >> 0x20);
  lVar8 = *param_3;
  if (DAT_23ed6a4e0 == (longlong *)0x0) {
    plVar17 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
  }
  else {
    plVar7 = (longlong *)*DAT_23ed6a4e0;
    *DAT_23ed6a4e0 = 1;
    DAT_23ed6a4e0 = plVar7;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
  }
  pcVar3 = _PyRuntime_exref;
  plVar7 = _DAT_23eeb0370;
  plVar17[2] = lVar8;
  lVar8 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar3 + 0x1f8) + 0x10) + 0x2e8);
  lVar1 = plVar17[-1];
  puVar2 = *(undefined8 **)(lVar8 + 8);
  *puVar2 = plVar17 + -2;
  plVar17[-2] = lVar8;
  plVar17[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
  *(longlong **)(lVar8 + 8) = plVar17 + -2;
  plStack_68 = (longlong *)0x0;
  auStack_78 = (undefined1  [16])0x0;
  if (plVar7 == (longlong *)0x0) {
LAB_23e2b60e1:
    plVar7 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeb0368,DAT_23eeb0380,0xc0);
    _DAT_23eeb0370 = plVar7;
  }
  else {
    lVar8 = *plVar7;
    if (1 < lVar8) {
      *plVar7 = lVar8 + -1;
      goto LAB_23e2b60e1;
    }
    if (plVar7[2] != 0) {
      *plVar7 = lVar8 + -1;
      if (lVar8 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23e2b60e1;
    }
  }
  lVar8 = *(longlong *)(param_1 + 0x38);
  lVar1 = *(longlong *)(lVar8 + 8);
  plVar7[0xf] = lVar1;
  *(longlong **)(lVar8 + 8) = plVar7 + 9;
  if ((lVar1 != 0) &&
     (((*(char *)(lVar1 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar1 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar1 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar1 + 0x38))
       ) && (plVar7[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar1 + 0x28);
    *(longlong **)(plVar7[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar7 = *plVar7 + 1;
  *(undefined4 *)(plVar7 + 8) = 0;
  lVar8 = FUN_23e8f7640();
  if (lVar8 == 0) {
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    FUN_23e915740(param_1,auStack_78,DAT_23eead958);
    uStack_a8 = 0x39;
    plStack_130 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_b8 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_140 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    goto LAB_23e2b9c20;
  }
  lVar1 = plVar17[2];
  *(undefined4 *)(plVar7 + 5) = 0x39;
  plVar9 = (longlong *)FUN_23e914090(param_1,lVar8,lVar1);
  lVar8 = _DAT_23eead968;
  uVar18 = _DAT_23eead960;
  if (plVar9 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar10 = (longlong *)0x0;
    uStack_a8 = 0x39;
    plStack_130 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_b8 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_140 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e2b9c20;
  }
  *(undefined4 *)(plVar7 + 5) = 0x3a;
  plVar10 = (longlong *)FUN_23e95a860(param_1,plVar9,uVar18,lVar8 + 0x18);
  if (plVar10 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_a8 = 0x3a;
    plStack_130 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_b8 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_140 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = (longlong *)0x0;
    goto LAB_23e2b9c20;
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  lVar8 = _DAT_23eead978;
  uVar18 = _DAT_23eead970;
  *(undefined4 *)(plVar7 + 5) = 0x3b;
  plVar10 = (longlong *)FUN_23e915840(param_1,plVar9,uVar18,*(undefined8 *)(lVar8 + 0x18));
  if (plVar10 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_a8 = 0x3b;
    plStack_130 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_b8 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_140 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = (longlong *)0x0;
    goto LAB_23e2b9c20;
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  lVar8 = *(longlong *)(DAT_23eeae258 + 0x20);
  if (*(char *)(lVar8 + 10) == '\0') {
    plVar10 = (longlong *)FUN_23a37a020(DAT_23eeae258,DAT_23eead980);
    if (plVar10 == (longlong *)0x0) goto LAB_23e2b9ae9;
    lVar8 = *plVar10;
LAB_23e2ba888:
    if (lVar8 == 0) goto LAB_23e2b9ae9;
  }
  else {
    iVar6 = *(int *)(lVar8 + 0xc);
    if (*(int *)(lVar8 + 0xc) == 0) {
      *(int *)(lVar8 + 0xc) = _DAT_23ec14e6c;
      iVar6 = _DAT_23ec14e6c;
      _DAT_23ec14e6c = _DAT_23ec14e6c + 1;
    }
    if (_DAT_23ec14e68 != iVar6) {
      _DAT_23ec14e68 = iVar6;
      _DAT_23eeb0348 = FUN_23e8cbd60(lVar8,DAT_23eead980,*(undefined8 *)(DAT_23eead980 + 0x18));
    }
    if (-1 < _DAT_23eeb0348) {
      lVar1 = lVar8 + 0x20 + (1L << (*(byte *)(lVar8 + 9) & 0x3f));
      if (*(longlong *)(lVar1 + 8 + _DAT_23eeb0348 * 0x10) != 0) goto LAB_23e2b627d;
      _DAT_23eeb0348 = FUN_23e8cbd60(lVar8,DAT_23eead980,*(undefined8 *)(DAT_23eead980 + 0x18));
      if (-1 < _DAT_23eeb0348) {
        lVar8 = *(longlong *)(lVar1 + 8 + _DAT_23eeb0348 * 0x10);
        goto LAB_23e2ba888;
      }
    }
LAB_23e2b9ae9:
    plVar10 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eead980);
    if ((plVar10 == (longlong *)0x0) || (*plVar10 == 0)) {
      plVar13 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      FUN_23e915740(param_1,auStack_78,DAT_23eead980);
      uStack_a8 = 0x3e;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plStack_b8 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_b0 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_c0 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      goto LAB_23e2b9c20;
    }
  }
LAB_23e2b627d:
  *(undefined4 *)(plVar7 + 5) = 0x3e;
  plVar10 = (longlong *)FUN_23e91a870(param_1);
  lVar8 = _DAT_23eead990;
  uVar18 = _DAT_23eead988;
  if (plVar10 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_a8 = 0x3e;
    plStack_130 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_b8 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_140 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e2b9c20;
  }
  *(undefined4 *)(plVar7 + 5) = 0x3f;
  plVar11 = (longlong *)FUN_23e915840(param_1,plVar10,uVar18,*(undefined8 *)(lVar8 + 0x18));
  if (plVar11 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    plStack_130 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_a8 = 0x3f;
    plStack_120 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_b8 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_140 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = (longlong *)0x0;
    goto LAB_23e2b9c20;
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  plVar12 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23eead998);
  if (plVar12 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_a8 = 0x40;
    plStack_130 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_b8 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_140 = (longlong *)0x0;
    goto LAB_23e2b9c20;
  }
  lVar8 = FUN_23e8f7770();
  if (lVar8 == 0) {
    FUN_23e915740(param_1,auStack_78,DAT_23eead9a0);
    lVar8 = *plVar12;
    *plVar12 = lVar8 + -1;
    plVar11 = (longlong *)0x0;
    if (lVar8 + -1 == 0) {
      plVar13 = (longlong *)0x0;
      (**(code **)(plVar12[1] + 0x30))(plVar12);
      uStack_a8 = 0x40;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plStack_b8 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_b0 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_c0 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
    }
    else {
      plStack_130 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      uStack_a8 = 0x40;
      plStack_120 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plStack_b8 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_b0 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_c0 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
    }
    goto LAB_23e2b9c20;
  }
  plVar11 = (longlong *)FUN_23e8bc2f0(lVar8,_DAT_23eead9a8);
  if (plVar11 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    lVar8 = *plVar12;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar12 = lVar8 + -1;
    plVar11 = (longlong *)0x0;
    if (lVar8 + -1 == 0) {
      plVar13 = (longlong *)0x0;
      (**(code **)(plVar12[1] + 0x30))();
      uStack_a8 = 0x40;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plStack_b8 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_b0 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_c0 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
    }
    else {
      plStack_130 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      uStack_a8 = 0x40;
      plStack_120 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plStack_b8 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_b0 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_c0 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
    }
    goto LAB_23e2b9c20;
  }
  plVar13 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23eead9b0);
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if (plVar13 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    lVar8 = *plVar12;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar12 = lVar8 + -1;
    plVar13 = (longlong *)0x0;
    if (lVar8 + -1 == 0) {
      plVar11 = (longlong *)0x0;
      (**(code **)(plVar12[1] + 0x30))(plVar12);
      uStack_a8 = 0x40;
      plStack_130 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plStack_b8 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_b0 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_c0 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
    }
    else {
      plStack_130 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      uStack_a8 = 0x40;
      plStack_120 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plStack_b8 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_b0 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plStack_c0 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
    }
    goto LAB_23e2b9c20;
  }
  *(undefined4 *)(plVar7 + 5) = 0x40;
  plVar11 = (longlong *)FUN_23e914090(param_1,plVar12,plVar13);
  lVar8 = *plVar12;
  *plVar12 = lVar8 + -1;
  if (lVar8 + -1 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if (plVar11 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    plStack_130 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_a8 = 0x40;
    plStack_120 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_b8 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_140 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = (longlong *)0x0;
    goto LAB_23e2b9c20;
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  lVar8 = _DAT_23eead9c0;
  uVar18 = _DAT_23eead9b8;
  *(undefined4 *)(plVar7 + 5) = 0x41;
  plVar11 = (longlong *)FUN_23e915840(param_1,plVar10,uVar18,*(undefined8 *)(lVar8 + 0x18));
  if (plVar11 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    plStack_130 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_a8 = 0x41;
    plStack_120 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_b8 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_140 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = (longlong *)0x0;
    goto LAB_23e2b9c20;
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  lVar8 = FUN_23e8f79f0();
  if (lVar8 == 0) {
    plVar13 = (longlong *)0x0;
    FUN_23e915740(param_1,auStack_78,DAT_23eead9c8);
    uStack_a8 = 0x43;
    plStack_130 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_b8 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_140 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    goto LAB_23e2b9c20;
  }
  *(undefined4 *)(plVar7 + 5) = 0x43;
  plVar11 = (longlong *)FUN_23e91a870(param_1,lVar8);
  if (plVar11 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    plStack_130 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_a8 = 0x43;
    plStack_120 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_b8 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_140 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e2b9c20;
  }
  lVar8 = FUN_23e8f7640();
  if (lVar8 == 0) {
    plVar13 = (longlong *)0x0;
    FUN_23e915740(param_1,auStack_78,DAT_23eead958);
    uStack_a8 = 0x44;
    plStack_130 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_b8 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_140 = (longlong *)0x0;
    goto LAB_23e2b9c20;
  }
  *(undefined4 *)(plVar7 + 5) = 0x44;
  plStack_140 = (longlong *)FUN_23e914090(param_1,lVar8,plVar11);
  lVar8 = _DAT_23eead978;
  uVar18 = _DAT_23eead970;
  if (plStack_140 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    plStack_130 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_a8 = 0x44;
    plStack_120 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_b8 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e2b9c20;
  }
  *(undefined4 *)(plVar7 + 5) = 0x45;
  plVar13 = (longlong *)FUN_23e915840(param_1,plStack_140,uVar18,*(undefined8 *)(lVar8 + 0x18));
  if (plVar13 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    plStack_130 = (longlong *)0x0;
    uStack_a8 = 0x45;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_120 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_b8 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar13 = (longlong *)0x0;
    goto LAB_23e2b9c20;
  }
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  lVar8 = _DAT_23eead9d0;
  *(undefined4 *)(plVar7 + 5) = 0x46;
  plVar13 = (longlong *)FUN_23e95a860(param_1,plStack_140,_DAT_23eead960,lVar8 + 0x18);
  if (plVar13 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    plStack_130 = (longlong *)0x0;
    uStack_a8 = 0x46;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_120 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_b8 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar13 = (longlong *)0x0;
    goto LAB_23e2b9c20;
  }
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  lVar1 = _DAT_23eead9e0;
  lVar8 = plVar17[2];
  *(undefined4 *)(plVar7 + 5) = 0x49;
  plVar13 = (longlong *)FUN_23e915840(param_1,lVar8,DAT_23eead9d8,*(undefined8 *)(lVar1 + 0x18));
  if (plVar13 == (longlong *)0x0) {
LAB_23e2bb580:
    uVar18 = *(undefined8 *)(param_1 + 0x60);
    uVar19 = *(undefined8 *)(param_1 + 0x68);
    plVar14 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  else {
    plVar12 = (longlong *)FUN_23a388310(plVar13);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if (plVar12 == (longlong *)0x0) goto LAB_23e2bb580;
    plVar13 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
    if ((plVar13 == (longlong *)0x0) &&
       (plVar13 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,0,2), plVar13 == (longlong *)0x0)) {
      plStack_c0 = (longlong *)0x0;
    }
    else {
      plStack_c0 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
      if (((plStack_c0 != (longlong *)0x0) ||
          (plStack_c0 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,1,2),
          plStack_c0 != (longlong *)0x0)) &&
         (cVar5 = FUN_23a3884a0(param_1,auStack_78,plVar12,2), cVar5 != '\0')) {
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        if (*plStack_c0 == 0) {
          (**(code **)(plStack_c0[1] + 0x30))();
        }
        lVar8 = FUN_23e8f6e60();
        if (lVar8 == 0) {
          FUN_23e915740(param_1,auStack_78,DAT_23eead9e8);
          uStack_a8 = 0x4b;
          plStack_130 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plStack_b8 = (longlong *)0x0;
          plStack_d0 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_b0 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
          goto LAB_23e2b9c20;
        }
        *(undefined4 *)(plVar7 + 5) = 0x4b;
        plVar12 = (longlong *)FUN_23e91a870(param_1,lVar8);
        if (plVar12 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          plStack_130 = (longlong *)0x0;
          uStack_a8 = 0x4b;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plStack_120 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plStack_b8 = (longlong *)0x0;
          plStack_d0 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_b0 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plStack_138 = (longlong *)0x0;
          goto LAB_23e2b9c20;
        }
        cVar5 = FUN_23e8d9ac0(plVar17[2],_DAT_23eead9f0,plVar12);
        lVar8 = *plVar12;
        *plVar12 = lVar8 + -1;
        if (lVar8 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if (cVar5 == '\0') {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          plStack_130 = (longlong *)0x0;
          uStack_a8 = 0x4b;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plStack_120 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plStack_b8 = (longlong *)0x0;
          plStack_d0 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_b0 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e2b9c20;
        }
        plVar12 = (longlong *)FUN_23e8bc2f0(plVar17[2],_DAT_23eead9f0);
        uVar18 = _DAT_23eead9f8;
        if (plVar12 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          plStack_130 = (longlong *)0x0;
          uStack_a8 = 0x4c;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plStack_120 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plStack_b8 = (longlong *)0x0;
          plStack_d0 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_b0 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plStack_138 = (longlong *)0x0;
          goto LAB_23e2b9c20;
        }
        *(undefined4 *)(plVar7 + 5) = 0x4c;
        plVar14 = (longlong *)FUN_23e915840(param_1,plVar12,uVar18);
        lVar8 = *plVar12;
        *plVar12 = lVar8 + -1;
        if (lVar8 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if (plVar14 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          plStack_130 = (longlong *)0x0;
          uStack_a8 = 0x4c;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plStack_120 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plStack_b8 = (longlong *)0x0;
          plStack_d0 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_b0 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plStack_100 = (longlong *)0x0;
          goto LAB_23e2b9c20;
        }
        lVar8 = *plVar14;
        *plVar14 = lVar8 + -1;
        if (lVar8 + -1 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        plVar12 = (longlong *)FUN_23e8bc2f0(plVar17[2],_DAT_23eead9f0);
        if (plVar12 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          plStack_130 = (longlong *)0x0;
          uStack_a8 = 0x4d;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plStack_120 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plStack_b8 = (longlong *)0x0;
          plStack_d0 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_b0 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plStack_138 = (longlong *)0x0;
          goto LAB_23e2b9c20;
        }
        plVar14 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23eeada00);
        lVar8 = *plVar12;
        *plVar12 = lVar8 + -1;
        if (lVar8 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if (plVar14 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          plStack_130 = (longlong *)0x0;
          uStack_a8 = 0x4d;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plStack_120 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plStack_b8 = (longlong *)0x0;
          plStack_d0 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_b0 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plStack_100 = (longlong *)0x0;
          goto LAB_23e2b9c20;
        }
        lVar8 = FUN_23e8f6bc0();
        if (lVar8 == 0) {
          FUN_23e915740(param_1,auStack_78);
          lVar8 = *plVar14;
          *plVar14 = lVar8 + -1;
          plStack_138 = (longlong *)0x0;
          if (lVar8 + -1 == 0) {
            FUN_23a334bc0(plVar14);
            uStack_a8 = 0x4d;
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_e8 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_d0 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_b0 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
          }
          else {
            uStack_a8 = 0x4d;
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_e8 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_d0 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_b0 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
          }
          goto LAB_23e2b9c20;
        }
        plVar12 = (longlong *)FUN_23e8bc2f0(lVar8);
        if (plVar12 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          lVar8 = *plVar14;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar14 = lVar8 + -1;
          plStack_138 = (longlong *)0x0;
          if (lVar8 + -1 == 0) {
            FUN_23a334bc0();
            uStack_a8 = 0x4d;
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_e8 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_d0 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_b0 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
          }
          else {
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_e8 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_d0 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_b0 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
            uStack_a8 = 0x4d;
          }
          goto LAB_23e2b9c20;
        }
        plVar15 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23eeada18);
        lVar8 = *plVar12;
        *plVar12 = lVar8 + -1;
        if (lVar8 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if (plVar15 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          lVar8 = *plVar14;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar14 = lVar8 + -1;
          plStack_b0 = (longlong *)0x0;
          if (lVar8 + -1 == 0) {
            FUN_23a334bc0(plVar14);
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_e8 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_d0 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
            plStack_138 = (longlong *)0x0;
            uStack_a8 = 0x4d;
          }
          else {
            uStack_a8 = 0x4d;
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_e8 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_d0 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
            plStack_138 = (longlong *)0x0;
          }
          goto LAB_23e2b9c20;
        }
        *(undefined4 *)(plVar7 + 5) = 0x4d;
        plVar12 = (longlong *)FUN_23e914090(param_1,plVar14,plVar15);
        lVar8 = *plVar14;
        *plVar14 = lVar8 + -1;
        if (lVar8 + -1 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        lVar8 = *plVar15;
        *plVar15 = lVar8 + -1;
        if (lVar8 + -1 == 0) {
          (**(code **)(plVar15[1] + 0x30))();
        }
        if (plVar12 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          uStack_a8 = 0x4d;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plStack_130 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plStack_b8 = (longlong *)0x0;
          plStack_d0 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_b0 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plStack_138 = (longlong *)0x0;
          goto LAB_23e2b9c20;
        }
        lVar8 = *plVar12;
        *plVar12 = lVar8 + -1;
        if (lVar8 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        plVar12 = (longlong *)FUN_23e8bc2f0(plVar17[2],_DAT_23eead9f0);
        if (plVar12 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          uStack_a8 = 0x4e;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plStack_130 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plStack_b8 = (longlong *)0x0;
          plStack_d0 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_b0 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plStack_100 = (longlong *)0x0;
          goto LAB_23e2b9c20;
        }
        *(undefined4 *)(plVar7 + 5) = 0x4e;
        plVar14 = (longlong *)FUN_23e915840(param_1,plVar12);
        lVar8 = *plVar12;
        *plVar12 = lVar8 + -1;
        if (lVar8 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if (plVar14 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          uStack_a8 = 0x4e;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plStack_130 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plStack_b8 = (longlong *)0x0;
          plStack_d0 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_b0 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plStack_138 = (longlong *)0x0;
          goto LAB_23e2b9c20;
        }
        lVar8 = *plVar14;
        *plVar14 = lVar8 + -1;
        if (lVar8 + -1 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        plVar12 = (longlong *)FUN_23e8bc2f0(plVar17[2],_DAT_23eead9f0);
        if (plVar12 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          uStack_a8 = 0x4f;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plStack_130 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plStack_b8 = (longlong *)0x0;
          plStack_d0 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_b0 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plStack_138 = (longlong *)0x0;
          goto LAB_23e2b9c20;
        }
        plVar14 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23eeada28);
        lVar8 = *plVar12;
        *plVar12 = lVar8 + -1;
        if (lVar8 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if (plVar14 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          uStack_a8 = 0x4f;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plStack_130 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plStack_b8 = (longlong *)0x0;
          plStack_d0 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          plStack_b0 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plStack_f8 = (longlong *)0x0;
          goto LAB_23e2b9c20;
        }
        lVar8 = FUN_23e8f6bc0();
        if (lVar8 == 0) {
          FUN_23e915740(param_1,auStack_78,DAT_23eeada08);
          lVar8 = *plVar14;
          *plVar14 = lVar8 + -1;
          plStack_138 = (longlong *)0x0;
          if (lVar8 + -1 == 0) {
            FUN_23a334bc0(plVar14);
            uStack_a8 = 0x4f;
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_e8 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_d0 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_b0 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
          }
          else {
            uStack_a8 = 0x4f;
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_e8 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_d0 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_b0 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
          }
          goto LAB_23e2b9c20;
        }
        plVar12 = (longlong *)FUN_23e8bc2f0(lVar8,_DAT_23eeada30);
        if (plVar12 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          lVar8 = *plVar14;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar14 = lVar8 + -1;
          plStack_138 = (longlong *)0x0;
          if (lVar8 + -1 == 0) {
            FUN_23a334bc0();
            uStack_a8 = 0x4f;
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_e8 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_d0 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_b0 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
          }
          else {
            uStack_a8 = 0x4f;
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_e8 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_d0 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_b0 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
          }
          goto LAB_23e2b9c20;
        }
        plVar15 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23eeada38);
        lVar8 = *plVar12;
        *plVar12 = lVar8 + -1;
        if (lVar8 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))();
        }
        if (plVar15 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          lVar8 = *plVar14;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar14 = lVar8 + -1;
          plStack_100 = (longlong *)0x0;
          if (lVar8 + -1 == 0) {
            FUN_23a334bc0(plVar14);
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_e8 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_d0 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_b0 = (longlong *)0x0;
            plStack_138 = (longlong *)0x0;
            uStack_a8 = 0x4f;
          }
          else {
            uStack_a8 = 0x4f;
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_e8 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_d0 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_b0 = (longlong *)0x0;
            plStack_138 = (longlong *)0x0;
          }
          goto LAB_23e2b9c20;
        }
        lVar8 = FUN_23e8f6bc0();
        if (lVar8 == 0) {
          FUN_23e915740(param_1,auStack_78,DAT_23eeada08);
          lVar8 = *plVar14;
          *plVar14 = lVar8 + -1;
          if (lVar8 + -1 == 0) {
            FUN_23a334bc0();
          }
          lVar8 = *plVar15;
          *plVar15 = lVar8 + -1;
          plStack_138 = (longlong *)0x0;
          if (lVar8 + -1 == 0) {
            FUN_23a334bc0(plVar15);
            uStack_a8 = 0x4f;
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_e8 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_d0 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_b0 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
          }
          else {
            uStack_a8 = 0x4f;
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_e8 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_d0 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_b0 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
          }
          goto LAB_23e2b9c20;
        }
        plVar12 = (longlong *)FUN_23e8bc2f0(lVar8,_DAT_23eeada30);
        if (plVar12 == (longlong *)0x0) {
          plStack_68 = *(longlong **)(param_1 + 0x70);
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          *(undefined8 *)(param_1 + 0x70) = 0;
          lVar8 = *plVar14;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar14 = lVar8 + -1;
          if (lVar8 + -1 == 0) {
            FUN_23a334bc0(plVar14);
          }
          lVar8 = *plVar15;
          *plVar15 = lVar8 + -1;
          plStack_138 = (longlong *)0x0;
          if (lVar8 + -1 == 0) {
            FUN_23a334bc0(plVar15);
            uStack_a8 = 0x4f;
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_e8 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_d0 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_b0 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
          }
          else {
            uStack_a8 = 0x4f;
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_e8 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_d0 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_b0 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
          }
          goto LAB_23e2b9c20;
        }
        plVar16 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23eeada40);
        lVar8 = *plVar12;
        *plVar12 = lVar8 + -1;
        if (lVar8 + -1 == 0) {
          FUN_23a334bc0(plVar12);
        }
        if (plVar16 == (longlong *)0x0) {
          plStack_68 = *(longlong **)(param_1 + 0x70);
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          *(undefined8 *)(param_1 + 0x70) = 0;
          lVar8 = *plVar14;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar14 = lVar8 + -1;
          if (lVar8 + -1 == 0) {
            FUN_23a334bc0();
          }
          lVar8 = *plVar15;
          *plVar15 = lVar8 + -1;
          plStack_b0 = (longlong *)0x0;
          if (lVar8 + -1 == 0) {
            FUN_23a334bc0(plVar15);
            uStack_a8 = 0x4f;
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_e8 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_d0 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
            plStack_138 = (longlong *)0x0;
          }
          else {
            uStack_a8 = 0x4f;
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_e8 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_d0 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
            plStack_138 = (longlong *)0x0;
          }
          goto LAB_23e2b9c20;
        }
        plVar12 = (longlong *)FUN_23e8c1360(plVar15,plVar16);
        lVar8 = *plVar15;
        *plVar15 = lVar8 + -1;
        if (lVar8 + -1 == 0) {
          FUN_23a334bc0(plVar15);
        }
        lVar8 = *plVar16;
        *plVar16 = lVar8 + -1;
        if (lVar8 + -1 == 0) {
          FUN_23a334bc0(plVar16);
        }
        if (plVar12 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          lVar8 = *plVar14;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar14 = lVar8 + -1;
          plStack_138 = (longlong *)0x0;
          if (lVar8 + -1 == 0) {
            FUN_23a334bc0();
            uStack_a8 = 0x4f;
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_e8 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_d0 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_b0 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
          }
          else {
            uStack_a8 = 0x4f;
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_e8 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_d0 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_b0 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
          }
          goto LAB_23e2b9c20;
        }
        *(undefined4 *)(plVar7 + 5) = 0x4f;
        plVar15 = (longlong *)FUN_23e914090(param_1,plVar14,plVar12);
        lVar8 = *plVar14;
        *plVar14 = lVar8 + -1;
        if (lVar8 + -1 == 0) {
          FUN_23a334bc0(plVar14);
        }
        lVar8 = *plVar12;
        *plVar12 = lVar8 + -1;
        if (lVar8 + -1 == 0) {
          FUN_23a334bc0(plVar12);
        }
        if (plVar15 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          plStack_130 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plStack_b8 = (longlong *)0x0;
          plStack_d0 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_b0 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
          uStack_a8 = 0x4f;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plStack_100 = (longlong *)0x0;
          goto LAB_23e2b9c20;
        }
        lVar8 = *plVar15;
        *plVar15 = lVar8 + -1;
        if (lVar8 + -1 == 0) {
          FUN_23a334bc0();
        }
        plVar12 = (longlong *)FUN_23e8bc2f0(plVar17[2],_DAT_23eead9f0);
        if (plVar12 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          uStack_a8 = 0x50;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plStack_130 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plStack_b8 = (longlong *)0x0;
          plStack_d0 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_b0 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plStack_138 = (longlong *)0x0;
          goto LAB_23e2b9c20;
        }
        plVar14 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23eead9b8);
        lVar8 = *plVar12;
        *plVar12 = lVar8 + -1;
        if (lVar8 + -1 == 0) {
          FUN_23a334bc0(plVar12);
        }
        plVar12 = _DAT_23eeada48;
        if (plVar14 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          uStack_a8 = 0x50;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plStack_130 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plStack_b8 = (longlong *)0x0;
          plStack_d0 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plStack_b0 = (longlong *)0x0;
          goto LAB_23e2b9c20;
        }
        plVar15 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
        *plVar12 = *plVar12 + 1;
        plVar15[3] = (longlong)plVar12;
        lVar8 = FUN_23e8f74f0();
        if (lVar8 == 0) {
          FUN_23e915740(param_1,auStack_78,DAT_23eeada50);
        }
        else {
          lVar8 = FUN_23e94f9d0(param_1,lVar8,DAT_23ed6cd28);
          if (lVar8 != 0) {
            plVar15[4] = lVar8;
            plVar12 = _DAT_23eeada58;
            *_DAT_23eeada58 = *_DAT_23eeada58 + 1;
            plVar15[5] = (longlong)plVar12;
            plVar12 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar15);
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              FUN_23a334bc0(plVar15);
            }
            if (plVar12 == (longlong *)0x0) {
              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_68 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              lVar8 = *plVar14;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar14 = lVar8 + -1;
              plStack_138 = (longlong *)0x0;
              if (lVar8 + -1 == 0) {
                FUN_23a334bc0();
                uStack_a8 = 0x50;
                plStack_130 = (longlong *)0x0;
                plStack_120 = (longlong *)0x0;
                plStack_128 = (longlong *)0x0;
                plStack_110 = (longlong *)0x0;
                plStack_e8 = (longlong *)0x0;
                plStack_f0 = (longlong *)0x0;
                plStack_108 = (longlong *)0x0;
                plStack_118 = (longlong *)0x0;
                plStack_e0 = (longlong *)0x0;
                plStack_c8 = (longlong *)0x0;
                plStack_b8 = (longlong *)0x0;
                plStack_d0 = (longlong *)0x0;
                plStack_d8 = (longlong *)0x0;
                plStack_f8 = (longlong *)0x0;
                plStack_b0 = (longlong *)0x0;
                plStack_100 = (longlong *)0x0;
              }
              else {
                uStack_a8 = 0x50;
                plStack_130 = (longlong *)0x0;
                plStack_120 = (longlong *)0x0;
                plStack_128 = (longlong *)0x0;
                plStack_110 = (longlong *)0x0;
                plStack_e8 = (longlong *)0x0;
                plStack_f0 = (longlong *)0x0;
                plStack_108 = (longlong *)0x0;
                plStack_118 = (longlong *)0x0;
                plStack_e0 = (longlong *)0x0;
                plStack_c8 = (longlong *)0x0;
                plStack_b8 = (longlong *)0x0;
                plStack_d0 = (longlong *)0x0;
                plStack_d8 = (longlong *)0x0;
                plStack_f8 = (longlong *)0x0;
                plStack_b0 = (longlong *)0x0;
                plStack_100 = (longlong *)0x0;
              }
              goto LAB_23e2b9c20;
            }
            *(undefined4 *)(plVar7 + 5) = 0x50;
            plVar15 = (longlong *)FUN_23e914090(param_1,plVar14);
            lVar8 = *plVar14;
            *plVar14 = lVar8 + -1;
            if (lVar8 + -1 == 0) {
              FUN_23a334bc0(plVar14);
            }
            lVar8 = *plVar12;
            *plVar12 = lVar8 + -1;
            if (lVar8 + -1 == 0) {
              FUN_23a334bc0(plVar12);
            }
            if (plVar15 == (longlong *)0x0) {
              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_68 = *(longlong **)(param_1 + 0x70);
              uStack_a8 = 0x50;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plStack_130 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              plStack_128 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plStack_e8 = (longlong *)0x0;
              plStack_f0 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_e0 = (longlong *)0x0;
              plStack_c8 = (longlong *)0x0;
              plStack_b8 = (longlong *)0x0;
              plStack_d0 = (longlong *)0x0;
              plStack_d8 = (longlong *)0x0;
              plStack_f8 = (longlong *)0x0;
              plStack_b0 = (longlong *)0x0;
              plStack_138 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plStack_100 = (longlong *)0x0;
              goto LAB_23e2b9c20;
            }
            lVar8 = *plVar15;
            *plVar15 = lVar8 + -1;
            if (lVar8 + -1 == 0) {
              FUN_23a334bc0();
            }
            plVar12 = (longlong *)FUN_23e8bc2f0(plVar17[2],_DAT_23eead9f0);
            lVar8 = _DAT_23eeada68;
            if (plVar12 == (longlong *)0x0) {
              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_68 = *(longlong **)(param_1 + 0x70);
              uStack_a8 = 0x58;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plStack_130 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              plStack_128 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plStack_e8 = (longlong *)0x0;
              plStack_f0 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_e0 = (longlong *)0x0;
              plStack_c8 = (longlong *)0x0;
              plStack_b8 = (longlong *)0x0;
              plStack_d0 = (longlong *)0x0;
              plStack_d8 = (longlong *)0x0;
              plStack_f8 = (longlong *)0x0;
              plStack_b0 = (longlong *)0x0;
              plStack_138 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plStack_100 = (longlong *)0x0;
              goto LAB_23e2b9c20;
            }
            *(undefined4 *)(plVar7 + 5) = 0x58;
            plVar14 = (longlong *)
                      FUN_23e915840(param_1,plVar12,_DAT_23eeada60,*(undefined8 *)(lVar8 + 0x18));
            lVar8 = *plVar12;
            *plVar12 = lVar8 + -1;
            if (lVar8 + -1 == 0) {
              FUN_23a334bc0();
            }
            if (plVar14 == (longlong *)0x0) {
              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_68 = *(longlong **)(param_1 + 0x70);
              uStack_a8 = 0x58;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plStack_130 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              plStack_128 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plStack_e8 = (longlong *)0x0;
              plStack_f0 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_e0 = (longlong *)0x0;
              plStack_c8 = (longlong *)0x0;
              plStack_b8 = (longlong *)0x0;
              plStack_d0 = (longlong *)0x0;
              plStack_d8 = (longlong *)0x0;
              plStack_f8 = (longlong *)0x0;
              plStack_b0 = (longlong *)0x0;
              plStack_100 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plStack_138 = (longlong *)0x0;
              goto LAB_23e2b9c20;
            }
            lVar8 = *plVar14;
            *plVar14 = lVar8 + -1;
            if (lVar8 + -1 == 0) {
              FUN_23a334bc0(plVar14);
            }
            plVar12 = (longlong *)FUN_23e8bc2f0(plStack_c0);
            if (plVar12 == (longlong *)0x0) {
              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_68 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              plStack_130 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              plStack_128 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plStack_e8 = (longlong *)0x0;
              plStack_f0 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_e0 = (longlong *)0x0;
              plStack_c8 = (longlong *)0x0;
              plStack_b8 = (longlong *)0x0;
              plStack_d0 = (longlong *)0x0;
              plStack_d8 = (longlong *)0x0;
              plStack_f8 = (longlong *)0x0;
              plStack_b0 = (longlong *)0x0;
              plStack_138 = (longlong *)0x0;
              uStack_a8 = 0x59;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plStack_100 = (longlong *)0x0;
              goto LAB_23e2b9c20;
            }
            plVar14 = (longlong *)FUN_23e8bc2f0(plVar17[2],_DAT_23eead9f0);
            if (plVar14 == (longlong *)0x0) {
              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_68 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              lVar8 = *plVar12;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar12 = lVar8 + -1;
              plStack_138 = (longlong *)0x0;
              if (lVar8 + -1 == 0) {
                FUN_23a334bc0();
                uStack_a8 = 0x59;
                plStack_130 = (longlong *)0x0;
                plStack_120 = (longlong *)0x0;
                plStack_128 = (longlong *)0x0;
                plStack_110 = (longlong *)0x0;
                plStack_e8 = (longlong *)0x0;
                plStack_f0 = (longlong *)0x0;
                plStack_108 = (longlong *)0x0;
                plStack_118 = (longlong *)0x0;
                plStack_e0 = (longlong *)0x0;
                plStack_c8 = (longlong *)0x0;
                plStack_b8 = (longlong *)0x0;
                plStack_d0 = (longlong *)0x0;
                plStack_d8 = (longlong *)0x0;
                plStack_f8 = (longlong *)0x0;
                plStack_b0 = (longlong *)0x0;
                plStack_100 = (longlong *)0x0;
              }
              else {
                uStack_a8 = 0x59;
                plStack_130 = (longlong *)0x0;
                plStack_120 = (longlong *)0x0;
                plStack_128 = (longlong *)0x0;
                plStack_110 = (longlong *)0x0;
                plStack_e8 = (longlong *)0x0;
                plStack_f0 = (longlong *)0x0;
                plStack_108 = (longlong *)0x0;
                plStack_118 = (longlong *)0x0;
                plStack_e0 = (longlong *)0x0;
                plStack_c8 = (longlong *)0x0;
                plStack_b8 = (longlong *)0x0;
                plStack_d0 = (longlong *)0x0;
                plStack_d8 = (longlong *)0x0;
                plStack_f8 = (longlong *)0x0;
                plStack_b0 = (longlong *)0x0;
                plStack_100 = (longlong *)0x0;
              }
              goto LAB_23e2b9c20;
            }
            *(undefined4 *)(plVar7 + 5) = 0x59;
            plVar15 = (longlong *)FUN_23e914090(param_1,plVar12,plVar14);
            lVar8 = *plVar12;
            *plVar12 = lVar8 + -1;
            if (lVar8 + -1 == 0) {
              FUN_23a334bc0(plVar12);
            }
            lVar8 = *plVar14;
            *plVar14 = lVar8 + -1;
            if (lVar8 + -1 == 0) {
              FUN_23a334bc0(plVar14);
            }
            if (plVar15 == (longlong *)0x0) {
              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_68 = *(longlong **)(param_1 + 0x70);
              uStack_a8 = 0x59;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plStack_130 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              plStack_128 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plStack_e8 = (longlong *)0x0;
              plStack_f0 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_e0 = (longlong *)0x0;
              plStack_c8 = (longlong *)0x0;
              plStack_b8 = (longlong *)0x0;
              plStack_d0 = (longlong *)0x0;
              plStack_d8 = (longlong *)0x0;
              plStack_f8 = (longlong *)0x0;
              plStack_100 = (longlong *)0x0;
              plStack_138 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plStack_b0 = (longlong *)0x0;
              goto LAB_23e2b9c20;
            }
            lVar8 = *plVar15;
            *plVar15 = lVar8 + -1;
            if (lVar8 + -1 == 0) {
              FUN_23a334bc0();
            }
            *(undefined4 *)(plVar7 + 5) = 0x5b;
            plVar12 = (longlong *)FUN_23e915840(param_1,plStack_140,_DAT_23eeada70,plVar13);
            if (plVar12 == (longlong *)0x0) {
              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_68 = *(longlong **)(param_1 + 0x70);
              uStack_a8 = 0x5b;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plStack_130 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              plStack_128 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plStack_e8 = (longlong *)0x0;
              plStack_f0 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_e0 = (longlong *)0x0;
              plStack_c8 = (longlong *)0x0;
              plStack_b8 = (longlong *)0x0;
              plStack_d0 = (longlong *)0x0;
              plStack_d8 = (longlong *)0x0;
              plStack_f8 = (longlong *)0x0;
              plStack_b0 = (longlong *)0x0;
              plStack_100 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plStack_138 = (longlong *)0x0;
              goto LAB_23e2b9c20;
            }
            lVar8 = *plVar12;
            *plVar12 = lVar8 + -1;
            if (lVar8 + -1 == 0) {
              FUN_23a334bc0(plVar12);
            }
            lVar1 = _DAT_23eeada78;
            lVar8 = plVar17[2];
            *(undefined4 *)(plVar7 + 5) = 0x5e;
            plVar12 = (longlong *)
                      FUN_23e915840(param_1,lVar8,DAT_23eead9d8,*(undefined8 *)(lVar1 + 0x18));
            if (plVar12 == (longlong *)0x0) {
LAB_23e2bdbe0:
              plVar12 = *(longlong **)(param_1 + 0x70);
              uVar18 = *(undefined8 *)(param_1 + 0x60);
              uVar19 = *(undefined8 *)(param_1 + 0x68);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            else {
              plVar14 = (longlong *)FUN_23a388310(plVar12);
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                FUN_23a334bc0();
              }
              if (plVar14 == (longlong *)0x0) goto LAB_23e2bdbe0;
              uVar18 = CONCAT44(uVar20,2);
              plStack_138 = (longlong *)FUN_23a3c1d30(param_1,auStack_78,plVar14,0,uVar18);
              if (plStack_138 == (longlong *)0x0) {
                *plVar14 = *plVar14 + -1;
                plStack_100 = (longlong *)0x0;
                plVar12 = plStack_68;
                uVar18 = auStack_78._0_8_;
                uVar19 = auStack_78._8_8_;
                if (*plVar14 == 0) {
LAB_23e2be42b:
                  plStack_68 = (longlong *)0x0;
                  auStack_78 = (undefined1  [16])0x0;
                  FUN_23a334bc0(plVar14);
                  plStack_68 = (longlong *)0x0;
                  auStack_78 = (undefined1  [16])0x0;
                  if (plStack_138 != (longlong *)0x0) goto LAB_23e2be464;
                  goto LAB_23e2be495;
                }
              }
              else {
                uVar18 = CONCAT44((int)((ulonglong)uVar18 >> 0x20),2);
                plStack_100 = (longlong *)FUN_23a3c1d30(param_1,auStack_78,plVar14,1,uVar18);
                uVar20 = (undefined4)((ulonglong)uVar18 >> 0x20);
                if ((plStack_100 != (longlong *)0x0) &&
                   (cVar5 = FUN_23a3884a0(param_1,auStack_78,plVar14), cVar5 != '\0')) {
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    FUN_23a334bc0(plVar14);
                  }
                  if (*plStack_138 == 0) {
                    FUN_23a334bc0(plStack_138);
                  }
                  if (*plStack_100 == 0) {
                    FUN_23a334bc0(plStack_100);
                  }
                  lVar8 = FUN_23e8f6fb0();
                  if (lVar8 == 0) {
                    FUN_23e915740(param_1,auStack_78,DAT_23eeada80);
                    uStack_a8 = 0x60;
                    plStack_130 = (longlong *)0x0;
                    plStack_120 = (longlong *)0x0;
                    plStack_128 = (longlong *)0x0;
                    plStack_110 = (longlong *)0x0;
                    plStack_e8 = (longlong *)0x0;
                    plStack_f0 = (longlong *)0x0;
                    plStack_108 = (longlong *)0x0;
                    plStack_118 = (longlong *)0x0;
                    plStack_e0 = (longlong *)0x0;
                    plStack_c8 = (longlong *)0x0;
                    plStack_b8 = (longlong *)0x0;
                    plStack_d0 = (longlong *)0x0;
                    plStack_d8 = (longlong *)0x0;
                    plStack_f8 = (longlong *)0x0;
                    plStack_b0 = (longlong *)0x0;
                    goto LAB_23e2b9c20;
                  }
                  *(undefined4 *)(plVar7 + 5) = 0x60;
                  plStack_b0 = (longlong *)FUN_23e91a870(param_1,lVar8);
                  lVar8 = _DAT_23eeada88;
                  if (plStack_b0 == (longlong *)0x0) {
                    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_68 = *(longlong **)(param_1 + 0x70);
                    uStack_a8 = 0x60;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plStack_130 = (longlong *)0x0;
                    plStack_120 = (longlong *)0x0;
                    plStack_128 = (longlong *)0x0;
                    plStack_110 = (longlong *)0x0;
                    plStack_e8 = (longlong *)0x0;
                    plStack_f0 = (longlong *)0x0;
                    plStack_108 = (longlong *)0x0;
                    plStack_118 = (longlong *)0x0;
                    plStack_e0 = (longlong *)0x0;
                    plStack_c8 = (longlong *)0x0;
                    plStack_b8 = (longlong *)0x0;
                    plStack_d0 = (longlong *)0x0;
                    plStack_d8 = (longlong *)0x0;
                    plStack_f8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e2b9c20;
                  }
                  *(undefined4 *)(plVar7 + 5) = 0x61;
                  plVar12 = (longlong *)
                            FUN_23e915840(param_1,plStack_b0,_DAT_23eead970,
                                          *(undefined8 *)(lVar8 + 0x18));
                  if (plVar12 == (longlong *)0x0) {
                    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_68 = *(longlong **)(param_1 + 0x70);
                    uStack_a8 = 0x61;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plStack_130 = (longlong *)0x0;
                    plStack_120 = (longlong *)0x0;
                    plStack_128 = (longlong *)0x0;
                    plStack_110 = (longlong *)0x0;
                    plStack_e8 = (longlong *)0x0;
                    plStack_f0 = (longlong *)0x0;
                    plStack_108 = (longlong *)0x0;
                    plStack_118 = (longlong *)0x0;
                    plStack_e0 = (longlong *)0x0;
                    plStack_c8 = (longlong *)0x0;
                    plStack_b8 = (longlong *)0x0;
                    plStack_d0 = (longlong *)0x0;
                    plStack_d8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plStack_f8 = (longlong *)0x0;
                    goto LAB_23e2b9c20;
                  }
                  lVar8 = *plVar12;
                  *plVar12 = lVar8 + -1;
                  if (lVar8 + -1 == 0) {
                    FUN_23a334bc0(plVar12);
                  }
                  lVar8 = *(longlong *)(DAT_23eeae258 + 0x20);
                  if (*(char *)(lVar8 + 10) == '\0') {
                    plVar12 = (longlong *)FUN_23a37a020(DAT_23eeae258,DAT_23eeada90);
                    if (plVar12 == (longlong *)0x0) goto LAB_23e2be63e;
                    lVar8 = *plVar12;
LAB_23e2be635:
                    if (lVar8 == 0) goto LAB_23e2be63e;
                  }
                  else {
                    iVar6 = *(int *)(lVar8 + 0xc);
                    if (*(int *)(lVar8 + 0xc) == 0) {
                      *(int *)(lVar8 + 0xc) = _DAT_23ec14e6c;
                      iVar6 = _DAT_23ec14e6c;
                      _DAT_23ec14e6c = _DAT_23ec14e6c + 1;
                    }
                    if (_DAT_23ec14e70 != iVar6) {
                      _DAT_23ec14e70 = iVar6;
                      _DAT_23eeb0350 =
                           FUN_23e8cbd60(lVar8,DAT_23eeada90,*(undefined8 *)(DAT_23eeada90 + 0x18));
                    }
                    if (-1 < _DAT_23eeb0350) {
                      lVar1 = lVar8 + 0x20 + (1L << (*(byte *)(lVar8 + 9) & 0x3f));
                      if (*(longlong *)(lVar1 + 8 + _DAT_23eeb0350 * 0x10) != 0) goto LAB_23e2b716b;
                      _DAT_23eeb0350 =
                           FUN_23e8cbd60(lVar8,DAT_23eeada90,*(undefined8 *)(DAT_23eeada90 + 0x18));
                      if (-1 < _DAT_23eeb0350) {
                        lVar8 = *(longlong *)(lVar1 + 8 + _DAT_23eeb0350 * 0x10);
                        goto LAB_23e2be635;
                      }
                    }
LAB_23e2be63e:
                    plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeada90);
                    if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
                      FUN_23e915740(param_1,auStack_78,DAT_23eeada90);
                      uStack_a8 = 99;
                      plStack_130 = (longlong *)0x0;
                      plStack_120 = (longlong *)0x0;
                      plStack_128 = (longlong *)0x0;
                      plStack_110 = (longlong *)0x0;
                      plStack_e8 = (longlong *)0x0;
                      plStack_f0 = (longlong *)0x0;
                      plStack_108 = (longlong *)0x0;
                      plStack_118 = (longlong *)0x0;
                      plStack_e0 = (longlong *)0x0;
                      plStack_c8 = (longlong *)0x0;
                      plStack_b8 = (longlong *)0x0;
                      plStack_d0 = (longlong *)0x0;
                      plStack_d8 = (longlong *)0x0;
                      plStack_f8 = (longlong *)0x0;
                      goto LAB_23e2b9c20;
                    }
                  }
LAB_23e2b716b:
                  *(undefined4 *)(plVar7 + 5) = 99;
                  plVar12 = (longlong *)FUN_23e91a870(param_1);
                  if (plVar12 == (longlong *)0x0) {
                    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_68 = *(longlong **)(param_1 + 0x70);
                    uStack_a8 = 99;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plStack_130 = (longlong *)0x0;
                    plStack_120 = (longlong *)0x0;
                    plStack_128 = (longlong *)0x0;
                    plStack_110 = (longlong *)0x0;
                    plStack_e8 = (longlong *)0x0;
                    plStack_f0 = (longlong *)0x0;
                    plStack_108 = (longlong *)0x0;
                    plStack_118 = (longlong *)0x0;
                    plStack_e0 = (longlong *)0x0;
                    plStack_c8 = (longlong *)0x0;
                    plStack_b8 = (longlong *)0x0;
                    plStack_d0 = (longlong *)0x0;
                    plStack_d8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plStack_f8 = (longlong *)0x0;
                    goto LAB_23e2b9c20;
                  }
                  cVar5 = FUN_23e8d9ac0(plVar17[2],_DAT_23eeada98,plVar12);
                  lVar8 = *plVar12;
                  *plVar12 = lVar8 + -1;
                  if (lVar8 + -1 == 0) {
                    FUN_23a334bc0(plVar12);
                  }
                  if (cVar5 == '\0') {
                    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_68 = *(longlong **)(param_1 + 0x70);
                    uStack_a8 = 99;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plStack_130 = (longlong *)0x0;
                    plStack_120 = (longlong *)0x0;
                    plStack_128 = (longlong *)0x0;
                    plStack_110 = (longlong *)0x0;
                    plStack_e8 = (longlong *)0x0;
                    plStack_f0 = (longlong *)0x0;
                    plStack_108 = (longlong *)0x0;
                    plStack_118 = (longlong *)0x0;
                    plStack_e0 = (longlong *)0x0;
                    plStack_c8 = (longlong *)0x0;
                    plStack_b8 = (longlong *)0x0;
                    plStack_d0 = (longlong *)0x0;
                    plStack_d8 = (longlong *)0x0;
                    plStack_f8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e2b9c20;
                  }
                  plVar12 = (longlong *)FUN_23e8bc2f0(plVar17[2],_DAT_23eeada98);
                  if (plVar12 == (longlong *)0x0) {
                    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_68 = *(longlong **)(param_1 + 0x70);
                    uStack_a8 = 100;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plStack_130 = (longlong *)0x0;
                    plStack_120 = (longlong *)0x0;
                    plStack_128 = (longlong *)0x0;
                    plStack_110 = (longlong *)0x0;
                    plStack_e8 = (longlong *)0x0;
                    plStack_f0 = (longlong *)0x0;
                    plStack_108 = (longlong *)0x0;
                    plStack_118 = (longlong *)0x0;
                    plStack_e0 = (longlong *)0x0;
                    plStack_c8 = (longlong *)0x0;
                    plStack_b8 = (longlong *)0x0;
                    plStack_d0 = (longlong *)0x0;
                    plStack_f8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plStack_d8 = (longlong *)0x0;
                    goto LAB_23e2b9c20;
                  }
                  *(undefined4 *)(plVar7 + 5) = 100;
                  plVar14 = (longlong *)FUN_23e915840(param_1,plVar12,_DAT_23eeadaa0);
                  lVar8 = *plVar12;
                  *plVar12 = lVar8 + -1;
                  if (lVar8 + -1 == 0) {
                    FUN_23a334bc0(plVar12);
                  }
                  if (plVar14 == (longlong *)0x0) {
                    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_68 = *(longlong **)(param_1 + 0x70);
                    uStack_a8 = 100;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plStack_130 = (longlong *)0x0;
                    plStack_120 = (longlong *)0x0;
                    plStack_128 = (longlong *)0x0;
                    plStack_110 = (longlong *)0x0;
                    plStack_e8 = (longlong *)0x0;
                    plStack_f0 = (longlong *)0x0;
                    plStack_108 = (longlong *)0x0;
                    plStack_118 = (longlong *)0x0;
                    plStack_e0 = (longlong *)0x0;
                    plStack_c8 = (longlong *)0x0;
                    plStack_b8 = (longlong *)0x0;
                    plStack_d0 = (longlong *)0x0;
                    plStack_d8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plStack_f8 = (longlong *)0x0;
                    goto LAB_23e2b9c20;
                  }
                  lVar8 = *plVar14;
                  *plVar14 = lVar8 + -1;
                  if (lVar8 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  plVar12 = (longlong *)FUN_23e8bc2f0(plVar17[2],_DAT_23eeada98);
                  if (plVar12 == (longlong *)0x0) {
                    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_68 = *(longlong **)(param_1 + 0x70);
                    uStack_a8 = 0x65;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plStack_130 = (longlong *)0x0;
                    plStack_120 = (longlong *)0x0;
                    plStack_128 = (longlong *)0x0;
                    plStack_110 = (longlong *)0x0;
                    plStack_e8 = (longlong *)0x0;
                    plStack_f0 = (longlong *)0x0;
                    plStack_108 = (longlong *)0x0;
                    plStack_118 = (longlong *)0x0;
                    plStack_e0 = (longlong *)0x0;
                    plStack_c8 = (longlong *)0x0;
                    plStack_b8 = (longlong *)0x0;
                    plStack_d0 = (longlong *)0x0;
                    plStack_d8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plStack_f8 = (longlong *)0x0;
                    goto LAB_23e2b9c20;
                  }
                  plVar14 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23eead9b8);
                  lVar8 = *plVar12;
                  *plVar12 = lVar8 + -1;
                  if (lVar8 + -1 == 0) {
                    FUN_23a334bc0(plVar12);
                  }
                  plVar12 = _DAT_23eeadab0;
                  if (plVar14 == (longlong *)0x0) {
                    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_68 = *(longlong **)(param_1 + 0x70);
                    uStack_a8 = 0x65;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plStack_130 = (longlong *)0x0;
                    plStack_120 = (longlong *)0x0;
                    plStack_128 = (longlong *)0x0;
                    plStack_110 = (longlong *)0x0;
                    plStack_e8 = (longlong *)0x0;
                    plStack_f0 = (longlong *)0x0;
                    plStack_108 = (longlong *)0x0;
                    plStack_118 = (longlong *)0x0;
                    plStack_e0 = (longlong *)0x0;
                    plStack_c8 = (longlong *)0x0;
                    plStack_b8 = (longlong *)0x0;
                    plStack_d8 = (longlong *)0x0;
                    plStack_f8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plStack_d0 = (longlong *)0x0;
                    goto LAB_23e2b9c20;
                  }
                  plVar15 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),7);
                  *plVar12 = *plVar12 + 1;
                  plVar15[3] = (longlong)plVar12;
                  lVar8 = FUN_23e8f74f0();
                  if (lVar8 == 0) {
                    FUN_23e915740(param_1,auStack_78,DAT_23eeada50);
LAB_23e2c1342:
                    uStack_a8 = 0x67;
                  }
                  else {
                    lVar8 = FUN_23e94f9d0(param_1,lVar8,DAT_23ed6cd28);
                    if (lVar8 == 0) {
                      plStack_68 = *(longlong **)(param_1 + 0x70);
                      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e2c1342;
                    }
                    plVar15[4] = lVar8;
                    plVar12 = _DAT_23eeadab8;
                    *_DAT_23eeadab8 = *_DAT_23eeadab8 + 1;
                    plVar15[5] = (longlong)plVar12;
                    lVar8 = FUN_23e8f73a0();
                    if (lVar8 == 0) {
                      FUN_23e915740(param_1,auStack_78,DAT_23eeadac0);
LAB_23e2c12f7:
                      uStack_a8 = 0x68;
                    }
                    else {
                      lVar8 = FUN_23e94f9d0(param_1,lVar8,DAT_23ed6cd28);
                      if (lVar8 == 0) {
                        plStack_68 = *(longlong **)(param_1 + 0x70);
                        auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23e2c12f7;
                      }
                      plVar15[6] = lVar8;
                      plVar12 = _DAT_23eeadac8;
                      *_DAT_23eeadac8 = *_DAT_23eeadac8 + 1;
                      plVar15[7] = (longlong)plVar12;
                      lVar8 = FUN_23e8f7250();
                      if (lVar8 == 0) {
                        FUN_23e915740(param_1,auStack_78,DAT_23eeadad0);
                      }
                      else {
                        lVar8 = FUN_23e94f9d0(param_1,lVar8);
                        if (lVar8 != 0) {
                          plVar15[8] = lVar8;
                          plVar12 = _DAT_23eeadad8;
                          *_DAT_23eeadad8 = *_DAT_23eeadad8 + 1;
                          plVar15[9] = (longlong)plVar12;
                          plVar12 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar15);
                          *plVar15 = *plVar15 + -1;
                          if (*plVar15 == 0) {
                            FUN_23a334bc0(plVar15);
                          }
                          if (plVar12 == (longlong *)0x0) {
                            auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                            plStack_68 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            lVar8 = *plVar14;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *plVar14 = lVar8 + -1;
                            plStack_f8 = (longlong *)0x0;
                            if (lVar8 + -1 == 0) {
                              FUN_23a334bc0(plVar14);
                              uStack_a8 = 0x65;
                              plStack_130 = (longlong *)0x0;
                              plStack_120 = (longlong *)0x0;
                              plStack_128 = (longlong *)0x0;
                              plStack_110 = (longlong *)0x0;
                              plStack_e8 = (longlong *)0x0;
                              plStack_f0 = (longlong *)0x0;
                              plStack_108 = (longlong *)0x0;
                              plStack_118 = (longlong *)0x0;
                              plStack_e0 = (longlong *)0x0;
                              plStack_c8 = (longlong *)0x0;
                              plStack_b8 = (longlong *)0x0;
                              plStack_d0 = (longlong *)0x0;
                              plStack_d8 = (longlong *)0x0;
                            }
                            else {
                              uStack_a8 = 0x65;
                              plStack_130 = (longlong *)0x0;
                              plStack_120 = (longlong *)0x0;
                              plStack_128 = (longlong *)0x0;
                              plStack_110 = (longlong *)0x0;
                              plStack_e8 = (longlong *)0x0;
                              plStack_f0 = (longlong *)0x0;
                              plStack_108 = (longlong *)0x0;
                              plStack_118 = (longlong *)0x0;
                              plStack_e0 = (longlong *)0x0;
                              plStack_c8 = (longlong *)0x0;
                              plStack_b8 = (longlong *)0x0;
                              plStack_d0 = (longlong *)0x0;
                              plStack_d8 = (longlong *)0x0;
                            }
                            goto LAB_23e2b9c20;
                          }
                          *(undefined4 *)(plVar7 + 5) = 0x65;
                          plVar15 = (longlong *)FUN_23e914090(param_1,plVar14,plVar12);
                          lVar8 = *plVar14;
                          *plVar14 = lVar8 + -1;
                          if (lVar8 + -1 == 0) {
                            FUN_23a334bc0(plVar14);
                          }
                          lVar8 = *plVar12;
                          *plVar12 = lVar8 + -1;
                          if (lVar8 + -1 == 0) {
                            FUN_23a334bc0(plVar12);
                          }
                          if (plVar15 == (longlong *)0x0) {
                            auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                            plStack_68 = *(longlong **)(param_1 + 0x70);
                            uStack_a8 = 0x65;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            plStack_130 = (longlong *)0x0;
                            plStack_120 = (longlong *)0x0;
                            plStack_128 = (longlong *)0x0;
                            plStack_110 = (longlong *)0x0;
                            plStack_e8 = (longlong *)0x0;
                            plStack_f0 = (longlong *)0x0;
                            plStack_108 = (longlong *)0x0;
                            plStack_118 = (longlong *)0x0;
                            plStack_e0 = (longlong *)0x0;
                            plStack_c8 = (longlong *)0x0;
                            plStack_b8 = (longlong *)0x0;
                            plStack_d0 = (longlong *)0x0;
                            plStack_f8 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plStack_d8 = (longlong *)0x0;
                            goto LAB_23e2b9c20;
                          }
                          lVar8 = *plVar15;
                          *plVar15 = lVar8 + -1;
                          if (lVar8 + -1 == 0) {
                            FUN_23a334bc0();
                          }
                          plVar12 = (longlong *)FUN_23e8bc2f0(plStack_b0,_DAT_23eeada70);
                          if (plVar12 == (longlong *)0x0) {
                            auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                            plStack_68 = *(longlong **)(param_1 + 0x70);
                            uStack_a8 = 0x72;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            plStack_130 = (longlong *)0x0;
                            plStack_120 = (longlong *)0x0;
                            plStack_128 = (longlong *)0x0;
                            plStack_110 = (longlong *)0x0;
                            plStack_e8 = (longlong *)0x0;
                            plStack_f0 = (longlong *)0x0;
                            plStack_108 = (longlong *)0x0;
                            plStack_118 = (longlong *)0x0;
                            plStack_e0 = (longlong *)0x0;
                            plStack_c8 = (longlong *)0x0;
                            plStack_b8 = (longlong *)0x0;
                            plStack_d0 = (longlong *)0x0;
                            plStack_f8 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plStack_d8 = (longlong *)0x0;
                            goto LAB_23e2b9c20;
                          }
                          plVar14 = (longlong *)FUN_23e8bc2f0(plVar17[2],_DAT_23eeada98);
                          uVar18 = _DAT_23eeadae0;
                          if (plVar14 == (longlong *)0x0) {
                            auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                            plStack_68 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            lVar8 = *plVar12;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *plVar12 = lVar8 + -1;
                            plStack_f8 = (longlong *)0x0;
                            if (lVar8 + -1 == 0) {
                              FUN_23a334bc0(plVar12);
                              plStack_130 = (longlong *)0x0;
                              uStack_a8 = 0x72;
                              plStack_120 = (longlong *)0x0;
                              plStack_128 = (longlong *)0x0;
                              plStack_110 = (longlong *)0x0;
                              plStack_e8 = (longlong *)0x0;
                              plStack_f0 = (longlong *)0x0;
                              plStack_108 = (longlong *)0x0;
                              plStack_118 = (longlong *)0x0;
                              plStack_e0 = (longlong *)0x0;
                              plStack_c8 = (longlong *)0x0;
                              plStack_b8 = (longlong *)0x0;
                              plStack_d0 = (longlong *)0x0;
                              plStack_d8 = (longlong *)0x0;
                            }
                            else {
                              uStack_a8 = 0x72;
                              plStack_130 = (longlong *)0x0;
                              plStack_120 = (longlong *)0x0;
                              plStack_128 = (longlong *)0x0;
                              plStack_110 = (longlong *)0x0;
                              plStack_e8 = (longlong *)0x0;
                              plStack_f0 = (longlong *)0x0;
                              plStack_108 = (longlong *)0x0;
                              plStack_118 = (longlong *)0x0;
                              plStack_e0 = (longlong *)0x0;
                              plStack_c8 = (longlong *)0x0;
                              plStack_b8 = (longlong *)0x0;
                              plStack_d0 = (longlong *)0x0;
                              plStack_d8 = (longlong *)0x0;
                            }
                            goto LAB_23e2b9c20;
                          }
                          *(undefined4 *)(plVar7 + 5) = 0x72;
                          uStack_80 = uVar18;
                          plStack_88 = plVar14;
                          plVar15 = (longlong *)FUN_23e94ed00(param_1,plVar12,&plStack_88);
                          lVar8 = *plVar12;
                          *plVar12 = lVar8 + -1;
                          if (lVar8 + -1 == 0) {
                            FUN_23a334bc0(plVar12);
                          }
                          lVar8 = *plVar14;
                          *plVar14 = lVar8 + -1;
                          if (lVar8 + -1 == 0) {
                            FUN_23a334bc0();
                          }
                          if (plVar15 == (longlong *)0x0) {
                            auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                            plStack_68 = *(longlong **)(param_1 + 0x70);
                            uStack_a8 = 0x72;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            plStack_130 = (longlong *)0x0;
                            plStack_120 = (longlong *)0x0;
                            plStack_128 = (longlong *)0x0;
                            plStack_110 = (longlong *)0x0;
                            plStack_e8 = (longlong *)0x0;
                            plStack_f0 = (longlong *)0x0;
                            plStack_108 = (longlong *)0x0;
                            plStack_118 = (longlong *)0x0;
                            plStack_e0 = (longlong *)0x0;
                            plStack_c8 = (longlong *)0x0;
                            plStack_b8 = (longlong *)0x0;
                            plStack_d8 = (longlong *)0x0;
                            plStack_f8 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plStack_d0 = (longlong *)0x0;
                            goto LAB_23e2b9c20;
                          }
                          lVar8 = *plVar15;
                          *plVar15 = lVar8 + -1;
                          if (lVar8 + -1 == 0) {
                            FUN_23a334bc0(plVar15);
                          }
                          lVar8 = FUN_23e8f6d10();
                          if (lVar8 == 0) {
                            FUN_23e915740(param_1,auStack_78,DAT_23eeadae8);
                            uStack_a8 = 0x74;
                            plStack_130 = (longlong *)0x0;
                            plStack_120 = (longlong *)0x0;
                            plStack_128 = (longlong *)0x0;
                            plStack_110 = (longlong *)0x0;
                            plStack_e8 = (longlong *)0x0;
                            plStack_f0 = (longlong *)0x0;
                            plStack_108 = (longlong *)0x0;
                            plStack_118 = (longlong *)0x0;
                            plStack_e0 = (longlong *)0x0;
                            plStack_c8 = (longlong *)0x0;
                            plStack_b8 = (longlong *)0x0;
                            plStack_d0 = (longlong *)0x0;
                            plStack_d8 = (longlong *)0x0;
                            plStack_f8 = (longlong *)0x0;
                            goto LAB_23e2b9c20;
                          }
                          *(undefined4 *)(plVar7 + 5) = 0x74;
                          plVar12 = (longlong *)FUN_23e94bb80(param_1,lVar8);
                          if (plVar12 == (longlong *)0x0) {
                            auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                            plStack_68 = *(longlong **)(param_1 + 0x70);
                            uStack_a8 = 0x74;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            plStack_130 = (longlong *)0x0;
                            plStack_120 = (longlong *)0x0;
                            plStack_128 = (longlong *)0x0;
                            plStack_110 = (longlong *)0x0;
                            plStack_e8 = (longlong *)0x0;
                            plStack_f0 = (longlong *)0x0;
                            plStack_108 = (longlong *)0x0;
                            plStack_118 = (longlong *)0x0;
                            plStack_e0 = (longlong *)0x0;
                            plStack_c8 = (longlong *)0x0;
                            plStack_b8 = (longlong *)0x0;
                            plStack_d0 = (longlong *)0x0;
                            plStack_d8 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plStack_f8 = (longlong *)0x0;
                            goto LAB_23e2b9c20;
                          }
                          cVar5 = FUN_23e8d9ac0(plVar17[2],_DAT_23eeadaf8,plVar12);
                          lVar8 = *plVar12;
                          *plVar12 = lVar8 + -1;
                          if (lVar8 + -1 == 0) {
                            FUN_23a334bc0();
                          }
                          if (cVar5 == '\0') {
                            auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                            plStack_68 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uStack_a8 = 0x74;
                            plStack_130 = (longlong *)0x0;
                            plStack_120 = (longlong *)0x0;
                            plStack_128 = (longlong *)0x0;
                            plStack_110 = (longlong *)0x0;
                            plStack_e8 = (longlong *)0x0;
                            plStack_f0 = (longlong *)0x0;
                            plStack_108 = (longlong *)0x0;
                            plStack_118 = (longlong *)0x0;
                            plStack_e0 = (longlong *)0x0;
                            plStack_c8 = (longlong *)0x0;
                            plStack_b8 = (longlong *)0x0;
                            plStack_d0 = (longlong *)0x0;
                            plStack_d8 = (longlong *)0x0;
                            plStack_f8 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            goto LAB_23e2b9c20;
                          }
                          plVar12 = (longlong *)FUN_23e8bc2f0(plVar17[2],_DAT_23eeadaf8);
                          if (plVar12 == (longlong *)0x0) {
                            auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                            plStack_68 = *(longlong **)(param_1 + 0x70);
                            uStack_a8 = 0x75;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            plStack_130 = (longlong *)0x0;
                            plStack_120 = (longlong *)0x0;
                            plStack_128 = (longlong *)0x0;
                            plStack_110 = (longlong *)0x0;
                            plStack_e8 = (longlong *)0x0;
                            plStack_f0 = (longlong *)0x0;
                            plStack_108 = (longlong *)0x0;
                            plStack_118 = (longlong *)0x0;
                            plStack_e0 = (longlong *)0x0;
                            plStack_c8 = (longlong *)0x0;
                            plStack_b8 = (longlong *)0x0;
                            plStack_d0 = (longlong *)0x0;
                            plStack_f8 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plStack_d8 = (longlong *)0x0;
                            goto LAB_23e2b9c20;
                          }
                          *(undefined4 *)(plVar7 + 5) = 0x75;
                          plVar14 = (longlong *)FUN_23e915840(param_1,plVar12,_DAT_23eeadb00);
                          lVar8 = *plVar12;
                          *plVar12 = lVar8 + -1;
                          if (lVar8 + -1 == 0) {
                            FUN_23a334bc0(plVar12);
                          }
                          if (plVar14 == (longlong *)0x0) {
                            auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                            plStack_68 = *(longlong **)(param_1 + 0x70);
                            uStack_a8 = 0x75;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            plStack_130 = (longlong *)0x0;
                            plStack_120 = (longlong *)0x0;
                            plStack_128 = (longlong *)0x0;
                            plStack_110 = (longlong *)0x0;
                            plStack_e8 = (longlong *)0x0;
                            plStack_f0 = (longlong *)0x0;
                            plStack_108 = (longlong *)0x0;
                            plStack_118 = (longlong *)0x0;
                            plStack_e0 = (longlong *)0x0;
                            plStack_c8 = (longlong *)0x0;
                            plStack_b8 = (longlong *)0x0;
                            plStack_d0 = (longlong *)0x0;
                            plStack_d8 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plStack_f8 = (longlong *)0x0;
                            goto LAB_23e2b9c20;
                          }
                          lVar8 = *plVar14;
                          *plVar14 = lVar8 + -1;
                          if (lVar8 + -1 == 0) {
                            FUN_23a334bc0();
                          }
                          plVar12 = (longlong *)FUN_23e8bc2f0(plVar17[2],_DAT_23eeadaf8);
                          if (plVar12 == (longlong *)0x0) {
                            auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                            plStack_68 = *(longlong **)(param_1 + 0x70);
                            uStack_a8 = 0x76;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            plStack_130 = (longlong *)0x0;
                            plStack_120 = (longlong *)0x0;
                            plStack_128 = (longlong *)0x0;
                            plStack_110 = (longlong *)0x0;
                            plStack_e8 = (longlong *)0x0;
                            plStack_f0 = (longlong *)0x0;
                            plStack_108 = (longlong *)0x0;
                            plStack_118 = (longlong *)0x0;
                            plStack_e0 = (longlong *)0x0;
                            plStack_c8 = (longlong *)0x0;
                            plStack_b8 = (longlong *)0x0;
                            plStack_d0 = (longlong *)0x0;
                            plStack_d8 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plStack_f8 = (longlong *)0x0;
                            goto LAB_23e2b9c20;
                          }
                          plVar14 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23eead9b8);
                          lVar8 = *plVar12;
                          *plVar12 = lVar8 + -1;
                          if (lVar8 + -1 == 0) {
                            FUN_23a334bc0(plVar12);
                          }
                          plVar12 = _DAT_23eeadb10;
                          if (plVar14 == (longlong *)0x0) {
                            auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                            plStack_68 = *(longlong **)(param_1 + 0x70);
                            uStack_a8 = 0x76;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            plStack_130 = (longlong *)0x0;
                            plStack_120 = (longlong *)0x0;
                            plStack_128 = (longlong *)0x0;
                            plStack_110 = (longlong *)0x0;
                            plStack_e8 = (longlong *)0x0;
                            plStack_f0 = (longlong *)0x0;
                            plStack_108 = (longlong *)0x0;
                            plStack_118 = (longlong *)0x0;
                            plStack_e0 = (longlong *)0x0;
                            plStack_c8 = (longlong *)0x0;
                            plStack_b8 = (longlong *)0x0;
                            plStack_d8 = (longlong *)0x0;
                            plStack_f8 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plStack_d0 = (longlong *)0x0;
                            goto LAB_23e2b9c20;
                          }
                          plVar15 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
                          *plVar12 = *plVar12 + 1;
                          plVar15[3] = (longlong)plVar12;
                          lVar8 = FUN_23e8f7250();
                          if (lVar8 == 0) {
                            FUN_23e915740(param_1,auStack_78,DAT_23eeadad0);
                          }
                          else {
                            lVar8 = FUN_23e94f9d0(param_1,lVar8);
                            if (lVar8 != 0) {
                              plVar15[4] = lVar8;
                              plVar12 = _DAT_23eeadb18;
                              *_DAT_23eeadb18 = *_DAT_23eeadb18 + 1;
                              plVar15[5] = (longlong)plVar12;
                              plVar12 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar15);
                              *plVar15 = *plVar15 + -1;
                              if (*plVar15 == 0) {
                                FUN_23a334bc0(plVar15);
                              }
                              if (plVar12 == (longlong *)0x0) {
                                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_68 = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                lVar8 = *plVar14;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *plVar14 = lVar8 + -1;
                                plStack_f8 = (longlong *)0x0;
                                if (lVar8 + -1 == 0) {
                                  FUN_23a334bc0();
                                  uStack_a8 = 0x76;
                                  plStack_130 = (longlong *)0x0;
                                  plStack_120 = (longlong *)0x0;
                                  plStack_128 = (longlong *)0x0;
                                  plStack_110 = (longlong *)0x0;
                                  plStack_e8 = (longlong *)0x0;
                                  plStack_f0 = (longlong *)0x0;
                                  plStack_108 = (longlong *)0x0;
                                  plStack_118 = (longlong *)0x0;
                                  plStack_e0 = (longlong *)0x0;
                                  plStack_c8 = (longlong *)0x0;
                                  plStack_b8 = (longlong *)0x0;
                                  plStack_d0 = (longlong *)0x0;
                                  plStack_d8 = (longlong *)0x0;
                                }
                                else {
                                  uStack_a8 = 0x76;
                                  plStack_130 = (longlong *)0x0;
                                  plStack_120 = (longlong *)0x0;
                                  plStack_128 = (longlong *)0x0;
                                  plStack_110 = (longlong *)0x0;
                                  plStack_e8 = (longlong *)0x0;
                                  plStack_f0 = (longlong *)0x0;
                                  plStack_108 = (longlong *)0x0;
                                  plStack_118 = (longlong *)0x0;
                                  plStack_e0 = (longlong *)0x0;
                                  plStack_c8 = (longlong *)0x0;
                                  plStack_b8 = (longlong *)0x0;
                                  plStack_d0 = (longlong *)0x0;
                                  plStack_d8 = (longlong *)0x0;
                                }
                                goto LAB_23e2b9c20;
                              }
                              *(undefined4 *)(plVar7 + 5) = 0x76;
                              plVar15 = (longlong *)FUN_23e914090(param_1,plVar14,plVar12);
                              lVar8 = *plVar14;
                              *plVar14 = lVar8 + -1;
                              if (lVar8 + -1 == 0) {
                                FUN_23a334bc0();
                              }
                              lVar8 = *plVar12;
                              *plVar12 = lVar8 + -1;
                              if (lVar8 + -1 == 0) {
                                FUN_23a334bc0();
                              }
                              if (plVar15 == (longlong *)0x0) {
                                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_68 = *(longlong **)(param_1 + 0x70);
                                uStack_a8 = 0x76;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_130 = (longlong *)0x0;
                                plStack_120 = (longlong *)0x0;
                                plStack_128 = (longlong *)0x0;
                                plStack_110 = (longlong *)0x0;
                                plStack_e8 = (longlong *)0x0;
                                plStack_f0 = (longlong *)0x0;
                                plStack_108 = (longlong *)0x0;
                                plStack_118 = (longlong *)0x0;
                                plStack_e0 = (longlong *)0x0;
                                plStack_c8 = (longlong *)0x0;
                                plStack_b8 = (longlong *)0x0;
                                plStack_d0 = (longlong *)0x0;
                                plStack_f8 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plStack_d8 = (longlong *)0x0;
                                goto LAB_23e2b9c20;
                              }
                              lVar8 = *plVar15;
                              *plVar15 = lVar8 + -1;
                              if (lVar8 + -1 == 0) {
                                FUN_23a334bc0();
                              }
                              plVar12 = (longlong *)FUN_23e8bc2f0(plVar17[2]);
                              if (plVar12 == (longlong *)0x0) {
                                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_68 = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_130 = (longlong *)0x0;
                                plStack_120 = (longlong *)0x0;
                                plStack_128 = (longlong *)0x0;
                                plStack_110 = (longlong *)0x0;
                                plStack_e8 = (longlong *)0x0;
                                plStack_f0 = (longlong *)0x0;
                                plStack_108 = (longlong *)0x0;
                                plStack_118 = (longlong *)0x0;
                                plStack_e0 = (longlong *)0x0;
                                plStack_c8 = (longlong *)0x0;
                                plStack_b8 = (longlong *)0x0;
                                plStack_d0 = (longlong *)0x0;
                                plStack_d8 = (longlong *)0x0;
                                uStack_a8 = 0x8b;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plStack_f8 = (longlong *)0x0;
                                goto LAB_23e2b9c20;
                              }
                              plVar14 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23eeadb20);
                              lVar8 = *plVar12;
                              *plVar12 = lVar8 + -1;
                              if (lVar8 + -1 == 0) {
                                FUN_23a334bc0(plVar12);
                              }
                              if (plVar14 == (longlong *)0x0) {
                                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_68 = *(longlong **)(param_1 + 0x70);
                                uStack_a8 = 0x8b;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_130 = (longlong *)0x0;
                                plStack_120 = (longlong *)0x0;
                                plStack_128 = (longlong *)0x0;
                                plStack_110 = (longlong *)0x0;
                                plStack_e8 = (longlong *)0x0;
                                plStack_f0 = (longlong *)0x0;
                                plStack_108 = (longlong *)0x0;
                                plStack_118 = (longlong *)0x0;
                                plStack_e0 = (longlong *)0x0;
                                plStack_c8 = (longlong *)0x0;
                                plStack_b8 = (longlong *)0x0;
                                plStack_d0 = (longlong *)0x0;
                                plStack_f8 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plStack_d8 = (longlong *)0x0;
                                goto LAB_23e2b9c20;
                              }
                              plVar12 = (longlong *)FUN_23e8bc2f0(plVar14,_DAT_23eead928);
                              lVar8 = *plVar14;
                              *plVar14 = lVar8 + -1;
                              if (lVar8 + -1 == 0) {
                                FUN_23a334bc0(plVar14);
                              }
                              if (plVar12 == (longlong *)0x0) {
                                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_68 = *(longlong **)(param_1 + 0x70);
                                uStack_a8 = 0x8b;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_130 = (longlong *)0x0;
                                plStack_120 = (longlong *)0x0;
                                plStack_128 = (longlong *)0x0;
                                plStack_110 = (longlong *)0x0;
                                plStack_e8 = (longlong *)0x0;
                                plStack_f0 = (longlong *)0x0;
                                plStack_108 = (longlong *)0x0;
                                plStack_118 = (longlong *)0x0;
                                plStack_e0 = (longlong *)0x0;
                                plStack_c8 = (longlong *)0x0;
                                plStack_b8 = (longlong *)0x0;
                                plStack_d8 = (longlong *)0x0;
                                plStack_f8 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plStack_d0 = (longlong *)0x0;
                                goto LAB_23e2b9c20;
                              }
                              plVar14 = (longlong *)FUN_23e8bc2f0(plVar17[2],DAT_23eeadb28);
                              if (plVar14 == (longlong *)0x0) {
                                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_68 = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                lVar8 = *plVar12;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *plVar12 = lVar8 + -1;
                                plStack_f8 = (longlong *)0x0;
                                if (lVar8 + -1 == 0) {
                                  FUN_23a334bc0(plVar12);
                                  uStack_a8 = 0x8b;
                                  plStack_130 = (longlong *)0x0;
                                  plStack_120 = (longlong *)0x0;
                                  plStack_128 = (longlong *)0x0;
                                  plStack_110 = (longlong *)0x0;
                                  plStack_e8 = (longlong *)0x0;
                                  plStack_f0 = (longlong *)0x0;
                                  plStack_108 = (longlong *)0x0;
                                  plStack_118 = (longlong *)0x0;
                                  plStack_e0 = (longlong *)0x0;
                                  plStack_c8 = (longlong *)0x0;
                                  plStack_b8 = (longlong *)0x0;
                                  plStack_d0 = (longlong *)0x0;
                                  plStack_d8 = (longlong *)0x0;
                                }
                                else {
                                  uStack_a8 = 0x8b;
                                  plStack_130 = (longlong *)0x0;
                                  plStack_120 = (longlong *)0x0;
                                  plStack_128 = (longlong *)0x0;
                                  plStack_110 = (longlong *)0x0;
                                  plStack_e8 = (longlong *)0x0;
                                  plStack_f0 = (longlong *)0x0;
                                  plStack_108 = (longlong *)0x0;
                                  plStack_118 = (longlong *)0x0;
                                  plStack_e0 = (longlong *)0x0;
                                  plStack_c8 = (longlong *)0x0;
                                  plStack_b8 = (longlong *)0x0;
                                  plStack_d0 = (longlong *)0x0;
                                  plStack_d8 = (longlong *)0x0;
                                }
                                goto LAB_23e2b9c20;
                              }
                              *(undefined4 *)(plVar7 + 5) = 0x8b;
                              plVar15 = (longlong *)FUN_23e914090(param_1,plVar12,plVar14);
                              lVar8 = *plVar12;
                              *plVar12 = lVar8 + -1;
                              if (lVar8 + -1 == 0) {
                                FUN_23a334bc0(plVar12);
                              }
                              lVar8 = *plVar14;
                              *plVar14 = lVar8 + -1;
                              if (lVar8 + -1 == 0) {
                                FUN_23a334bc0();
                              }
                              if (plVar15 == (longlong *)0x0) {
                                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_68 = *(longlong **)(param_1 + 0x70);
                                uStack_a8 = 0x8b;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_130 = (longlong *)0x0;
                                plStack_120 = (longlong *)0x0;
                                plStack_128 = (longlong *)0x0;
                                plStack_110 = (longlong *)0x0;
                                plStack_e8 = (longlong *)0x0;
                                plStack_f0 = (longlong *)0x0;
                                plStack_108 = (longlong *)0x0;
                                plStack_118 = (longlong *)0x0;
                                plStack_e0 = (longlong *)0x0;
                                plStack_c8 = (longlong *)0x0;
                                plStack_b8 = (longlong *)0x0;
                                plStack_d0 = (longlong *)0x0;
                                plStack_f8 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plStack_d8 = (longlong *)0x0;
                                goto LAB_23e2b9c20;
                              }
                              lVar8 = *plVar15;
                              *plVar15 = lVar8 + -1;
                              if (lVar8 + -1 == 0) {
                                FUN_23a334bc0(plVar15);
                              }
                              plVar12 = (longlong *)FUN_23e8bc2f0(plStack_b0,_DAT_23eeada70);
                              if (plVar12 == (longlong *)0x0) {
                                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_68 = *(longlong **)(param_1 + 0x70);
                                uStack_a8 = 0x8c;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_130 = (longlong *)0x0;
                                plStack_120 = (longlong *)0x0;
                                plStack_128 = (longlong *)0x0;
                                plStack_110 = (longlong *)0x0;
                                plStack_e8 = (longlong *)0x0;
                                plStack_f0 = (longlong *)0x0;
                                plStack_108 = (longlong *)0x0;
                                plStack_118 = (longlong *)0x0;
                                plStack_e0 = (longlong *)0x0;
                                plStack_c8 = (longlong *)0x0;
                                plStack_b8 = (longlong *)0x0;
                                plStack_d0 = (longlong *)0x0;
                                plStack_f8 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plStack_d8 = (longlong *)0x0;
                                goto LAB_23e2b9c20;
                              }
                              plVar14 = (longlong *)FUN_23e8bc2f0(plVar17[2]);
                              if (plVar14 == (longlong *)0x0) {
                                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_68 = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                lVar8 = *plVar12;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *plVar12 = lVar8 + -1;
                                plStack_f8 = (longlong *)0x0;
                                if (lVar8 + -1 == 0) {
                                  FUN_23a334bc0();
                                  uStack_a8 = 0x8c;
                                  plStack_130 = (longlong *)0x0;
                                  plStack_120 = (longlong *)0x0;
                                  plStack_128 = (longlong *)0x0;
                                  plStack_110 = (longlong *)0x0;
                                  plStack_e8 = (longlong *)0x0;
                                  plStack_f0 = (longlong *)0x0;
                                  plStack_108 = (longlong *)0x0;
                                  plStack_118 = (longlong *)0x0;
                                  plStack_e0 = (longlong *)0x0;
                                  plStack_c8 = (longlong *)0x0;
                                  plStack_b8 = (longlong *)0x0;
                                  plStack_d0 = (longlong *)0x0;
                                  plStack_d8 = (longlong *)0x0;
                                }
                                else {
                                  plStack_130 = (longlong *)0x0;
                                  plStack_120 = (longlong *)0x0;
                                  plStack_128 = (longlong *)0x0;
                                  plStack_110 = (longlong *)0x0;
                                  plStack_e8 = (longlong *)0x0;
                                  plStack_f0 = (longlong *)0x0;
                                  plStack_108 = (longlong *)0x0;
                                  plStack_118 = (longlong *)0x0;
                                  plStack_e0 = (longlong *)0x0;
                                  plStack_c8 = (longlong *)0x0;
                                  plStack_b8 = (longlong *)0x0;
                                  plStack_d0 = (longlong *)0x0;
                                  plStack_d8 = (longlong *)0x0;
                                  uStack_a8 = 0x8c;
                                }
                                goto LAB_23e2b9c20;
                              }
                              *(undefined4 *)(plVar7 + 5) = 0x8c;
                              uStack_80 = DAT_23ed6ccf8;
                              plStack_88 = plVar14;
                              plVar15 = (longlong *)FUN_23e94ed00(param_1,plVar12);
                              lVar8 = *plVar12;
                              *plVar12 = lVar8 + -1;
                              if (lVar8 + -1 == 0) {
                                FUN_23a334bc0(plVar12);
                              }
                              lVar8 = *plVar14;
                              *plVar14 = lVar8 + -1;
                              if (lVar8 + -1 == 0) {
                                FUN_23a334bc0(plVar14);
                              }
                              if (plVar15 == (longlong *)0x0) {
                                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_68 = *(longlong **)(param_1 + 0x70);
                                uStack_a8 = 0x8c;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_130 = (longlong *)0x0;
                                plStack_120 = (longlong *)0x0;
                                plStack_128 = (longlong *)0x0;
                                plStack_110 = (longlong *)0x0;
                                plStack_e8 = (longlong *)0x0;
                                plStack_f0 = (longlong *)0x0;
                                plStack_108 = (longlong *)0x0;
                                plStack_118 = (longlong *)0x0;
                                plStack_e0 = (longlong *)0x0;
                                plStack_c8 = (longlong *)0x0;
                                plStack_b8 = (longlong *)0x0;
                                plStack_d8 = (longlong *)0x0;
                                plStack_f8 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plStack_d0 = (longlong *)0x0;
                                goto LAB_23e2b9c20;
                              }
                              lVar8 = *plVar15;
                              *plVar15 = lVar8 + -1;
                              if (lVar8 + -1 == 0) {
                                FUN_23a334bc0();
                              }
                              *(undefined4 *)(plVar7 + 5) = 0x8e;
                              plVar12 = (longlong *)
                                        FUN_23e915840(param_1,plStack_100,_DAT_23eeadb30,plStack_b0)
                              ;
                              if (plVar12 == (longlong *)0x0) {
                                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_68 = *(longlong **)(param_1 + 0x70);
                                uStack_a8 = 0x8e;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_130 = (longlong *)0x0;
                                plStack_120 = (longlong *)0x0;
                                plStack_128 = (longlong *)0x0;
                                plStack_110 = (longlong *)0x0;
                                plStack_e8 = (longlong *)0x0;
                                plStack_f0 = (longlong *)0x0;
                                plStack_108 = (longlong *)0x0;
                                plStack_118 = (longlong *)0x0;
                                plStack_e0 = (longlong *)0x0;
                                plStack_c8 = (longlong *)0x0;
                                plStack_b8 = (longlong *)0x0;
                                plStack_d0 = (longlong *)0x0;
                                plStack_d8 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plStack_f8 = (longlong *)0x0;
                                goto LAB_23e2b9c20;
                              }
                              lVar8 = *plVar12;
                              *plVar12 = lVar8 + -1;
                              if (lVar8 + -1 == 0) {
                                FUN_23a334bc0(plVar12);
                              }
                              lVar8 = FUN_23e8f6e60();
                              if (lVar8 == 0) {
                                FUN_23e915740(param_1,auStack_78,DAT_23eead9e8);
                                plStack_130 = (longlong *)0x0;
                                plStack_120 = (longlong *)0x0;
                                plStack_128 = (longlong *)0x0;
                                plStack_110 = (longlong *)0x0;
                                plStack_e8 = (longlong *)0x0;
                                plStack_f0 = (longlong *)0x0;
                                plStack_108 = (longlong *)0x0;
                                plStack_118 = (longlong *)0x0;
                                plStack_e0 = (longlong *)0x0;
                                plStack_c8 = (longlong *)0x0;
                                plStack_b8 = (longlong *)0x0;
                                plStack_d0 = (longlong *)0x0;
                                plStack_d8 = (longlong *)0x0;
                                uStack_a8 = 0x91;
                                plStack_f8 = (longlong *)0x0;
                                goto LAB_23e2b9c20;
                              }
                              *(undefined4 *)(plVar7 + 5) = 0x91;
                              plVar12 = (longlong *)FUN_23e94bb80(param_1,lVar8,_DAT_23eeadb38);
                              if (plVar12 == (longlong *)0x0) {
                                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_68 = *(longlong **)(param_1 + 0x70);
                                uStack_a8 = 0x91;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_130 = (longlong *)0x0;
                                plStack_120 = (longlong *)0x0;
                                plStack_128 = (longlong *)0x0;
                                plStack_110 = (longlong *)0x0;
                                plStack_e8 = (longlong *)0x0;
                                plStack_f0 = (longlong *)0x0;
                                plStack_108 = (longlong *)0x0;
                                plStack_118 = (longlong *)0x0;
                                plStack_e0 = (longlong *)0x0;
                                plStack_c8 = (longlong *)0x0;
                                plStack_b8 = (longlong *)0x0;
                                plStack_d0 = (longlong *)0x0;
                                plStack_d8 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plStack_f8 = (longlong *)0x0;
                                goto LAB_23e2b9c20;
                              }
                              cVar5 = FUN_23e8d9ac0(plVar17[2],_DAT_23eeadb40,plVar12);
                              lVar8 = *plVar12;
                              *plVar12 = lVar8 + -1;
                              if (lVar8 + -1 == 0) {
                                FUN_23a334bc0();
                              }
                              if (cVar5 == '\0') {
                                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_68 = *(longlong **)(param_1 + 0x70);
                                uStack_a8 = 0x91;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_130 = (longlong *)0x0;
                                plStack_120 = (longlong *)0x0;
                                plStack_128 = (longlong *)0x0;
                                plStack_110 = (longlong *)0x0;
                                plStack_e8 = (longlong *)0x0;
                                plStack_f0 = (longlong *)0x0;
                                plStack_108 = (longlong *)0x0;
                                plStack_118 = (longlong *)0x0;
                                plStack_e0 = (longlong *)0x0;
                                plStack_c8 = (longlong *)0x0;
                                plStack_b8 = (longlong *)0x0;
                                plStack_d0 = (longlong *)0x0;
                                plStack_d8 = (longlong *)0x0;
                                plStack_f8 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e2b9c20;
                              }
                              plVar12 = (longlong *)FUN_23e8bc2f0(plVar17[2],_DAT_23eeadb40);
                              if (plVar12 == (longlong *)0x0) {
                                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_68 = *(longlong **)(param_1 + 0x70);
                                uStack_a8 = 0x92;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_130 = (longlong *)0x0;
                                plStack_120 = (longlong *)0x0;
                                plStack_128 = (longlong *)0x0;
                                plStack_110 = (longlong *)0x0;
                                plStack_e8 = (longlong *)0x0;
                                plStack_f0 = (longlong *)0x0;
                                plStack_108 = (longlong *)0x0;
                                plStack_118 = (longlong *)0x0;
                                plStack_e0 = (longlong *)0x0;
                                plStack_c8 = (longlong *)0x0;
                                plStack_b8 = (longlong *)0x0;
                                plStack_d0 = (longlong *)0x0;
                                plStack_f8 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plStack_d8 = (longlong *)0x0;
                                goto LAB_23e2b9c20;
                              }
                              *(undefined4 *)(plVar7 + 5) = 0x92;
                              plVar14 = (longlong *)FUN_23e915840(param_1,plVar12,_DAT_23eead9f8);
                              lVar8 = *plVar12;
                              *plVar12 = lVar8 + -1;
                              if (lVar8 + -1 == 0) {
                                FUN_23a334bc0(plVar12);
                              }
                              if (plVar14 == (longlong *)0x0) {
                                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_68 = *(longlong **)(param_1 + 0x70);
                                uStack_a8 = 0x92;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_130 = (longlong *)0x0;
                                plStack_120 = (longlong *)0x0;
                                plStack_128 = (longlong *)0x0;
                                plStack_110 = (longlong *)0x0;
                                plStack_e8 = (longlong *)0x0;
                                plStack_f0 = (longlong *)0x0;
                                plStack_108 = (longlong *)0x0;
                                plStack_118 = (longlong *)0x0;
                                plStack_e0 = (longlong *)0x0;
                                plStack_c8 = (longlong *)0x0;
                                plStack_b8 = (longlong *)0x0;
                                plStack_d0 = (longlong *)0x0;
                                plStack_d8 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plStack_f8 = (longlong *)0x0;
                                goto LAB_23e2b9c20;
                              }
                              lVar8 = *plVar14;
                              *plVar14 = lVar8 + -1;
                              if (lVar8 + -1 == 0) {
                                FUN_23a334bc0();
                              }
                              plVar12 = (longlong *)FUN_23e8bc2f0(plVar17[2],_DAT_23eeadb40);
                              if (plVar12 == (longlong *)0x0) {
                                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_68 = *(longlong **)(param_1 + 0x70);
                                uStack_a8 = 0x93;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_130 = (longlong *)0x0;
                                plStack_120 = (longlong *)0x0;
                                plStack_128 = (longlong *)0x0;
                                plStack_110 = (longlong *)0x0;
                                plStack_e8 = (longlong *)0x0;
                                plStack_f0 = (longlong *)0x0;
                                plStack_108 = (longlong *)0x0;
                                plStack_118 = (longlong *)0x0;
                                plStack_e0 = (longlong *)0x0;
                                plStack_c8 = (longlong *)0x0;
                                plStack_b8 = (longlong *)0x0;
                                plStack_d0 = (longlong *)0x0;
                                plStack_d8 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plStack_f8 = (longlong *)0x0;
                                goto LAB_23e2b9c20;
                              }
                              plVar14 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23eead9b8);
                              lVar8 = *plVar12;
                              *plVar12 = lVar8 + -1;
                              if (lVar8 + -1 == 0) {
                                FUN_23a334bc0(plVar12);
                              }
                              plVar12 = _DAT_23eeadb48;
                              if (plVar14 == (longlong *)0x0) {
                                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                plStack_68 = *(longlong **)(param_1 + 0x70);
                                uStack_a8 = 0x93;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_130 = (longlong *)0x0;
                                plStack_120 = (longlong *)0x0;
                                plStack_128 = (longlong *)0x0;
                                plStack_110 = (longlong *)0x0;
                                plStack_e8 = (longlong *)0x0;
                                plStack_f0 = (longlong *)0x0;
                                plStack_108 = (longlong *)0x0;
                                plStack_118 = (longlong *)0x0;
                                plStack_e0 = (longlong *)0x0;
                                plStack_c8 = (longlong *)0x0;
                                plStack_b8 = (longlong *)0x0;
                                plStack_d8 = (longlong *)0x0;
                                plStack_f8 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plStack_d0 = (longlong *)0x0;
                                goto LAB_23e2b9c20;
                              }
                              plVar15 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3)
                              ;
                              *plVar12 = *plVar12 + 1;
                              plVar15[3] = (longlong)plVar12;
                              lVar8 = FUN_23e8f7100();
                              if (lVar8 == 0) {
                                FUN_23e915740(param_1,auStack_78);
                              }
                              else {
                                lVar8 = FUN_23e94f9d0(param_1,lVar8);
                                if (lVar8 != 0) {
                                  plVar15[4] = lVar8;
                                  plVar12 = _DAT_23eeadb58;
                                  *_DAT_23eeadb58 = *_DAT_23eeadb58 + 1;
                                  plVar15[5] = (longlong)plVar12;
                                  plVar12 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar15);
                                  *plVar15 = *plVar15 + -1;
                                  if (*plVar15 == 0) {
                                    FUN_23a334bc0(plVar15);
                                  }
                                  if (plVar12 == (longlong *)0x0) {
                                    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    lVar8 = *plVar14;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    *plVar14 = lVar8 + -1;
                                    plStack_f8 = (longlong *)0x0;
                                    if (lVar8 + -1 == 0) {
                                      FUN_23a334bc0();
                                      uStack_a8 = 0x93;
                                      plStack_130 = (longlong *)0x0;
                                      plStack_120 = (longlong *)0x0;
                                      plStack_128 = (longlong *)0x0;
                                      plStack_110 = (longlong *)0x0;
                                      plStack_e8 = (longlong *)0x0;
                                      plStack_f0 = (longlong *)0x0;
                                      plStack_108 = (longlong *)0x0;
                                      plStack_118 = (longlong *)0x0;
                                      plStack_e0 = (longlong *)0x0;
                                      plStack_c8 = (longlong *)0x0;
                                      plStack_b8 = (longlong *)0x0;
                                      plStack_d0 = (longlong *)0x0;
                                      plStack_d8 = (longlong *)0x0;
                                    }
                                    else {
                                      uStack_a8 = 0x93;
                                      plStack_130 = (longlong *)0x0;
                                      plStack_120 = (longlong *)0x0;
                                      plStack_128 = (longlong *)0x0;
                                      plStack_110 = (longlong *)0x0;
                                      plStack_e8 = (longlong *)0x0;
                                      plStack_f0 = (longlong *)0x0;
                                      plStack_108 = (longlong *)0x0;
                                      plStack_118 = (longlong *)0x0;
                                      plStack_e0 = (longlong *)0x0;
                                      plStack_c8 = (longlong *)0x0;
                                      plStack_b8 = (longlong *)0x0;
                                      plStack_d0 = (longlong *)0x0;
                                      plStack_d8 = (longlong *)0x0;
                                    }
                                    goto LAB_23e2b9c20;
                                  }
                                  *(undefined4 *)(plVar7 + 5) = 0x93;
                                  plVar15 = (longlong *)FUN_23e914090(param_1,plVar14,plVar12);
                                  lVar8 = *plVar14;
                                  *plVar14 = lVar8 + -1;
                                  if (lVar8 + -1 == 0) {
                                    FUN_23a334bc0(plVar14);
                                  }
                                  lVar8 = *plVar12;
                                  *plVar12 = lVar8 + -1;
                                  if (lVar8 + -1 == 0) {
                                    FUN_23a334bc0(plVar12);
                                  }
                                  if (plVar15 == (longlong *)0x0) {
                                    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                    uStack_a8 = 0x93;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    plStack_130 = (longlong *)0x0;
                                    plStack_120 = (longlong *)0x0;
                                    plStack_128 = (longlong *)0x0;
                                    plStack_110 = (longlong *)0x0;
                                    plStack_e8 = (longlong *)0x0;
                                    plStack_f0 = (longlong *)0x0;
                                    plStack_108 = (longlong *)0x0;
                                    plStack_118 = (longlong *)0x0;
                                    plStack_e0 = (longlong *)0x0;
                                    plStack_c8 = (longlong *)0x0;
                                    plStack_b8 = (longlong *)0x0;
                                    plStack_d0 = (longlong *)0x0;
                                    plStack_f8 = (longlong *)0x0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    plStack_d8 = (longlong *)0x0;
                                    goto LAB_23e2b9c20;
                                  }
                                  lVar8 = *plVar15;
                                  *plVar15 = lVar8 + -1;
                                  if (lVar8 + -1 == 0) {
                                    FUN_23a334bc0();
                                  }
                                  plVar12 = (longlong *)FUN_23e8bc2f0(plStack_100,_DAT_23eeada70);
                                  if (plVar12 == (longlong *)0x0) {
                                    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                    uStack_a8 = 0x94;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    plStack_130 = (longlong *)0x0;
                                    plStack_120 = (longlong *)0x0;
                                    plStack_128 = (longlong *)0x0;
                                    plStack_110 = (longlong *)0x0;
                                    plStack_e8 = (longlong *)0x0;
                                    plStack_f0 = (longlong *)0x0;
                                    plStack_108 = (longlong *)0x0;
                                    plStack_118 = (longlong *)0x0;
                                    plStack_e0 = (longlong *)0x0;
                                    plStack_c8 = (longlong *)0x0;
                                    plStack_b8 = (longlong *)0x0;
                                    plStack_d0 = (longlong *)0x0;
                                    plStack_f8 = (longlong *)0x0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    plStack_d8 = (longlong *)0x0;
                                    goto LAB_23e2b9c20;
                                  }
                                  plVar14 = (longlong *)FUN_23e8bc2f0(plVar17[2],_DAT_23eeadb40);
                                  if (plVar14 == (longlong *)0x0) {
                                    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    lVar8 = *plVar12;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    *plVar12 = lVar8 + -1;
                                    plStack_f8 = (longlong *)0x0;
                                    if (lVar8 + -1 == 0) {
                                      FUN_23a334bc0(plVar12);
                                      plStack_130 = (longlong *)0x0;
                                      uStack_a8 = 0x94;
                                      plStack_120 = (longlong *)0x0;
                                      plStack_128 = (longlong *)0x0;
                                      plStack_110 = (longlong *)0x0;
                                      plStack_e8 = (longlong *)0x0;
                                      plStack_f0 = (longlong *)0x0;
                                      plStack_108 = (longlong *)0x0;
                                      plStack_118 = (longlong *)0x0;
                                      plStack_e0 = (longlong *)0x0;
                                      plStack_c8 = (longlong *)0x0;
                                      plStack_b8 = (longlong *)0x0;
                                      plStack_d0 = (longlong *)0x0;
                                      plStack_d8 = (longlong *)0x0;
                                    }
                                    else {
                                      uStack_a8 = 0x94;
                                      plStack_130 = (longlong *)0x0;
                                      plStack_120 = (longlong *)0x0;
                                      plStack_128 = (longlong *)0x0;
                                      plStack_110 = (longlong *)0x0;
                                      plStack_e8 = (longlong *)0x0;
                                      plStack_f0 = (longlong *)0x0;
                                      plStack_108 = (longlong *)0x0;
                                      plStack_118 = (longlong *)0x0;
                                      plStack_e0 = (longlong *)0x0;
                                      plStack_c8 = (longlong *)0x0;
                                      plStack_b8 = (longlong *)0x0;
                                      plStack_d0 = (longlong *)0x0;
                                      plStack_d8 = (longlong *)0x0;
                                    }
                                    goto LAB_23e2b9c20;
                                  }
                                  *(undefined4 *)(plVar7 + 5) = 0x94;
                                  plVar15 = (longlong *)FUN_23e914090(param_1,plVar12,plVar14);
                                  lVar8 = *plVar12;
                                  *plVar12 = lVar8 + -1;
                                  if (lVar8 + -1 == 0) {
                                    FUN_23a334bc0(plVar12);
                                  }
                                  lVar8 = *plVar14;
                                  *plVar14 = lVar8 + -1;
                                  if (lVar8 + -1 == 0) {
                                    FUN_23a334bc0();
                                  }
                                  if (plVar15 == (longlong *)0x0) {
                                    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                    uStack_a8 = 0x94;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    plStack_130 = (longlong *)0x0;
                                    plStack_120 = (longlong *)0x0;
                                    plStack_128 = (longlong *)0x0;
                                    plStack_110 = (longlong *)0x0;
                                    plStack_e8 = (longlong *)0x0;
                                    plStack_f0 = (longlong *)0x0;
                                    plStack_108 = (longlong *)0x0;
                                    plStack_118 = (longlong *)0x0;
                                    plStack_e0 = (longlong *)0x0;
                                    plStack_c8 = (longlong *)0x0;
                                    plStack_b8 = (longlong *)0x0;
                                    plStack_d8 = (longlong *)0x0;
                                    plStack_f8 = (longlong *)0x0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    plStack_d0 = (longlong *)0x0;
                                    goto LAB_23e2b9c20;
                                  }
                                  lVar8 = *plVar15;
                                  *plVar15 = lVar8 + -1;
                                  if (lVar8 + -1 == 0) {
                                    FUN_23a334bc0(plVar15);
                                  }
                                  *(undefined4 *)(plVar7 + 5) = 0x96;
                                  plVar12 = (longlong *)
                                            FUN_23e915840(param_1,plStack_140,_DAT_23eeada70);
                                  if (plVar12 == (longlong *)0x0) {
                                    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                    uStack_a8 = 0x96;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    plStack_130 = (longlong *)0x0;
                                    plStack_120 = (longlong *)0x0;
                                    plStack_128 = (longlong *)0x0;
                                    plStack_110 = (longlong *)0x0;
                                    plStack_e8 = (longlong *)0x0;
                                    plStack_f0 = (longlong *)0x0;
                                    plStack_108 = (longlong *)0x0;
                                    plStack_118 = (longlong *)0x0;
                                    plStack_e0 = (longlong *)0x0;
                                    plStack_c8 = (longlong *)0x0;
                                    plStack_b8 = (longlong *)0x0;
                                    plStack_d0 = (longlong *)0x0;
                                    plStack_d8 = (longlong *)0x0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    plStack_f8 = (longlong *)0x0;
                                    goto LAB_23e2b9c20;
                                  }
                                  lVar8 = *plVar12;
                                  *plVar12 = lVar8 + -1;
                                  if (lVar8 + -1 == 0) {
                                    FUN_23a334bc0();
                                  }
                                  lVar1 = _DAT_23eeadb60;
                                  lVar8 = plVar17[2];
                                  *(undefined4 *)(plVar7 + 5) = 0x99;
                                  plVar12 = (longlong *)
                                            FUN_23e915840(param_1,lVar8,DAT_23eead9d8,
                                                          *(undefined8 *)(lVar1 + 0x18));
                                  if (plVar12 == (longlong *)0x0) {
LAB_23e2c2468:
                                    uVar18 = *(undefined8 *)(param_1 + 0x60);
                                    uVar19 = *(undefined8 *)(param_1 + 0x68);
                                    plVar12 = *(longlong **)(param_1 + 0x70);
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                  }
                                  else {
                                    plVar14 = (longlong *)FUN_23a388310();
                                    *plVar12 = *plVar12 + -1;
                                    if (*plVar12 == 0) {
                                      FUN_23a334bc0();
                                    }
                                    if (plVar14 == (longlong *)0x0) goto LAB_23e2c2468;
                                    uVar18 = CONCAT44(uVar20,2);
                                    plStack_f8 = (longlong *)
                                                 FUN_23a3c1d30(param_1,auStack_78,plVar14,0,uVar18);
                                    if (plStack_f8 == (longlong *)0x0) {
                                      *plVar14 = *plVar14 + -1;
                                      plStack_d8 = (longlong *)0x0;
                                      plVar12 = plStack_68;
                                      uVar18 = auStack_78._0_8_;
                                      uVar19 = auStack_78._8_8_;
                                      if (*plVar14 == 0) {
LAB_23e2c2425:
                                        plStack_68 = (longlong *)0x0;
                                        auStack_78 = (undefined1  [16])0x0;
                                        FUN_23a334bc0();
                                        plStack_68 = (longlong *)0x0;
                                        auStack_78 = (undefined1  [16])0x0;
                                        if (plStack_f8 != (longlong *)0x0) goto LAB_23e2c22ee;
                                        goto LAB_23e2c2322;
                                      }
                                    }
                                    else {
                                      uVar18 = CONCAT44((int)((ulonglong)uVar18 >> 0x20),2);
                                      plStack_d8 = (longlong *)
                                                   FUN_23a3c1d30(param_1,auStack_78,plVar14,1,uVar18
                                                                );
                                      uVar20 = (undefined4)((ulonglong)uVar18 >> 0x20);
                                      if ((plStack_d8 != (longlong *)0x0) &&
                                         (cVar5 = FUN_23a3884a0(param_1,auStack_78), cVar5 != '\0'))
                                      {
                                        *plVar14 = *plVar14 + -1;
                                        if (*plVar14 == 0) {
                                          FUN_23a334bc0(plVar14);
                                        }
                                        if (*plStack_f8 == 0) {
                                          FUN_23a334bc0(plStack_f8);
                                        }
                                        if (*plStack_d8 == 0) {
                                          FUN_23a334bc0(plStack_d8);
                                        }
                                        lVar1 = _DAT_23eeadb70;
                                        lVar8 = plVar17[2];
                                        *(undefined4 *)(plVar7 + 5) = 0x9c;
                                        plStack_d0 = (longlong *)
                                                     FUN_23e954670(param_1,lVar8,DAT_23eeadb68,
                                                                   lVar1 + 0x18);
                                        if (plStack_d0 == (longlong *)0x0) {
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plStack_130 = (longlong *)0x0;
                                          plStack_120 = (longlong *)0x0;
                                          plStack_128 = (longlong *)0x0;
                                          plStack_110 = (longlong *)0x0;
                                          plStack_e8 = (longlong *)0x0;
                                          plStack_f0 = (longlong *)0x0;
                                          plStack_108 = (longlong *)0x0;
                                          plStack_118 = (longlong *)0x0;
                                          plStack_e0 = (longlong *)0x0;
                                          plStack_c8 = (longlong *)0x0;
                                          plStack_b8 = (longlong *)0x0;
                                          uStack_a8 = 0x9c;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          goto LAB_23e2b9c20;
                                        }
                                        plVar12 = (longlong *)
                                                  FUN_23a388650(param_1,plStack_d0,DAT_23ed6ccf8,1);
                                        if (plVar12 == (longlong *)0x0) {
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          uStack_a8 = 0x9d;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plStack_130 = (longlong *)0x0;
                                          plStack_120 = (longlong *)0x0;
                                          plStack_128 = (longlong *)0x0;
                                          plStack_110 = (longlong *)0x0;
                                          plStack_e8 = (longlong *)0x0;
                                          plStack_f0 = (longlong *)0x0;
                                          plStack_108 = (longlong *)0x0;
                                          plStack_118 = (longlong *)0x0;
                                          plStack_e0 = (longlong *)0x0;
                                          plStack_c8 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          plStack_b8 = (longlong *)0x0;
                                          goto LAB_23e2b9c20;
                                        }
                                        cVar5 = FUN_23e8d9ac0(plVar17[2],_DAT_23eeadb78,plVar12);
                                        lVar8 = *plVar12;
                                        *plVar12 = lVar8 + -1;
                                        if (lVar8 + -1 == 0) {
                                          FUN_23a334bc0();
                                        }
                                        if (cVar5 == '\0') {
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          uStack_a8 = 0x9d;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plStack_130 = (longlong *)0x0;
                                          plStack_120 = (longlong *)0x0;
                                          plStack_128 = (longlong *)0x0;
                                          plStack_110 = (longlong *)0x0;
                                          plStack_e8 = (longlong *)0x0;
                                          plStack_f0 = (longlong *)0x0;
                                          plStack_108 = (longlong *)0x0;
                                          plStack_118 = (longlong *)0x0;
                                          plStack_e0 = (longlong *)0x0;
                                          plStack_c8 = (longlong *)0x0;
                                          plStack_b8 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          goto LAB_23e2b9c20;
                                        }
                                        plVar12 = (longlong *)
                                                  FUN_23e8bc2f0(plStack_d8,_DAT_23eeadb30);
                                        if (plVar12 == (longlong *)0x0) {
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          uStack_a8 = 0x9e;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plStack_130 = (longlong *)0x0;
                                          plStack_120 = (longlong *)0x0;
                                          plStack_128 = (longlong *)0x0;
                                          plStack_110 = (longlong *)0x0;
                                          plStack_e8 = (longlong *)0x0;
                                          plStack_f0 = (longlong *)0x0;
                                          plStack_108 = (longlong *)0x0;
                                          plStack_118 = (longlong *)0x0;
                                          plStack_e0 = (longlong *)0x0;
                                          plStack_b8 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          plStack_c8 = (longlong *)0x0;
                                          goto LAB_23e2b9c20;
                                        }
                                        plVar14 = (longlong *)
                                                  FUN_23a388650(param_1,plStack_d0,DAT_23ed6ccf0,0);
                                        if (plVar14 == (longlong *)0x0) {
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          lVar8 = *plVar12;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          *plVar12 = lVar8 + -1;
                                          plStack_b8 = (longlong *)0x0;
                                          if (lVar8 + -1 == 0) {
                                            FUN_23a334bc0();
                                            uStack_a8 = 0x9e;
                                            plStack_130 = (longlong *)0x0;
                                            plStack_120 = (longlong *)0x0;
                                            plStack_128 = (longlong *)0x0;
                                            plStack_110 = (longlong *)0x0;
                                            plStack_e8 = (longlong *)0x0;
                                            plStack_f0 = (longlong *)0x0;
                                            plStack_108 = (longlong *)0x0;
                                            plStack_118 = (longlong *)0x0;
                                            plStack_e0 = (longlong *)0x0;
                                            plStack_c8 = (longlong *)0x0;
                                          }
                                          else {
                                            uStack_a8 = 0x9e;
                                            plStack_130 = (longlong *)0x0;
                                            plStack_120 = (longlong *)0x0;
                                            plStack_128 = (longlong *)0x0;
                                            plStack_110 = (longlong *)0x0;
                                            plStack_e8 = (longlong *)0x0;
                                            plStack_f0 = (longlong *)0x0;
                                            plStack_108 = (longlong *)0x0;
                                            plStack_118 = (longlong *)0x0;
                                            plStack_e0 = (longlong *)0x0;
                                            plStack_c8 = (longlong *)0x0;
                                          }
                                          goto LAB_23e2b9c20;
                                        }
                                        *(undefined4 *)(plVar7 + 5) = 0x9e;
                                        plVar15 = (longlong *)FUN_23e914090(param_1,plVar12,plVar14)
                                        ;
                                        lVar8 = *plVar12;
                                        *plVar12 = lVar8 + -1;
                                        if (lVar8 + -1 == 0) {
                                          FUN_23a334bc0(plVar12);
                                        }
                                        lVar8 = *plVar14;
                                        *plVar14 = lVar8 + -1;
                                        if (lVar8 + -1 == 0) {
                                          FUN_23a334bc0(plVar14);
                                        }
                                        if (plVar15 == (longlong *)0x0) {
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          uStack_a8 = 0x9e;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plStack_130 = (longlong *)0x0;
                                          plStack_120 = (longlong *)0x0;
                                          plStack_128 = (longlong *)0x0;
                                          plStack_110 = (longlong *)0x0;
                                          plStack_e8 = (longlong *)0x0;
                                          plStack_f0 = (longlong *)0x0;
                                          plStack_108 = (longlong *)0x0;
                                          plStack_118 = (longlong *)0x0;
                                          plStack_c8 = (longlong *)0x0;
                                          plStack_b8 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          plStack_e0 = (longlong *)0x0;
                                          goto LAB_23e2b9c20;
                                        }
                                        lVar8 = *plVar15;
                                        *plVar15 = lVar8 + -1;
                                        if (lVar8 + -1 == 0) {
                                          FUN_23a334bc0();
                                        }
                                        lVar8 = plVar17[2];
                                        *(undefined4 *)(plVar7 + 5) = 0xa1;
                                        plStack_b8 = (longlong *)
                                                     FUN_23e954670(param_1,lVar8,DAT_23eeadb68);
                                        if (plStack_b8 == (longlong *)0x0) {
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          uStack_a8 = 0xa1;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plStack_130 = (longlong *)0x0;
                                          plStack_120 = (longlong *)0x0;
                                          plStack_128 = (longlong *)0x0;
                                          plStack_110 = (longlong *)0x0;
                                          plStack_e8 = (longlong *)0x0;
                                          plStack_f0 = (longlong *)0x0;
                                          plStack_108 = (longlong *)0x0;
                                          plStack_118 = (longlong *)0x0;
                                          plStack_e0 = (longlong *)0x0;
                                          plStack_c8 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          goto LAB_23e2b9c20;
                                        }
                                        plVar12 = (longlong *)
                                                  FUN_23a388650(param_1,plStack_b8,DAT_23ed6ccf8,1);
                                        if (plVar12 == (longlong *)0x0) {
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          uStack_a8 = 0xa2;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plStack_130 = (longlong *)0x0;
                                          plStack_120 = (longlong *)0x0;
                                          plStack_128 = (longlong *)0x0;
                                          plStack_110 = (longlong *)0x0;
                                          plStack_e8 = (longlong *)0x0;
                                          plStack_f0 = (longlong *)0x0;
                                          plStack_108 = (longlong *)0x0;
                                          plStack_118 = (longlong *)0x0;
                                          plStack_e0 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          plStack_c8 = (longlong *)0x0;
                                          goto LAB_23e2b9c20;
                                        }
                                        cVar5 = FUN_23e8d9ac0(plVar17[2],_DAT_23eeadb88,plVar12);
                                        lVar8 = *plVar12;
                                        *plVar12 = lVar8 + -1;
                                        if (lVar8 + -1 == 0) {
                                          FUN_23a334bc0();
                                        }
                                        if (cVar5 == '\0') {
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          uStack_a8 = 0xa2;
                                          plStack_130 = (longlong *)0x0;
                                          plStack_120 = (longlong *)0x0;
                                          plStack_128 = (longlong *)0x0;
                                          plStack_110 = (longlong *)0x0;
                                          plStack_e8 = (longlong *)0x0;
                                          plStack_f0 = (longlong *)0x0;
                                          plStack_108 = (longlong *)0x0;
                                          plStack_118 = (longlong *)0x0;
                                          plStack_e0 = (longlong *)0x0;
                                          plStack_c8 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          goto LAB_23e2b9c20;
                                        }
                                        plVar12 = (longlong *)
                                                  FUN_23e8bc2f0(plStack_d8,_DAT_23eeadb30);
                                        if (plVar12 == (longlong *)0x0) {
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          uStack_a8 = 0xa3;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plStack_130 = (longlong *)0x0;
                                          plStack_120 = (longlong *)0x0;
                                          plStack_128 = (longlong *)0x0;
                                          plStack_110 = (longlong *)0x0;
                                          plStack_e8 = (longlong *)0x0;
                                          plStack_f0 = (longlong *)0x0;
                                          plStack_108 = (longlong *)0x0;
                                          plStack_118 = (longlong *)0x0;
                                          plStack_c8 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          plStack_e0 = (longlong *)0x0;
                                          goto LAB_23e2b9c20;
                                        }
                                        plVar14 = (longlong *)
                                                  FUN_23a388650(param_1,plStack_b8,DAT_23ed6ccf0,0);
                                        if (plVar14 == (longlong *)0x0) {
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          lVar8 = *plVar12;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          *plVar12 = lVar8 + -1;
                                          plStack_c8 = (longlong *)0x0;
                                          if (lVar8 + -1 == 0) {
                                            FUN_23a334bc0(plVar12);
                                            uStack_a8 = 0xa3;
                                            plStack_130 = (longlong *)0x0;
                                            plStack_120 = (longlong *)0x0;
                                            plStack_128 = (longlong *)0x0;
                                            plStack_110 = (longlong *)0x0;
                                            plStack_e8 = (longlong *)0x0;
                                            plStack_f0 = (longlong *)0x0;
                                            plStack_108 = (longlong *)0x0;
                                            plStack_118 = (longlong *)0x0;
                                            plStack_e0 = (longlong *)0x0;
                                          }
                                          else {
                                            uStack_a8 = 0xa3;
                                            plStack_130 = (longlong *)0x0;
                                            plStack_120 = (longlong *)0x0;
                                            plStack_128 = (longlong *)0x0;
                                            plStack_110 = (longlong *)0x0;
                                            plStack_e8 = (longlong *)0x0;
                                            plStack_f0 = (longlong *)0x0;
                                            plStack_108 = (longlong *)0x0;
                                            plStack_118 = (longlong *)0x0;
                                            plStack_e0 = (longlong *)0x0;
                                          }
                                          goto LAB_23e2b9c20;
                                        }
                                        *(undefined4 *)(plVar7 + 5) = 0xa3;
                                        plVar15 = (longlong *)FUN_23e914090(param_1,plVar12,plVar14)
                                        ;
                                        lVar8 = *plVar12;
                                        *plVar12 = lVar8 + -1;
                                        if (lVar8 + -1 == 0) {
                                          FUN_23a334bc0(plVar12);
                                        }
                                        lVar8 = *plVar14;
                                        *plVar14 = lVar8 + -1;
                                        if (lVar8 + -1 == 0) {
                                          FUN_23a334bc0();
                                        }
                                        if (plVar15 == (longlong *)0x0) {
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          uStack_a8 = 0xa3;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plStack_130 = (longlong *)0x0;
                                          plStack_120 = (longlong *)0x0;
                                          plStack_128 = (longlong *)0x0;
                                          plStack_110 = (longlong *)0x0;
                                          plStack_e8 = (longlong *)0x0;
                                          plStack_f0 = (longlong *)0x0;
                                          plStack_108 = (longlong *)0x0;
                                          plStack_e0 = (longlong *)0x0;
                                          plStack_c8 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          plStack_118 = (longlong *)0x0;
                                          goto LAB_23e2b9c20;
                                        }
                                        lVar8 = *plVar15;
                                        *plVar15 = lVar8 + -1;
                                        if (lVar8 + -1 == 0) {
                                          FUN_23a334bc0(plVar15);
                                        }
                                        lVar1 = _DAT_23eeadb90;
                                        lVar8 = plVar17[2];
                                        *(undefined4 *)(plVar7 + 5) = 0xa6;
                                        plStack_c8 = (longlong *)
                                                     FUN_23e954670(param_1,lVar8,DAT_23eeadb68,
                                                                   lVar1 + 0x18);
                                        if (plStack_c8 == (longlong *)0x0) {
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          uStack_a8 = 0xa6;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plStack_130 = (longlong *)0x0;
                                          plStack_120 = (longlong *)0x0;
                                          plStack_128 = (longlong *)0x0;
                                          plStack_110 = (longlong *)0x0;
                                          plStack_e8 = (longlong *)0x0;
                                          plStack_f0 = (longlong *)0x0;
                                          plStack_108 = (longlong *)0x0;
                                          plStack_118 = (longlong *)0x0;
                                          plStack_e0 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          goto LAB_23e2b9c20;
                                        }
                                        plVar12 = (longlong *)
                                                  FUN_23a388650(param_1,plStack_c8,DAT_23ed6ccf8);
                                        if (plVar12 == (longlong *)0x0) {
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          uStack_a8 = 0xa7;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plStack_130 = (longlong *)0x0;
                                          plStack_120 = (longlong *)0x0;
                                          plStack_128 = (longlong *)0x0;
                                          plStack_110 = (longlong *)0x0;
                                          plStack_e8 = (longlong *)0x0;
                                          plStack_f0 = (longlong *)0x0;
                                          plStack_108 = (longlong *)0x0;
                                          plStack_118 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          plStack_e0 = (longlong *)0x0;
                                          goto LAB_23e2b9c20;
                                        }
                                        cVar5 = FUN_23e8d9ac0(plVar17[2],_DAT_23eeadb98);
                                        lVar8 = *plVar12;
                                        *plVar12 = lVar8 + -1;
                                        if (lVar8 + -1 == 0) {
                                          FUN_23a334bc0();
                                        }
                                        if (cVar5 == '\0') {
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          uStack_a8 = 0xa7;
                                          plStack_130 = (longlong *)0x0;
                                          plStack_120 = (longlong *)0x0;
                                          plStack_128 = (longlong *)0x0;
                                          plStack_110 = (longlong *)0x0;
                                          plStack_e8 = (longlong *)0x0;
                                          plStack_f0 = (longlong *)0x0;
                                          plStack_108 = (longlong *)0x0;
                                          plStack_118 = (longlong *)0x0;
                                          plStack_e0 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          goto LAB_23e2b9c20;
                                        }
                                        plVar12 = (longlong *)
                                                  FUN_23e8bc2f0(plStack_d8,_DAT_23eeadb30);
                                        if (plVar12 == (longlong *)0x0) {
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          uStack_a8 = 0xa8;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plStack_130 = (longlong *)0x0;
                                          plStack_120 = (longlong *)0x0;
                                          plStack_128 = (longlong *)0x0;
                                          plStack_110 = (longlong *)0x0;
                                          plStack_e8 = (longlong *)0x0;
                                          plStack_f0 = (longlong *)0x0;
                                          plStack_108 = (longlong *)0x0;
                                          plStack_e0 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          plStack_118 = (longlong *)0x0;
                                          goto LAB_23e2b9c20;
                                        }
                                        plVar14 = (longlong *)
                                                  FUN_23a388650(param_1,plStack_c8,DAT_23ed6ccf0,0);
                                        if (plVar14 == (longlong *)0x0) {
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          lVar8 = *plVar12;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          *plVar12 = lVar8 + -1;
                                          plStack_e0 = (longlong *)0x0;
                                          if (lVar8 + -1 == 0) {
                                            FUN_23a334bc0();
                                            plStack_130 = (longlong *)0x0;
                                            plStack_120 = (longlong *)0x0;
                                            plStack_128 = (longlong *)0x0;
                                            plStack_110 = (longlong *)0x0;
                                            plStack_e8 = (longlong *)0x0;
                                            plStack_f0 = (longlong *)0x0;
                                            plStack_108 = (longlong *)0x0;
                                            plStack_118 = (longlong *)0x0;
                                            uStack_a8 = 0xa8;
                                          }
                                          else {
                                            uStack_a8 = 0xa8;
                                            plStack_130 = (longlong *)0x0;
                                            plStack_120 = (longlong *)0x0;
                                            plStack_128 = (longlong *)0x0;
                                            plStack_110 = (longlong *)0x0;
                                            plStack_e8 = (longlong *)0x0;
                                            plStack_f0 = (longlong *)0x0;
                                            plStack_108 = (longlong *)0x0;
                                            plStack_118 = (longlong *)0x0;
                                          }
                                          goto LAB_23e2b9c20;
                                        }
                                        *(undefined4 *)(plVar7 + 5) = 0xa8;
                                        plVar15 = (longlong *)FUN_23e914090(param_1,plVar12,plVar14)
                                        ;
                                        lVar8 = *plVar12;
                                        *plVar12 = lVar8 + -1;
                                        if (lVar8 + -1 == 0) {
                                          FUN_23a334bc0(plVar12);
                                        }
                                        lVar8 = *plVar14;
                                        *plVar14 = lVar8 + -1;
                                        if (lVar8 + -1 == 0) {
                                          FUN_23a334bc0(plVar14);
                                        }
                                        if (plVar15 == (longlong *)0x0) {
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          uStack_a8 = 0xa8;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plStack_130 = (longlong *)0x0;
                                          plStack_120 = (longlong *)0x0;
                                          plStack_128 = (longlong *)0x0;
                                          plStack_110 = (longlong *)0x0;
                                          plStack_e8 = (longlong *)0x0;
                                          plStack_f0 = (longlong *)0x0;
                                          plStack_118 = (longlong *)0x0;
                                          plStack_e0 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          plStack_108 = (longlong *)0x0;
                                          goto LAB_23e2b9c20;
                                        }
                                        lVar8 = *plVar15;
                                        *plVar15 = lVar8 + -1;
                                        if (lVar8 + -1 == 0) {
                                          FUN_23a334bc0();
                                        }
                                        lVar1 = _DAT_23eeadba0;
                                        lVar8 = plVar17[2];
                                        *(undefined4 *)(plVar7 + 5) = 0xab;
                                        plStack_e0 = (longlong *)
                                                     FUN_23e954670(param_1,lVar8,DAT_23eeadb68,
                                                                   lVar1 + 0x18);
                                        if (plStack_e0 == (longlong *)0x0) {
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          uStack_a8 = 0xab;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plStack_130 = (longlong *)0x0;
                                          plStack_120 = (longlong *)0x0;
                                          plStack_128 = (longlong *)0x0;
                                          plStack_110 = (longlong *)0x0;
                                          plStack_e8 = (longlong *)0x0;
                                          plStack_f0 = (longlong *)0x0;
                                          plStack_108 = (longlong *)0x0;
                                          plStack_118 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          goto LAB_23e2b9c20;
                                        }
                                        plVar12 = (longlong *)
                                                  FUN_23a388650(param_1,plStack_e0,DAT_23ed6ccf8);
                                        if (plVar12 == (longlong *)0x0) {
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          uStack_a8 = 0xac;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plStack_130 = (longlong *)0x0;
                                          plStack_120 = (longlong *)0x0;
                                          plStack_128 = (longlong *)0x0;
                                          plStack_110 = (longlong *)0x0;
                                          plStack_e8 = (longlong *)0x0;
                                          plStack_f0 = (longlong *)0x0;
                                          plStack_108 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          plStack_118 = (longlong *)0x0;
                                          goto LAB_23e2b9c20;
                                        }
                                        cVar5 = FUN_23e8d9ac0(plVar17[2],_DAT_23eeadba8,plVar12);
                                        lVar8 = *plVar12;
                                        *plVar12 = lVar8 + -1;
                                        if (lVar8 + -1 == 0) {
                                          FUN_23a334bc0();
                                        }
                                        if (cVar5 == '\0') {
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          uStack_a8 = 0xac;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plStack_130 = (longlong *)0x0;
                                          plStack_120 = (longlong *)0x0;
                                          plStack_128 = (longlong *)0x0;
                                          plStack_110 = (longlong *)0x0;
                                          plStack_e8 = (longlong *)0x0;
                                          plStack_f0 = (longlong *)0x0;
                                          plStack_108 = (longlong *)0x0;
                                          plStack_118 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          goto LAB_23e2b9c20;
                                        }
                                        plVar12 = (longlong *)
                                                  FUN_23e8bc2f0(plVar17[2],_DAT_23eeadba8);
                                        if (plVar12 == (longlong *)0x0) {
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          uStack_a8 = 0xad;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plStack_130 = (longlong *)0x0;
                                          plStack_120 = (longlong *)0x0;
                                          plStack_128 = (longlong *)0x0;
                                          plStack_110 = (longlong *)0x0;
                                          plStack_e8 = (longlong *)0x0;
                                          plStack_f0 = (longlong *)0x0;
                                          plStack_108 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          plStack_118 = (longlong *)0x0;
                                          goto LAB_23e2b9c20;
                                        }
                                        plVar14 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23eead9b8);
                                        lVar8 = *plVar12;
                                        *plVar12 = lVar8 + -1;
                                        if (lVar8 + -1 == 0) {
                                          FUN_23a334bc0(plVar12);
                                        }
                                        plVar12 = _DAT_23eeadb48;
                                        if (plVar14 == (longlong *)0x0) {
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          uStack_a8 = 0xad;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plStack_130 = (longlong *)0x0;
                                          plStack_120 = (longlong *)0x0;
                                          plStack_128 = (longlong *)0x0;
                                          plStack_110 = (longlong *)0x0;
                                          plStack_e8 = (longlong *)0x0;
                                          plStack_f0 = (longlong *)0x0;
                                          plStack_118 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          plStack_108 = (longlong *)0x0;
                                          goto LAB_23e2b9c20;
                                        }
                                        plVar15 = (longlong *)
                                                  FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
                                        *plVar12 = *plVar12 + 1;
                                        plVar15[3] = (longlong)plVar12;
                                        lVar8 = FUN_23e8f7100();
                                        if (lVar8 == 0) {
                                          FUN_23e915740(param_1,auStack_78);
                                        }
                                        else {
                                          lVar8 = FUN_23e94f9d0(param_1,lVar8);
                                          if (lVar8 != 0) {
                                            plVar15[4] = lVar8;
                                            plVar12 = _DAT_23eeadbb0;
                                            *_DAT_23eeadbb0 = *_DAT_23eeadbb0 + 1;
                                            plVar15[5] = (longlong)plVar12;
                                            plVar12 = (longlong *)PyUnicode_Join();
                                            *plVar15 = *plVar15 + -1;
                                            if (*plVar15 == 0) {
                                              FUN_23a334bc0();
                                            }
                                            if (plVar12 == (longlong *)0x0) {
                                              plStack_68 = *(longlong **)(param_1 + 0x70);
                                              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              lVar8 = *plVar14;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              *plVar14 = lVar8 + -1;
                                              plStack_118 = (longlong *)0x0;
                                              if (lVar8 + -1 == 0) {
                                                FUN_23a334bc0();
                                                plStack_130 = (longlong *)0x0;
                                                plStack_120 = (longlong *)0x0;
                                                plStack_128 = (longlong *)0x0;
                                                plStack_110 = (longlong *)0x0;
                                                plStack_e8 = (longlong *)0x0;
                                                plStack_f0 = (longlong *)0x0;
                                                plStack_108 = (longlong *)0x0;
                                                uStack_a8 = 0xad;
                                              }
                                              else {
                                                uStack_a8 = 0xad;
                                                plStack_130 = (longlong *)0x0;
                                                plStack_120 = (longlong *)0x0;
                                                plStack_128 = (longlong *)0x0;
                                                plStack_110 = (longlong *)0x0;
                                                plStack_e8 = (longlong *)0x0;
                                                plStack_f0 = (longlong *)0x0;
                                                plStack_108 = (longlong *)0x0;
                                              }
                                              goto LAB_23e2b9c20;
                                            }
                                            *(undefined4 *)(plVar7 + 5) = 0xad;
                                            plVar15 = (longlong *)
                                                      FUN_23e914090(param_1,plVar14,plVar12);
                                            lVar8 = *plVar14;
                                            *plVar14 = lVar8 + -1;
                                            if (lVar8 + -1 == 0) {
                                              FUN_23a334bc0(plVar14);
                                            }
                                            lVar8 = *plVar12;
                                            *plVar12 = lVar8 + -1;
                                            if (lVar8 + -1 == 0) {
                                              FUN_23a334bc0(plVar12);
                                            }
                                            if (plVar15 == (longlong *)0x0) {
                                              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                              plStack_68 = *(longlong **)(param_1 + 0x70);
                                              uStack_a8 = 0xad;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              plStack_130 = (longlong *)0x0;
                                              plStack_120 = (longlong *)0x0;
                                              plStack_128 = (longlong *)0x0;
                                              plStack_110 = (longlong *)0x0;
                                              plStack_e8 = (longlong *)0x0;
                                              plStack_108 = (longlong *)0x0;
                                              plStack_118 = (longlong *)0x0;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              plStack_f0 = (longlong *)0x0;
                                              goto LAB_23e2b9c20;
                                            }
                                            lVar8 = *plVar15;
                                            *plVar15 = lVar8 + -1;
                                            if (lVar8 + -1 == 0) {
                                              FUN_23a334bc0();
                                            }
                                            plVar12 = (longlong *)
                                                      FUN_23e8bc2f0(plStack_d8,_DAT_23eeadb30);
                                            if (plVar12 == (longlong *)0x0) {
                                              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                              plStack_68 = *(longlong **)(param_1 + 0x70);
                                              uStack_a8 = 0xae;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              plStack_130 = (longlong *)0x0;
                                              plStack_120 = (longlong *)0x0;
                                              plStack_128 = (longlong *)0x0;
                                              plStack_110 = (longlong *)0x0;
                                              plStack_e8 = (longlong *)0x0;
                                              plStack_f0 = (longlong *)0x0;
                                              plStack_118 = (longlong *)0x0;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              plStack_108 = (longlong *)0x0;
                                              goto LAB_23e2b9c20;
                                            }
                                            plVar14 = (longlong *)
                                                      FUN_23a388650(param_1,plStack_e0,DAT_23ed6ccf0
                                                                    ,0);
                                            if (plVar14 == (longlong *)0x0) {
                                              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                              plStack_68 = *(longlong **)(param_1 + 0x70);
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              lVar8 = *plVar12;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              *plVar12 = lVar8 + -1;
                                              plStack_118 = (longlong *)0x0;
                                              if (lVar8 + -1 == 0) {
                                                FUN_23a334bc0(plVar12);
                                                uStack_a8 = 0xae;
                                                plStack_130 = (longlong *)0x0;
                                                plStack_120 = (longlong *)0x0;
                                                plStack_128 = (longlong *)0x0;
                                                plStack_110 = (longlong *)0x0;
                                                plStack_e8 = (longlong *)0x0;
                                                plStack_f0 = (longlong *)0x0;
                                                plStack_108 = (longlong *)0x0;
                                              }
                                              else {
                                                uStack_a8 = 0xae;
                                                plStack_130 = (longlong *)0x0;
                                                plStack_120 = (longlong *)0x0;
                                                plStack_128 = (longlong *)0x0;
                                                plStack_110 = (longlong *)0x0;
                                                plStack_e8 = (longlong *)0x0;
                                                plStack_f0 = (longlong *)0x0;
                                                plStack_108 = (longlong *)0x0;
                                              }
                                              goto LAB_23e2b9c20;
                                            }
                                            *(undefined4 *)(plVar7 + 5) = 0xae;
                                            plVar15 = (longlong *)
                                                      FUN_23e914090(param_1,plVar12,plVar14);
                                            lVar8 = *plVar12;
                                            *plVar12 = lVar8 + -1;
                                            if (lVar8 + -1 == 0) {
                                              FUN_23a334bc0(plVar12);
                                            }
                                            lVar8 = *plVar14;
                                            *plVar14 = lVar8 + -1;
                                            if (lVar8 + -1 == 0) {
                                              FUN_23a334bc0();
                                            }
                                            if (plVar15 == (longlong *)0x0) {
                                              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                              plStack_68 = *(longlong **)(param_1 + 0x70);
                                              uStack_a8 = 0xae;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              plStack_130 = (longlong *)0x0;
                                              plStack_120 = (longlong *)0x0;
                                              plStack_128 = (longlong *)0x0;
                                              plStack_110 = (longlong *)0x0;
                                              plStack_e8 = (longlong *)0x0;
                                              plStack_108 = (longlong *)0x0;
                                              plStack_118 = (longlong *)0x0;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              plStack_f0 = (longlong *)0x0;
                                              goto LAB_23e2b9c20;
                                            }
                                            lVar8 = *plVar15;
                                            *plVar15 = lVar8 + -1;
                                            if (lVar8 + -1 == 0) {
                                              FUN_23a334bc0(plVar15);
                                            }
                                            *(undefined4 *)(plVar7 + 5) = 0xb0;
                                            plVar12 = (longlong *)
                                                      FUN_23e915840(param_1,plStack_140,
                                                                    _DAT_23eeada70,plStack_f8);
                                            if (plVar12 == (longlong *)0x0) {
                                              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                              plStack_68 = *(longlong **)(param_1 + 0x70);
                                              uStack_a8 = 0xb0;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              plStack_130 = (longlong *)0x0;
                                              plStack_120 = (longlong *)0x0;
                                              plStack_128 = (longlong *)0x0;
                                              plStack_110 = (longlong *)0x0;
                                              plStack_e8 = (longlong *)0x0;
                                              plStack_f0 = (longlong *)0x0;
                                              plStack_108 = (longlong *)0x0;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              plStack_118 = (longlong *)0x0;
                                              goto LAB_23e2b9c20;
                                            }
                                            lVar8 = *plVar12;
                                            *plVar12 = lVar8 + -1;
                                            if (lVar8 + -1 == 0) {
                                              FUN_23a334bc0();
                                            }
                                            lVar8 = plVar17[2];
                                            *(undefined4 *)(plVar7 + 5) = 0xb3;
                                            plVar12 = (longlong *)
                                                      FUN_23e915840(param_1,lVar8,DAT_23eead9d8);
                                            if (plVar12 == (longlong *)0x0) {
LAB_23e2bf622:
                                              uVar18 = *(undefined8 *)(param_1 + 0x60);
                                              uVar19 = *(undefined8 *)(param_1 + 0x68);
                                              plVar12 = *(longlong **)(param_1 + 0x70);
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                            }
                                            else {
                                              plVar14 = (longlong *)FUN_23a388310(plVar12);
                                              *plVar12 = *plVar12 + -1;
                                              if (*plVar12 == 0) {
                                                FUN_23a334bc0(plVar12);
                                              }
                                              if (plVar14 == (longlong *)0x0) goto LAB_23e2bf622;
                                              plStack_118 = (longlong *)
                                                            FUN_23a3c1d30(param_1,auStack_78,plVar14
                                                                          ,0,CONCAT44(uVar20,2));
                                              if (plStack_118 == (longlong *)0x0) {
                                                *plVar14 = *plVar14 + -1;
                                                plVar12 = plStack_68;
                                                uVar18 = auStack_78._0_8_;
                                                uVar19 = auStack_78._8_8_;
                                                if (*plVar14 == 0) {
                                                  plStack_108 = (longlong *)0x0;
                                                  goto LAB_23e2bf4c9;
                                                }
                                              }
                                              else {
                                                plStack_108 = (longlong *)
                                                              FUN_23a3c1d30(param_1,auStack_78,
                                                                            plVar14,1,2);
                                                if (plStack_108 == (longlong *)0x0) {
                                                  lVar8 = *plVar14;
                                                }
                                                else {
                                                  cVar5 = FUN_23a3884a0(param_1,auStack_78);
                                                  lVar8 = *plVar14;
                                                  if (cVar5 != '\0') {
                                                    *plVar14 = lVar8 + -1;
                                                    if (lVar8 + -1 == 0) {
                                                      FUN_23a334bc0(plVar14);
                                                    }
                                                    if (*plStack_118 == 0) {
                                                      FUN_23a334bc0(plStack_118);
                                                    }
                                                    if (*plStack_108 == 0) {
                                                      FUN_23a334bc0(plStack_108);
                                                    }
                                                    lVar8 = FUN_23e8f6fb0();
                                                    if (lVar8 == 0) {
                                                      FUN_23e915740(param_1,auStack_78);
                                                      uStack_a8 = 0xb6;
                                                      plStack_130 = (longlong *)0x0;
                                                      plStack_120 = (longlong *)0x0;
                                                      plStack_128 = (longlong *)0x0;
                                                      plStack_110 = (longlong *)0x0;
                                                      plStack_e8 = (longlong *)0x0;
                                                      plStack_f0 = (longlong *)0x0;
                                                    }
                                                    else {
                                                      *(undefined4 *)(plVar7 + 5) = 0xb6;
                                                      plStack_f0 = (longlong *)
                                                                   FUN_23e91a870(param_1,lVar8);
                                                      lVar8 = _DAT_23eeada88;
                                                      if (plStack_f0 == (longlong *)0x0) {
                                                        auStack_78 = *(undefined1 (*) [16])
                                                                      (param_1 + 0x60);
                                                        plStack_68 = *(longlong **)(param_1 + 0x70);
                                                        uStack_a8 = 0xb6;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        plStack_130 = (longlong *)0x0;
                                                        plStack_120 = (longlong *)0x0;
                                                        plStack_128 = (longlong *)0x0;
                                                        plStack_110 = (longlong *)0x0;
                                                        plStack_e8 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                      }
                                                      else {
                                                        *(undefined4 *)(plVar7 + 5) = 0xb7;
                                                        plVar12 = (longlong *)
                                                                  FUN_23e915840(param_1,plStack_f0,
                                                                                _DAT_23eead970,
                                                                                *(undefined8 *)
                                                                                 (lVar8 + 0x18));
                                                        if (plVar12 == (longlong *)0x0) {
                                                          auStack_78 = *(undefined1 (*) [16])
                                                                        (param_1 + 0x60);
                                                          plStack_68 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          plStack_130 = (longlong *)0x0;
                                                          plStack_120 = (longlong *)0x0;
                                                          plStack_128 = (longlong *)0x0;
                                                          plStack_110 = (longlong *)0x0;
                                                          uStack_a8 = 0xb7;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          plStack_e8 = (longlong *)0x0;
                                                        }
                                                        else {
                                                          lVar8 = *plVar12;
                                                          *plVar12 = lVar8 + -1;
                                                          if (lVar8 + -1 == 0) {
                                                            FUN_23a334bc0();
                                                          }
                                                          lVar8 = FUN_23e8f6e60();
                                                          if (lVar8 == 0) {
                                                            FUN_23e915740(param_1,auStack_78,
                                                                          DAT_23eead9e8);
                                                            uStack_a8 = 0xb8;
                                                            plStack_130 = (longlong *)0x0;
                                                            plStack_120 = (longlong *)0x0;
                                                            plStack_128 = (longlong *)0x0;
                                                            plStack_110 = (longlong *)0x0;
                                                            plStack_e8 = (longlong *)0x0;
                                                          }
                                                          else {
                                                            *(undefined4 *)(plVar7 + 5) = 0xb8;
                                                            plStack_e8 = (longlong *)
                                                                         FUN_23e94bb80(param_1,lVar8
                                                                                       ,
                                                  _DAT_23eeadbc0);
                                                  lVar8 = _DAT_23eeadbd0;
                                                  if (plStack_e8 == (longlong *)0x0) {
                                                    auStack_78 = *(undefined1 (*) [16])
                                                                  (param_1 + 0x60);
                                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                                    uStack_a8 = 0xb8;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    plStack_130 = (longlong *)0x0;
                                                    plStack_120 = (longlong *)0x0;
                                                    plStack_128 = (longlong *)0x0;
                                                    plStack_110 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  else {
                                                    *(undefined4 *)(plVar7 + 5) = 0xb9;
                                                    plVar12 = (longlong *)
                                                              FUN_23e915840(param_1,plStack_e8,
                                                                            _DAT_23eeadbc8,
                                                                            *(undefined8 *)
                                                                             (lVar8 + 0x18));
                                                    if (plVar12 == (longlong *)0x0) {
                                                      auStack_78 = *(undefined1 (*) [16])
                                                                    (param_1 + 0x60);
                                                      plStack_68 = *(longlong **)(param_1 + 0x70);
                                                      uStack_a8 = 0xb9;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      plStack_130 = (longlong *)0x0;
                                                      plStack_120 = (longlong *)0x0;
                                                      plStack_128 = (longlong *)0x0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      plStack_110 = (longlong *)0x0;
                                                    }
                                                    else {
                                                      lVar8 = *plVar12;
                                                      *plVar12 = lVar8 + -1;
                                                      if (lVar8 + -1 == 0) {
                                                        FUN_23a334bc0(plVar12);
                                                      }
                                                      *(undefined4 *)(plVar7 + 5) = 0xba;
                                                      plVar12 = (longlong *)
                                                                FUN_23e915840(param_1,plStack_e8,
                                                                              _DAT_23eead9b8);
                                                      if (plVar12 == (longlong *)0x0) {
                                                        auStack_78 = *(undefined1 (*) [16])
                                                                      (param_1 + 0x60);
                                                        plStack_68 = *(longlong **)(param_1 + 0x70);
                                                        uStack_a8 = 0xba;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        plStack_130 = (longlong *)0x0;
                                                        plStack_120 = (longlong *)0x0;
                                                        plStack_128 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        plStack_110 = (longlong *)0x0;
                                                      }
                                                      else {
                                                        lVar8 = *plVar12;
                                                        *plVar12 = lVar8 + -1;
                                                        if (lVar8 + -1 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                        lVar8 = FUN_23e8f6d10();
                                                        if (lVar8 == 0) {
                                                          FUN_23e915740(param_1,auStack_78,
                                                                        DAT_23eeadae8);
                                                          uStack_a8 = 0xbb;
                                                          plStack_130 = (longlong *)0x0;
                                                          plStack_120 = (longlong *)0x0;
                                                          plStack_128 = (longlong *)0x0;
                                                          plStack_110 = (longlong *)0x0;
                                                        }
                                                        else {
                                                          *(undefined4 *)(plVar7 + 5) = 0xbb;
                                                          plStack_110 = (longlong *)
                                                                        FUN_23e94bb80(param_1,lVar8,
                                                                                      _DAT_23eeadbe0
                                                                                     );
                                                          if (plStack_110 == (longlong *)0x0) {
                                                            auStack_78 = *(undefined1 (*) [16])
                                                                          (param_1 + 0x60);
                                                            plStack_68 = *(longlong **)
                                                                          (param_1 + 0x70);
                                                            uStack_a8 = 0xbb;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            plStack_130 = (longlong *)0x0;
                                                            plStack_120 = (longlong *)0x0;
                                                            plStack_128 = (longlong *)0x0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                          }
                                                          else {
                                                            plVar12 = (longlong *)
                                                                      FUN_23e8bc2f0(plStack_110,
                                                                                    _DAT_23eead9b8);
                                                            if (plVar12 == (longlong *)0x0) {
                                                              auStack_78 = *(undefined1 (*) [16])
                                                                            (param_1 + 0x60);
                                                              plStack_68 = *(longlong **)
                                                                            (param_1 + 0x70);
                                                              uStack_a8 = 0xbc;
                                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                                              plStack_130 = (longlong *)0x0;
                                                              plStack_128 = (longlong *)0x0;
                                                              *(undefined1 (*) [16])(param_1 + 0x60)
                                                                   = (undefined1  [16])0x0;
                                                              plStack_120 = (longlong *)0x0;
                                                            }
                                                            else {
                                                              lVar8 = plVar17[2];
                                                              *(undefined4 *)(plVar7 + 5) = 0xbc;
                                                              plVar14 = (longlong *)
                                                                        FUN_23e91bfe0(param_1,lVar8)
                                                              ;
                                                              if (plVar14 == (longlong *)0x0) {
                                                                auStack_78 = *(undefined1 (*) [16])
                                                                              (param_1 + 0x60);
                                                                plStack_68 = *(longlong **)
                                                                              (param_1 + 0x70);
                                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                                lVar8 = *plVar12;
                                                                *(undefined1 (*) [16])
                                                                 (param_1 + 0x60) =
                                                                     (undefined1  [16])0x0;
                                                                *plVar12 = lVar8 + -1;
                                                                plStack_128 = (longlong *)0x0;
                                                                if (lVar8 + -1 == 0) {
                                                                  FUN_23a334bc0(plVar12);
                                                                  uStack_a8 = 0xbc;
                                                                  plStack_130 = (longlong *)0x0;
                                                                  plStack_120 = (longlong *)0x0;
                                                                }
                                                                else {
                                                                  uStack_a8 = 0xbc;
                                                                  plStack_130 = (longlong *)0x0;
                                                                  plStack_120 = (longlong *)0x0;
                                                                }
                                                              }
                                                              else {
                                                                *(undefined4 *)(plVar7 + 5) = 0xbc;
                                                                plVar15 = (longlong *)
                                                                          FUN_23e914090(param_1,
                                                  plVar12);
                                                  lVar8 = *plVar12;
                                                  *plVar12 = lVar8 + -1;
                                                  if (lVar8 + -1 == 0) {
                                                    FUN_23a334bc0(plVar12);
                                                  }
                                                  lVar8 = *plVar14;
                                                  *plVar14 = lVar8 + -1;
                                                  if (lVar8 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  if (plVar15 == (longlong *)0x0) {
                                                    auStack_78 = *(undefined1 (*) [16])
                                                                  (param_1 + 0x60);
                                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                                    uStack_a8 = 0xbc;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    plStack_120 = (longlong *)0x0;
                                                    plStack_128 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plStack_130 = (longlong *)0x0;
                                                  }
                                                  else {
                                                    lVar8 = *plVar15;
                                                    *plVar15 = lVar8 + -1;
                                                    if (lVar8 + -1 == 0) {
                                                      FUN_23a334bc0(plVar15);
                                                    }
                                                    plVar12 = (longlong *)FUN_23e8bc2f0(plStack_110)
                                                    ;
                                                    if (plVar12 == (longlong *)0x0) {
                                                      auStack_78 = *(undefined1 (*) [16])
                                                                    (param_1 + 0x60);
                                                      plStack_68 = *(longlong **)(param_1 + 0x70);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      plStack_120 = (longlong *)0x0;
                                                      plStack_128 = (longlong *)0x0;
                                                      uStack_a8 = 0xbd;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      plStack_130 = (longlong *)0x0;
                                                    }
                                                    else {
                                                      lVar8 = FUN_23e8f6bc0();
                                                      if (lVar8 == 0) {
                                                        FUN_23e915740(param_1,auStack_78,
                                                                      DAT_23eeada08);
                                                        lVar8 = *plVar12;
                                                        *plVar12 = lVar8 + -1;
                                                        plStack_128 = (longlong *)0x0;
                                                        if (lVar8 + -1 == 0) {
                                                          FUN_23a334bc0(plVar12);
                                                          uStack_a8 = 0xbd;
                                                          plStack_130 = (longlong *)0x0;
                                                          plStack_120 = (longlong *)0x0;
                                                        }
                                                        else {
                                                          uStack_a8 = 0xbd;
                                                          plStack_130 = (longlong *)0x0;
                                                          plStack_120 = (longlong *)0x0;
                                                        }
                                                      }
                                                      else {
                                                        plVar14 = (longlong *)
                                                                  FUN_23e8bc2f0(lVar8,_DAT_23eeadbf8
                                                                               );
                                                        if (plVar14 == (longlong *)0x0) {
                                                          auStack_78 = *(undefined1 (*) [16])
                                                                        (param_1 + 0x60);
                                                          plStack_68 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          lVar8 = *plVar12;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          *plVar12 = lVar8 + -1;
                                                          plStack_128 = (longlong *)0x0;
                                                          if (lVar8 + -1 == 0) {
                                                            FUN_23a334bc0();
                                                            uStack_a8 = 0xbd;
                                                            plStack_130 = (longlong *)0x0;
                                                            plStack_120 = (longlong *)0x0;
                                                          }
                                                          else {
                                                            uStack_a8 = 0xbd;
                                                            plStack_130 = (longlong *)0x0;
                                                            plStack_120 = (longlong *)0x0;
                                                          }
                                                        }
                                                        else {
                                                          plVar15 = (longlong *)
                                                                    FUN_23e8bc2f0(plVar14,
                                                  _DAT_23eeadc00);
                                                  lVar8 = *plVar14;
                                                  *plVar14 = lVar8 + -1;
                                                  if (lVar8 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  if (plVar15 == (longlong *)0x0) {
                                                    auStack_78 = *(undefined1 (*) [16])
                                                                  (param_1 + 0x60);
                                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    lVar8 = *plVar12;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *plVar12 = lVar8 + -1;
                                                    plStack_120 = (longlong *)0x0;
                                                    if (lVar8 + -1 == 0) {
                                                      FUN_23a334bc0(plVar12);
                                                      plStack_130 = (longlong *)0x0;
                                                      uStack_a8 = 0xbd;
                                                      plStack_128 = (longlong *)0x0;
                                                    }
                                                    else {
                                                      uStack_a8 = 0xbd;
                                                      plStack_130 = (longlong *)0x0;
                                                      plStack_128 = (longlong *)0x0;
                                                    }
                                                  }
                                                  else {
                                                    *(undefined4 *)(plVar7 + 5) = 0xbd;
                                                    plVar14 = (longlong *)
                                                              FUN_23e914090(param_1,plVar12);
                                                    lVar8 = *plVar12;
                                                    *plVar12 = lVar8 + -1;
                                                    if (lVar8 + -1 == 0) {
                                                      FUN_23a334bc0(plVar12);
                                                    }
                                                    lVar8 = *plVar15;
                                                    *plVar15 = lVar8 + -1;
                                                    if (lVar8 + -1 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    if (plVar14 == (longlong *)0x0) {
                                                      auStack_78 = *(undefined1 (*) [16])
                                                                    (param_1 + 0x60);
                                                      plStack_68 = *(longlong **)(param_1 + 0x70);
                                                      uStack_a8 = 0xbd;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      plStack_130 = (longlong *)0x0;
                                                      plStack_120 = (longlong *)0x0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      plStack_128 = (longlong *)0x0;
                                                    }
                                                    else {
                                                      lVar8 = *plVar14;
                                                      *plVar14 = lVar8 + -1;
                                                      if (lVar8 + -1 == 0) {
                                                        FUN_23a334bc0(plVar14);
                                                      }
                                                      plVar12 = (longlong *)
                                                                FUN_23e8bc2f0(plStack_110,
                                                                              _DAT_23eeadb20);
                                                      uVar18 = _DAT_23eeadc08;
                                                      if (plVar12 != (longlong *)0x0) {
                                                        *plVar17 = *plVar17 + 1;
                                                        plStack_88 = plVar17;
                                                        plVar14 = (longlong *)
                                                                  FUN_23e93e1e0(FUN_23e2c2b70,uVar18
                                                                                ,_DAT_23eeadc10,
                                                                                _DAT_23eeb0358,0,0,
                                                                                DAT_23eeb0380,0,
                                                                                &plStack_88,1);
                                                        *(undefined4 *)(plVar7 + 5) = 0xbe;
                                                        plVar15 = (longlong *)
                                                                  FUN_23e915840(param_1,plVar12,
                                                                                _DAT_23eead928,
                                                                                plVar14);
                                                        *plVar12 = *plVar12 + -1;
                                                        if (*plVar12 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                        *plVar14 = *plVar14 + -1;
                                                        if (*plVar14 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                        if (plVar15 != (longlong *)0x0) {
                                                          *plVar15 = *plVar15 + -1;
                                                          if (*plVar15 == 0) {
                                                            FUN_23a334bc0(plVar15);
                                                          }
                                                          *(undefined4 *)(plVar7 + 5) = 0xbf;
                                                          plVar12 = (longlong *)
                                                                    FUN_23e915840(param_1,plStack_f0
                                                                                  ,_DAT_23eeada70,
                                                                                  plStack_e8);
                                                          if (plVar12 == (longlong *)0x0) {
                                                            auStack_78 = *(undefined1 (*) [16])
                                                                          (param_1 + 0x60);
                                                            plStack_68 = *(longlong **)
                                                                          (param_1 + 0x70);
                                                            uStack_a8 = 0xbf;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            plStack_130 = (longlong *)0x0;
                                                            plStack_120 = (longlong *)0x0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            plStack_128 = (longlong *)0x0;
                                                          }
                                                          else {
                                                            lVar8 = *plVar12;
                                                            *plVar12 = lVar8 + -1;
                                                            if (lVar8 + -1 == 0) {
                                                              FUN_23a334bc0();
                                                            }
                                                            *(undefined4 *)(plVar7 + 5) = 0xc0;
                                                            plVar12 = (longlong *)
                                                                      FUN_23e915840(param_1,
                                                  plStack_f0,_DAT_23eeada70,plStack_110);
                                                  if (plVar12 == (longlong *)0x0) {
                                                    auStack_78 = *(undefined1 (*) [16])
                                                                  (param_1 + 0x60);
                                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                                    uStack_a8 = 0xc0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    plStack_130 = (longlong *)0x0;
                                                    plStack_120 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plStack_128 = (longlong *)0x0;
                                                  }
                                                  else {
                                                    lVar8 = *plVar12;
                                                    *plVar12 = lVar8 + -1;
                                                    if (lVar8 + -1 == 0) {
                                                      FUN_23a334bc0(plVar12);
                                                    }
                                                    *(undefined4 *)(plVar7 + 5) = 0xc1;
                                                    plVar12 = (longlong *)
                                                              FUN_23e91bfe0(param_1,plStack_f0,
                                                                            _DAT_23eeadc18);
                                                    if (plVar12 == (longlong *)0x0) {
                                                      auStack_78 = *(undefined1 (*) [16])
                                                                    (param_1 + 0x60);
                                                      plStack_68 = *(longlong **)(param_1 + 0x70);
                                                      uStack_a8 = 0xc1;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      plStack_130 = (longlong *)0x0;
                                                      plStack_120 = (longlong *)0x0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      plStack_128 = (longlong *)0x0;
                                                    }
                                                    else {
                                                      lVar8 = *plVar12;
                                                      *plVar12 = lVar8 + -1;
                                                      if (lVar8 + -1 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      *(undefined4 *)(plVar7 + 5) = 0xc2;
                                                      plVar12 = (longlong *)
                                                                FUN_23e915840(param_1,plStack_108,
                                                                              _DAT_23eeadb30,
                                                                              plStack_f0);
                                                      if (plVar12 == (longlong *)0x0) {
                                                        auStack_78 = *(undefined1 (*) [16])
                                                                      (param_1 + 0x60);
                                                        plStack_68 = *(longlong **)(param_1 + 0x70);
                                                        uStack_a8 = 0xc2;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        plStack_130 = (longlong *)0x0;
                                                        plStack_120 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        plStack_128 = (longlong *)0x0;
                                                      }
                                                      else {
                                                        lVar8 = *plVar12;
                                                        *plVar12 = lVar8 + -1;
                                                        if (lVar8 + -1 == 0) {
                                                          FUN_23a334bc0(plVar12);
                                                        }
                                                        lVar8 = FUN_23e8f6fb0();
                                                        if (lVar8 == 0) {
                                                          FUN_23e915740(param_1,auStack_78,
                                                                        DAT_23eeada80);
                                                          plStack_130 = (longlong *)0x0;
                                                          uStack_a8 = 0xc5;
                                                          plStack_120 = (longlong *)0x0;
                                                          plStack_128 = (longlong *)0x0;
                                                        }
                                                        else {
                                                          *(undefined4 *)(plVar7 + 5) = 0xc5;
                                                          plStack_128 = (longlong *)
                                                                        FUN_23e91a870(param_1,lVar8)
                                                          ;
                                                          if (plStack_128 == (longlong *)0x0) {
                                                            auStack_78 = *(undefined1 (*) [16])
                                                                          (param_1 + 0x60);
                                                            plStack_68 = *(longlong **)
                                                                          (param_1 + 0x70);
                                                            uStack_a8 = 0xc5;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            plStack_130 = (longlong *)0x0;
                                                            plStack_120 = (longlong *)0x0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                          }
                                                          else {
                                                            *(undefined4 *)(plVar7 + 5) = 0xc6;
                                                            plVar12 = (longlong *)
                                                                      FUN_23e915840(param_1,
                                                  plStack_128,_DAT_23eead970);
                                                  if (plVar12 == (longlong *)0x0) {
                                                    auStack_78 = *(undefined1 (*) [16])
                                                                  (param_1 + 0x60);
                                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                                    uStack_a8 = 0xc6;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    plStack_130 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plStack_120 = (longlong *)0x0;
                                                  }
                                                  else {
                                                    lVar8 = *plVar12;
                                                    *plVar12 = lVar8 + -1;
                                                    if (lVar8 + -1 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    lVar8 = FUN_23e8f6e60();
                                                    if (lVar8 == 0) {
                                                      FUN_23e915740(param_1,auStack_78);
                                                      uStack_a8 = 199;
                                                      plStack_130 = (longlong *)0x0;
                                                      plStack_120 = (longlong *)0x0;
                                                    }
                                                    else {
                                                      *(undefined4 *)(plVar7 + 5) = 199;
                                                      plStack_120 = (longlong *)
                                                                    FUN_23e94bb80(param_1,lVar8,
                                                                                  _DAT_23eeadc20);
                                                      lVar8 = _DAT_23eeadbd0;
                                                      if (plStack_120 == (longlong *)0x0) {
                                                        auStack_78 = *(undefined1 (*) [16])
                                                                      (param_1 + 0x60);
                                                        plStack_68 = *(longlong **)(param_1 + 0x70);
                                                        uStack_a8 = 199;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        plStack_130 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                      }
                                                      else {
                                                        *(undefined4 *)(plVar7 + 5) = 200;
                                                        plVar12 = (longlong *)
                                                                  FUN_23e915840(param_1,plStack_120,
                                                                                _DAT_23eeadbc8,
                                                                                *(undefined8 *)
                                                                                 (lVar8 + 0x18));
                                                        if (plVar12 == (longlong *)0x0) {
                                                          auStack_78 = *(undefined1 (*) [16])
                                                                        (param_1 + 0x60);
                                                          plStack_68 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          uStack_a8 = 200;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          plStack_130 = (longlong *)0x0;
                                                        }
                                                        else {
                                                          lVar8 = *plVar12;
                                                          *plVar12 = lVar8 + -1;
                                                          if (lVar8 + -1 == 0) {
                                                            FUN_23a334bc0(plVar12);
                                                          }
                                                          lVar8 = _DAT_23eeadbd8;
                                                          *(undefined4 *)(plVar7 + 5) = 0xc9;
                                                          plVar12 = (longlong *)
                                                                    FUN_23e915840(param_1,
                                                  plStack_120,_DAT_23eead9b8,
                                                  *(undefined8 *)(lVar8 + 0x18));
                                                  if (plVar12 == (longlong *)0x0) {
                                                    auStack_78 = *(undefined1 (*) [16])
                                                                  (param_1 + 0x60);
                                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                                    uStack_a8 = 0xc9;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plStack_130 = (longlong *)0x0;
                                                  }
                                                  else {
                                                    lVar8 = *plVar12;
                                                    *plVar12 = lVar8 + -1;
                                                    if (lVar8 + -1 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    lVar8 = FUN_23e8f6d10();
                                                    if (lVar8 == 0) {
                                                      FUN_23e915740(param_1,auStack_78,DAT_23eeadae8
                                                                   );
                                                      uStack_a8 = 0xca;
                                                      plStack_130 = (longlong *)0x0;
                                                    }
                                                    else {
                                                      *(undefined4 *)(plVar7 + 5) = 0xca;
                                                      plStack_130 = (longlong *)
                                                                    FUN_23e94bb80(param_1,lVar8,
                                                                                  _DAT_23eeadc28);
                                                      if (plStack_130 == (longlong *)0x0) {
                                                        auStack_78 = *(undefined1 (*) [16])
                                                                      (param_1 + 0x60);
                                                        plStack_68 = *(longlong **)(param_1 + 0x70);
                                                        uStack_a8 = 0xca;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                      }
                                                      else {
                                                        plVar12 = (longlong *)
                                                                  FUN_23e8bc2f0(plStack_130,
                                                                                _DAT_23eead9b8);
                                                        if (plVar12 == (longlong *)0x0) {
                                                          auStack_78 = *(undefined1 (*) [16])
                                                                        (param_1 + 0x60);
                                                          plStack_68 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                          uStack_a8 = 0xcb;
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                        }
                                                        else {
                                                          lVar8 = plVar17[2];
                                                          *(undefined4 *)(plVar7 + 5) = 0xcb;
                                                          plVar14 = (longlong *)
                                                                    FUN_23e91bfe0(param_1,lVar8,
                                                                                  DAT_23eeadbe8);
                                                          if (plVar14 == (longlong *)0x0) {
                                                            auStack_78 = *(undefined1 (*) [16])
                                                                          (param_1 + 0x60);
                                                            plStack_68 = *(longlong **)
                                                                          (param_1 + 0x70);
                                                            uStack_a8 = 0xcb;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            *plVar12 = *plVar12 + -1;
                                                            if (*plVar12 == 0) {
                                                              FUN_23a334bc0(plVar12,0xcb,0);
                                                              uStack_a8 = 0xcb;
                                                            }
                                                          }
                                                          else {
                                                            *(undefined4 *)(plVar7 + 5) = 0xcb;
                                                            plVar15 = (longlong *)
                                                                      FUN_23e914090(param_1,plVar12)
                                                            ;
                                                            *plVar12 = *plVar12 + -1;
                                                            if (*plVar12 == 0) {
                                                              FUN_23a334bc0(plVar12);
                                                            }
                                                            *plVar14 = *plVar14 + -1;
                                                            if (*plVar14 == 0) {
                                                              FUN_23a334bc0(plVar14);
                                                            }
                                                            if (plVar15 == (longlong *)0x0) {
                                                              auStack_78 = *(undefined1 (*) [16])
                                                                            (param_1 + 0x60);
                                                              plStack_68 = *(longlong **)
                                                                            (param_1 + 0x70);
                                                              uStack_a8 = 0xcb;
                                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                                              *(undefined1 (*) [16])(param_1 + 0x60)
                                                                   = (undefined1  [16])0x0;
                                                            }
                                                            else {
                                                              *plVar15 = *plVar15 + -1;
                                                              if (*plVar15 == 0) {
                                                                FUN_23a334bc0(plVar15);
                                                              }
                                                              plVar12 = (longlong *)
                                                                        FUN_23e8bc2f0(plStack_130,
                                                                                      _DAT_23eeadbf0
                                                                                     );
                                                              if (plVar12 == (longlong *)0x0) {
                                                                auStack_78 = *(undefined1 (*) [16])
                                                                              (param_1 + 0x60);
                                                                plStack_68 = *(longlong **)
                                                                              (param_1 + 0x70);
                                                                uStack_a8 = 0xcc;
                                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                                *(undefined1 (*) [16])
                                                                 (param_1 + 0x60) =
                                                                     (undefined1  [16])0x0;
                                                              }
                                                              else {
                                                                lVar8 = FUN_23e8f6bc0();
                                                                if (lVar8 == 0) {
                                                                  FUN_23e915740(param_1,auStack_78,
                                                                                DAT_23eeada08);
                                                                  *plVar12 = *plVar12 + -1;
                                                                  if (*plVar12 == 0) {
                                                                    FUN_23a334bc0(plVar12);
                                                                    uStack_a8 = 0xcc;
                                                                  }
                                                                  else {
                                                                    uStack_a8 = 0xcc;
                                                                  }
                                                                }
                                                                else {
                                                                  plVar14 = (longlong *)
                                                                            FUN_23e8bc2f0(lVar8,
                                                  _DAT_23eeadbf8);
                                                  if (plVar14 == (longlong *)0x0) {
                                                    auStack_78 = *(undefined1 (*) [16])
                                                                  (param_1 + 0x60);
                                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                                    uStack_a8 = 0xcc;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *plVar12 = *plVar12 + -1;
                                                    if (*plVar12 == 0) {
                                                      FUN_23a334bc0(plVar12);
                                                      uStack_a8 = 0xcc;
                                                    }
                                                  }
                                                  else {
                                                    plVar15 = (longlong *)
                                                              FUN_23e8bc2f0(plVar14,_DAT_23eeadc00);
                                                    *plVar14 = *plVar14 + -1;
                                                    if (*plVar14 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    if (plVar15 == (longlong *)0x0) {
                                                      auStack_78 = *(undefined1 (*) [16])
                                                                    (param_1 + 0x60);
                                                      plStack_68 = *(longlong **)(param_1 + 0x70);
                                                      uStack_a8 = 0xcc;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *plVar12 = *plVar12 + -1;
                                                      if (*plVar12 == 0) {
                                                        FUN_23a334bc0(plVar12);
                                                        uStack_a8 = 0xcc;
                                                      }
                                                    }
                                                    else {
                                                      *(undefined4 *)(plVar7 + 5) = 0xcc;
                                                      plVar14 = (longlong *)
                                                                FUN_23e914090(param_1,plVar12,
                                                                              plVar15);
                                                      *plVar12 = *plVar12 + -1;
                                                      if (*plVar12 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      *plVar15 = *plVar15 + -1;
                                                      if (*plVar15 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      if (plVar14 == (longlong *)0x0) {
                                                        auStack_78 = *(undefined1 (*) [16])
                                                                      (param_1 + 0x60);
                                                        plStack_68 = *(longlong **)(param_1 + 0x70);
                                                        uStack_a8 = 0xcc;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                      }
                                                      else {
                                                        *plVar14 = *plVar14 + -1;
                                                        if (*plVar14 == 0) {
                                                          FUN_23a334bc0(plVar14);
                                                        }
                                                        plVar12 = (longlong *)
                                                                  FUN_23e8bc2f0(plStack_130);
                                                        uVar18 = _DAT_23eeb0360;
                                                        if (plVar12 != (longlong *)0x0) {
                                                          *plVar17 = *plVar17 + 1;
                                                          plStack_88 = plVar17;
                                                          plVar14 = (longlong *)
                                                                    FUN_23e93e1e0(FUN_23e2c3050,
                                                                                  _DAT_23eeadc08,
                                                                                  _DAT_23eeadc10,
                                                                                  uVar18,0,0,
                                                                                  DAT_23eeb0380,0,
                                                                                  &plStack_88,1);
                                                          *(undefined4 *)(plVar7 + 5) = 0xcd;
                                                          plVar15 = (longlong *)
                                                                    FUN_23e915840(param_1,plVar12,
                                                                                  _DAT_23eead928,
                                                                                  plVar14);
                                                          *plVar12 = *plVar12 + -1;
                                                          if (*plVar12 == 0) {
                                                            FUN_23a334bc0(plVar12);
                                                          }
                                                          *plVar14 = *plVar14 + -1;
                                                          if (*plVar14 == 0) {
                                                            FUN_23a334bc0(plVar14);
                                                          }
                                                          if (plVar15 != (longlong *)0x0) {
                                                            *plVar15 = *plVar15 + -1;
                                                            if (*plVar15 == 0) {
                                                              FUN_23a334bc0(plVar15);
                                                            }
                                                            *(undefined4 *)(plVar7 + 5) = 0xce;
                                                            plVar12 = (longlong *)
                                                                      FUN_23e915840(param_1,
                                                  plStack_128,_DAT_23eeada70,plStack_120);
                                                  if (plVar12 == (longlong *)0x0) {
                                                    auStack_78 = *(undefined1 (*) [16])
                                                                  (param_1 + 0x60);
                                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                                    uStack_a8 = 0xce;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  else {
                                                    *plVar12 = *plVar12 + -1;
                                                    if (*plVar12 == 0) {
                                                      FUN_23a334bc0(plVar12);
                                                    }
                                                    *(undefined4 *)(plVar7 + 5) = 0xcf;
                                                    plVar12 = (longlong *)
                                                              FUN_23e915840(param_1,plStack_128,
                                                                            _DAT_23eeada70,
                                                                            plStack_130);
                                                    if (plVar12 == (longlong *)0x0) {
                                                      auStack_78 = *(undefined1 (*) [16])
                                                                    (param_1 + 0x60);
                                                      plStack_68 = *(longlong **)(param_1 + 0x70);
                                                      uStack_a8 = 0xcf;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                    }
                                                    else {
                                                      *plVar12 = *plVar12 + -1;
                                                      if (*plVar12 == 0) {
                                                        FUN_23a334bc0(plVar12);
                                                      }
                                                      *(undefined4 *)(plVar7 + 5) = 0xd0;
                                                      plVar12 = (longlong *)
                                                                FUN_23e91bfe0(param_1,plStack_128,
                                                                              _DAT_23eeadc18);
                                                      if (plVar12 == (longlong *)0x0) {
                                                        auStack_78 = *(undefined1 (*) [16])
                                                                      (param_1 + 0x60);
                                                        plStack_68 = *(longlong **)(param_1 + 0x70);
                                                        uStack_a8 = 0xd0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                      }
                                                      else {
                                                        *plVar12 = *plVar12 + -1;
                                                        if (*plVar12 == 0) {
                                                          FUN_23a334bc0(plVar12);
                                                        }
                                                        *(undefined4 *)(plVar7 + 5) = 0xd1;
                                                        plVar12 = (longlong *)
                                                                  FUN_23e915840(param_1,plStack_108,
                                                                                _DAT_23eeadb30,
                                                                                plStack_128);
                                                        if (plVar12 == (longlong *)0x0) {
                                                          auStack_78 = *(undefined1 (*) [16])
                                                                        (param_1 + 0x60);
                                                          plStack_68 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                          uStack_a8 = 0xd1;
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                        }
                                                        else {
                                                          *plVar12 = *plVar12 + -1;
                                                          if (*plVar12 == 0) {
                                                            FUN_23a334bc0(plVar12);
                                                          }
                                                          *(undefined4 *)(plVar7 + 5) = 0xd3;
                                                          plVar12 = (longlong *)
                                                                    FUN_23e915840(param_1,
                                                  plStack_140,_DAT_23eeada70);
                                                  if (plVar12 == (longlong *)0x0) {
                                                    auStack_78 = *(undefined1 (*) [16])
                                                                  (param_1 + 0x60);
                                                    plStack_68 = *(longlong **)(param_1 + 0x70);
                                                    uStack_a8 = 0xd3;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  else {
                                                    *plVar12 = *plVar12 + -1;
                                                    if (*plVar12 == 0) {
                                                      FUN_23a334bc0(plVar12);
                                                    }
                                                    *(undefined4 *)(plVar7 + 5) = 0xd6;
                                                    plVar12 = (longlong *)
                                                              FUN_23e91bfe0(param_1,plStack_140,
                                                                            _DAT_23eeadc18);
                                                    if (plVar12 == (longlong *)0x0) {
                                                      auStack_78 = *(undefined1 (*) [16])
                                                                    (param_1 + 0x60);
                                                      plStack_68 = *(longlong **)(param_1 + 0x70);
                                                      uStack_a8 = 0xd6;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                    }
                                                    else {
                                                      *plVar12 = *plVar12 + -1;
                                                      if (*plVar12 == 0) {
                                                        FUN_23a334bc0(plVar12);
                                                      }
                                                      uVar18 = _DAT_23eeadc30;
                                                      *(undefined4 *)(plVar7 + 5) = 0xd8;
                                                      plVar12 = (longlong *)
                                                                FUN_23e915840(param_1,plVar10,uVar18
                                                                              ,plVar11);
                                                      if (plVar12 == (longlong *)0x0) {
                                                        auStack_78 = *(undefined1 (*) [16])
                                                                      (param_1 + 0x60);
                                                        plStack_68 = *(longlong **)(param_1 + 0x70);
                                                        uStack_a8 = 0xd8;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                      }
                                                      else {
                                                        *plVar12 = *plVar12 + -1;
                                                        if (*plVar12 == 0) {
                                                          FUN_23a334bc0(plVar12);
                                                        }
                                                        uVar18 = _DAT_23eeada70;
                                                        *(undefined4 *)(plVar7 + 5) = 0xd9;
                                                        plVar12 = (longlong *)
                                                                  FUN_23e915840(param_1,plVar9,
                                                                                uVar18,plVar10);
                                                        if (plVar12 != (longlong *)0x0) {
                                                          *plVar12 = *plVar12 + -1;
                                                          if (*plVar12 == 0) {
                                                            FUN_23a334bc0();
                                                          }
                                                          FUN_23ebf6b20(*(undefined8 *)
                                                                         (param_1 + 0x38));
                                                          pcVar3 = _Py_NoneStruct_exref;
                                                          *(longlong *)_Py_NoneStruct_exref =
                                                               *(longlong *)_Py_NoneStruct_exref + 1
                                                          ;
                                                          *plVar17 = *plVar17 + -1;
                                                          if (*plVar17 == 0) {
                                                            FUN_23a334bc0(plVar17);
                                                          }
                                                          *plVar9 = *plVar9 + -1;
                                                          if (*plVar9 == 0) {
                                                            FUN_23a334bc0(plVar9);
                                                          }
                                                          *plVar10 = *plVar10 + -1;
                                                          if (*plVar10 == 0) {
                                                            FUN_23a334bc0(plVar10);
                                                          }
                                                          *plVar11 = *plVar11 + -1;
                                                          if (*plVar11 == 0) {
                                                            FUN_23a334bc0(plVar11);
                                                          }
                                                          lVar8 = *plStack_140;
                                                          *plStack_140 = lVar8 + -1;
                                                          if (lVar8 + -1 == 0) {
                                                            FUN_23a334bc0(plStack_140);
                                                          }
                                                          *plVar13 = *plVar13 + -1;
                                                          if (*plVar13 == 0) {
                                                            FUN_23a334bc0(plVar13);
                                                          }
                                                          lVar8 = *plStack_c0;
                                                          *plStack_c0 = lVar8 + -1;
                                                          if (lVar8 + -1 == 0) {
                                                            FUN_23a334bc0(plStack_c0);
                                                          }
                                                          lVar8 = *plStack_138;
                                                          *plStack_138 = lVar8 + -1;
                                                          if (lVar8 + -1 == 0) {
                                                            FUN_23a334bc0(plStack_138);
                                                          }
                                                          lVar8 = *plStack_100;
                                                          *plStack_100 = lVar8 + -1;
                                                          if (lVar8 + -1 == 0) {
                                                            FUN_23a334bc0(plStack_100);
                                                          }
                                                          lVar8 = *plStack_b0;
                                                          *plStack_b0 = lVar8 + -1;
                                                          if (lVar8 + -1 == 0) {
                                                            FUN_23a334bc0(plStack_b0);
                                                          }
                                                          lVar8 = *plStack_f8;
                                                          *plStack_f8 = lVar8 + -1;
                                                          if (lVar8 + -1 == 0) {
                                                            FUN_23a334bc0(plStack_f8);
                                                          }
                                                          lVar8 = *plStack_d8;
                                                          *plStack_d8 = lVar8 + -1;
                                                          if (lVar8 + -1 == 0) {
                                                            FUN_23a334bc0(plStack_d8);
                                                          }
                                                          lVar8 = *plStack_d0;
                                                          *plStack_d0 = lVar8 + -1;
                                                          if (lVar8 + -1 == 0) {
                                                            FUN_23a334bc0(plStack_d0);
                                                          }
                                                          lVar8 = *plStack_b8;
                                                          *plStack_b8 = lVar8 + -1;
                                                          if (lVar8 + -1 == 0) {
                                                            FUN_23a334bc0(plStack_b8);
                                                          }
                                                          lVar8 = *plStack_c8;
                                                          *plStack_c8 = lVar8 + -1;
                                                          if (lVar8 + -1 == 0) {
                                                            FUN_23a334bc0(plStack_c8);
                                                          }
                                                          lVar8 = *plStack_e0;
                                                          *plStack_e0 = lVar8 + -1;
                                                          if (lVar8 + -1 == 0) {
                                                            FUN_23a334bc0(plStack_e0);
                                                          }
                                                          lVar8 = *plStack_118;
                                                          *plStack_118 = lVar8 + -1;
                                                          if (lVar8 + -1 == 0) {
                                                            FUN_23a334bc0(plStack_118);
                                                          }
                                                          lVar8 = *plStack_108;
                                                          *plStack_108 = lVar8 + -1;
                                                          if (lVar8 + -1 == 0) {
                                                            FUN_23a334bc0(plStack_108);
                                                          }
                                                          lVar8 = *plStack_f0;
                                                          *plStack_f0 = lVar8 + -1;
                                                          if (lVar8 + -1 == 0) {
                                                            FUN_23a334bc0(plStack_f0);
                                                          }
                                                          lVar8 = *plStack_e8;
                                                          *plStack_e8 = lVar8 + -1;
                                                          if (lVar8 + -1 == 0) {
                                                            FUN_23a334bc0(plStack_e8);
                                                          }
                                                          lVar8 = *plStack_110;
                                                          *plStack_110 = lVar8 + -1;
                                                          if (lVar8 + -1 == 0) {
                                                            FUN_23a334bc0(plStack_110);
                                                          }
                                                          lVar8 = *plStack_128;
                                                          *plStack_128 = lVar8 + -1;
                                                          if (lVar8 + -1 == 0) {
                                                            FUN_23a334bc0(plStack_128);
                                                          }
                                                          lVar8 = *plStack_120;
                                                          *plStack_120 = lVar8 + -1;
                                                          if (lVar8 + -1 == 0) {
                                                            FUN_23a334bc0(plStack_120);
                                                          }
                                                          lVar8 = *plStack_130;
                                                          *plStack_130 = lVar8 + -1;
                                                          if (lVar8 + -1 != 0) {
                                                            return pcVar3;
                                                          }
                                                          FUN_23a334bc0(plStack_130);
                                                          return pcVar3;
                                                        }
                                                        auStack_78 = *(undefined1 (*) [16])
                                                                      (param_1 + 0x60);
                                                        plStack_68 = *(longlong **)(param_1 + 0x70);
                                                        uStack_a8 = 0xd9;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                      }
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_23e2b9c20;
                                                  }
                                                  }
                                                  auStack_78 = *(undefined1 (*) [16])
                                                                (param_1 + 0x60);
                                                  plStack_68 = *(longlong **)(param_1 + 0x70);
                                                  uStack_a8 = 0xcd;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
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
                                                  goto LAB_23e2b9c20;
                                                  }
                                                  }
                                                  auStack_78 = *(undefined1 (*) [16])
                                                                (param_1 + 0x60);
                                                  plStack_68 = *(longlong **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  uStack_a8 = 0xbe;
                                                  plStack_130 = (longlong *)0x0;
                                                  plStack_120 = (longlong *)0x0;
                                                  plStack_128 = (longlong *)0x0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
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
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_23e2b9c20;
                                                  }
                                                }
                                                *plVar14 = lVar8 + -1;
                                                plVar12 = plStack_68;
                                                uVar18 = auStack_78._0_8_;
                                                uVar19 = auStack_78._8_8_;
                                                if (lVar8 + -1 == 0) {
LAB_23e2bf4c9:
                                                  plStack_68 = (longlong *)0x0;
                                                  auStack_78 = (undefined1  [16])0x0;
                                                  FUN_23a334bc0(plVar14);
                                                  plStack_68 = (longlong *)0x0;
                                                  auStack_78 = (undefined1  [16])0x0;
                                                  if (plStack_118 != (longlong *)0x0)
                                                  goto LAB_23e2bf503;
                                                }
                                                else {
LAB_23e2bf503:
                                                  plStack_68 = (longlong *)0x0;
                                                  auStack_78 = (undefined1  [16])0x0;
                                                  lVar8 = *plStack_118;
                                                  *plStack_118 = lVar8 + -1;
                                                  if (lVar8 + -1 == 0) {
                                                    FUN_23a334bc0(plStack_118);
                                                  }
                                                }
                                                if ((plStack_108 != (longlong *)0x0) &&
                                                   (lVar8 = *plStack_108, *plStack_108 = lVar8 + -1,
                                                   lVar8 + -1 == 0)) {
                                                  FUN_23a334bc0();
                                                }
                                              }
                                            }
                                            uStack_a8 = 0xb3;
                                            plStack_130 = (longlong *)0x0;
                                            plStack_120 = (longlong *)0x0;
                                            plStack_128 = (longlong *)0x0;
                                            plStack_110 = (longlong *)0x0;
                                            plStack_e8 = (longlong *)0x0;
                                            plStack_f0 = (longlong *)0x0;
                                            plStack_108 = (longlong *)0x0;
                                            plStack_118 = (longlong *)0x0;
                                            auStack_78._8_8_ = uVar19;
                                            auStack_78._0_8_ = uVar18;
                                            plStack_68 = plVar12;
                                            goto LAB_23e2b9c20;
                                          }
                                          plStack_68 = *(longlong **)(param_1 + 0x70);
                                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                        }
                                        lVar8 = *plVar14;
                                        *plVar14 = lVar8 + -1;
                                        if (lVar8 + -1 == 0) {
                                          FUN_23a334bc0(plVar14);
                                        }
                                        *plVar15 = *plVar15 + -1;
                                        if (*plVar15 == 0) {
                                          FUN_23a334bc0(plVar15);
                                          uStack_a8 = 0xad;
                                          plStack_130 = (longlong *)0x0;
                                          plStack_120 = (longlong *)0x0;
                                          plStack_128 = (longlong *)0x0;
                                          plStack_110 = (longlong *)0x0;
                                          plStack_e8 = (longlong *)0x0;
                                          plStack_f0 = (longlong *)0x0;
                                          plStack_108 = (longlong *)0x0;
                                          plStack_118 = (longlong *)0x0;
                                        }
                                        else {
                                          uStack_a8 = 0xad;
                                          plStack_130 = (longlong *)0x0;
                                          plStack_120 = (longlong *)0x0;
                                          plStack_128 = (longlong *)0x0;
                                          plStack_110 = (longlong *)0x0;
                                          plStack_e8 = (longlong *)0x0;
                                          plStack_f0 = (longlong *)0x0;
                                          plStack_108 = (longlong *)0x0;
                                          plStack_118 = (longlong *)0x0;
                                        }
                                        goto LAB_23e2b9c20;
                                      }
                                      *plVar14 = *plVar14 + -1;
                                      plVar12 = plStack_68;
                                      uVar18 = auStack_78._0_8_;
                                      uVar19 = auStack_78._8_8_;
                                      if (*plVar14 == 0) goto LAB_23e2c2425;
LAB_23e2c22ee:
                                      plStack_68 = (longlong *)0x0;
                                      auStack_78 = (undefined1  [16])0x0;
                                      lVar8 = *plStack_f8;
                                      *plStack_f8 = lVar8 + -1;
                                      if (lVar8 + -1 == 0) {
                                        FUN_23a334bc0();
                                      }
LAB_23e2c2322:
                                      if ((plStack_d8 != (longlong *)0x0) &&
                                         (lVar8 = *plStack_d8, *plStack_d8 = lVar8 + -1,
                                         lVar8 + -1 == 0)) {
                                        FUN_23a334bc0();
                                      }
                                    }
                                  }
                                  uStack_a8 = 0x99;
                                  plStack_130 = (longlong *)0x0;
                                  plStack_120 = (longlong *)0x0;
                                  plStack_128 = (longlong *)0x0;
                                  plStack_110 = (longlong *)0x0;
                                  plStack_e8 = (longlong *)0x0;
                                  plStack_f0 = (longlong *)0x0;
                                  plStack_108 = (longlong *)0x0;
                                  plStack_118 = (longlong *)0x0;
                                  plStack_e0 = (longlong *)0x0;
                                  plStack_c8 = (longlong *)0x0;
                                  plStack_b8 = (longlong *)0x0;
                                  plStack_d0 = (longlong *)0x0;
                                  plStack_d8 = (longlong *)0x0;
                                  plStack_f8 = (longlong *)0x0;
                                  auStack_78._8_8_ = uVar19;
                                  auStack_78._0_8_ = uVar18;
                                  plStack_68 = plVar12;
                                  goto LAB_23e2b9c20;
                                }
                                plStack_68 = *(longlong **)(param_1 + 0x70);
                                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              }
                              lVar8 = *plVar14;
                              *plVar14 = lVar8 + -1;
                              if (lVar8 + -1 == 0) {
                                FUN_23a334bc0(plVar14);
                              }
                              *plVar15 = *plVar15 + -1;
                              if (*plVar15 == 0) {
                                FUN_23a334bc0();
                                uStack_a8 = 0x93;
                                plStack_130 = (longlong *)0x0;
                                plStack_120 = (longlong *)0x0;
                                plStack_128 = (longlong *)0x0;
                                plStack_110 = (longlong *)0x0;
                                plStack_e8 = (longlong *)0x0;
                                plStack_f0 = (longlong *)0x0;
                                plStack_108 = (longlong *)0x0;
                                plStack_118 = (longlong *)0x0;
                                plStack_e0 = (longlong *)0x0;
                                plStack_c8 = (longlong *)0x0;
                                plStack_b8 = (longlong *)0x0;
                                plStack_d0 = (longlong *)0x0;
                                plStack_d8 = (longlong *)0x0;
                                plStack_f8 = (longlong *)0x0;
                              }
                              else {
                                uStack_a8 = 0x93;
                                plStack_130 = (longlong *)0x0;
                                plStack_120 = (longlong *)0x0;
                                plStack_128 = (longlong *)0x0;
                                plStack_110 = (longlong *)0x0;
                                plStack_e8 = (longlong *)0x0;
                                plStack_f0 = (longlong *)0x0;
                                plStack_108 = (longlong *)0x0;
                                plStack_118 = (longlong *)0x0;
                                plStack_e0 = (longlong *)0x0;
                                plStack_c8 = (longlong *)0x0;
                                plStack_b8 = (longlong *)0x0;
                                plStack_d0 = (longlong *)0x0;
                                plStack_d8 = (longlong *)0x0;
                                plStack_f8 = (longlong *)0x0;
                              }
                              goto LAB_23e2b9c20;
                            }
                            plStack_68 = *(longlong **)(param_1 + 0x70);
                            auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          }
                          lVar8 = *plVar14;
                          *plVar14 = lVar8 + -1;
                          if (lVar8 + -1 == 0) {
                            FUN_23a334bc0(plVar14);
                          }
                          *plVar15 = *plVar15 + -1;
                          if (*plVar15 == 0) {
                            FUN_23a334bc0(plVar15);
                            uStack_a8 = 0x78;
                            plStack_130 = (longlong *)0x0;
                            plStack_120 = (longlong *)0x0;
                            plStack_128 = (longlong *)0x0;
                            plStack_110 = (longlong *)0x0;
                            plStack_e8 = (longlong *)0x0;
                            plStack_f0 = (longlong *)0x0;
                            plStack_108 = (longlong *)0x0;
                            plStack_118 = (longlong *)0x0;
                            plStack_e0 = (longlong *)0x0;
                            plStack_c8 = (longlong *)0x0;
                            plStack_b8 = (longlong *)0x0;
                            plStack_d0 = (longlong *)0x0;
                            plStack_d8 = (longlong *)0x0;
                            plStack_f8 = (longlong *)0x0;
                          }
                          else {
                            uStack_a8 = 0x78;
                            plStack_130 = (longlong *)0x0;
                            plStack_120 = (longlong *)0x0;
                            plStack_128 = (longlong *)0x0;
                            plStack_110 = (longlong *)0x0;
                            plStack_e8 = (longlong *)0x0;
                            plStack_f0 = (longlong *)0x0;
                            plStack_108 = (longlong *)0x0;
                            plStack_118 = (longlong *)0x0;
                            plStack_e0 = (longlong *)0x0;
                            plStack_c8 = (longlong *)0x0;
                            plStack_b8 = (longlong *)0x0;
                            plStack_d0 = (longlong *)0x0;
                            plStack_d8 = (longlong *)0x0;
                            plStack_f8 = (longlong *)0x0;
                          }
                          goto LAB_23e2b9c20;
                        }
                        plStack_68 = *(longlong **)(param_1 + 0x70);
                        auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      }
                      uStack_a8 = 0x6f;
                    }
                  }
                  lVar8 = *plVar14;
                  *plVar14 = lVar8 + -1;
                  if (lVar8 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                  *plVar15 = *plVar15 + -1;
                  if (*plVar15 == 0) {
                    FUN_23a334bc0(plVar15);
                    plStack_130 = (longlong *)0x0;
                    plStack_120 = (longlong *)0x0;
                    plStack_128 = (longlong *)0x0;
                    plStack_110 = (longlong *)0x0;
                    plStack_e8 = (longlong *)0x0;
                    plStack_f0 = (longlong *)0x0;
                    plStack_108 = (longlong *)0x0;
                    plStack_118 = (longlong *)0x0;
                    plStack_e0 = (longlong *)0x0;
                    plStack_c8 = (longlong *)0x0;
                    plStack_b8 = (longlong *)0x0;
                    plStack_d0 = (longlong *)0x0;
                    plStack_d8 = (longlong *)0x0;
                    plStack_f8 = (longlong *)0x0;
                  }
                  else {
                    plStack_130 = (longlong *)0x0;
                    plStack_120 = (longlong *)0x0;
                    plStack_128 = (longlong *)0x0;
                    plStack_110 = (longlong *)0x0;
                    plStack_e8 = (longlong *)0x0;
                    plStack_f0 = (longlong *)0x0;
                    plStack_108 = (longlong *)0x0;
                    plStack_118 = (longlong *)0x0;
                    plStack_e0 = (longlong *)0x0;
                    plStack_c8 = (longlong *)0x0;
                    plStack_b8 = (longlong *)0x0;
                    plStack_d0 = (longlong *)0x0;
                    plStack_d8 = (longlong *)0x0;
                    plStack_f8 = (longlong *)0x0;
                  }
                  goto LAB_23e2b9c20;
                }
                *plVar14 = *plVar14 + -1;
                plVar12 = plStack_68;
                uVar18 = auStack_78._0_8_;
                uVar19 = auStack_78._8_8_;
                if (*plVar14 == 0) goto LAB_23e2be42b;
LAB_23e2be464:
                plStack_68 = (longlong *)0x0;
                auStack_78 = (undefined1  [16])0x0;
                lVar8 = *plStack_138;
                *plStack_138 = lVar8 + -1;
                if (lVar8 + -1 == 0) {
                  FUN_23a334bc0();
                }
LAB_23e2be495:
                if ((plStack_100 != (longlong *)0x0) &&
                   (lVar8 = *plStack_100, *plStack_100 = lVar8 + -1, lVar8 + -1 == 0)) {
                  FUN_23a334bc0();
                }
              }
            }
            uStack_a8 = 0x5e;
            plStack_130 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_e8 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plStack_c8 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_d0 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_b0 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
            plStack_138 = (longlong *)0x0;
            auStack_78._8_8_ = uVar19;
            auStack_78._0_8_ = uVar18;
            plStack_68 = plVar12;
            goto LAB_23e2b9c20;
          }
          plStack_68 = *(longlong **)(param_1 + 0x70);
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        }
        lVar8 = *plVar14;
        *plVar14 = lVar8 + -1;
        if (lVar8 + -1 == 0) {
          FUN_23a334bc0(plVar14);
        }
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) {
          FUN_23a334bc0(plVar15);
          uStack_a8 = 0x52;
          plStack_130 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plStack_b8 = (longlong *)0x0;
          plStack_d0 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_b0 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
        }
        else {
          uStack_a8 = 0x52;
          plStack_130 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plStack_b8 = (longlong *)0x0;
          plStack_d0 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_b0 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
        }
        goto LAB_23e2b9c20;
      }
    }
    plVar14 = plStack_68;
    uVar18 = auStack_78._0_8_;
    uVar19 = auStack_78._8_8_;
    plStack_68 = (longlong *)0x0;
    auStack_78 = (undefined1  [16])0x0;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    plStack_68 = (longlong *)0x0;
    auStack_78 = (undefined1  [16])0x0;
    if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if ((plStack_c0 != (longlong *)0x0) &&
       (lVar8 = *plStack_c0, *plStack_c0 = lVar8 + -1, lVar8 + -1 == 0)) {
      (**(code **)(plStack_c0[1] + 0x30))();
    }
  }
  plVar13 = (longlong *)0x0;
  uStack_a8 = 0x49;
  plStack_130 = (longlong *)0x0;
  plStack_120 = (longlong *)0x0;
  plStack_128 = (longlong *)0x0;
  plStack_110 = (longlong *)0x0;
  plStack_e8 = (longlong *)0x0;
  plStack_f0 = (longlong *)0x0;
  plStack_108 = (longlong *)0x0;
  plStack_118 = (longlong *)0x0;
  plStack_e0 = (longlong *)0x0;
  plStack_c8 = (longlong *)0x0;
  plStack_b8 = (longlong *)0x0;
  plStack_d0 = (longlong *)0x0;
  plStack_d8 = (longlong *)0x0;
  plStack_f8 = (longlong *)0x0;
  plStack_b0 = (longlong *)0x0;
  plStack_100 = (longlong *)0x0;
  plStack_138 = (longlong *)0x0;
  plStack_c0 = (longlong *)0x0;
  auStack_78._8_8_ = uVar19;
  auStack_78._0_8_ = uVar18;
  plStack_68 = plVar14;
LAB_23e2b9c20:
  plVar14 = plStack_68;
  plVar12 = DAT_23ed6a4f8;
  if (plStack_68 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar14 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar14;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar3 = _PyRuntime_exref;
    plVar12[2] = 0;
    plVar12[3] = (longlong)plVar7;
    *plVar7 = *plVar7 + 1;
    lVar8 = *(longlong *)(pcVar3 + 0x1f8);
    *(undefined4 *)((longlong)plVar12 + 0x24) = uStack_a8;
    lVar8 = *(longlong *)(lVar8 + 0x10);
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar8 = *(longlong *)(lVar8 + 0x2e8);
    lVar1 = plVar12[-1];
    puVar2 = *(undefined8 **)(lVar8 + 8);
    *puVar2 = plVar12 + -2;
    plVar12[-2] = lVar8;
    plVar12[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar8 + 8) = plVar12 + -2;
    plVar14 = plVar12;
    if ((plStack_68 != (longlong *)0x0) && (*plStack_68 = *plStack_68 + -1, *plStack_68 == 0)) {
      (**(code **)(plStack_68[1] + 0x30))(plStack_68);
    }
  }
  else if ((longlong *)plStack_68[3] != plVar7) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar15 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar15;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar3 = _PyRuntime_exref;
    plVar12[3] = (longlong)plVar7;
    *plVar7 = *plVar7 + 1;
    lVar8 = *(longlong *)(pcVar3 + 0x1f8);
    *(undefined4 *)((longlong)plVar12 + 0x24) = uStack_a8;
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar8 = *(longlong *)(*(longlong *)(lVar8 + 0x10) + 0x2e8);
    lVar1 = plVar12[-1];
    puVar2 = *(undefined8 **)(lVar8 + 8);
    *puVar2 = plVar12 + -2;
    plVar12[-2] = lVar8;
    plVar12[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar8 + 8) = plVar12 + -2;
    plVar12[2] = (longlong)plVar14;
    *plVar14 = *plVar14 + 1;
    plVar14 = plVar12;
    if ((plStack_68 != (longlong *)0x0) && (*plStack_68 = *plStack_68 + -1, *plStack_68 == 0)) {
      (**(code **)(plStack_68[1] + 0x30))();
    }
  }
  plStack_68 = plVar14;
  FUN_23e8bba40(plVar7,"cooooooooooooooooooooooo",plVar17,plVar9,plVar10,plVar11,plStack_140,plVar13
                ,plStack_c0,plStack_138,plStack_100,plStack_b0,plStack_f8,plStack_d8,plStack_d0,
                plStack_b8,plStack_c8,plStack_e0,plStack_118,plStack_108,plStack_f0,plStack_e8,
                plStack_110,plStack_128,plStack_120,plStack_130);
  if (_DAT_23eeb0370 == plVar7) {
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    _DAT_23eeb0370 = (longlong *)0x0;
  }
  lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar7 = *(longlong **)(lVar8 + 0x28);
  plVar12 = (longlong *)plVar7[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar8 + 0x30);
  *(undefined4 *)(plVar7 + 8) = 0xffffffff;
  if (plVar12 != (longlong *)0x0) {
    plVar7[2] = 0;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))();
    }
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  plVar12 = plStack_68;
  auVar4 = auStack_78;
  plVar7[0xf] = 0;
  uVar18 = auStack_78._0_8_;
  uVar19 = auStack_78._8_8_;
  auStack_78 = (undefined1  [16])0x0;
  plStack_68 = (longlong *)0x0;
  *plVar17 = *plVar17 + -1;
  if (*plVar17 == 0) {
    (**(code **)(plVar17[1] + 0x30))(plVar17);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plStack_140 != (longlong *)0x0) &&
     (lVar8 = *plStack_140, *plStack_140 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_140[1] + 0x30))(plStack_140);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plStack_c0 != (longlong *)0x0) &&
     (lVar8 = *plStack_c0, *plStack_c0 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
  }
  if ((plStack_138 != (longlong *)0x0) &&
     (lVar8 = *plStack_138, *plStack_138 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_138[1] + 0x30))(plStack_138);
  }
  if ((plStack_100 != (longlong *)0x0) &&
     (lVar8 = *plStack_100, *plStack_100 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_100[1] + 0x30))(plStack_100);
  }
  if ((plStack_b0 != (longlong *)0x0) &&
     (lVar8 = *plStack_b0, *plStack_b0 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_b0[1] + 0x30))(plStack_b0);
  }
  if ((plStack_f8 != (longlong *)0x0) &&
     (lVar8 = *plStack_f8, *plStack_f8 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
  }
  if ((plStack_d8 != (longlong *)0x0) &&
     (lVar8 = *plStack_d8, *plStack_d8 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
  }
  if ((plStack_d0 != (longlong *)0x0) &&
     (lVar8 = *plStack_d0, *plStack_d0 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_d0[1] + 0x30))(plStack_d0);
  }
  if ((plStack_b8 != (longlong *)0x0) &&
     (lVar8 = *plStack_b8, *plStack_b8 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_b8[1] + 0x30))(plStack_b8);
  }
  if ((plStack_c8 != (longlong *)0x0) &&
     (lVar8 = *plStack_c8, *plStack_c8 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_c8[1] + 0x30))(plStack_c8);
  }
  if ((plStack_e0 != (longlong *)0x0) &&
     (lVar8 = *plStack_e0, *plStack_e0 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
  }
  if ((plStack_118 != (longlong *)0x0) &&
     (lVar8 = *plStack_118, *plStack_118 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_118[1] + 0x30))(plStack_118);
  }
  if ((plStack_108 != (longlong *)0x0) &&
     (lVar8 = *plStack_108, *plStack_108 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_108[1] + 0x30))(plStack_108);
  }
  if ((plStack_f0 != (longlong *)0x0) &&
     (lVar8 = *plStack_f0, *plStack_f0 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_f0[1] + 0x30))(plStack_f0);
  }
  if ((plStack_e8 != (longlong *)0x0) &&
     (lVar8 = *plStack_e8, *plStack_e8 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
  }
  if ((plStack_110 != (longlong *)0x0) &&
     (lVar8 = *plStack_110, *plStack_110 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_110[1] + 0x30))(plStack_110);
  }
  if ((plStack_128 != (longlong *)0x0) &&
     (lVar8 = *plStack_128, *plStack_128 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_128[1] + 0x30))(plStack_128);
  }
  if ((plStack_120 != (longlong *)0x0) &&
     (lVar8 = *plStack_120, *plStack_120 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_120[1] + 0x30))(plStack_120);
  }
  if ((plStack_130 != (longlong *)0x0) &&
     (lVar8 = *plStack_130, *plStack_130 = lVar8 + -1, lVar8 + -1 == 0)) {
    (**(code **)(plStack_130[1] + 0x30))(plStack_130);
  }
  auStack_78 = auVar4;
  plStack_68 = plVar12;
  FUN_23a33aa70(param_1,uVar18,uVar19,plVar12);
  return (code *)0x0;
}
