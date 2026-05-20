/* ===== 23e813650 workers.fishing.memory_reeling:MemoryReelingTracker._find_cped ===== */
/* ghidra_name=FUN_23e813650 entry=23e813650 size=20531 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e813650(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  char cVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  undefined8 uVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong *plVar20;
  code *pcVar21;
  longlong lVar22;
  undefined4 uVar23;
  longlong lVar24;
  undefined8 in_stack_fffffffffffffe38;
  longlong *plStack_130;
  longlong *plStack_128;
  code *pcStack_120;
  longlong *plStack_118;
  longlong *plStack_110;
  longlong *plStack_108;
  longlong *plStack_100;
  longlong *plStack_f8;
  longlong *plStack_f0;
  longlong *plStack_e8;
  longlong *plStack_e0;
  longlong *plStack_d8;
  longlong *plStack_b0;
  longlong *plStack_a8;
  longlong *plStack_98;
  longlong *plStack_88;
  longlong lStack_80;
  undefined1 auStack_78 [16];
  longlong *aplStack_68 [5];
  
  plVar9 = _DAT_23eede848;
  uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffe38 >> 0x20);
  plVar2 = (longlong *)param_3[1];
  plVar3 = (longlong *)*param_3;
  aplStack_68[0] = (longlong *)0x0;
  auStack_78._0_8_ = (code *)0x0;
  auStack_78._8_8_ = 0;
  if (_DAT_23eede848 == (longlong *)0x0) {
LAB_23e8136b9:
    _DAT_23eede848 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede9c8,DAT_23eedd0f8);
  }
  else {
    lVar24 = *_DAT_23eede848;
    if (1 < lVar24) {
      *_DAT_23eede848 = lVar24 + -1;
      goto LAB_23e8136b9;
    }
    if (_DAT_23eede848[2] != 0) {
      *_DAT_23eede848 = lVar24 + -1;
      if (lVar24 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e8136b9;
    }
  }
  plVar4 = _DAT_23eede848;
  lVar24 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eede848 + 9;
  lVar22 = *(longlong *)(lVar24 + 8);
  _DAT_23eede848[0xf] = lVar22;
  *(longlong **)(lVar24 + 8) = plVar9;
  if ((lVar22 != 0) &&
     (((*(char *)(lVar22 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar22 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar22 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar22 + 0x38))) && (plVar4[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar22 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar14 = _DAT_23eedd1c0;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar3,uVar14);
  if (plVar9 == (longlong *)0x0) {
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    plStack_b0 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    uVar23 = 0x18e;
    plStack_108 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar9 = (longlong *)0x0;
    goto LAB_23e813eac;
  }
  iVar8 = FUN_23a35f020(plVar9);
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar12 = DAT_23ed6ccf0;
  if (iVar8 == -1) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    uVar23 = 0x18e;
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b0 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e813eac;
  }
  if (iVar8 == 0) {
    plStack_b0 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plVar15 = (longlong *)0x0;
    goto LAB_23e81382b;
  }
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar3,_DAT_23eedd528);
  if (plVar10 == (longlong *)0x0) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    plStack_b0 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    uVar23 = 0x191;
    plStack_108 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = (longlong *)0x0;
    goto LAB_23e813eac;
  }
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar3,_DAT_23eedd1c0);
  if (plVar11 == (longlong *)0x0) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar10 = *plVar10 + -1;
    plVar11 = (longlong *)0x0;
    if (*plVar10 == 0) {
      plStack_98 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plStack_b0 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      (**(code **)(plVar10[1] + 0x30))(plVar10);
      plVar10 = (longlong *)0x0;
      uVar23 = 0x191;
      plStack_108 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      pcStack_120 = (code *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
    }
    else {
      plStack_108 = (longlong *)0x0;
      plStack_98 = (longlong *)0x0;
      plStack_b0 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      uVar23 = 0x191;
      plStack_110 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      pcStack_120 = (code *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
    }
    goto LAB_23e813eac;
  }
  *(undefined4 *)(plVar4 + 5) = 0x191;
  plVar9 = (longlong *)FUN_23e914090(param_1,plVar10,plVar11);
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if (plVar9 == (longlong *)0x0) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    plStack_b0 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    uVar23 = 0x191;
    plStack_108 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e813eac;
  }
  *(undefined4 *)(plVar4 + 5) = 0x192;
  plVar10 = (longlong *)FUN_23e915840(param_1,plVar3,_DAT_23eedd530);
  if (plVar10 == (longlong *)0x0) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    plStack_b0 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    uVar23 = 0x192;
    plStack_108 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = (longlong *)0x0;
    goto LAB_23e813eac;
  }
  iVar8 = FUN_23a35f020(plVar10);
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  plVar12 = DAT_23ed6ccf0;
  if (iVar8 == -1) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    uVar23 = 0x192;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e814e1c:
    plStack_108 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    goto LAB_23e813eac;
  }
  if (iVar8 == 0) {
    plStack_b0 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plVar15 = (longlong *)0x0;
    goto LAB_23e81382b;
  }
  plVar12 = (longlong *)FUN_23e8bc2f0(plVar3,_DAT_23eedd528);
  if (plVar12 == (longlong *)0x0) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    plStack_b0 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar10 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    uVar23 = 0x195;
    plStack_108 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar13 = (longlong *)0x0;
    goto LAB_23e813eac;
  }
  lVar24 = *(longlong *)(DAT_23eedd0f0 + 0x20);
  if (*(char *)(lVar24 + 10) == '\0') {
    plVar10 = (longlong *)FUN_23a37a020(DAT_23eedd0f0,_DAT_23eedd590);
    if (plVar10 == (longlong *)0x0) goto LAB_23e814dc0;
    lVar24 = *plVar10;
LAB_23e814da9:
    if (lVar24 == 0) goto LAB_23e814dc0;
  }
  else {
    iVar8 = *(int *)(lVar24 + 0xc);
    if (*(int *)(lVar24 + 0xc) == 0) {
      *(int *)(lVar24 + 0xc) = DAT_23ec155d8;
      iVar8 = DAT_23ec155d8;
      DAT_23ec155d8 = DAT_23ec155d8 + 1;
    }
    if (_DAT_23ec1559c != iVar8) {
      _DAT_23ec1559c = iVar8;
      _DAT_23eede818 = FUN_23e8cbd60(lVar24,_DAT_23eedd590,*(undefined8 *)(_DAT_23eedd590 + 0x18));
    }
    if (-1 < _DAT_23eede818) {
      lVar22 = lVar24 + 0x20 + (1L << (*(byte *)(lVar24 + 9) & 0x3f));
      if (*(longlong *)(lVar22 + 8 + _DAT_23eede818 * 0x10) != 0) goto LAB_23e8148e8;
      _DAT_23eede818 = FUN_23e8cbd60(lVar24,_DAT_23eedd590,*(undefined8 *)(_DAT_23eedd590 + 0x18));
      if (-1 < _DAT_23eede818) {
        lVar24 = *(longlong *)(lVar22 + 8 + _DAT_23eede818 * 0x10);
        goto LAB_23e814da9;
      }
    }
LAB_23e814dc0:
    plVar10 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedd590);
    if ((plVar10 == (longlong *)0x0) || (*plVar10 == 0)) {
      FUN_23e915740(param_1,auStack_78,_DAT_23eedd590);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      uVar23 = 0x195;
      goto LAB_23e814e1c;
    }
  }
LAB_23e8148e8:
  plVar10 = (longlong *)FUN_23e8c09e0(plVar9);
  if (plVar10 == (longlong *)0x0) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar12 = *plVar12 + -1;
    plVar10 = (longlong *)0x0;
    if (*plVar12 == 0) {
      plStack_b0 = (longlong *)0x0;
      plStack_98 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      (**(code **)(plVar12[1] + 0x30))(plVar12);
      plVar11 = (longlong *)0x0;
      uVar23 = 0x195;
      plStack_108 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      pcStack_120 = (code *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
    }
    else {
      plStack_108 = (longlong *)0x0;
      plStack_b0 = (longlong *)0x0;
      plStack_98 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      uVar23 = 0x195;
      plStack_110 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      pcStack_120 = (code *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
    }
    goto LAB_23e813eac;
  }
  *(undefined4 *)(plVar4 + 5) = 0x195;
  plVar11 = (longlong *)FUN_23e914090(param_1,plVar12,plVar10);
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if (plVar11 == (longlong *)0x0) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    plStack_b0 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    uVar23 = 0x195;
    plStack_108 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e813eac;
  }
  *(undefined4 *)(plVar4 + 5) = 0x196;
  plVar10 = (longlong *)FUN_23e915840(param_1,plVar3);
  if (plVar10 == (longlong *)0x0) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    plStack_b0 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    uVar23 = 0x196;
    plStack_108 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = (longlong *)0x0;
    goto LAB_23e813eac;
  }
  iVar8 = FUN_23a35f020(plVar10);
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  plVar12 = DAT_23ed6ccf0;
  if (iVar8 == -1) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    uVar23 = 0x196;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e81567d:
    plStack_108 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    goto LAB_23e813eac;
  }
  if (iVar8 == 0) {
    plStack_b0 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plVar15 = (longlong *)0x0;
    goto LAB_23e81382b;
  }
  plVar12 = (longlong *)FUN_23e8bc2f0(plVar3,_DAT_23eedd598);
  if (plVar12 == (longlong *)0x0) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    plStack_b0 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_98 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    uVar23 = 0x199;
    plStack_108 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar13 = (longlong *)0x0;
    goto LAB_23e813eac;
  }
  lVar24 = *(longlong *)(DAT_23eedd0f0 + 0x20);
  if (*(char *)(lVar24 + 10) == '\0') {
    plVar10 = (longlong *)FUN_23a37a020(DAT_23eedd0f0,_DAT_23eedd5a0);
    if (plVar10 == (longlong *)0x0) goto LAB_23e815607;
    lVar24 = *plVar10;
LAB_23e8155fe:
    if (lVar24 == 0) goto LAB_23e815607;
  }
  else {
    iVar8 = *(int *)(lVar24 + 0xc);
    if (*(int *)(lVar24 + 0xc) == 0) {
      *(int *)(lVar24 + 0xc) = DAT_23ec155d8;
      iVar8 = DAT_23ec155d8;
      DAT_23ec155d8 = DAT_23ec155d8 + 1;
    }
    if (_DAT_23ec155a0 != iVar8) {
      _DAT_23ec155a0 = iVar8;
      _DAT_23eede820 = FUN_23e8cbd60(lVar24);
    }
    if (-1 < _DAT_23eede820) {
      lVar22 = lVar24 + 0x20 + (1L << (*(byte *)(lVar24 + 9) & 0x3f));
      if (*(longlong *)(lVar22 + 8 + _DAT_23eede820 * 0x10) != 0) goto LAB_23e8150a5;
      _DAT_23eede820 = FUN_23e8cbd60(lVar24);
      if (-1 < _DAT_23eede820) {
        lVar24 = *(longlong *)(lVar22 + 8 + _DAT_23eede820 * 0x10);
        goto LAB_23e8155fe;
      }
    }
LAB_23e815607:
    plVar10 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedd5a0);
    if ((plVar10 == (longlong *)0x0) || (*plVar10 == 0)) {
      FUN_23e915740(param_1,auStack_78,_DAT_23eedd5a0);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        plStack_98 = (longlong *)0x0;
        FUN_23a334bc0(plVar12);
        plVar10 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        uVar23 = 0x199;
        plStack_110 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_b0 = (longlong *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        pcStack_120 = (code *)0x0;
        plStack_e8 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        goto LAB_23e813eac;
      }
      uVar23 = 0x199;
      goto LAB_23e81567d;
    }
  }
LAB_23e8150a5:
  plVar13 = (longlong *)FUN_23e8c09e0(plVar11);
  if (plVar13 == (longlong *)0x0) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar12 = *plVar12 + -1;
    plVar10 = (longlong *)0x0;
    if (*plVar12 == 0) {
      plStack_b0 = (longlong *)0x0;
      plStack_98 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      FUN_23a334bc0(plVar12);
      plStack_d8 = (longlong *)0x0;
      uVar23 = 0x199;
      plStack_e0 = (longlong *)0x0;
      pcStack_120 = (code *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
    }
    else {
      plStack_b0 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_98 = (longlong *)0x0;
      uVar23 = 0x199;
      plStack_e0 = (longlong *)0x0;
      pcStack_120 = (code *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
    }
    goto LAB_23e813eac;
  }
  *(undefined4 *)(plVar4 + 5) = 0x199;
  plVar10 = (longlong *)FUN_23e914090();
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    (**(code **)(plVar12[1] + 0x30))();
  }
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    (**(code **)(plVar13[1] + 0x30))();
  }
  if (plVar10 == (longlong *)0x0) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b0 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    uVar23 = 0x199;
    plStack_108 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e813eac;
  }
  iVar8 = FUN_23e97b760(plVar10,DAT_23ed6ccf0);
  plVar12 = DAT_23ed6ccf0;
  if (iVar8 == -1) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar23 = 0x19a;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e815e79:
    plStack_b0 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    goto LAB_23e813eac;
  }
  if (iVar8 == 1) {
    plStack_b0 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plVar15 = plVar10;
    goto LAB_23e81382b;
  }
  uVar14 = FUN_23a3a0d40(DAT_23eedd4c0);
  lStack_80 = _DAT_23eedd5a8;
  *(undefined4 *)(plVar4 + 5) = 0x19c;
  plStack_88 = plVar10;
  plVar15 = (longlong *)FUN_23e94ed00(param_1,uVar14,&plStack_88);
  if (plVar15 == (longlong *)0x0) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    plStack_b0 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_98 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    uVar23 = 0x19c;
    plStack_130 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e813eac;
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    FUN_23a334bc0(plVar10);
  }
  plVar12 = (longlong *)FUN_23e8bc2f0(plVar3,_DAT_23eedd528);
  plVar10 = plVar15;
  if (plVar12 == (longlong *)0x0) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    plStack_d8 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    uVar23 = 0x19e;
    plStack_118 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_108 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_f8 = (longlong *)0x0;
    goto LAB_23e813eac;
  }
  lVar24 = *(longlong *)(DAT_23eedd0f0 + 0x20);
  if (*(char *)(lVar24 + 10) == '\0') {
    plVar13 = (longlong *)FUN_23a37a020(DAT_23eedd0f0,_DAT_23eedd5b0);
    if (plVar13 == (longlong *)0x0) goto LAB_23e815dce;
    lVar24 = *plVar13;
LAB_23e815dc5:
    if (lVar24 == 0) goto LAB_23e815dce;
  }
  else {
    iVar8 = *(int *)(lVar24 + 0xc);
    if (*(int *)(lVar24 + 0xc) == 0) {
      *(int *)(lVar24 + 0xc) = DAT_23ec155d8;
      iVar8 = DAT_23ec155d8;
      DAT_23ec155d8 = DAT_23ec155d8 + 1;
    }
    if (_DAT_23ec155a4 != iVar8) {
      _DAT_23ec155a4 = iVar8;
      _DAT_23eede828 = FUN_23e8cbd60(lVar24,_DAT_23eedd5b0,*(undefined8 *)(_DAT_23eedd5b0 + 0x18));
    }
    if (-1 < _DAT_23eede828) {
      lVar22 = lVar24 + 0x20 + (1L << (*(byte *)(lVar24 + 9) & 0x3f));
      if (*(longlong *)(lVar22 + 8 + _DAT_23eede828 * 0x10) != 0) goto LAB_23e815909;
      _DAT_23eede828 = FUN_23e8cbd60(lVar24,_DAT_23eedd5b0,*(undefined8 *)(_DAT_23eedd5b0 + 0x18));
      if (-1 < _DAT_23eede828) {
        lVar24 = *(longlong *)(lVar22 + 8 + _DAT_23eede828 * 0x10);
        goto LAB_23e815dc5;
      }
    }
LAB_23e815dce:
    plVar13 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedd5b0);
    if ((plVar13 == (longlong *)0x0) || (*plVar13 == 0)) {
      FUN_23e915740(param_1,auStack_78);
      lVar24 = *plVar12;
      *plVar12 = lVar24 + -1;
      if (lVar24 + -1 == 0) {
        plStack_b0 = (longlong *)0x0;
        plStack_98 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        FUN_23a334bc0(plVar12);
        plStack_108 = (longlong *)0x0;
        uVar23 = 0x19e;
        plStack_130 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        pcStack_120 = (code *)0x0;
        plStack_e8 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        goto LAB_23e813eac;
      }
      uVar23 = 0x19e;
      goto LAB_23e815e79;
    }
  }
LAB_23e815909:
  plVar16 = (longlong *)FUN_23e8c09e0();
  if (plVar16 == (longlong *)0x0) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    lVar24 = *plVar12;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar12 = lVar24 + -1;
    plStack_f0 = (longlong *)0x0;
    if (lVar24 + -1 == 0) {
      plStack_98 = (longlong *)0x0;
      plStack_b0 = (longlong *)0x0;
      FUN_23a334bc0(plVar12);
      uVar23 = 0x19e;
      plStack_108 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      pcStack_120 = (code *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
    }
    else {
      plStack_b0 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_98 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      uVar23 = 0x19e;
      plStack_108 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      pcStack_120 = (code *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
    }
    goto LAB_23e813eac;
  }
  *(undefined4 *)(plVar4 + 5) = 0x19e;
  plVar13 = (longlong *)FUN_23e914090(param_1,plVar12);
  lVar24 = *plVar12;
  *plVar12 = lVar24 + -1;
  if (lVar24 + -1 == 0) {
    FUN_23a334bc0();
  }
  lVar24 = *plVar16;
  *plVar16 = lVar24 + -1;
  if (lVar24 + -1 == 0) {
    FUN_23a334bc0();
  }
  if (plVar13 == (longlong *)0x0) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b0 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    uVar23 = 0x19e;
    plStack_108 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e813eac;
  }
  *(undefined4 *)(plVar4 + 5) = 0x19f;
  plVar12 = (longlong *)FUN_23e915840(param_1,plVar3,_DAT_23eedd530);
  if (plVar12 == (longlong *)0x0) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b0 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    uVar23 = 0x19f;
    plStack_118 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_f0 = (longlong *)0x0;
    goto LAB_23e813eac;
  }
  iVar8 = FUN_23a35f020(plVar12);
  lVar24 = *plVar12;
  *plVar12 = lVar24 + -1;
  if (lVar24 + -1 == 0) {
    FUN_23a334bc0(plVar12);
  }
  plVar12 = DAT_23ed6ccf0;
  if (iVar8 == -1) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    plVar12 = *(longlong **)(param_1 + 0x70);
    uVar23 = 0x19f;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  else {
    if (iVar8 == 0) {
      plStack_98 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_b0 = (longlong *)0x0;
      *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
      plStack_d8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      pcStack_120 = (code *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
LAB_23e81382b:
      lVar24 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar4 = *(longlong **)(lVar24 + 0x28);
      plVar10 = (longlong *)plVar4[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar24 + 0x30);
      *(undefined4 *)(plVar4 + 8) = 0xffffffff;
      if (plVar10 != (longlong *)0x0) {
        plVar4[2] = 0;
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))();
        }
      }
      *plVar4 = *plVar4 + -1;
      if (*plVar4 == 0) {
        (**(code **)(plVar4[1] + 0x30))(plVar4);
      }
      plVar4[0xf] = 0;
      if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      if ((plStack_f0 != (longlong *)0x0) &&
         (lVar24 = *plStack_f0, *plStack_f0 = lVar24 + -1, lVar24 + -1 == 0)) {
        (**(code **)(plStack_f0[1] + 0x30))(plStack_f0);
      }
      if ((plStack_f8 != (longlong *)0x0) &&
         (lVar24 = *plStack_f8, *plStack_f8 = lVar24 + -1, lVar24 + -1 == 0)) {
        (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
      }
      if ((plStack_e8 != (longlong *)0x0) &&
         (lVar24 = *plStack_e8, *plStack_e8 = lVar24 + -1, lVar24 + -1 == 0)) {
        (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
      }
      if ((pcStack_120 != (code *)0x0) &&
         (lVar24 = *(longlong *)pcStack_120, *(longlong *)pcStack_120 = lVar24 + -1,
         lVar24 + -1 == 0)) {
        (**(code **)(*(longlong *)(pcStack_120 + 8) + 0x30))(pcStack_120);
      }
      if ((plStack_e0 != (longlong *)0x0) &&
         (lVar24 = *plStack_e0, *plStack_e0 = lVar24 + -1, lVar24 + -1 == 0)) {
        (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
      }
      if ((plStack_d8 != (longlong *)0x0) &&
         (lVar24 = *plStack_d8, *plStack_d8 = lVar24 + -1, lVar24 + -1 == 0)) {
        (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
      }
      if ((plStack_98 != (longlong *)0x0) && (*plStack_98 = *plStack_98 + -1, *plStack_98 == 0)) {
        (**(code **)(plStack_98[1] + 0x30))(plStack_98);
      }
      if ((plStack_100 != (longlong *)0x0) &&
         (lVar24 = *plStack_100, *plStack_100 = lVar24 + -1, lVar24 + -1 == 0)) {
        (**(code **)(plStack_100[1] + 0x30))(plStack_100);
      }
      if ((plStack_118 != (longlong *)0x0) &&
         (lVar24 = *plStack_118, *plStack_118 = lVar24 + -1, lVar24 + -1 == 0)) {
        (**(code **)(plStack_118[1] + 0x30))(plStack_118);
      }
      if ((plStack_b0 != (longlong *)0x0) && (*plStack_b0 = *plStack_b0 + -1, *plStack_b0 == 0)) {
        (**(code **)(plStack_b0[1] + 0x30))(plStack_b0);
      }
      if ((plStack_128 != (longlong *)0x0) &&
         (lVar24 = *plStack_128, *plStack_128 = lVar24 + -1, lVar24 + -1 == 0)) {
        (**(code **)(plStack_128[1] + 0x30))(plStack_128);
      }
      if ((plStack_110 != (longlong *)0x0) &&
         (lVar24 = *plStack_110, *plStack_110 = lVar24 + -1, lVar24 + -1 == 0)) {
        (**(code **)(plStack_110[1] + 0x30))(plStack_110);
      }
      if ((plStack_130 != (longlong *)0x0) &&
         (lVar24 = *plStack_130, *plStack_130 = lVar24 + -1, lVar24 + -1 == 0)) {
        (**(code **)(plStack_130[1] + 0x30))(plStack_130);
      }
      if ((plStack_108 != (longlong *)0x0) &&
         (lVar24 = *plStack_108, *plStack_108 = lVar24 + -1, lVar24 + -1 == 0)) {
        (**(code **)(plStack_108[1] + 0x30))(plStack_108);
      }
      *plVar3 = *plVar3 + -1;
      if (*plVar3 == 0) {
        (**(code **)(plVar3[1] + 0x30))(plVar3);
      }
      lVar24 = *plVar2;
      *plVar2 = lVar24 + -1;
      if (lVar24 + -1 != 0) {
        return plVar12;
      }
      (**(code **)(plVar2[1] + 0x30))(plVar2);
      return plVar12;
    }
    plVar16 = (longlong *)FUN_23a388310(plVar2);
    if (plVar16 == (longlong *)0x0) {
      pcVar21 = *(code **)(param_1 + 0x60);
      uVar14 = *(undefined8 *)(param_1 + 0x68);
      plVar12 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
    }
    else {
      plStack_f0 = (longlong *)FUN_23a3c1d30(param_1,auStack_78,plVar16,0,CONCAT44(uVar23,3));
      if (plStack_f0 == (longlong *)0x0) {
        plStack_e8 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
      }
      else {
        plStack_f8 = (longlong *)FUN_23a3c1d30(param_1,auStack_78,plVar16,1,3);
        if (plStack_f8 == (longlong *)0x0) {
          plStack_e8 = (longlong *)0x0;
        }
        else {
          plStack_e8 = (longlong *)FUN_23a3c1d30(param_1,auStack_78,plVar16,2,3);
          if ((plStack_e8 != (longlong *)0x0) &&
             (cVar7 = FUN_23a3884a0(param_1,auStack_78,plVar16), cVar7 != '\0')) {
            *plVar16 = *plVar16 + -1;
            if (*plVar16 == 0) {
              FUN_23a334bc0(plVar16);
            }
            if (*plStack_f0 == 0) {
              FUN_23a334bc0();
            }
            if (*plStack_f8 == 0) {
              FUN_23a334bc0();
            }
            if (*plStack_e8 == 0) {
              FUN_23a334bc0();
            }
            uVar14 = DAT_23eedd4c0;
            *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
            FUN_23a3a0d40(uVar14);
            plVar12 = (longlong *)FUN_23e8dc450();
            if (plVar12 == (longlong *)0x0) {
              plStack_b0 = (longlong *)0x0;
              FUN_23e915740(param_1,auStack_78,_DAT_23eedd5b8);
              plStack_108 = (longlong *)0x0;
              plStack_118 = (longlong *)0x0;
              uVar23 = 0x1a4;
              plStack_100 = (longlong *)0x0;
              plStack_d8 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plStack_128 = (longlong *)0x0;
              plStack_98 = (longlong *)0x0;
              pcStack_120 = _Py_NoneStruct_exref;
              plStack_e0 = (longlong *)0x0;
              goto LAB_23e813eac;
            }
            lVar24 = *(longlong *)(DAT_23eedd0f0 + 0x20);
            if (*(char *)(lVar24 + 10) == '\0') {
              plVar16 = (longlong *)FUN_23a37a020(DAT_23eedd0f0,_DAT_23eedd5c0);
              if (plVar16 == (longlong *)0x0) goto LAB_23e818409;
              lVar22 = *plVar16;
LAB_23e818400:
              if (lVar22 == 0) goto LAB_23e818409;
            }
            else {
              iVar8 = *(int *)(lVar24 + 0xc);
              if (*(int *)(lVar24 + 0xc) == 0) {
                *(int *)(lVar24 + 0xc) = DAT_23ec155d8;
                iVar8 = DAT_23ec155d8;
                DAT_23ec155d8 = DAT_23ec155d8 + 1;
              }
              if (_DAT_23ec155a8 != iVar8) {
                _DAT_23ec155a8 = iVar8;
                _DAT_23eede830 =
                     FUN_23e8cbd60(lVar24,_DAT_23eedd5c0,*(undefined8 *)(_DAT_23eedd5c0 + 0x18));
              }
              if (-1 < _DAT_23eede830) {
                lVar1 = lVar24 + 0x20 + (1L << (*(byte *)(lVar24 + 9) & 0x3f));
                lVar22 = *(longlong *)(lVar1 + 8 + _DAT_23eede830 * 0x10);
                if (lVar22 != 0) goto LAB_23e81628b;
                _DAT_23eede830 =
                     FUN_23e8cbd60(lVar24,_DAT_23eedd5c0,*(undefined8 *)(_DAT_23eedd5c0 + 0x18));
                if (-1 < _DAT_23eede830) {
                  lVar22 = *(longlong *)(lVar1 + 8 + _DAT_23eede830 * 0x10);
                  goto LAB_23e818400;
                }
              }
LAB_23e818409:
              plVar16 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedd5c0);
              if ((plVar16 == (longlong *)0x0) || (lVar22 = *plVar16, lVar22 == 0)) {
                plStack_b0 = (longlong *)0x0;
                plStack_98 = (longlong *)0x0;
                FUN_23e915740(param_1,auStack_78,_DAT_23eedd5c0);
                plStack_118 = (longlong *)0x0;
                uVar23 = 0x1a4;
                plStack_100 = (longlong *)0x0;
                plStack_d8 = (longlong *)0x0;
                plStack_e0 = (longlong *)0x0;
                plStack_108 = (longlong *)0x0;
                plStack_130 = (longlong *)0x0;
                plStack_110 = (longlong *)0x0;
                plStack_128 = (longlong *)0x0;
                pcStack_120 = _Py_NoneStruct_exref;
                goto LAB_23e813eac;
              }
            }
LAB_23e81628b:
            *(undefined4 *)(plVar4 + 5) = 0x1a4;
            plStack_88 = plVar12;
            lStack_80 = lVar22;
            plStack_e0 = (longlong *)FUN_23e94ed00();
            pcStack_120 = _Py_NoneStruct_exref;
            if (plStack_e0 != (longlong *)0x0) {
              plStack_d8 = (longlong *)FUN_23e8c4990(plStack_e0);
              if (plStack_d8 == (longlong *)0x0) {
                auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                plStack_b0 = (longlong *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                plStack_98 = (longlong *)0x0;
                uVar23 = 0x1a5;
                plStack_108 = (longlong *)0x0;
                plStack_130 = (longlong *)0x0;
                plStack_110 = (longlong *)0x0;
                plStack_128 = (longlong *)0x0;
                plStack_118 = (longlong *)0x0;
                plStack_100 = (longlong *)0x0;
                pcStack_120 = _Py_NoneStruct_exref;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e813eac;
              }
              plVar12 = (longlong *)FUN_23e9834c0(param_1,plVar15);
              if (plVar12 == (longlong *)0x0) {
                auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                plStack_b0 = (longlong *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar23 = 0x1a7;
                plStack_108 = (longlong *)0x0;
                plStack_130 = (longlong *)0x0;
                plStack_110 = (longlong *)0x0;
                plStack_128 = (longlong *)0x0;
                plStack_118 = (longlong *)0x0;
                plStack_100 = (longlong *)0x0;
                pcStack_120 = _Py_NoneStruct_exref;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plStack_98 = (longlong *)0x0;
                goto LAB_23e813eac;
              }
              plVar16 = (longlong *)FUN_23ebf7180(plVar12);
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                FUN_23a334bc0(plVar12);
              }
              if (plVar16 == (longlong *)0x0) {
                auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                plStack_118 = (longlong *)0x0;
                plStack_98 = (longlong *)0x0;
                uVar23 = 0x1a7;
                plStack_100 = (longlong *)0x0;
                pcStack_120 = _Py_NoneStruct_exref;
                *(undefined8 *)(param_1 + 0x70) = 0;
                plStack_108 = (longlong *)0x0;
                plStack_130 = (longlong *)0x0;
                plStack_110 = (longlong *)0x0;
                plStack_128 = (longlong *)0x0;
                plStack_b0 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e813eac;
              }
              plStack_b0 = (longlong *)0x0;
              plStack_108 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plStack_128 = (longlong *)0x0;
              pcStack_120 = _Py_NoneStruct_exref;
              plStack_118 = (longlong *)0x0;
              plStack_100 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_98 = (longlong *)0x0;
LAB_23e816428:
              plVar12 = (longlong *)(**(code **)(plVar16[1] + 0xe0))();
              if (plVar12 == (longlong *)0x0) goto LAB_23e8180c2;
              if (plStack_98 == (longlong *)0x0) {
                *plVar12 = *plVar12 + 1;
              }
              else {
                *plStack_98 = *plStack_98 + -1;
                if (*plStack_98 == 0) {
                  FUN_23a334bc0(plStack_98);
                }
                *plVar12 = *plVar12 + 1;
                *plStack_98 = *plStack_98 + -1;
                if (*plStack_98 == 0) {
                  FUN_23a334bc0(plStack_98);
                }
              }
              plStack_98 = plVar12;
              if (plVar3 == (longlong *)0x0) {
                FUN_23e8ba2b0(auStack_78,DAT_23eedd4b0);
                if (((code *)auStack_78._0_8_ != _Py_NoneStruct_exref) &&
                   ((code *)auStack_78._0_8_ != (code *)0x0)) {
                  FUN_23e91b1b0(param_1,auStack_78,auStack_78 + 8,aplStack_68);
                }
                FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),auStack_78._8_8_);
LAB_23e817e7f:
                uVar23 = 0x1a8;
                plStack_a8 = plStack_118;
                goto LAB_23e817302;
              }
              plVar12 = (longlong *)FUN_23e8bc2f0(plVar3);
              if (plVar12 == (longlong *)0x0) {
LAB_23e817f84:
                auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e817e7f;
              }
              lVar24 = *(longlong *)(DAT_23eedd0f0 + 0x20);
              if (*(char *)(lVar24 + 10) != '\0') {
                iVar8 = *(int *)(lVar24 + 0xc);
                if (*(int *)(lVar24 + 0xc) == 0) {
                  *(int *)(lVar24 + 0xc) = DAT_23ec155d8;
                  iVar8 = DAT_23ec155d8;
                  DAT_23ec155d8 = DAT_23ec155d8 + 1;
                }
                if (_DAT_23ec155ac != iVar8) {
                  _DAT_23ec155ac = iVar8;
                  _DAT_23eede838 =
                       FUN_23e8cbd60(lVar24,_DAT_23eedd5d0,*(undefined8 *)(_DAT_23eedd5d0 + 0x18));
                }
                if (-1 < _DAT_23eede838) {
                  lVar22 = lVar24 + 0x20 + (1L << (*(byte *)(lVar24 + 9) & 0x3f));
                  if (*(longlong *)(lVar22 + 8 + _DAT_23eede838 * 0x10) != 0) goto LAB_23e81652d;
                  _DAT_23eede838 =
                       FUN_23e8cbd60(lVar24,_DAT_23eedd5d0,*(undefined8 *)(_DAT_23eedd5d0 + 0x18));
                  if (-1 < _DAT_23eede838) {
                    lVar24 = *(longlong *)(lVar22 + 8 + _DAT_23eede838 * 0x10);
                    goto LAB_23e817ec9;
                  }
                }
LAB_23e817ed2:
                plVar17 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedd5d0);
                if ((plVar17 != (longlong *)0x0) && (*plVar17 != 0)) goto LAB_23e81652d;
                FUN_23e915740(param_1,auStack_78,_DAT_23eedd5d0);
                *plVar12 = *plVar12 + -1;
                lVar24 = *plVar12;
joined_r0x00023e817f5c:
                if (lVar24 == 0) {
                  FUN_23a334bc0(plVar12);
                }
                goto LAB_23e817e7f;
              }
              plVar17 = (longlong *)FUN_23a37a020(DAT_23eedd0f0,_DAT_23eedd5d0);
              if (plVar17 == (longlong *)0x0) goto LAB_23e817ed2;
              lVar24 = *plVar17;
LAB_23e817ec9:
              if (lVar24 == 0) goto LAB_23e817ed2;
LAB_23e81652d:
              plVar17 = (longlong *)FUN_23e8c4990();
              if (plVar17 == (longlong *)0x0) {
LAB_23e817e02:
                auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar12 = *plVar12 + -1;
                lVar24 = *plVar12;
                goto joined_r0x00023e817f5c;
              }
              plVar18 = (longlong *)FUN_23e8c09e0(plVar13,plVar17);
              *plVar17 = *plVar17 + -1;
              if (*plVar17 == 0) {
                FUN_23a334bc0();
              }
              if (plVar18 == (longlong *)0x0) goto LAB_23e817e02;
              *(undefined4 *)(plVar4 + 5) = 0x1a8;
              plVar17 = (longlong *)FUN_23e914090(param_1,plVar12,plVar18);
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                FUN_23a334bc0(plVar12);
              }
              *plVar18 = *plVar18 + -1;
              if (*plVar18 == 0) {
                FUN_23a334bc0(plVar18);
              }
              if (plVar17 == (longlong *)0x0) goto LAB_23e817f84;
              if ((plStack_100 != (longlong *)0x0) &&
                 (lVar24 = *plStack_100, *plStack_100 = lVar24 + -1, lVar24 + -1 == 0)) {
                FUN_23a334bc0(plStack_100);
              }
              *(undefined4 *)(plVar4 + 5) = 0x1a9;
              plVar12 = (longlong *)FUN_23e915840(param_1,plVar3,_DAT_23eedd530,plVar17);
              plStack_100 = plVar17;
              if (plVar12 == (longlong *)0x0) {
LAB_23e817d89:
                aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                uVar23 = 0x1a9;
                *(undefined8 *)(param_1 + 0x70) = 0;
                plStack_a8 = plStack_118;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e817302;
              }
              iVar8 = FUN_23a35f020(plVar12);
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                FUN_23a334bc0(plVar12);
              }
              if (iVar8 == -1) goto LAB_23e817d89;
              plVar12 = plStack_130;
              if (iVar8 == 0) {
LAB_23e81662b:
                plStack_a8 = plStack_118;
                goto LAB_23e816643;
              }
              plVar18 = (longlong *)FUN_23e8bc2f0(plVar3,_DAT_23eedd150);
              if (plVar18 == (longlong *)0x0) {
LAB_23e817bb8:
                aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                uVar23 = 0x1ab;
                *(undefined8 *)(param_1 + 0x70) = 0;
                plStack_a8 = plStack_118;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e817302;
              }
              iVar8 = FUN_23e912620(plVar17,plVar18);
              *plVar18 = *plVar18 + -1;
              if (*plVar18 == 0) {
                FUN_23a334bc0(plVar18);
              }
              if (iVar8 == -1) goto LAB_23e817bb8;
              if (iVar8 == 1) goto LAB_23e81662b;
              *(undefined4 *)(plVar4 + 5) = 0x1ae;
              plStack_a8 = (longlong *)FUN_23e915840(param_1,plVar3,_DAT_23eedd5d8,plVar17);
              if (plStack_a8 == (longlong *)0x0) {
                aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                uVar23 = 0x1ae;
                *(undefined8 *)(param_1 + 0x70) = 0;
                plStack_a8 = plStack_118;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e817302;
              }
              if ((plStack_118 != (longlong *)0x0) &&
                 (lVar24 = *plStack_118, *plStack_118 = lVar24 + -1, lVar24 + -1 == 0)) {
                FUN_23a334bc0(plStack_118);
              }
              lVar24 = *(longlong *)(DAT_23eedd0f0 + 0x20);
              if (*(char *)(lVar24 + 10) != '\0') {
                iVar8 = *(int *)(lVar24 + 0xc);
                if (*(int *)(lVar24 + 0xc) == 0) {
                  *(int *)(lVar24 + 0xc) = DAT_23ec155d8;
                  iVar8 = DAT_23ec155d8;
                  DAT_23ec155d8 = DAT_23ec155d8 + 1;
                }
                if (_DAT_23ec155b0 != iVar8) {
                  _DAT_23ec155b0 = iVar8;
                  _DAT_23eede840 = FUN_23e8cbd60(lVar24);
                }
                if (-1 < _DAT_23eede840) {
                  lVar22 = lVar24 + 0x20 + (1L << (*(byte *)(lVar24 + 9) & 0x3f));
                  if (*(longlong *)(lVar22 + 8 + _DAT_23eede840 * 0x10) != 0) goto LAB_23e816eb0;
                  _DAT_23eede840 = FUN_23e8cbd60(lVar24);
                  if (-1 < _DAT_23eede840) {
                    lVar24 = *(longlong *)(lVar22 + 8 + _DAT_23eede840 * 0x10);
                    goto LAB_23e817a86;
                  }
                }
LAB_23e817a8f:
                plVar18 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedd5e0);
                if ((plVar18 != (longlong *)0x0) && (*plVar18 != 0)) goto LAB_23e816eb0;
                FUN_23e915740(param_1,auStack_78,_DAT_23eedd5e0);
LAB_23e817a4c:
                uVar23 = 0x1af;
                goto LAB_23e817302;
              }
              plVar18 = (longlong *)FUN_23a37a020(DAT_23eedd0f0,_DAT_23eedd5e0);
              if (plVar18 == (longlong *)0x0) goto LAB_23e817a8f;
              lVar24 = *plVar18;
LAB_23e817a86:
              if (lVar24 == 0) goto LAB_23e817a8f;
LAB_23e816eb0:
              iVar8 = FUN_23e983ac0(plStack_a8);
              if (iVar8 == -1) {
                aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e817a4c;
              }
              if (iVar8 == 1) {
LAB_23e816643:
                plStack_118 = plStack_a8;
                plStack_130 = plVar12;
                goto LAB_23e816428;
              }
              *(undefined4 *)(plVar4 + 5) = 0x1b2;
              plVar18 = (longlong *)FUN_23e915840(param_1,plVar3,_DAT_23eedd270,plVar17);
              if (plVar18 == (longlong *)0x0) {
                auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                uVar23 = 0x1b2;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e817302;
              }
              if ((plStack_b0 != (longlong *)0x0) &&
                 (*plStack_b0 = *plStack_b0 + -1, *plStack_b0 == 0)) {
                FUN_23a334bc0(plStack_b0);
              }
              iVar8 = FUN_23a35f020(plVar18);
              plStack_b0 = plVar18;
              if (iVar8 == -1) {
                auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar23 = 0x1b3;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e817302;
              }
              if (iVar8 == 0) goto LAB_23e816643;
              plVar12 = (longlong *)FUN_23a388650(param_1,plVar18,DAT_23ed6ccf0,0);
              if (plVar12 == (longlong *)0x0) {
LAB_23e8178c8:
                auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar23 = 0x1b5;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e817302;
              }
              plVar19 = (longlong *)FUN_23e8c6640(plVar12,plStack_f0);
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                FUN_23a334bc0(plVar12);
              }
              if (plVar19 == (longlong *)0x0) goto LAB_23e8178c8;
              if ((plStack_128 != (longlong *)0x0) &&
                 (lVar24 = *plStack_128, *plStack_128 = lVar24 + -1, lVar24 + -1 == 0)) {
                FUN_23a334bc0(plStack_128);
              }
              plVar12 = (longlong *)FUN_23a388650(param_1,plVar18,DAT_23ed6ccf8,1);
              plStack_128 = plVar19;
              if (plVar12 == (longlong *)0x0) {
LAB_23e81785f:
                auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                uVar23 = 0x1b6;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e817302;
              }
              plVar20 = (longlong *)FUN_23e8c6640(plVar12,plStack_f8);
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                FUN_23a334bc0(plVar12);
              }
              if (plVar20 == (longlong *)0x0) goto LAB_23e81785f;
              if ((plStack_110 != (longlong *)0x0) &&
                 (lVar24 = *plStack_110, *plStack_110 = lVar24 + -1, lVar24 + -1 == 0)) {
                FUN_23a334bc0(plStack_110);
              }
              plVar18 = (longlong *)FUN_23a388650(param_1,plVar18);
              plStack_110 = plVar20;
              if (plVar18 == (longlong *)0x0) {
LAB_23e8177ed:
                auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar23 = 0x1b7;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e817302;
              }
              plVar12 = (longlong *)FUN_23e8c6640(plVar18,plStack_e8);
              *plVar18 = *plVar18 + -1;
              if (*plVar18 == 0) {
                FUN_23a334bc0(plVar18);
              }
              if (plVar12 == (longlong *)0x0) goto LAB_23e8177ed;
              if ((plStack_130 != (longlong *)0x0) &&
                 (*plStack_130 = *plStack_130 + -1, *plStack_130 == 0)) {
                FUN_23a334bc0(plStack_130);
              }
              plVar18 = (longlong *)FUN_23e8c4990(plVar19,plVar19);
              plStack_130 = plVar12;
              if (plVar18 != (longlong *)0x0) {
                plVar19 = (longlong *)FUN_23e8c4990(plVar20,plVar20);
                if (plVar19 == (longlong *)0x0) {
                  auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                  auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                  aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar18 = *plVar18 + -1;
                  if (*plVar18 == 0) {
                    FUN_23a334bc0(plVar18,0);
                  }
                  goto LAB_23e8175e9;
                }
                plVar20 = (longlong *)FUN_23e8c09e0(plVar18);
                *plVar18 = *plVar18 + -1;
                if (*plVar18 == 0) {
                  FUN_23a334bc0(plVar18);
                }
                *plVar19 = *plVar19 + -1;
                if (*plVar19 == 0) {
                  FUN_23a334bc0(plVar19);
                }
                if (plVar20 == (longlong *)0x0) goto LAB_23e817798;
                plVar18 = (longlong *)FUN_23e8c4990(plVar12);
                if (plVar18 == (longlong *)0x0) {
                  auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                  auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                  aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar20 = *plVar20 + -1;
                  if (*plVar20 == 0) {
                    FUN_23a334bc0(plVar20);
                  }
                  goto LAB_23e8175e9;
                }
                plVar19 = (longlong *)FUN_23e8c09e0(plVar20);
                *plVar20 = *plVar20 + -1;
                if (*plVar20 == 0) {
                  FUN_23a334bc0(plVar20);
                }
                *plVar18 = *plVar18 + -1;
                if (*plVar18 == 0) {
                  FUN_23a334bc0(plVar18);
                }
                if (plVar19 != (longlong *)0x0) {
                  if ((plStack_108 != (longlong *)0x0) &&
                     (lVar24 = *plStack_108, *plStack_108 = lVar24 + -1, lVar24 + -1 == 0)) {
                    FUN_23a334bc0(plStack_108);
                  }
                  iVar8 = FUN_23e97dbc0(plVar19,plStack_d8);
                  plStack_108 = plVar19;
                  if (iVar8 == -1) {
                    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    uVar23 = 0x1b9;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  else {
                    if (iVar8 == 1) goto LAB_23e816643;
                    if (pcStack_120 == (code *)0x0) {
                      FUN_23e8ba2b0(auStack_78,_DAT_23eedd600);
                      if (((code *)auStack_78._0_8_ != _Py_NoneStruct_exref) &&
                         ((code *)auStack_78._0_8_ != (code *)0x0)) {
                        FUN_23e91b1b0(param_1,auStack_78,auStack_78 + 8,aplStack_68);
                      }
                      FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),auStack_78._8_8_);
                      uVar23 = 0x1bc;
                    }
                    else if (pcStack_120 == _Py_NoneStruct_exref) {
LAB_23e817401:
                      pcVar21 = (code *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                      *plVar19 = *plVar19 + 1;
                      *(longlong **)(pcVar21 + 0x18) = plVar19;
                      *plVar17 = *plVar17 + 1;
                      *(longlong **)(pcVar21 + 0x20) = plVar17;
                      lVar24 = *(longlong *)pcStack_120;
                      *(longlong *)pcStack_120 = lVar24 + -1;
                      if (lVar24 + -1 == 0) {
                        FUN_23a334bc0(pcStack_120);
                      }
LAB_23e817251:
                      pcStack_120 = pcVar21;
                      cVar7 = FUN_23a3a5fe0(param_1);
                      if (cVar7 != '\0') goto LAB_23e816643;
                      aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                      uVar23 = 0x1a7;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    }
                    else {
                      plVar18 = (longlong *)FUN_23a388650(param_1,pcStack_120,DAT_23ed6ccf0,0);
                      if (plVar18 != (longlong *)0x0) {
                        iVar8 = FUN_23e97c060(plVar19,plVar18);
                        *plVar18 = *plVar18 + -1;
                        if (*plVar18 == 0) {
                          FUN_23a334bc0(plVar18);
                        }
                        if (iVar8 != -1) {
                          pcVar21 = pcStack_120;
                          if (iVar8 == 1) goto LAB_23e817401;
                          goto LAB_23e817251;
                        }
                      }
                      aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                      uVar23 = 0x1bc;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    }
                  }
                  goto LAB_23e817302;
                }
              }
LAB_23e817798:
              auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
              auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
              aplStack_68[0] = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e8175e9:
              uVar23 = 0x1b8;
              goto LAB_23e817302;
            }
            auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
            auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
            aplStack_68[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            plStack_98 = (longlong *)0x0;
            plStack_b0 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_130 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            uVar23 = 0x1a4;
            plStack_118 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e813eac;
          }
        }
      }
      plVar12 = aplStack_68[0];
      uVar14 = auStack_78._8_8_;
      pcVar21 = (code *)auStack_78._0_8_;
      auStack_78 = (undefined1  [16])0x0;
      aplStack_68[0] = (longlong *)0x0;
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        FUN_23a334bc0(plVar16);
      }
      aplStack_68[0] = (longlong *)0x0;
      auStack_78._0_8_ = 0;
      auStack_78._8_8_ = 0;
      if ((plStack_f0 != (longlong *)0x0) &&
         (lVar24 = *plStack_f0, *plStack_f0 = lVar24 + -1, lVar24 + -1 == 0)) {
        FUN_23a334bc0(plStack_f0);
      }
      if ((plStack_f8 != (longlong *)0x0) &&
         (lVar24 = *plStack_f8, *plStack_f8 = lVar24 + -1, lVar24 + -1 == 0)) {
        FUN_23a334bc0(plStack_f8);
      }
      if ((plStack_e8 != (longlong *)0x0) &&
         (lVar24 = *plStack_e8, *plStack_e8 = lVar24 + -1, lVar24 + -1 == 0)) {
        FUN_23a334bc0(plStack_e8);
      }
    }
    uVar23 = 0x1a2;
    auStack_78._0_8_ = pcVar21;
    auStack_78._8_8_ = uVar14;
  }
  plStack_b0 = (longlong *)0x0;
  plStack_98 = (longlong *)0x0;
  plStack_108 = (longlong *)0x0;
  plStack_130 = (longlong *)0x0;
  plStack_110 = (longlong *)0x0;
  plStack_128 = (longlong *)0x0;
  plStack_118 = (longlong *)0x0;
  plStack_100 = (longlong *)0x0;
  plStack_d8 = (longlong *)0x0;
  plStack_e0 = (longlong *)0x0;
  pcStack_120 = (code *)0x0;
  plStack_e8 = (longlong *)0x0;
  plStack_f8 = (longlong *)0x0;
  plStack_f0 = (longlong *)0x0;
  aplStack_68[0] = plVar12;
LAB_23e813eac:
  plVar15 = aplStack_68[0];
  plVar12 = DAT_23ed6a4f8;
  if (aplStack_68[0] == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar15 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar15;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar12[2] = 0;
    plVar12[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar23;
    pcVar21 = _PyRuntime_exref;
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar24 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar21 + 0x1f8) + 0x10) + 0x2e8);
    lVar22 = plVar12[-1];
    puVar5 = *(undefined8 **)(lVar24 + 8);
    *puVar5 = plVar12 + -2;
    plVar12[-2] = lVar24;
    plVar12[-1] = (ulonglong)((uint)lVar22 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar24 + 8) = plVar12 + -2;
    plVar15 = plVar12;
    if ((aplStack_68[0] != (longlong *)0x0) &&
       (*aplStack_68[0] = *aplStack_68[0] + -1, *aplStack_68[0] == 0)) {
      (**(code **)(aplStack_68[0][1] + 0x30))(aplStack_68[0]);
    }
  }
  else if ((longlong *)aplStack_68[0][3] != plVar4) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar16 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar16;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar12[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar23;
    pcVar21 = _PyRuntime_exref;
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar24 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar21 + 0x1f8) + 0x10) + 0x2e8);
    puVar5 = *(undefined8 **)(lVar24 + 8);
    *puVar5 = plVar12 + -2;
    plVar12[-2] = lVar24;
    plVar12[-1] = (ulonglong)puVar5 | (ulonglong)((uint)plVar12[-1] & 3);
    *(longlong **)(lVar24 + 8) = plVar12 + -2;
    plVar12[2] = (longlong)plVar15;
    *plVar15 = *plVar15 + 1;
    plVar15 = plVar12;
    if ((aplStack_68[0] != (longlong *)0x0) &&
       (*aplStack_68[0] = *aplStack_68[0] + -1, *aplStack_68[0] == 0)) {
      (**(code **)(aplStack_68[0][1] + 0x30))();
    }
  }
  aplStack_68[0] = plVar15;
  FUN_23e8bba40(plVar4,"oooooooooooooooooooo",plVar3,plVar2,plVar9,plVar11,plVar10,plVar13,
                plStack_f0,plStack_f8,plStack_e8,pcStack_120,plStack_e0,plStack_d8,plStack_98,
                plStack_100,plStack_118,plStack_b0,plStack_128,plStack_110,plStack_130,plStack_108);
  if (_DAT_23eede848 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eede848 = (longlong *)0x0;
  }
  lVar24 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar4 = *(longlong **)(lVar24 + 0x28);
  plVar12 = (longlong *)plVar4[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar24 + 0x30);
  *(undefined4 *)(plVar4 + 8) = 0xffffffff;
  if (plVar12 != (longlong *)0x0) {
    plVar4[2] = 0;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))();
    }
  }
  *plVar4 = *plVar4 + -1;
  if (*plVar4 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  plVar12 = aplStack_68[0];
  uVar6 = auStack_78._8_8_;
  uVar14 = auStack_78._0_8_;
  plVar4[0xf] = 0;
  auStack_78 = (undefined1  [16])0x0;
  aplStack_68[0] = (longlong *)0x0;
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plStack_f0 != (longlong *)0x0) &&
     (lVar24 = *plStack_f0, *plStack_f0 = lVar24 + -1, lVar24 + -1 == 0)) {
    (**(code **)(plStack_f0[1] + 0x30))(plStack_f0);
  }
  if ((plStack_f8 != (longlong *)0x0) &&
     (lVar24 = *plStack_f8, *plStack_f8 = lVar24 + -1, lVar24 + -1 == 0)) {
    (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
  }
  if ((plStack_e8 != (longlong *)0x0) &&
     (lVar24 = *plStack_e8, *plStack_e8 = lVar24 + -1, lVar24 + -1 == 0)) {
    (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
  }
  if ((pcStack_120 != (code *)0x0) &&
     (lVar24 = *(longlong *)pcStack_120, *(longlong *)pcStack_120 = lVar24 + -1, lVar24 + -1 == 0))
  {
    (**(code **)(*(longlong *)(pcStack_120 + 8) + 0x30))(pcStack_120);
  }
  if ((plStack_e0 != (longlong *)0x0) &&
     (lVar24 = *plStack_e0, *plStack_e0 = lVar24 + -1, lVar24 + -1 == 0)) {
    (**(code **)(plStack_e0[1] + 0x30))();
  }
  if ((plStack_d8 != (longlong *)0x0) &&
     (lVar24 = *plStack_d8, *plStack_d8 = lVar24 + -1, lVar24 + -1 == 0)) {
    (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
  }
  if ((plStack_98 != (longlong *)0x0) && (*plStack_98 = *plStack_98 + -1, *plStack_98 == 0)) {
    (**(code **)(plStack_98[1] + 0x30))(plStack_98);
  }
  if ((plStack_100 != (longlong *)0x0) &&
     (lVar24 = *plStack_100, *plStack_100 = lVar24 + -1, lVar24 + -1 == 0)) {
    (**(code **)(plStack_100[1] + 0x30))(plStack_100);
  }
  if ((plStack_118 != (longlong *)0x0) &&
     (lVar24 = *plStack_118, *plStack_118 = lVar24 + -1, lVar24 + -1 == 0)) {
    (**(code **)(plStack_118[1] + 0x30))(plStack_118);
  }
  if ((plStack_b0 != (longlong *)0x0) && (*plStack_b0 = *plStack_b0 + -1, *plStack_b0 == 0)) {
    (**(code **)(plStack_b0[1] + 0x30))(plStack_b0);
  }
  if ((plStack_128 != (longlong *)0x0) &&
     (lVar24 = *plStack_128, *plStack_128 = lVar24 + -1, lVar24 + -1 == 0)) {
    (**(code **)(plStack_128[1] + 0x30))(plStack_128);
  }
  if ((plStack_110 != (longlong *)0x0) &&
     (lVar24 = *plStack_110, *plStack_110 = lVar24 + -1, lVar24 + -1 == 0)) {
    (**(code **)(plStack_110[1] + 0x30))(plStack_110);
  }
  if ((plStack_130 != (longlong *)0x0) &&
     (lVar24 = *plStack_130, *plStack_130 = lVar24 + -1, lVar24 + -1 == 0)) {
    (**(code **)(plStack_130[1] + 0x30))(plStack_130);
  }
  if ((plStack_108 != (longlong *)0x0) &&
     (lVar24 = *plStack_108, *plStack_108 = lVar24 + -1, lVar24 + -1 == 0)) {
    (**(code **)(plStack_108[1] + 0x30))(plStack_108);
  }
  auStack_78 = CONCAT88(uVar6,uVar14);
  *plVar3 = *plVar3 + -1;
  aplStack_68[0] = plVar12;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  lVar24 = *plVar2;
  *plVar2 = lVar24 + -1;
  if (lVar24 + -1 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,auStack_78._0_8_,auStack_78._8_8_,aplStack_68[0]);
  return (longlong *)0x0;
LAB_23e8180c2:
  cVar7 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
  if (cVar7 == '\0') {
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar23 = 0x1a7;
    plStack_a8 = plStack_118;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e817302:
    plVar12 = aplStack_68[0];
    uVar6 = auStack_78._8_8_;
    uVar14 = auStack_78._0_8_;
    auStack_78 = (undefined1  [16])0x0;
    aplStack_68[0] = (longlong *)0x0;
    if ((plStack_98 != (longlong *)0x0) &&
       (lVar24 = *plStack_98, *plStack_98 = lVar24 + -1, lVar24 + -1 == 0)) {
      FUN_23a334bc0();
    }
    lVar24 = *plVar16;
    *plVar16 = lVar24 + -1;
    if (lVar24 + -1 == 0) {
      FUN_23a334bc0();
    }
    plStack_118 = plStack_a8;
    aplStack_68[0] = plVar12;
    auStack_78._0_8_ = uVar14;
    auStack_78._8_8_ = uVar6;
  }
  else {
    if ((plStack_98 != (longlong *)0x0) && (*plStack_98 = *plStack_98 + -1, *plStack_98 == 0)) {
      FUN_23a334bc0(plStack_98);
    }
    lVar24 = *plVar16;
    *plVar16 = lVar24 + -1;
    if (lVar24 + -1 == 0) {
      FUN_23a334bc0();
    }
    if (pcStack_120 == (code *)0x0) {
      FUN_23e8ba2b0(auStack_78,_DAT_23eedd600);
      if (((code *)auStack_78._0_8_ != _Py_NoneStruct_exref) &&
         ((code *)auStack_78._0_8_ != (code *)0x0)) {
        FUN_23e91b1b0(param_1,auStack_78,auStack_78 + 8,aplStack_68);
      }
      FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),auStack_78._8_8_);
      uVar23 = 0x1bf;
      goto LAB_23e813eac;
    }
    iVar8 = FUN_23a35f020(pcStack_120);
    plVar12 = DAT_23ed6ccf0;
    if (iVar8 != -1) {
      if (iVar8 == 0) {
        *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
        goto LAB_23e81382b;
      }
      plVar12 = (longlong *)FUN_23a388650(param_1,pcStack_120,DAT_23ed6ccf8,1);
      if (plVar12 != (longlong *)0x0) goto LAB_23e81382b;
    }
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    uVar23 = 0x1bf;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  goto LAB_23e813eac;
}
