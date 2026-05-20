/* ===== 23e317480 ui.telegram_tab:34 ===== */
/* ghidra_name=FUN_23e317480 entry=23e317480 size=26966 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e317480(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong lVar16;
  longlong *plStack_e8;
  longlong *plStack_e0;
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
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined4 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar9 = _DAT_23eeb4cd8;
  param_3 = (longlong *)*param_3;
  if (_DAT_23eeb4cd8 == (longlong *)0x0) {
LAB_23e3174c5:
    _DAT_23eeb4cd8 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb4cd0,DAT_23eeb4cf0,0x98);
  }
  else {
    lVar7 = *_DAT_23eeb4cd8;
    if (1 < lVar7) {
      *_DAT_23eeb4cd8 = lVar7 + -1;
      goto LAB_23e3174c5;
    }
    if (_DAT_23eeb4cd8[2] != 0) {
      *_DAT_23eeb4cd8 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e3174c5;
    }
  }
  plVar3 = _DAT_23eeb4cd8;
  lVar7 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eeb4cd8 + 9;
  lVar16 = *(longlong *)(lVar7 + 8);
  _DAT_23eeb4cd8[0xf] = lVar16;
  *(longlong **)(lVar7 + 8) = plVar9;
  if ((lVar16 != 0) &&
     (((*(char *)(lVar16 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar16 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar16 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar16 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar16 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  lVar7 = FUN_23e8f4ca0();
  if (lVar7 == 0) {
    plVar14 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    FUN_23e915740(param_1,&uStack_68,_DAT_23eeb39c0);
    uStack_70 = 0x24;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    uStack_80 = uStack_68;
    plStack_c0 = (longlong *)0x0;
    uStack_78 = uStack_60;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    plVar9 = plStack_58;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x24;
  plVar8 = (longlong *)FUN_23e914090(param_1,lVar7,param_3);
  lVar7 = _DAT_23eeb39d0;
  if (plVar8 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    uStack_70 = 0x24;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x25;
  plVar9 = (longlong *)FUN_23e95a860(param_1,plVar8,_DAT_23eeb39c8,lVar7 + 0x18);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    uStack_70 = 0x25;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  lVar7 = _DAT_23eeb39e0;
  *(undefined4 *)(plVar3 + 5) = 0x26;
  plVar9 = (longlong *)FUN_23e915840(param_1,plVar8,_DAT_23eeb39d8,*(undefined8 *)(lVar7 + 0x18));
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    uStack_70 = 0x26;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  lVar7 = *(longlong *)(DAT_23eeb3ee0 + 0x20);
  if (*(char *)(lVar7 + 10) == '\0') {
    plVar9 = (longlong *)FUN_23a37a020(DAT_23eeb3ee0,_DAT_23eeb39e8);
    if (plVar9 == (longlong *)0x0) goto LAB_23e3197c9;
    lVar7 = *plVar9;
LAB_23e31a288:
    if (lVar7 == 0) goto LAB_23e3197c9;
  }
  else {
    iVar6 = *(int *)(lVar7 + 0xc);
    if (*(int *)(lVar7 + 0xc) == 0) {
      *(int *)(lVar7 + 0xc) = DAT_23ec1506c;
      iVar6 = DAT_23ec1506c;
      DAT_23ec1506c = DAT_23ec1506c + 1;
    }
    if (_DAT_23ec15060 != iVar6) {
      _DAT_23ec15060 = iVar6;
      _DAT_23eeb4cb8 = FUN_23e8cbd60(lVar7,_DAT_23eeb39e8,*(undefined8 *)(_DAT_23eeb39e8 + 0x18));
    }
    if (-1 < _DAT_23eeb4cb8) {
      lVar16 = lVar7 + 0x20 + (1L << (*(byte *)(lVar7 + 9) & 0x3f));
      if (*(longlong *)(lVar16 + 8 + _DAT_23eeb4cb8 * 0x10) != 0) goto LAB_23e317660;
      _DAT_23eeb4cb8 = FUN_23e8cbd60(lVar7,_DAT_23eeb39e8,*(undefined8 *)(_DAT_23eeb39e8 + 0x18));
      if (-1 < _DAT_23eeb4cb8) {
        lVar7 = *(longlong *)(lVar16 + 8 + _DAT_23eeb4cb8 * 0x10);
        goto LAB_23e31a288;
      }
    }
LAB_23e3197c9:
    plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeb39e8);
    if ((plVar9 == (longlong *)0x0) || (*plVar9 == 0)) {
      plVar14 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      FUN_23e915740(param_1,&uStack_68,_DAT_23eeb39e8);
      uStack_70 = 0x29;
      plStack_b8 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      uStack_80 = uStack_68;
      plStack_c0 = (longlong *)0x0;
      uStack_78 = uStack_60;
      plStack_88 = (longlong *)0x0;
      plStack_90 = (longlong *)0x0;
      plStack_98 = (longlong *)0x0;
      plStack_b0 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x0;
      plStack_a0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plVar9 = plStack_58;
      goto LAB_23e3198e0;
    }
  }
LAB_23e317660:
  *(undefined4 *)(plVar3 + 5) = 0x29;
  plVar10 = (longlong *)FUN_23e91a870(param_1);
  lVar7 = _DAT_23eeb39f8;
  if (plVar10 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    uStack_70 = 0x29;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x2a;
  plVar9 = (longlong *)FUN_23e915840(param_1,plVar10,_DAT_23eeb39f0,*(undefined8 *)(lVar7 + 0x18));
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    uStack_70 = 0x2a;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar12 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23eeb3a00);
  if (plVar11 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar12 = (longlong *)0x0;
    uStack_70 = 0x2b;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar13 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = FUN_23e8f4dd0();
  if (lVar7 == 0) {
    FUN_23e915740(param_1,&uStack_68,_DAT_23eeb3a08);
    *plVar11 = *plVar11 + -1;
    uStack_80 = uStack_68;
    uStack_78 = uStack_60;
    plVar12 = (longlong *)0x0;
    plVar9 = plStack_58;
    if (*plVar11 == 0) {
      plVar14 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      (**(code **)(plVar11[1] + 0x30))(plVar11);
      uStack_70 = 0x2b;
      plStack_b8 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      plStack_c0 = (longlong *)0x0;
      plStack_88 = (longlong *)0x0;
      plStack_90 = (longlong *)0x0;
      plStack_98 = (longlong *)0x0;
      plStack_b0 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x0;
      plStack_a0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
    }
    else {
      plStack_b8 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      uStack_70 = 0x2b;
      plStack_a8 = (longlong *)0x0;
      plStack_c0 = (longlong *)0x0;
      plStack_88 = (longlong *)0x0;
      plStack_90 = (longlong *)0x0;
      plStack_98 = (longlong *)0x0;
      plStack_b0 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x0;
      plStack_a0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
    }
    goto LAB_23e3198e0;
  }
  plVar9 = (longlong *)FUN_23e8bc2f0(lVar7,_DAT_23eeb3a10);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar11 = *plVar11 + -1;
    plVar12 = (longlong *)0x0;
    if (*plVar11 == 0) {
      plVar14 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      (**(code **)(plVar11[1] + 0x30))(plVar11);
      uStack_70 = 0x2b;
      plStack_b8 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      plStack_c0 = (longlong *)0x0;
      plStack_88 = (longlong *)0x0;
      plStack_90 = (longlong *)0x0;
      plStack_98 = (longlong *)0x0;
      plStack_b0 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x0;
      plStack_a0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
    }
    else {
      plStack_b8 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      uStack_70 = 0x2b;
      plStack_a8 = (longlong *)0x0;
      plStack_c0 = (longlong *)0x0;
      plStack_88 = (longlong *)0x0;
      plStack_90 = (longlong *)0x0;
      plStack_98 = (longlong *)0x0;
      plStack_b0 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x0;
      plStack_a0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
    }
    goto LAB_23e3198e0;
  }
  plVar12 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23eeb3a18);
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if (plVar12 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar11 = *plVar11 + -1;
    plVar14 = (longlong *)0x0;
    if (*plVar11 == 0) {
      plVar12 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      (**(code **)(plVar11[1] + 0x30))(plVar11);
      uStack_70 = 0x2b;
      plStack_b8 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      plStack_c0 = (longlong *)0x0;
      plStack_88 = (longlong *)0x0;
      plStack_90 = (longlong *)0x0;
      plStack_98 = (longlong *)0x0;
      plStack_b0 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x0;
      plStack_a0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
    }
    else {
      plStack_b8 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      uStack_70 = 0x2b;
      plStack_a8 = (longlong *)0x0;
      plStack_c0 = (longlong *)0x0;
      plStack_88 = (longlong *)0x0;
      plStack_90 = (longlong *)0x0;
      plStack_98 = (longlong *)0x0;
      plStack_b0 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x0;
      plStack_a0 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
    }
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x2b;
  plVar9 = (longlong *)FUN_23e914090(param_1,plVar11,plVar12);
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    uStack_70 = 0x2b;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar12 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  lVar7 = FUN_23e8f4f20();
  if (lVar7 == 0) {
    plVar14 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    FUN_23e915740(param_1,&uStack_68,_DAT_23eeb3a20);
    uStack_70 = 0x2d;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    uStack_80 = uStack_68;
    plStack_c0 = (longlong *)0x0;
    uStack_78 = uStack_60;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    plVar9 = plStack_58;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x2d;
  plVar12 = (longlong *)FUN_23e91a870(param_1,lVar7);
  if (plVar12 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    uStack_70 = 0x2d;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = FUN_23e8f4ca0();
  if (lVar7 == 0) {
    plVar14 = (longlong *)0x0;
    FUN_23e915740(param_1,&uStack_68,_DAT_23eeb39c0);
    uStack_70 = 0x2e;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    uStack_80 = uStack_68;
    plStack_c0 = (longlong *)0x0;
    uStack_78 = uStack_60;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar9 = plStack_58;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x2e;
  plVar13 = (longlong *)FUN_23e914090(param_1,lVar7,plVar12);
  lVar7 = _DAT_23eeb3a28;
  if (plVar13 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_70 = 0x2e;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x2f;
  plVar9 = (longlong *)FUN_23e95a860(param_1,plVar13,_DAT_23eeb39c8,lVar7 + 0x18);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_70 = 0x2f;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar14 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  lVar7 = _DAT_23eeb39e0;
  *(undefined4 *)(plVar3 + 5) = 0x30;
  plVar9 = (longlong *)FUN_23e915840(param_1,plVar13,_DAT_23eeb39d8,*(undefined8 *)(lVar7 + 0x18));
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_70 = 0x30;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar14 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  lVar7 = FUN_23e8f48b0();
  if (lVar7 == 0) {
    FUN_23e915740(param_1,&uStack_68,_DAT_23eeb3a30);
    uStack_70 = 0x33;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    uStack_80 = uStack_68;
    plStack_c0 = (longlong *)0x0;
    uStack_78 = uStack_60;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    plVar9 = plStack_58;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x33;
  plVar14 = (longlong *)FUN_23e94bb80(param_1,lVar7,_DAT_23eeb3a38);
  lVar7 = _DAT_23eeb3a48;
  if (plVar14 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_70 = 0x33;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x34;
  plVar9 = (longlong *)FUN_23e915840(param_1,plVar14,_DAT_23eeb3a40,*(undefined8 *)(lVar7 + 0x18));
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_70 = 0x34;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_e0 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  lVar7 = FUN_23e8f4b50();
  if (lVar7 == 0) {
    FUN_23e915740(param_1,&uStack_68,_DAT_23eeb3a50);
    uStack_70 = 0x35;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    uStack_80 = uStack_68;
    plStack_c0 = (longlong *)0x0;
    uStack_78 = uStack_60;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plVar9 = plStack_58;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x35;
  plStack_e0 = (longlong *)FUN_23e91a870(param_1,lVar7);
  lVar7 = _DAT_23eeb3a60;
  if (plStack_e0 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_70 = 0x35;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x36;
  plVar9 = (longlong *)
           FUN_23e915840(param_1,plStack_e0,_DAT_23eeb3a58,*(undefined8 *)(lVar7 + 0x18));
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_70 = 0x36;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_e8 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  lVar7 = _DAT_23eeb39f8;
  *(undefined4 *)(plVar3 + 5) = 0x37;
  plVar9 = (longlong *)
           FUN_23e915840(param_1,plStack_e0,_DAT_23eeb3a68,*(undefined8 *)(lVar7 + 0x18));
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_70 = 0x37;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_e8 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  *(undefined4 *)(plVar3 + 5) = 0x38;
  plVar9 = (longlong *)FUN_23e915840(param_1,plVar14,_DAT_23eeb3a70,plStack_e0);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_70 = 0x38;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_e8 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  *(undefined4 *)(plVar3 + 5) = 0x39;
  plVar9 = (longlong *)FUN_23e915840(param_1,plVar13,_DAT_23eeb3a78,plVar14);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_70 = 0x39;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_e8 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  lVar7 = _DAT_23eeb3a88;
  *(undefined4 *)(plVar3 + 5) = 0x3a;
  plVar9 = (longlong *)FUN_23e915840(param_1,plVar13,_DAT_23eeb3a80,*(undefined8 *)(lVar7 + 0x18));
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_70 = 0x3a;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_e8 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  lVar7 = FUN_23e8f4dd0();
  if (lVar7 == 0) {
    FUN_23e915740(param_1,&uStack_68,_DAT_23eeb3a08);
    uStack_70 = 0x3d;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    uStack_80 = uStack_68;
    plStack_c0 = (longlong *)0x0;
    uStack_78 = uStack_60;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plVar9 = plStack_58;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x3d;
  plStack_e8 = (longlong *)FUN_23e91a870(param_1,lVar7);
  lVar7 = _DAT_23eeb3a90;
  if (plStack_e8 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_70 = 0x3d;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x3e;
  plVar9 = (longlong *)
           FUN_23e915840(param_1,plStack_e8,_DAT_23eeb3a40,*(undefined8 *)(lVar7 + 0x18));
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_70 = 0x3e;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_d8 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  lVar7 = FUN_23e8f4ca0();
  if (lVar7 == 0) {
    FUN_23e915740(param_1,&uStack_68,_DAT_23eeb39c0);
    uStack_70 = 0x3f;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    uStack_80 = uStack_68;
    plStack_c0 = (longlong *)0x0;
    uStack_78 = uStack_60;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plVar9 = plStack_58;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x3f;
  plStack_d8 = (longlong *)FUN_23e914090(param_1,lVar7,plStack_e8);
  if (plStack_d8 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_70 = 0x3f;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x40;
  plVar9 = (longlong *)FUN_23e95a860(param_1,plStack_d8,_DAT_23eeb39c8,_DAT_23eeb3a98 + 0x18);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_70 = 0x40;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_c8 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    (**(code **)(plVar9[1] + 0x30))();
  }
  lVar7 = FUN_23e8f48b0();
  if (lVar7 == 0) {
    FUN_23e915740(param_1,&uStack_68,_DAT_23eeb3a30);
    uStack_70 = 0x42;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    uStack_80 = uStack_68;
    plStack_c0 = (longlong *)0x0;
    uStack_78 = uStack_60;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plVar9 = plStack_58;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x42;
  plStack_c8 = (longlong *)FUN_23e94bb80(param_1,lVar7,_DAT_23eeb3aa0);
  if (plStack_c8 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_70 = 0x42;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = FUN_23e8f4b50();
  if (lVar7 == 0) {
    FUN_23e915740(param_1,&uStack_68,_DAT_23eeb3a50);
    uStack_70 = 0x43;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    uStack_80 = uStack_68;
    plStack_c0 = (longlong *)0x0;
    uStack_78 = uStack_60;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    plStack_a0 = (longlong *)0x0;
    plVar9 = plStack_58;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x43;
  plStack_a0 = (longlong *)FUN_23e91a870(param_1,lVar7);
  lVar7 = _DAT_23eeb3aa8;
  if (plStack_a0 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_70 = 0x43;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x44;
  plVar9 = (longlong *)
           FUN_23e915840(param_1,plStack_a0,_DAT_23eeb3a58,*(undefined8 *)(lVar7 + 0x18));
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    uStack_70 = 0x44;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_d0 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    (**(code **)(plVar9[1] + 0x30))();
  }
  lVar7 = _DAT_23eeb39f8;
  *(undefined4 *)(plVar3 + 5) = 0x45;
  plVar9 = (longlong *)
           FUN_23e915840(param_1,plStack_a0,_DAT_23eeb3a68,*(undefined8 *)(lVar7 + 0x18));
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    uStack_70 = 0x45;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_d0 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  *(undefined4 *)(plVar3 + 5) = 0x46;
  plVar9 = (longlong *)FUN_23e915840(param_1,plStack_c8,_DAT_23eeb3a70,plStack_a0);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x46;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    (**(code **)(plVar9[1] + 0x30))();
  }
  *(undefined4 *)(plVar3 + 5) = 0x47;
  plVar9 = (longlong *)FUN_23e915840(param_1,plStack_d8,_DAT_23eeb3a78,plStack_c8);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x47;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  lVar7 = *(longlong *)(DAT_23eeb3ee0 + 0x20);
  if (*(char *)(lVar7 + 10) == '\0') {
    plVar9 = (longlong *)FUN_23a37a020(DAT_23eeb3ee0,_DAT_23eeb3ab0);
    if (plVar9 == (longlong *)0x0) goto LAB_23e31bafe;
    lVar7 = *plVar9;
LAB_23e31baf5:
    if (lVar7 == 0) goto LAB_23e31bafe;
  }
  else {
    iVar6 = *(int *)(lVar7 + 0xc);
    if (*(int *)(lVar7 + 0xc) == 0) {
      *(int *)(lVar7 + 0xc) = DAT_23ec1506c;
      iVar6 = DAT_23ec1506c;
      DAT_23ec1506c = DAT_23ec1506c + 1;
    }
    if (_DAT_23ec15064 != iVar6) {
      _DAT_23ec15064 = iVar6;
      _DAT_23eeb4cc0 = FUN_23e8cbd60(lVar7,_DAT_23eeb3ab0,*(undefined8 *)(_DAT_23eeb3ab0 + 0x18));
    }
    if (-1 < _DAT_23eeb4cc0) {
      lVar16 = lVar7 + 0x20 + (1L << (*(byte *)(lVar7 + 9) & 0x3f));
      if (*(longlong *)(lVar16 + 8 + _DAT_23eeb4cc0 * 0x10) != 0) goto LAB_23e317e1e;
      _DAT_23eeb4cc0 = FUN_23e8cbd60(lVar7,_DAT_23eeb3ab0,*(undefined8 *)(_DAT_23eeb3ab0 + 0x18));
      if (-1 < _DAT_23eeb4cc0) {
        lVar7 = *(longlong *)(lVar16 + 8 + _DAT_23eeb4cc0 * 0x10);
        goto LAB_23e31baf5;
      }
    }
LAB_23e31bafe:
    plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeb3ab0);
    if ((plVar9 == (longlong *)0x0) || (*plVar9 == 0)) {
      FUN_23e915740(param_1,&uStack_68,_DAT_23eeb3ab0);
      uStack_70 = 0x4a;
      uStack_80 = uStack_68;
      uStack_78 = uStack_60;
      plStack_b8 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      plStack_c0 = (longlong *)0x0;
      plStack_88 = (longlong *)0x0;
      plStack_90 = (longlong *)0x0;
      plStack_98 = (longlong *)0x0;
      plStack_b0 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x0;
      plVar9 = plStack_58;
      goto LAB_23e3198e0;
    }
  }
LAB_23e317e1e:
  *(undefined4 *)(plVar3 + 5) = 0x4a;
  plStack_d0 = (longlong *)FUN_23e91a870(param_1);
  lVar7 = _DAT_23eeb39f8;
  if (plStack_d0 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_70 = 0x4a;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x4b;
  plVar9 = (longlong *)
           FUN_23e915840(param_1,plStack_d0,_DAT_23eeb3ab8,*(undefined8 *)(lVar7 + 0x18));
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x4b;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  *(undefined4 *)(plVar3 + 5) = 0x4c;
  plVar9 = (longlong *)FUN_23e915840(param_1,plStack_d0);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x4c;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    (**(code **)(plVar9[1] + 0x30))();
  }
  plVar11 = (longlong *)FUN_23e8bc2f0(plStack_d0,_DAT_23eeb3a00);
  if (plVar11 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    uStack_70 = 0x4d;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_90 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = FUN_23e8f4dd0();
  if (lVar7 == 0) {
    FUN_23e915740(param_1,&uStack_68);
    uStack_80 = uStack_68;
    uStack_78 = uStack_60;
    lVar7 = *plVar11;
    *plVar11 = lVar7 + -1;
    plStack_b0 = (longlong *)0x0;
    plVar9 = plStack_58;
    if (lVar7 + -1 == 0) {
      FUN_23a334bc0();
      uStack_70 = 0x4d;
      plStack_b8 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      plStack_c0 = (longlong *)0x0;
      plStack_88 = (longlong *)0x0;
      plStack_90 = (longlong *)0x0;
      plStack_98 = (longlong *)0x0;
    }
    else {
      uStack_70 = 0x4d;
      plStack_b8 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      plStack_c0 = (longlong *)0x0;
      plStack_88 = (longlong *)0x0;
      plStack_90 = (longlong *)0x0;
      plStack_98 = (longlong *)0x0;
    }
    goto LAB_23e3198e0;
  }
  plVar9 = (longlong *)FUN_23e8bc2f0(lVar7,_DAT_23eeb3a10);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    lVar7 = *plVar11;
    *plVar11 = lVar7 + -1;
    plStack_b0 = (longlong *)0x0;
    if (lVar7 + -1 == 0) {
      FUN_23a334bc0(plVar11);
      uStack_70 = 0x4d;
      plStack_b8 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      plStack_c0 = (longlong *)0x0;
      plStack_88 = (longlong *)0x0;
      plStack_90 = (longlong *)0x0;
      plStack_98 = (longlong *)0x0;
    }
    else {
      uStack_70 = 0x4d;
      plStack_b8 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      plStack_c0 = (longlong *)0x0;
      plStack_88 = (longlong *)0x0;
      plStack_90 = (longlong *)0x0;
      plStack_98 = (longlong *)0x0;
    }
    goto LAB_23e3198e0;
  }
  plVar15 = (longlong *)FUN_23e8bc2f0();
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    (**(code **)(plVar9[1] + 0x30))();
  }
  if (plVar15 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    lVar7 = *plVar11;
    *plVar11 = lVar7 + -1;
    plStack_98 = (longlong *)0x0;
    if (lVar7 + -1 == 0) {
      FUN_23a334bc0();
      plStack_b8 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      plStack_c0 = (longlong *)0x0;
      plStack_88 = (longlong *)0x0;
      plStack_90 = (longlong *)0x0;
      plStack_b0 = (longlong *)0x0;
      uStack_70 = 0x4d;
    }
    else {
      plStack_b8 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      plStack_c0 = (longlong *)0x0;
      plStack_88 = (longlong *)0x0;
      plStack_90 = (longlong *)0x0;
      plStack_b0 = (longlong *)0x0;
      uStack_70 = 0x4d;
    }
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x4d;
  plVar9 = (longlong *)FUN_23e914090(param_1,plVar11,plVar15);
  lVar7 = *plVar11;
  *plVar11 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  lVar7 = *plVar15;
  *plVar15 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x4d;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    (**(code **)(plVar9[1] + 0x30))();
  }
  lVar7 = _DAT_23eeb3ad8;
  *(undefined4 *)(plVar3 + 5) = 0x4e;
  plVar9 = (longlong *)
           FUN_23e915840(param_1,plStack_d0,_DAT_23eeb3ad0,*(undefined8 *)(lVar7 + 0x18));
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x4e;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  lVar7 = _DAT_23eeb3ae8;
  *(undefined4 *)(plVar3 + 5) = 0x4f;
  plVar9 = (longlong *)
           FUN_23e915840(param_1,plStack_d0,_DAT_23eeb3ae0,*(undefined8 *)(lVar7 + 0x18));
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x4f;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    (**(code **)(plVar9[1] + 0x30))();
  }
  *(undefined4 *)(plVar3 + 5) = 0x5a;
  plVar9 = (longlong *)FUN_23e915840(param_1,plStack_d8,_DAT_23eeb3a78,plStack_d0);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x5a;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0(plVar9);
  }
  *(undefined4 *)(plVar3 + 5) = 0x5c;
  plVar9 = (longlong *)FUN_23e915840(param_1,plVar13,_DAT_23eeb3a78,plStack_e8);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x5c;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0();
  }
  *(undefined4 *)(plVar3 + 5) = 0x5d;
  plVar9 = (longlong *)FUN_23e915840(param_1,plVar13,_DAT_23eeb3a80);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    uStack_70 = 0x5d;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_b0 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0(plVar9);
  }
  lVar7 = FUN_23e8f4dd0();
  if (lVar7 == 0) {
    FUN_23e915740(param_1,&uStack_68,_DAT_23eeb3a08);
    plStack_b8 = (longlong *)0x0;
    uStack_70 = 0x60;
    uStack_80 = uStack_68;
    plStack_a8 = (longlong *)0x0;
    uStack_78 = uStack_60;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plStack_b0 = (longlong *)0x0;
    plVar9 = plStack_58;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x60;
  plStack_b0 = (longlong *)FUN_23e91a870(param_1,lVar7);
  lVar7 = _DAT_23eeb3a90;
  if (plStack_b0 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    uStack_70 = 0x60;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x61;
  plVar9 = (longlong *)
           FUN_23e915840(param_1,plStack_b0,_DAT_23eeb3a40,*(undefined8 *)(lVar7 + 0x18));
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    uStack_70 = 0x61;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_98 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0();
  }
  lVar7 = FUN_23e8f4ca0();
  if (lVar7 == 0) {
    FUN_23e915740(param_1,&uStack_68,_DAT_23eeb39c0);
    plStack_b8 = (longlong *)0x0;
    uStack_70 = 0x62;
    uStack_80 = uStack_68;
    plStack_a8 = (longlong *)0x0;
    uStack_78 = uStack_60;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plStack_98 = (longlong *)0x0;
    plVar9 = plStack_58;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x62;
  plStack_98 = (longlong *)FUN_23e914090(param_1,lVar7,plStack_b0);
  lVar7 = _DAT_23eeb3a98;
  if (plStack_98 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    uStack_70 = 0x62;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 99;
  plVar9 = (longlong *)FUN_23e95a860(param_1,plStack_98,_DAT_23eeb39c8,lVar7 + 0x18);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 99;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0();
  }
  lVar7 = _DAT_23eeb3af8;
  *(undefined4 *)(plVar3 + 5) = 100;
  plVar9 = (longlong *)
           FUN_23e915840(param_1,plStack_98,_DAT_23eeb39d8,*(undefined8 *)(lVar7 + 0x18));
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 100;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0(plVar9);
  }
  lVar7 = FUN_23e8f48b0();
  if (lVar7 == 0) {
    FUN_23e915740(param_1,&uStack_68,_DAT_23eeb3a30);
    uStack_70 = 0x67;
    uStack_80 = uStack_68;
    uStack_78 = uStack_60;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plStack_90 = (longlong *)0x0;
    plVar9 = plStack_58;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x67;
  plStack_90 = (longlong *)FUN_23e94bb80(param_1,lVar7,_DAT_23eeb3b00);
  if (plStack_90 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x67;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = FUN_23e8f4b50();
  if (lVar7 == 0) {
    FUN_23e915740(param_1,&uStack_68,_DAT_23eeb3a50);
    uStack_70 = 0x68;
    uStack_80 = uStack_68;
    uStack_78 = uStack_60;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_88 = (longlong *)0x0;
    plVar9 = plStack_58;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x68;
  plStack_88 = (longlong *)FUN_23e91a870(param_1,lVar7);
  lVar7 = _DAT_23eeb3af8;
  if (plStack_88 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    uStack_70 = 0x68;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x69;
  plVar9 = (longlong *)
           FUN_23e915840(param_1,plStack_88,_DAT_23eeb3a58,*(undefined8 *)(lVar7 + 0x18));
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    uStack_70 = 0x69;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_a8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_c0 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0();
  }
  *(undefined4 *)(plVar3 + 5) = 0x6a;
  plVar9 = (longlong *)FUN_23e915840(param_1,plStack_88,_DAT_23eeb3a68);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    uStack_70 = 0x6a;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_a8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_c0 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0();
  }
  *(undefined4 *)(plVar3 + 5) = 0x6b;
  plVar9 = (longlong *)FUN_23e915840(param_1,plStack_90,_DAT_23eeb3a70,plStack_88);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    uStack_70 = 0x6b;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_a8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_c0 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0(plVar9);
  }
  *(undefined4 *)(plVar3 + 5) = 0x6c;
  plVar9 = (longlong *)FUN_23e915840(param_1,plStack_98,_DAT_23eeb3a78,plStack_90);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    uStack_70 = 0x6c;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_a8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_c0 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0();
  }
  lVar7 = FUN_23e8f4a00();
  if (lVar7 == 0) {
    FUN_23e915740(param_1,&uStack_68,_DAT_23eeb3b08);
    plStack_b8 = (longlong *)0x0;
    uStack_80 = uStack_68;
    plStack_a8 = (longlong *)0x0;
    uStack_70 = 0x6e;
    uStack_78 = uStack_60;
    plStack_c0 = (longlong *)0x0;
    plVar9 = plStack_58;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x6e;
  plVar9 = (longlong *)FUN_23e91a870(param_1,lVar7);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x6e;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  cVar5 = FUN_23e8d9ac0(param_3,_DAT_23eeb3b10,plVar9);
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0(plVar9);
  }
  if (cVar5 == '\0') {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x6e;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  plVar9 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeb3b10);
  lVar7 = _DAT_23eeb3b20;
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x6f;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x6f;
  plVar11 = (longlong *)FUN_23e915840(param_1,plVar9,_DAT_23eeb3b18,*(undefined8 *)(lVar7 + 0x18));
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0(plVar9);
  }
  if (plVar11 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x6f;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar11;
  *plVar11 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0();
  }
  plVar9 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeb3b10);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    uStack_70 = 0x70;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_c0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_a8 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x70;
  plVar11 = (longlong *)FUN_23e915840(param_1,plVar9,_DAT_23eeb3b28);
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0(plVar9);
  }
  if (plVar11 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    uStack_70 = 0x70;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_a8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_c0 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar11;
  *plVar11 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0(plVar11);
  }
  plVar9 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeb3b10);
  lVar7 = _DAT_23eeb3b38;
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    uStack_70 = 0x71;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_c0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_a8 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x71;
  plVar11 = (longlong *)FUN_23e915840(param_1,plVar9,_DAT_23eeb3ad0,*(undefined8 *)(lVar7 + 0x18));
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0(plVar9);
  }
  if (plVar11 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    uStack_70 = 0x71;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_a8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_c0 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar11;
  *plVar11 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0();
  }
  plVar11 = (longlong *)FUN_23e8bc2f0(plStack_98,_DAT_23eeb3a78);
  if (plVar11 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    uStack_70 = 0x7e;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_c0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_a8 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  plVar9 = (longlong *)FUN_23e8bc2f0(param_3);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    lVar7 = *plVar11;
    *plVar11 = lVar7 + -1;
    plStack_c0 = (longlong *)0x0;
    if (lVar7 + -1 == 0) {
      FUN_23a334bc0(plVar11);
      uStack_70 = 0x7e;
      plStack_b8 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
    }
    else {
      uStack_70 = 0x7e;
      plStack_b8 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
    }
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x7e;
  plVar15 = (longlong *)FUN_23e914090(param_1,plVar11,plVar9);
  lVar7 = *plVar11;
  *plVar11 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0(plVar11);
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0();
  }
  if (plVar15 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x7e;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plStack_b8 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar15;
  *plVar15 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0(plVar15);
  }
  lVar7 = _DAT_23eeb39e0;
  *(undefined4 *)(plVar3 + 5) = 0x80;
  plVar9 = (longlong *)
           FUN_23e915840(param_1,plStack_98,_DAT_23eeb3a80,*(undefined8 *)(lVar7 + 0x18));
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x80;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0();
  }
  lVar7 = FUN_23e8f48b0();
  if (lVar7 == 0) {
    FUN_23e915740(param_1,&uStack_68,_DAT_23eeb3a30);
    uStack_70 = 0x83;
    uStack_80 = uStack_68;
    uStack_78 = uStack_60;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    plStack_c0 = (longlong *)0x0;
    plVar9 = plStack_58;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x83;
  plStack_c0 = (longlong *)FUN_23e94bb80(param_1,lVar7,_DAT_23eeb3b40);
  if (plStack_c0 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x83;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b8 = (longlong *)0x0;
    plStack_a8 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = FUN_23e8f4b50();
  if (lVar7 == 0) {
    FUN_23e915740(param_1,&uStack_68,_DAT_23eeb3a50);
    plStack_b8 = (longlong *)0x0;
    uStack_70 = 0x84;
    uStack_80 = uStack_68;
    uStack_78 = uStack_60;
    plStack_a8 = (longlong *)0x0;
    plVar9 = plStack_58;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x84;
  plStack_a8 = (longlong *)FUN_23e91a870(param_1,lVar7);
  if (plStack_a8 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_b8 = (longlong *)0x0;
    uStack_70 = 0x84;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x85;
  plVar9 = (longlong *)FUN_23e915840(param_1,plStack_a8,_DAT_23eeb3a58);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x85;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_b8 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0();
  }
  lVar7 = _DAT_23eeb39f8;
  *(undefined4 *)(plVar3 + 5) = 0x86;
  plVar9 = (longlong *)
           FUN_23e915840(param_1,plStack_a8,_DAT_23eeb3a68,*(undefined8 *)(lVar7 + 0x18));
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x86;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_b8 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0(plVar9);
  }
  *(undefined4 *)(plVar3 + 5) = 0x87;
  plVar9 = (longlong *)FUN_23e915840(param_1,plStack_c0,_DAT_23eeb3a70,plStack_a8);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x87;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_b8 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0();
  }
  *(undefined4 *)(plVar3 + 5) = 0x88;
  plVar9 = (longlong *)FUN_23e915840(param_1,plStack_98,_DAT_23eeb3a78,plStack_c0);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_70 = 0x88;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_b8 = (longlong *)0x0;
    goto LAB_23e3198e0;
  }
  lVar7 = *plVar9;
  *plVar9 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    FUN_23a334bc0(plVar9);
  }
  lVar7 = FUN_23e8f48b0();
  if (lVar7 == 0) {
    FUN_23e915740(param_1,&uStack_68,_DAT_23eeb3a30);
    uStack_70 = 0x8a;
    uStack_80 = uStack_68;
    uStack_78 = uStack_60;
    plStack_b8 = (longlong *)0x0;
    plVar9 = plStack_58;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x8a;
  plStack_b8 = (longlong *)FUN_23e94bb80(param_1,lVar7,_DAT_23eeb3b48);
  lVar7 = _DAT_23eeb3b50;
  if (plStack_b8 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x8a;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x8b;
  plVar9 = (longlong *)
           FUN_23e915840(param_1,plStack_b8,_DAT_23eeb3ad0,*(undefined8 *)(lVar7 + 0x18));
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x8b;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23e3198e0;
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    FUN_23a334bc0(plVar9);
  }
  *(undefined4 *)(plVar3 + 5) = 0x8c;
  plVar9 = (longlong *)FUN_23e915840(param_1,plStack_98,_DAT_23eeb3a78,plStack_b8);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x8c;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23e3198e0;
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    FUN_23a334bc0(plVar9);
  }
  lVar7 = FUN_23e8f4a00();
  if (lVar7 == 0) {
    FUN_23e915740(param_1,&uStack_68,_DAT_23eeb3b08);
    uStack_70 = 0x8e;
    uStack_80 = uStack_68;
    uStack_78 = uStack_60;
    plVar9 = plStack_58;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x8e;
  plVar9 = (longlong *)FUN_23e91a870(param_1,lVar7);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x8e;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23e3198e0;
  }
  cVar5 = FUN_23e8d9ac0(param_3,_DAT_23eeb3b58,plVar9);
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    FUN_23a334bc0(plVar9);
  }
  if (cVar5 == '\0') {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x8e;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23e3198e0;
  }
  plVar9 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeb3b58);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x8f;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x8f;
  plVar11 = (longlong *)FUN_23e915840(param_1,plVar9,_DAT_23eeb3b18);
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    FUN_23a334bc0(plVar9);
  }
  if (plVar11 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x8f;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3198e0;
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    FUN_23a334bc0(plVar11);
  }
  plVar9 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeb3b58);
  lVar7 = _DAT_23eeb3b30;
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x90;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x90;
  plVar11 = (longlong *)FUN_23e915840(param_1,plVar9,_DAT_23eeb3b28,*(undefined8 *)(lVar7 + 0x18));
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    FUN_23a334bc0(plVar9);
  }
  if (plVar11 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x90;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3198e0;
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    FUN_23a334bc0(plVar11);
  }
  plVar9 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeb3b58);
  lVar7 = _DAT_23eeb3b38;
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x91;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x91;
  plVar11 = (longlong *)FUN_23e915840(param_1,plVar9,_DAT_23eeb3ad0,*(undefined8 *)(lVar7 + 0x18));
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    FUN_23a334bc0(plVar9);
  }
  if (plVar11 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_70 = 0x91;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e3198e0;
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    FUN_23a334bc0(plVar11);
  }
  plVar11 = (longlong *)FUN_23e8bc2f0(plStack_98,_DAT_23eeb3a78);
  if (plVar11 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x9e;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23e3198e0;
  }
  plVar9 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeb3b58);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x9e;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      FUN_23a334bc0(plVar11);
      uStack_70 = 0x9e;
    }
    goto LAB_23e3198e0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x9e;
  plVar15 = (longlong *)FUN_23e914090(param_1,plVar11,plVar9);
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    FUN_23a334bc0(plVar11);
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    FUN_23a334bc0(plVar9);
  }
  if (plVar15 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0x9e;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23e3198e0;
  }
  *plVar15 = *plVar15 + -1;
  if (*plVar15 == 0) {
    FUN_23a334bc0(plVar15);
  }
  *(undefined4 *)(plVar3 + 5) = 0xa0;
  plVar9 = (longlong *)FUN_23e915840(param_1,plVar13,_DAT_23eeb3a78,plStack_b0);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0xa0;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23e3198e0;
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    FUN_23a334bc0(plVar9);
  }
  *(undefined4 *)(plVar3 + 5) = 0xa1;
  plVar9 = (longlong *)FUN_23e915840(param_1,plVar13,_DAT_23eeb3a80);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0xa1;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23e3198e0;
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    FUN_23a334bc0(plVar9);
  }
  lVar7 = *(longlong *)(DAT_23eeb3ee0 + 0x20);
  if (*(char *)(lVar7 + 10) == '\0') {
    plVar9 = (longlong *)FUN_23a37a020(DAT_23eeb3ee0,_DAT_23eeb3b68);
    if (plVar9 == (longlong *)0x0) goto LAB_23e31da9b;
    lVar16 = *plVar9;
LAB_23e31da92:
    if (lVar16 == 0) goto LAB_23e31da9b;
  }
  else {
    iVar6 = *(int *)(lVar7 + 0xc);
    if (*(int *)(lVar7 + 0xc) == 0) {
      *(int *)(lVar7 + 0xc) = DAT_23ec1506c;
      iVar6 = DAT_23ec1506c;
      DAT_23ec1506c = DAT_23ec1506c + 1;
    }
    if (_DAT_23ec15068 != iVar6) {
      _DAT_23ec15068 = iVar6;
      _DAT_23eeb4cc8 = FUN_23e8cbd60(lVar7,_DAT_23eeb3b68,*(undefined8 *)(_DAT_23eeb3b68 + 0x18));
    }
    if (-1 < _DAT_23eeb4cc8) {
      lVar1 = lVar7 + 0x20 + (1L << (*(byte *)(lVar7 + 9) & 0x3f));
      lVar16 = *(longlong *)(lVar1 + 8 + _DAT_23eeb4cc8 * 0x10);
      if (lVar16 != 0) goto LAB_23e318f31;
      _DAT_23eeb4cc8 = FUN_23e8cbd60(lVar7,_DAT_23eeb3b68,*(undefined8 *)(_DAT_23eeb3b68 + 0x18));
      if (-1 < _DAT_23eeb4cc8) {
        lVar16 = *(longlong *)(lVar1 + 8 + _DAT_23eeb4cc8 * 0x10);
        goto LAB_23e31da92;
      }
    }
LAB_23e31da9b:
    plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeb3b68);
    if ((plVar9 == (longlong *)0x0) || (lVar16 = *plVar9, lVar16 == 0)) {
      FUN_23e915740(param_1,&uStack_68,_DAT_23eeb3b68);
      uStack_70 = 0xa4;
      uStack_80 = uStack_68;
      uStack_78 = uStack_60;
      plVar9 = plStack_58;
      goto LAB_23e3198e0;
    }
  }
LAB_23e318f31:
  *(undefined4 *)(plVar3 + 5) = 0xa4;
  plVar9 = (longlong *)FUN_23e94bb80(param_1,lVar16,_DAT_23eeb3b70);
  if (plVar9 == (longlong *)0x0) {
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    uStack_70 = 0xa4;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  else {
    cVar5 = FUN_23e8d9ac0(param_3,_DAT_23eeb3b78,plVar9);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      FUN_23a334bc0(plVar9);
    }
    if (cVar5 == '\0') {
      uStack_80 = *(undefined8 *)(param_1 + 0x60);
      plVar9 = *(longlong **)(param_1 + 0x70);
      uStack_70 = 0xa4;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uStack_78 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
    else {
      plVar9 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeb3b78);
      lVar7 = _DAT_23eeb3b80;
      if (plVar9 == (longlong *)0x0) {
        uStack_80 = *(undefined8 *)(param_1 + 0x60);
        plVar9 = *(longlong **)(param_1 + 0x70);
        uStack_70 = 0xa5;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_78 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        *(undefined4 *)(plVar3 + 5) = 0xa5;
        plVar11 = (longlong *)
                  FUN_23e915840(param_1,plVar9,_DAT_23eeb3a40,*(undefined8 *)(lVar7 + 0x18));
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          FUN_23a334bc0(plVar9);
        }
        if (plVar11 == (longlong *)0x0) {
          uStack_80 = *(undefined8 *)(param_1 + 0x60);
          plVar9 = *(longlong **)(param_1 + 0x70);
          uStack_70 = 0xa5;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uStack_78 = *(undefined8 *)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        }
        else {
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            FUN_23a334bc0(plVar11);
          }
          plVar9 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeb3b78);
          lVar7 = _DAT_23eeb3b88;
          if (plVar9 == (longlong *)0x0) {
            uStack_80 = *(undefined8 *)(param_1 + 0x60);
            plVar9 = *(longlong **)(param_1 + 0x70);
            uStack_70 = 0xa6;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uStack_78 = *(undefined8 *)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          else {
            *(undefined4 *)(plVar3 + 5) = 0xa6;
            plVar11 = (longlong *)
                      FUN_23e915840(param_1,plVar9,_DAT_23eeb3b28,*(undefined8 *)(lVar7 + 0x18));
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              FUN_23a334bc0(plVar9);
            }
            if (plVar11 == (longlong *)0x0) {
              uStack_80 = *(undefined8 *)(param_1 + 0x60);
              plVar9 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              uStack_70 = 0xa6;
              uStack_78 = *(undefined8 *)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            else {
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                FUN_23a334bc0(plVar11);
              }
              plVar9 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeb3b78);
              if (plVar9 == (longlong *)0x0) {
                uStack_80 = *(undefined8 *)(param_1 + 0x60);
                plVar9 = *(longlong **)(param_1 + 0x70);
                uStack_70 = 0xa7;
                uStack_78 = *(undefined8 *)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
              }
              else {
                plVar11 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23eeb3b90);
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  FUN_23a334bc0();
                }
                if (plVar11 == (longlong *)0x0) {
                  uStack_80 = *(undefined8 *)(param_1 + 0x60);
                  plVar9 = *(longlong **)(param_1 + 0x70);
                  uStack_70 = 0xa7;
                  uStack_78 = *(undefined8 *)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                }
                else {
                  plVar15 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23eeb3b98);
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    FUN_23a334bc0(plVar11);
                  }
                  if (plVar15 == (longlong *)0x0) {
                    uStack_80 = *(undefined8 *)(param_1 + 0x60);
                    plVar9 = *(longlong **)(param_1 + 0x70);
                    uStack_70 = 0xa7;
                    uStack_78 = *(undefined8 *)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                  }
                  else {
                    plVar9 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeb3ba0);
                    if (plVar9 == (longlong *)0x0) {
                      uStack_80 = *(undefined8 *)(param_1 + 0x60);
                      plVar9 = *(longlong **)(param_1 + 0x70);
                      uStack_70 = 0xa7;
                      uStack_78 = *(undefined8 *)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *plVar15 = *plVar15 + -1;
                      if (*plVar15 == 0) {
                        FUN_23a334bc0(plVar15);
                        uStack_70 = 0xa7;
                      }
                    }
                    else {
                      *(undefined4 *)(plVar3 + 5) = 0xa7;
                      plVar11 = (longlong *)FUN_23e914090(param_1,plVar15,plVar9);
                      *plVar15 = *plVar15 + -1;
                      if (*plVar15 == 0) {
                        FUN_23a334bc0(plVar15);
                      }
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 == 0) {
                        FUN_23a334bc0(plVar9);
                      }
                      if (plVar11 == (longlong *)0x0) {
                        uStack_80 = *(undefined8 *)(param_1 + 0x60);
                        plVar9 = *(longlong **)(param_1 + 0x70);
                        uStack_70 = 0xa7;
                        uStack_78 = *(undefined8 *)(param_1 + 0x68);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                      }
                      else {
                        *plVar11 = *plVar11 + -1;
                        if (*plVar11 == 0) {
                          FUN_23a334bc0(plVar11);
                        }
                        plVar11 = (longlong *)FUN_23e8bc2f0(plVar13,_DAT_23eeb3a78);
                        if (plVar11 == (longlong *)0x0) {
                          uStack_80 = *(undefined8 *)(param_1 + 0x60);
                          plVar9 = *(longlong **)(param_1 + 0x70);
                          uStack_70 = 0xa8;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          uStack_78 = *(undefined8 *)(param_1 + 0x68);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        }
                        else {
                          plVar9 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeb3b78);
                          if (plVar9 == (longlong *)0x0) {
                            uStack_80 = *(undefined8 *)(param_1 + 0x60);
                            plVar9 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uStack_70 = 0xa8;
                            uStack_78 = *(undefined8 *)(param_1 + 0x68);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *plVar11 = *plVar11 + -1;
                            if (*plVar11 == 0) {
                              FUN_23a334bc0(plVar11);
                              uStack_70 = 0xa8;
                            }
                          }
                          else {
                            *(undefined4 *)(plVar3 + 5) = 0xa8;
                            plVar15 = (longlong *)FUN_23e914090(param_1,plVar11,plVar9);
                            *plVar11 = *plVar11 + -1;
                            if (*plVar11 == 0) {
                              FUN_23a334bc0(plVar11);
                            }
                            *plVar9 = *plVar9 + -1;
                            if (*plVar9 == 0) {
                              FUN_23a334bc0(plVar9);
                            }
                            if (plVar15 == (longlong *)0x0) {
                              uStack_80 = *(undefined8 *)(param_1 + 0x60);
                              plVar9 = *(longlong **)(param_1 + 0x70);
                              uStack_70 = 0xa8;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              uStack_78 = *(undefined8 *)(param_1 + 0x68);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            }
                            else {
                              *plVar15 = *plVar15 + -1;
                              if (*plVar15 == 0) {
                                FUN_23a334bc0(plVar15);
                              }
                              lVar7 = _DAT_23eeb3a88;
                              *(undefined4 *)(plVar3 + 5) = 0xaa;
                              plVar9 = (longlong *)
                                       FUN_23e915840(param_1,plVar13,_DAT_23eeb3a80,
                                                     *(undefined8 *)(lVar7 + 0x18));
                              if (plVar9 == (longlong *)0x0) {
                                uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                plVar9 = *(longlong **)(param_1 + 0x70);
                                uStack_70 = 0xaa;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              }
                              else {
                                *plVar9 = *plVar9 + -1;
                                if (*plVar9 == 0) {
                                  FUN_23a334bc0(plVar9);
                                }
                                lVar7 = FUN_23e8f48b0();
                                if (lVar7 == 0) {
                                  FUN_23e915740(param_1,&uStack_68,_DAT_23eeb3a30);
                                  uStack_70 = 0xad;
                                  uStack_80 = uStack_68;
                                  uStack_78 = uStack_60;
                                  plVar9 = plStack_58;
                                }
                                else {
                                  *(undefined4 *)(plVar3 + 5) = 0xad;
                                  plVar9 = (longlong *)FUN_23e94bb80(param_1,lVar7,_DAT_23eeb3ba8);
                                  if (plVar9 == (longlong *)0x0) {
                                    uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                    plVar9 = *(longlong **)(param_1 + 0x70);
                                    uStack_70 = 0xad;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  }
                                  else {
                                    cVar5 = FUN_23e8d9ac0(param_3,_DAT_23eeb3bb0,plVar9);
                                    *plVar9 = *plVar9 + -1;
                                    if (*plVar9 == 0) {
                                      FUN_23a334bc0(plVar9);
                                    }
                                    if (cVar5 == '\0') {
                                      uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                      plVar9 = *(longlong **)(param_1 + 0x70);
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      uStack_70 = 0xad;
                                      uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                    }
                                    else {
                                      plVar9 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeb3bb0);
                                      lVar7 = _DAT_23eeb3bb8;
                                      if (plVar9 == (longlong *)0x0) {
                                        uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                        plVar9 = *(longlong **)(param_1 + 0x70);
                                        uStack_70 = 0xae;
                                        uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                      }
                                      else {
                                        *(undefined4 *)(plVar3 + 5) = 0xae;
                                        plVar11 = (longlong *)
                                                  FUN_23e915840(param_1,plVar9,_DAT_23eeb3ad0,
                                                                *(undefined8 *)(lVar7 + 0x18));
                                        *plVar9 = *plVar9 + -1;
                                        if (*plVar9 == 0) {
                                          FUN_23a334bc0(plVar9);
                                        }
                                        if (plVar11 == (longlong *)0x0) {
                                          uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                          plVar9 = *(longlong **)(param_1 + 0x70);
                                          uStack_70 = 0xae;
                                          uStack_78 = *(undefined8 *)(param_1 + 0x68);
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
                                                    FUN_23e8bc2f0(plVar13,_DAT_23eeb3a78);
                                          if (plVar11 == (longlong *)0x0) {
                                            uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                            plVar9 = *(longlong **)(param_1 + 0x70);
                                            uStack_70 = 0xb7;
                                            uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                          }
                                          else {
                                            plVar9 = (longlong *)
                                                     FUN_23e8bc2f0(param_3,_DAT_23eeb3bb0);
                                            if (plVar9 == (longlong *)0x0) {
                                              uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                              plVar9 = *(longlong **)(param_1 + 0x70);
                                              uStack_70 = 0xb7;
                                              uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              *plVar11 = *plVar11 + -1;
                                              if (*plVar11 == 0) {
                                                FUN_23a334bc0(plVar11);
                                                uStack_70 = 0xb7;
                                              }
                                            }
                                            else {
                                              *(undefined4 *)(plVar3 + 5) = 0xb7;
                                              plVar15 = (longlong *)
                                                        FUN_23e914090(param_1,plVar11,plVar9);
                                              *plVar11 = *plVar11 + -1;
                                              if (*plVar11 == 0) {
                                                FUN_23a334bc0(plVar11);
                                              }
                                              *plVar9 = *plVar9 + -1;
                                              if (*plVar9 == 0) {
                                                FUN_23a334bc0(plVar9);
                                              }
                                              if (plVar15 == (longlong *)0x0) {
                                                uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                                plVar9 = *(longlong **)(param_1 + 0x70);
                                                uStack_70 = 0xb7;
                                                uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                              }
                                              else {
                                                *plVar15 = *plVar15 + -1;
                                                if (*plVar15 == 0) {
                                                  FUN_23a334bc0(plVar15);
                                                }
                                                *(undefined4 *)(plVar3 + 5) = 0xba;
                                                plVar9 = (longlong *)
                                                         FUN_23e91bfe0(param_1,plVar13,
                                                                       _DAT_23eeb3bc0);
                                                if (plVar9 == (longlong *)0x0) {
                                                  uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                                  plVar9 = *(longlong **)(param_1 + 0x70);
                                                  uStack_70 = 0xba;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                }
                                                else {
                                                  *plVar9 = *plVar9 + -1;
                                                  if (*plVar9 == 0) {
                                                    FUN_23a334bc0(plVar9);
                                                  }
                                                  *(undefined4 *)(plVar3 + 5) = 0xbc;
                                                  plVar9 = (longlong *)
                                                           FUN_23e915840(param_1,plVar10,
                                                                         _DAT_23eeb3bc8,plVar12);
                                                  if (plVar9 == (longlong *)0x0) {
                                                    uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                                    plVar9 = *(longlong **)(param_1 + 0x70);
                                                    uStack_70 = 0xbc;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  else {
                                                    *plVar9 = *plVar9 + -1;
                                                    if (*plVar9 == 0) {
                                                      FUN_23a334bc0(plVar9);
                                                    }
                                                    *(undefined4 *)(plVar3 + 5) = 0xbd;
                                                    plVar9 = (longlong *)
                                                             FUN_23e915840(param_1,plVar8,
                                                                           _DAT_23eeb3a78);
                                                    if (plVar9 != (longlong *)0x0) {
                                                      *plVar9 = *plVar9 + -1;
                                                      if (*plVar9 == 0) {
                                                        FUN_23a334bc0(plVar9);
                                                      }
                                                      FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38))
                                                      ;
                                                      pcVar4 = _Py_NoneStruct_exref;
                                                      *(longlong *)_Py_NoneStruct_exref =
                                                           *(longlong *)_Py_NoneStruct_exref + 1;
                                                      *plVar8 = *plVar8 + -1;
                                                      if (*plVar8 == 0) {
                                                        FUN_23a334bc0(plVar8);
                                                      }
                                                      *plVar10 = *plVar10 + -1;
                                                      if (*plVar10 == 0) {
                                                        FUN_23a334bc0(plVar10);
                                                      }
                                                      *plVar12 = *plVar12 + -1;
                                                      if (*plVar12 == 0) {
                                                        FUN_23a334bc0(plVar12);
                                                      }
                                                      *plVar13 = *plVar13 + -1;
                                                      if (*plVar13 == 0) {
                                                        FUN_23a334bc0(plVar13);
                                                      }
                                                      *plVar14 = *plVar14 + -1;
                                                      if (*plVar14 == 0) {
                                                        FUN_23a334bc0(plVar14);
                                                      }
                                                      lVar7 = *plStack_e0;
                                                      *plStack_e0 = lVar7 + -1;
                                                      if (lVar7 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_e0);
                                                      }
                                                      lVar7 = *plStack_e8;
                                                      *plStack_e8 = lVar7 + -1;
                                                      if (lVar7 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_e8);
                                                      }
                                                      lVar7 = *plStack_d8;
                                                      *plStack_d8 = lVar7 + -1;
                                                      if (lVar7 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_d8);
                                                      }
                                                      lVar7 = *plStack_c8;
                                                      *plStack_c8 = lVar7 + -1;
                                                      if (lVar7 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_c8);
                                                      }
                                                      lVar7 = *plStack_a0;
                                                      *plStack_a0 = lVar7 + -1;
                                                      if (lVar7 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_a0);
                                                      }
                                                      lVar7 = *plStack_d0;
                                                      *plStack_d0 = lVar7 + -1;
                                                      if (lVar7 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_d0);
                                                      }
                                                      lVar7 = *plStack_b0;
                                                      *plStack_b0 = lVar7 + -1;
                                                      if (lVar7 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_b0);
                                                      }
                                                      lVar7 = *plStack_98;
                                                      *plStack_98 = lVar7 + -1;
                                                      if (lVar7 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_98);
                                                      }
                                                      lVar7 = *plStack_90;
                                                      *plStack_90 = lVar7 + -1;
                                                      if (lVar7 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_90);
                                                      }
                                                      lVar7 = *plStack_88;
                                                      *plStack_88 = lVar7 + -1;
                                                      if (lVar7 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_88);
                                                      }
                                                      lVar7 = *plStack_c0;
                                                      *plStack_c0 = lVar7 + -1;
                                                      if (lVar7 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_c0);
                                                      }
                                                      lVar7 = *plStack_a8;
                                                      *plStack_a8 = lVar7 + -1;
                                                      if (lVar7 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_a8);
                                                      }
                                                      lVar7 = *plStack_b8;
                                                      *plStack_b8 = lVar7 + -1;
                                                      if (lVar7 + -1 == 0) {
                                                        FUN_23a334bc0(plStack_b8);
                                                      }
                                                      lVar7 = *param_3;
                                                      *param_3 = lVar7 + -1;
                                                      if (lVar7 + -1 != 0) {
                                                        return pcVar4;
                                                      }
                                                      FUN_23a334bc0(param_3);
                                                      return pcVar4;
                                                    }
                                                    uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                                    plVar9 = *(longlong **)(param_1 + 0x70);
                                                    uStack_70 = 0xbd;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    uStack_78 = *(undefined8 *)(param_1 + 0x68);
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
        }
      }
    }
  }
LAB_23e3198e0:
  plVar11 = DAT_23ed6a4f8;
  if (plVar9 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar9 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar9;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar4 = _PyRuntime_exref;
    plVar11[2] = 0;
    plVar11[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar7 = *(longlong *)(pcVar4 + 0x1f8);
    *(undefined4 *)((longlong)plVar11 + 0x24) = uStack_70;
    lVar7 = *(longlong *)(lVar7 + 0x10);
    *(undefined4 *)(plVar11 + 4) = 0xffffffff;
    lVar7 = *(longlong *)(lVar7 + 0x2e8);
    lVar16 = plVar11[-1];
    puVar2 = *(undefined8 **)(lVar7 + 8);
    *puVar2 = plVar11 + -2;
    plVar11[-2] = lVar7;
    plVar11[-1] = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar7 + 8) = plVar11 + -2;
    plVar15 = plVar11;
  }
  else {
    plVar15 = plVar9;
    if ((longlong *)plVar9[3] != plVar3) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar15 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar15;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar11[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      *(undefined4 *)((longlong)plVar11 + 0x24) = uStack_70;
      pcVar4 = _PyRuntime_exref;
      *(undefined4 *)(plVar11 + 4) = 0xffffffff;
      lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar4 + 0x1f8) + 0x10) + 0x2e8);
      lVar16 = plVar11[-1];
      puVar2 = *(undefined8 **)(lVar7 + 8);
      *puVar2 = plVar11 + -2;
      plVar11[-2] = lVar7;
      plVar11[-1] = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar2;
      lVar16 = *plVar9;
      *(longlong **)(lVar7 + 8) = plVar11 + -2;
      plVar11[2] = (longlong)plVar9;
      plVar15 = plVar11;
      if (lVar16 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
    }
  }
  FUN_23e8bba40(plVar3,"ooooooooooooooooooo",param_3,plVar8,plVar10,plVar12,plVar13,plVar14,
                plStack_e0,plStack_e8,plStack_d8,plStack_c8,plStack_a0,plStack_d0,plStack_b0,
                plStack_98,plStack_90,plStack_88,plStack_c0,plStack_a8,plStack_b8);
  if (_DAT_23eeb4cd8 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eeb4cd8 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar7 + 0x28);
  plVar3 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
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
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((plStack_e0 != (longlong *)0x0) &&
     (lVar7 = *plStack_e0, *plStack_e0 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
  }
  if ((plStack_e8 != (longlong *)0x0) &&
     (lVar7 = *plStack_e8, *plStack_e8 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
  }
  if ((plStack_d8 != (longlong *)0x0) &&
     (lVar7 = *plStack_d8, *plStack_d8 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
  }
  if ((plStack_c8 != (longlong *)0x0) &&
     (lVar7 = *plStack_c8, *plStack_c8 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_c8[1] + 0x30))(plStack_c8);
  }
  if ((plStack_a0 != (longlong *)0x0) &&
     (lVar7 = *plStack_a0, *plStack_a0 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_a0[1] + 0x30))(plStack_a0);
  }
  if ((plStack_d0 != (longlong *)0x0) &&
     (lVar7 = *plStack_d0, *plStack_d0 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_d0[1] + 0x30))(plStack_d0);
  }
  if ((plStack_b0 != (longlong *)0x0) &&
     (lVar7 = *plStack_b0, *plStack_b0 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_b0[1] + 0x30))(plStack_b0);
  }
  if ((plStack_98 != (longlong *)0x0) &&
     (lVar7 = *plStack_98, *plStack_98 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_98[1] + 0x30))(plStack_98);
  }
  if ((plStack_90 != (longlong *)0x0) &&
     (lVar7 = *plStack_90, *plStack_90 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_90[1] + 0x30))(plStack_90);
  }
  if ((plStack_88 != (longlong *)0x0) &&
     (lVar7 = *plStack_88, *plStack_88 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_88[1] + 0x30))(plStack_88);
  }
  if ((plStack_c0 != (longlong *)0x0) &&
     (lVar7 = *plStack_c0, *plStack_c0 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
  }
  if ((plStack_a8 != (longlong *)0x0) &&
     (lVar7 = *plStack_a8, *plStack_a8 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_a8[1] + 0x30))(plStack_a8);
  }
  if ((plStack_b8 != (longlong *)0x0) &&
     (lVar7 = *plStack_b8, *plStack_b8 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_b8[1] + 0x30))(plStack_b8);
  }
  lVar7 = *param_3;
  *param_3 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    (**(code **)(param_3[1] + 0x30))(param_3);
  }
  FUN_23a33aa70(param_1,uStack_80,uStack_78,plVar15);
  return (code *)0x0;
}
