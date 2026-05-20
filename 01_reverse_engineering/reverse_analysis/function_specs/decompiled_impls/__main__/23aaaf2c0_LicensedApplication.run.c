/* ===== 23aaaf2c0 __main__:328 ===== */
/* ghidra_name=FUN_23aaaf2c0 entry=23aaaf2c0 size=8427 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23aaaf2c0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  code *pcVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  code *pcVar6;
  longlong **pplVar7;
  char cVar8;
  int iVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  undefined8 uVar13;
  longlong lVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong *plVar18;
  code *pcVar19;
  longlong *plVar20;
  int iVar21;
  longlong **pplVar22;
  code *pcVar23;
  undefined4 uVar24;
  code *pcStack_c8;
  code *pcStack_c0;
  longlong **pplStack_b8;
  longlong **pplStack_a8;
  longlong **pplStack_a0;
  undefined1 auStack_98 [16];
  code *apcStack_88 [2];
  longlong *plStack_78;
  longlong **pplStack_70;
  code *pcStack_68;
  
  plVar10 = _DAT_23ed90c38;
  plVar3 = (longlong *)*param_3;
  if (_DAT_23ed90c38 == (longlong *)0x0) {
LAB_23aaaf305:
    _DAT_23ed90c38 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23ed90c30,DAT_23ed90d18,0x20);
  }
  else {
    lVar14 = *_DAT_23ed90c38;
    if (1 < lVar14) {
      *_DAT_23ed90c38 = lVar14 + -1;
      goto LAB_23aaaf305;
    }
    if (_DAT_23ed90c38[2] != 0) {
      *_DAT_23ed90c38 = lVar14 + -1;
      if (lVar14 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23aaaf305;
    }
  }
  plVar4 = _DAT_23ed90c38;
  lVar14 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23ed90c38 + 9;
  lVar11 = *(longlong *)(lVar14 + 8);
  _DAT_23ed90c38[0xf] = lVar11;
  *(longlong **)(lVar14 + 8) = plVar10;
  if ((lVar11 != 0) &&
     (((*(char *)(lVar11 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar11 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar11 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar11 + 0x38))) && (plVar4[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar11 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar13 = _DAT_23ed8ffd8;
  *(undefined4 *)(plVar4 + 8) = 0;
  *(undefined4 *)(plVar4 + 5) = 0x151;
  plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar3,uVar13);
  pcStack_c8 = _PyRuntime_exref;
  if (plVar10 != (longlong *)0x0) {
    iVar9 = FUN_23a35f020(plVar10);
    *plVar10 = *plVar10 + -1;
    pcStack_c8 = _PyRuntime_exref;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
      pcStack_c8 = _PyRuntime_exref;
    }
    _PyRuntime_exref = pcStack_c8;
    if (iVar9 == -1) {
      plVar10 = *(longlong **)(param_1 + 0x60);
      pplVar22 = *(longlong ***)(param_1 + 0x68);
      pcVar23 = *(code **)(param_1 + 0x70);
      plVar12 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar24 = 0x151;
      *(undefined8 *)(param_1 + 0x70) = 0;
      goto LAB_23aaaf763;
    }
    if (iVar9 == 0) {
      lVar11 = FUN_23ebc0cf0();
      lVar14 = _DAT_23ed8ffe0;
      if (lVar11 == 0) {
        uVar24 = 0x152;
        FUN_23e915740(param_1,&plStack_78,DAT_23ed8fba8);
        pcStack_c8 = _PyRuntime_exref;
        plVar12 = (longlong *)0x0;
        pcVar23 = pcStack_68;
        plVar10 = plStack_78;
        pplVar22 = pplStack_70;
        goto LAB_23aaaf763;
      }
      *(undefined4 *)(plVar4 + 5) = 0x152;
      plVar10 = (longlong *)
                FUN_23e915840(param_1,lVar11,DAT_23ed8fbb0,*(undefined8 *)(lVar14 + 0x18));
      if (plVar10 == (longlong *)0x0) {
        pcStack_c8 = _PyRuntime_exref;
        plVar10 = *(longlong **)(param_1 + 0x60);
        uVar24 = 0x152;
        pcVar23 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar12 = (longlong *)0x0;
        pplVar22 = *(longlong ***)(param_1 + 0x68);
        goto LAB_23aaaf763;
      }
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      plVar18 = DAT_23ed6ccf0;
      plVar10 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
LAB_23aaaf437:
      lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar4 = *(longlong **)(lVar14 + 0x28);
      plVar20 = (longlong *)plVar4[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar14 + 0x30);
      *(undefined4 *)(plVar4 + 8) = 0xffffffff;
      if (plVar20 != (longlong *)0x0) {
        plVar4[2] = 0;
        *plVar20 = *plVar20 + -1;
        if (*plVar20 == 0) {
          (**(code **)(plVar20[1] + 0x30))();
        }
      }
      *plVar4 = *plVar4 + -1;
      if (*plVar4 == 0) {
        (**(code **)(plVar4[1] + 0x30))(plVar4);
      }
      plVar4[0xf] = 0;
      if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
LAB_23aaaf4b2:
      *plVar3 = *plVar3 + -1;
      if (*plVar3 != 0) {
        return plVar18;
      }
      (**(code **)(plVar3[1] + 0x30))(plVar3);
      return plVar18;
    }
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar3,DAT_23ed8fd58);
    pcStack_c8 = _PyRuntime_exref;
    if (plVar10 == (longlong *)0x0) {
      plVar10 = *(longlong **)(param_1 + 0x60);
      pplVar22 = *(longlong ***)(param_1 + 0x68);
      uVar24 = 0x156;
      pcVar23 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar12 = (longlong *)0x0;
      goto LAB_23aaaf763;
    }
    plVar18 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23ed8fed0);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar18 == (longlong *)0x0) {
LAB_23aab0738:
      pcStack_c8 = _PyRuntime_exref;
      plVar10 = *(longlong **)(param_1 + 0x60);
      pplVar22 = *(longlong ***)(param_1 + 0x68);
      pcVar23 = *(code **)(param_1 + 0x70);
      plVar12 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar24 = 0x156;
      *(undefined8 *)(param_1 + 0x70) = 0;
      goto LAB_23aaaf763;
    }
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar3,_DAT_23ed8fed8);
    if (plVar10 == (longlong *)0x0) {
      plVar10 = *(longlong **)(param_1 + 0x60);
      pplVar22 = *(longlong ***)(param_1 + 0x68);
      pcVar23 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar18 = *plVar18 + -1;
      plVar12 = (longlong *)0x0;
      if (*plVar18 == 0) {
        uVar24 = 0x156;
        (**(code **)(plVar18[1] + 0x30))(plVar18);
        pcStack_c8 = _PyRuntime_exref;
      }
      else {
        uVar24 = 0x156;
        pcStack_c8 = _PyRuntime_exref;
      }
      goto LAB_23aaaf763;
    }
    *(undefined4 *)(plVar4 + 5) = 0x156;
    plVar12 = (longlong *)FUN_23e914090(param_1,plVar18,plVar10);
    *plVar18 = *plVar18 + -1;
    if (*plVar18 == 0) {
      (**(code **)(plVar18[1] + 0x30))(plVar18);
    }
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar12 == (longlong *)0x0) goto LAB_23aab0738;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    lVar14 = *(longlong *)(DAT_23ed8fb58 + 0x20);
    if (*(char *)(lVar14 + 10) == '\0') {
      plVar10 = (longlong *)FUN_23a37a020(DAT_23ed8fb58,_DAT_23ed8ffe8);
      if (plVar10 == (longlong *)0x0) goto LAB_23aab0b40;
      lVar11 = *plVar10;
LAB_23aab0b2c:
      if (lVar11 == 0) goto LAB_23aab0b40;
    }
    else {
      iVar9 = *(int *)(lVar14 + 0xc);
      if (*(int *)(lVar14 + 0xc) == 0) {
        *(int *)(lVar14 + 0xc) = DAT_23ec107d0;
        iVar9 = DAT_23ec107d0;
        DAT_23ec107d0 = DAT_23ec107d0 + 1;
      }
      if (_DAT_23ec107a8 != iVar9) {
        _DAT_23ec107a8 = iVar9;
        _DAT_23ed90c28 = FUN_23e8cbd60(lVar14,_DAT_23ed8ffe8,*(undefined8 *)(_DAT_23ed8ffe8 + 0x18))
        ;
      }
      if (-1 < _DAT_23ed90c28) {
        lVar2 = lVar14 + 0x20 + (1L << (*(byte *)(lVar14 + 9) & 0x3f));
        lVar11 = *(longlong *)(lVar2 + 8 + _DAT_23ed90c28 * 0x10);
        if (lVar11 != 0) goto LAB_23aaaf675;
        _DAT_23ed90c28 = FUN_23e8cbd60(lVar14,_DAT_23ed8ffe8,*(undefined8 *)(_DAT_23ed8ffe8 + 0x18))
        ;
        if (-1 < _DAT_23ed90c28) {
          lVar11 = *(longlong *)(lVar2 + 8 + _DAT_23ed90c28 * 0x10);
          goto LAB_23aab0b2c;
        }
      }
LAB_23aab0b40:
      plVar10 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23ed8ffe8);
      if ((plVar10 == (longlong *)0x0) || (lVar11 = *plVar10, lVar11 == 0)) {
        plVar12 = (longlong *)0x0;
        uVar24 = 0x159;
        FUN_23e915740(param_1,&plStack_78,_DAT_23ed8ffe8);
        pcStack_c8 = _PyRuntime_exref;
        pcVar23 = pcStack_68;
        plVar10 = plStack_78;
        pplVar22 = pplStack_70;
        goto LAB_23aaaf763;
      }
    }
LAB_23aaaf675:
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar3,DAT_23ed8fd58);
    pcStack_c8 = _PyRuntime_exref;
    if (plVar10 == (longlong *)0x0) {
      plVar10 = *(longlong **)(param_1 + 0x60);
      uVar24 = 0x159;
      pcVar23 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar12 = (longlong *)0x0;
      pplVar22 = *(longlong ***)(param_1 + 0x68);
      goto LAB_23aaaf763;
    }
    *(undefined4 *)(plVar4 + 5) = 0x159;
    pplVar22 = &plStack_78;
    plStack_78 = plVar10;
    plVar12 = (longlong *)FUN_23e9186b0(param_1,lVar11,pplVar22,_DAT_23ed8fff0);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    pcStack_c8 = _PyRuntime_exref;
    if (plVar12 == (longlong *)0x0) {
      plVar10 = *(longlong **)(param_1 + 0x60);
      pcVar23 = *(code **)(param_1 + 0x70);
      plVar12 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar24 = 0x159;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pplVar22 = *(longlong ***)(param_1 + 0x68);
      goto LAB_23aaaf763;
    }
    cVar8 = FUN_23e8d9ac0(plVar3,DAT_23ed8fd88,plVar12);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    pcStack_c8 = _PyRuntime_exref;
    if (cVar8 == '\0') {
      plVar10 = *(longlong **)(param_1 + 0x60);
      pcVar23 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar24 = 0x159;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar12 = (longlong *)0x0;
      pplVar22 = *(longlong ***)(param_1 + 0x68);
      goto LAB_23aaaf763;
    }
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar3,DAT_23ed8fd88);
    pcStack_c8 = _PyRuntime_exref;
    if (plVar10 == (longlong *)0x0) {
      plVar10 = *(longlong **)(param_1 + 0x60);
      uVar24 = 0x15a;
      pcVar23 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar12 = (longlong *)0x0;
      pplVar22 = *(longlong ***)(param_1 + 0x68);
      goto LAB_23aaaf763;
    }
    *(undefined4 *)(plVar4 + 5) = 0x15a;
    plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar10,_DAT_23ed8fec8);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    pcStack_c8 = _PyRuntime_exref;
    if (plVar12 == (longlong *)0x0) {
      plVar10 = *(longlong **)(param_1 + 0x60);
      pcVar23 = *(code **)(param_1 + 0x70);
      plVar12 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar24 = 0x15a;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pplVar22 = *(longlong ***)(param_1 + 0x68);
      goto LAB_23aaaf763;
    }
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    lVar11 = FUN_23ebc0cf0();
    lVar14 = _DAT_23ed8fff8;
    if (lVar11 == 0) {
      uVar24 = 0x15c;
      FUN_23e915740(param_1,pplVar22,DAT_23ed8fba8);
      pcStack_c8 = _PyRuntime_exref;
      plVar12 = (longlong *)0x0;
      pcVar23 = pcStack_68;
      plVar10 = plStack_78;
      pplVar22 = pplStack_70;
      goto LAB_23aaaf763;
    }
    *(undefined4 *)(plVar4 + 5) = 0x15c;
    plVar10 = (longlong *)FUN_23e915840(param_1,lVar11,DAT_23ed8fbb0,*(undefined8 *)(lVar14 + 0x18))
    ;
    pcStack_c8 = _PyRuntime_exref;
    if (plVar10 == (longlong *)0x0) {
      plVar10 = *(longlong **)(param_1 + 0x60);
      uVar24 = 0x15c;
      pcVar23 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar12 = (longlong *)0x0;
      pplVar22 = *(longlong ***)(param_1 + 0x68);
      goto LAB_23aaaf763;
    }
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar3,_DAT_23ed8fc98);
    pcStack_c8 = _PyRuntime_exref;
    if (plVar10 == (longlong *)0x0) {
      plVar10 = *(longlong **)(param_1 + 0x60);
      pcVar23 = *(code **)(param_1 + 0x70);
      plVar12 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar24 = 0x15f;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pplVar22 = *(longlong ***)(param_1 + 0x68);
      goto LAB_23aaaf763;
    }
    *(undefined4 *)(plVar4 + 5) = 0x15f;
    plVar18 = (longlong *)FUN_23e91bfe0(param_1,plVar10,DAT_23ed8fe28);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    pcStack_c8 = _PyRuntime_exref;
    plVar12 = plVar18;
    if (plVar18 == (longlong *)0x0) {
      plVar10 = *(longlong **)(param_1 + 0x60);
      uVar24 = 0x15f;
      pcVar23 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pplVar22 = *(longlong ***)(param_1 + 0x68);
      goto LAB_23aaaf763;
    }
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar3,DAT_23ed8fd58);
    if (plVar10 == (longlong *)0x0) {
LAB_23aab12f5:
      pcStack_c8 = _PyRuntime_exref;
      plVar10 = *(longlong **)(param_1 + 0x60);
      uVar24 = 0x162;
      pcVar23 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pplVar22 = *(longlong ***)(param_1 + 0x68);
      goto LAB_23aaaf763;
    }
    *(undefined4 *)(plVar4 + 5) = 0x162;
    plVar20 = (longlong *)FUN_23e91bfe0(param_1,plVar10,_DAT_23ed90000);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar20 == (longlong *)0x0) goto LAB_23aab12f5;
    *plVar20 = *plVar20 + -1;
    if (*plVar20 == 0) {
      FUN_23a334bc0(plVar20);
    }
    lVar14 = FUN_23ebc0cf0();
    if (lVar14 == 0) {
      uVar24 = 0x164;
      FUN_23e915740(param_1,pplVar22,DAT_23ed8fba8);
      pcStack_c8 = _PyRuntime_exref;
      pcVar23 = pcStack_68;
      plVar10 = plStack_78;
      pplVar22 = pplStack_70;
      goto LAB_23aaaf763;
    }
    plVar20 = (longlong *)FUN_23e8bc2f0(lVar14,DAT_23ed8fbb0);
    pcStack_c8 = _PyRuntime_exref;
    plVar10 = _DAT_23ed90008;
    if (plVar20 == (longlong *)0x0) {
      plVar10 = *(longlong **)(param_1 + 0x60);
      pcVar23 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar24 = 0x164;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pplVar22 = *(longlong ***)(param_1 + 0x68);
      goto LAB_23aaaf763;
    }
    lVar14 = *(longlong *)(param_1 + 0x10);
    plVar15 = *(longlong **)(lVar14 + 0xe20);
    if (plVar15 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar11 = plVar15[3];
      *(int *)(lVar14 + 0xebc) = *(int *)(lVar14 + 0xebc) + -1;
      *(longlong *)(lVar14 + 0xe20) = lVar11;
      *plVar15 = 1;
    }
    pcStack_c8 = _PyRuntime_exref;
    plVar15[4] = 0;
    lVar14 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_c8 + 0x1f8) + 0x10) + 0x2e8);
    lVar11 = plVar15[-1];
    puVar5 = *(undefined8 **)(lVar14 + 8);
    *puVar5 = plVar15 + -2;
    plVar15[-2] = lVar14;
    plVar15[-1] = (ulonglong)((uint)lVar11 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar14 + 8) = plVar15 + -2;
    plVar16 = DAT_23ed6a4c0;
    *plVar10 = *plVar10 + 1;
    plVar15[3] = (longlong)plVar10;
    pplVar7 = DAT_23ed6cd28;
    if (plVar16 != (longlong *)0x0) {
LAB_23aab0f5c:
      pplStack_70 = pplVar7;
      plStack_78 = plVar18;
      lVar14 = FUN_23e94ed00(param_1,plVar16,pplVar22);
      if (lVar14 == 0) {
        plVar10 = *(longlong **)(param_1 + 0x60);
        pplVar22 = *(longlong ***)(param_1 + 0x68);
        pcVar23 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar20 = *plVar20 + -1;
        if (*plVar20 == 0) {
          FUN_23a334bc0(plVar20);
        }
        *plVar15 = *plVar15 + -1;
        uVar24 = 0x164;
        if (*plVar15 == 0) {
          FUN_23a334bc0(plVar15);
        }
      }
      else {
        plVar15[4] = lVar14;
        plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar15);
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) {
          FUN_23a334bc0(plVar15);
        }
        if (plVar10 == (longlong *)0x0) {
          plVar10 = *(longlong **)(param_1 + 0x60);
          pplVar22 = *(longlong ***)(param_1 + 0x68);
          pcVar23 = *(code **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uVar24 = 0x164;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *plVar20 = *plVar20 + -1;
          if (*plVar20 == 0) {
            FUN_23a334bc0(plVar20);
          }
        }
        else {
          *(undefined4 *)(plVar4 + 5) = 0x164;
          plVar15 = (longlong *)FUN_23e914090(param_1,plVar20);
          *plVar20 = *plVar20 + -1;
          if (*plVar20 == 0) {
            FUN_23a334bc0(plVar20);
          }
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            FUN_23a334bc0(plVar10);
          }
          if (plVar15 != (longlong *)0x0) {
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              FUN_23a334bc0(plVar15);
            }
            FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
            if (*plVar18 == 0) {
              (**(code **)(plVar18[1] + 0x30))(plVar18);
            }
            goto LAB_23aaaf4b2;
          }
          plVar10 = *(longlong **)(param_1 + 0x60);
          pcVar23 = *(code **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uVar24 = 0x164;
          *(undefined8 *)(param_1 + 0x70) = 0;
          pplVar22 = *(longlong ***)(param_1 + 0x68);
        }
      }
      goto LAB_23aaaf763;
    }
    plVar16 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
    if (plVar16 != (longlong *)0x0) {
      *plVar16 = *plVar16 + 1;
      DAT_23ed6a4c0 = plVar16;
      goto LAB_23aab0f5c;
    }
LAB_23aab10e7:
    plVar10 = (longlong *)&DAT_23ed6a4c0;
    PyErr_PrintEx(0,0);
    Py_Exit(1);
LAB_23aab10fa:
    pcStack_c0 = *(code **)(param_1 + 0x60);
    pcVar23 = *(code **)(param_1 + 0x70);
    iVar9 = 0x16d;
    *(undefined8 *)(param_1 + 0x70) = 0;
    pplStack_b8 = *(longlong ***)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar12 = plVar18;
    goto LAB_23aab02f0;
  }
  pcVar23 = *(code **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  plVar10 = *(longlong **)(param_1 + 0x60);
  pplVar22 = *(longlong ***)(param_1 + 0x68);
  uVar24 = 0x151;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar12 = (longlong *)0x0;
LAB_23aaaf763:
  plVar20 = *(longlong **)(param_1 + 0x138);
  auStack_98._8_8_ = pplVar22;
  auStack_98._0_8_ = plVar10;
  if (plVar20 != (longlong *)0x0) {
    *plVar20 = *plVar20 + 1;
  }
  pcVar19 = DAT_23ed6a4f8;
  apcStack_88[0] = pcVar23;
  if (pcVar23 == (code *)0x0) {
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar23 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar23;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong *)(pcVar19 + 0x10) = 0;
    *(longlong **)(pcVar19 + 0x18) = plVar4;
    *plVar4 = *plVar4 + 1;
    lVar14 = *(longlong *)(pcStack_c8 + 0x1f8);
    *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
    lVar14 = *(longlong *)(lVar14 + 0x10);
    *(undefined4 *)(pcVar19 + 0x24) = uVar24;
    lVar14 = *(longlong *)(lVar14 + 0x2e8);
    lVar11 = *(longlong *)(pcVar19 + -8);
    puVar5 = *(undefined8 **)(lVar14 + 8);
    *puVar5 = pcVar19 + -0x10;
    *(longlong *)(pcVar19 + -0x10) = lVar14;
    *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar11 & 3) | (ulonglong)puVar5;
    *(code **)(lVar14 + 8) = pcVar19 + -0x10;
    if ((apcStack_88[0] != (code *)0x0) &&
       (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
       *(longlong *)apcStack_88[0] == 0)) {
      (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))(apcStack_88[0]);
    }
  }
  else {
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar6 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar6;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar19 + 0x18) = plVar4;
    *plVar4 = *plVar4 + 1;
    lVar14 = *(longlong *)(pcStack_c8 + 0x1f8);
    *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
    *(undefined4 *)(pcVar19 + 0x24) = uVar24;
    lVar14 = *(longlong *)(*(longlong *)(lVar14 + 0x10) + 0x2e8);
    lVar11 = *(longlong *)(pcVar19 + -8);
    puVar5 = *(undefined8 **)(lVar14 + 8);
    *puVar5 = pcVar19 + -0x10;
    *(longlong *)(pcVar19 + -0x10) = lVar14;
    *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar11 & 3) | (ulonglong)puVar5;
    *(code **)(lVar14 + 8) = pcVar19 + -0x10;
    *(code **)(pcVar19 + 0x10) = pcVar23;
    *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
    if ((apcStack_88[0] != (code *)0x0) &&
       (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
       *(longlong *)apcStack_88[0] == 0)) {
      (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
    }
  }
  pcVar23 = _Py_NoneStruct_exref;
  apcStack_88[0] = pcVar19;
  if (((code *)auStack_98._0_8_ != _Py_NoneStruct_exref) &&
     ((code *)auStack_98._0_8_ != (code *)0x0)) {
    FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
  }
  plVar10 = *(longlong **)(auStack_98._8_8_ + 0x28);
  if (apcStack_88[0] == pcVar23) {
    pcVar19 = (code *)0x0;
  }
  else {
    pcVar19 = apcStack_88[0];
    if (apcStack_88[0] != (code *)0x0) {
      *(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + 1;
    }
  }
  *(code **)(auStack_98._8_8_ + 0x28) = pcVar19;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))();
  }
  plVar10 = *(longlong **)(param_1 + 0x138);
  *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))();
  }
  *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + -1;
  if (*(longlong *)auStack_98._0_8_ == 0) {
    (**(code **)(*(longlong *)(auStack_98._0_8_ + 8) + 0x30))();
  }
  if ((apcStack_88[0] != (code *)0x0) &&
     (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
     *(longlong *)apcStack_88[0] == 0)) {
    (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
  }
  pplVar22 = *(longlong ***)(param_1 + 0x138);
  apcStack_88[0] = (code *)0x0;
  auStack_98 = (undefined1  [16])0x0;
  pcVar19 = (code *)pplVar22[1];
  pcVar6 = *(code **)PyExc_Exception_exref;
  if ((*(uint *)(*(longlong *)(pcVar6 + 8) + 0xa8) & 0x4000000) == 0) {
    if (((int)*(uint *)(*(longlong *)(pcVar6 + 8) + 0xa8) < 0) && (((byte)pcVar6[0xab] & 0x40) != 0)
       ) {
      pcStack_c0 = *(code **)(pcVar19 + 8);
      pcVar1 = pcStack_c0 + 0xa8;
      if ((*(uint *)pcVar1 & 0x40000000) == 0) {
        pcStack_c0 = pcVar19;
        if ((-1 < (int)*(uint *)pcVar1) || (((byte)pcVar19[0xab] & 0x40) == 0)) goto LAB_23aab08c1;
      }
      else {
        pcVar19 = pcStack_c0;
        if (-1 < *(int *)(*(longlong *)(pcStack_c0 + 8) + 0xa8)) {
LAB_23aab08c1:
          if (pcVar6 != pcStack_c0) goto LAB_23aaaf99a;
          goto LAB_23aaafb04;
        }
      }
      lVar14 = *(longlong *)(pcVar19 + 0x158);
      if (lVar14 == 0) {
        do {
          if (pcVar6 == pcVar19) goto LAB_23aaafb04;
          pcVar19 = *(code **)(pcVar19 + 0x100);
        } while (pcVar19 != (code *)0x0);
        if (pcVar6 == PyBaseObject_Type_exref) goto LAB_23aaafb04;
      }
      else if (0 < *(longlong *)(lVar14 + 0x10)) {
        lVar11 = 0;
        do {
          if (pcVar6 == *(code **)(lVar14 + 0x18 + lVar11 * 8)) goto LAB_23aaafb04;
          lVar11 = lVar11 + 1;
        } while (*(longlong *)(lVar14 + 0x10) != lVar11);
      }
      goto LAB_23aaaf99a;
    }
    plVar10 = *(longlong **)PyExc_TypeError_exref;
    uVar13 = PyUnicode_FromString
                       ("catching classes that do not inherit from BaseException is not allowed");
    plVar18 = *(longlong **)(param_1 + 0x60);
    plVar15 = *(longlong **)(param_1 + 0x68);
    plVar16 = *(longlong **)(param_1 + 0x70);
    *(longlong **)(param_1 + 0x60) = plVar10;
    *plVar10 = *plVar10 + 1;
    *(undefined8 *)(param_1 + 0x68) = uVar13;
    *(undefined8 *)(param_1 + 0x70) = 0;
    if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
      (**(code **)(plVar18[1] + 0x30))();
    }
    if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    if ((plVar16 == (longlong *)0x0) || (*plVar16 = *plVar16 + -1, *plVar16 != 0)) {
LAB_23aaafafd:
      pplVar22 = *(longlong ***)(param_1 + 0x138);
    }
    else {
      (**(code **)(plVar16[1] + 0x30))(plVar16);
      pplVar22 = *(longlong ***)(param_1 + 0x138);
    }
LAB_23aaafb04:
    *pplVar22 = (longlong *)((longlong)*pplVar22 + 1);
    lVar14 = FUN_23ebc0cf0();
    if (lVar14 == 0) {
      FUN_23e915740(param_1,&plStack_78,DAT_23ed8fba8);
      iVar9 = 0x168;
      pcStack_c0 = (code *)plStack_78;
      pplStack_b8 = pplStack_70;
      plVar10 = (longlong *)0x0;
      pcVar23 = pcStack_68;
    }
    else {
      plVar15 = (longlong *)FUN_23e8bc2f0(lVar14,_DAT_23ed90010);
      plVar10 = _DAT_23ed90018;
      if (plVar15 == (longlong *)0x0) {
LAB_23aab0618:
        pcStack_c0 = *(code **)(param_1 + 0x60);
        pcVar23 = *(code **)(param_1 + 0x70);
        plVar10 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        iVar9 = 0x168;
        pplStack_b8 = *(longlong ***)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        lVar14 = *(longlong *)(param_1 + 0x10);
        plVar16 = *(longlong **)(lVar14 + 0xe20);
        if (plVar16 == (longlong *)0x0) {
          plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
        }
        else {
          lVar11 = plVar16[3];
          *(int *)(lVar14 + 0xebc) = *(int *)(lVar14 + 0xebc) + -1;
          *(longlong *)(lVar14 + 0xe20) = lVar11;
          *plVar16 = 1;
        }
        plVar16[4] = 0;
        lVar14 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_c8 + 0x1f8) + 0x10) + 0x2e8);
        lVar11 = plVar16[-1];
        puVar5 = *(undefined8 **)(lVar14 + 8);
        *puVar5 = plVar16 + -2;
        plVar16[-2] = lVar14;
        plVar16[-1] = (ulonglong)((uint)lVar11 & 3) | (ulonglong)puVar5;
        *(longlong **)(lVar14 + 8) = plVar16 + -2;
        plVar17 = DAT_23ed6a4c0;
        *plVar10 = *plVar10 + 1;
        plVar16[3] = (longlong)plVar10;
        pplVar7 = DAT_23ed6cd28;
        plVar18 = plVar12;
        if (plVar17 == (longlong *)0x0) {
          plVar17 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar17 == (longlong *)0x0) goto LAB_23aab10e7;
          *plVar17 = *plVar17 + 1;
          DAT_23ed6a4c0 = plVar17;
        }
        pplStack_a0 = pplVar7;
        pplStack_a8 = pplVar22;
        lVar14 = FUN_23e94ed00(param_1,plVar17,&pplStack_a8);
        if (lVar14 == 0) {
          pcStack_c0 = *(code **)(param_1 + 0x60);
          pcVar23 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          pplStack_b8 = *(longlong ***)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          iVar9 = 0x168;
          iVar21 = 0x168;
          lVar14 = *plVar16 + -1;
          *plVar16 = lVar14;
          plVar10 = (longlong *)0x0;
joined_r0x00023aab02da:
          if (lVar14 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
            iVar9 = iVar21;
          }
        }
        else {
          plVar16[4] = lVar14;
          plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          if (plVar10 == (longlong *)0x0) {
            pcStack_c0 = *(code **)(param_1 + 0x60);
            pcVar23 = *(code **)(param_1 + 0x70);
            iVar9 = 0x168;
            *(undefined8 *)(param_1 + 0x70) = 0;
            pplStack_b8 = *(longlong ***)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            lVar14 = *plVar15;
            *plVar15 = lVar14 + -1;
            plVar10 = (longlong *)0x0;
            if (lVar14 + -1 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
              iVar9 = 0x168;
            }
          }
          else {
            *(undefined4 *)(plVar4 + 5) = 0x168;
            plVar16 = (longlong *)FUN_23e914090(param_1,plVar15,plVar10);
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            if (plVar16 == (longlong *)0x0) goto LAB_23aab0618;
            *plVar16 = *plVar16 + -1;
            if (*plVar16 == 0) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
            lVar14 = FUN_23ebc0ba0();
            if (lVar14 == 0) {
              FUN_23e915740(param_1,&plStack_78,DAT_23ed8fdc0);
              iVar9 = 0x16b;
              pcStack_c0 = (code *)plStack_78;
              pplStack_b8 = pplStack_70;
              plVar10 = (longlong *)0x0;
              pcVar23 = pcStack_68;
            }
            else {
              *(undefined4 *)(plVar4 + 5) = 0x16b;
              plVar10 = (longlong *)FUN_23e91a870(param_1,lVar14);
              if (plVar10 == (longlong *)0x0) {
                pcStack_c0 = *(code **)(param_1 + 0x60);
                pcVar23 = *(code **)(param_1 + 0x70);
                iVar9 = 0x16b;
                *(undefined8 *)(param_1 + 0x70) = 0;
                pplStack_b8 = *(longlong ***)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              else {
                plVar15 = (longlong *)FUN_23e8bc2f0(plVar10,DAT_23ed8fdc8);
                if (plVar15 == (longlong *)0x0) {
LAB_23aab0ae8:
                  pcStack_c0 = *(code **)(param_1 + 0x60);
                  pcVar23 = *(code **)(param_1 + 0x70);
                  iVar9 = 0x16c;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pplStack_b8 = *(longlong ***)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                }
                else {
                  lVar14 = FUN_23ebc0ba0();
                  if (lVar14 == 0) {
                    FUN_23e915740(param_1,&plStack_78,DAT_23ed8fdc0);
                    pcStack_c0 = (code *)plStack_78;
                    pplStack_b8 = pplStack_70;
LAB_23aab0a66:
                    iVar9 = 0x16c;
                    iVar21 = 0x16c;
                    lVar14 = *plVar15 + -1;
                    *plVar15 = lVar14;
                    pcVar23 = pcStack_68;
                  }
                  else {
                    plVar16 = (longlong *)FUN_23e8bc2f0(lVar14,DAT_23ed8fdd0);
                    if (plVar16 == (longlong *)0x0) {
LAB_23aab0a40:
                      pcStack_c0 = *(code **)(param_1 + 0x60);
                      pcStack_68 = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      pplStack_b8 = *(longlong ***)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23aab0a66;
                    }
                    plVar17 = (longlong *)FUN_23e8bc2f0(plVar16,_DAT_23ed90020);
                    *plVar16 = *plVar16 + -1;
                    if (*plVar16 == 0) {
                      (**(code **)(plVar16[1] + 0x30))();
                    }
                    if (plVar17 == (longlong *)0x0) goto LAB_23aab0a40;
                    *(undefined4 *)(plVar4 + 5) = 0x16c;
                    plVar16 = (longlong *)FUN_23e914090(param_1,plVar15);
                    lVar14 = *plVar15;
                    *plVar15 = lVar14 + -1;
                    if (lVar14 + -1 == 0) {
                      (**(code **)(plVar15[1] + 0x30))();
                    }
                    *plVar17 = *plVar17 + -1;
                    if (*plVar17 == 0) {
                      (**(code **)(plVar17[1] + 0x30))(plVar17);
                    }
                    if (plVar16 == (longlong *)0x0) goto LAB_23aab0ae8;
                    *plVar16 = *plVar16 + -1;
                    if (*plVar16 == 0) {
                      (**(code **)(plVar16[1] + 0x30))(plVar16);
                    }
                    lVar14 = _DAT_23ed90028;
                    *(undefined4 *)(plVar4 + 5) = 0x16d;
                    plVar15 = (longlong *)
                              FUN_23e915840(param_1,plVar10,DAT_23ed8fde0,
                                            *(undefined8 *)(lVar14 + 0x18));
                    if (plVar15 == (longlong *)0x0) goto LAB_23aab10fa;
                    *plVar15 = *plVar15 + -1;
                    if (*plVar15 == 0) {
                      (**(code **)(plVar15[1] + 0x30))(plVar15);
                    }
                    lVar14 = _DAT_23ed90030;
                    *(undefined4 *)(plVar4 + 5) = 0x16e;
                    plVar18 = (longlong *)
                              FUN_23e915840(param_1,plVar10,DAT_23ed8fdf0,
                                            *(undefined8 *)(lVar14 + 0x18));
                    if (plVar18 == (longlong *)0x0) {
                      pcStack_c0 = *(code **)(param_1 + 0x60);
                      pcVar23 = *(code **)(param_1 + 0x70);
                      iVar9 = 0x16e;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      pplStack_b8 = *(longlong ***)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23aab02f0;
                    }
                    *plVar18 = *plVar18 + -1;
                    if (*plVar18 == 0) {
                      (**(code **)(plVar18[1] + 0x30))(plVar18);
                    }
                    plVar16 = (longlong *)FUN_23e8bc2f0(plVar10,DAT_23ed8fe00);
                    if (plVar16 == (longlong *)0x0) {
LAB_23aab0cb1:
                      pcStack_c0 = *(code **)(param_1 + 0x60);
                      pcVar23 = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      pplStack_b8 = *(longlong ***)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      iVar9 = 0x16f;
                      goto LAB_23aab02f0;
                    }
                    plVar18 = (longlong *)FUN_23e8bd350(pplVar22);
                    if (plVar18 == (longlong *)0x0) {
                      pcStack_c0 = *(code **)(param_1 + 0x60);
                      pcVar23 = *(code **)(param_1 + 0x70);
                      iVar9 = 0x16f;
                      iVar21 = 0x16f;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      pplStack_b8 = *(longlong ***)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      lVar14 = *plVar16 + -1;
                      *plVar16 = lVar14;
                      goto joined_r0x00023aab02da;
                    }
                    *(undefined4 *)(plVar4 + 5) = 0x16f;
                    plVar15 = (longlong *)FUN_23e914090(param_1,plVar16,plVar18);
                    *plVar16 = *plVar16 + -1;
                    if (*plVar16 == 0) {
                      (**(code **)(plVar16[1] + 0x30))(plVar16);
                    }
                    *plVar18 = *plVar18 + -1;
                    if (*plVar18 == 0) {
                      (**(code **)(plVar18[1] + 0x30))(plVar18);
                    }
                    if (plVar15 == (longlong *)0x0) goto LAB_23aab0cb1;
                    *plVar15 = *plVar15 + -1;
                    if (*plVar15 == 0) {
                      (**(code **)(plVar15[1] + 0x30))(plVar15);
                    }
                    plVar15 = (longlong *)FUN_23e8bc2f0(plVar10,DAT_23ed8fe10);
                    if (plVar15 == (longlong *)0x0) {
LAB_23aab09c0:
                      pcStack_c0 = *(code **)(param_1 + 0x60);
                      pcVar23 = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      pplStack_b8 = *(longlong ***)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      iVar9 = 0x170;
                      goto LAB_23aab02f0;
                    }
                    lVar14 = FUN_23ebc0ba0();
                    if (lVar14 == 0) {
                      FUN_23e915740(param_1,&plStack_78,DAT_23ed8fdc0);
                      pcStack_c0 = (code *)plStack_78;
                      pplStack_b8 = pplStack_70;
                    }
                    else {
                      plVar18 = (longlong *)FUN_23e8bc2f0(lVar14,DAT_23ed8fe18);
                      if (plVar18 != (longlong *)0x0) {
                        plVar16 = (longlong *)FUN_23e8bc2f0(plVar18,DAT_23ed8fe20);
                        *plVar18 = *plVar18 + -1;
                        if (*plVar18 == 0) {
                          (**(code **)(plVar18[1] + 0x30))();
                        }
                        if (plVar16 != (longlong *)0x0) {
                          *(undefined4 *)(plVar4 + 5) = 0x170;
                          plVar18 = (longlong *)FUN_23e914090(param_1,plVar15);
                          lVar14 = *plVar15;
                          *plVar15 = lVar14 + -1;
                          if (lVar14 + -1 == 0) {
                            (**(code **)(plVar15[1] + 0x30))();
                          }
                          *plVar16 = *plVar16 + -1;
                          if (*plVar16 == 0) {
                            (**(code **)(plVar16[1] + 0x30))(plVar16);
                          }
                          if (plVar18 != (longlong *)0x0) {
                            *plVar18 = *plVar18 + -1;
                            if (*plVar18 == 0) {
                              (**(code **)(plVar18[1] + 0x30))(plVar18);
                            }
                            *(undefined4 *)(plVar4 + 5) = 0x171;
                            plVar18 = (longlong *)FUN_23e91bfe0(param_1,plVar10,DAT_23ed8fe28);
                            if (plVar18 != (longlong *)0x0) {
                              *plVar18 = *plVar18 + -1;
                              if (*plVar18 == 0) {
                                (**(code **)(plVar18[1] + 0x30))(plVar18);
                              }
                              plVar18 = DAT_23ed6ccf8;
                              *DAT_23ed6ccf8 = *DAT_23ed6ccf8 + 1;
                              *pplVar22 = (longlong *)((longlong)*pplVar22 + -1);
                              if (*pplVar22 == (longlong *)0x0) {
                                (*(code *)pplVar22[1][6])(pplVar22);
                              }
                              plVar4 = *(longlong **)(param_1 + 0x138);
                              *(longlong **)(param_1 + 0x138) = plVar20;
                              if ((plVar4 != (longlong *)0x0) &&
                                 (*plVar4 = *plVar4 + -1, *plVar4 == 0)) {
                                (**(code **)(plVar4[1] + 0x30))();
                              }
                              goto LAB_23aaaf437;
                            }
                            pcStack_c0 = *(code **)(param_1 + 0x60);
                            pcVar23 = *(code **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            pplStack_b8 = *(longlong ***)(param_1 + 0x68);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            iVar9 = 0x171;
                            goto LAB_23aab02f0;
                          }
                          goto LAB_23aab09c0;
                        }
                      }
                      pcStack_c0 = *(code **)(param_1 + 0x60);
                      pcStack_68 = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      pplStack_b8 = *(longlong ***)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    }
                    iVar9 = 0x170;
                    iVar21 = 0x170;
                    lVar14 = *plVar15 + -1;
                    *plVar15 = lVar14;
                    pcVar23 = pcStack_68;
                  }
                  if (lVar14 == 0) {
                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                    iVar9 = iVar21;
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_23aab02f0:
    *pplVar22 = (longlong *)((longlong)*pplVar22 + -1);
    if (*pplVar22 == (longlong *)0x0) {
      (*(code *)pplVar22[1][6])(pplVar22);
      pplVar22 = *(longlong ***)(param_1 + 0x138);
      *(longlong **)(param_1 + 0x138) = plVar20;
      if (pplVar22 == (longlong **)0x0) goto LAB_23aab04ea;
LAB_23aab0312:
      *pplVar22 = (longlong *)((longlong)*pplVar22 + -1);
      if (*pplVar22 == (longlong *)0x0) goto LAB_23aab0560;
      if (pcVar23 == (code *)0x0) goto LAB_23aab0583;
LAB_23aab0326:
      pcVar19 = pcVar23;
      if (*(longlong **)(pcVar23 + 0x18) == plVar4) goto LAB_23aab03e0;
      if (iVar9 == 0) goto LAB_23aab0337;
    }
    else {
      pplVar22 = *(longlong ***)(param_1 + 0x138);
      *(longlong **)(param_1 + 0x138) = plVar20;
      if (pplVar22 != (longlong **)0x0) goto LAB_23aab0312;
LAB_23aab04ea:
      if (pcVar23 == (code *)0x0) goto LAB_23aab0583;
      pcVar19 = pcVar23;
      if (plVar4 == *(longlong **)(pcVar23 + 0x18)) goto LAB_23aab03e0;
    }
LAB_23aab033d:
    pcVar19 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar6 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar6;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar19 + 0x18) = plVar4;
    *plVar4 = *plVar4 + 1;
    *(int *)(pcVar19 + 0x24) = iVar9;
    lVar14 = *(longlong *)(pcStack_c8 + 0x1f8);
    *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
    lVar14 = *(longlong *)(*(longlong *)(lVar14 + 0x10) + 0x2e8);
    lVar11 = *(longlong *)(pcVar19 + -8);
    puVar5 = *(undefined8 **)(lVar14 + 8);
    *puVar5 = pcVar19 + -0x10;
    *(longlong *)(pcVar19 + -0x10) = lVar14;
    *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar11 & 3) | (ulonglong)puVar5;
    lVar11 = *(longlong *)pcVar23;
    *(code **)(lVar14 + 8) = pcVar19 + -0x10;
    *(code **)(pcVar19 + 0x10) = pcVar23;
    if (lVar11 == 0) {
      (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
    }
  }
  else {
    lVar14 = *(longlong *)(pcVar6 + 0x10);
    if (0 < lVar14) {
      lVar11 = 0;
      do {
        if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar6 + lVar11 * 8 + 0x18) + 8) + 0xa8)) ||
           ((*(byte *)(*(longlong *)(pcVar6 + lVar11 * 8 + 0x18) + 0xab) & 0x40) == 0)) {
          plVar10 = *(longlong **)PyExc_TypeError_exref;
          uVar13 = PyUnicode_FromString
                             (
                             "catching classes that do not inherit from BaseException is not allowed"
                             );
          plVar18 = *(longlong **)(param_1 + 0x60);
          plVar15 = *(longlong **)(param_1 + 0x68);
          plVar16 = *(longlong **)(param_1 + 0x70);
          *(longlong **)(param_1 + 0x60) = plVar10;
          *plVar10 = *plVar10 + 1;
          *(undefined8 *)(param_1 + 0x68) = uVar13;
          *(undefined8 *)(param_1 + 0x70) = 0;
          if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
            (**(code **)(plVar18[1] + 0x30))();
          }
          if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          if ((plVar16 == (longlong *)0x0) || (*plVar16 = *plVar16 + -1, *plVar16 != 0))
          goto LAB_23aaafafd;
          (**(code **)(plVar16[1] + 0x30))(plVar16);
          pplVar22 = *(longlong ***)(param_1 + 0x138);
          goto LAB_23aaafb04;
        }
        lVar11 = lVar11 + 1;
      } while (lVar14 != lVar11);
      lVar11 = 0;
      do {
        iVar9 = FUN_23a35ebd0(param_1,pcVar19,*(undefined8 *)(pcVar6 + lVar11 * 8 + 0x18));
        if (iVar9 != 0) goto LAB_23aaafafd;
        lVar11 = lVar11 + 1;
      } while (lVar14 != lVar11);
      pplVar22 = *(longlong ***)(param_1 + 0x138);
    }
LAB_23aaaf99a:
    if ((pplVar22 == (longlong **)pcVar23) || (pplVar22 == (longlong **)0x0)) {
      pcStack_c0 = *(code **)PyExc_RuntimeError_exref;
      pplStack_b8 = (longlong **)PyUnicode_FromString("No active exception to reraise");
      pplVar22 = *(longlong ***)(param_1 + 0x138);
      *(longlong *)pcStack_c0 = *(longlong *)pcStack_c0 + 1;
      *(longlong **)(param_1 + 0x138) = plVar20;
      if ((pplVar22 == (longlong **)0x0) ||
         (*pplVar22 = (longlong *)((longlong)*pplVar22 + -1), *pplVar22 != (longlong *)0x0)) {
        plVar10 = (longlong *)0x0;
        iVar9 = 0x14f;
      }
      else {
        pcVar23 = (code *)0x0;
        plVar10 = (longlong *)0x0;
        iVar9 = 0x14f;
LAB_23aab0560:
        (*(code *)pplVar22[1][6])(pplVar22);
        if (pcVar23 != (code *)0x0) goto LAB_23aab0326;
        if (iVar9 == 0) goto LAB_23aab0580;
      }
    }
    else {
      pcStack_c0 = (code *)pplVar22[1];
      pcVar23 = (code *)pplVar22[5];
      *pplVar22 = (longlong *)((longlong)*pplVar22 + 1);
      *(longlong *)pcStack_c0 = *(longlong *)pcStack_c0 + 1;
      pplStack_b8 = pplVar22;
      if (pcVar23 != (code *)0x0) {
        *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
        if (*(longlong **)(pcVar23 + 0x18) == plVar4) {
          *(undefined4 *)(plVar4 + 5) = *(undefined4 *)(pcVar23 + 0x24);
          *(longlong **)(param_1 + 0x138) = plVar20;
          *pplVar22 = (longlong *)((longlong)*pplVar22 + -1);
          if (*pplVar22 == (longlong *)0x0) {
            plVar10 = (longlong *)0x0;
            iVar9 = 0;
            goto LAB_23aab0560;
          }
LAB_23aaaf9fb:
          plVar10 = (longlong *)0x0;
          iVar9 = 0;
          goto LAB_23aab0326;
        }
        *(longlong **)(param_1 + 0x138) = plVar20;
        *pplVar22 = (longlong *)((longlong)*pplVar22 + -1);
        if (*pplVar22 == (longlong *)0x0) {
          (**(code **)((longlong)pcStack_c0 + 0x30))(pplVar22);
          goto LAB_23aaaf9fb;
        }
        plVar10 = (longlong *)0x0;
        pcVar19 = pcVar23;
        if (plVar4 == *(longlong **)(pcVar23 + 0x18)) goto LAB_23aab03e0;
LAB_23aab0337:
        iVar9 = (int)plVar4[5];
        goto LAB_23aab033d;
      }
      plVar18 = *pplVar22;
      *(longlong **)(param_1 + 0x138) = plVar20;
      plVar10 = (longlong *)0x0;
      *pplVar22 = (longlong *)((longlong)plVar18 + -1);
      if ((longlong *)((longlong)plVar18 + -1) == (longlong *)0x0) {
        iVar9 = 0;
        goto LAB_23aab0560;
      }
LAB_23aab0580:
      iVar9 = (int)plVar4[5];
    }
LAB_23aab0583:
    pcVar19 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar23 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar23;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong *)(pcVar19 + 0x10) = 0;
    *(longlong **)(pcVar19 + 0x18) = plVar4;
    *plVar4 = *plVar4 + 1;
    *(int *)(pcVar19 + 0x24) = iVar9;
    lVar14 = *(longlong *)(pcStack_c8 + 0x1f8);
    *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
    lVar14 = *(longlong *)(*(longlong *)(lVar14 + 0x10) + 0x2e8);
    lVar11 = *(longlong *)(pcVar19 + -8);
    puVar5 = *(undefined8 **)(lVar14 + 8);
    *puVar5 = pcVar19 + -0x10;
    *(longlong *)(pcVar19 + -0x10) = lVar14;
    *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar11 & 3) | (ulonglong)puVar5;
    *(code **)(lVar14 + 8) = pcVar19 + -0x10;
  }
LAB_23aab03e0:
  FUN_23e8bba40(plVar4,&DAT_23ec31985,plVar3,plVar12,0,plVar10);
  if (_DAT_23ed90c38 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23ed90c38 = (longlong *)0x0;
  }
  lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar4 = *(longlong **)(lVar14 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar14 + 0x30);
  plVar18 = (longlong *)plVar4[2];
  *(undefined4 *)(plVar4 + 8) = 0xffffffff;
  if (plVar18 != (longlong *)0x0) {
    plVar4[2] = 0;
    *plVar18 = *plVar18 + -1;
    if (*plVar18 == 0) {
      (**(code **)(plVar18[1] + 0x30))();
    }
  }
  *plVar4 = *plVar4 + -1;
  if (*plVar4 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  plVar4[0xf] = 0;
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  FUN_23a33aa70(param_1,pcStack_c0,pplStack_b8,pcVar19);
  return (longlong *)0x0;
}
