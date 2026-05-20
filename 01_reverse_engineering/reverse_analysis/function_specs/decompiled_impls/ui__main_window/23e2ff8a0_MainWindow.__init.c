/* ===== 23e2ff8a0 ui.main_window:c1569 ===== */
/* ghidra_name=FUN_23e2ff8a0 entry=23e2ff8a0 size=23816 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2ff8a0(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  uint uVar2;
  int iVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  undefined8 uVar6;
  code *pcVar7;
  char cVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong lVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong *plVar18;
  longlong lVar19;
  longlong *plVar20;
  longlong *plVar21;
  longlong lVar22;
  longlong *plStack_b0;
  longlong *plStack_a8;
  longlong *plStack_a0;
  longlong *plStack_98;
  longlong *plStack_90;
  undefined8 uStack_88;
  undefined4 uStack_80;
  longlong *plStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar21 = DAT_23ed6a4e0;
  lVar15 = *param_3;
  if (DAT_23ed6a4e0 == (longlong *)0x0) {
    plVar21 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
  }
  else {
    plVar10 = (longlong *)*DAT_23ed6a4e0;
    *DAT_23ed6a4e0 = 1;
    DAT_23ed6a4e0 = plVar10;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
  }
  pcVar7 = _PyRuntime_exref;
  plVar21[2] = lVar15;
  plVar10 = _DAT_23eeafef0;
  lVar22 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar7 + 0x1f8) + 0x10) + 0x2e8);
  lVar19 = plVar21[-1];
  puVar4 = *(undefined8 **)(lVar22 + 8);
  *puVar4 = plVar21 + -2;
  plVar21[-2] = lVar22;
  plVar21[-1] = (ulonglong)((uint)lVar19 & 3) | (ulonglong)puVar4;
  *(longlong **)(lVar22 + 8) = plVar21 + -2;
  if (plVar10 == (longlong *)0x0) {
LAB_23e2ff956:
    plVar10 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeac680,DAT_23eeac668,0x48);
    lVar15 = plVar21[2];
    _DAT_23eeafef0 = plVar10;
  }
  else {
    lVar22 = *plVar10;
    if (1 < lVar22) {
      *plVar10 = lVar22 + -1;
      goto LAB_23e2ff956;
    }
    if (plVar10[2] != 0) {
      *plVar10 = lVar22 + -1;
      if (lVar22 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e2ff956;
    }
  }
  lVar22 = *(longlong *)(param_1 + 0x38);
  lVar19 = *(longlong *)(lVar22 + 8);
  plVar10[0xf] = lVar19;
  *(longlong **)(lVar22 + 8) = plVar10 + 9;
  if ((lVar19 != 0) &&
     (((*(char *)(lVar19 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar19 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar19 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar19 + 0x38))) && (plVar10[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar19 + 0x28);
    *(longlong **)(plVar10[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar10 = *plVar10 + 1;
  uVar6 = _DAT_23eeac8c0;
  *(undefined4 *)(plVar10 + 8) = 0;
  plVar11 = (longlong *)FUN_23e8bc2f0(lVar15,uVar6);
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plVar17 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar16 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    uStack_80 = 0x70;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_98 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar13 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  lVar15 = *(longlong *)(DAT_23eeac660 + 0x20);
  if (*(char *)(lVar15 + 10) == '\0') {
    plVar12 = (longlong *)FUN_23a37a020(DAT_23eeac660,_DAT_23eeac8c8);
    if (plVar12 == (longlong *)0x0) goto LAB_23e3022f1;
    lVar15 = *plVar12;
LAB_23e3029f0:
    if (lVar15 == 0) goto LAB_23e3022f1;
  }
  else {
    iVar9 = *(int *)(lVar15 + 0xc);
    if (*(int *)(lVar15 + 0xc) == 0) {
      *(int *)(lVar15 + 0xc) = DAT_23ec14e10;
      iVar9 = DAT_23ec14e10;
      DAT_23ec14e10 = DAT_23ec14e10 + 1;
    }
    if (_DAT_23ec14db8 != iVar9) {
      _DAT_23ec14db8 = iVar9;
      _DAT_23eeafeb0 = FUN_23e8cbd60(lVar15,_DAT_23eeac8c8,*(undefined8 *)(_DAT_23eeac8c8 + 0x18));
    }
    if (-1 < _DAT_23eeafeb0) {
      lVar22 = lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f));
      if (*(longlong *)(lVar22 + 8 + _DAT_23eeafeb0 * 0x10) != 0) goto LAB_23e2ffa66;
      _DAT_23eeafeb0 = FUN_23e8cbd60(lVar15,_DAT_23eeac8c8,*(undefined8 *)(_DAT_23eeac8c8 + 0x18));
      if (-1 < _DAT_23eeafeb0) {
        lVar15 = *(longlong *)(lVar22 + 8 + _DAT_23eeafeb0 * 0x10);
        goto LAB_23e3029f0;
      }
    }
LAB_23e3022f1:
    plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeac8c8);
    if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
      FUN_23e915740(param_1,&plStack_68,_DAT_23eeac8c8);
      plStack_90 = plStack_68;
      *plVar11 = *plVar11 + -1;
      uStack_88 = uStack_60;
      plVar12 = plStack_58;
      if (*plVar11 == 0) {
        plVar17 = (longlong *)0x0;
        plVar16 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        (**(code **)(plVar11[1] + 0x30))(plVar11);
        uStack_80 = 0x70;
        plStack_98 = (longlong *)0x0;
        plStack_a0 = (longlong *)0x0;
        plStack_b0 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
      }
      else {
        plStack_a0 = (longlong *)0x0;
        plVar17 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        plStack_98 = (longlong *)0x0;
        uStack_80 = 0x70;
        plVar16 = (longlong *)0x0;
        plStack_b0 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
      }
      goto LAB_23e3024b0;
    }
  }
LAB_23e2ffa66:
  *(undefined4 *)(plVar10 + 5) = 0x70;
  plVar12 = (longlong *)FUN_23e914090(param_1,plVar11);
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if (plVar12 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plVar17 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar16 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    uStack_80 = 0x70;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_98 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar14 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  lVar15 = *(longlong *)(DAT_23eeac660 + 0x20);
  if (*(char *)(lVar15 + 10) == '\0') {
    plVar11 = (longlong *)FUN_23a37a020(DAT_23eeac660,_DAT_23eeac8d0);
    if (plVar11 == (longlong *)0x0) goto LAB_23e302409;
    lVar15 = *plVar11;
LAB_23e302a38:
    if (lVar15 == 0) goto LAB_23e302409;
  }
  else {
    iVar9 = *(int *)(lVar15 + 0xc);
    if (*(int *)(lVar15 + 0xc) == 0) {
      *(int *)(lVar15 + 0xc) = DAT_23ec14e10;
      iVar9 = DAT_23ec14e10;
      DAT_23ec14e10 = DAT_23ec14e10 + 1;
    }
    if (_DAT_23ec14dbc != iVar9) {
      _DAT_23ec14dbc = iVar9;
      _DAT_23eeafeb8 = FUN_23e8cbd60(lVar15,_DAT_23eeac8d0,*(undefined8 *)(_DAT_23eeac8d0 + 0x18));
    }
    if (-1 < _DAT_23eeafeb8) {
      lVar22 = lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f));
      if (*(longlong *)(lVar22 + 8 + _DAT_23eeafeb8 * 0x10) != 0) goto LAB_23e2ffb12;
      _DAT_23eeafeb8 = FUN_23e8cbd60(lVar15,_DAT_23eeac8d0,*(undefined8 *)(_DAT_23eeac8d0 + 0x18));
      if (-1 < _DAT_23eeafeb8) {
        lVar15 = *(longlong *)(lVar22 + 8 + _DAT_23eeafeb8 * 0x10);
        goto LAB_23e302a38;
      }
    }
LAB_23e302409:
    plVar11 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeac8d0);
    if ((plVar11 == (longlong *)0x0) || (*plVar11 == 0)) {
      plVar17 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      FUN_23e915740(param_1,&plStack_68,_DAT_23eeac8d0);
      uStack_80 = 0x73;
      plStack_98 = (longlong *)0x0;
      plStack_a0 = (longlong *)0x0;
      plStack_90 = plStack_68;
      plStack_b0 = (longlong *)0x0;
      uStack_88 = uStack_60;
      plStack_a8 = (longlong *)0x0;
      plVar12 = plStack_58;
      goto LAB_23e3024b0;
    }
  }
LAB_23e2ffb12:
  *(undefined4 *)(plVar10 + 5) = 0x73;
  plVar13 = (longlong *)FUN_23e91a870(param_1);
  if (plVar13 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plVar17 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar16 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    uStack_80 = 0x73;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_98 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3024b0;
  }
  lVar15 = plVar21[2];
  *(undefined4 *)(plVar10 + 5) = 0x74;
  plVar11 = (longlong *)FUN_23e915840(param_1,lVar15,_DAT_23eeac8d8,plVar13);
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plVar17 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar16 = (longlong *)0x0;
    uStack_80 = 0x74;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_98 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar14 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  lVar15 = *(longlong *)(DAT_23eeac660 + 0x20);
  if (*(char *)(lVar15 + 10) == '\0') {
    plVar11 = (longlong *)FUN_23a37a020(DAT_23eeac660,_DAT_23eeac8e0);
    if (plVar11 == (longlong *)0x0) goto LAB_23e302779;
    lVar22 = *plVar11;
LAB_23e302d58:
    if (lVar22 == 0) goto LAB_23e302779;
  }
  else {
    iVar9 = *(int *)(lVar15 + 0xc);
    if (*(int *)(lVar15 + 0xc) == 0) {
      *(int *)(lVar15 + 0xc) = DAT_23ec14e10;
      iVar9 = DAT_23ec14e10;
      DAT_23ec14e10 = DAT_23ec14e10 + 1;
    }
    if (_DAT_23ec14dc0 != iVar9) {
      _DAT_23ec14dc0 = iVar9;
      _DAT_23eeafec0 = FUN_23e8cbd60(lVar15,_DAT_23eeac8e0,*(undefined8 *)(_DAT_23eeac8e0 + 0x18));
    }
    if (-1 < _DAT_23eeafec0) {
      lVar19 = lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f));
      lVar22 = *(longlong *)(lVar19 + 8 + _DAT_23eeafec0 * 0x10);
      if (lVar22 != 0) goto LAB_23e2ffbd4;
      _DAT_23eeafec0 = FUN_23e8cbd60(lVar15,_DAT_23eeac8e0,*(undefined8 *)(_DAT_23eeac8e0 + 0x18));
      if (-1 < _DAT_23eeafec0) {
        lVar22 = *(longlong *)(lVar19 + 8 + _DAT_23eeafec0 * 0x10);
        goto LAB_23e302d58;
      }
    }
LAB_23e302779:
    plVar11 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeac8e0);
    if ((plVar11 == (longlong *)0x0) || (lVar22 = *plVar11, lVar22 == 0)) {
      plVar17 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      FUN_23e915740(param_1,&plStack_68,_DAT_23eeac8e0);
      uStack_80 = 0x77;
      plStack_98 = (longlong *)0x0;
      plStack_a0 = (longlong *)0x0;
      plStack_90 = plStack_68;
      plStack_b0 = (longlong *)0x0;
      uStack_88 = uStack_60;
      plStack_a8 = (longlong *)0x0;
      plVar12 = plStack_58;
      goto LAB_23e3024b0;
    }
  }
LAB_23e2ffbd4:
  *(undefined4 *)(plVar10 + 5) = 0x77;
  plVar14 = (longlong *)FUN_23e914090(param_1,lVar22,plVar13);
  lVar15 = _DAT_23eeac8f0;
  if (plVar14 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plVar17 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar16 = (longlong *)0x0;
    uStack_80 = 0x77;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_98 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3024b0;
  }
  *(undefined4 *)(plVar10 + 5) = 0x78;
  plVar11 = (longlong *)FUN_23e95a860(param_1,plVar14,_DAT_23eeac8e8,lVar15 + 0x18);
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plVar17 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = 0x78;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_98 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar16 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  lVar15 = _DAT_23eeac900;
  *(undefined4 *)(plVar10 + 5) = 0x79;
  plVar11 = (longlong *)FUN_23e915840(param_1,plVar14,_DAT_23eeac8f8,*(undefined8 *)(lVar15 + 0x18))
  ;
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plVar17 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = 0x79;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_98 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar16 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  lVar15 = FUN_23e8f5310();
  if (lVar15 == 0) {
    plVar17 = (longlong *)0x0;
    FUN_23e915740(param_1,&plStack_68,_DAT_23eeac908);
    uStack_80 = 0x7c;
    plStack_98 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_90 = plStack_68;
    plStack_b0 = (longlong *)0x0;
    uStack_88 = uStack_60;
    plStack_a8 = (longlong *)0x0;
    plVar16 = (longlong *)0x0;
    plVar12 = plStack_58;
    goto LAB_23e3024b0;
  }
  *(undefined4 *)(plVar10 + 5) = 0x7c;
  plVar16 = (longlong *)FUN_23e91a870(param_1,lVar15);
  lVar15 = _DAT_23eeac918;
  if (plVar16 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plVar17 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = 0x7c;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_98 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3024b0;
  }
  *(undefined4 *)(plVar10 + 5) = 0x7d;
  plVar11 = (longlong *)FUN_23e915840(param_1,plVar16,_DAT_23eeac910,*(undefined8 *)(lVar15 + 0x18))
  ;
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = 0x7d;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_a0 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar17 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  lVar15 = _DAT_23eeac928;
  *(undefined4 *)(plVar10 + 5) = 0x7e;
  plVar11 = (longlong *)FUN_23e915840(param_1,plVar16,_DAT_23eeac920,*(undefined8 *)(lVar15 + 0x18))
  ;
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = 0x7e;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_a0 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar17 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  lVar15 = FUN_23e8f51c0();
  if (lVar15 == 0) {
    FUN_23e915740(param_1,&plStack_68,_DAT_23eeac930);
    uStack_80 = 0x7f;
    plStack_98 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_90 = plStack_68;
    plStack_b0 = (longlong *)0x0;
    uStack_88 = uStack_60;
    plStack_a8 = (longlong *)0x0;
    plVar17 = (longlong *)0x0;
    plVar12 = plStack_58;
    goto LAB_23e3024b0;
  }
  *(undefined4 *)(plVar10 + 5) = 0x7f;
  plVar17 = (longlong *)FUN_23e914090(param_1,lVar15,plVar16);
  lVar15 = _DAT_23eeac938;
  if (plVar17 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = 0x7f;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_a0 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3024b0;
  }
  *(undefined4 *)(plVar10 + 5) = 0x80;
  plVar11 = (longlong *)FUN_23e95a860(param_1,plVar17,_DAT_23eeac8e8,lVar15 + 0x18);
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = 0x80;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_a0 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_a8 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  lVar15 = *plVar11;
  *plVar11 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    (**(code **)(plVar11[1] + 0x30))();
  }
  lVar15 = _DAT_23eeac940;
  *(undefined4 *)(plVar10 + 5) = 0x81;
  plVar11 = (longlong *)FUN_23e915840(param_1,plVar17,_DAT_23eeac8f8,*(undefined8 *)(lVar15 + 0x18))
  ;
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = 0x81;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_a0 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_a8 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  lVar15 = *plVar11;
  *plVar11 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    (**(code **)(plVar11[1] + 0x30))();
  }
  lVar15 = *(longlong *)(DAT_23eeac660 + 0x20);
  if (*(char *)(lVar15 + 10) == '\0') {
    plVar11 = (longlong *)FUN_23a37a020(DAT_23eeac660,_DAT_23eeac948);
    if (plVar11 == (longlong *)0x0) goto LAB_23e302b70;
    lVar15 = *plVar11;
LAB_23e302b5c:
    if (lVar15 == 0) goto LAB_23e302b70;
  }
  else {
    iVar9 = *(int *)(lVar15 + 0xc);
    if (*(int *)(lVar15 + 0xc) == 0) {
      *(int *)(lVar15 + 0xc) = DAT_23ec14e10;
      iVar9 = DAT_23ec14e10;
      DAT_23ec14e10 = DAT_23ec14e10 + 1;
    }
    if (_DAT_23ec14dc4 != iVar9) {
      _DAT_23ec14dc4 = iVar9;
      _DAT_23eeafec8 = FUN_23e8cbd60(lVar15,_DAT_23eeac948,*(undefined8 *)(_DAT_23eeac948 + 0x18));
    }
    if (-1 < _DAT_23eeafec8) {
      lVar22 = lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f));
      if (*(longlong *)(lVar22 + 8 + _DAT_23eeafec8 * 0x10) != 0) goto LAB_23e2ffe52;
      _DAT_23eeafec8 = FUN_23e8cbd60(lVar15,_DAT_23eeac948,*(undefined8 *)(_DAT_23eeac948 + 0x18));
      if (-1 < _DAT_23eeafec8) {
        lVar15 = *(longlong *)(lVar22 + 8 + _DAT_23eeafec8 * 0x10);
        goto LAB_23e302b5c;
      }
    }
LAB_23e302b70:
    plVar11 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeac948);
    if ((plVar11 == (longlong *)0x0) || (*plVar11 == 0)) {
      FUN_23e915740(param_1,&plStack_68,_DAT_23eeac948);
      uStack_80 = 0x84;
      plStack_98 = (longlong *)0x0;
      plStack_a0 = (longlong *)0x0;
      plStack_90 = plStack_68;
      plStack_b0 = (longlong *)0x0;
      uStack_88 = uStack_60;
      plStack_a8 = (longlong *)0x0;
      plVar12 = plStack_58;
      goto LAB_23e3024b0;
    }
  }
LAB_23e2ffe52:
  *(undefined4 *)(plVar10 + 5) = 0x84;
  plStack_a8 = (longlong *)FUN_23e91a870(param_1);
  if (plStack_a8 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = 0x84;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_a0 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3024b0;
  }
  *(undefined4 *)(plVar10 + 5) = 0x85;
  plVar11 = (longlong *)FUN_23e915840(param_1,plVar17,_DAT_23eeac950,plStack_a8);
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = 0x85;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_a0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_b0 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  lVar15 = *plVar11;
  *plVar11 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  lVar15 = _DAT_23eeac960;
  *(undefined4 *)(plVar10 + 5) = 0x88;
  plVar11 = (longlong *)FUN_23e915840(param_1,plVar17,_DAT_23eeac958,*(undefined8 *)(lVar15 + 0x18))
  ;
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = 0x88;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_a0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_b0 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  lVar15 = *plVar11;
  *plVar11 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    (**(code **)(plVar11[1] + 0x30))();
  }
  lVar15 = *(longlong *)(param_1 + 0x10);
  if (*(int *)(lVar15 + 0x1188) == 0) {
    plVar11 = (longlong *)FUN_23a33a530(PyList_Type_exref);
  }
  else {
    iVar9 = *(int *)(lVar15 + 0x1188) + -1;
    *(int *)(lVar15 + 0x1188) = iVar9;
    plVar11 = *(longlong **)(lVar15 + 0xf08 + (longlong)iVar9 * 8);
    *plVar11 = 1;
  }
  pcVar7 = _PyRuntime_exref;
  plVar11[2] = 0;
  plVar11[4] = 0;
  lVar15 = *(longlong *)(pcVar7 + 0x1f8);
  plVar11[3] = 0;
  lVar15 = *(longlong *)(*(longlong *)(lVar15 + 0x10) + 0x2e8);
  lVar22 = plVar11[-1];
  puVar4 = *(undefined8 **)(lVar15 + 8);
  *puVar4 = plVar11 + -2;
  plVar11[-2] = lVar15;
  plVar11[-1] = (ulonglong)((uint)lVar22 & 3) | (ulonglong)puVar4;
  *(longlong **)(lVar15 + 8) = plVar11 + -2;
  cVar8 = FUN_23e8d9ac0(plVar21[2],_DAT_23eeac968,plVar11);
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  lVar15 = _DAT_23eeac978;
  if (cVar8 == '\0') {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = 0x8b;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_a0 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3024b0;
  }
  lVar22 = plVar21[2];
  *(undefined4 *)(plVar10 + 5) = 0x8d;
  plVar11 = (longlong *)FUN_23e915840(param_1,lVar22,_DAT_23eeac970,*(undefined8 *)(lVar15 + 0x18));
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = 0x8d;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_a0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_b0 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  cVar8 = FUN_23e8d9ac0(plVar21[2],_DAT_23eeac980,plVar11);
  lVar15 = *plVar11;
  *plVar11 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  lVar15 = _DAT_23eeac988;
  if (cVar8 == '\0') {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = 0x8d;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_a0 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3024b0;
  }
  lVar22 = plVar21[2];
  *(undefined4 *)(plVar10 + 5) = 0x8e;
  plVar11 = (longlong *)FUN_23e915840(param_1,lVar22,_DAT_23eeac970,*(undefined8 *)(lVar15 + 0x18));
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = 0x8e;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_a0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_b0 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  cVar8 = FUN_23e8d9ac0(plVar21[2],_DAT_23eeac990,plVar11);
  lVar15 = *plVar11;
  *plVar11 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  lVar15 = _DAT_23eeac998;
  if (cVar8 == '\0') {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = 0x8e;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_a0 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3024b0;
  }
  lVar22 = plVar21[2];
  *(undefined4 *)(plVar10 + 5) = 0x8f;
  plVar11 = (longlong *)FUN_23e915840(param_1,lVar22,_DAT_23eeac970,*(undefined8 *)(lVar15 + 0x18));
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = 0x8f;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_a0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_b0 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  cVar8 = FUN_23e8d9ac0(plVar21[2],_DAT_23eeac9a0,plVar11);
  lVar15 = *plVar11;
  *plVar11 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  lVar15 = _DAT_23eeac9a8;
  if (cVar8 == '\0') {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = 0x8f;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_a0 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3024b0;
  }
  lVar22 = plVar21[2];
  *(undefined4 *)(plVar10 + 5) = 0x90;
  plVar11 = (longlong *)FUN_23e915840(param_1,lVar22,_DAT_23eeac970,*(undefined8 *)(lVar15 + 0x18));
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = 0x90;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_a0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_b0 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  cVar8 = FUN_23e8d9ac0(plVar21[2],_DAT_23eeac9b0,plVar11);
  lVar15 = *plVar11;
  *plVar11 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if (cVar8 == '\0') {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = 0x90;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_a0 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3024b0;
  }
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar21[2],_DAT_23eeac980);
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = 0x93;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plStack_a0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_b0 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  *(undefined4 *)(plVar10 + 5) = 0x93;
  plVar12 = (longlong *)FUN_23e915840(param_1,plVar11,_DAT_23eeac9b8);
  lVar15 = *plVar11;
  *plVar11 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if (plVar12 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    uStack_80 = 0x93;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  lVar15 = *plVar12;
  *plVar12 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar17,_DAT_23eeac950);
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    uStack_80 = 0x95;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  plVar12 = (longlong *)FUN_23e8bc2f0(plVar21[2],_DAT_23eeac980);
  if (plVar12 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    lVar15 = *plVar11;
    *plVar11 = lVar15 + -1;
    plStack_b0 = (longlong *)0x0;
    if (lVar15 + -1 == 0) {
      FUN_23a334bc0(plVar11);
      uStack_80 = 0x95;
      plStack_98 = (longlong *)0x0;
      plStack_a0 = (longlong *)0x0;
    }
    else {
      uStack_80 = 0x95;
      plStack_98 = (longlong *)0x0;
      plStack_a0 = (longlong *)0x0;
    }
    goto LAB_23e3024b0;
  }
  *(undefined4 *)(plVar10 + 5) = 0x95;
  plVar18 = (longlong *)FUN_23e914090(param_1,plVar11,plVar12);
  lVar15 = *plVar11;
  *plVar11 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  lVar15 = *plVar12;
  *plVar12 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if (plVar18 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    uStack_80 = 0x95;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_a0 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  lVar15 = *plVar18;
  *plVar18 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    (**(code **)(plVar18[1] + 0x30))(plVar18);
  }
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar17,_DAT_23eeac950);
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    uStack_80 = 0x96;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_a0 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  plVar12 = (longlong *)FUN_23e8bc2f0(plVar21[2],_DAT_23eeac990);
  if (plVar12 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    lVar15 = *plVar11;
    *plVar11 = lVar15 + -1;
    plStack_b0 = (longlong *)0x0;
    if (lVar15 + -1 == 0) {
      FUN_23a334bc0(plVar11);
      uStack_80 = 0x96;
      plStack_98 = (longlong *)0x0;
      plStack_a0 = (longlong *)0x0;
    }
    else {
      uStack_80 = 0x96;
      plStack_98 = (longlong *)0x0;
      plStack_a0 = (longlong *)0x0;
    }
    goto LAB_23e3024b0;
  }
  *(undefined4 *)(plVar10 + 5) = 0x96;
  plVar18 = (longlong *)FUN_23e914090(param_1,plVar11);
  lVar15 = *plVar11;
  *plVar11 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  lVar15 = *plVar12;
  *plVar12 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if (plVar18 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_a0 = (longlong *)0x0;
    uStack_80 = 0x96;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_98 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  lVar15 = *plVar18;
  *plVar18 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    (**(code **)(plVar18[1] + 0x30))(plVar18);
  }
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar17,_DAT_23eeac950);
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    uStack_80 = 0x97;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_a0 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  plVar12 = (longlong *)FUN_23e8bc2f0(plVar21[2]);
  if (plVar12 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    lVar15 = *plVar11;
    *plVar11 = lVar15 + -1;
    plStack_b0 = (longlong *)0x0;
    if (lVar15 + -1 == 0) {
      FUN_23a334bc0(plVar11);
      uStack_80 = 0x97;
      plStack_98 = (longlong *)0x0;
      plStack_a0 = (longlong *)0x0;
    }
    else {
      uStack_80 = 0x97;
      plStack_98 = (longlong *)0x0;
      plStack_a0 = (longlong *)0x0;
    }
    goto LAB_23e3024b0;
  }
  *(undefined4 *)(plVar10 + 5) = 0x97;
  plVar18 = (longlong *)FUN_23e914090(param_1,plVar11);
  lVar15 = *plVar11;
  *plVar11 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    FUN_23a334bc0(plVar11);
  }
  lVar15 = *plVar12;
  *plVar12 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    FUN_23a334bc0(plVar12);
  }
  if (plVar18 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    uStack_80 = 0x97;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_a0 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  lVar15 = *plVar18;
  *plVar18 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    FUN_23a334bc0(plVar18);
  }
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar17,_DAT_23eeac950);
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    uStack_80 = 0x98;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  plVar12 = (longlong *)FUN_23e8bc2f0(plVar21[2],_DAT_23eeac9b0);
  if (plVar12 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    lVar15 = *plVar11;
    *plVar11 = lVar15 + -1;
    plStack_b0 = (longlong *)0x0;
    if (lVar15 + -1 == 0) {
      FUN_23a334bc0(plVar11);
      uStack_80 = 0x98;
      plStack_98 = (longlong *)0x0;
      plStack_a0 = (longlong *)0x0;
    }
    else {
      uStack_80 = 0x98;
      plStack_98 = (longlong *)0x0;
      plStack_a0 = (longlong *)0x0;
    }
    goto LAB_23e3024b0;
  }
  *(undefined4 *)(plVar10 + 5) = 0x98;
  plVar18 = (longlong *)FUN_23e914090(param_1,plVar11,plVar12);
  lVar15 = *plVar11;
  *plVar11 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    FUN_23a334bc0(plVar11);
  }
  lVar15 = *plVar12;
  *plVar12 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    FUN_23a334bc0(plVar12);
  }
  if (plVar18 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_a0 = (longlong *)0x0;
    uStack_80 = 0x98;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_98 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  lVar15 = *plVar18;
  *plVar18 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    FUN_23a334bc0(plVar18);
  }
  *(undefined4 *)(plVar10 + 5) = 0x9b;
  plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar17,_DAT_23eeac9c8);
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    uStack_80 = 0x9b;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_a0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_b0 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  lVar15 = *plVar11;
  *plVar11 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    FUN_23a334bc0(plVar11);
  }
  lVar15 = FUN_23e8f5830();
  if (lVar15 == 0) {
    FUN_23e915740(param_1,&plStack_68,_DAT_23eeac9d0);
    plStack_98 = (longlong *)0x0;
    uStack_80 = 0x9e;
    plStack_90 = plStack_68;
    plStack_a0 = (longlong *)0x0;
    uStack_88 = uStack_60;
    plStack_b0 = (longlong *)0x0;
    plVar12 = plStack_58;
    goto LAB_23e3024b0;
  }
  *(undefined4 *)(plVar10 + 5) = 0x9e;
  plStack_b0 = (longlong *)FUN_23e94bb80(param_1,lVar15);
  lVar15 = _DAT_23eeac9e0;
  if (plStack_b0 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    uStack_80 = 0x9e;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_a0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3024b0;
  }
  *(undefined4 *)(plVar10 + 5) = 0x9f;
  plVar11 = (longlong *)
            FUN_23e915840(param_1,plStack_b0,_DAT_23eeac8c0,*(undefined8 *)(lVar15 + 0x18));
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    uStack_80 = 0x9f;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_a0 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  lVar15 = *plVar11;
  *plVar11 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    FUN_23a334bc0(plVar11);
  }
  plVar11 = (longlong *)FUN_23e8bc2f0(plStack_b0);
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_a0 = (longlong *)0x0;
    uStack_80 = 0xa0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3024b0;
  }
  lVar15 = FUN_23e8f5070();
  if (lVar15 == 0) {
    FUN_23e915740(param_1,&plStack_68,_DAT_23eeac9f0);
    plStack_90 = plStack_68;
    *plVar11 = *plVar11 + -1;
    uStack_88 = uStack_60;
    plStack_a0 = (longlong *)0x0;
    plVar12 = plStack_58;
    if (*plVar11 == 0) {
      FUN_23a334bc0(plVar11);
      uStack_80 = 0xa0;
      plStack_98 = (longlong *)0x0;
    }
    else {
      uStack_80 = 0xa0;
      plStack_98 = (longlong *)0x0;
    }
    goto LAB_23e3024b0;
  }
  plVar12 = (longlong *)FUN_23e8bc2f0(lVar15);
  if (plVar12 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar11 = *plVar11 + -1;
    plStack_a0 = (longlong *)0x0;
    if (*plVar11 == 0) {
      FUN_23a334bc0(plVar11);
      uStack_80 = 0xa0;
      plStack_98 = (longlong *)0x0;
    }
    else {
      plStack_98 = (longlong *)0x0;
      uStack_80 = 0xa0;
    }
    goto LAB_23e3024b0;
  }
  plVar18 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23eeaca00);
  lVar15 = *plVar12;
  *plVar12 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    FUN_23a334bc0(plVar12);
  }
  if (plVar18 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar11 = *plVar11 + -1;
    plStack_98 = (longlong *)0x0;
    if (*plVar11 == 0) {
      FUN_23a334bc0(plVar11);
      uStack_80 = 0xa0;
      plStack_a0 = (longlong *)0x0;
    }
    else {
      uStack_80 = 0xa0;
      plStack_a0 = (longlong *)0x0;
    }
    goto LAB_23e3024b0;
  }
  *(undefined4 *)(plVar10 + 5) = 0xa0;
  plVar12 = (longlong *)FUN_23e914090(param_1,plVar11,plVar18);
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    FUN_23a334bc0(plVar11);
  }
  lVar15 = *plVar18;
  *plVar18 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    FUN_23a334bc0(plVar18);
  }
  if (plVar12 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    uStack_80 = 0xa0;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_a0 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  lVar15 = *plVar12;
  *plVar12 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    FUN_23a334bc0(plVar12);
  }
  *(undefined4 *)(plVar10 + 5) = 0xa1;
  plVar11 = (longlong *)FUN_23e915840(param_1,plVar17,_DAT_23eeac950,plStack_b0);
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    uStack_80 = 0xa1;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_a0 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  lVar15 = *plVar11;
  *plVar11 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    FUN_23a334bc0(plVar11);
  }
  *(undefined4 *)(plVar10 + 5) = 0xa3;
  plVar11 = (longlong *)FUN_23e915840(param_1,plVar14,_DAT_23eeac950);
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    uStack_80 = 0xa3;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_a0 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  lVar15 = *plVar11;
  *plVar11 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    FUN_23a334bc0(plVar11);
  }
  lVar15 = FUN_23e8f5310();
  if (lVar15 == 0) {
    FUN_23e915740(param_1,&plStack_68);
    plStack_98 = (longlong *)0x0;
    uStack_80 = 0xa6;
    plStack_90 = plStack_68;
    uStack_88 = uStack_60;
    plStack_a0 = (longlong *)0x0;
    plVar12 = plStack_58;
    goto LAB_23e3024b0;
  }
  *(undefined4 *)(plVar10 + 5) = 0xa6;
  plStack_a0 = (longlong *)FUN_23e91a870(param_1,lVar15);
  lVar15 = _DAT_23eeaca08;
  if (plStack_a0 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    plStack_98 = (longlong *)0x0;
    uStack_80 = 0xa6;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3024b0;
  }
  *(undefined4 *)(plVar10 + 5) = 0xa7;
  plVar11 = (longlong *)
            FUN_23e915840(param_1,plStack_a0,_DAT_23eeac910,*(undefined8 *)(lVar15 + 0x18));
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = 0xa7;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_98 = (longlong *)0x0;
    goto LAB_23e3024b0;
  }
  lVar15 = *plVar11;
  *plVar11 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    FUN_23a334bc0(plVar11);
  }
  lVar15 = FUN_23e8f51c0();
  if (lVar15 == 0) {
    FUN_23e915740(param_1,&plStack_68,_DAT_23eeac930);
    uStack_80 = 0xa8;
    plStack_90 = plStack_68;
    uStack_88 = uStack_60;
    plStack_98 = (longlong *)0x0;
    plVar12 = plStack_58;
    goto LAB_23e3024b0;
  }
  *(undefined4 *)(plVar10 + 5) = 0xa8;
  plStack_98 = (longlong *)FUN_23e914090(param_1,lVar15,plStack_a0);
  lVar15 = _DAT_23eeac8f0;
  if (plStack_98 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    uStack_80 = 0xa8;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23e3024b0;
  }
  *(undefined4 *)(plVar10 + 5) = 0xa9;
  plVar11 = (longlong *)FUN_23e95a860(param_1,plStack_98,_DAT_23eeac8e8,lVar15 + 0x18);
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    uStack_80 = 0xa9;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23e3024b0;
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    FUN_23a334bc0(plVar11);
  }
  lVar15 = *(longlong *)(DAT_23eeac660 + 0x20);
  if (*(char *)(lVar15 + 10) == '\0') {
    plVar11 = (longlong *)FUN_23a37a020(DAT_23eeac660,_DAT_23eeaca10);
    if (plVar11 == (longlong *)0x0) goto LAB_23e303d0c;
    lVar15 = *plVar11;
LAB_23e303d03:
    if (lVar15 == 0) goto LAB_23e303d0c;
  }
  else {
    iVar9 = *(int *)(lVar15 + 0xc);
    if (*(int *)(lVar15 + 0xc) == 0) {
      *(int *)(lVar15 + 0xc) = DAT_23ec14e10;
      iVar9 = DAT_23ec14e10;
      DAT_23ec14e10 = DAT_23ec14e10 + 1;
    }
    if (_DAT_23ec14dc8 != iVar9) {
      _DAT_23ec14dc8 = iVar9;
      _DAT_23eeafed0 = FUN_23e8cbd60(lVar15,_DAT_23eeaca10,*(undefined8 *)(_DAT_23eeaca10 + 0x18));
    }
    if (-1 < _DAT_23eeafed0) {
      lVar22 = lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f));
      if (*(longlong *)(lVar22 + 8 + _DAT_23eeafed0 * 0x10) != 0) goto LAB_23e300983;
      _DAT_23eeafed0 = FUN_23e8cbd60(lVar15,_DAT_23eeaca10,*(undefined8 *)(_DAT_23eeaca10 + 0x18));
      if (-1 < _DAT_23eeafed0) {
        lVar15 = *(longlong *)(lVar22 + 8 + _DAT_23eeafed0 * 0x10);
        goto LAB_23e303d03;
      }
    }
LAB_23e303d0c:
    plVar11 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeaca10);
    if ((plVar11 == (longlong *)0x0) || (*plVar11 == 0)) {
      FUN_23e915740(param_1,&plStack_68,_DAT_23eeaca10);
      uStack_80 = 0xac;
      plStack_90 = plStack_68;
      uStack_88 = uStack_60;
      plVar12 = plStack_58;
      goto LAB_23e3024b0;
    }
  }
LAB_23e300983:
  *(undefined4 *)(plVar10 + 5) = 0xac;
  plVar11 = (longlong *)FUN_23e91a870(param_1);
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    uStack_80 = 0xac;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23e3024b0;
  }
  cVar8 = FUN_23e8d9ac0(plVar21[2],_DAT_23eeaca18,plVar11);
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    FUN_23a334bc0(plVar11);
  }
  if (cVar8 == '\0') {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    uStack_80 = 0xac;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23e3024b0;
  }
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar21[2],_DAT_23eeac840);
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    uStack_80 = 0xaf;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23e3024b0;
  }
  iVar9 = FUN_23a35f020(plVar11);
  lVar15 = *plVar11 + -1;
  if (iVar9 == -1) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uStack_80 = 0xaf;
    *plVar11 = lVar15;
    if (lVar15 == 0) {
      FUN_23a334bc0();
      uStack_80 = 0xaf;
    }
    goto LAB_23e3024b0;
  }
  *plVar11 = lVar15;
  if (lVar15 == 0) {
    FUN_23a334bc0();
  }
  if (iVar9 == 0) {
    lVar15 = FUN_23e8f5830();
    if (lVar15 == 0) {
      FUN_23e915740(param_1,&plStack_68,_DAT_23eeac9d0);
      uStack_80 = 0xb2;
      plStack_90 = plStack_68;
      uStack_88 = uStack_60;
      plVar12 = plStack_58;
      goto LAB_23e3024b0;
    }
    *(undefined4 *)(plVar10 + 5) = 0xb2;
    plVar11 = (longlong *)FUN_23e94bb80(param_1,lVar15,_DAT_23eeaca30);
    if (plVar11 == (longlong *)0x0) {
      plStack_90 = *(longlong **)(param_1 + 0x60);
      plVar12 = *(longlong **)(param_1 + 0x70);
      uStack_80 = 0xb2;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uStack_88 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e3024b0;
    }
    cVar8 = FUN_23e8d9ac0(plVar21[2],_DAT_23eeaca28,plVar11);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      FUN_23a334bc0(plVar11);
    }
    if (cVar8 == '\0') {
      plStack_90 = *(longlong **)(param_1 + 0x60);
      plVar12 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uStack_80 = 0xb2;
      uStack_88 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e3024b0;
    }
    plVar11 = (longlong *)FUN_23e8bc2f0(plVar21[2],_DAT_23eeaca28);
    if (plVar11 == (longlong *)0x0) {
      plStack_90 = *(longlong **)(param_1 + 0x60);
      plVar12 = *(longlong **)(param_1 + 0x70);
      uStack_80 = 0xb3;
      uStack_88 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      goto LAB_23e3024b0;
    }
    plVar18 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23eeac9e8);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      FUN_23a334bc0(plVar11);
    }
    if (plVar18 == (longlong *)0x0) {
      plStack_90 = *(longlong **)(param_1 + 0x60);
      plVar12 = *(longlong **)(param_1 + 0x70);
      uStack_80 = 0xb3;
      uStack_88 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      goto LAB_23e3024b0;
    }
    lVar15 = FUN_23e8f5070();
    if (lVar15 == 0) {
      FUN_23e915740(param_1,&plStack_68,_DAT_23eeac9f0);
      uStack_80 = 0xb3;
      plStack_90 = plStack_68;
      *plVar18 = *plVar18 + -1;
      uStack_88 = uStack_60;
      plVar12 = plStack_58;
      if (*plVar18 == 0) {
        FUN_23a334bc0(plVar18);
        uStack_80 = 0xb3;
      }
      goto LAB_23e3024b0;
    }
    plVar11 = (longlong *)FUN_23e8bc2f0(lVar15,_DAT_23eeac9f8);
    if (plVar11 == (longlong *)0x0) {
      plStack_90 = *(longlong **)(param_1 + 0x60);
      plVar12 = *(longlong **)(param_1 + 0x70);
      uStack_80 = 0xb3;
      uStack_88 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar18 = *plVar18 + -1;
      if (*plVar18 == 0) {
        FUN_23a334bc0(plVar18);
        uStack_80 = 0xb3;
      }
      goto LAB_23e3024b0;
    }
    plVar12 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23eeaca00);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      FUN_23a334bc0();
    }
    if (plVar12 == (longlong *)0x0) {
      plStack_90 = *(longlong **)(param_1 + 0x60);
      plVar12 = *(longlong **)(param_1 + 0x70);
      uStack_80 = 0xb3;
      uStack_88 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar18 = *plVar18 + -1;
      if (*plVar18 == 0) {
        FUN_23a334bc0(plVar18);
        uStack_80 = 0xb3;
      }
      goto LAB_23e3024b0;
    }
    *(undefined4 *)(plVar10 + 5) = 0xb3;
    plVar11 = (longlong *)FUN_23e914090(param_1,plVar18,plVar12);
    *plVar18 = *plVar18 + -1;
    if (*plVar18 == 0) {
      FUN_23a334bc0(plVar18);
    }
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      FUN_23a334bc0(plVar12);
    }
    if (plVar11 == (longlong *)0x0) {
      plStack_90 = *(longlong **)(param_1 + 0x60);
      plVar12 = *(longlong **)(param_1 + 0x70);
      uStack_80 = 0xb3;
      uStack_88 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      goto LAB_23e3024b0;
    }
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      FUN_23a334bc0(plVar11);
    }
    plVar11 = (longlong *)FUN_23e8bc2f0(plVar21[2],_DAT_23eeaca28);
    lVar15 = _DAT_23eeaca38;
    if (plVar11 == (longlong *)0x0) {
      plStack_90 = *(longlong **)(param_1 + 0x60);
      plVar12 = *(longlong **)(param_1 + 0x70);
      uStack_80 = 0xb4;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uStack_88 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e3024b0;
    }
    *(undefined4 *)(plVar10 + 5) = 0xb4;
    plVar12 = (longlong *)
              FUN_23e915840(param_1,plVar11,_DAT_23eeac8c0,*(undefined8 *)(lVar15 + 0x18));
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      FUN_23a334bc0(plVar11);
    }
    if (plVar12 == (longlong *)0x0) {
      plStack_90 = *(longlong **)(param_1 + 0x60);
      plVar12 = *(longlong **)(param_1 + 0x70);
      uStack_80 = 0xb4;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uStack_88 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e3024b0;
    }
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      FUN_23a334bc0(plVar12);
    }
  }
  else {
    lVar15 = *(longlong *)(DAT_23eeac660 + 0x20);
    if (*(char *)(lVar15 + 10) == '\0') {
      plVar11 = (longlong *)FUN_23a37a020(DAT_23eeac660,_DAT_23eeaca20);
      if (plVar11 == (longlong *)0x0) goto LAB_23e303f0e;
      lVar22 = *plVar11;
LAB_23e303f05:
      if (lVar22 == 0) goto LAB_23e303f0e;
    }
    else {
      iVar9 = *(int *)(lVar15 + 0xc);
      if (*(int *)(lVar15 + 0xc) == 0) {
        *(int *)(lVar15 + 0xc) = DAT_23ec14e10;
        iVar9 = DAT_23ec14e10;
        DAT_23ec14e10 = DAT_23ec14e10 + 1;
      }
      if (_DAT_23ec14dcc != iVar9) {
        _DAT_23ec14dcc = iVar9;
        _DAT_23eeafed8 = FUN_23e8cbd60(lVar15,_DAT_23eeaca20,*(undefined8 *)(_DAT_23eeaca20 + 0x18))
        ;
      }
      if (-1 < _DAT_23eeafed8) {
        lVar19 = lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f));
        lVar22 = *(longlong *)(lVar19 + 8 + _DAT_23eeafed8 * 0x10);
        if (lVar22 != 0) goto LAB_23e300ad2;
        _DAT_23eeafed8 = FUN_23e8cbd60(lVar15,_DAT_23eeaca20,*(undefined8 *)(_DAT_23eeaca20 + 0x18))
        ;
        if (-1 < _DAT_23eeafed8) {
          lVar22 = *(longlong *)(lVar19 + 8 + _DAT_23eeafed8 * 0x10);
          goto LAB_23e303f05;
        }
      }
LAB_23e303f0e:
      plVar11 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeaca20);
      if ((plVar11 == (longlong *)0x0) || (lVar22 = *plVar11, lVar22 == 0)) {
        FUN_23e915740(param_1,&plStack_68,_DAT_23eeaca20);
        uStack_80 = 0xb0;
        plStack_90 = plStack_68;
        uStack_88 = uStack_60;
        plVar12 = plStack_58;
        goto LAB_23e3024b0;
      }
    }
LAB_23e300ad2:
    plVar11 = (longlong *)FUN_23e8bc2f0(plVar21[2],_DAT_23eeac840);
    if (plVar11 == (longlong *)0x0) {
      plStack_90 = *(longlong **)(param_1 + 0x60);
      plVar12 = *(longlong **)(param_1 + 0x70);
      uStack_80 = 0xb0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uStack_88 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e3024b0;
    }
    *(undefined4 *)(plVar10 + 5) = 0xb0;
    plVar12 = (longlong *)FUN_23e914090(param_1,lVar22,plVar11);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      FUN_23a334bc0(plVar11);
    }
    if (plVar12 == (longlong *)0x0) {
      plStack_90 = *(longlong **)(param_1 + 0x60);
      plVar12 = *(longlong **)(param_1 + 0x70);
      uStack_80 = 0xb0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uStack_88 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e3024b0;
    }
    cVar8 = FUN_23e8d9ac0(plVar21[2],_DAT_23eeaca28);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      FUN_23a334bc0(plVar12);
    }
    if (cVar8 == '\0') {
      plStack_90 = *(longlong **)(param_1 + 0x60);
      plVar12 = *(longlong **)(param_1 + 0x70);
      uStack_80 = 0xb0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uStack_88 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e3024b0;
    }
  }
  lVar15 = *(longlong *)(DAT_23eeac660 + 0x20);
  if (*(char *)(lVar15 + 10) == '\0') {
    plVar11 = (longlong *)FUN_23a37a020(DAT_23eeac660,_DAT_23eeaca40);
    if (plVar11 == (longlong *)0x0) goto LAB_23e3047fc;
    lVar15 = *plVar11;
LAB_23e3047f3:
    if (lVar15 == 0) goto LAB_23e3047fc;
  }
  else {
    iVar9 = *(int *)(lVar15 + 0xc);
    if (*(int *)(lVar15 + 0xc) == 0) {
      *(int *)(lVar15 + 0xc) = DAT_23ec14e10;
      iVar9 = DAT_23ec14e10;
      DAT_23ec14e10 = DAT_23ec14e10 + 1;
    }
    if (_DAT_23ec14dd0 != iVar9) {
      _DAT_23ec14dd0 = iVar9;
      _DAT_23eeafee0 = FUN_23e8cbd60(lVar15,_DAT_23eeaca40,*(undefined8 *)(_DAT_23eeaca40 + 0x18));
    }
    if (-1 < _DAT_23eeafee0) {
      lVar22 = lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f));
      if (*(longlong *)(lVar22 + 8 + _DAT_23eeafee0 * 0x10) != 0) goto LAB_23e300c03;
      _DAT_23eeafee0 = FUN_23e8cbd60(lVar15,_DAT_23eeaca40,*(undefined8 *)(_DAT_23eeaca40 + 0x18));
      if (-1 < _DAT_23eeafee0) {
        lVar15 = *(longlong *)(lVar22 + 8 + _DAT_23eeafee0 * 0x10);
        goto LAB_23e3047f3;
      }
    }
LAB_23e3047fc:
    plVar11 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeaca40);
    if ((plVar11 == (longlong *)0x0) || (*plVar11 == 0)) {
      FUN_23e915740(param_1,&plStack_68,_DAT_23eeaca40);
      uStack_80 = 0xb6;
      plStack_90 = plStack_68;
      uStack_88 = uStack_60;
      plVar12 = plStack_58;
      goto LAB_23e3024b0;
    }
  }
LAB_23e300c03:
  *(undefined4 *)(plVar10 + 5) = 0xb6;
  plVar11 = (longlong *)FUN_23e91a870(param_1);
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    uStack_80 = 0xb6;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3024b0;
  }
  cVar8 = FUN_23e8d9ac0(plVar21[2],_DAT_23eeaca48);
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    FUN_23a334bc0(plVar11);
  }
  if (cVar8 == '\0') {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    uStack_80 = 0xb6;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3024b0;
  }
  lVar15 = *(longlong *)(DAT_23eeac660 + 0x20);
  if (*(char *)(lVar15 + 10) == '\0') {
    plVar11 = (longlong *)FUN_23a37a020(DAT_23eeac660,_DAT_23eeaca50);
    if (plVar11 == (longlong *)0x0) goto LAB_23e3046d4;
    lVar22 = *plVar11;
LAB_23e3046cb:
    if (lVar22 == 0) goto LAB_23e3046d4;
  }
  else {
    iVar9 = *(int *)(lVar15 + 0xc);
    if (*(int *)(lVar15 + 0xc) == 0) {
      *(int *)(lVar15 + 0xc) = DAT_23ec14e10;
      iVar9 = DAT_23ec14e10;
      DAT_23ec14e10 = DAT_23ec14e10 + 1;
    }
    if (_DAT_23ec14dd4 != iVar9) {
      _DAT_23ec14dd4 = iVar9;
      _DAT_23eeafee8 = FUN_23e8cbd60(lVar15,_DAT_23eeaca50,*(undefined8 *)(_DAT_23eeaca50 + 0x18));
    }
    if (-1 < _DAT_23eeafee8) {
      lVar19 = lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f));
      lVar22 = *(longlong *)(lVar19 + 8 + _DAT_23eeafee8 * 0x10);
      if (lVar22 != 0) goto LAB_23e300cf6;
      _DAT_23eeafee8 = FUN_23e8cbd60(lVar15,_DAT_23eeaca50,*(undefined8 *)(_DAT_23eeaca50 + 0x18));
      if (-1 < _DAT_23eeafee8) {
        lVar22 = *(longlong *)(lVar19 + 8 + _DAT_23eeafee8 * 0x10);
        goto LAB_23e3046cb;
      }
    }
LAB_23e3046d4:
    plVar11 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeaca50);
    if ((plVar11 == (longlong *)0x0) || (lVar22 = *plVar11, lVar22 == 0)) {
      FUN_23e915740(param_1,&plStack_68,_DAT_23eeaca50);
      uStack_80 = 0xb8;
      plStack_90 = plStack_68;
      uStack_88 = uStack_60;
      plVar12 = plStack_58;
      goto LAB_23e3024b0;
    }
  }
LAB_23e300cf6:
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar21[2],_DAT_23eeaca48);
  if (plVar11 == (longlong *)0x0) {
    plStack_90 = *(longlong **)(param_1 + 0x60);
    plVar12 = *(longlong **)(param_1 + 0x70);
    uStack_80 = 0xb8;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  else {
    *(undefined4 *)(plVar10 + 5) = 0xb8;
    plStack_68 = plVar11;
    plVar12 = (longlong *)FUN_23e9186b0(param_1,lVar22,&plStack_68,_DAT_23eeaca58);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      FUN_23a334bc0(plVar11);
    }
    if (plVar12 == (longlong *)0x0) {
      plStack_90 = *(longlong **)(param_1 + 0x60);
      plVar12 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uStack_80 = 0xb8;
      uStack_88 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
    else {
      cVar8 = FUN_23e8d9ac0(plVar21[2],_DAT_23eeaca60,plVar12);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        FUN_23a334bc0(plVar12);
      }
      if (cVar8 == '\0') {
        plStack_90 = *(longlong **)(param_1 + 0x60);
        plVar12 = *(longlong **)(param_1 + 0x70);
        uStack_80 = 0xb8;
        uStack_88 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
      }
      else {
        lVar15 = FUN_23e8f5830();
        if (lVar15 == 0) {
          FUN_23e915740(param_1,&plStack_68,_DAT_23eeac9d0);
          uStack_80 = 0xba;
          plStack_90 = plStack_68;
          uStack_88 = uStack_60;
          plVar12 = plStack_58;
        }
        else {
          *(undefined4 *)(plVar10 + 5) = 0xba;
          plVar11 = (longlong *)FUN_23e94bb80(param_1,lVar15,_DAT_23eeaca68);
          if (plVar11 == (longlong *)0x0) {
            plStack_90 = *(longlong **)(param_1 + 0x60);
            plVar12 = *(longlong **)(param_1 + 0x70);
            uStack_80 = 0xba;
            uStack_88 = *(undefined8 *)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
          }
          else {
            cVar8 = FUN_23e8d9ac0(plVar21[2],_DAT_23eeaca70,plVar11);
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              FUN_23a334bc0(plVar11);
            }
            if (cVar8 == '\0') {
              plStack_90 = *(longlong **)(param_1 + 0x60);
              plVar12 = *(longlong **)(param_1 + 0x70);
              uStack_80 = 0xba;
              uStack_88 = *(undefined8 *)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
            }
            else {
              plVar11 = (longlong *)FUN_23e8bc2f0(plVar21[2],_DAT_23eeaca70);
              if (plVar11 == (longlong *)0x0) {
                plStack_90 = *(longlong **)(param_1 + 0x60);
                plVar12 = *(longlong **)(param_1 + 0x70);
                uStack_80 = 0xbb;
                uStack_88 = *(undefined8 *)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
              }
              else {
                plVar18 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23eeac9e8);
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  FUN_23a334bc0();
                }
                if (plVar18 == (longlong *)0x0) {
                  plStack_90 = *(longlong **)(param_1 + 0x60);
                  plVar12 = *(longlong **)(param_1 + 0x70);
                  uStack_80 = 0xbb;
                  uStack_88 = *(undefined8 *)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                }
                else {
                  lVar15 = FUN_23e8f5070();
                  if (lVar15 == 0) {
                    FUN_23e915740(param_1,&plStack_68,_DAT_23eeac9f0);
                    uStack_80 = 0xbb;
                    plStack_90 = plStack_68;
                    *plVar18 = *plVar18 + -1;
                    uStack_88 = uStack_60;
                    plVar12 = plStack_58;
                    if (*plVar18 == 0) {
                      FUN_23a334bc0(plVar18);
                      uStack_80 = 0xbb;
                    }
                  }
                  else {
                    plVar11 = (longlong *)FUN_23e8bc2f0(lVar15,_DAT_23eeac9f8);
                    if (plVar11 == (longlong *)0x0) {
                      plStack_90 = *(longlong **)(param_1 + 0x60);
                      plVar12 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uStack_80 = 0xbb;
                      uStack_88 = *(undefined8 *)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar18 = *plVar18 + -1;
                      if (*plVar18 == 0) {
                        FUN_23a334bc0(plVar18);
                        uStack_80 = 0xbb;
                      }
                    }
                    else {
                      plVar12 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23eeaca00);
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        FUN_23a334bc0();
                      }
                      if (plVar12 == (longlong *)0x0) {
                        plStack_90 = *(longlong **)(param_1 + 0x60);
                        plVar12 = *(longlong **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uStack_80 = 0xbb;
                        uStack_88 = *(undefined8 *)(param_1 + 0x68);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *plVar18 = *plVar18 + -1;
                        if (*plVar18 == 0) {
                          FUN_23a334bc0(plVar18);
                          uStack_80 = 0xbb;
                        }
                      }
                      else {
                        *(undefined4 *)(plVar10 + 5) = 0xbb;
                        plVar11 = (longlong *)FUN_23e914090(param_1,plVar18);
                        *plVar18 = *plVar18 + -1;
                        if (*plVar18 == 0) {
                          FUN_23a334bc0(plVar18);
                        }
                        *plVar12 = *plVar12 + -1;
                        if (*plVar12 == 0) {
                          FUN_23a334bc0(plVar12);
                        }
                        if (plVar11 == (longlong *)0x0) {
                          plStack_90 = *(longlong **)(param_1 + 0x60);
                          plVar12 = *(longlong **)(param_1 + 0x70);
                          uStack_80 = 0xbb;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          uStack_88 = *(undefined8 *)(param_1 + 0x68);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        }
                        else {
                          *plVar11 = *plVar11 + -1;
                          if (*plVar11 == 0) {
                            FUN_23a334bc0(plVar11);
                          }
                          plVar11 = (longlong *)FUN_23e8bc2f0(plVar21[2],_DAT_23eeaca70);
                          lVar15 = _DAT_23eeaca38;
                          if (plVar11 == (longlong *)0x0) {
                            plStack_90 = *(longlong **)(param_1 + 0x60);
                            plVar12 = *(longlong **)(param_1 + 0x70);
                            uStack_80 = 0xbc;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uStack_88 = *(undefined8 *)(param_1 + 0x68);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          }
                          else {
                            *(undefined4 *)(plVar10 + 5) = 0xbc;
                            plVar12 = (longlong *)
                                      FUN_23e915840(param_1,plVar11,_DAT_23eeac8c0,
                                                    *(undefined8 *)(lVar15 + 0x18));
                            *plVar11 = *plVar11 + -1;
                            if (*plVar11 == 0) {
                              FUN_23a334bc0();
                            }
                            if (plVar12 == (longlong *)0x0) {
                              plStack_90 = *(longlong **)(param_1 + 0x60);
                              plVar12 = *(longlong **)(param_1 + 0x70);
                              uStack_80 = 0xbc;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              uStack_88 = *(undefined8 *)(param_1 + 0x68);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            }
                            else {
                              *plVar12 = *plVar12 + -1;
                              if (*plVar12 == 0) {
                                FUN_23a334bc0(plVar12);
                              }
                              plVar11 = (longlong *)FUN_23e8bc2f0(plVar21[2]);
                              if (plVar11 == (longlong *)0x0) {
                                plStack_90 = *(longlong **)(param_1 + 0x60);
                                plVar12 = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                uStack_80 = 0xbf;
                                uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              }
                              else {
                                plVar18 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23eeac950);
                                *plVar11 = *plVar11 + -1;
                                if (*plVar11 == 0) {
                                  FUN_23a334bc0(plVar11);
                                }
                                if (plVar18 == (longlong *)0x0) {
                                  plStack_90 = *(longlong **)(param_1 + 0x60);
                                  plVar12 = *(longlong **)(param_1 + 0x70);
                                  uStack_80 = 0xbf;
                                  uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                }
                                else {
                                  plVar11 = (longlong *)FUN_23e8bc2f0(plVar21[2],_DAT_23eeaca28);
                                  if (plVar11 == (longlong *)0x0) {
                                    plStack_90 = *(longlong **)(param_1 + 0x60);
                                    plVar12 = *(longlong **)(param_1 + 0x70);
                                    uStack_80 = 0xbf;
                                    uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *plVar18 = *plVar18 + -1;
                                    if (*plVar18 == 0) {
                                      FUN_23a334bc0(plVar18,0xbf,0);
                                      uStack_80 = 0xbf;
                                    }
                                  }
                                  else {
                                    *(undefined4 *)(plVar10 + 5) = 0xbf;
                                    plVar12 = (longlong *)FUN_23e914090(param_1,plVar18);
                                    *plVar18 = *plVar18 + -1;
                                    if (*plVar18 == 0) {
                                      FUN_23a334bc0(plVar18);
                                    }
                                    *plVar11 = *plVar11 + -1;
                                    if (*plVar11 == 0) {
                                      FUN_23a334bc0(plVar11);
                                    }
                                    if (plVar12 == (longlong *)0x0) {
                                      plStack_90 = *(longlong **)(param_1 + 0x60);
                                      plVar12 = *(longlong **)(param_1 + 0x70);
                                      uStack_80 = 0xbf;
                                      uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                    }
                                    else {
                                      *plVar12 = *plVar12 + -1;
                                      if (*plVar12 == 0) {
                                        FUN_23a334bc0(plVar12);
                                      }
                                      plVar11 = (longlong *)FUN_23e8bc2f0(plVar21[2],_DAT_23eeaca18)
                                      ;
                                      if (plVar11 == (longlong *)0x0) {
                                        plStack_90 = *(longlong **)(param_1 + 0x60);
                                        plVar12 = *(longlong **)(param_1 + 0x70);
                                        uStack_80 = 0xc0;
                                        uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                      }
                                      else {
                                        plVar18 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23eeac950);
                                        *plVar11 = *plVar11 + -1;
                                        if (*plVar11 == 0) {
                                          FUN_23a334bc0(plVar11);
                                        }
                                        if (plVar18 == (longlong *)0x0) {
                                          plStack_90 = *(longlong **)(param_1 + 0x60);
                                          plVar12 = *(longlong **)(param_1 + 0x70);
                                          uStack_80 = 0xc0;
                                          uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                        }
                                        else {
                                          plVar11 = (longlong *)
                                                    FUN_23e8bc2f0(plVar21[2],_DAT_23eeaca48);
                                          if (plVar11 == (longlong *)0x0) {
                                            plStack_90 = *(longlong **)(param_1 + 0x60);
                                            plVar12 = *(longlong **)(param_1 + 0x70);
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            uStack_80 = 0xc0;
                                            uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            *plVar18 = *plVar18 + -1;
                                            if (*plVar18 == 0) {
                                              FUN_23a334bc0(plVar18,0xc0,0);
                                              uStack_80 = 0xc0;
                                            }
                                          }
                                          else {
                                            *(undefined4 *)(plVar10 + 5) = 0xc0;
                                            plVar12 = (longlong *)FUN_23e914090(param_1,plVar18);
                                            *plVar18 = *plVar18 + -1;
                                            if (*plVar18 == 0) {
                                              FUN_23a334bc0(plVar18);
                                            }
                                            *plVar11 = *plVar11 + -1;
                                            if (*plVar11 == 0) {
                                              FUN_23a334bc0(plVar11);
                                            }
                                            if (plVar12 == (longlong *)0x0) {
                                              plStack_90 = *(longlong **)(param_1 + 0x60);
                                              plVar12 = *(longlong **)(param_1 + 0x70);
                                              uStack_80 = 0xc0;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                            }
                                            else {
                                              *plVar12 = *plVar12 + -1;
                                              if (*plVar12 == 0) {
                                                FUN_23a334bc0(plVar12);
                                              }
                                              plVar11 = (longlong *)
                                                        FUN_23e8bc2f0(plVar21[2],_DAT_23eeaca18);
                                              if (plVar11 == (longlong *)0x0) {
                                                plStack_90 = *(longlong **)(param_1 + 0x60);
                                                plVar12 = *(longlong **)(param_1 + 0x70);
                                                uStack_80 = 0xc1;
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                              }
                                              else {
                                                plVar18 = (longlong *)
                                                          FUN_23e8bc2f0(plVar11,_DAT_23eeac950);
                                                *plVar11 = *plVar11 + -1;
                                                if (*plVar11 == 0) {
                                                  FUN_23a334bc0(plVar11);
                                                }
                                                if (plVar18 == (longlong *)0x0) {
                                                  plStack_90 = *(longlong **)(param_1 + 0x60);
                                                  plVar12 = *(longlong **)(param_1 + 0x70);
                                                  uStack_80 = 0xc1;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                }
                                                else {
                                                  plVar11 = (longlong *)
                                                            FUN_23e8bc2f0(plVar21[2],_DAT_23eeaca60)
                                                  ;
                                                  if (plVar11 == (longlong *)0x0) {
                                                    plStack_90 = *(longlong **)(param_1 + 0x60);
                                                    plVar12 = *(longlong **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    uStack_80 = 0xc1;
                                                    uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *plVar18 = *plVar18 + -1;
                                                    if (*plVar18 == 0) {
                                                      FUN_23a334bc0(plVar18,0xc1,0);
                                                      uStack_80 = 0xc1;
                                                    }
                                                  }
                                                  else {
                                                    *(undefined4 *)(plVar10 + 5) = 0xc1;
                                                    plVar12 = (longlong *)FUN_23e914090(param_1);
                                                    *plVar18 = *plVar18 + -1;
                                                    if (*plVar18 == 0) {
                                                      FUN_23a334bc0(plVar18);
                                                    }
                                                    *plVar11 = *plVar11 + -1;
                                                    if (*plVar11 == 0) {
                                                      FUN_23a334bc0(plVar11);
                                                    }
                                                    if (plVar12 == (longlong *)0x0) {
                                                      plStack_90 = *(longlong **)(param_1 + 0x60);
                                                      plVar12 = *(longlong **)(param_1 + 0x70);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      uStack_80 = 0xc1;
                                                      uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                    }
                                                    else {
                                                      *plVar12 = *plVar12 + -1;
                                                      if (*plVar12 == 0) {
                                                        FUN_23a334bc0(plVar12);
                                                      }
                                                      plVar11 = (longlong *)
                                                                FUN_23e8bc2f0(plVar21[2],
                                                                              _DAT_23eeaca18);
                                                      if (plVar11 == (longlong *)0x0) {
                                                        plStack_90 = *(longlong **)(param_1 + 0x60);
                                                        plVar12 = *(longlong **)(param_1 + 0x70);
                                                        uStack_80 = 0xc2;
                                                        uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                      }
                                                      else {
                                                        plVar18 = (longlong *)
                                                                  FUN_23e8bc2f0(plVar11,
                                                  _DAT_23eeac950);
                                                  *plVar11 = *plVar11 + -1;
                                                  if (*plVar11 == 0) {
                                                    FUN_23a334bc0(plVar11);
                                                  }
                                                  if (plVar18 == (longlong *)0x0) {
                                                    plStack_90 = *(longlong **)(param_1 + 0x60);
                                                    plVar12 = *(longlong **)(param_1 + 0x70);
                                                    uStack_80 = 0xc2;
                                                    uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                  }
                                                  else {
                                                    plVar11 = (longlong *)
                                                              FUN_23e8bc2f0(plVar21[2],
                                                                            _DAT_23eeaca70);
                                                    if (plVar11 == (longlong *)0x0) {
                                                      plStack_90 = *(longlong **)(param_1 + 0x60);
                                                      plVar12 = *(longlong **)(param_1 + 0x70);
                                                      uStack_80 = 0xc2;
                                                      uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *plVar18 = *plVar18 + -1;
                                                      if (*plVar18 == 0) {
                                                        FUN_23a334bc0(plVar18,0xc2,0);
                                                        uStack_80 = 0xc2;
                                                      }
                                                    }
                                                    else {
                                                      *(undefined4 *)(plVar10 + 5) = 0xc2;
                                                      plVar12 = (longlong *)
                                                                FUN_23e914090(param_1,plVar18);
                                                      *plVar18 = *plVar18 + -1;
                                                      if (*plVar18 == 0) {
                                                        FUN_23a334bc0(plVar18);
                                                      }
                                                      *plVar11 = *plVar11 + -1;
                                                      if (*plVar11 == 0) {
                                                        FUN_23a334bc0(plVar11);
                                                      }
                                                      if (plVar12 == (longlong *)0x0) {
                                                        plStack_90 = *(longlong **)(param_1 + 0x60);
                                                        plVar12 = *(longlong **)(param_1 + 0x70);
                                                        uStack_80 = 0xc2;
                                                        uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                      }
                                                      else {
                                                        *plVar12 = *plVar12 + -1;
                                                        if (*plVar12 == 0) {
                                                          FUN_23a334bc0(plVar12);
                                                        }
                                                        plVar11 = (longlong *)
                                                                  FUN_23e8bc2f0(plVar21[2],
                                                                                _DAT_23eeaca18);
                                                        if (plVar11 == (longlong *)0x0) {
                                                          plStack_90 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                          plVar12 = *(longlong **)(param_1 + 0x70);
                                                          uStack_80 = 0xc5;
                                                          uStack_88 = *(undefined8 *)
                                                                       (param_1 + 0x68);
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                        }
                                                        else {
                                                          plVar18 = (longlong *)
                                                                    FUN_23e8bc2f0(plVar11,
                                                  _DAT_23eeaca78);
                                                  *plVar11 = *plVar11 + -1;
                                                  if (*plVar11 == 0) {
                                                    FUN_23a334bc0(plVar11);
                                                  }
                                                  if (plVar18 == (longlong *)0x0) {
                                                    plStack_90 = *(longlong **)(param_1 + 0x60);
                                                    plVar12 = *(longlong **)(param_1 + 0x70);
                                                    uStack_80 = 0xc5;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  else {
                                                    plVar11 = (longlong *)
                                                              FUN_23e8bc2f0(plVar21[2],
                                                                            _DAT_23eeaca28);
                                                    if (plVar11 == (longlong *)0x0) {
                                                      plStack_90 = *(longlong **)(param_1 + 0x60);
                                                      plVar12 = *(longlong **)(param_1 + 0x70);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      uStack_80 = 0xc5;
                                                      uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *plVar18 = *plVar18 + -1;
                                                      if (*plVar18 == 0) {
                                                        FUN_23a334bc0(plVar18,0xc5,0);
                                                        uStack_80 = 0xc5;
                                                      }
                                                    }
                                                    else {
                                                      *(undefined4 *)(plVar10 + 5) = 0xc5;
                                                      plVar12 = (longlong *)
                                                                FUN_23e914090(param_1,plVar18);
                                                      *plVar18 = *plVar18 + -1;
                                                      if (*plVar18 == 0) {
                                                        FUN_23a334bc0(plVar18);
                                                      }
                                                      *plVar11 = *plVar11 + -1;
                                                      if (*plVar11 == 0) {
                                                        FUN_23a334bc0(plVar11);
                                                      }
                                                      if (plVar12 == (longlong *)0x0) {
                                                        plStack_90 = *(longlong **)(param_1 + 0x60);
                                                        plVar12 = *(longlong **)(param_1 + 0x70);
                                                        uStack_80 = 0xc5;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                      }
                                                      else {
                                                        *plVar12 = *plVar12 + -1;
                                                        if (*plVar12 == 0) {
                                                          FUN_23a334bc0(plVar12);
                                                        }
                                                        plVar11 = (longlong *)
                                                                  FUN_23e8bc2f0(plStack_98,
                                                                                _DAT_23eeac950);
                                                        if (plVar11 == (longlong *)0x0) {
                                                          plStack_90 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                          plVar12 = *(longlong **)(param_1 + 0x70);
                                                          uStack_80 = 199;
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          uStack_88 = *(undefined8 *)
                                                                       (param_1 + 0x68);
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                        }
                                                        else {
                                                          plVar12 = (longlong *)
                                                                    FUN_23e8bc2f0(plVar21[2],
                                                                                  _DAT_23eeaca18);
                                                          if (plVar12 == (longlong *)0x0) {
                                                            plStack_90 = *(longlong **)
                                                                          (param_1 + 0x60);
                                                            plVar12 = *(longlong **)(param_1 + 0x70)
                                                            ;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            uStack_80 = 199;
                                                            uStack_88 = *(undefined8 *)
                                                                         (param_1 + 0x68);
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            *plVar11 = *plVar11 + -1;
                                                            if (*plVar11 == 0) {
                                                              FUN_23a334bc0(plVar11,199,0);
                                                              uStack_80 = 199;
                                                            }
                                                          }
                                                          else {
                                                            *(undefined4 *)(plVar10 + 5) = 199;
                                                            plVar18 = (longlong *)
                                                                      FUN_23e914090(param_1);
                                                            *plVar11 = *plVar11 + -1;
                                                            if (*plVar11 == 0) {
                                                              FUN_23a334bc0(plVar11);
                                                            }
                                                            *plVar12 = *plVar12 + -1;
                                                            if (*plVar12 == 0) {
                                                              FUN_23a334bc0(plVar12);
                                                            }
                                                            if (plVar18 == (longlong *)0x0) {
                                                              plStack_90 = *(longlong **)
                                                                            (param_1 + 0x60);
                                                              plVar12 = *(longlong **)
                                                                         (param_1 + 0x70);
                                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                                              uStack_80 = 199;
                                                              uStack_88 = *(undefined8 *)
                                                                           (param_1 + 0x68);
                                                              *(undefined1 (*) [16])(param_1 + 0x60)
                                                                   = (undefined1  [16])0x0;
                                                            }
                                                            else {
                                                              *plVar18 = *plVar18 + -1;
                                                              if (*plVar18 == 0) {
                                                                FUN_23a334bc0(plVar18);
                                                              }
                                                              *(undefined4 *)(plVar10 + 5) = 200;
                                                              plVar11 = (longlong *)
                                                                        FUN_23e915840(param_1,
                                                  plVar14,_DAT_23eeac950,plStack_a0);
                                                  if (plVar11 == (longlong *)0x0) {
                                                    plStack_90 = *(longlong **)(param_1 + 0x60);
                                                    plVar12 = *(longlong **)(param_1 + 0x70);
                                                    uStack_80 = 200;
                                                    uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                  }
                                                  else {
                                                    *plVar11 = *plVar11 + -1;
                                                    if (*plVar11 == 0) {
                                                      FUN_23a334bc0(plVar11);
                                                    }
                                                    plVar11 = (longlong *)
                                                              FUN_23e8bc2f0(plVar21[2],
                                                                            _DAT_23eeac980);
                                                    if (plVar11 == (longlong *)0x0) {
                                                      plStack_90 = *(longlong **)(param_1 + 0x60);
                                                      plVar12 = *(longlong **)(param_1 + 0x70);
                                                      uStack_80 = 0xcb;
                                                      uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                    }
                                                    else {
                                                      plVar12 = (longlong *)
                                                                FUN_23e8bc2f0(plVar11,_DAT_23eeaca80
                                                                             );
                                                      *plVar11 = *plVar11 + -1;
                                                      if (*plVar11 == 0) {
                                                        FUN_23a334bc0(plVar11);
                                                      }
                                                      lVar15 = DAT_23eeac668;
                                                      if (plVar12 == (longlong *)0x0) {
                                                        plStack_90 = *(longlong **)(param_1 + 0x60);
                                                        plVar12 = *(longlong **)(param_1 + 0x70);
                                                        uStack_80 = 0xcb;
                                                        uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                      }
                                                      else {
                                                        *plVar21 = *plVar21 + 1;
                                                        lVar22 = _DAT_23eeaffb0;
                                                        plVar20 = _DAT_23eeaca90;
                                                        plVar18 = _DAT_23eeaca88;
                                                        plVar11 = DAT_23ed6e608;
                                                        if (DAT_23ed6e608 == (longlong *)0x0) {
                                                          plVar11 = (longlong *)
                                                                    FUN_23e916a20(&DAT_23ec10040,1);
                                                        }
                                                        else {
                                                          plVar5 = (longlong *)*DAT_23ed6e608;
                                                          DAT_23ed6e604 = DAT_23ed6e604 + -1;
                                                          plVar1 = DAT_23ed6e608 + 2;
                                                          DAT_23ed6e608 = plVar5;
                                                          if (*plVar1 < 1) {
                                                            plVar11 = (longlong *)
                                                                      _PyObject_GC_Resize(plVar11,1)
                                                            ;
                                                          }
                                                          *plVar11 = 1;
                                                        }
                                                        plVar11[0x1b] = (longlong)plVar21;
                                                        iVar9 = *(int *)(lVar22 + 0x38);
                                                        plVar11[0xf] = (longlong)FUN_23e305670;
                                                        uVar2 = *(uint *)(lVar22 + 0x30);
                                                        plVar11[0x18] = 0;
                                                        plVar11[0x1a] = 1;
                                                        *plVar18 = *plVar18 + 1;
                                                        plVar11[3] = (longlong)plVar18;
                                                        if (plVar20 != (longlong *)0x0) {
                                                          plVar18 = plVar20;
                                                        }
                                                        *plVar18 = *plVar18 + 1;
                                                        plVar11[0x14] = 0;
                                                        iVar3 = *(int *)(lVar22 + 0x40);
                                                        plVar11[8] = (longlong)iVar9;
                                                        lVar19 = (longlong)iVar3 + (longlong)iVar9;
                                                        iVar9 = *(int *)(lVar22 + 0x3c);
                                                        plVar11[0x17] = (longlong)plVar18;
                                                        pcVar7 = _Py_NoneStruct_exref;
                                                        plVar11[6] = lVar22;
                                                        plVar11[0xd] = (longlong)iVar9;
                                                        *(longlong *)pcVar7 =
                                                             *(longlong *)pcVar7 + 1;
                                                        plVar11[0x13] = (longlong)pcVar7;
                                                        plVar11[9] = lVar19;
                                                        *(undefined1 (*) [16])(plVar11 + 0x15) =
                                                             (undefined1  [16])0x0;
                                                        plVar11[7] = (ulonglong)
                                                                     ((int)uVar2 >> 2 & 1) +
                                                                     (ulonglong)
                                                                     ((int)uVar2 >> 3 & 1) + lVar19;
                                                        *(bool *)(plVar11 + 10) =
                                                             (uVar2 & 0xc) == 0 && iVar3 < 1;
                                                        if ((uVar2 & 4) == 0) {
                                                          plVar11[0xb] = -1;
                                                        }
                                                        else {
                                                          plVar11[0xb] = lVar19;
                                                          lVar19 = lVar19 + 1;
                                                        }
                                                        if ((uVar2 & 8) == 0) {
                                                          lVar19 = -1;
                                                        }
                                                        plVar11[0xc] = lVar19;
                                                        lVar22 = *(longlong *)(lVar22 + 0x60);
                                                        *(undefined1 (*) [16])(plVar11 + 0x11) =
                                                             (undefined1  [16])0x0;
                                                        plVar11[5] = 0;
                                                        plVar11[0xe] = lVar22 + 0x18;
                                                        plVar11[4] = lVar15;
                                                        *(int *)(plVar11 + 0x19) = DAT_23ed6e600;
                                                        DAT_23ed6e600 = DAT_23ed6e600 + 1;
                                                        plVar11[0x10] = (longlong)FUN_23e919820;
                                                        lVar15 = *(longlong *)
                                                                  (*(longlong *)
                                                                    (*(longlong *)
                                                                      (_PyRuntime_exref + 0x1f8) +
                                                                    0x10) + 0x2e8);
                                                        lVar22 = plVar11[-1];
                                                        puVar4 = *(undefined8 **)(lVar15 + 8);
                                                        *puVar4 = plVar11 + -2;
                                                        plVar11[-2] = lVar15;
                                                        plVar11[-1] = (ulonglong)((uint)lVar22 & 3)
                                                                      | (ulonglong)puVar4;
                                                        *(longlong **)(lVar15 + 8) = plVar11 + -2;
                                                        *(undefined4 *)(plVar10 + 5) = 0xcb;
                                                        plVar18 = (longlong *)
                                                                  FUN_23e915840(param_1,plVar12);
                                                        lVar15 = *plVar12;
                                                        *plVar12 = lVar15 + -1;
                                                        if (lVar15 + -1 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                        *plVar11 = *plVar11 + -1;
                                                        if (*plVar11 == 0) {
                                                          FUN_23a334bc0(plVar11);
                                                        }
                                                        if (plVar18 == (longlong *)0x0) {
                                                          plStack_90 = *(longlong **)
                                                                        (param_1 + 0x60);
                                                          plVar12 = *(longlong **)(param_1 + 0x70);
                                                          uStack_80 = 0xcb;
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          uStack_88 = *(undefined8 *)
                                                                       (param_1 + 0x68);
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                        }
                                                        else {
                                                          *plVar18 = *plVar18 + -1;
                                                          if (*plVar18 == 0) {
                                                            FUN_23a334bc0(plVar18);
                                                          }
                                                          plVar11 = (longlong *)
                                                                    FUN_23e8bc2f0(plVar21[2],
                                                                                  _DAT_23eeac990);
                                                          if (plVar11 == (longlong *)0x0) {
                                                            plStack_90 = *(longlong **)
                                                                          (param_1 + 0x60);
                                                            plVar12 = *(longlong **)(param_1 + 0x70)
                                                            ;
                                                            uStack_80 = 0xcc;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            uStack_88 = *(undefined8 *)
                                                                         (param_1 + 0x68);
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                          }
                                                          else {
                                                            plVar12 = (longlong *)
                                                                      FUN_23e8bc2f0(plVar11,
                                                  _DAT_23eeaca80);
                                                  *plVar11 = *plVar11 + -1;
                                                  if (*plVar11 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  lVar15 = DAT_23eeac668;
                                                  if (plVar12 == (longlong *)0x0) {
                                                    plStack_90 = *(longlong **)(param_1 + 0x60);
                                                    plVar12 = *(longlong **)(param_1 + 0x70);
                                                    uStack_80 = 0xcc;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  else {
                                                    *plVar21 = *plVar21 + 1;
                                                    lVar22 = _DAT_23eeaffa8;
                                                    plVar18 = _DAT_23eeaca90;
                                                    plVar11 = _DAT_23eeaca88;
                                                    if (DAT_23ed6e608 == (longlong *)0x0) {
                                                      plVar20 = (longlong *)FUN_23e916a20();
                                                    }
                                                    else {
                                                      plVar5 = (longlong *)*DAT_23ed6e608;
                                                      DAT_23ed6e604 = DAT_23ed6e604 + -1;
                                                      plVar1 = DAT_23ed6e608 + 2;
                                                      plVar20 = DAT_23ed6e608;
                                                      DAT_23ed6e608 = plVar5;
                                                      if (*plVar1 < 1) {
                                                        plVar20 = (longlong *)_PyObject_GC_Resize();
                                                      }
                                                      *plVar20 = 1;
                                                    }
                                                    plVar20[0x1b] = (longlong)plVar21;
                                                    plVar20[0xf] = (longlong)FUN_23e305b50;
                                                    plVar20[0x18] = 0;
                                                    iVar9 = *(int *)(lVar22 + 0x38);
                                                    plVar20[0x1a] = 1;
                                                    *plVar11 = *plVar11 + 1;
                                                    plVar20[3] = (longlong)plVar11;
                                                    if (plVar18 != (longlong *)0x0) {
                                                      plVar11 = plVar18;
                                                    }
                                                    iVar3 = *(int *)(lVar22 + 0x40);
                                                    *plVar11 = *plVar11 + 1;
                                                    plVar20[0x17] = (longlong)plVar11;
                                                    lVar19 = (longlong)iVar3 + (longlong)iVar9;
                                                    plVar20[0x14] = 0;
                                                    uVar2 = *(uint *)(lVar22 + 0x30);
                                                    plVar20[8] = (longlong)iVar9;
                                                    iVar9 = *(int *)(lVar22 + 0x3c);
                                                    *(longlong *)pcVar7 = *(longlong *)pcVar7 + 1;
                                                    plVar20[0xd] = (longlong)iVar9;
                                                    plVar20[0x13] = (longlong)pcVar7;
                                                    plVar20[6] = lVar22;
                                                    plVar20[9] = lVar19;
                                                    *(undefined1 (*) [16])(plVar20 + 0x15) =
                                                         (undefined1  [16])0x0;
                                                    plVar20[7] = (ulonglong)((int)uVar2 >> 2 & 1) +
                                                                 (ulonglong)((int)uVar2 >> 3 & 1) +
                                                                 lVar19;
                                                    *(bool *)(plVar20 + 10) =
                                                         (uVar2 & 0xc) == 0 && iVar3 < 1;
                                                    if ((uVar2 & 4) == 0) {
                                                      plVar20[0xb] = -1;
                                                    }
                                                    else {
                                                      plVar20[0xb] = lVar19;
                                                      lVar19 = lVar19 + 1;
                                                    }
                                                    if ((uVar2 & 8) == 0) {
                                                      lVar19 = -1;
                                                    }
                                                    plVar20[0xc] = lVar19;
                                                    lVar22 = *(longlong *)(lVar22 + 0x60);
                                                    *(undefined1 (*) [16])(plVar20 + 0x11) =
                                                         (undefined1  [16])0x0;
                                                    plVar20[0xe] = lVar22 + 0x18;
                                                    plVar20[4] = lVar15;
                                                    plVar20[5] = 0;
                                                    *(int *)(plVar20 + 0x19) = DAT_23ed6e600;
                                                    DAT_23ed6e600 = DAT_23ed6e600 + 1;
                                                    plVar20[0x10] = (longlong)FUN_23e919820;
                                                    lVar15 = *(longlong *)
                                                              (*(longlong *)
                                                                (*(longlong *)
                                                                  (_PyRuntime_exref + 0x1f8) + 0x10)
                                                              + 0x2e8);
                                                    lVar22 = plVar20[-1];
                                                    puVar4 = *(undefined8 **)(lVar15 + 8);
                                                    *puVar4 = plVar20 + -2;
                                                    uVar6 = DAT_23eeac818;
                                                    plVar20[-2] = lVar15;
                                                    plVar20[-1] = (ulonglong)((uint)lVar22 & 3) |
                                                                  (ulonglong)puVar4;
                                                    *(longlong **)(lVar15 + 8) = plVar20 + -2;
                                                    *(undefined4 *)(plVar10 + 5) = 0xcc;
                                                    plVar11 = (longlong *)
                                                              FUN_23e915840(param_1,plVar12,uVar6);
                                                    lVar15 = *plVar12;
                                                    *plVar12 = lVar15 + -1;
                                                    if (lVar15 + -1 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    *plVar20 = *plVar20 + -1;
                                                    if (*plVar20 == 0) {
                                                      FUN_23a334bc0(plVar20);
                                                    }
                                                    if (plVar11 == (longlong *)0x0) {
                                                      plStack_90 = *(longlong **)(param_1 + 0x60);
                                                      plVar12 = *(longlong **)(param_1 + 0x70);
                                                      uStack_80 = 0xcc;
                                                      uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                    }
                                                    else {
                                                      *plVar11 = *plVar11 + -1;
                                                      if (*plVar11 == 0) {
                                                        FUN_23a334bc0(plVar11);
                                                      }
                                                      plVar11 = (longlong *)
                                                                FUN_23e8bc2f0(plVar21[2],
                                                                              _DAT_23eeac9a0);
                                                      if (plVar11 == (longlong *)0x0) {
                                                        plStack_90 = *(longlong **)(param_1 + 0x60);
                                                        plVar12 = *(longlong **)(param_1 + 0x70);
                                                        uStack_80 = 0xcd;
                                                        uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                      }
                                                      else {
                                                        plVar12 = (longlong *)
                                                                  FUN_23e8bc2f0(plVar11,
                                                  _DAT_23eeaca80);
                                                  *plVar11 = *plVar11 + -1;
                                                  if (*plVar11 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  lVar15 = DAT_23eeac668;
                                                  if (plVar12 == (longlong *)0x0) {
                                                    plStack_90 = *(longlong **)(param_1 + 0x60);
                                                    plVar12 = *(longlong **)(param_1 + 0x70);
                                                    uStack_80 = 0xcd;
                                                    uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                  }
                                                  else {
                                                    *plVar21 = *plVar21 + 1;
                                                    lVar22 = _DAT_23eeaffa0;
                                                    plVar20 = _DAT_23eeaca90;
                                                    plVar18 = _DAT_23eeaca88;
                                                    plVar11 = DAT_23ed6e608;
                                                    if (DAT_23ed6e608 == (longlong *)0x0) {
                                                      plVar11 = (longlong *)
                                                                FUN_23e916a20(&DAT_23ec10040,1);
                                                    }
                                                    else {
                                                      plVar5 = (longlong *)*DAT_23ed6e608;
                                                      DAT_23ed6e604 = DAT_23ed6e604 + -1;
                                                      plVar1 = DAT_23ed6e608 + 2;
                                                      DAT_23ed6e608 = plVar5;
                                                      if (*plVar1 < 1) {
                                                        plVar11 = (longlong *)
                                                                  _PyObject_GC_Resize(plVar11,1);
                                                      }
                                                      *plVar11 = 1;
                                                    }
                                                    plVar11[0x1b] = (longlong)plVar21;
                                                    iVar9 = *(int *)(lVar22 + 0x38);
                                                    plVar11[0xf] = (longlong)FUN_23e306030;
                                                    plVar11[0x18] = 0;
                                                    uVar2 = *(uint *)(lVar22 + 0x30);
                                                    plVar11[0x1a] = 1;
                                                    *plVar18 = *plVar18 + 1;
                                                    plVar11[3] = (longlong)plVar18;
                                                    if (plVar20 != (longlong *)0x0) {
                                                      plVar18 = plVar20;
                                                    }
                                                    *plVar18 = *plVar18 + 1;
                                                    plVar11[0x14] = 0;
                                                    iVar3 = *(int *)(lVar22 + 0x40);
                                                    plVar11[0x17] = (longlong)plVar18;
                                                    plVar11[8] = (longlong)iVar9;
                                                    lVar19 = (longlong)iVar3 + (longlong)iVar9;
                                                    iVar9 = *(int *)(lVar22 + 0x3c);
                                                    *(longlong *)pcVar7 = *(longlong *)pcVar7 + 1;
                                                    plVar11[0xd] = (longlong)iVar9;
                                                    plVar11[0x13] = (longlong)pcVar7;
                                                    plVar11[6] = lVar22;
                                                    plVar11[9] = lVar19;
                                                    *(undefined1 (*) [16])(plVar11 + 0x15) =
                                                         (undefined1  [16])0x0;
                                                    plVar11[7] = (ulonglong)((int)uVar2 >> 2 & 1) +
                                                                 (ulonglong)((int)uVar2 >> 3 & 1) +
                                                                 lVar19;
                                                    *(bool *)(plVar11 + 10) =
                                                         (uVar2 & 0xc) == 0 && iVar3 < 1;
                                                    if ((uVar2 & 4) == 0) {
                                                      plVar11[0xb] = -1;
                                                    }
                                                    else {
                                                      plVar11[0xb] = lVar19;
                                                      lVar19 = lVar19 + 1;
                                                    }
                                                    if ((uVar2 & 8) == 0) {
                                                      lVar19 = -1;
                                                    }
                                                    plVar11[0xc] = lVar19;
                                                    lVar22 = *(longlong *)(lVar22 + 0x60);
                                                    plVar11[5] = 0;
                                                    *(undefined1 (*) [16])(plVar11 + 0x11) =
                                                         (undefined1  [16])0x0;
                                                    plVar11[0xe] = lVar22 + 0x18;
                                                    plVar11[4] = lVar15;
                                                    *(int *)(plVar11 + 0x19) = DAT_23ed6e600;
                                                    DAT_23ed6e600 = DAT_23ed6e600 + 1;
                                                    plVar11[0x10] = (longlong)FUN_23e919820;
                                                    lVar15 = *(longlong *)
                                                              (*(longlong *)
                                                                (*(longlong *)
                                                                  (_PyRuntime_exref + 0x1f8) + 0x10)
                                                              + 0x2e8);
                                                    lVar22 = plVar11[-1];
                                                    puVar4 = *(undefined8 **)(lVar15 + 8);
                                                    *puVar4 = plVar11 + -2;
                                                    uVar6 = DAT_23eeac818;
                                                    plVar11[-2] = lVar15;
                                                    plVar11[-1] = (ulonglong)((uint)lVar22 & 3) |
                                                                  (ulonglong)puVar4;
                                                    *(longlong **)(lVar15 + 8) = plVar11 + -2;
                                                    *(undefined4 *)(plVar10 + 5) = 0xcd;
                                                    plVar18 = (longlong *)
                                                              FUN_23e915840(param_1,plVar12,uVar6);
                                                    lVar15 = *plVar12;
                                                    *plVar12 = lVar15 + -1;
                                                    if (lVar15 + -1 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    *plVar11 = *plVar11 + -1;
                                                    if (*plVar11 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    if (plVar18 == (longlong *)0x0) {
                                                      plStack_90 = *(longlong **)(param_1 + 0x60);
                                                      plVar12 = *(longlong **)(param_1 + 0x70);
                                                      uStack_80 = 0xcd;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                    }
                                                    else {
                                                      *plVar18 = *plVar18 + -1;
                                                      if (*plVar18 == 0) {
                                                        FUN_23a334bc0(plVar18);
                                                      }
                                                      plVar11 = (longlong *)
                                                                FUN_23e8bc2f0(plVar21[2]);
                                                      if (plVar11 == (longlong *)0x0) {
                                                        plStack_90 = *(longlong **)(param_1 + 0x60);
                                                        plVar12 = *(longlong **)(param_1 + 0x70);
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        uStack_80 = 0xce;
                                                        uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                      }
                                                      else {
                                                        plVar12 = (longlong *)
                                                                  FUN_23e8bc2f0(plVar11,
                                                  _DAT_23eeaca80);
                                                  *plVar11 = *plVar11 + -1;
                                                  if (*plVar11 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  lVar15 = DAT_23eeac668;
                                                  if (plVar12 == (longlong *)0x0) {
                                                    plStack_90 = *(longlong **)(param_1 + 0x60);
                                                    plVar12 = *(longlong **)(param_1 + 0x70);
                                                    uStack_80 = 0xce;
                                                    uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                  }
                                                  else {
                                                    *plVar21 = *plVar21 + 1;
                                                    lVar22 = _DAT_23eeaff98;
                                                    plVar20 = _DAT_23eeaca90;
                                                    plVar18 = _DAT_23eeaca88;
                                                    plVar11 = DAT_23ed6e608;
                                                    if (DAT_23ed6e608 == (longlong *)0x0) {
                                                      plVar11 = (longlong *)
                                                                FUN_23e916a20(&DAT_23ec10040,1);
                                                    }
                                                    else {
                                                      plVar5 = (longlong *)*DAT_23ed6e608;
                                                      DAT_23ed6e604 = DAT_23ed6e604 + -1;
                                                      plVar1 = DAT_23ed6e608 + 2;
                                                      DAT_23ed6e608 = plVar5;
                                                      if (*plVar1 < 1) {
                                                        plVar11 = (longlong *)
                                                                  _PyObject_GC_Resize(plVar11,1);
                                                      }
                                                      *plVar11 = 1;
                                                    }
                                                    plVar11[0x1b] = (longlong)plVar21;
                                                    iVar9 = *(int *)(lVar22 + 0x38);
                                                    plVar11[0xf] = (longlong)FUN_23e306510;
                                                    uVar2 = *(uint *)(lVar22 + 0x30);
                                                    plVar11[0x18] = 0;
                                                    plVar11[0x1a] = 1;
                                                    *plVar18 = *plVar18 + 1;
                                                    plVar11[3] = (longlong)plVar18;
                                                    if (plVar20 != (longlong *)0x0) {
                                                      plVar18 = plVar20;
                                                    }
                                                    *plVar18 = *plVar18 + 1;
                                                    plVar11[0x14] = 0;
                                                    iVar3 = *(int *)(lVar22 + 0x40);
                                                    plVar11[0x17] = (longlong)plVar18;
                                                    plVar11[8] = (longlong)iVar9;
                                                    lVar19 = (longlong)iVar3 + (longlong)iVar9;
                                                    iVar9 = *(int *)(lVar22 + 0x3c);
                                                    *(longlong *)pcVar7 = *(longlong *)pcVar7 + 1;
                                                    plVar11[0xd] = (longlong)iVar9;
                                                    plVar11[0x13] = (longlong)pcVar7;
                                                    plVar11[6] = lVar22;
                                                    plVar11[9] = lVar19;
                                                    *(undefined1 (*) [16])(plVar11 + 0x15) =
                                                         (undefined1  [16])0x0;
                                                    plVar11[7] = (ulonglong)((int)uVar2 >> 2 & 1) +
                                                                 (ulonglong)((int)uVar2 >> 3 & 1) +
                                                                 lVar19;
                                                    *(bool *)(plVar11 + 10) =
                                                         (uVar2 & 0xc) == 0 && iVar3 < 1;
                                                    if ((uVar2 & 4) == 0) {
                                                      plVar11[0xb] = -1;
                                                    }
                                                    else {
                                                      plVar11[0xb] = lVar19;
                                                      lVar19 = lVar19 + 1;
                                                    }
                                                    if ((uVar2 & 8) == 0) {
                                                      lVar19 = -1;
                                                    }
                                                    plVar11[0xc] = lVar19;
                                                    lVar22 = *(longlong *)(lVar22 + 0x60);
                                                    *(undefined1 (*) [16])(plVar11 + 0x11) =
                                                         (undefined1  [16])0x0;
                                                    plVar11[0xe] = lVar22 + 0x18;
                                                    plVar11[4] = lVar15;
                                                    plVar11[5] = 0;
                                                    *(int *)(plVar11 + 0x19) = DAT_23ed6e600;
                                                    DAT_23ed6e600 = DAT_23ed6e600 + 1;
                                                    plVar11[0x10] = (longlong)FUN_23e919820;
                                                    lVar15 = *(longlong *)
                                                              (*(longlong *)
                                                                (*(longlong *)
                                                                  (_PyRuntime_exref + 0x1f8) + 0x10)
                                                              + 0x2e8);
                                                    lVar22 = plVar11[-1];
                                                    puVar4 = *(undefined8 **)(lVar15 + 8);
                                                    *puVar4 = plVar11 + -2;
                                                    uVar6 = DAT_23eeac818;
                                                    plVar11[-2] = lVar15;
                                                    plVar11[-1] = (ulonglong)((uint)lVar22 & 3) |
                                                                  (ulonglong)puVar4;
                                                    *(longlong **)(lVar15 + 8) = plVar11 + -2;
                                                    *(undefined4 *)(plVar10 + 5) = 0xce;
                                                    plVar18 = (longlong *)
                                                              FUN_23e915840(param_1,plVar12,uVar6);
                                                    lVar15 = *plVar12;
                                                    *plVar12 = lVar15 + -1;
                                                    if (lVar15 + -1 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    *plVar11 = *plVar11 + -1;
                                                    if (*plVar11 == 0) {
                                                      FUN_23a334bc0(plVar11);
                                                    }
                                                    if (plVar18 != (longlong *)0x0) {
                                                      *plVar18 = *plVar18 + -1;
                                                      if (*plVar18 == 0) {
                                                        FUN_23a334bc0(plVar18);
                                                      }
                                                      FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38))
                                                      ;
                                                      *(longlong *)pcVar7 = *(longlong *)pcVar7 + 1;
                                                      *plVar21 = *plVar21 + -1;
                                                      if (*plVar21 == 0) {
                                                        FUN_23a334bc0(plVar21);
                                                      }
                                                      *plVar13 = *plVar13 + -1;
                                                      if (*plVar13 == 0) {
                                                        FUN_23a334bc0(plVar13);
                                                      }
                                                      *plVar14 = *plVar14 + -1;
                                                      if (*plVar14 == 0) {
                                                        FUN_23a334bc0(plVar14);
                                                      }
                                                      *plVar16 = *plVar16 + -1;
                                                      if (*plVar16 == 0) {
                                                        FUN_23a334bc0(plVar16);
                                                      }
                                                      *plVar17 = *plVar17 + -1;
                                                      if (*plVar17 == 0) {
                                                        FUN_23a334bc0(plVar17);
                                                      }
                                                      lVar15 = *plStack_a8;
                                                      *plStack_a8 = lVar15 + -1;
                                                      if (lVar15 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_a8);
                                                      }
                                                      lVar15 = *plStack_b0;
                                                      *plStack_b0 = lVar15 + -1;
                                                      if (lVar15 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_b0);
                                                      }
                                                      lVar15 = *plStack_a0;
                                                      *plStack_a0 = lVar15 + -1;
                                                      if (lVar15 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_a0);
                                                      }
                                                      lVar15 = *plStack_98;
                                                      *plStack_98 = lVar15 + -1;
                                                      if (lVar15 + -1 != 0) {
                                                        return pcVar7;
                                                      }
                                                      FUN_23a334bc0(plStack_98);
                                                      return pcVar7;
                                                    }
                                                    plStack_90 = *(longlong **)(param_1 + 0x60);
                                                    plVar12 = *(longlong **)(param_1 + 0x70);
                                                    uStack_80 = 0xce;
                                                    uStack_88 = *(undefined8 *)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
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
              }
            }
          }
        }
      }
    }
  }
LAB_23e3024b0:
  plVar11 = DAT_23ed6a4f8;
  if (plVar12 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar12 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar12;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar7 = _PyRuntime_exref;
    plVar11[2] = 0;
    plVar11[3] = (longlong)plVar10;
    *plVar10 = *plVar10 + 1;
    lVar15 = *(longlong *)(pcVar7 + 0x1f8);
    *(undefined4 *)((longlong)plVar11 + 0x24) = uStack_80;
    lVar15 = *(longlong *)(lVar15 + 0x10);
    *(undefined4 *)(plVar11 + 4) = 0xffffffff;
    lVar15 = *(longlong *)(lVar15 + 0x2e8);
    lVar22 = plVar11[-1];
    puVar4 = *(undefined8 **)(lVar15 + 8);
    *puVar4 = plVar11 + -2;
    plVar11[-2] = lVar15;
    plVar11[-1] = (ulonglong)((uint)lVar22 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar15 + 8) = plVar11 + -2;
    plVar18 = plVar11;
  }
  else {
    plVar18 = plVar12;
    if ((longlong *)plVar12[3] != plVar10) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar18 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar18;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar7 = _PyRuntime_exref;
      plVar11[3] = (longlong)plVar10;
      *plVar10 = *plVar10 + 1;
      *(undefined4 *)((longlong)plVar11 + 0x24) = uStack_80;
      lVar15 = *(longlong *)(pcVar7 + 0x1f8);
      *(undefined4 *)(plVar11 + 4) = 0xffffffff;
      lVar15 = *(longlong *)(*(longlong *)(lVar15 + 0x10) + 0x2e8);
      lVar22 = plVar11[-1];
      puVar4 = *(undefined8 **)(lVar15 + 8);
      *puVar4 = plVar11 + -2;
      plVar11[-2] = lVar15;
      plVar11[-1] = (ulonglong)((uint)lVar22 & 3) | (ulonglong)puVar4;
      lVar22 = *plVar12;
      *(longlong **)(lVar15 + 8) = plVar11 + -2;
      plVar11[2] = (longlong)plVar12;
      plVar18 = plVar11;
      if (lVar22 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
    }
  }
  FUN_23e8bba40(plVar10,"coooooooo",plVar21,plVar13,plVar14,plVar16,plVar17,plStack_a8,plStack_b0,
                plStack_a0,plStack_98);
  if (_DAT_23eeafef0 == plVar10) {
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    _DAT_23eeafef0 = (longlong *)0x0;
  }
  lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar10 = *(longlong **)(lVar15 + 0x28);
  plVar11 = (longlong *)plVar10[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
  *(undefined4 *)(plVar10 + 8) = 0xffffffff;
  if (plVar11 != (longlong *)0x0) {
    plVar10[2] = 0;
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))();
    }
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  plVar10[0xf] = 0;
  *plVar21 = *plVar21 + -1;
  if (*plVar21 == 0) {
    (**(code **)(plVar21[1] + 0x30))(plVar21);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
    (**(code **)(plVar17[1] + 0x30))(plVar17);
  }
  if ((plStack_a8 != (longlong *)0x0) &&
     (lVar15 = *plStack_a8, *plStack_a8 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(plStack_a8[1] + 0x30))(plStack_a8);
  }
  if ((plStack_b0 != (longlong *)0x0) &&
     (lVar15 = *plStack_b0, *plStack_b0 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(plStack_b0[1] + 0x30))(plStack_b0);
  }
  if ((plStack_a0 != (longlong *)0x0) &&
     (lVar15 = *plStack_a0, *plStack_a0 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(plStack_a0[1] + 0x30))(plStack_a0);
  }
  if ((plStack_98 != (longlong *)0x0) &&
     (lVar15 = *plStack_98, *plStack_98 = lVar15 + -1, lVar15 + -1 == 0)) {
    (**(code **)(plStack_98[1] + 0x30))(plStack_98);
  }
  FUN_23a33aa70(param_1,plStack_90,uStack_88,plVar18);
  return (code *)0x0;
}
