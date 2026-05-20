/* ===== 23e7acc60 workers.fishing.hooking:83 ===== */
/* ghidra_name=FUN_23e7acc60 entry=23e7acc60 size=11396 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

code * FUN_23e7acc60(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  code *pcVar17;
  code *pcVar18;
  code *pcVar19;
  longlong *plVar20;
  longlong lVar21;
  undefined4 uVar22;
  undefined1 auVar23 [8];
  code *pcStack_138;
  longlong *plStack_130;
  longlong *plStack_128;
  code *pcStack_120;
  longlong *plStack_118;
  longlong *plStack_110;
  longlong *plStack_108;
  code *pcStack_100;
  code *pcStack_f0;
  longlong *plStack_c0;
  undefined1 auStack_b8 [8];
  code *pcStack_b0;
  code *pcStack_a8;
  undefined1 auStack_98 [16];
  code *pcStack_88;
  undefined8 uStack_80;
  longlong *plStack_78;
  
  plVar8 = _DAT_23eedab28;
  plVar1 = (longlong *)*param_3;
  pcStack_a8 = (code *)0x0;
  auStack_b8 = (undefined1  [8])0x0;
  pcStack_b0 = (code *)0x0;
  if (_DAT_23eedab28 == (longlong *)0x0) {
LAB_23e7accc5:
    _DAT_23eedab28 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedab20,DAT_23eedab78,0x78);
  }
  else {
    lVar9 = *_DAT_23eedab28;
    if (1 < lVar9) {
      *_DAT_23eedab28 = lVar9 + -1;
      goto LAB_23e7accc5;
    }
    if (_DAT_23eedab28[2] != 0) {
      *_DAT_23eedab28 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e7accc5;
    }
  }
  plVar20 = _DAT_23eedab28;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eedab28 + 9;
  lVar2 = *(longlong *)(lVar9 + 8);
  _DAT_23eedab28[0xf] = lVar2;
  *(longlong **)(lVar9 + 8) = plVar8;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar20[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar20[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar20 = *plVar20 + 1;
  uVar3 = DAT_23eed7968;
  *(undefined4 *)(plVar20 + 8) = 0;
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar3);
  if (plVar8 == (longlong *)0x0) {
LAB_23e7add60:
    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_b0 = *(code **)(param_1 + 0x68);
    pcStack_a8 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcStack_a8 == (code *)0x0) goto LAB_23e7ae700;
    plVar8 = *(longlong **)(pcStack_a8 + 0x18);
joined_r0x00023e7aed3c:
    if (plVar8 == plVar20) {
      pcStack_138 = (code *)0x0;
      plVar12 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      pcStack_120 = (code *)0x0;
      plStack_110 = (longlong *)0x0;
      pcStack_100 = (code *)0x0;
      plStack_108 = (longlong *)0x0;
      pcVar17 = pcStack_a8;
      goto LAB_23e7adee6;
    }
    plVar11 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    pcStack_100 = (code *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    pcStack_138 = (code *)0x0;
    plVar13 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    uVar22 = 0x55;
    pcStack_f0 = _PyRuntime_exref;
LAB_23e7ade2b:
    pcVar18 = pcStack_a8;
    pcVar17 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar19 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar19;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar17 + 0x18) = plVar20;
    *plVar20 = *plVar20 + 1;
    lVar9 = *(longlong *)(pcStack_f0 + 0x1f8);
    *(undefined4 *)(pcVar17 + 0x24) = uVar22;
    *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
    lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
    lVar2 = *(longlong *)(pcVar17 + -8);
    plVar14 = *(longlong **)(lVar9 + 8);
    *plVar14 = (longlong)(pcVar17 + -0x10);
    *(longlong *)(pcVar17 + -0x10) = lVar9;
    *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)plVar14;
    *(code **)(lVar9 + 8) = pcVar17 + -0x10;
    *(code **)(pcVar17 + 0x10) = pcVar18;
    *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
    if ((pcStack_a8 != (code *)0x0) &&
       (*(longlong *)pcStack_a8 = *(longlong *)pcStack_a8 + -1, *(longlong *)pcStack_a8 == 0)) {
      (**(code **)(*(longlong *)(pcStack_a8 + 8) + 0x30))(pcStack_a8);
    }
    goto LAB_23e7adee6;
  }
  iVar6 = FUN_23a35f020(plVar8);
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if (iVar6 == -1) {
LAB_23e7ae5e0:
    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_b0 = *(code **)(param_1 + 0x68);
    pcStack_a8 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcStack_a8 != (code *)0x0) {
      plVar8 = *(longlong **)(pcStack_a8 + 0x18);
      goto joined_r0x00023e7aed3c;
    }
    goto LAB_23e7ae700;
  }
  if (iVar6 == 0) {
LAB_23e7acd88:
    pcVar17 = _Py_NoneStruct_exref;
    plVar8 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    pcStack_138 = (code *)0x0;
    plVar11 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
    plStack_130 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_110 = (longlong *)0x0;
    pcStack_100 = (code *)0x0;
    plStack_108 = (longlong *)0x0;
LAB_23e7ace00:
    lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar20 = *(longlong **)(lVar9 + 0x28);
    plVar14 = (longlong *)plVar20[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
    *(undefined4 *)(plVar20 + 8) = 0xffffffff;
    if (plVar14 != (longlong *)0x0) {
      plVar20[2] = 0;
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))();
      }
    }
    *plVar20 = *plVar20 + -1;
    if (*plVar20 == 0) {
      (**(code **)(plVar20[1] + 0x30))(plVar20);
    }
    plVar20[0xf] = 0;
    if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar11 != (longlong *)0x0) {
LAB_23e7ace9e:
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
LAB_23e7acea5:
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
    }
    if (plVar12 == (longlong *)0x0) goto LAB_23e7acec6;
LAB_23e7aceb5:
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
LAB_23e7acec6:
    if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if ((plStack_108 != (longlong *)0x0) &&
       (lVar9 = *plStack_108, *plStack_108 = lVar9 + -1, lVar9 + -1 == 0)) {
      (**(code **)(plStack_108[1] + 0x30))(plStack_108);
    }
    if ((pcStack_100 != (code *)0x0) &&
       (lVar9 = *(longlong *)pcStack_100, *(longlong *)pcStack_100 = lVar9 + -1, lVar9 + -1 == 0)) {
      (**(code **)(*(longlong *)(pcStack_100 + 8) + 0x30))(pcStack_100);
    }
    if ((plStack_110 != (longlong *)0x0) &&
       (lVar9 = *plStack_110, *plStack_110 = lVar9 + -1, lVar9 + -1 == 0)) {
      (**(code **)(plStack_110[1] + 0x30))(plStack_110);
    }
    if ((pcStack_120 != (code *)0x0) &&
       (lVar9 = *(longlong *)pcStack_120, *(longlong *)pcStack_120 = lVar9 + -1, lVar9 + -1 == 0)) {
      (**(code **)(*(longlong *)(pcStack_120 + 8) + 0x30))(pcStack_120);
    }
    if ((plStack_118 != (longlong *)0x0) &&
       (lVar9 = *plStack_118, *plStack_118 = lVar9 + -1, lVar9 + -1 == 0)) {
      (**(code **)(plStack_118[1] + 0x30))(plStack_118);
    }
    if ((plStack_128 != (longlong *)0x0) &&
       (lVar9 = *plStack_128, *plStack_128 = lVar9 + -1, lVar9 + -1 == 0)) {
      (**(code **)(plStack_128[1] + 0x30))(plStack_128);
    }
    if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if ((plStack_130 != (longlong *)0x0) &&
       (lVar9 = *plStack_130, *plStack_130 = lVar9 + -1, lVar9 + -1 == 0)) {
      (**(code **)(plStack_130[1] + 0x30))(plStack_130);
    }
    if ((pcStack_138 != (code *)0x0) &&
       (lVar9 = *(longlong *)pcStack_138, *(longlong *)pcStack_138 = lVar9 + -1, lVar9 + -1 == 0)) {
      (**(code **)(*(longlong *)(pcStack_138 + 8) + 0x30))(pcStack_138);
    }
    *plVar1 = *plVar1 + -1;
    if (*plVar1 != 0) {
      return pcVar17;
    }
    (**(code **)(plVar1[1] + 0x30))(plVar1);
    return pcVar17;
  }
  lVar9 = FUN_23e8df2f0();
  if (lVar9 == 0) {
    FUN_23e915740(param_1,auStack_b8,DAT_23eed7980);
    if (pcStack_a8 != (code *)0x0) {
      plVar8 = *(longlong **)(pcStack_a8 + 0x18);
      goto joined_r0x00023e7aed3c;
    }
    goto LAB_23e7ae700;
  }
  plVar8 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eed79d8);
  if (plVar8 == (longlong *)0x0) goto LAB_23e7add60;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed7968);
  if (plVar10 == (longlong *)0x0) {
    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_b0 = *(code **)(param_1 + 0x68);
    pcStack_a8 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (pcStack_a8 != (code *)0x0) {
      plVar8 = *(longlong **)(pcStack_a8 + 0x18);
      goto joined_r0x00023e7aed3c;
    }
LAB_23e7ae700:
    plVar8 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    pcStack_138 = (code *)0x0;
    plVar11 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    uVar22 = 0x55;
    plStack_130 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_110 = (longlong *)0x0;
    pcStack_100 = (code *)0x0;
    plStack_108 = (longlong *)0x0;
    pcStack_f0 = _PyRuntime_exref;
  }
  else {
    *(undefined4 *)(plVar20 + 5) = 0x55;
    plVar11 = (longlong *)FUN_23e914090(param_1,plVar8,plVar10);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar11 == (longlong *)0x0) {
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_b0 = *(code **)(param_1 + 0x68);
      pcStack_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcStack_a8 != (code *)0x0) {
        plVar8 = *(longlong **)(pcStack_a8 + 0x18);
        goto joined_r0x00023e7aed3c;
      }
      goto LAB_23e7ae700;
    }
    uVar7 = FUN_23a35f020(plVar11);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (uVar7 == 0xffffffff) goto LAB_23e7ae5e0;
    if ((uVar7 & 1) == 0) goto LAB_23e7acd88;
    lVar9 = FUN_23e8df2f0();
    if (lVar9 != 0) {
      plVar8 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eed79e8);
      if (plVar8 == (longlong *)0x0) goto LAB_23e7ae208;
      plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed7968);
      if (plVar10 == (longlong *)0x0) {
        pcStack_138 = *(code **)(param_1 + 0x70);
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar8 = *plVar8 + -1;
        auVar23 = auStack_b8;
        pcVar17 = pcStack_b0;
        if (*plVar8 == 0) {
          pcStack_a8 = pcStack_138;
          (**(code **)(plVar8[1] + 0x30))(plVar8);
          pcStack_138 = pcStack_a8;
          auVar23 = auStack_b8;
          pcVar17 = pcStack_b0;
        }
        goto LAB_23e7ae229;
      }
      *(undefined4 *)(plVar20 + 5) = 0x59;
      plVar11 = (longlong *)FUN_23e914090(param_1,plVar8,plVar10);
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (plVar11 == (longlong *)0x0) {
LAB_23e7ae208:
        pcStack_138 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        auVar23 = *(undefined1 (*) [8])(param_1 + 0x60);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar17 = *(code **)(param_1 + 0x68);
        goto LAB_23e7ae229;
      }
      plVar8 = (longlong *)FUN_23a388310(plVar11);
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (plVar8 == (longlong *)0x0) goto LAB_23e7ae208;
      plVar10 = (longlong *)(**(code **)(plVar8[1] + 0xe0))(plVar8);
      if ((plVar10 == (longlong *)0x0) &&
         (plVar10 = (longlong *)FUN_23a3c1b70(param_1,auStack_b8,0,4), plVar10 == (longlong *)0x0))
      {
        plVar13 = (longlong *)0x0;
        plVar12 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
LAB_23e7aea3b:
        pcStack_138 = pcStack_a8;
        pcVar17 = pcStack_b0;
        auVar23 = auStack_b8;
        pcStack_a8 = (code *)0x0;
        _auStack_b8 = (undefined1  [16])0x0;
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        pcStack_a8 = (code *)0x0;
        auStack_b8 = (undefined1  [8])0x0;
        pcStack_b0 = (code *)0x0;
        if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        goto LAB_23e7ae229;
      }
      plVar11 = (longlong *)(**(code **)(plVar8[1] + 0xe0))(plVar8);
      if (plVar11 == (longlong *)0x0) {
        plVar13 = (longlong *)0x0;
        plVar12 = (longlong *)0x0;
        plVar11 = (longlong *)FUN_23a3c1b70(param_1,auStack_b8,1,4);
        if (plVar11 == (longlong *)0x0) goto LAB_23e7aea3b;
      }
      plVar12 = (longlong *)(**(code **)(plVar8[1] + 0xe0))(plVar8);
      if (plVar12 == (longlong *)0x0) {
        plVar13 = (longlong *)0x0;
        plVar12 = (longlong *)FUN_23a3c1b70(param_1,auStack_b8,2,4);
        if (plVar12 == (longlong *)0x0) goto LAB_23e7aea3b;
      }
      plVar13 = (longlong *)(**(code **)(plVar8[1] + 0xe0))(plVar8);
      if (((plVar13 == (longlong *)0x0) &&
          (plVar13 = (longlong *)FUN_23a3c1b70(param_1,auStack_b8,3,4), plVar13 == (longlong *)0x0))
         || (cVar5 = FUN_23a3884a0(param_1,auStack_b8,plVar8,4), cVar5 == '\0')) goto LAB_23e7aea3b;
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      plStack_108 = (longlong *)FUN_23e8c6640(plVar12,plVar10);
      if (plStack_108 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        pcStack_138 = (code *)0x0;
        plVar8 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar22 = 0x5a;
        plStack_130 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_118 = (longlong *)0x0;
        pcStack_120 = (code *)0x0;
        plStack_110 = (longlong *)0x0;
        pcStack_100 = (code *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_b0 = *(code **)(param_1 + 0x68);
        goto LAB_23e7ae2b4;
      }
      pcStack_100 = (code *)FUN_23e8c6640(plVar13,plVar11);
      if (pcStack_100 == (code *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        pcStack_138 = (code *)0x0;
        plVar8 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar22 = 0x5b;
        plStack_130 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_118 = (longlong *)0x0;
        pcStack_120 = (code *)0x0;
        plStack_110 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_b0 = *(code **)(param_1 + 0x68);
        goto LAB_23e7ae2b4;
      }
      lVar9 = FUN_23e8df2f0();
      if (lVar9 == 0) {
        FUN_23e915740(param_1,auStack_b8);
LAB_23e7af146:
        uVar22 = 0x5d;
        plVar8 = (longlong *)0x0;
        pcStack_138 = (code *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_118 = (longlong *)0x0;
        pcStack_120 = (code *)0x0;
        plStack_110 = (longlong *)0x0;
        goto LAB_23e7ae2b4;
      }
      plVar8 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eed79f8);
      if (plVar8 == (longlong *)0x0) {
LAB_23e7af11f:
        pcStack_a8 = *(code **)(param_1 + 0x70);
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e7af146;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(plVar1);
      if (plVar14 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar8 = *plVar8 + -1;
        if (*plVar8 != 0) {
          plVar8 = (longlong *)0x0;
          uVar22 = 0x5d;
          pcStack_138 = (code *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          pcStack_120 = (code *)0x0;
          goto LAB_23e7ae2b4;
        }
        FUN_23a334bc0();
        goto LAB_23e7af146;
      }
      *(undefined4 *)(plVar20 + 5) = 0x5d;
      plStack_110 = (longlong *)FUN_23e914090(param_1,plVar8);
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        FUN_23a334bc0();
      }
      lVar9 = *plVar14;
      *plVar14 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        FUN_23a334bc0();
      }
      if (plStack_110 == (longlong *)0x0) goto LAB_23e7af11f;
      lVar9 = FUN_23e8df1a0();
      if (lVar9 == 0) {
        FUN_23e915740(param_1,auStack_b8,_DAT_23eed7a00);
        pcStack_120 = (code *)0x0;
LAB_23e7af248:
        plVar8 = (longlong *)0x0;
        uVar22 = 0x5e;
        pcStack_138 = (code *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_118 = (longlong *)0x0;
        goto LAB_23e7ae2b4;
      }
      *(undefined4 *)(plVar20 + 5) = 0x5e;
      pcStack_120 = (code *)FUN_23e915840(param_1,lVar9,_DAT_23eed7a08);
      if (pcStack_120 == (code *)0x0) {
        pcStack_a8 = *(code **)(param_1 + 0x70);
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e7af248;
      }
      *(undefined4 *)(plVar20 + 5) = 0x5f;
      plStack_118 = (longlong *)FUN_23e91bfe0(param_1,pcStack_120,_DAT_23eed7a10);
      if (plStack_118 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        plVar8 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar22 = 0x5f;
        pcStack_138 = (code *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_b0 = *(code **)(param_1 + 0x68);
        goto LAB_23e7ae2b4;
      }
      lVar9 = FUN_23e8df1a0();
      if (lVar9 == 0) {
        plVar8 = (longlong *)0x0;
        FUN_23e915740(param_1,auStack_b8,_DAT_23eed7a00);
        uVar22 = 0x61;
        pcStack_138 = (code *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        goto LAB_23e7ae2b4;
      }
      *(undefined4 *)(plVar20 + 5) = 0x61;
      plStack_128 = (longlong *)FUN_23e91bfe0(param_1,lVar9,_DAT_23eed7a18);
      if (plStack_128 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        plVar8 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_138 = (code *)0x0;
        plStack_130 = (longlong *)0x0;
        uVar22 = 0x61;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_b0 = *(code **)(param_1 + 0x68);
        goto LAB_23e7ae2b4;
      }
      *(undefined4 *)(plVar20 + 5) = 0x62;
      auStack_98._8_8_ = plStack_108;
      auStack_98._0_8_ = pcStack_120;
      pcStack_88 = pcStack_100;
      plVar8 = (longlong *)FUN_23e9578c0(param_1,plStack_128,_DAT_23eed7a20,auStack_98);
      if (plVar8 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        uVar22 = 0x62;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_138 = (code *)0x0;
        plStack_130 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar8 = (longlong *)0x0;
        pcStack_b0 = *(code **)(param_1 + 0x68);
        goto LAB_23e7ae2b4;
      }
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        FUN_23a334bc0(plVar8);
      }
      *(undefined4 *)(plVar20 + 5) = 99;
      plVar8 = (longlong *)FUN_23e915840(param_1,plStack_118,_DAT_23eed7a28,plStack_128);
      if (plVar8 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        uVar22 = 99;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_138 = (code *)0x0;
        plStack_130 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar8 = (longlong *)0x0;
        pcStack_b0 = *(code **)(param_1 + 0x68);
        goto LAB_23e7ae2b4;
      }
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        FUN_23a334bc0(plVar8);
      }
      plVar8 = (longlong *)FUN_23e8bc2f0(plStack_118);
      uVar3 = _DAT_23eed79e0;
      if (plVar8 == (longlong *)0x0) {
LAB_23e7af432:
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7af412:
        uVar22 = 0x65;
        plVar8 = (longlong *)0x0;
        pcStack_138 = (code *)0x0;
        plStack_130 = (longlong *)0x0;
        goto LAB_23e7ae2b4;
      }
      plVar14 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
      uVar4 = _DAT_23eed79e0;
      lVar2 = _DAT_23eed7948;
      *plStack_108 = *plStack_108 + 1;
      lVar9 = *(longlong *)(lVar2 + 0x20);
      plVar14[3] = (longlong)plStack_108;
      *(longlong *)pcStack_100 = *(longlong *)pcStack_100 + 1;
      plVar14[4] = (longlong)pcStack_100;
      if (*(char *)(lVar9 + 10) != '\0') {
        iVar6 = *(int *)(lVar9 + 0xc);
        if (*(int *)(lVar9 + 0xc) == 0) {
          *(int *)(lVar9 + 0xc) = _DAT_23ec153f4;
          iVar6 = _DAT_23ec153f4;
          _DAT_23ec153f4 = _DAT_23ec153f4 + 1;
        }
        if (_DAT_23ec153ec != iVar6) {
          _DAT_23ec153ec = iVar6;
          _DAT_23eedab18 =
               FUN_23e8cbd60(lVar9,_DAT_23eed7a38,*(undefined8 *)(_DAT_23eed7a38 + 0x18));
        }
        if (-1 < _DAT_23eedab18) {
          lVar2 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
          lVar21 = *(longlong *)(lVar2 + 8 + _DAT_23eedab18 * 0x10);
          if (lVar21 != 0) goto LAB_23e7ad66e;
          _DAT_23eedab18 =
               FUN_23e8cbd60(lVar9,_DAT_23eed7a38,*(undefined8 *)(_DAT_23eed7a38 + 0x18));
          if (-1 < _DAT_23eedab18) {
            lVar21 = *(longlong *)(lVar2 + 8 + _DAT_23eedab18 * 0x10);
            goto LAB_23e7af399;
          }
        }
LAB_23e7af3a2:
        plVar15 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eed7a38);
        if ((plVar15 != (longlong *)0x0) && (lVar21 = *plVar15, lVar21 != 0)) goto LAB_23e7ad66e;
        FUN_23e915740(param_1,auStack_b8,_DAT_23eed7a38);
        *plVar8 = *plVar8 + -1;
        lVar9 = *plVar8;
joined_r0x00023e7af3e4:
        if (lVar9 == 0) {
          FUN_23a334bc0(plVar8);
        }
        lVar9 = *plVar14;
        *plVar14 = lVar9 + -1;
        if (lVar9 + -1 == 0) {
          FUN_23a334bc0(plVar14);
        }
        goto LAB_23e7af412;
      }
      plVar15 = (longlong *)FUN_23a37a020(lVar2,_DAT_23eed7a38);
      if (plVar15 == (longlong *)0x0) goto LAB_23e7af3a2;
      lVar21 = *plVar15;
LAB_23e7af399:
      if (lVar21 == 0) goto LAB_23e7af3a2;
LAB_23e7ad66e:
      plVar15 = (longlong *)FUN_23e8bc2f0(lVar21,_DAT_23eed7a40);
      if (plVar15 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar8 = *plVar8 + -1;
        lVar9 = *plVar8;
        goto joined_r0x00023e7af3e4;
      }
      *(undefined4 *)(plVar20 + 5) = 0x65;
      auStack_98._8_8_ = plVar14;
      auStack_98._0_8_ = uVar3;
      uStack_80 = uVar4;
      pcStack_88 = pcStack_120;
      plStack_78 = plVar15;
      plVar16 = (longlong *)FUN_23e95b390(param_1,plVar8,auStack_98);
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        FUN_23a334bc0(plVar8);
      }
      lVar9 = *plVar14;
      *plVar14 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        FUN_23a334bc0(plVar14);
      }
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        FUN_23a334bc0(plVar15);
      }
      if (plVar16 == (longlong *)0x0) goto LAB_23e7af432;
      lVar9 = *plVar16;
      *plVar16 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        FUN_23a334bc0(plVar16);
      }
      *(undefined4 *)(plVar20 + 5) = 0x67;
      plVar8 = (longlong *)FUN_23e91bfe0(param_1,plStack_128,_DAT_23eed7a48);
      lVar9 = _DAT_23eed7a58;
      if (plVar8 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        uVar22 = 0x67;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_138 = (code *)0x0;
        plStack_130 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_b0 = *(code **)(param_1 + 0x68);
        goto LAB_23e7ae2b4;
      }
      *(undefined4 *)(plVar20 + 5) = 0x68;
      plStack_130 = (longlong *)
                    FUN_23e915840(param_1,plStack_128,_DAT_23eed7a50,*(undefined8 *)(lVar9 + 0x18));
      if (plStack_130 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        uVar22 = 0x68;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_138 = (code *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_b0 = *(code **)(param_1 + 0x68);
        goto LAB_23e7ae2b4;
      }
      lVar9 = FUN_23e8deb10();
      if (lVar9 == 0) {
        FUN_23e915740(param_1,auStack_b8,_DAT_23eed7a60);
LAB_23e7af7b0:
        uVar22 = 0x6a;
        pcStack_138 = (code *)0x0;
        goto LAB_23e7ae2b4;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eed7a68);
      if (plVar14 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        uVar22 = 0x6a;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_138 = (code *)0x0;
        pcStack_b0 = *(code **)(param_1 + 0x68);
        goto LAB_23e7ae2b4;
      }
      lVar9 = FUN_23e8deb10();
      if (lVar9 == 0) {
        FUN_23e915740(param_1,auStack_b8,_DAT_23eed7a60);
LAB_23e7af7ed:
        lVar9 = *plVar14;
        *plVar14 = lVar9 + -1;
        if (lVar9 + -1 == 0) {
          FUN_23a334bc0(plVar14);
        }
        goto LAB_23e7af7b0;
      }
      plVar15 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eed7a70);
      if (plVar15 == (longlong *)0x0) {
        pcStack_a8 = *(code **)(param_1 + 0x70);
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e7af7ed;
      }
      *(undefined4 *)(plVar20 + 5) = 0x6a;
      auStack_98._0_8_ = plStack_130;
      plStack_c0 = plVar15;
      pcStack_138 = (code *)FUN_23e939900(param_1,plVar14,auStack_98,&plStack_c0,_DAT_23eed7a78);
      lVar9 = *plVar14;
      *plVar14 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        FUN_23a334bc0(plVar14);
      }
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        FUN_23a334bc0(plVar15);
      }
      if (pcStack_138 == (code *)0x0) {
        pcStack_a8 = *(code **)(param_1 + 0x70);
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e7af7b0;
      }
      lVar9 = FUN_23a38cc10(param_1,plVar8);
      if (lVar9 == 0) {
LAB_23e7af75e:
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7af743:
        uVar22 = 0x6b;
        goto LAB_23e7ae2b4;
      }
      plVar14 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
      plVar14[3] = lVar9;
      lVar9 = FUN_23a38cc10(param_1,plVar8,_DAT_23eed7a88);
      if (lVar9 == 0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          FUN_23a334bc0(plVar14);
        }
        goto LAB_23e7af743;
      }
      plVar14[4] = lVar9;
      uVar3 = _DAT_23eed7a98;
      plVar15 = _DAT_23eed7a90;
      *_DAT_23eed7a90 = *_DAT_23eed7a90 + 1;
      plVar14[5] = (longlong)plVar15;
      cVar5 = FUN_23e8d9ac0(pcStack_138,uVar3);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        FUN_23a334bc0(plVar14);
      }
      if (cVar5 == '\0') goto LAB_23e7af75e;
      lVar9 = FUN_23e8df050();
      if (lVar9 == 0) {
        FUN_23e915740(param_1,auStack_b8,_DAT_23eed7aa0);
LAB_23e7af67f:
        uVar22 = 0x6c;
        goto LAB_23e7ae2b4;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(lVar9);
      if (plVar14 == (longlong *)0x0) {
LAB_23e7af6c9:
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e7af67f;
      }
      lVar9 = FUN_23e8df050();
      if (lVar9 == 0) {
        FUN_23e915740(param_1,auStack_b8,_DAT_23eed7aa0);
        *plVar14 = *plVar14 + -1;
        lVar9 = *plVar14;
joined_r0x00023e7af6c5:
        if (lVar9 == 0) {
          FUN_23a334bc0(plVar14);
        }
        goto LAB_23e7af67f;
      }
      plVar15 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eed7ab0);
      if (plVar15 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar14 = *plVar14 + -1;
        lVar9 = *plVar14;
        goto joined_r0x00023e7af6c5;
      }
      *(undefined4 *)(plVar20 + 5) = 0x6c;
      auStack_98._8_8_ = plVar15;
      auStack_98._0_8_ = pcStack_138;
      pcVar17 = (code *)FUN_23e94ed00(param_1,plVar14,auStack_98);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        FUN_23a334bc0(plVar14);
      }
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        FUN_23a334bc0(plVar15);
      }
      if (pcVar17 == (code *)0x0) goto LAB_23e7af6c9;
      lVar9 = *(longlong *)pcStack_138;
      *(longlong *)pcStack_138 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        FUN_23a334bc0(pcStack_138);
      }
      lVar9 = FUN_23e8df2f0();
      pcStack_138 = pcVar17;
      if (lVar9 == 0) {
        FUN_23e915740(param_1,auStack_b8,DAT_23eed7980);
LAB_23e7af5fd:
        uVar22 = 0x6e;
        goto LAB_23e7ae2b4;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eed7ab8);
      if (plVar14 == (longlong *)0x0) {
LAB_23e7af608:
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e7af5fd;
      }
      *(undefined4 *)(plVar20 + 5) = 0x6e;
      plVar15 = (longlong *)FUN_23e91bfe0(param_1,plStack_128,_DAT_23eed7ac0);
      if (plVar15 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          FUN_23a334bc0(plVar14);
        }
        goto LAB_23e7af5fd;
      }
      *(undefined4 *)(plVar20 + 5) = 0x6e;
      plVar16 = (longlong *)FUN_23e914090(param_1,plVar14);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        FUN_23a334bc0(plVar14);
      }
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        FUN_23a334bc0(plVar15);
      }
      if (plVar16 == (longlong *)0x0) goto LAB_23e7af608;
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        FUN_23a334bc0(plVar16);
      }
      *(undefined4 *)(plVar20 + 5) = 0x6f;
      plVar14 = (longlong *)FUN_23e91bfe0(param_1,plStack_118,_DAT_23eed7ac8);
      if (plVar14 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        uVar22 = 0x6f;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_b0 = *(code **)(param_1 + 0x68);
        goto LAB_23e7ae2b4;
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        FUN_23a334bc0(plVar14);
      }
      *(undefined4 *)(plVar20 + 5) = 0x70;
      plVar14 = (longlong *)FUN_23e91bfe0(param_1,pcStack_120,_DAT_23eed7ac8);
      if (plVar14 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        uVar22 = 0x70;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_b0 = *(code **)(param_1 + 0x68);
        goto LAB_23e7ae2b4;
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        FUN_23a334bc0(plVar14);
      }
      lVar9 = FUN_23e8df2f0();
      if (lVar9 == 0) {
        FUN_23e915740(param_1,auStack_b8,DAT_23eed7980);
LAB_23e7af516:
        uVar22 = 0x71;
        goto LAB_23e7ae2b4;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eed7ad0);
      if (plVar14 == (longlong *)0x0) {
LAB_23e7af521:
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e7af516;
      }
      plVar15 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed7968);
      if (plVar15 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          FUN_23a334bc0(plVar14);
        }
        goto LAB_23e7af516;
      }
      *(undefined4 *)(plVar20 + 5) = 0x71;
      auStack_98._8_8_ = plStack_110;
      auStack_98._0_8_ = plVar15;
      plVar16 = (longlong *)FUN_23e94ed00(param_1,plVar14,auStack_98);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        FUN_23a334bc0(plVar14);
      }
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        FUN_23a334bc0(plVar15);
      }
      if (plVar16 == (longlong *)0x0) goto LAB_23e7af521;
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        FUN_23a334bc0(plVar16);
      }
      FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
      *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
        goto LAB_23e7ace9e;
      }
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) goto LAB_23e7acea5;
      goto LAB_23e7aceb5;
    }
    FUN_23e915740(param_1,auStack_b8,DAT_23eed7980);
    pcStack_138 = pcStack_a8;
    auVar23 = auStack_b8;
    pcVar17 = pcStack_b0;
LAB_23e7ae229:
    pcStack_a8 = pcStack_138;
    plVar8 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    pcStack_138 = (code *)0x0;
    plVar11 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    uVar22 = 0x59;
    plStack_130 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_110 = (longlong *)0x0;
    pcStack_100 = (code *)0x0;
    plStack_108 = (longlong *)0x0;
    auStack_b8 = auVar23;
    pcStack_b0 = pcVar17;
LAB_23e7ae2b4:
    pcVar17 = pcStack_a8;
    auStack_98._8_8_ = pcStack_b0;
    auStack_98._0_8_ = auStack_b8;
    pcStack_a8 = (code *)0x0;
    auStack_b8 = (undefined1  [8])0x0;
    pcStack_b0 = (code *)0x0;
    pcStack_88 = pcVar17;
    plVar14 = *(longlong **)(param_1 + 0x138);
    if (plVar14 != (longlong *)0x0) {
      *plVar14 = *plVar14 + 1;
    }
    pcVar18 = DAT_23ed6a4f8;
    if (pcVar17 == (code *)0x0) {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar17 = *(code **)DAT_23ed6a4f8;
        *(undefined8 *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar17;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcStack_f0 = _PyRuntime_exref;
      *(longlong *)(pcVar18 + 0x10) = 0;
      *(longlong **)(pcVar18 + 0x18) = plVar20;
      *plVar20 = *plVar20 + 1;
      lVar9 = *(longlong *)(pcStack_f0 + 0x1f8);
      *(undefined4 *)(pcVar18 + 0x24) = uVar22;
      lVar9 = *(longlong *)(lVar9 + 0x10);
      *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
      lVar9 = *(longlong *)(lVar9 + 0x2e8);
      lVar2 = *(longlong *)(pcVar18 + -8);
      plVar15 = *(longlong **)(lVar9 + 8);
      *plVar15 = (longlong)(pcVar18 + -0x10);
      *(longlong *)(pcVar18 + -0x10) = lVar9;
      *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)plVar15;
      *(code **)(lVar9 + 8) = pcVar18 + -0x10;
      if ((pcStack_88 != (code *)0x0) &&
         (*(longlong *)pcStack_88 = *(longlong *)pcStack_88 + -1, *(longlong *)pcStack_88 == 0)) {
        (**(code **)(*(longlong *)(pcStack_88 + 8) + 0x30))(pcStack_88);
      }
    }
    else {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar19 = *(code **)DAT_23ed6a4f8;
        *(undefined8 *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar19;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcStack_f0 = _PyRuntime_exref;
      *(longlong **)(pcVar18 + 0x18) = plVar20;
      *plVar20 = *plVar20 + 1;
      lVar9 = *(longlong *)(pcStack_f0 + 0x1f8);
      *(undefined4 *)(pcVar18 + 0x24) = uVar22;
      lVar9 = *(longlong *)(lVar9 + 0x10);
      *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
      lVar9 = *(longlong *)(lVar9 + 0x2e8);
      lVar2 = *(longlong *)(pcVar18 + -8);
      plVar15 = *(longlong **)(lVar9 + 8);
      *plVar15 = (longlong)(pcVar18 + -0x10);
      *(longlong *)(pcVar18 + -0x10) = lVar9;
      *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)plVar15;
      *(code **)(lVar9 + 8) = pcVar18 + -0x10;
      *(code **)(pcVar18 + 0x10) = pcVar17;
      *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
      if ((pcStack_88 != (code *)0x0) &&
         (*(longlong *)pcStack_88 = *(longlong *)pcStack_88 + -1, *(longlong *)pcStack_88 == 0)) {
        (**(code **)(*(longlong *)(pcStack_88 + 8) + 0x30))(pcStack_88);
      }
    }
    pcVar17 = _Py_NoneStruct_exref;
    pcStack_88 = pcVar18;
    if (((code *)auStack_98._0_8_ != (code *)0x0) &&
       ((code *)auStack_98._0_8_ != _Py_NoneStruct_exref)) {
      FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,&pcStack_88);
    }
    plVar15 = *(longlong **)(auStack_98._8_8_ + 0x28);
    if (pcStack_88 == pcVar17) {
      pcVar18 = (code *)0x0;
    }
    else {
      pcVar18 = pcStack_88;
      if (pcStack_88 != (code *)0x0) {
        *(longlong *)pcStack_88 = *(longlong *)pcStack_88 + 1;
      }
    }
    *(code **)(auStack_98._8_8_ + 0x28) = pcVar18;
    if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
      (**(code **)(plVar15[1] + 0x30))();
    }
    plVar15 = *(longlong **)(param_1 + 0x138);
    *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
    if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
      (**(code **)(plVar15[1] + 0x30))();
    }
    *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + -1;
    if (*(longlong *)auStack_98._0_8_ == 0) {
      (**(code **)(*(longlong *)(auStack_98._0_8_ + 8) + 0x30))();
    }
    if ((pcStack_88 != (code *)0x0) &&
       (*(longlong *)pcStack_88 = *(longlong *)pcStack_88 + -1, *(longlong *)pcStack_88 == 0)) {
      (**(code **)(*(longlong *)(pcStack_88 + 8) + 0x30))();
    }
    pcStack_88 = (code *)0x0;
    auStack_98 = (undefined1  [16])0x0;
    iVar6 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                          *(undefined8 *)PyExc_Exception_exref);
    if (iVar6 != 0) {
      plVar20 = *(longlong **)(param_1 + 0x138);
      *plVar20 = *plVar20 + 1;
      *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
      lVar9 = *plVar20 + -1;
      *plVar20 = lVar9;
      if (lVar9 == 0) {
        (**(code **)(plVar20[1] + 0x30))();
        plVar20 = *(longlong **)(param_1 + 0x138);
        *(longlong **)(param_1 + 0x138) = plVar14;
        if (plVar20 == (longlong *)0x0) goto LAB_23e7ace00;
        lVar9 = *plVar20;
      }
      else {
        *(longlong **)(param_1 + 0x138) = plVar14;
      }
      *plVar20 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar20[1] + 0x30))();
      }
      goto LAB_23e7ace00;
    }
    pcVar18 = *(code **)(param_1 + 0x138);
    pcStack_b0 = pcVar18;
    if ((pcVar18 == pcVar17) || (pcVar18 == (code *)0x0)) {
      plVar15 = *(longlong **)PyExc_RuntimeError_exref;
      pcVar19 = (code *)PyUnicode_FromString("No active exception to reraise");
      pcVar18 = *(code **)(param_1 + 0x138);
      *plVar15 = *plVar15 + 1;
      *(longlong **)(param_1 + 0x138) = plVar14;
      auStack_b8 = (undefined1  [8])plVar15;
      pcStack_b0 = pcVar19;
      if (pcVar18 != (code *)0x0) {
        pcVar17 = (code *)0x0;
        iVar6 = 0x58;
        goto LAB_23e7aeb7a;
      }
LAB_23e7aef3e:
      pcStack_a8 = (code *)0x0;
      uVar22 = 0x58;
    }
    else {
      plVar15 = *(longlong **)(pcVar18 + 8);
      pcVar17 = *(code **)(pcVar18 + 0x28);
      *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
      *plVar15 = *plVar15 + 1;
      iVar6 = 0;
      pcVar19 = pcVar18;
      if (pcVar17 == (code *)0x0) {
        *(longlong **)(param_1 + 0x138) = plVar14;
      }
      else {
        *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
        if (*(longlong **)(pcVar17 + 0x18) == plVar20) {
          *(undefined4 *)(plVar20 + 5) = *(undefined4 *)(pcVar17 + 0x24);
        }
        *(longlong **)(param_1 + 0x138) = plVar14;
      }
LAB_23e7aeb7a:
      pcStack_a8 = (code *)0x0;
      _auStack_b8 = (undefined1  [16])0x0;
      *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
      if (*(longlong *)pcVar18 == 0) {
        (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))();
      }
      auStack_b8 = (undefined1  [8])plVar15;
      pcStack_b0 = pcVar19;
      if (pcVar17 != (code *)0x0) {
        if (*(longlong **)(pcVar17 + 0x18) == plVar20) goto LAB_23e7adee6;
        pcStack_a8 = pcVar17;
        if (iVar6 == 0) {
          uVar22 = (undefined4)plVar20[5];
        }
        else {
          uVar22 = 0x58;
        }
        goto LAB_23e7ade2b;
      }
      pcStack_a8 = (code *)0x0;
      if (iVar6 != 0) goto LAB_23e7aef3e;
      uVar22 = (undefined4)plVar20[5];
    }
  }
  pcVar17 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    pcVar18 = pcStack_a8;
  }
  else {
    pcVar18 = *(code **)DAT_23ed6a4f8;
    *(undefined8 *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar18;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    pcVar18 = (code *)0x0;
  }
  *(longlong *)(pcVar17 + 0x10) = 0;
  *(longlong **)(pcVar17 + 0x18) = plVar20;
  *plVar20 = *plVar20 + 1;
  *(undefined4 *)(pcVar17 + 0x24) = uVar22;
  *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
  lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_f0 + 0x1f8) + 0x10) + 0x2e8);
  lVar2 = *(longlong *)(pcVar17 + -8);
  plVar14 = *(longlong **)(lVar9 + 8);
  *plVar14 = (longlong)(pcVar17 + -0x10);
  *(longlong *)(pcVar17 + -0x10) = lVar9;
  *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)plVar14;
  *(code **)(lVar9 + 8) = pcVar17 + -0x10;
  if ((pcVar18 != (code *)0x0) &&
     (*(longlong *)pcVar18 = *(longlong *)pcVar18 + -1, *(longlong *)pcVar18 == 0)) {
    (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))();
  }
LAB_23e7adee6:
  pcStack_a8 = pcVar17;
  FUN_23e8bba40(plVar20,"ooooooooooooooo",plVar1,plVar10,plVar11,plVar12,plVar13,plStack_108,
                pcStack_100,plStack_110,pcStack_120,plStack_118,plStack_128,plVar8,plStack_130,
                pcStack_138,0);
  if (_DAT_23eedab28 == plVar20) {
    *plVar20 = *plVar20 + -1;
    if (*plVar20 == 0) {
      (**(code **)(plVar20[1] + 0x30))(plVar20);
    }
    _DAT_23eedab28 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar20 = *(longlong **)(lVar9 + 0x28);
  plVar14 = (longlong *)plVar20[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
  *(undefined4 *)(plVar20 + 8) = 0xffffffff;
  if (plVar14 != (longlong *)0x0) {
    plVar20[2] = 0;
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))();
    }
  }
  *plVar20 = *plVar20 + -1;
  if (*plVar20 == 0) {
    (**(code **)(plVar20[1] + 0x30))(plVar20);
  }
  pcVar18 = pcStack_a8;
  pcVar17 = pcStack_b0;
  auVar23 = auStack_b8;
  plVar20[0xf] = 0;
  _auStack_b8 = (undefined1  [16])0x0;
  pcStack_a8 = (code *)0x0;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plStack_108 != (longlong *)0x0) &&
     (lVar9 = *plStack_108, *plStack_108 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_108[1] + 0x30))(plStack_108);
  }
  if ((pcStack_100 != (code *)0x0) &&
     (lVar9 = *(longlong *)pcStack_100, *(longlong *)pcStack_100 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(*(longlong *)(pcStack_100 + 8) + 0x30))(pcStack_100);
  }
  if ((plStack_110 != (longlong *)0x0) &&
     (lVar9 = *plStack_110, *plStack_110 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_110[1] + 0x30))(plStack_110);
  }
  if ((pcStack_120 != (code *)0x0) &&
     (lVar9 = *(longlong *)pcStack_120, *(longlong *)pcStack_120 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(*(longlong *)(pcStack_120 + 8) + 0x30))(pcStack_120);
  }
  if ((plStack_118 != (longlong *)0x0) &&
     (lVar9 = *plStack_118, *plStack_118 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_118[1] + 0x30))(plStack_118);
  }
  if ((plStack_128 != (longlong *)0x0) &&
     (lVar9 = *plStack_128, *plStack_128 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_128[1] + 0x30))(plStack_128);
  }
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plStack_130 != (longlong *)0x0) &&
     (lVar9 = *plStack_130, *plStack_130 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_130[1] + 0x30))();
  }
  if ((pcStack_138 != (code *)0x0) &&
     (lVar9 = *(longlong *)pcStack_138, *(longlong *)pcStack_138 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(*(longlong *)(pcStack_138 + 8) + 0x30))(pcStack_138);
  }
  *plVar1 = *plVar1 + -1;
  pcStack_a8 = pcVar18;
  auStack_b8 = auVar23;
  pcStack_b0 = pcVar17;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,auStack_b8,pcStack_b0,pcStack_a8);
  return (code *)0x0;
}
