/* ===== 23e83de30 workers.fishing.trigger_monitor:418 ===== */
/* ghidra_name=FUN_23e83de30 entry=23e83de30 size=22359 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e83de30(longlong param_1)

{
  longlong *plVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  undefined8 uVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  code *pcVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong lVar18;
  longlong lVar19;
  undefined4 uVar20;
  undefined1 auVar21 [8];
  longlong *plStack_108;
  code *pcStack_100;
  longlong *plStack_f8;
  longlong *plStack_f0;
  longlong *plStack_e8;
  longlong *plStack_e0;
  code *pcStack_d8;
  int iStack_d0;
  longlong *plStack_98;
  longlong *plStack_90;
  longlong *plStack_88;
  undefined1 auStack_78 [8];
  longlong *plStack_70;
  longlong *plStack_68;
  
  plVar7 = _DAT_23eede400;
  plStack_68 = (longlong *)0x0;
  auStack_78 = (undefined1  [8])0x0;
  plStack_70 = (longlong *)0x0;
  if (_DAT_23eede400 == (longlong *)0x0) {
LAB_23e83de8a:
    _DAT_23eede400 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede3f8,DAT_23eede5a0,0x58);
  }
  else {
    lVar9 = *_DAT_23eede400;
    if (1 < lVar9) {
      *_DAT_23eede400 = lVar9 + -1;
      goto LAB_23e83de8a;
    }
    if (_DAT_23eede400[2] != 0) {
      *_DAT_23eede400 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23e83de8a;
    }
  }
  plVar1 = _DAT_23eede400;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar7 = _DAT_23eede400 + 9;
  lVar18 = *(longlong *)(lVar9 + 8);
  _DAT_23eede400[0xf] = lVar18;
  *(longlong **)(lVar9 + 8) = plVar7;
  if ((lVar18 != 0) &&
     (((*(char *)(lVar18 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar18 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar18 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar18 + 0x38))) && (plVar1[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar18 + 0x28);
    *(longlong **)(plVar1[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  *plVar1 = *plVar1 + 1;
  *(undefined4 *)(plVar1 + 8) = 0;
  uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
  *(undefined4 *)(plVar1 + 5) = 0x1a3;
  plVar7 = (longlong *)FUN_23e94bb80(param_1,uVar6,_DAT_23eedc420);
  if (plVar7 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    plStack_70 = *(longlong **)(param_1 + 0x68);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (plStack_68 == (longlong *)0x0) {
      plVar12 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      uVar20 = 0x1a3;
      pcStack_100 = (code *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      pcStack_d8 = _PyRuntime_exref;
      plVar7 = (longlong *)0x0;
      goto LAB_23e8403f0;
    }
    if ((longlong *)plStack_68[3] != plVar1) {
      plVar12 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      uVar20 = 0x1a3;
      pcStack_100 = (code *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      pcStack_d8 = _PyRuntime_exref;
      plVar7 = (longlong *)0x0;
      goto LAB_23e83fdb0;
    }
LAB_23e83f28c:
    pcStack_100 = (code *)0x0;
    plVar12 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    plVar7 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plVar13 = plStack_68;
    goto LAB_23e83f2e0;
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
  *(undefined4 *)(plVar1 + 5) = 0x1a4;
  plVar7 = (longlong *)FUN_23e94bb80(param_1,uVar6,_DAT_23eedc428);
  if (plVar7 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    plStack_70 = *(longlong **)(param_1 + 0x68);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (plStack_68 == (longlong *)0x0) {
      plVar12 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      uVar20 = 0x1a4;
      pcStack_100 = (code *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      pcStack_d8 = _PyRuntime_exref;
      plVar7 = (longlong *)0x0;
      goto LAB_23e8403f0;
    }
    if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e83f28c;
    plVar12 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    uVar20 = 0x1a4;
    pcStack_100 = (code *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    pcStack_d8 = _PyRuntime_exref;
    plVar7 = (longlong *)0x0;
    goto LAB_23e83fdb0;
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
  *(undefined4 *)(plVar1 + 5) = 0x1a5;
  plVar7 = (longlong *)FUN_23e94bb80(param_1,uVar6,_DAT_23eedc430);
  if (plVar7 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    plStack_70 = *(longlong **)(param_1 + 0x68);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (plStack_68 != (longlong *)0x0) {
      if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e83f28c;
      plVar12 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      uVar20 = 0x1a5;
      pcStack_100 = (code *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      pcStack_d8 = _PyRuntime_exref;
      plVar7 = (longlong *)0x0;
      goto LAB_23e83fdb0;
    }
    plVar12 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    uVar20 = 0x1a5;
    pcStack_100 = (code *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    pcStack_d8 = _PyRuntime_exref;
    plVar7 = (longlong *)0x0;
LAB_23e8403f0:
    plVar13 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      plVar15 = plStack_68;
    }
    else {
      plVar15 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar15;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar15 = (longlong *)0x0;
    }
    plVar13[2] = 0;
    plVar13[3] = (longlong)plVar1;
    *plVar1 = *plVar1 + 1;
    lVar9 = *(longlong *)(pcStack_d8 + 0x1f8);
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar9 = *(longlong *)(lVar9 + 0x10);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar20;
    lVar9 = *(longlong *)(lVar9 + 0x2e8);
    lVar18 = plVar13[-1];
    puVar2 = *(undefined8 **)(lVar9 + 8);
    *puVar2 = plVar13 + -2;
    plVar13[-2] = lVar9;
    plVar13[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar9 + 8) = plVar13 + -2;
  }
  else {
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
    *(undefined4 *)(plVar1 + 5) = 0x1a8;
    plVar7 = (longlong *)FUN_23e94bb80(param_1,uVar6,_DAT_23eedc438);
    if (plVar7 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_70 = *(longlong **)(param_1 + 0x68);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plStack_68 != (longlong *)0x0) {
        if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e83f28c;
        plVar12 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        uVar20 = 0x1a8;
        pcStack_100 = (code *)0x0;
        plStack_e0 = (longlong *)0x0;
        plStack_e8 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        pcStack_d8 = _PyRuntime_exref;
        plVar7 = (longlong *)0x0;
        goto LAB_23e83fdb0;
      }
      plVar12 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      uVar20 = 0x1a8;
      pcStack_100 = (code *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      pcStack_d8 = _PyRuntime_exref;
      plVar7 = (longlong *)0x0;
      goto LAB_23e8403f0;
    }
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    lVar9 = *(longlong *)(DAT_23eedbeb8 + 0x20);
    if (*(char *)(lVar9 + 10) != '\0') {
      iVar5 = *(int *)(lVar9 + 0xc);
      if (*(int *)(lVar9 + 0xc) == 0) {
        *(int *)(lVar9 + 0xc) = DAT_23ec1552c;
        iVar5 = DAT_23ec1552c;
        DAT_23ec1552c = DAT_23ec1552c + 1;
      }
      if (_DAT_23ec154e4 != iVar5) {
        _DAT_23ec154e4 = iVar5;
        _DAT_23eede3d0 = FUN_23e8cbd60(lVar9,_DAT_23eedc440,*(undefined8 *)(_DAT_23eedc440 + 0x18));
      }
      if (-1 < _DAT_23eede3d0) {
        lVar18 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
        lVar19 = *(longlong *)(lVar18 + 8 + _DAT_23eede3d0 * 0x10);
        if (lVar19 != 0) goto LAB_23e83e06d;
        _DAT_23eede3d0 = FUN_23e8cbd60(lVar9,_DAT_23eedc440,*(undefined8 *)(_DAT_23eedc440 + 0x18));
        if (-1 < _DAT_23eede3d0) {
          lVar19 = *(longlong *)(lVar18 + 8 + _DAT_23eede3d0 * 0x10);
          goto LAB_23e83f890;
        }
      }
LAB_23e83e409:
      plVar7 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedc440);
      if ((plVar7 != (longlong *)0x0) && (lVar19 = *plVar7, lVar19 != 0)) goto LAB_23e83e06d;
      FUN_23e915740(param_1,auStack_78,_DAT_23eedc440);
      if (plStack_68 != (longlong *)0x0) {
        if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e83f28c;
        plVar12 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        pcStack_100 = (code *)0x0;
        plVar8 = (longlong *)0x0;
        plVar7 = (longlong *)0x0;
        uVar20 = 0x1a9;
        plStack_f0 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        plStack_e8 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        pcStack_d8 = _PyRuntime_exref;
        goto LAB_23e83fdb0;
      }
LAB_23e840380:
      plVar12 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      pcStack_100 = (code *)0x0;
      plVar8 = (longlong *)0x0;
      plVar7 = (longlong *)0x0;
      uVar20 = 0x1a9;
      plStack_f0 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      pcStack_d8 = _PyRuntime_exref;
      goto LAB_23e8403f0;
    }
    plVar7 = (longlong *)FUN_23a37a020(DAT_23eedbeb8,_DAT_23eedc440);
    if (plVar7 == (longlong *)0x0) goto LAB_23e83e409;
    lVar19 = *plVar7;
LAB_23e83f890:
    if (lVar19 == 0) goto LAB_23e83e409;
LAB_23e83e06d:
    *(undefined4 *)(plVar1 + 5) = 0x1a9;
    plVar7 = (longlong *)FUN_23e94bb80(param_1,lVar19,_DAT_23eedc448);
    if (plVar7 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_70 = *(longlong **)(param_1 + 0x68);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plStack_68 != (longlong *)0x0) {
        if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e83f28c;
        plVar12 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        uVar20 = 0x1a9;
        pcStack_100 = (code *)0x0;
        plStack_e0 = (longlong *)0x0;
        plStack_e8 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        pcStack_d8 = _PyRuntime_exref;
        goto LAB_23e83fdb0;
      }
      goto LAB_23e840380;
    }
    *(undefined4 *)(plVar1 + 5) = 0x1ab;
    plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar7,_DAT_23eedc450);
    if (plVar8 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_70 = *(longlong **)(param_1 + 0x68);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plStack_68 == (longlong *)0x0) goto LAB_23e8408a0;
      if ((longlong *)plStack_68[3] != plVar1) {
        plVar12 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        pcStack_100 = (code *)0x0;
        uVar20 = 0x1ab;
        plStack_f0 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        plStack_e8 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        pcStack_d8 = _PyRuntime_exref;
        goto LAB_23e83fdb0;
      }
      goto LAB_23e83f6d0;
    }
    iVar5 = FUN_23a35f020(plVar8);
    *plVar8 = *plVar8 + -1;
    plVar10 = plVar8;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (iVar5 == -1) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_70 = *(longlong **)(param_1 + 0x68);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plStack_68 != (longlong *)0x0) {
        if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e83f6d0;
        plVar12 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        uVar20 = 0x1ab;
        pcStack_100 = (code *)0x0;
        plStack_e0 = (longlong *)0x0;
        plStack_e8 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        pcStack_d8 = _PyRuntime_exref;
        goto LAB_23e83fdb0;
      }
LAB_23e8408a0:
      plVar12 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      uVar20 = 0x1ab;
      pcStack_100 = (code *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      pcStack_d8 = _PyRuntime_exref;
      goto LAB_23e8403f0;
    }
    if (iVar5 == 0) {
      uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
      *(undefined4 *)(plVar1 + 5) = 0x1ac;
      plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar6,_DAT_23eedc458);
      if (plVar8 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        plStack_70 = *(longlong **)(param_1 + 0x68);
        plStack_68 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (plStack_68 == (longlong *)0x0) {
          plVar12 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          pcStack_100 = (code *)0x0;
          uVar20 = 0x1ac;
          plStack_f0 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          pcStack_d8 = _PyRuntime_exref;
          plVar8 = (longlong *)0x0;
          goto LAB_23e8403f0;
        }
        if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e83f6d0;
        plVar12 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        pcStack_100 = (code *)0x0;
        uVar20 = 0x1ac;
        plStack_f0 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        plStack_e8 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        pcStack_d8 = _PyRuntime_exref;
        plVar8 = (longlong *)0x0;
        goto LAB_23e83fdb0;
      }
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
      *(undefined4 *)(plVar1 + 5) = 0x1ad;
      plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar6,_DAT_23eedc460);
      if (plVar8 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        plStack_70 = *(longlong **)(param_1 + 0x68);
        plStack_68 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (plStack_68 != (longlong *)0x0) {
          if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e83f6d0;
          pcStack_d8 = _PyRuntime_exref;
          plVar12 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          pcStack_100 = (code *)0x0;
          uVar20 = 0x1ad;
          plStack_f0 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plVar8 = (longlong *)0x0;
          goto LAB_23e83fdb0;
        }
        pcStack_d8 = _PyRuntime_exref;
        plVar12 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        pcStack_100 = (code *)0x0;
        uVar20 = 0x1ad;
        plStack_f0 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        plStack_e8 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        goto LAB_23e8403f0;
      }
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      plVar8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      lVar9 = *(longlong *)_Py_NoneStruct_exref;
      plStack_108 = (longlong *)0x0;
LAB_23e83e1a8:
      pcVar14 = _Py_NoneStruct_exref;
      *(longlong *)_Py_NoneStruct_exref = lVar9 + 1;
      lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar1 = *(longlong **)(lVar9 + 0x28);
      plVar10 = (longlong *)plVar1[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
      *(undefined4 *)(plVar1 + 8) = 0xffffffff;
      if (plVar10 != (longlong *)0x0) {
        plVar1[2] = 0;
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))();
        }
      }
      *plVar1 = *plVar1 + -1;
      if (*plVar1 == 0) {
        (**(code **)(plVar1[1] + 0x30))(plVar1);
      }
      plVar1[0xf] = 0;
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      pcStack_100 = (code *)0x0;
      plVar12 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      if (plVar8 != (longlong *)0x0) {
        plVar10 = (longlong *)0x0;
        goto LAB_23e83e22e;
      }
      goto LAB_23e83e23c;
    }
    uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
    plVar12 = _DAT_23eedc468;
    lVar9 = *(longlong *)(param_1 + 0x10);
    plVar11 = *(longlong **)(lVar9 + 0xe28);
    if (plVar11 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
    }
    else {
      lVar18 = plVar11[3];
      *(int *)(lVar9 + 0xec0) = *(int *)(lVar9 + 0xec0) + -1;
      *(longlong *)(lVar9 + 0xe28) = lVar18;
      *plVar11 = 1;
    }
    pcStack_d8 = _PyRuntime_exref;
    *(undefined1 (*) [16])(plVar11 + 4) = (undefined1  [16])0x0;
    lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_d8 + 0x1f8) + 0x10) + 0x2e8);
    lVar18 = plVar11[-1];
    puVar2 = *(undefined8 **)(lVar9 + 8);
    *puVar2 = plVar11 + -2;
    plVar11[-2] = lVar9;
    plVar11[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar9 + 8) = plVar11 + -2;
    uVar3 = DAT_23eedbec8;
    *plVar12 = *plVar12 + 1;
    plVar11[3] = (longlong)plVar12;
    plVar13 = (longlong *)FUN_23e8bc2f0(plVar7,uVar3);
    plVar12 = DAT_23ed6cd28;
    if (plVar13 == (longlong *)0x0) {
LAB_23e83f670:
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_70 = *(longlong **)(param_1 + 0x68);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
        if (plStack_68 != (longlong *)0x0) {
          plVar8 = (longlong *)plStack_68[3];
joined_r0x00023e83fe9d:
          if (plVar8 == plVar1) goto LAB_23e83f6d0;
          pcStack_100 = (code *)0x0;
          plVar12 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plVar8 = (longlong *)0x0;
          uVar20 = 0x1b0;
          plStack_e0 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          goto LAB_23e83fdb0;
        }
      }
      else if (plStack_68 != (longlong *)0x0) {
        plVar8 = (longlong *)plStack_68[3];
        goto joined_r0x00023e83fe9d;
      }
LAB_23e8406c0:
      pcStack_100 = (code *)0x0;
      plVar12 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      uVar20 = 0x1b0;
      plStack_e0 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      goto LAB_23e8403f0;
    }
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      plStack_108 = plVar8;
      if (plVar15 != (longlong *)0x0) {
        *plVar15 = *plVar15 + 1;
        DAT_23ed6a4c0 = plVar15;
        goto LAB_23e83e5d9;
      }
LAB_23e840c9d:
      PyErr_PrintEx(0);
      Py_Exit(1);
      plVar8 = plVar10;
LAB_23e840cb0:
      pcStack_100 = (code *)0x0;
      plVar12 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plVar13 = plStack_68;
      goto LAB_23e83f2e0;
    }
LAB_23e83e5d9:
    plStack_90 = plVar12;
    plStack_98 = plVar13;
    lVar9 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    plVar8 = _DAT_23eedc470;
    if (lVar9 == 0) goto LAB_23e83f670;
    plVar11[4] = lVar9;
    *plVar8 = *plVar8 + 1;
    plVar11[5] = (longlong)plVar8;
    plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar11);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (plVar8 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_70 = *(longlong **)(param_1 + 0x68);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plStack_68 == (longlong *)0x0) goto LAB_23e8406c0;
      if ((longlong *)plStack_68[3] != plVar1) {
        pcStack_100 = (code *)0x0;
        plVar12 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        uVar20 = 0x1b0;
        plStack_e0 = (longlong *)0x0;
        plStack_e8 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        goto LAB_23e83fdb0;
      }
LAB_23e83f6d0:
      pcStack_100 = (code *)0x0;
      plVar12 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plVar13 = plStack_68;
      goto LAB_23e83f2e0;
    }
    *(undefined4 *)(plVar1 + 5) = 0x1b0;
    plVar10 = (longlong *)FUN_23e914090(param_1,uVar6,plVar8);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (plVar10 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_70 = *(longlong **)(param_1 + 0x68);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plStack_68 == (longlong *)0x0) goto LAB_23e8406c0;
      if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e83f6d0;
      pcStack_100 = (code *)0x0;
      plVar12 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      uVar20 = 0x1b0;
      plStack_e0 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      goto LAB_23e83fdb0;
    }
    lVar9 = *plVar10;
    *plVar10 = lVar9 + -1;
    if (lVar9 + -1 == 0) {
      (**(code **)(plVar10[1] + 0x30))();
    }
    *(undefined4 *)(plVar1 + 5) = 0x1b3;
    plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar7,_DAT_23eedc478);
    if (plVar8 == (longlong *)0x0) {
LAB_23e8402d0:
      auVar21 = *(undefined1 (*) [8])(param_1 + 0x60);
      plVar12 = *(longlong **)(param_1 + 0x68);
      plVar11 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e840066:
      plStack_68 = plVar11;
      auStack_78 = auVar21;
      plStack_70 = plVar12;
      if (plVar11 == (longlong *)0x0) {
        pcStack_100 = (code *)0x0;
        plVar12 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        uVar20 = 0x1b3;
        plStack_e0 = (longlong *)0x0;
        plStack_e8 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        goto LAB_23e8403f0;
      }
      if ((longlong *)plVar11[3] == plVar1) goto LAB_23e83f6d0;
      pcStack_100 = (code *)0x0;
      plVar12 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      uVar20 = 0x1b3;
      plStack_e0 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
    }
    else {
      plVar10 = (longlong *)FUN_23a388310(plVar8);
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (plVar10 == (longlong *)0x0) goto LAB_23e8402d0;
      plVar8 = (longlong *)(**(code **)(plVar10[1] + 0xe0))(plVar10);
      if ((plVar8 == (longlong *)0x0) &&
         (plVar8 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,0,2), plVar8 == (longlong *)0x0)) {
        plStack_108 = (longlong *)0x0;
LAB_23e83ffd0:
        plVar11 = plStack_68;
        plVar12 = plStack_70;
        auVar21 = auStack_78;
        plStack_68 = (longlong *)0x0;
        _auStack_78 = (undefined1  [16])0x0;
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        plStack_68 = (longlong *)0x0;
        auStack_78 = (undefined1  [8])0x0;
        plStack_70 = (longlong *)0x0;
        if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if ((plStack_108 != (longlong *)0x0) &&
           (lVar9 = *plStack_108, *plStack_108 = lVar9 + -1, lVar9 + -1 == 0)) {
          (**(code **)(plStack_108[1] + 0x30))(plStack_108);
        }
        goto LAB_23e840066;
      }
      plStack_108 = (longlong *)(**(code **)(plVar10[1] + 0xe0))(plVar10);
      if (((plStack_108 == (longlong *)0x0) &&
          (plStack_108 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,1,2),
          plStack_108 == (longlong *)0x0)) ||
         (cVar4 = FUN_23a3884a0(param_1,auStack_78,plVar10,2), cVar4 == '\0')) goto LAB_23e83ffd0;
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (*plStack_108 == 0) {
        (**(code **)(plStack_108[1] + 0x30))();
      }
      uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
      plVar10 = _DAT_23eedc480;
      lVar9 = *(longlong *)(param_1 + 0x10);
      plVar11 = *(longlong **)(lVar9 + 0xe30);
      if (plVar11 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,4);
      }
      else {
        lVar18 = plVar11[3];
        *(int *)(lVar9 + 0xec4) = *(int *)(lVar9 + 0xec4) + -1;
        *(longlong *)(lVar9 + 0xe30) = lVar18;
        *plVar11 = 1;
      }
      plVar11[6] = 0;
      *(undefined1 (*) [16])(plVar11 + 4) = (undefined1  [16])0x0;
      lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_d8 + 0x1f8) + 0x10) + 0x2e8);
      lVar18 = plVar11[-1];
      puVar2 = *(undefined8 **)(lVar9 + 8);
      *puVar2 = plVar11 + -2;
      plVar11[-2] = lVar9;
      plVar11[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
      *(longlong **)(lVar9 + 8) = plVar11 + -2;
      plVar12 = DAT_23ed6a4c0;
      *plVar10 = *plVar10 + 1;
      plVar11[3] = (longlong)plVar10;
      plVar13 = DAT_23ed6cd28;
      if (plVar12 == (longlong *)0x0) {
        plVar10 = plVar8;
        plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
        if (plVar12 == (longlong *)0x0) goto LAB_23e840c9d;
        *plVar12 = *plVar12 + 1;
        DAT_23ed6a4c0 = plVar12;
      }
      plStack_90 = plVar13;
      plStack_98 = plVar8;
      lVar9 = FUN_23e94ed00(param_1,plVar12,&plStack_98);
      if (lVar9 == 0) {
LAB_23e8405a0:
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        plStack_70 = *(longlong **)(param_1 + 0x68);
        plStack_68 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (plStack_68 == (longlong *)0x0) {
LAB_23e840a37:
          pcStack_100 = (code *)0x0;
          plVar12 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          uVar20 = 0x1b4;
          plStack_e0 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          goto LAB_23e8403f0;
        }
        if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e840cb0;
        pcStack_100 = (code *)0x0;
        plVar12 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        uVar20 = 0x1b4;
        plStack_e0 = (longlong *)0x0;
        plStack_e8 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
      }
      else {
        plVar11[4] = lVar9;
        plVar10 = _DAT_23eedc350;
        *_DAT_23eedc350 = *_DAT_23eedc350 + 1;
        plVar11[5] = (longlong)plVar10;
        plVar12 = DAT_23ed6cd28;
        if (DAT_23ed6a4c0 == (longlong *)0x0) {
          plVar10 = plVar8;
          plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar13 == (longlong *)0x0) goto LAB_23e840c9d;
          *plVar13 = *plVar13 + 1;
          DAT_23ed6a4c0 = plVar13;
        }
        plStack_98 = plStack_108;
        plStack_90 = plVar12;
        lVar9 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
        if (lVar9 == 0) goto LAB_23e8405a0;
        plVar11[6] = lVar9;
        plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar11);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (plVar10 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
          plStack_70 = *(longlong **)(param_1 + 0x68);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (plStack_68 != (longlong *)0x0) {
            if ((longlong *)plStack_68[3] != plVar1) {
              pcStack_100 = (code *)0x0;
              plVar12 = (longlong *)0x0;
              plVar10 = (longlong *)0x0;
              plVar11 = (longlong *)0x0;
              plStack_f0 = (longlong *)0x0;
              uVar20 = 0x1b4;
              plStack_e0 = (longlong *)0x0;
              plStack_e8 = (longlong *)0x0;
              plStack_f8 = (longlong *)0x0;
              goto LAB_23e83fdb0;
            }
            goto LAB_23e840cb0;
          }
          goto LAB_23e840a37;
        }
        *(undefined4 *)(plVar1 + 5) = 0x1b4;
        plVar11 = (longlong *)FUN_23e914090(param_1,uVar6,plVar10);
        lVar9 = *plVar10;
        *plVar10 = lVar9 + -1;
        if (lVar9 + -1 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (plVar11 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
          plStack_70 = *(longlong **)(param_1 + 0x68);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (plStack_68 == (longlong *)0x0) goto LAB_23e840a37;
          if (plVar1 != (longlong *)plStack_68[3]) {
            plVar12 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plVar10 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            uVar20 = 0x1b4;
            pcStack_100 = (code *)0x0;
            plStack_e8 = (longlong *)0x0;
            goto LAB_23e83fdb0;
          }
          goto LAB_23e840cb0;
        }
        lVar9 = *plVar11;
        *plVar11 = lVar9 + -1;
        if (lVar9 + -1 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        lVar9 = *(longlong *)(DAT_23eedbeb8 + 0x20);
        if (*(char *)(lVar9 + 10) == '\0') {
          plVar10 = (longlong *)FUN_23a37a020(DAT_23eedbeb8,_DAT_23eedc488);
          if (plVar10 == (longlong *)0x0) goto LAB_23e84095d;
          lVar18 = *plVar10;
LAB_23e840954:
          if (lVar18 == 0) goto LAB_23e84095d;
LAB_23e83ea7a:
          *(undefined4 *)(plVar1 + 5) = 0x1b6;
          plStack_90 = plStack_108;
          plStack_98 = plVar8;
          plVar10 = (longlong *)FUN_23e94ed00(param_1,lVar18,&plStack_98);
          if (plVar10 == (longlong *)0x0) {
LAB_23e840cf6:
            auVar21 = *(undefined1 (*) [8])(param_1 + 0x60);
            plVar10 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar12 = *(longlong **)(param_1 + 0x68);
            goto LAB_23e8409c0;
          }
          plVar11 = (longlong *)FUN_23a388310(plVar10);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if (plVar11 == (longlong *)0x0) goto LAB_23e840cf6;
          plStack_f8 = (longlong *)(**(code **)(plVar11[1] + 0xe0))(plVar11);
          if ((plStack_f8 == (longlong *)0x0) &&
             (plStack_f8 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,0,2),
             plStack_f8 == (longlong *)0x0)) {
            plStack_e8 = (longlong *)0x0;
LAB_23e840b30:
            plVar10 = plStack_68;
            plVar12 = plStack_70;
            auVar21 = auStack_78;
            plStack_68 = (longlong *)0x0;
            _auStack_78 = (undefined1  [16])0x0;
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            plStack_68 = (longlong *)0x0;
            auStack_78 = (undefined1  [8])0x0;
            plStack_70 = (longlong *)0x0;
            if ((plStack_f8 != (longlong *)0x0) &&
               (lVar9 = *plStack_f8, *plStack_f8 = lVar9 + -1, lVar9 + -1 == 0)) {
              (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
            }
            if ((plStack_e8 != (longlong *)0x0) &&
               (lVar9 = *plStack_e8, *plStack_e8 = lVar9 + -1, lVar9 + -1 == 0)) {
              (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
            }
            goto LAB_23e8409c0;
          }
          plStack_e8 = (longlong *)(**(code **)(plVar11[1] + 0xe0))(plVar11);
          if (((plStack_e8 == (longlong *)0x0) &&
              (plStack_e8 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,1,2),
              plStack_e8 == (longlong *)0x0)) ||
             (cVar4 = FUN_23a3884a0(param_1,auStack_78,plVar11), cVar4 == '\0')) goto LAB_23e840b30;
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (*plStack_f8 == 0) {
            (**(code **)(plStack_f8[1] + 0x30))();
          }
          if (*plStack_e8 == 0) {
            (**(code **)(plStack_e8[1] + 0x30))();
          }
          uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
          plVar10 = _DAT_23eedc490;
          lVar9 = *(longlong *)(param_1 + 0x10);
          plVar11 = *(longlong **)(lVar9 + 0xe20);
          if (plVar11 == (longlong *)0x0) {
            plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
          }
          else {
            lVar18 = plVar11[3];
            *(int *)(lVar9 + 0xebc) = *(int *)(lVar9 + 0xebc) + -1;
            *(longlong *)(lVar9 + 0xe20) = lVar18;
            *plVar11 = 1;
          }
          plVar11[4] = 0;
          lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_d8 + 0x1f8) + 0x10) + 0x2e8);
          lVar18 = plVar11[-1];
          puVar2 = *(undefined8 **)(lVar9 + 8);
          *puVar2 = plVar11 + -2;
          plVar11[-2] = lVar9;
          plVar11[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
          *(longlong **)(lVar9 + 8) = plVar11 + -2;
          plVar12 = DAT_23ed6a4c0;
          *plVar10 = *plVar10 + 1;
          plVar11[3] = (longlong)plVar10;
          plVar13 = DAT_23ed6cd28;
          if (plVar12 == (longlong *)0x0) {
            plVar10 = plVar8;
            plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar12 == (longlong *)0x0) goto LAB_23e840c9d;
            *plVar12 = *plVar12 + 1;
            DAT_23ed6a4c0 = plVar12;
          }
          plStack_98 = plStack_f8;
          plStack_90 = plVar13;
          lVar9 = FUN_23e94ed00(param_1);
          if (lVar9 == 0) {
            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
            plStack_70 = *(longlong **)(param_1 + 0x68);
            plStack_68 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              FUN_23a334bc0(plVar11);
            }
            if (plStack_68 == (longlong *)0x0) goto LAB_23e8410ef;
LAB_23e840f2a:
            plStack_e0 = (longlong *)0x0;
            if (plVar1 != (longlong *)plStack_68[3]) {
              plVar12 = (longlong *)0x0;
              plVar11 = (longlong *)0x0;
              plVar10 = (longlong *)0x0;
              plStack_f0 = (longlong *)0x0;
              uVar20 = 0x1b7;
              pcStack_100 = (code *)0x0;
              goto LAB_23e83fdb0;
            }
LAB_23e840fe3:
            pcStack_100 = (code *)0x0;
            plVar12 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            plVar10 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plVar13 = plStack_68;
            goto LAB_23e83f2e0;
          }
          plVar11[4] = lVar9;
          plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar11);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))();
          }
          if (plVar10 == (longlong *)0x0) {
            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
            plStack_70 = *(longlong **)(param_1 + 0x68);
            plStack_68 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (plStack_68 != (longlong *)0x0) {
              if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e840fe3;
              plVar12 = (longlong *)0x0;
              plVar11 = (longlong *)0x0;
              plStack_f0 = (longlong *)0x0;
              uVar20 = 0x1b7;
              pcStack_100 = (code *)0x0;
              plStack_e0 = (longlong *)0x0;
              plVar10 = (longlong *)0x0;
              goto LAB_23e83fdb0;
            }
LAB_23e8410ef:
            plVar12 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            plVar10 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            uVar20 = 0x1b7;
            pcStack_100 = (code *)0x0;
            plStack_e0 = (longlong *)0x0;
            goto LAB_23e8403f0;
          }
          *(undefined4 *)(plVar1 + 5) = 0x1b7;
          plVar11 = (longlong *)FUN_23e914090(param_1,uVar6,plVar10);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if (plVar11 == (longlong *)0x0) {
            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
            plStack_70 = *(longlong **)(param_1 + 0x68);
            plStack_68 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (plStack_68 != (longlong *)0x0) goto LAB_23e840f2a;
            goto LAB_23e8410ef;
          }
          lVar9 = *plVar11;
          *plVar11 = lVar9 + -1;
          if (lVar9 + -1 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
          plVar10 = _DAT_23eedc498;
          lVar9 = *(longlong *)(param_1 + 0x10);
          plVar11 = *(longlong **)(lVar9 + 0xe28);
          if (plVar11 == (longlong *)0x0) {
            plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
          }
          else {
            lVar18 = plVar11[3];
            *(int *)(lVar9 + 0xec0) = *(int *)(lVar9 + 0xec0) + -1;
            *(longlong *)(lVar9 + 0xe28) = lVar18;
            *plVar11 = 1;
          }
          *(undefined1 (*) [16])(plVar11 + 4) = (undefined1  [16])0x0;
          lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_d8 + 0x1f8) + 0x10) + 0x2e8);
          lVar18 = plVar11[-1];
          puVar2 = *(undefined8 **)(lVar9 + 8);
          *puVar2 = plVar11 + -2;
          plVar11[-2] = lVar9;
          plVar11[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
          *(longlong **)(lVar9 + 8) = plVar11 + -2;
          uVar3 = _DAT_23eedc380;
          *plVar10 = *plVar10 + 1;
          plVar11[3] = (longlong)plVar10;
          plVar10 = (longlong *)FUN_23e8bc2f0(plStack_e8,uVar3);
          if (plVar10 != (longlong *)0x0) {
            *(undefined4 *)(plVar1 + 5) = 0x1b8;
            plVar12 = (longlong *)FUN_23e91a870(param_1,plVar10);
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            plVar13 = DAT_23ed6cd28;
            if (plVar12 == (longlong *)0x0) goto LAB_23e840f57;
            if (DAT_23ed6a4c0 == (longlong *)0x0) {
              plVar10 = plVar8;
              plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar15 == (longlong *)0x0) goto LAB_23e840c9d;
              *plVar15 = *plVar15 + 1;
              DAT_23ed6a4c0 = plVar15;
            }
            plStack_90 = plVar13;
            plStack_98 = plVar12;
            lVar9 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            plVar10 = _DAT_23eedc4a0;
            if (lVar9 == 0) goto LAB_23e840f57;
            plVar11[4] = lVar9;
            *plVar10 = *plVar10 + 1;
            plVar11[5] = (longlong)plVar10;
            plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar11);
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              FUN_23a334bc0(plVar11);
            }
            if (plVar10 != (longlong *)0x0) {
              *(undefined4 *)(plVar1 + 5) = 0x1b8;
              plVar11 = (longlong *)FUN_23e914090(param_1,uVar6,plVar10);
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                FUN_23a334bc0(plVar10);
              }
              if (plVar11 == (longlong *)0x0) {
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_70 = *(longlong **)(param_1 + 0x68);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_68 != (longlong *)0x0) {
                  if (plVar1 == (longlong *)plStack_68[3]) goto LAB_23e840fe3;
                  plVar12 = (longlong *)0x0;
                  plVar11 = (longlong *)0x0;
                  plStack_f0 = (longlong *)0x0;
                  uVar20 = 0x1b8;
                  plVar10 = (longlong *)0x0;
                  pcStack_100 = (code *)0x0;
                  plStack_e0 = (longlong *)0x0;
                  goto LAB_23e83fdb0;
                }
                goto LAB_23e841126;
              }
              lVar9 = *plVar11;
              *plVar11 = lVar9 + -1;
              if (lVar9 + -1 == 0) {
                FUN_23a334bc0(plVar11);
              }
              lVar9 = *(longlong *)(DAT_23eedbeb8 + 0x20);
              if (*(char *)(lVar9 + 10) != '\0') {
                iVar5 = *(int *)(lVar9 + 0xc);
                if (*(int *)(lVar9 + 0xc) == 0) {
                  *(int *)(lVar9 + 0xc) = DAT_23ec1552c;
                  iVar5 = DAT_23ec1552c;
                  DAT_23ec1552c = DAT_23ec1552c + 1;
                }
                if (_DAT_23ec154ec != iVar5) {
                  _DAT_23ec154ec = iVar5;
                  _DAT_23eede3e0 =
                       FUN_23e8cbd60(lVar9,_DAT_23eedc4a8,*(undefined8 *)(_DAT_23eedc4a8 + 0x18));
                }
                if (-1 < _DAT_23eede3e0) {
                  lVar18 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
                  lVar19 = *(longlong *)(lVar18 + 8 + _DAT_23eede3e0 * 0x10);
                  if (lVar19 != 0) goto LAB_23e83f057;
                  _DAT_23eede3e0 =
                       FUN_23e8cbd60(lVar9,_DAT_23eedc4a8,*(undefined8 *)(_DAT_23eedc4a8 + 0x18));
                  if (-1 < _DAT_23eede3e0) {
                    lVar19 = *(longlong *)(lVar18 + 8 + _DAT_23eede3e0 * 0x10);
                    goto LAB_23e8411eb;
                  }
                }
LAB_23e8411f4:
                plVar10 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedc4a8);
                if ((plVar10 != (longlong *)0x0) && (lVar19 = *plVar10, lVar19 != 0))
                goto LAB_23e83f057;
                FUN_23e915740();
                if (plStack_68 != (longlong *)0x0) {
                  if (plVar1 == (longlong *)plStack_68[3]) goto LAB_23e840fe3;
                  plVar12 = (longlong *)0x0;
                  plStack_f0 = (longlong *)0x0;
                  plVar11 = (longlong *)0x0;
                  plVar10 = (longlong *)0x0;
                  uVar20 = 0x1bb;
                  pcStack_100 = (code *)0x0;
                  plStack_e0 = (longlong *)0x0;
                  goto LAB_23e83fdb0;
                }
LAB_23e8422bc:
                plVar12 = (longlong *)0x0;
                plStack_f0 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                plVar10 = (longlong *)0x0;
                pcStack_100 = (code *)0x0;
                uVar20 = 0x1bb;
                plStack_e0 = (longlong *)0x0;
                goto LAB_23e8403f0;
              }
              plVar10 = (longlong *)FUN_23a37a020(DAT_23eedbeb8,_DAT_23eedc4a8);
              if (plVar10 == (longlong *)0x0) goto LAB_23e8411f4;
              lVar19 = *plVar10;
LAB_23e8411eb:
              if (lVar19 == 0) goto LAB_23e8411f4;
LAB_23e83f057:
              uVar6 = _DAT_23eedc4b0;
              *(undefined4 *)(plVar1 + 5) = 0x1bb;
              plStack_e0 = (longlong *)FUN_23e94bb80(param_1,lVar19,uVar6);
              if (plStack_e0 == (longlong *)0x0) {
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_70 = *(longlong **)(param_1 + 0x68);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_68 == (longlong *)0x0) goto LAB_23e8422bc;
                if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e840fe3;
                plVar12 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                pcStack_100 = (code *)0x0;
                uVar20 = 0x1bb;
                plVar10 = (longlong *)0x0;
                plStack_f0 = (longlong *)0x0;
                goto LAB_23e83fdb0;
              }
              *(undefined4 *)(plVar1 + 5) = 0x1bd;
              plVar10 = (longlong *)FUN_23e91bfe0(param_1,plStack_e0);
              if (plVar10 == (longlong *)0x0) {
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_70 = *(longlong **)(param_1 + 0x68);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_68 == (longlong *)0x0) goto LAB_23e842296;
                if (plVar1 != (longlong *)plStack_68[3]) {
                  plVar12 = (longlong *)0x0;
                  plVar11 = (longlong *)0x0;
                  uVar20 = 0x1bd;
                  plStack_f0 = (longlong *)0x0;
                  pcStack_100 = (code *)0x0;
                  plVar10 = (longlong *)0x0;
                  goto LAB_23e83fdb0;
                }
                goto LAB_23e841fae;
              }
              iVar5 = FUN_23a35f020();
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                FUN_23a334bc0();
              }
              if (iVar5 == -1) {
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_70 = *(longlong **)(param_1 + 0x68);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_68 != (longlong *)0x0) {
                  if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e841fae;
                  plVar12 = (longlong *)0x0;
                  plVar10 = (longlong *)0x0;
                  plStack_f0 = (longlong *)0x0;
                  uVar20 = 0x1bd;
                  plVar11 = (longlong *)0x0;
                  pcStack_100 = (code *)0x0;
                  goto LAB_23e83fdb0;
                }
LAB_23e842296:
                plVar12 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                plStack_f0 = (longlong *)0x0;
                plVar10 = (longlong *)0x0;
                uVar20 = 0x1bd;
                pcStack_100 = (code *)0x0;
                goto LAB_23e8403f0;
              }
              if (iVar5 == 0) {
                uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                plVar10 = _DAT_23eedc4b8;
                plVar11 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                *plVar10 = *plVar10 + 1;
                plVar11[3] = (longlong)plVar10;
                lVar9 = FUN_23e94f9d0(param_1,plStack_e0,DAT_23ed6cd28);
                if (lVar9 == 0) {
                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  plStack_70 = *(longlong **)(param_1 + 0x68);
                  plStack_68 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    FUN_23a334bc0(plVar11);
                  }
joined_r0x00023e842075:
                  if (plStack_68 != (longlong *)0x0) {
                    plVar10 = (longlong *)0x0;
                    if ((longlong *)plStack_68[3] == plVar1) {
LAB_23e841fae:
                      plVar12 = (longlong *)0x0;
                      plVar11 = (longlong *)0x0;
                      plVar10 = (longlong *)0x0;
                      plStack_f0 = (longlong *)0x0;
                      pcStack_100 = (code *)0x0;
                      plVar13 = plStack_68;
                      goto LAB_23e83f2e0;
                    }
                    plVar12 = (longlong *)0x0;
                    plVar11 = (longlong *)0x0;
                    uVar20 = 0x1be;
                    plStack_f0 = (longlong *)0x0;
                    pcStack_100 = (code *)0x0;
                    goto LAB_23e83fdb0;
                  }
                }
                else {
                  plVar11[4] = lVar9;
                  plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar11);
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    FUN_23a334bc0(plVar11);
                  }
                  if (plVar10 != (longlong *)0x0) {
                    *(undefined4 *)(plVar1 + 5) = 0x1be;
                    plVar11 = (longlong *)FUN_23e914090(param_1,uVar6,plVar10);
                    lVar9 = *plVar10;
                    *plVar10 = lVar9 + -1;
                    if (lVar9 + -1 == 0) {
                      FUN_23a334bc0(plVar10);
                    }
                    if (plVar11 != (longlong *)0x0) {
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        FUN_23a334bc0(plVar11);
                      }
                      lVar9 = *(longlong *)_Py_NoneStruct_exref;
                      goto LAB_23e83e1a8;
                    }
                    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                    plStack_70 = *(longlong **)(param_1 + 0x68);
                    plStack_68 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto joined_r0x00023e842075;
                  }
                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  plStack_70 = *(longlong **)(param_1 + 0x68);
                  plStack_68 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  if (plStack_68 != (longlong *)0x0) {
                    if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e841fae;
                    plVar12 = (longlong *)0x0;
                    plVar11 = (longlong *)0x0;
                    plVar10 = (longlong *)0x0;
                    plStack_f0 = (longlong *)0x0;
                    uVar20 = 0x1be;
                    pcStack_100 = (code *)0x0;
                    goto LAB_23e83fdb0;
                  }
                }
                plVar12 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                plStack_f0 = (longlong *)0x0;
                plVar10 = (longlong *)0x0;
                pcStack_100 = (code *)0x0;
                uVar20 = 0x1be;
                goto LAB_23e8403f0;
              }
              uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
              plVar10 = _DAT_23eedc4c0;
              plVar11 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
              *plVar10 = *plVar10 + 1;
              plVar11[3] = (longlong)plVar10;
              lVar9 = FUN_23e94f9d0(param_1,plStack_e0,DAT_23ed6cd28);
              if (lVar9 == 0) {
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_70 = *(longlong **)(param_1 + 0x68);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  FUN_23a334bc0(plVar11);
                }
joined_r0x00023e84285a:
                if (plStack_68 != (longlong *)0x0) {
                  plVar10 = (longlong *)0x0;
                  if ((longlong *)plStack_68[3] != plVar1) {
                    plVar12 = (longlong *)0x0;
                    plVar11 = (longlong *)0x0;
                    plStack_f0 = (longlong *)0x0;
                    uVar20 = 0x1c1;
                    pcStack_100 = (code *)0x0;
                    goto LAB_23e83fdb0;
                  }
                  goto LAB_23e841fae;
                }
LAB_23e842832:
                plVar12 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                plStack_f0 = (longlong *)0x0;
                plVar10 = (longlong *)0x0;
                uVar20 = 0x1c1;
                pcStack_100 = (code *)0x0;
                goto LAB_23e8403f0;
              }
              plVar11[4] = lVar9;
              plVar10 = _DAT_23eedc4c8;
              *_DAT_23eedc4c8 = *_DAT_23eedc4c8 + 1;
              plVar11[5] = (longlong)plVar10;
              plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar11);
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                FUN_23a334bc0(plVar11);
              }
              if (plVar10 == (longlong *)0x0) {
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_70 = *(longlong **)(param_1 + 0x68);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_68 != (longlong *)0x0) {
                  if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e841fae;
                  plVar12 = (longlong *)0x0;
                  plVar11 = (longlong *)0x0;
                  plVar10 = (longlong *)0x0;
                  plStack_f0 = (longlong *)0x0;
                  uVar20 = 0x1c1;
                  pcStack_100 = (code *)0x0;
                  goto LAB_23e83fdb0;
                }
                goto LAB_23e842832;
              }
              *(undefined4 *)(plVar1 + 5) = 0x1c1;
              plVar11 = (longlong *)FUN_23e914090(param_1,uVar6,plVar10);
              lVar9 = *plVar10;
              *plVar10 = lVar9 + -1;
              if (lVar9 + -1 == 0) {
                FUN_23a334bc0(plVar10);
              }
              if (plVar11 == (longlong *)0x0) {
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_70 = *(longlong **)(param_1 + 0x68);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto joined_r0x00023e84285a;
              }
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                FUN_23a334bc0(plVar11);
              }
              lVar9 = *(longlong *)(DAT_23eedbeb8 + 0x20);
              if (*(char *)(lVar9 + 10) != '\0') {
                iVar5 = *(int *)(lVar9 + 0xc);
                if (*(int *)(lVar9 + 0xc) == 0) {
                  *(int *)(lVar9 + 0xc) = DAT_23ec1552c;
                  iVar5 = DAT_23ec1552c;
                  DAT_23ec1552c = DAT_23ec1552c + 1;
                }
                if (_DAT_23ec154f0 != iVar5) {
                  _DAT_23ec154f0 = iVar5;
                  _DAT_23eede3e8 =
                       FUN_23e8cbd60(lVar9,_DAT_23eedc4d0,*(undefined8 *)(_DAT_23eedc4d0 + 0x18));
                }
                if (-1 < _DAT_23eede3e8) {
                  lVar18 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
                  lVar19 = *(longlong *)(lVar18 + 8 + _DAT_23eede3e8 * 0x10);
                  if (lVar19 != 0) goto LAB_23e841480;
                  _DAT_23eede3e8 =
                       FUN_23e8cbd60(lVar9,_DAT_23eedc4d0,*(undefined8 *)(_DAT_23eedc4d0 + 0x18));
                  if (-1 < _DAT_23eede3e8) {
                    lVar19 = *(longlong *)(lVar18 + 8 + _DAT_23eede3e8 * 0x10);
                    goto LAB_23e8421dc;
                  }
                }
LAB_23e8421e5:
                plVar10 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedc4d0);
                if ((plVar10 != (longlong *)0x0) && (lVar19 = *plVar10, lVar19 != 0))
                goto LAB_23e841480;
                FUN_23e915740(param_1,auStack_78);
                if (plStack_68 != (longlong *)0x0) {
                  if ((longlong *)plStack_68[3] != plVar1) {
                    plVar12 = (longlong *)0x0;
                    plVar11 = (longlong *)0x0;
                    plStack_f0 = (longlong *)0x0;
                    plVar10 = (longlong *)0x0;
                    uVar20 = 0x1c4;
                    pcStack_100 = (code *)0x0;
                    goto LAB_23e83fdb0;
                  }
                  goto LAB_23e841fae;
                }
LAB_23e842272:
                plVar12 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                pcStack_100 = (code *)0x0;
                uVar20 = 0x1c4;
                plVar10 = (longlong *)0x0;
                plStack_f0 = (longlong *)0x0;
                goto LAB_23e8403f0;
              }
              plVar10 = (longlong *)FUN_23a37a020(DAT_23eedbeb8,_DAT_23eedc4d0);
              if (plVar10 == (longlong *)0x0) goto LAB_23e8421e5;
              lVar19 = *plVar10;
LAB_23e8421dc:
              if (lVar19 == 0) goto LAB_23e8421e5;
LAB_23e841480:
              plVar11 = (longlong *)FUN_23e8bd350(plStack_e0);
              if (plVar11 == (longlong *)0x0) {
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_70 = *(longlong **)(param_1 + 0x68);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_68 == (longlong *)0x0) goto LAB_23e842272;
                if ((longlong *)plStack_68[3] != plVar1) {
                  plVar12 = (longlong *)0x0;
                  plVar11 = (longlong *)0x0;
                  plVar10 = (longlong *)0x0;
                  plStack_f0 = (longlong *)0x0;
                  uVar20 = 0x1c4;
                  pcStack_100 = (code *)0x0;
                  goto LAB_23e83fdb0;
                }
                goto LAB_23e841fae;
              }
              *(undefined4 *)(plVar1 + 5) = 0x1c4;
              plStack_98 = plStack_e8;
              plStack_90 = plVar11;
              plVar10 = (longlong *)FUN_23e94ed00(param_1,lVar19,&plStack_98);
              lVar9 = *plVar11;
              *plVar11 = lVar9 + -1;
              if (lVar9 + -1 == 0) {
                FUN_23a334bc0(plVar11);
              }
              if (plVar10 == (longlong *)0x0) {
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_70 = *(longlong **)(param_1 + 0x68);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_68 != (longlong *)0x0) {
                  if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e841fae;
                  plVar12 = (longlong *)0x0;
                  plVar11 = (longlong *)0x0;
                  plStack_f0 = (longlong *)0x0;
                  uVar20 = 0x1c4;
                  pcStack_100 = (code *)0x0;
                  goto LAB_23e83fdb0;
                }
                goto LAB_23e842272;
              }
              uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
              *(undefined4 *)(plVar1 + 5) = 0x1c6;
              plVar11 = (longlong *)FUN_23e94bb80(param_1,uVar6,_DAT_23eedc4d8);
              if (plVar11 == (longlong *)0x0) {
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_70 = *(longlong **)(param_1 + 0x68);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_68 != (longlong *)0x0) {
                  if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e842fd0;
                  plVar12 = (longlong *)0x0;
                  pcStack_100 = (code *)0x0;
                  uVar20 = 0x1c6;
                  plStack_f0 = (longlong *)0x0;
                  plVar11 = (longlong *)0x0;
                  goto LAB_23e83fdb0;
                }
                plVar12 = (longlong *)0x0;
                uVar20 = 0x1c6;
                plStack_f0 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                pcStack_100 = (code *)0x0;
                goto LAB_23e8403f0;
              }
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                FUN_23a334bc0(plVar11);
              }
              FUN_23a3a0d40(DAT_23ed6cf28);
              *(undefined4 *)(plVar1 + 5) = 0x1c7;
              plVar11 = (longlong *)FUN_23e94bb80();
              if (plVar11 == (longlong *)0x0) {
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_70 = *(longlong **)(param_1 + 0x68);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_68 != (longlong *)0x0) {
                  if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e842fd0;
                  plVar12 = (longlong *)0x0;
                  plStack_f0 = (longlong *)0x0;
                  uVar20 = 0x1c7;
                  pcStack_100 = (code *)0x0;
                  plVar11 = (longlong *)0x0;
                  goto LAB_23e83fdb0;
                }
                plVar12 = (longlong *)0x0;
                uVar20 = 0x1c7;
                plStack_f0 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                pcStack_100 = (code *)0x0;
                goto LAB_23e8403f0;
              }
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                FUN_23a334bc0(plVar11);
              }
              FUN_23a3a0d40(DAT_23ed6cf28);
              *(undefined4 *)(plVar1 + 5) = 0x1c8;
              plVar11 = (longlong *)FUN_23e94bb80();
              if (plVar11 == (longlong *)0x0) {
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_70 = *(longlong **)(param_1 + 0x68);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_68 != (longlong *)0x0) {
                  if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e842fd0;
                  plVar12 = (longlong *)0x0;
                  plStack_f0 = (longlong *)0x0;
                  uVar20 = 0x1c8;
                  pcStack_100 = (code *)0x0;
                  plVar11 = (longlong *)0x0;
                  goto LAB_23e83fdb0;
                }
                plVar12 = (longlong *)0x0;
                uVar20 = 0x1c8;
                plStack_f0 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                pcStack_100 = (code *)0x0;
                goto LAB_23e8403f0;
              }
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                FUN_23a334bc0(plVar11);
              }
              uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
              *(undefined4 *)(plVar1 + 5) = 0x1c9;
              plVar11 = (longlong *)FUN_23e94bb80(param_1,uVar6,_DAT_23eedc4e8);
              if (plVar11 == (longlong *)0x0) {
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_70 = *(longlong **)(param_1 + 0x68);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_68 != (longlong *)0x0) {
                  if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e842fd0;
                  plVar12 = (longlong *)0x0;
                  plStack_f0 = (longlong *)0x0;
                  uVar20 = 0x1c9;
                  pcStack_100 = (code *)0x0;
                  plVar11 = (longlong *)0x0;
                  goto LAB_23e83fdb0;
                }
                uVar20 = 0x1c9;
                plStack_f0 = (longlong *)0x0;
                plVar12 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                pcStack_100 = (code *)0x0;
                goto LAB_23e8403f0;
              }
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                FUN_23a334bc0(plVar11);
              }
              uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
              *(undefined4 *)(plVar1 + 5) = 0x1ca;
              plVar11 = (longlong *)FUN_23e94bb80(param_1,uVar6,_DAT_23eedc4f0);
              if (plVar11 == (longlong *)0x0) {
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_70 = *(longlong **)(param_1 + 0x68);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_68 != (longlong *)0x0) {
                  if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e842fd0;
                  plVar12 = (longlong *)0x0;
                  uVar20 = 0x1ca;
                  plStack_f0 = (longlong *)0x0;
                  pcStack_100 = (code *)0x0;
                  plVar11 = (longlong *)0x0;
                  goto LAB_23e83fdb0;
                }
                plVar12 = (longlong *)0x0;
                plStack_f0 = (longlong *)0x0;
                uVar20 = 0x1ca;
                plVar11 = (longlong *)0x0;
                pcStack_100 = (code *)0x0;
                goto LAB_23e8403f0;
              }
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                FUN_23a334bc0(plVar11);
              }
              uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
              *(undefined4 *)(plVar1 + 5) = 0x1cb;
              plVar11 = (longlong *)FUN_23e94bb80(param_1,uVar6,_DAT_23eedc4f8);
              if (plVar11 == (longlong *)0x0) {
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_70 = *(longlong **)(param_1 + 0x68);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_68 != (longlong *)0x0) {
                  if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e842fd0;
                  plVar12 = (longlong *)0x0;
                  uVar20 = 0x1cb;
                  plStack_f0 = (longlong *)0x0;
                  pcStack_100 = (code *)0x0;
                  plVar11 = (longlong *)0x0;
                  goto LAB_23e83fdb0;
                }
                plVar12 = (longlong *)0x0;
                uVar20 = 0x1cb;
                plStack_f0 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                pcStack_100 = (code *)0x0;
                goto LAB_23e8403f0;
              }
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                FUN_23a334bc0(plVar11);
              }
              uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
              *(undefined4 *)(plVar1 + 5) = 0x1cc;
              plVar11 = (longlong *)FUN_23e94bb80(param_1,uVar6,_DAT_23eedc500);
              if (plVar11 == (longlong *)0x0) {
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_70 = *(longlong **)(param_1 + 0x68);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_68 != (longlong *)0x0) {
                  if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e842fd0;
                  plVar12 = (longlong *)0x0;
                  plStack_f0 = (longlong *)0x0;
                  uVar20 = 0x1cc;
                  pcStack_100 = (code *)0x0;
                  plVar11 = (longlong *)0x0;
                  goto LAB_23e83fdb0;
                }
                plVar12 = (longlong *)0x0;
                uVar20 = 0x1cc;
                plStack_f0 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                pcStack_100 = (code *)0x0;
                goto LAB_23e8403f0;
              }
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                FUN_23a334bc0(plVar11);
              }
              FUN_23a3a0d40(DAT_23ed6cf28);
              *(undefined4 *)(plVar1 + 5) = 0x1cd;
              plVar11 = (longlong *)FUN_23e94bb80();
              if (plVar11 == (longlong *)0x0) {
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_70 = *(longlong **)(param_1 + 0x68);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_68 != (longlong *)0x0) {
                  if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e842fd0;
                  plVar12 = (longlong *)0x0;
                  plStack_f0 = (longlong *)0x0;
                  uVar20 = 0x1cd;
                  pcStack_100 = (code *)0x0;
                  plVar11 = (longlong *)0x0;
                  goto LAB_23e83fdb0;
                }
                plVar12 = (longlong *)0x0;
                uVar20 = 0x1cd;
                plStack_f0 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                pcStack_100 = (code *)0x0;
                goto LAB_23e8403f0;
              }
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                FUN_23a334bc0(plVar11);
              }
              FUN_23a3a0d40(DAT_23ed6cf28);
              plVar11 = _DAT_23eedc510;
              plVar12 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
              *plVar11 = *plVar11 + 1;
              plVar12[3] = (longlong)plVar11;
              lVar9 = FUN_23e8db270();
              if (lVar9 == 0) {
                FUN_23e915740();
LAB_23e843121:
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  FUN_23a334bc0();
                }
                if (plStack_68 == (longlong *)0x0) {
LAB_23e8430d5:
                  plVar12 = (longlong *)0x0;
                  plVar11 = (longlong *)0x0;
                  plStack_f0 = (longlong *)0x0;
                  uVar20 = 0x1ce;
                  pcStack_100 = (code *)0x0;
                  goto LAB_23e8403f0;
                }
                if ((longlong *)plStack_68[3] == plVar1) {
LAB_23e842fd0:
                  plVar12 = (longlong *)0x0;
                  plVar11 = (longlong *)0x0;
                  plStack_f0 = (longlong *)0x0;
                  pcStack_100 = (code *)0x0;
                  plVar13 = plStack_68;
                  goto LAB_23e83f2e0;
                }
                plVar12 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                uVar20 = 0x1ce;
                plStack_f0 = (longlong *)0x0;
                pcStack_100 = (code *)0x0;
              }
              else {
                lVar9 = FUN_23e94f9d0();
                if (lVar9 == 0) {
                  plStack_68 = *(longlong **)(param_1 + 0x70);
                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  plStack_70 = *(longlong **)(param_1 + 0x68);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e843121;
                }
                plVar12[4] = lVar9;
                plVar11 = (longlong *)PyUnicode_Join();
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  FUN_23a334bc0();
                }
                if (plVar11 == (longlong *)0x0) {
                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  plStack_70 = *(longlong **)(param_1 + 0x68);
                  plStack_68 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  if (plStack_68 != (longlong *)0x0) {
                    if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e842fd0;
                    plVar12 = (longlong *)0x0;
                    uVar20 = 0x1ce;
                    plStack_f0 = (longlong *)0x0;
                    pcStack_100 = (code *)0x0;
                    plVar11 = (longlong *)0x0;
                    goto LAB_23e83fdb0;
                  }
                  goto LAB_23e8430d5;
                }
                *(undefined4 *)(plVar1 + 5) = 0x1ce;
                plVar12 = (longlong *)FUN_23e914090();
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  FUN_23a334bc0();
                }
                if (plVar12 != (longlong *)0x0) {
                  lVar9 = *plVar12;
                  *plVar12 = lVar9 + -1;
                  if (lVar9 + -1 == 0) {
                    FUN_23a334bc0(plVar12);
                  }
                  FUN_23a3a0d40(DAT_23ed6cf28);
                  *(undefined4 *)(plVar1 + 5) = 0x1cf;
                  plVar11 = (longlong *)FUN_23e94bb80();
                  if (plVar11 != (longlong *)0x0) {
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      FUN_23a334bc0(plVar11);
                    }
                    uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                    *(undefined4 *)(plVar1 + 5) = 0x1d0;
                    plVar11 = (longlong *)FUN_23e94bb80(param_1,uVar6,_DAT_23eedc430);
                    if (plVar11 != (longlong *)0x0) {
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        FUN_23a334bc0(plVar11);
                      }
                      plStack_f0 = (longlong *)0x0;
                      pcStack_100 = (code *)0x0;
                      plVar11 = (longlong *)0x0;
                      plVar12 = (longlong *)0x0;
LAB_23e84199d:
                      while( true ) {
                        *(undefined4 *)(plVar1 + 5) = 0x1d4;
                        pcVar14 = (code *)FUN_23e91bfe0(param_1,plVar7,_DAT_23eedc520);
                        if (pcVar14 == (code *)0x0) {
                          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          plStack_70 = *(longlong **)(param_1 + 0x68);
                          plStack_68 = *(longlong **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          uVar20 = 0x1d4;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          goto LAB_23e83fa42;
                        }
                        if ((pcStack_100 != (code *)0x0) &&
                           (*(longlong *)pcStack_100 = *(longlong *)pcStack_100 + -1,
                           *(longlong *)pcStack_100 == 0)) {
                          FUN_23a334bc0(pcStack_100);
                        }
                        pcStack_100 = pcVar14;
                        if (pcVar14 == _Py_NoneStruct_exref) break;
                        *(undefined4 *)(plVar1 + 5) = 0x1dc;
                        plVar13 = (longlong *)FUN_23e915840(param_1,plVar10,_DAT_23eedc550);
                        if (plVar13 == (longlong *)0x0) {
                          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          plStack_70 = *(longlong **)(param_1 + 0x68);
                          plStack_68 = *(longlong **)(param_1 + 0x70);
                          uVar20 = 0x1dc;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          goto LAB_23e83fa42;
                        }
                        if ((plVar11 != (longlong *)0x0) &&
                           (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                          FUN_23a334bc0(plVar11);
                        }
                        lVar9 = *(longlong *)(DAT_23eedbeb8 + 0x20);
                        plVar11 = plVar13;
                        if (*(char *)(lVar9 + 10) != '\0') {
                          iVar5 = *(int *)(lVar9 + 0xc);
                          if (*(int *)(lVar9 + 0xc) == 0) {
                            *(int *)(lVar9 + 0xc) = DAT_23ec1552c;
                            iVar5 = DAT_23ec1552c;
                            DAT_23ec1552c = DAT_23ec1552c + 1;
                          }
                          if (_DAT_23ec154f4 != iVar5) {
                            _DAT_23ec154f4 = iVar5;
                            _DAT_23eede3f0 =
                                 FUN_23e8cbd60(lVar9,_DAT_23eedc558,
                                               *(undefined8 *)(_DAT_23eedc558 + 0x18));
                          }
                          if (-1 < _DAT_23eede3f0) {
                            lVar18 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
                            if (*(longlong *)(lVar18 + 8 + _DAT_23eede3f0 * 0x10) != 0)
                            goto LAB_23e841abf;
                            _DAT_23eede3f0 =
                                 FUN_23e8cbd60(lVar9,_DAT_23eedc558,
                                               *(undefined8 *)(_DAT_23eedc558 + 0x18));
                            if (-1 < _DAT_23eede3f0) {
                              lVar9 = *(longlong *)(lVar18 + 8 + _DAT_23eede3f0 * 0x10);
                              goto LAB_23e842c27;
                            }
                          }
LAB_23e842c30:
                          plVar15 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedc558);
                          if ((plVar15 != (longlong *)0x0) && (*plVar15 != 0)) goto LAB_23e841abf;
                          FUN_23e915740(param_1,auStack_78,_DAT_23eedc558);
LAB_23e842bf5:
                          uVar20 = 0x1df;
                          goto LAB_23e83fa42;
                        }
                        plVar15 = (longlong *)FUN_23a37a020(DAT_23eedbeb8,_DAT_23eedc558);
                        if (plVar15 == (longlong *)0x0) goto LAB_23e842c30;
                        lVar9 = *plVar15;
LAB_23e842c27:
                        if (lVar9 == 0) goto LAB_23e842c30;
LAB_23e841abf:
                        *(undefined4 *)(plVar1 + 5) = 0x1df;
                        plVar15 = (longlong *)FUN_23e914090(param_1);
                        if (plVar15 == (longlong *)0x0) {
                          plStack_68 = *(longlong **)(param_1 + 0x70);
                          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          plStack_70 = *(longlong **)(param_1 + 0x68);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          goto LAB_23e842bf5;
                        }
                        if ((plVar12 != (longlong *)0x0) &&
                           (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
                          FUN_23a334bc0(plVar12);
                        }
                        plVar16 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23ed6ce40);
                        plVar12 = plVar15;
                        if (plVar16 == (longlong *)0x0) {
LAB_23e842b59:
                          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          plStack_70 = *(longlong **)(param_1 + 0x68);
                          plStack_68 = *(longlong **)(param_1 + 0x70);
                          uVar20 = 0x1e3;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          goto LAB_23e83fa42;
                        }
                        *(undefined4 *)(plVar1 + 5) = 0x1e3;
                        lVar9 = FUN_23e94bb80(param_1,plVar16,_DAT_23eedc560);
                        *plVar16 = *plVar16 + -1;
                        if (*plVar16 == 0) {
                          FUN_23a334bc0();
                        }
                        if (lVar9 == 0) goto LAB_23e842b59;
                        plVar16 = (longlong *)FUN_23e8d6340(*(undefined8 *)(param_1 + 0x10),5);
                        *(longlong *)plVar16[3] = lVar9;
                        plVar17 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23ed6ce40);
                        if (plVar17 == (longlong *)0x0) {
LAB_23e842b18:
                          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          plStack_70 = *(longlong **)(param_1 + 0x68);
                          plStack_68 = *(longlong **)(param_1 + 0x70);
                          uVar20 = 0x1e4;
LAB_23e842a4e:
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          *plVar16 = *plVar16 + -1;
                          if (*plVar16 == 0) {
                            FUN_23a334bc0();
                          }
                          goto LAB_23e83fa42;
                        }
                        *(undefined4 *)(plVar1 + 5) = 0x1e4;
                        lVar9 = FUN_23e94bb80(param_1,plVar17,_DAT_23eedc568);
                        *plVar17 = *plVar17 + -1;
                        if (*plVar17 == 0) {
                          FUN_23a334bc0(plVar17);
                        }
                        if (lVar9 == 0) goto LAB_23e842b18;
                        *(longlong *)(plVar16[3] + 8) = lVar9;
                        plVar17 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23ed6ce40);
                        if (plVar17 == (longlong *)0x0) {
LAB_23e842ad7:
                          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          plStack_70 = *(longlong **)(param_1 + 0x68);
                          plStack_68 = *(longlong **)(param_1 + 0x70);
                          uVar20 = 0x1e5;
                          goto LAB_23e842a4e;
                        }
                        *(undefined4 *)(plVar1 + 5) = 0x1e5;
                        lVar9 = FUN_23e94bb80(param_1,plVar17,_DAT_23eedc570);
                        *plVar17 = *plVar17 + -1;
                        if (*plVar17 == 0) {
                          FUN_23a334bc0(plVar17);
                        }
                        if (lVar9 == 0) goto LAB_23e842ad7;
                        *(longlong *)(plVar16[3] + 0x10) = lVar9;
                        plVar17 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23ed6ce40);
                        if (plVar17 == (longlong *)0x0) {
LAB_23e842a96:
                          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          plStack_70 = *(longlong **)(param_1 + 0x68);
                          plStack_68 = *(longlong **)(param_1 + 0x70);
                          uVar20 = 0x1e6;
                          goto LAB_23e842a4e;
                        }
                        *(undefined4 *)(plVar1 + 5) = 0x1e6;
                        lVar9 = FUN_23e94bb80(param_1,plVar17,_DAT_23eedc578);
                        *plVar17 = *plVar17 + -1;
                        if (*plVar17 == 0) {
                          FUN_23a334bc0(plVar17);
                        }
                        if (lVar9 == 0) goto LAB_23e842a96;
                        *(longlong *)(plVar16[3] + 0x18) = lVar9;
                        plVar13 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23ed6ce40);
                        if (plVar13 == (longlong *)0x0) {
LAB_23e842a12:
                          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          plStack_70 = *(longlong **)(param_1 + 0x68);
                          plStack_68 = *(longlong **)(param_1 + 0x70);
                          uVar20 = 0x1e7;
                          goto LAB_23e842a4e;
                        }
                        *(undefined4 *)(plVar1 + 5) = 0x1e7;
                        lVar9 = FUN_23e94bb80(param_1,plVar13,_DAT_23eedc580);
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          FUN_23a334bc0(plVar13);
                        }
                        if (lVar9 == 0) goto LAB_23e842a12;
                        *(longlong *)(plVar16[3] + 0x20) = lVar9;
                        plVar13 = (longlong *)FUN_23e8bd690(param_1);
                        *plVar16 = *plVar16 + -1;
                        if (*plVar16 == 0) {
                          FUN_23a334bc0(plVar16);
                        }
                        if (plVar13 == (longlong *)0x0) {
                          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          plStack_70 = *(longlong **)(param_1 + 0x68);
                          plStack_68 = *(longlong **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          uVar20 = 0x1e2;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          goto LAB_23e83fa42;
                        }
                        if ((plStack_f0 != (longlong *)0x0) &&
                           (*plStack_f0 = *plStack_f0 + -1, *plStack_f0 == 0)) {
                          FUN_23a334bc0(plStack_f0);
                        }
                        iVar5 = FUN_23a35f020(plVar13);
                        plStack_f0 = plVar13;
                        if (iVar5 == 1) {
                          uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                          plVar13 = _DAT_23eedc588;
                          plVar16 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                          *plVar13 = *plVar13 + 1;
                          plVar16[3] = (longlong)plVar13;
                          lVar9 = FUN_23e94f9d0(param_1,plVar15,DAT_23ed6cd28);
                          if (lVar9 == 0) {
                            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                            plStack_70 = *(longlong **)(param_1 + 0x68);
                            plStack_68 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *plVar16 = *plVar16 + -1;
                            if (*plVar16 == 0) {
                              FUN_23a334bc0(plVar16);
                            }
                          }
                          else {
                            plVar16[4] = lVar9;
                            plVar13 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
                            *plVar16 = *plVar16 + -1;
                            if (*plVar16 == 0) {
                              FUN_23a334bc0(plVar16);
                            }
                            if (plVar13 != (longlong *)0x0) {
                              *(undefined4 *)(plVar1 + 5) = 0x1eb;
                              plVar15 = (longlong *)FUN_23e914090(param_1,uVar6,plVar13);
                              *plVar13 = *plVar13 + -1;
                              if (*plVar13 == 0) {
                                FUN_23a334bc0(plVar13);
                              }
                              if (plVar15 != (longlong *)0x0) goto LAB_23e841e28;
                            }
                            plStack_68 = *(longlong **)(param_1 + 0x70);
                            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                            plStack_70 = *(longlong **)(param_1 + 0x68);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          }
                          uVar20 = 0x1eb;
                          goto LAB_23e83fa42;
                        }
                        uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                        plVar13 = _DAT_23eedc588;
                        plVar16 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                        *plVar13 = *plVar13 + 1;
                        plVar16[3] = (longlong)plVar13;
                        lVar9 = FUN_23e94f9d0(param_1,plVar15,DAT_23ed6cd28);
                        if (lVar9 == 0) {
                          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          plStack_70 = *(longlong **)(param_1 + 0x68);
                          plStack_68 = *(longlong **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          *plVar16 = *plVar16 + -1;
                          if (*plVar16 == 0) {
                            FUN_23a334bc0(plVar16);
                          }
LAB_23e84275c:
                          uVar20 = 0x1ed;
                          goto LAB_23e83fa42;
                        }
                        plVar16[4] = lVar9;
                        lVar9 = PyUnicode_Join(DAT_23ed6cd28,plVar16);
                        *plVar16 = *plVar16 + -1;
                        if (*plVar16 == 0) {
                          FUN_23a334bc0(plVar16);
                        }
                        if (lVar9 == 0) {
LAB_23e84271a:
                          plStack_68 = *(longlong **)(param_1 + 0x70);
                          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          plStack_70 = *(longlong **)(param_1 + 0x68);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          goto LAB_23e84275c;
                        }
                        plVar13 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),1);
                        uVar3 = _DAT_23eedc590;
                        plVar13[3] = lVar9;
                        plVar16 = (longlong *)FUN_23e8d7870(param_1,uVar3);
                        *(undefined4 *)(plVar1 + 5) = 0x1ed;
                        plVar15 = (longlong *)FUN_23a334c60(param_1,uVar6,plVar13);
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          FUN_23a334bc0(plVar13);
                        }
                        *plVar16 = *plVar16 + -1;
                        if (*plVar16 == 0) {
                          FUN_23a334bc0(plVar16);
                        }
                        if (plVar15 == (longlong *)0x0) goto LAB_23e84271a;
LAB_23e841e28:
                        *plVar15 = *plVar15 + -1;
                        if (*plVar15 == 0) {
                          FUN_23a334bc0(plVar15);
                        }
                        cVar4 = FUN_23a3a5fe0(param_1);
                        if (cVar4 == '\0') goto LAB_23e83f9ea;
                      }
                      uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
                      *(undefined4 *)(plVar1 + 5) = 0x1d7;
                      plVar13 = (longlong *)FUN_23e939610(param_1,uVar6,_DAT_23eedc528 + 0x18);
                      if (plVar13 == (longlong *)0x0) {
                        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                        plStack_70 = *(longlong **)(param_1 + 0x68);
                        plStack_68 = *(longlong **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar20 = 0x1d7;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23e83fa42;
                      }
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        FUN_23a334bc0(plVar13);
                      }
                      lVar9 = FUN_23e8db3c0();
                      if (lVar9 == 0) {
                        FUN_23e915740(param_1,auStack_78,_DAT_23eedc100);
                      }
                      else {
                        *(undefined4 *)(plVar1 + 5) = 0x1d8;
                        plVar13 = (longlong *)FUN_23e915840(param_1,lVar9,_DAT_23eedc538);
                        if (plVar13 != (longlong *)0x0) {
                          *plVar13 = *plVar13 + -1;
                          if (*plVar13 == 0) {
                            FUN_23a334bc0(plVar13);
                          }
                          goto LAB_23e84199d;
                        }
                        plStack_68 = *(longlong **)(param_1 + 0x70);
                        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                        plStack_70 = *(longlong **)(param_1 + 0x68);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      }
                      uVar20 = 0x1d8;
                      pcStack_100 = _Py_NoneStruct_exref;
                      goto LAB_23e83fa42;
                    }
                    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                    plStack_70 = *(longlong **)(param_1 + 0x68);
                    plStack_68 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (plStack_68 != (longlong *)0x0) {
                      if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e842fd0;
                      plVar12 = (longlong *)0x0;
                      uVar20 = 0x1d0;
                      plStack_f0 = (longlong *)0x0;
                      pcStack_100 = (code *)0x0;
                      plVar11 = (longlong *)0x0;
                      goto LAB_23e83fdb0;
                    }
                    plVar12 = (longlong *)0x0;
                    uVar20 = 0x1d0;
                    plStack_f0 = (longlong *)0x0;
                    plVar11 = (longlong *)0x0;
                    pcStack_100 = (code *)0x0;
                    goto LAB_23e8403f0;
                  }
                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  plStack_70 = *(longlong **)(param_1 + 0x68);
                  plStack_68 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  if (plStack_68 == (longlong *)0x0) {
                    plVar12 = (longlong *)0x0;
                    uVar20 = 0x1cf;
                    plStack_f0 = (longlong *)0x0;
                    plVar11 = (longlong *)0x0;
                    pcStack_100 = (code *)0x0;
                    goto LAB_23e8403f0;
                  }
                  if ((longlong *)plStack_68[3] != plVar1) {
                    uVar20 = 0x1cf;
                    plStack_f0 = (longlong *)0x0;
                    plVar12 = (longlong *)0x0;
                    pcStack_100 = (code *)0x0;
                    plVar11 = (longlong *)0x0;
                    goto LAB_23e83fdb0;
                  }
                  goto LAB_23e842fd0;
                }
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_70 = *(longlong **)(param_1 + 0x68);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_68 == (longlong *)0x0) goto LAB_23e8430d5;
                if ((longlong *)plStack_68[3] == plVar1) goto LAB_23e842fd0;
                plVar12 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                plStack_f0 = (longlong *)0x0;
                uVar20 = 0x1ce;
                pcStack_100 = (code *)0x0;
              }
              goto LAB_23e83fdb0;
            }
            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
            plStack_70 = *(longlong **)(param_1 + 0x68);
            plStack_68 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (plStack_68 != (longlong *)0x0) {
              if ((longlong *)plStack_68[3] != plVar1) {
                plVar12 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                plStack_f0 = (longlong *)0x0;
                uVar20 = 0x1b8;
                pcStack_100 = (code *)0x0;
                plStack_e0 = (longlong *)0x0;
                plVar10 = (longlong *)0x0;
                goto LAB_23e83fdb0;
              }
              goto LAB_23e840fe3;
            }
LAB_23e841126:
            plVar11 = (longlong *)0x0;
            plVar10 = (longlong *)0x0;
            pcStack_100 = (code *)0x0;
            uVar20 = 0x1b8;
            plStack_f0 = (longlong *)0x0;
            plVar12 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            goto LAB_23e8403f0;
          }
LAB_23e840f57:
          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
          plStack_70 = *(longlong **)(param_1 + 0x68);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            FUN_23a334bc0(plVar11);
          }
          if (plStack_68 == (longlong *)0x0) goto LAB_23e841126;
          if (plVar1 == (longlong *)plStack_68[3]) goto LAB_23e840fe3;
          plVar12 = (longlong *)0x0;
          pcStack_100 = (code *)0x0;
          plVar11 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          uVar20 = 0x1b8;
          plStack_f0 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
        }
        else {
          iVar5 = *(int *)(lVar9 + 0xc);
          if (*(int *)(lVar9 + 0xc) == 0) {
            *(int *)(lVar9 + 0xc) = DAT_23ec1552c;
            iVar5 = DAT_23ec1552c;
            DAT_23ec1552c = DAT_23ec1552c + 1;
          }
          if (_DAT_23ec154e8 != iVar5) {
            _DAT_23ec154e8 = iVar5;
            _DAT_23eede3d8 =
                 FUN_23e8cbd60(lVar9,_DAT_23eedc488,*(undefined8 *)(_DAT_23eedc488 + 0x18));
          }
          if (-1 < _DAT_23eede3d8) {
            lVar19 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
            lVar18 = *(longlong *)(lVar19 + 8 + _DAT_23eede3d8 * 0x10);
            if (lVar18 != 0) goto LAB_23e83ea7a;
            _DAT_23eede3d8 =
                 FUN_23e8cbd60(lVar9,_DAT_23eedc488,*(undefined8 *)(_DAT_23eedc488 + 0x18));
            if (-1 < _DAT_23eede3d8) {
              lVar18 = *(longlong *)(lVar19 + 8 + _DAT_23eede3d8 * 0x10);
              goto LAB_23e840954;
            }
          }
LAB_23e84095d:
          plVar10 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedc488);
          if ((plVar10 != (longlong *)0x0) && (lVar18 = *plVar10, lVar18 != 0)) goto LAB_23e83ea7a;
          FUN_23e915740(param_1,auStack_78,_DAT_23eedc488);
          plVar10 = plStack_68;
          auVar21 = auStack_78;
          plVar12 = plStack_70;
LAB_23e8409c0:
          plStack_68 = plVar10;
          auStack_78 = auVar21;
          plStack_70 = plVar12;
          if (plVar10 == (longlong *)0x0) {
            pcStack_100 = (code *)0x0;
            plVar12 = (longlong *)0x0;
            plVar10 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            uVar20 = 0x1b6;
            plStack_e0 = (longlong *)0x0;
            plStack_e8 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            goto LAB_23e8403f0;
          }
          if ((longlong *)plVar10[3] == plVar1) goto LAB_23e840cb0;
          pcStack_100 = (code *)0x0;
          plVar12 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          uVar20 = 0x1b6;
          plStack_e0 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
        }
      }
    }
LAB_23e83fdb0:
    plVar15 = plStack_68;
    plVar13 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar16 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar16;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar13[3] = (longlong)plVar1;
    *plVar1 = *plVar1 + 1;
    lVar9 = *(longlong *)(pcStack_d8 + 0x1f8);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar20;
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
    lVar18 = plVar13[-1];
    puVar2 = *(undefined8 **)(lVar9 + 8);
    *puVar2 = plVar13 + -2;
    plVar13[-2] = lVar9;
    plVar13[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar9 + 8) = plVar13 + -2;
    plVar13[2] = (longlong)plVar15;
    *plVar15 = *plVar15 + 1;
    plVar15 = plStack_68;
  }
  if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
    (**(code **)(plVar15[1] + 0x30))();
  }
LAB_23e83f2e0:
  plStack_68 = plVar13;
  FUN_23e8bba40(plVar1,"ooooooooooo",plVar7,plVar8,plStack_108,plStack_f8,plStack_e8,plStack_e0,
                plVar10,pcStack_100,plVar11,plVar12,plStack_f0);
  if (_DAT_23eede400 == plVar1) {
    *plVar1 = *plVar1 + -1;
    if (*plVar1 == 0) {
      (**(code **)(plVar1[1] + 0x30))(plVar1);
    }
    _DAT_23eede400 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar1 = *(longlong **)(lVar9 + 0x28);
  plVar13 = (longlong *)plVar1[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
  *(undefined4 *)(plVar1 + 8) = 0xffffffff;
  if (plVar13 != (longlong *)0x0) {
    plVar1[2] = 0;
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))();
    }
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  plVar15 = plStack_68;
  plVar13 = plStack_70;
  auVar21 = auStack_78;
  plVar1[0xf] = 0;
  _auStack_78 = (undefined1  [16])0x0;
  plStack_68 = (longlong *)0x0;
  if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plStack_108 != (longlong *)0x0) &&
     (lVar9 = *plStack_108, *plStack_108 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_108[1] + 0x30))(plStack_108);
  }
  if ((plStack_f8 != (longlong *)0x0) &&
     (lVar9 = *plStack_f8, *plStack_f8 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_f8[1] + 0x30))();
  }
  if ((plStack_e8 != (longlong *)0x0) &&
     (lVar9 = *plStack_e8, *plStack_e8 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
  }
  if ((plStack_e0 != (longlong *)0x0) &&
     (lVar9 = *plStack_e0, *plStack_e0 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_e0[1] + 0x30))();
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((pcStack_100 != (code *)0x0) &&
     (lVar9 = *(longlong *)pcStack_100, *(longlong *)pcStack_100 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(*(longlong *)(pcStack_100 + 8) + 0x30))(pcStack_100);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar12 != (longlong *)0x0) && (lVar9 = *plVar12, *plVar12 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plStack_f0 != (longlong *)0x0) &&
     (lVar9 = *plStack_f0, *plStack_f0 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_f0[1] + 0x30))(plStack_f0);
  }
  _auStack_78 = CONCAT88(plVar13,auVar21);
  plStack_68 = plVar15;
  FUN_23a33aa70(param_1,auVar21,plVar13,plVar15);
  return (code *)0x0;
LAB_23e83f9ea:
  plStack_68 = *(longlong **)(param_1 + 0x70);
  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
  plStack_70 = *(longlong **)(param_1 + 0x68);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar20 = 0x1d3;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e83fa42:
  plVar13 = plStack_68;
  plStack_68 = (longlong *)0x0;
  plStack_88 = plVar13;
  plVar15 = *(longlong **)(param_1 + 0x138);
  plStack_98 = (longlong *)auStack_78;
  plStack_90 = plStack_70;
  auStack_78 = (undefined1  [8])0x0;
  plStack_70 = (longlong *)0x0;
  if (plVar15 != (longlong *)0x0) {
    *plVar15 = *plVar15 + 1;
  }
  if (plVar13 == (longlong *)0x0) {
    lVar9 = FUN_23e8d6280(plVar1,uVar20);
    if ((plStack_88 != (longlong *)0x0) && (*plStack_88 = *plStack_88 + -1, *plStack_88 == 0)) {
      FUN_23a334bc0();
    }
  }
  else {
    lVar9 = FUN_23e8d6280(plVar1,uVar20);
    *(longlong **)(lVar9 + 0x10) = plVar13;
    *plVar13 = *plVar13 + 1;
    if ((plStack_88 != (longlong *)0x0) && (*plStack_88 = *plStack_88 + -1, *plStack_88 == 0)) {
      FUN_23a334bc0();
    }
  }
  plStack_88 = (longlong *)lVar9;
  FUN_23a35ef40(param_1,&plStack_98);
  iVar5 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                        *(undefined8 *)PyExc_KeyboardInterrupt_exref);
  if (iVar5 == 0) {
    cVar4 = FUN_23e8ba320(*(undefined8 *)(param_1 + 0x138),auStack_78);
    plVar13 = plStack_68;
    iStack_d0 = 0;
    if (cVar4 == '\0') {
      iStack_d0 = 0x1d2;
    }
    if (plStack_68 == (longlong *)0x0) {
      uVar20 = 0x1d2;
      _auStack_78 = (undefined1  [16])0x0;
      FUN_23ebf6ae0(param_1);
      plStack_68 = (longlong *)0x0;
      if (iStack_d0 == 0) {
        uVar20 = (undefined4)plVar1[5];
      }
      goto LAB_23e8403f0;
    }
    if ((longlong *)plStack_68[3] == plVar1) {
      *(undefined4 *)(plVar1 + 5) = *(undefined4 *)((longlong)plStack_68 + 0x24);
    }
    plStack_68 = (longlong *)0x0;
    _auStack_78 = (undefined1  [16])0x0;
    FUN_23ebf6ae0(param_1,plVar15);
    if ((longlong *)plVar13[3] == plVar1) goto LAB_23e83f2e0;
    plStack_68 = plVar13;
    if (iStack_d0 == 0) {
      uVar20 = (undefined4)plVar1[5];
    }
    else {
      uVar20 = 0x1d2;
    }
    goto LAB_23e83fdb0;
  }
  uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
  *(undefined4 *)(plVar1 + 5) = 0x1f2;
  plVar13 = (longlong *)FUN_23e94bb80(param_1,uVar6,_DAT_23eedc598);
  if (plVar13 == (longlong *)0x0) {
    plVar13 = *(longlong **)(param_1 + 0x70);
    plVar16 = *(longlong **)(param_1 + 0x60);
    plVar17 = *(longlong **)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_68 = (longlong *)0x0;
    _auStack_78 = (undefined1  [16])0x0;
    FUN_23ebf6ae0(param_1,plVar15);
    plStack_68 = plVar13;
    auStack_78 = (undefined1  [8])plVar16;
    plStack_70 = plVar17;
    if (plVar13 != (longlong *)0x0) {
      if (plVar1 == (longlong *)plVar13[3]) goto LAB_23e83f2e0;
      uVar20 = 0x1f2;
      goto LAB_23e83fdb0;
    }
    uVar20 = 0x1f2;
    goto LAB_23e8403f0;
  }
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    FUN_23a334bc0(plVar13);
  }
  FUN_23ebf6ae0(param_1,plVar15);
  uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
  *(undefined4 *)(plVar1 + 5) = 500;
  plVar13 = (longlong *)FUN_23e94bb80(param_1,uVar6);
  if (plVar13 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    plStack_70 = *(longlong **)(param_1 + 0x68);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (plStack_68 != (longlong *)0x0) {
      uVar20 = 500;
      plVar15 = (longlong *)plStack_68[3];
joined_r0x00023e842423:
      plVar13 = plStack_68;
      if (plVar15 == plVar1) goto LAB_23e83f2e0;
      goto LAB_23e83fdb0;
    }
    uVar20 = 500;
    goto LAB_23e8403f0;
  }
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    FUN_23a334bc0(plVar13);
  }
  uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
  *(undefined4 *)(plVar1 + 5) = 0x1f5;
  plVar13 = (longlong *)FUN_23e94bb80(param_1,uVar6,_DAT_23eedc5a0);
  if (plVar13 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    plStack_70 = *(longlong **)(param_1 + 0x68);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (plStack_68 != (longlong *)0x0) {
      uVar20 = 0x1f5;
      plVar15 = (longlong *)plStack_68[3];
      goto joined_r0x00023e842423;
    }
    uVar20 = 0x1f5;
    goto LAB_23e8403f0;
  }
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    FUN_23a334bc0();
  }
  uVar6 = FUN_23a3a0d40(DAT_23ed6cf28);
  *(undefined4 *)(plVar1 + 5) = 0x1f6;
  plVar13 = (longlong *)FUN_23e94bb80(param_1,uVar6,_DAT_23eedc430);
  if (plVar13 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    plStack_70 = *(longlong **)(param_1 + 0x68);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (plStack_68 != (longlong *)0x0) {
      uVar20 = 0x1f6;
      plVar15 = (longlong *)plStack_68[3];
      goto joined_r0x00023e842423;
    }
    uVar20 = 0x1f6;
    goto LAB_23e8403f0;
  }
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    FUN_23a334bc0(plVar13);
  }
  FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
  pcVar14 = _Py_NoneStruct_exref;
  *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
LAB_23e83e22e:
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) goto LAB_23e83fd20;
LAB_23e83e23c:
    if (plStack_108 == (longlong *)0x0) goto LAB_23e83e264;
  }
  else {
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
LAB_23e83fd20:
      (**(code **)(plVar8[1] + 0x30))(plVar8);
      goto LAB_23e83e23c;
    }
  }
  lVar9 = *plStack_108;
  *plStack_108 = lVar9 + -1;
  if (lVar9 + -1 == 0) {
    (**(code **)(plStack_108[1] + 0x30))(plStack_108);
  }
LAB_23e83e264:
  if ((plStack_f8 != (longlong *)0x0) &&
     (lVar9 = *plStack_f8, *plStack_f8 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
  }
  if ((plStack_e8 != (longlong *)0x0) &&
     (lVar9 = *plStack_e8, *plStack_e8 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
  }
  if ((plStack_e0 != (longlong *)0x0) &&
     (lVar9 = *plStack_e0, *plStack_e0 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((pcStack_100 != (code *)0x0) &&
     (lVar9 = *(longlong *)pcStack_100, *(longlong *)pcStack_100 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(*(longlong *)(pcStack_100 + 8) + 0x30))(pcStack_100);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar12 != (longlong *)0x0) && (lVar9 = *plVar12, *plVar12 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if (plStack_f0 == (longlong *)0x0) {
    return pcVar14;
  }
  lVar9 = *plStack_f0;
  *plStack_f0 = lVar9 + -1;
  if (lVar9 + -1 != 0) {
    return pcVar14;
  }
  (**(code **)(plStack_f0[1] + 0x30))(plStack_f0);
  return pcVar14;
}
