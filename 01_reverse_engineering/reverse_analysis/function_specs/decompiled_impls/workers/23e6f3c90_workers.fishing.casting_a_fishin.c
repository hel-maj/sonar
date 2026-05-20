/* ===== 23e6f3c90 workers.fishing.casting_a_fishin:64 ===== */
/* ghidra_name=FUN_23e6f3c90 entry=23e6f3c90 size=11396 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

code * FUN_23e6f3c90(longlong param_1,undefined8 param_2,undefined8 *param_3)

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
  
  plVar8 = _DAT_23eedb218;
  plVar1 = (longlong *)*param_3;
  pcStack_a8 = (code *)0x0;
  auStack_b8 = (undefined1  [8])0x0;
  pcStack_b0 = (code *)0x0;
  if (_DAT_23eedb218 == (longlong *)0x0) {
LAB_23e6f3cf5:
    _DAT_23eedb218 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedb210,DAT_23eedb268,0x78);
  }
  else {
    lVar9 = *_DAT_23eedb218;
    if (1 < lVar9) {
      *_DAT_23eedb218 = lVar9 + -1;
      goto LAB_23e6f3cf5;
    }
    if (_DAT_23eedb218[2] != 0) {
      *_DAT_23eedb218 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e6f3cf5;
    }
  }
  plVar20 = _DAT_23eedb218;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eedb218 + 9;
  lVar2 = *(longlong *)(lVar9 + 8);
  _DAT_23eedb218[0xf] = lVar2;
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
  uVar3 = DAT_23eeda328;
  *(undefined4 *)(plVar20 + 8) = 0;
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar3);
  if (plVar8 == (longlong *)0x0) {
LAB_23e6f4d90:
    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_b0 = *(code **)(param_1 + 0x68);
    pcStack_a8 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcStack_a8 == (code *)0x0) goto LAB_23e6f5730;
    plVar8 = *(longlong **)(pcStack_a8 + 0x18);
joined_r0x00023e6f5d6c:
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
      goto LAB_23e6f4f16;
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
    uVar22 = 0x42;
    pcStack_f0 = _PyRuntime_exref;
LAB_23e6f4e5b:
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
    goto LAB_23e6f4f16;
  }
  iVar6 = FUN_23a35f020(plVar8);
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if (iVar6 == -1) {
LAB_23e6f5610:
    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_b0 = *(code **)(param_1 + 0x68);
    pcStack_a8 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcStack_a8 != (code *)0x0) {
      plVar8 = *(longlong **)(pcStack_a8 + 0x18);
      goto joined_r0x00023e6f5d6c;
    }
    goto LAB_23e6f5730;
  }
  if (iVar6 == 0) {
LAB_23e6f3db8:
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
LAB_23e6f3e30:
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
LAB_23e6f3ece:
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
LAB_23e6f3ed5:
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
    }
    if (plVar12 == (longlong *)0x0) goto LAB_23e6f3ef6;
LAB_23e6f3ee5:
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
LAB_23e6f3ef6:
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
  lVar9 = FUN_23e8e1ef0();
  if (lVar9 == 0) {
    FUN_23e915740(param_1,auStack_b8,_DAT_23eeda340);
    if (pcStack_a8 != (code *)0x0) {
      plVar8 = *(longlong **)(pcStack_a8 + 0x18);
      goto joined_r0x00023e6f5d6c;
    }
    goto LAB_23e6f5730;
  }
  plVar8 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eeda398);
  if (plVar8 == (longlong *)0x0) goto LAB_23e6f4d90;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeda328);
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
      goto joined_r0x00023e6f5d6c;
    }
LAB_23e6f5730:
    plVar8 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    pcStack_138 = (code *)0x0;
    plVar11 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    uVar22 = 0x42;
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
    *(undefined4 *)(plVar20 + 5) = 0x42;
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
        goto joined_r0x00023e6f5d6c;
      }
      goto LAB_23e6f5730;
    }
    uVar7 = FUN_23a35f020(plVar11);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (uVar7 == 0xffffffff) goto LAB_23e6f5610;
    if ((uVar7 & 1) == 0) goto LAB_23e6f3db8;
    lVar9 = FUN_23e8e1ef0();
    if (lVar9 != 0) {
      plVar8 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eeda3a8);
      if (plVar8 == (longlong *)0x0) goto LAB_23e6f5238;
      plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeda328);
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
        goto LAB_23e6f5259;
      }
      *(undefined4 *)(plVar20 + 5) = 0x46;
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
LAB_23e6f5238:
        pcStack_138 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        auVar23 = *(undefined1 (*) [8])(param_1 + 0x60);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar17 = *(code **)(param_1 + 0x68);
        goto LAB_23e6f5259;
      }
      plVar8 = (longlong *)FUN_23a388310(plVar11);
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (plVar8 == (longlong *)0x0) goto LAB_23e6f5238;
      plVar10 = (longlong *)(**(code **)(plVar8[1] + 0xe0))(plVar8);
      if ((plVar10 == (longlong *)0x0) &&
         (plVar10 = (longlong *)FUN_23a3c1b70(param_1,auStack_b8,0,4), plVar10 == (longlong *)0x0))
      {
        plVar13 = (longlong *)0x0;
        plVar12 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
LAB_23e6f5a6b:
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
        goto LAB_23e6f5259;
      }
      plVar11 = (longlong *)(**(code **)(plVar8[1] + 0xe0))(plVar8);
      if (plVar11 == (longlong *)0x0) {
        plVar13 = (longlong *)0x0;
        plVar12 = (longlong *)0x0;
        plVar11 = (longlong *)FUN_23a3c1b70(param_1,auStack_b8,1,4);
        if (plVar11 == (longlong *)0x0) goto LAB_23e6f5a6b;
      }
      plVar12 = (longlong *)(**(code **)(plVar8[1] + 0xe0))(plVar8);
      if (plVar12 == (longlong *)0x0) {
        plVar13 = (longlong *)0x0;
        plVar12 = (longlong *)FUN_23a3c1b70(param_1,auStack_b8,2,4);
        if (plVar12 == (longlong *)0x0) goto LAB_23e6f5a6b;
      }
      plVar13 = (longlong *)(**(code **)(plVar8[1] + 0xe0))(plVar8);
      if (((plVar13 == (longlong *)0x0) &&
          (plVar13 = (longlong *)FUN_23a3c1b70(param_1,auStack_b8,3,4), plVar13 == (longlong *)0x0))
         || (cVar5 = FUN_23a3884a0(param_1,auStack_b8,plVar8,4), cVar5 == '\0')) goto LAB_23e6f5a6b;
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
        uVar22 = 0x47;
        plStack_130 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_118 = (longlong *)0x0;
        pcStack_120 = (code *)0x0;
        plStack_110 = (longlong *)0x0;
        pcStack_100 = (code *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_b0 = *(code **)(param_1 + 0x68);
        goto LAB_23e6f52e4;
      }
      pcStack_100 = (code *)FUN_23e8c6640(plVar13,plVar11);
      if (pcStack_100 == (code *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        pcStack_138 = (code *)0x0;
        plVar8 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar22 = 0x48;
        plStack_130 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_118 = (longlong *)0x0;
        pcStack_120 = (code *)0x0;
        plStack_110 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_b0 = *(code **)(param_1 + 0x68);
        goto LAB_23e6f52e4;
      }
      lVar9 = FUN_23e8e1ef0();
      if (lVar9 == 0) {
        FUN_23e915740(param_1,auStack_b8);
LAB_23e6f6176:
        uVar22 = 0x4a;
        plVar8 = (longlong *)0x0;
        pcStack_138 = (code *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_118 = (longlong *)0x0;
        pcStack_120 = (code *)0x0;
        plStack_110 = (longlong *)0x0;
        goto LAB_23e6f52e4;
      }
      plVar8 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eeda3b8);
      if (plVar8 == (longlong *)0x0) {
LAB_23e6f614f:
        pcStack_a8 = *(code **)(param_1 + 0x70);
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e6f6176;
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
          uVar22 = 0x4a;
          pcStack_138 = (code *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          pcStack_120 = (code *)0x0;
          goto LAB_23e6f52e4;
        }
        FUN_23a334bc0();
        goto LAB_23e6f6176;
      }
      *(undefined4 *)(plVar20 + 5) = 0x4a;
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
      if (plStack_110 == (longlong *)0x0) goto LAB_23e6f614f;
      lVar9 = FUN_23e8e1da0();
      if (lVar9 == 0) {
        FUN_23e915740(param_1,auStack_b8,_DAT_23eeda3c0);
        pcStack_120 = (code *)0x0;
LAB_23e6f6278:
        plVar8 = (longlong *)0x0;
        uVar22 = 0x4b;
        pcStack_138 = (code *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_118 = (longlong *)0x0;
        goto LAB_23e6f52e4;
      }
      *(undefined4 *)(plVar20 + 5) = 0x4b;
      pcStack_120 = (code *)FUN_23e915840(param_1,lVar9,_DAT_23eeda3c8);
      if (pcStack_120 == (code *)0x0) {
        pcStack_a8 = *(code **)(param_1 + 0x70);
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e6f6278;
      }
      *(undefined4 *)(plVar20 + 5) = 0x4c;
      plStack_118 = (longlong *)FUN_23e91bfe0(param_1,pcStack_120,_DAT_23eeda3d0);
      if (plStack_118 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        plVar8 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar22 = 0x4c;
        pcStack_138 = (code *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_b0 = *(code **)(param_1 + 0x68);
        goto LAB_23e6f52e4;
      }
      lVar9 = FUN_23e8e1da0();
      if (lVar9 == 0) {
        plVar8 = (longlong *)0x0;
        FUN_23e915740(param_1,auStack_b8,_DAT_23eeda3c0);
        uVar22 = 0x4e;
        pcStack_138 = (code *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        goto LAB_23e6f52e4;
      }
      *(undefined4 *)(plVar20 + 5) = 0x4e;
      plStack_128 = (longlong *)FUN_23e91bfe0(param_1,lVar9,_DAT_23eeda3d8);
      if (plStack_128 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        plVar8 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_138 = (code *)0x0;
        plStack_130 = (longlong *)0x0;
        uVar22 = 0x4e;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_b0 = *(code **)(param_1 + 0x68);
        goto LAB_23e6f52e4;
      }
      *(undefined4 *)(plVar20 + 5) = 0x4f;
      auStack_98._8_8_ = plStack_108;
      auStack_98._0_8_ = pcStack_120;
      pcStack_88 = pcStack_100;
      plVar8 = (longlong *)FUN_23e9578c0(param_1,plStack_128,_DAT_23eeda3e0,auStack_98);
      if (plVar8 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        uVar22 = 0x4f;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_138 = (code *)0x0;
        plStack_130 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar8 = (longlong *)0x0;
        pcStack_b0 = *(code **)(param_1 + 0x68);
        goto LAB_23e6f52e4;
      }
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        FUN_23a334bc0(plVar8);
      }
      *(undefined4 *)(plVar20 + 5) = 0x50;
      plVar8 = (longlong *)FUN_23e915840(param_1,plStack_118,_DAT_23eeda3e8,plStack_128);
      if (plVar8 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        uVar22 = 0x50;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_138 = (code *)0x0;
        plStack_130 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar8 = (longlong *)0x0;
        pcStack_b0 = *(code **)(param_1 + 0x68);
        goto LAB_23e6f52e4;
      }
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        FUN_23a334bc0(plVar8);
      }
      plVar8 = (longlong *)FUN_23e8bc2f0(plStack_118);
      uVar3 = _DAT_23eeda3a0;
      if (plVar8 == (longlong *)0x0) {
LAB_23e6f6462:
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e6f6442:
        uVar22 = 0x52;
        plVar8 = (longlong *)0x0;
        pcStack_138 = (code *)0x0;
        plStack_130 = (longlong *)0x0;
        goto LAB_23e6f52e4;
      }
      plVar14 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
      uVar4 = _DAT_23eeda3a0;
      lVar2 = _DAT_23eeda318;
      *plStack_108 = *plStack_108 + 1;
      lVar9 = *(longlong *)(lVar2 + 0x20);
      plVar14[3] = (longlong)plStack_108;
      *(longlong *)pcStack_100 = *(longlong *)pcStack_100 + 1;
      plVar14[4] = (longlong)pcStack_100;
      if (*(char *)(lVar9 + 10) != '\0') {
        iVar6 = *(int *)(lVar9 + 0xc);
        if (*(int *)(lVar9 + 0xc) == 0) {
          *(int *)(lVar9 + 0xc) = _DAT_23ec154a0;
          iVar6 = _DAT_23ec154a0;
          _DAT_23ec154a0 = _DAT_23ec154a0 + 1;
        }
        if (_DAT_23ec15498 != iVar6) {
          _DAT_23ec15498 = iVar6;
          _DAT_23eedb208 =
               FUN_23e8cbd60(lVar9,_DAT_23eeda3f8,*(undefined8 *)(_DAT_23eeda3f8 + 0x18));
        }
        if (-1 < _DAT_23eedb208) {
          lVar2 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
          lVar21 = *(longlong *)(lVar2 + 8 + _DAT_23eedb208 * 0x10);
          if (lVar21 != 0) goto LAB_23e6f469e;
          _DAT_23eedb208 =
               FUN_23e8cbd60(lVar9,_DAT_23eeda3f8,*(undefined8 *)(_DAT_23eeda3f8 + 0x18));
          if (-1 < _DAT_23eedb208) {
            lVar21 = *(longlong *)(lVar2 + 8 + _DAT_23eedb208 * 0x10);
            goto LAB_23e6f63c9;
          }
        }
LAB_23e6f63d2:
        plVar15 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeda3f8);
        if ((plVar15 != (longlong *)0x0) && (lVar21 = *plVar15, lVar21 != 0)) goto LAB_23e6f469e;
        FUN_23e915740(param_1,auStack_b8,_DAT_23eeda3f8);
        *plVar8 = *plVar8 + -1;
        lVar9 = *plVar8;
joined_r0x00023e6f6414:
        if (lVar9 == 0) {
          FUN_23a334bc0(plVar8);
        }
        lVar9 = *plVar14;
        *plVar14 = lVar9 + -1;
        if (lVar9 + -1 == 0) {
          FUN_23a334bc0(plVar14);
        }
        goto LAB_23e6f6442;
      }
      plVar15 = (longlong *)FUN_23a37a020(lVar2,_DAT_23eeda3f8);
      if (plVar15 == (longlong *)0x0) goto LAB_23e6f63d2;
      lVar21 = *plVar15;
LAB_23e6f63c9:
      if (lVar21 == 0) goto LAB_23e6f63d2;
LAB_23e6f469e:
      plVar15 = (longlong *)FUN_23e8bc2f0(lVar21,_DAT_23eeda400);
      if (plVar15 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar8 = *plVar8 + -1;
        lVar9 = *plVar8;
        goto joined_r0x00023e6f6414;
      }
      *(undefined4 *)(plVar20 + 5) = 0x52;
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
      if (plVar16 == (longlong *)0x0) goto LAB_23e6f6462;
      lVar9 = *plVar16;
      *plVar16 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        FUN_23a334bc0(plVar16);
      }
      *(undefined4 *)(plVar20 + 5) = 0x54;
      plVar8 = (longlong *)FUN_23e91bfe0(param_1,plStack_128,_DAT_23eeda408);
      lVar9 = _DAT_23eeda418;
      if (plVar8 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        uVar22 = 0x54;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_138 = (code *)0x0;
        plStack_130 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_b0 = *(code **)(param_1 + 0x68);
        goto LAB_23e6f52e4;
      }
      *(undefined4 *)(plVar20 + 5) = 0x55;
      plStack_130 = (longlong *)
                    FUN_23e915840(param_1,plStack_128,_DAT_23eeda410,*(undefined8 *)(lVar9 + 0x18));
      if (plStack_130 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        uVar22 = 0x55;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_138 = (code *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_b0 = *(code **)(param_1 + 0x68);
        goto LAB_23e6f52e4;
      }
      lVar9 = FUN_23e8e1860();
      if (lVar9 == 0) {
        FUN_23e915740(param_1,auStack_b8,_DAT_23eeda420);
LAB_23e6f67e0:
        uVar22 = 0x57;
        pcStack_138 = (code *)0x0;
        goto LAB_23e6f52e4;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eeda428);
      if (plVar14 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        uVar22 = 0x57;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_138 = (code *)0x0;
        pcStack_b0 = *(code **)(param_1 + 0x68);
        goto LAB_23e6f52e4;
      }
      lVar9 = FUN_23e8e1860();
      if (lVar9 == 0) {
        FUN_23e915740(param_1,auStack_b8,_DAT_23eeda420);
LAB_23e6f681d:
        lVar9 = *plVar14;
        *plVar14 = lVar9 + -1;
        if (lVar9 + -1 == 0) {
          FUN_23a334bc0(plVar14);
        }
        goto LAB_23e6f67e0;
      }
      plVar15 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eeda430);
      if (plVar15 == (longlong *)0x0) {
        pcStack_a8 = *(code **)(param_1 + 0x70);
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e6f681d;
      }
      *(undefined4 *)(plVar20 + 5) = 0x57;
      auStack_98._0_8_ = plStack_130;
      plStack_c0 = plVar15;
      pcStack_138 = (code *)FUN_23e939900(param_1,plVar14,auStack_98,&plStack_c0,_DAT_23eeda438);
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
        goto LAB_23e6f67e0;
      }
      lVar9 = FUN_23a38cc10(param_1,plVar8);
      if (lVar9 == 0) {
LAB_23e6f678e:
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e6f6773:
        uVar22 = 0x58;
        goto LAB_23e6f52e4;
      }
      plVar14 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
      plVar14[3] = lVar9;
      lVar9 = FUN_23a38cc10(param_1,plVar8,_DAT_23eeda448);
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
        goto LAB_23e6f6773;
      }
      plVar14[4] = lVar9;
      uVar3 = _DAT_23eeda458;
      plVar15 = _DAT_23eeda450;
      *_DAT_23eeda450 = *_DAT_23eeda450 + 1;
      plVar14[5] = (longlong)plVar15;
      cVar5 = FUN_23e8d9ac0(pcStack_138,uVar3);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        FUN_23a334bc0(plVar14);
      }
      if (cVar5 == '\0') goto LAB_23e6f678e;
      lVar9 = FUN_23e8e1c50();
      if (lVar9 == 0) {
        FUN_23e915740(param_1,auStack_b8,DAT_23eeda460);
LAB_23e6f66af:
        uVar22 = 0x59;
        goto LAB_23e6f52e4;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(lVar9);
      if (plVar14 == (longlong *)0x0) {
LAB_23e6f66f9:
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e6f66af;
      }
      lVar9 = FUN_23e8e1c50();
      if (lVar9 == 0) {
        FUN_23e915740(param_1,auStack_b8,DAT_23eeda460);
        *plVar14 = *plVar14 + -1;
        lVar9 = *plVar14;
joined_r0x00023e6f66f5:
        if (lVar9 == 0) {
          FUN_23a334bc0(plVar14);
        }
        goto LAB_23e6f66af;
      }
      plVar15 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eeda470);
      if (plVar15 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar14 = *plVar14 + -1;
        lVar9 = *plVar14;
        goto joined_r0x00023e6f66f5;
      }
      *(undefined4 *)(plVar20 + 5) = 0x59;
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
      if (pcVar17 == (code *)0x0) goto LAB_23e6f66f9;
      lVar9 = *(longlong *)pcStack_138;
      *(longlong *)pcStack_138 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        FUN_23a334bc0(pcStack_138);
      }
      lVar9 = FUN_23e8e1ef0();
      pcStack_138 = pcVar17;
      if (lVar9 == 0) {
        FUN_23e915740(param_1,auStack_b8,_DAT_23eeda340);
LAB_23e6f662d:
        uVar22 = 0x5b;
        goto LAB_23e6f52e4;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eeda478);
      if (plVar14 == (longlong *)0x0) {
LAB_23e6f6638:
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e6f662d;
      }
      *(undefined4 *)(plVar20 + 5) = 0x5b;
      plVar15 = (longlong *)FUN_23e91bfe0(param_1,plStack_128,_DAT_23eeda480);
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
        goto LAB_23e6f662d;
      }
      *(undefined4 *)(plVar20 + 5) = 0x5b;
      plVar16 = (longlong *)FUN_23e914090(param_1,plVar14);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        FUN_23a334bc0(plVar14);
      }
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        FUN_23a334bc0(plVar15);
      }
      if (plVar16 == (longlong *)0x0) goto LAB_23e6f6638;
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        FUN_23a334bc0(plVar16);
      }
      *(undefined4 *)(plVar20 + 5) = 0x5c;
      plVar14 = (longlong *)FUN_23e91bfe0(param_1,plStack_118,_DAT_23eeda488);
      if (plVar14 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        uVar22 = 0x5c;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_b0 = *(code **)(param_1 + 0x68);
        goto LAB_23e6f52e4;
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        FUN_23a334bc0(plVar14);
      }
      *(undefined4 *)(plVar20 + 5) = 0x5d;
      plVar14 = (longlong *)FUN_23e91bfe0(param_1,pcStack_120,_DAT_23eeda488);
      if (plVar14 == (longlong *)0x0) {
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        uVar22 = 0x5d;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_b0 = *(code **)(param_1 + 0x68);
        goto LAB_23e6f52e4;
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        FUN_23a334bc0(plVar14);
      }
      lVar9 = FUN_23e8e1ef0();
      if (lVar9 == 0) {
        FUN_23e915740(param_1,auStack_b8,_DAT_23eeda340);
LAB_23e6f6546:
        uVar22 = 0x5e;
        goto LAB_23e6f52e4;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eeda490);
      if (plVar14 == (longlong *)0x0) {
LAB_23e6f6551:
        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_b0 = *(code **)(param_1 + 0x68);
        pcStack_a8 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e6f6546;
      }
      plVar15 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeda328);
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
        goto LAB_23e6f6546;
      }
      *(undefined4 *)(plVar20 + 5) = 0x5e;
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
      if (plVar16 == (longlong *)0x0) goto LAB_23e6f6551;
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        FUN_23a334bc0(plVar16);
      }
      FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
      *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
        goto LAB_23e6f3ece;
      }
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) goto LAB_23e6f3ed5;
      goto LAB_23e6f3ee5;
    }
    FUN_23e915740(param_1,auStack_b8,_DAT_23eeda340);
    pcStack_138 = pcStack_a8;
    auVar23 = auStack_b8;
    pcVar17 = pcStack_b0;
LAB_23e6f5259:
    pcStack_a8 = pcStack_138;
    plVar8 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    pcStack_138 = (code *)0x0;
    plVar11 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    uVar22 = 0x46;
    plStack_130 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    pcStack_120 = (code *)0x0;
    plStack_110 = (longlong *)0x0;
    pcStack_100 = (code *)0x0;
    plStack_108 = (longlong *)0x0;
    auStack_b8 = auVar23;
    pcStack_b0 = pcVar17;
LAB_23e6f52e4:
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
        if (plVar20 == (longlong *)0x0) goto LAB_23e6f3e30;
        lVar9 = *plVar20;
      }
      else {
        *(longlong **)(param_1 + 0x138) = plVar14;
      }
      *plVar20 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar20[1] + 0x30))();
      }
      goto LAB_23e6f3e30;
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
        iVar6 = 0x45;
        goto LAB_23e6f5baa;
      }
LAB_23e6f5f6e:
      pcStack_a8 = (code *)0x0;
      uVar22 = 0x45;
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
LAB_23e6f5baa:
      pcStack_a8 = (code *)0x0;
      _auStack_b8 = (undefined1  [16])0x0;
      *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
      if (*(longlong *)pcVar18 == 0) {
        (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))();
      }
      auStack_b8 = (undefined1  [8])plVar15;
      pcStack_b0 = pcVar19;
      if (pcVar17 != (code *)0x0) {
        if (*(longlong **)(pcVar17 + 0x18) == plVar20) goto LAB_23e6f4f16;
        pcStack_a8 = pcVar17;
        if (iVar6 == 0) {
          uVar22 = (undefined4)plVar20[5];
        }
        else {
          uVar22 = 0x45;
        }
        goto LAB_23e6f4e5b;
      }
      pcStack_a8 = (code *)0x0;
      if (iVar6 != 0) goto LAB_23e6f5f6e;
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
LAB_23e6f4f16:
  pcStack_a8 = pcVar17;
  FUN_23e8bba40(plVar20,"ooooooooooooooo",plVar1,plVar10,plVar11,plVar12,plVar13,plStack_108,
                pcStack_100,plStack_110,pcStack_120,plStack_118,plStack_128,plVar8,plStack_130,
                pcStack_138,0);
  if (_DAT_23eedb218 == plVar20) {
    *plVar20 = *plVar20 + -1;
    if (*plVar20 == 0) {
      (**(code **)(plVar20[1] + 0x30))(plVar20);
    }
    _DAT_23eedb218 = (longlong *)0x0;
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
