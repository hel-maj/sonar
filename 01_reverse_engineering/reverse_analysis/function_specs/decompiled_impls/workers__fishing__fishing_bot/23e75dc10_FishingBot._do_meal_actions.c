/* ===== 23e75dc10 workers.fishing.fishing_bot:FishingBot._do_meal_actions ===== */
/* ghidra_name=FUN_23e75dc10 entry=23e75dc10 size=13370 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e75dc10(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 auVar7 [16];
  char cVar8;
  int iVar9;
  uint uVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong lVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  code *pcVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong *plVar20;
  undefined4 uVar21;
  undefined8 uVar22;
  undefined8 *puVar23;
  longlong *unaff_R13;
  longlong *plVar24;
  undefined8 uVar25;
  code *pcStack_128;
  longlong *plStack_120;
  longlong *plStack_118;
  code *pcStack_110;
  longlong *plStack_108;
  code *pcStack_100;
  code *pcStack_f8;
  undefined1 auStack_d8 [16];
  longlong *plStack_c8;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  code *pcStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_88;
  undefined8 uStack_80;
  code *pcStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  
  plVar11 = _DAT_23eedadb8;
  plVar1 = (longlong *)*param_3;
  plStack_c8 = (longlong *)0x0;
  auStack_d8 = (undefined1  [16])0x0;
  if (_DAT_23eedadb8 == (longlong *)0x0) {
LAB_23e75dc6d:
    _DAT_23eedadb8 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedaf78,DAT_23eedaeb8);
  }
  else {
    lVar13 = *_DAT_23eedadb8;
    if (1 < lVar13) {
      *_DAT_23eedadb8 = lVar13 + -1;
      goto LAB_23e75dc6d;
    }
    if (_DAT_23eedadb8[2] != 0) {
      *_DAT_23eedadb8 = lVar13 + -1;
      if (lVar13 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e75dc6d;
    }
  }
  plVar3 = _DAT_23eedadb8;
  lVar13 = *(longlong *)(param_1 + 0x38);
  plVar11 = _DAT_23eedadb8 + 9;
  lVar2 = *(longlong *)(lVar13 + 8);
  _DAT_23eedadb8[0xf] = lVar2;
  *(longlong **)(lVar13 + 8) = plVar11;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar22 = DAT_23eed89b0;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,uVar22);
  if (plVar11 == (longlong *)0x0) {
    auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_c8 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (plStack_c8 == (longlong *)0x0) {
LAB_23e75eb30:
      pcStack_110 = (code *)0x0;
      plVar15 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      plVar24 = (longlong *)0x0;
      pcStack_128 = (code *)0x0;
      plVar12 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      uVar21 = 0x3f8;
      pcStack_100 = (code *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      goto LAB_23e75eb8a;
    }
    if ((longlong *)plStack_c8[3] != plVar3) {
      pcStack_110 = (code *)0x0;
      plVar15 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      plVar24 = (longlong *)0x0;
      pcStack_128 = (code *)0x0;
      plVar12 = (longlong *)0x0;
      uVar21 = 0x3f8;
      pcStack_100 = (code *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      goto LAB_23e75e6a0;
    }
LAB_23e75f5d0:
    pcStack_110 = (code *)0x0;
    plVar15 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    plVar24 = (longlong *)0x0;
    pcStack_128 = (code *)0x0;
    plVar12 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    pcStack_100 = (code *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plVar16 = plStack_c8;
    goto LAB_23e75e75d;
  }
  *(undefined4 *)(plVar3 + 5) = 0x3f8;
  plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar11,DAT_23eed8d38);
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if (plVar12 == (longlong *)0x0) {
    auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_c8 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (plStack_c8 == (longlong *)0x0) goto LAB_23e75eb30;
    if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e75f5d0;
    pcStack_110 = (code *)0x0;
    plVar15 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    pcStack_128 = (code *)0x0;
    plVar24 = (longlong *)0x0;
    uVar21 = 0x3f8;
    pcStack_100 = (code *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plStack_108 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
LAB_23e75e6a0:
    plVar20 = plStack_c8;
    plVar16 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar16 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar18 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar18;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar17 = _PyRuntime_exref;
    plVar16[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar13 = *(longlong *)(pcVar17 + 0x1f8);
    *(undefined4 *)((longlong)plVar16 + 0x24) = uVar21;
    *(undefined4 *)(plVar16 + 4) = 0xffffffff;
    lVar13 = *(longlong *)(*(longlong *)(lVar13 + 0x10) + 0x2e8);
    lVar2 = plVar16[-1];
    puVar23 = *(undefined8 **)(lVar13 + 8);
    *puVar23 = plVar16 + -2;
    plVar16[-2] = lVar13;
    plVar16[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar23;
    *(longlong **)(lVar13 + 8) = plVar16 + -2;
    plVar16[2] = (longlong)plVar20;
    *plVar20 = *plVar20 + 1;
    plVar20 = plStack_c8;
  }
  else {
    iVar9 = FUN_23a35f020(plVar12);
    lVar13 = *plVar12 + -1;
    if (iVar9 == -1) {
      auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_c8 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar12 = lVar13;
      if (lVar13 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if (plStack_c8 == (longlong *)0x0) goto LAB_23e75eb30;
      if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e75f5d0;
      pcStack_110 = (code *)0x0;
      plVar15 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      plVar24 = (longlong *)0x0;
      pcStack_128 = (code *)0x0;
      plVar12 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      uVar21 = 0x3f8;
      pcStack_100 = (code *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
      goto LAB_23e75e6a0;
    }
    *plVar12 = lVar13;
    if (lVar13 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (iVar9 != 0) {
      plVar14 = (longlong *)0x0;
      plVar24 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      pcStack_f8 = _Py_NoneStruct_exref;
      lVar13 = *(longlong *)_Py_NoneStruct_exref;
      plStack_120 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
LAB_23e75ddbe:
      *(longlong *)pcStack_f8 = lVar13 + 1;
      lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar3 = *(longlong **)(lVar13 + 0x28);
      plVar15 = (longlong *)plVar3[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
      *(undefined4 *)(plVar3 + 8) = 0xffffffff;
      if (plVar15 != (longlong *)0x0) {
        plVar3[2] = 0;
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) {
          (**(code **)(plVar15[1] + 0x30))();
        }
      }
      *plVar3 = *plVar3 + -1;
      if (*plVar3 == 0) {
        (**(code **)(plVar3[1] + 0x30))(plVar3);
      }
      plVar3[0xf] = 0;
      plVar15 = (longlong *)0x0;
      pcStack_110 = (code *)0x0;
      pcStack_128 = (code *)0x0;
      pcStack_100 = (code *)0x0;
      if (plVar11 == (longlong *)0x0) goto LAB_23e75de5a;
      pcStack_100 = (code *)0x0;
LAB_23e75de42:
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
LAB_23e75de5a:
      if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if ((plVar24 != (longlong *)0x0) && (*plVar24 = *plVar24 + -1, *plVar24 == 0)) {
        (**(code **)(plVar24[1] + 0x30))(plVar24);
      }
      if ((plStack_108 != (longlong *)0x0) &&
         (lVar13 = *plStack_108, *plStack_108 = lVar13 + -1, lVar13 + -1 == 0)) {
        (**(code **)(plStack_108[1] + 0x30))(plStack_108);
      }
      if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if ((plStack_120 != (longlong *)0x0) &&
         (lVar13 = *plStack_120, *plStack_120 = lVar13 + -1, lVar13 + -1 == 0)) {
        (**(code **)(plStack_120[1] + 0x30))(plStack_120);
      }
      if ((plStack_118 != (longlong *)0x0) &&
         (lVar13 = *plStack_118, *plStack_118 = lVar13 + -1, lVar13 + -1 == 0)) {
        (**(code **)(plStack_118[1] + 0x30))(plStack_118);
      }
      if ((pcStack_100 != (code *)0x0) &&
         (*(longlong *)pcStack_100 = *(longlong *)pcStack_100 + -1, *(longlong *)pcStack_100 == 0))
      {
        (**(code **)(*(longlong *)(pcStack_100 + 8) + 0x30))(pcStack_100);
      }
      if ((pcStack_128 != (code *)0x0) &&
         (lVar13 = *(longlong *)pcStack_128, *(longlong *)pcStack_128 = lVar13 + -1,
         lVar13 + -1 == 0)) {
        (**(code **)(*(longlong *)(pcStack_128 + 8) + 0x30))(pcStack_128);
      }
      if ((pcStack_110 != (code *)0x0) &&
         (lVar13 = *(longlong *)pcStack_110, *(longlong *)pcStack_110 = lVar13 + -1,
         lVar13 + -1 == 0)) {
        (**(code **)(*(longlong *)(pcStack_110 + 8) + 0x30))(pcStack_110);
      }
      if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      *plVar1 = *plVar1 + -1;
      if (*plVar1 != 0) {
        return pcStack_f8;
      }
      (**(code **)(plVar1[1] + 0x30))(plVar1);
      return pcStack_f8;
    }
    lVar13 = FUN_23e8e0120();
    if (lVar13 == 0) {
      FUN_23e915740(param_1,auStack_d8,_DAT_23eed9380);
      plVar11 = (longlong *)0x0;
joined_r0x00023e75ec62:
      if (plStack_c8 != (longlong *)0x0) {
        if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e75f5d0;
        pcStack_110 = (code *)0x0;
        plVar15 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        plVar24 = (longlong *)0x0;
        pcStack_128 = (code *)0x0;
        plVar12 = (longlong *)0x0;
        uVar21 = 0x3fc;
        pcStack_100 = (code *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        goto LAB_23e75e6a0;
      }
      pcStack_110 = (code *)0x0;
      plVar15 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      plVar24 = (longlong *)0x0;
      pcStack_128 = (code *)0x0;
      plVar12 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      uVar21 = 0x3fc;
      pcStack_100 = (code *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_108 = (longlong *)0x0;
    }
    else {
      *(undefined4 *)(plVar3 + 5) = 0x3fc;
      plVar11 = (longlong *)FUN_23e91a870(param_1,lVar13);
      if (plVar11 == (longlong *)0x0) {
        auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_c8 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto joined_r0x00023e75ec62;
      }
      plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a98);
      if (plVar12 == (longlong *)0x0) {
        auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_c8 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (plStack_c8 == (longlong *)0x0) goto LAB_23e75f890;
        if ((longlong *)plStack_c8[3] != plVar3) {
          pcStack_110 = (code *)0x0;
          plVar15 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          plVar24 = (longlong *)0x0;
          pcStack_128 = (code *)0x0;
          uVar21 = 0x3ff;
          pcStack_100 = (code *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plVar12 = (longlong *)0x0;
          goto LAB_23e75e6a0;
        }
LAB_23e75f050:
        pcStack_110 = (code *)0x0;
        plVar15 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        plVar24 = (longlong *)0x0;
        pcStack_128 = (code *)0x0;
        plVar12 = (longlong *)0x0;
        pcStack_100 = (code *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        plVar16 = plStack_c8;
        goto LAB_23e75e75d;
      }
      cVar8 = FUN_23e8d9ac0(plVar11,DAT_23eed8a98,plVar12);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if (cVar8 == '\0') {
        auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_c8 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (plStack_c8 != (longlong *)0x0) {
          if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e75f050;
          pcStack_110 = (code *)0x0;
          plVar15 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          plVar24 = (longlong *)0x0;
          pcStack_128 = (code *)0x0;
          plVar12 = (longlong *)0x0;
          uVar21 = 0x3ff;
          pcStack_100 = (code *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          goto LAB_23e75e6a0;
        }
LAB_23e75f890:
        pcStack_110 = (code *)0x0;
        plVar15 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        plVar24 = (longlong *)0x0;
        pcStack_128 = (code *)0x0;
        plVar12 = (longlong *)0x0;
        uVar21 = 0x3ff;
        pcStack_100 = (code *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        goto LAB_23e75eb8a;
      }
      plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8aa8);
      if (plVar12 == (longlong *)0x0) {
        auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_c8 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (plStack_c8 != (longlong *)0x0) {
          if (plVar3 == (longlong *)plStack_c8[3]) goto LAB_23e75f050;
          pcStack_110 = (code *)0x0;
          plVar15 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          plVar24 = (longlong *)0x0;
          pcStack_128 = (code *)0x0;
          uVar21 = 0x400;
          pcStack_100 = (code *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plVar12 = (longlong *)0x0;
          goto LAB_23e75e6a0;
        }
LAB_23e75fa71:
        pcStack_110 = (code *)0x0;
        plVar15 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        plVar24 = (longlong *)0x0;
        pcStack_128 = (code *)0x0;
        plVar12 = (longlong *)0x0;
        uVar21 = 0x400;
        pcStack_100 = (code *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        goto LAB_23e75eb8a;
      }
      iVar9 = FUN_23e913250(plVar12,DAT_23eed90d8);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if (iVar9 == -1) {
        auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_c8 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (plStack_c8 == (longlong *)0x0) goto LAB_23e75fa71;
        plVar12 = (longlong *)plStack_c8[3];
joined_r0x00023e75f03f:
        if (plVar12 != plVar3) {
          pcStack_110 = (code *)0x0;
          plVar15 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          plVar24 = (longlong *)0x0;
          pcStack_128 = (code *)0x0;
          plVar12 = (longlong *)0x0;
          uVar21 = 0x400;
          pcStack_100 = (code *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          goto LAB_23e75e6a0;
        }
        goto LAB_23e75f050;
      }
      uVar22 = DAT_23eed9220;
      if (iVar9 != 1) {
        uVar22 = DAT_23eed9388;
      }
      cVar8 = FUN_23e8d9ac0(plVar11,DAT_23eed9390,uVar22);
      if (cVar8 == '\0') {
        auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_c8 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (plStack_c8 == (longlong *)0x0) goto LAB_23e75fa71;
        plVar12 = (longlong *)plStack_c8[3];
        goto joined_r0x00023e75f03f;
      }
      plVar12 = (longlong *)FUN_23e8bc2f0();
      if (plVar12 == (longlong *)0x0) {
        auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_c8 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (plStack_c8 == (longlong *)0x0) {
LAB_23e760320:
          plVar15 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          pcStack_110 = (code *)0x0;
          plVar24 = (longlong *)0x0;
          plVar12 = (longlong *)0x0;
          pcStack_128 = (code *)0x0;
          pcStack_100 = (code *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          uVar21 = 0x403;
          plStack_108 = (longlong *)0x0;
          goto LAB_23e75eb8a;
        }
        if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e75f050;
        pcStack_110 = (code *)0x0;
        plVar15 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        plVar24 = (longlong *)0x0;
        pcStack_128 = (code *)0x0;
        uVar21 = 0x403;
        pcStack_100 = (code *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        plVar12 = (longlong *)0x0;
        goto LAB_23e75e6a0;
      }
      uVar10 = FUN_23e913250();
      *plVar12 = *plVar12 + -1;
      pcVar17 = (code *)(ulonglong)uVar10;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))();
      }
      pcStack_f8 = _Py_NoneStruct_exref;
      uVar6 = _DAT_23eed93e0;
      uVar5 = _DAT_23eed93a0;
      uVar4 = _DAT_23eed9398;
      uVar25 = DAT_23eed8950;
      uVar22 = DAT_23ed6ccf0;
      plVar12 = DAT_23ed6a498;
      if (uVar10 == 0xffffffff) {
        auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_c8 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (plStack_c8 == (longlong *)0x0) goto LAB_23e760320;
        if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e75f050;
        pcStack_110 = (code *)0x0;
        plVar15 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        plVar24 = (longlong *)0x0;
        pcStack_128 = (code *)0x0;
        plVar12 = (longlong *)0x0;
        uVar21 = 0x403;
        pcStack_100 = (code *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        goto LAB_23e75e6a0;
      }
      puVar23 = &DAT_23ed6a498;
      if (uVar10 == 1) {
        *(undefined4 *)(plVar3 + 5) = 0x404;
        uStack_98 = uVar22;
        pcStack_a8 = pcStack_f8;
        uStack_a0 = uVar5;
        uStack_b8 = uVar4;
        uStack_b0 = uVar25;
        if (plVar12 == (longlong *)0x0) {
          plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"__import__");
          if (plVar12 == (longlong *)0x0) {
LAB_23e760369:
            PyErr_PrintEx(0,0);
            Py_Exit(1);
LAB_23e76037c:
            plVar14 = (longlong *)FUN_23e8d2cf0(param_1,unaff_R13,puVar23);
LAB_23e75f152:
            if (plVar14 != (longlong *)0x0) goto LAB_23e75e278;
            plStack_120 = (longlong *)0x0;
            uVar22 = *(undefined8 *)(param_1 + 0x60);
            uVar25 = *(undefined8 *)(param_1 + 0x68);
            plVar16 = *(longlong **)(param_1 + 0x70);
            goto LAB_23e75f170;
          }
          *plVar12 = *plVar12 + 1;
          DAT_23ed6a498 = plVar12;
        }
        plVar14 = (longlong *)FUN_23e95b390(param_1,plVar12);
        pcVar17 = PyModule_Type_exref;
        if (plVar14 == (longlong *)0x0) {
          auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
          plVar16 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar14 = (longlong *)0x0;
          if (plVar16 == (longlong *)0x0) {
            plVar15 = (longlong *)0x0;
            plVar24 = (longlong *)0x0;
            uVar21 = 0x404;
            pcStack_110 = (code *)0x0;
            pcStack_128 = (code *)0x0;
            pcStack_100 = (code *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plVar12 = (longlong *)0x0;
            plStack_c8 = plVar16;
            goto LAB_23e75eb8a;
          }
          if ((longlong *)plVar16[3] == plVar3) {
            plVar15 = (longlong *)0x0;
            plVar24 = (longlong *)0x0;
            plVar12 = (longlong *)0x0;
            pcStack_110 = (code *)0x0;
            pcStack_128 = (code *)0x0;
            pcStack_100 = (code *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            goto LAB_23e75e75d;
          }
          plVar24 = (longlong *)0x0;
          plVar12 = (longlong *)0x0;
        }
        else {
          if (((code *)plVar14[1] == PyModule_Type_exref) ||
             (iVar9 = PyType_IsSubtype((code *)plVar14[1],PyModule_Type_exref),
             uVar22 = _DAT_23eed93a8, iVar9 != 0)) {
            uVar4 = _DAT_23eed93a8;
            uVar25 = DAT_23eed8950;
            uVar22 = DAT_23ed6ccf0;
            pcStack_128 = PyObject_GetAttr_exref;
            plVar12 = (longlong *)PyObject_GetAttr(plVar14,_DAT_23eed93a8);
            if (plVar12 != (longlong *)0x0) goto LAB_23e75f491;
            plVar12 = (longlong *)FUN_23e970390(param_1,plVar14,uVar25,uVar4,uVar22);
LAB_23e75f69c:
            if (plVar12 != (longlong *)0x0) goto LAB_23e75f491;
            uVar22 = *(undefined8 *)(param_1 + 0x60);
            uVar25 = *(undefined8 *)(param_1 + 0x68);
            plVar16 = *(longlong **)(param_1 + 0x70);
            plVar24 = (longlong *)0x0;
          }
          else {
            pcStack_128 = PyObject_GetAttr_exref;
            plVar12 = (longlong *)PyObject_GetAttr(plVar14,_DAT_23eed93a8);
            if (plVar12 == (longlong *)0x0) {
              plVar12 = (longlong *)FUN_23e8d2cf0(param_1,plVar14,uVar22);
              goto LAB_23e75f69c;
            }
LAB_23e75f491:
            if (((code *)plVar14[1] != pcVar17) &&
               (iVar9 = PyType_IsSubtype((code *)plVar14[1],pcVar17), uVar22 = _DAT_23eed93b0,
               iVar9 == 0)) {
              plVar24 = (longlong *)(*pcStack_128)(plVar14,_DAT_23eed93b0);
              if (plVar24 == (longlong *)0x0) {
                plVar24 = (longlong *)FUN_23e8d2cf0(param_1,plVar14,uVar22);
                goto LAB_23e75f7e7;
              }
LAB_23e75f4e2:
              if (((code *)plVar14[1] == pcVar17) ||
                 (iVar9 = PyType_IsSubtype((code *)plVar14[1],pcVar17), uVar22 = _DAT_23eed93b8,
                 iVar9 != 0)) {
                uVar4 = _DAT_23eed93b8;
                uVar25 = DAT_23eed8950;
                uVar22 = DAT_23ed6ccf0;
                plStack_108 = (longlong *)(*pcStack_128)(plVar14,_DAT_23eed93b8);
                if (plStack_108 == (longlong *)0x0) {
                  plStack_108 = (longlong *)FUN_23e970390(param_1,plVar14,uVar25,uVar4,uVar22);
                  goto LAB_23e75f873;
                }
              }
              else {
                plStack_108 = (longlong *)(*pcStack_128)(plVar14,_DAT_23eed93b8);
                if (plStack_108 == (longlong *)0x0) {
                  plStack_108 = (longlong *)FUN_23e8d2cf0(param_1,plVar14,uVar22);
LAB_23e75f873:
                  if (plStack_108 == (longlong *)0x0) goto LAB_23e75f7f0;
                }
              }
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              cVar8 = FUN_23e8d9ac0(plVar11,_DAT_23eed93c0,plVar12);
              if (cVar8 == '\0') {
                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_c8 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_c8 != (longlong *)0x0) {
                  if ((longlong *)plStack_c8[3] == plVar3) {
LAB_23e75fc81:
                    pcStack_110 = (code *)0x0;
                    plVar15 = (longlong *)0x0;
                    plVar14 = (longlong *)0x0;
                    pcStack_128 = (code *)0x0;
                    pcStack_100 = (code *)0x0;
                    plStack_118 = (longlong *)0x0;
                    plStack_120 = (longlong *)0x0;
                    plVar16 = plStack_c8;
                    goto LAB_23e75e75d;
                  }
                  pcStack_110 = (code *)0x0;
                  plVar15 = (longlong *)0x0;
                  plVar14 = (longlong *)0x0;
                  uVar21 = 0x405;
                  pcStack_128 = (code *)0x0;
                  pcStack_100 = (code *)0x0;
                  plStack_118 = (longlong *)0x0;
                  plStack_120 = (longlong *)0x0;
                  goto LAB_23e75e6a0;
                }
                plVar15 = (longlong *)0x0;
                plVar14 = (longlong *)0x0;
                uVar21 = 0x405;
                pcStack_110 = (code *)0x0;
                pcStack_128 = (code *)0x0;
                pcStack_100 = (code *)0x0;
                plStack_118 = (longlong *)0x0;
                plStack_120 = (longlong *)0x0;
              }
              else {
                cVar8 = FUN_23e8d9ac0(plVar11,_DAT_23eed93c8);
                if (cVar8 == '\0') {
                  auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                  plStack_c8 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  if (plStack_c8 != (longlong *)0x0) {
                    if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e75fc81;
                    plVar15 = (longlong *)0x0;
                    plVar14 = (longlong *)0x0;
                    pcStack_110 = (code *)0x0;
                    uVar21 = 0x406;
                    pcStack_128 = (code *)0x0;
                    pcStack_100 = (code *)0x0;
                    plStack_118 = (longlong *)0x0;
                    plStack_120 = (longlong *)0x0;
                    goto LAB_23e75e6a0;
                  }
                  plVar15 = (longlong *)0x0;
                  uVar21 = 0x406;
                  pcStack_110 = (code *)0x0;
                  pcStack_128 = (code *)0x0;
                  pcStack_100 = (code *)0x0;
                  plStack_118 = (longlong *)0x0;
                  plStack_120 = (longlong *)0x0;
                  plVar14 = (longlong *)0x0;
                }
                else {
                  cVar8 = FUN_23e8d9ac0(plVar11,_DAT_23eed93d0,plStack_108);
                  if (cVar8 == '\0') {
                    auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_c8 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (plStack_c8 != (longlong *)0x0) {
                      if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e75fc81;
                      plVar15 = (longlong *)0x0;
                      plVar14 = (longlong *)0x0;
                      pcStack_110 = (code *)0x0;
                      uVar21 = 0x407;
                      pcStack_128 = (code *)0x0;
                      pcStack_100 = (code *)0x0;
                      plStack_118 = (longlong *)0x0;
                      plStack_120 = (longlong *)0x0;
                      goto LAB_23e75e6a0;
                    }
                    plVar15 = (longlong *)0x0;
                    uVar21 = 0x407;
                    pcStack_110 = (code *)0x0;
                    pcStack_128 = (code *)0x0;
                    pcStack_100 = (code *)0x0;
                    plStack_118 = (longlong *)0x0;
                    plStack_120 = (longlong *)0x0;
                    plVar14 = (longlong *)0x0;
                  }
                  else {
                    cVar8 = FUN_23e8d9ac0(plVar11,_DAT_23eed93d8,DAT_23eed90d8);
                    if (cVar8 != '\0') {
                      plStack_118 = (longlong *)0x0;
                      plVar14 = (longlong *)0x0;
                      plStack_120 = (longlong *)0x0;
                      goto LAB_23e75e3a1;
                    }
                    auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_c8 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (plStack_c8 != (longlong *)0x0) {
                      if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e75fc81;
                      plVar15 = (longlong *)0x0;
                      plVar14 = (longlong *)0x0;
                      pcStack_110 = (code *)0x0;
                      uVar21 = 0x408;
                      pcStack_128 = (code *)0x0;
                      pcStack_100 = (code *)0x0;
                      plStack_118 = (longlong *)0x0;
                      plStack_120 = (longlong *)0x0;
                      goto LAB_23e75e6a0;
                    }
                    plVar15 = (longlong *)0x0;
                    uVar21 = 0x408;
                    pcStack_110 = (code *)0x0;
                    pcStack_128 = (code *)0x0;
                    pcStack_100 = (code *)0x0;
                    plStack_118 = (longlong *)0x0;
                    plStack_120 = (longlong *)0x0;
                    plVar14 = (longlong *)0x0;
                  }
                }
              }
              goto LAB_23e75eb8a;
            }
            uVar4 = _DAT_23eed93b0;
            uVar25 = DAT_23eed8950;
            uVar22 = DAT_23ed6ccf0;
            plVar24 = (longlong *)(*pcStack_128)(plVar14);
            if (plVar24 != (longlong *)0x0) goto LAB_23e75f4e2;
            plVar24 = (longlong *)FUN_23e970390(param_1,plVar14,uVar25,uVar4,uVar22);
LAB_23e75f7e7:
            if (plVar24 != (longlong *)0x0) goto LAB_23e75f4e2;
LAB_23e75f7f0:
            uVar22 = *(undefined8 *)(param_1 + 0x60);
            uVar25 = *(undefined8 *)(param_1 + 0x68);
            plVar16 = *(longlong **)(param_1 + 0x70);
          }
          *(undefined8 *)(param_1 + 0x70) = 0;
          plStack_c8 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          auStack_d8 = (undefined1  [16])0x0;
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))();
          }
          auStack_d8._8_8_ = uVar25;
          auStack_d8._0_8_ = uVar22;
          if (plVar16 == (longlong *)0x0) {
            plVar15 = (longlong *)0x0;
            plVar14 = (longlong *)0x0;
            pcStack_110 = (code *)0x0;
            pcStack_128 = (code *)0x0;
            pcStack_100 = (code *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            uVar21 = 0x404;
            plStack_108 = (longlong *)0x0;
            plStack_c8 = plVar16;
            goto LAB_23e75eb8a;
          }
          plVar15 = (longlong *)0x0;
          pcStack_110 = (code *)0x0;
          plVar14 = (longlong *)0x0;
          pcStack_128 = (code *)0x0;
          pcStack_100 = (code *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          if ((longlong *)plVar16[3] == plVar3) goto LAB_23e75e75d;
        }
        plVar14 = (longlong *)0x0;
        pcStack_100 = (code *)0x0;
        plStack_108 = (longlong *)0x0;
        pcStack_110 = (code *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        pcStack_128 = (code *)0x0;
        plVar15 = (longlong *)0x0;
        uVar21 = 0x404;
        plStack_c8 = plVar16;
        goto LAB_23e75e6a0;
      }
      *(undefined4 *)(plVar3 + 5) = 0x40a;
      uStack_68 = uVar22;
      pcStack_78 = pcStack_f8;
      uStack_70 = uVar6;
      uStack_88 = uVar4;
      uStack_80 = uVar25;
      if (plVar12 == (longlong *)0x0) {
        plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"__import__");
        if (plVar12 == (longlong *)0x0) goto LAB_23e760369;
        *plVar12 = *plVar12 + 1;
        DAT_23ed6a498 = plVar12;
      }
      unaff_R13 = (longlong *)FUN_23e95b390(param_1,plVar12,&uStack_88);
      pcVar17 = PyModule_Type_exref;
      if (unaff_R13 == (longlong *)0x0) {
        auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
        plVar16 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar24 = (longlong *)0x0;
        if (plVar16 == (longlong *)0x0) {
          plVar15 = (longlong *)0x0;
          uVar21 = 0x40a;
          pcStack_110 = (code *)0x0;
          pcStack_128 = (code *)0x0;
          pcStack_100 = (code *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          plVar12 = (longlong *)0x0;
          plStack_c8 = plVar16;
          goto LAB_23e75eb8a;
        }
        if ((longlong *)plVar16[3] == plVar3) {
          plVar15 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          pcStack_110 = (code *)0x0;
          plVar12 = (longlong *)0x0;
          pcStack_128 = (code *)0x0;
          pcStack_100 = (code *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          goto LAB_23e75e75d;
        }
        plVar14 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
LAB_23e75f222:
        plVar24 = (longlong *)0x0;
        pcStack_100 = (code *)0x0;
        plStack_108 = (longlong *)0x0;
        pcStack_110 = (code *)0x0;
        plStack_118 = (longlong *)0x0;
        pcStack_128 = (code *)0x0;
        plVar12 = (longlong *)0x0;
        plVar15 = (longlong *)0x0;
        uVar21 = 0x40a;
        plStack_c8 = plVar16;
        goto LAB_23e75e6a0;
      }
      if (((code *)unaff_R13[1] == PyModule_Type_exref) ||
         (iVar9 = PyType_IsSubtype((code *)unaff_R13[1],PyModule_Type_exref),
         puVar23 = _DAT_23eed93e8, iVar9 != 0)) {
        puVar23 = _DAT_23eed93e8;
        uVar25 = DAT_23eed8950;
        uVar22 = DAT_23ed6ccf0;
        pcStack_128 = PyObject_GetAttr_exref;
        plVar14 = (longlong *)PyObject_GetAttr(unaff_R13,_DAT_23eed93e8);
        if (plVar14 == (longlong *)0x0) {
          plVar14 = (longlong *)FUN_23e970390(param_1,unaff_R13,uVar25,puVar23,uVar22);
          goto LAB_23e75f152;
        }
      }
      else {
        pcStack_128 = PyObject_GetAttr_exref;
        plVar14 = (longlong *)PyObject_GetAttr(unaff_R13,_DAT_23eed93e8);
        if (plVar14 == (longlong *)0x0) goto LAB_23e76037c;
      }
LAB_23e75e278:
      if (((code *)unaff_R13[1] == pcVar17) ||
         (iVar9 = PyType_IsSubtype((code *)unaff_R13[1],pcVar17), uVar22 = _DAT_23eed93f0,
         iVar9 != 0)) {
        uVar4 = _DAT_23eed93f0;
        uVar25 = DAT_23eed8950;
        uVar22 = DAT_23ed6ccf0;
        plStack_120 = (longlong *)(*pcStack_128)(unaff_R13,_DAT_23eed93f0);
        if (plStack_120 == (longlong *)0x0) {
          plStack_120 = (longlong *)FUN_23e970390(param_1,unaff_R13,uVar25,uVar4,uVar22);
          goto LAB_23e75f2a5;
        }
LAB_23e75e2be:
        if (((code *)unaff_R13[1] == pcVar17) ||
           (iVar9 = PyType_IsSubtype((code *)unaff_R13[1],pcVar17), uVar22 = _DAT_23eed93f8,
           iVar9 != 0)) {
          uVar4 = _DAT_23eed93f8;
          uVar25 = DAT_23eed8950;
          uVar22 = DAT_23ed6ccf0;
          plStack_118 = (longlong *)(*pcStack_128)(unaff_R13,_DAT_23eed93f8);
          if (plStack_118 == (longlong *)0x0) {
            plStack_118 = (longlong *)FUN_23e970390(param_1,unaff_R13,uVar25,uVar4,uVar22);
            goto LAB_23e75f3c5;
          }
        }
        else {
          plStack_118 = (longlong *)(*pcStack_128)(unaff_R13,_DAT_23eed93f8);
          if (plStack_118 == (longlong *)0x0) {
            plStack_118 = (longlong *)FUN_23e8d2cf0(param_1,unaff_R13,uVar22);
LAB_23e75f3c5:
            if (plStack_118 == (longlong *)0x0) goto LAB_23e75f2b4;
          }
        }
        *unaff_R13 = *unaff_R13 + -1;
        if (*unaff_R13 == 0) {
          (**(code **)(unaff_R13[1] + 0x30))(unaff_R13);
        }
        cVar8 = FUN_23e8d9ac0(plVar11,_DAT_23eed93c0,plVar14);
        if (cVar8 == '\0') {
          auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_c8 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (plStack_c8 != (longlong *)0x0) {
            if ((longlong *)plStack_c8[3] == plVar3) {
LAB_23e75fa34:
              pcStack_110 = (code *)0x0;
              plVar15 = (longlong *)0x0;
              plVar24 = (longlong *)0x0;
              plVar12 = (longlong *)0x0;
              pcStack_128 = (code *)0x0;
              pcStack_100 = (code *)0x0;
              plStack_108 = (longlong *)0x0;
              plVar16 = plStack_c8;
              goto LAB_23e75e75d;
            }
            pcStack_110 = (code *)0x0;
            plVar15 = (longlong *)0x0;
            plVar24 = (longlong *)0x0;
            plVar12 = (longlong *)0x0;
            pcStack_128 = (code *)0x0;
            uVar21 = 0x40b;
            pcStack_100 = (code *)0x0;
            plStack_108 = (longlong *)0x0;
            goto LAB_23e75e6a0;
          }
          plVar15 = (longlong *)0x0;
          plVar12 = (longlong *)0x0;
          uVar21 = 0x40b;
          pcStack_110 = (code *)0x0;
          pcStack_128 = (code *)0x0;
          pcStack_100 = (code *)0x0;
          plStack_108 = (longlong *)0x0;
          plVar24 = (longlong *)0x0;
        }
        else {
          cVar8 = FUN_23e8d9ac0(plVar11,_DAT_23eed93c8,plStack_120);
          if (cVar8 == '\0') {
            auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
            plStack_c8 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (plStack_c8 != (longlong *)0x0) {
              if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e75fa34;
              pcStack_110 = (code *)0x0;
              plVar15 = (longlong *)0x0;
              plVar24 = (longlong *)0x0;
              plVar12 = (longlong *)0x0;
              pcStack_128 = (code *)0x0;
              uVar21 = 0x40c;
              pcStack_100 = (code *)0x0;
              plStack_108 = (longlong *)0x0;
              goto LAB_23e75e6a0;
            }
            plVar15 = (longlong *)0x0;
            plVar24 = (longlong *)0x0;
            uVar21 = 0x40c;
            pcStack_110 = (code *)0x0;
            pcStack_128 = (code *)0x0;
            pcStack_100 = (code *)0x0;
            plStack_108 = (longlong *)0x0;
            plVar12 = (longlong *)0x0;
            goto LAB_23e75eb8a;
          }
          cVar8 = FUN_23e8d9ac0(plVar11,_DAT_23eed93d0,plStack_118);
          if (cVar8 == '\0') {
            auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
            plStack_c8 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (plStack_c8 != (longlong *)0x0) {
              if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e75fa34;
              pcStack_110 = (code *)0x0;
              plVar15 = (longlong *)0x0;
              plVar24 = (longlong *)0x0;
              plVar12 = (longlong *)0x0;
              pcStack_128 = (code *)0x0;
              uVar21 = 0x40d;
              pcStack_100 = (code *)0x0;
              plStack_108 = (longlong *)0x0;
              goto LAB_23e75e6a0;
            }
            plVar15 = (longlong *)0x0;
            plVar24 = (longlong *)0x0;
            plVar12 = (longlong *)0x0;
            pcStack_110 = (code *)0x0;
            uVar21 = 0x40d;
            pcStack_128 = (code *)0x0;
            pcStack_100 = (code *)0x0;
            plStack_108 = (longlong *)0x0;
            goto LAB_23e75eb8a;
          }
          cVar8 = FUN_23e8d9ac0(plVar11,_DAT_23eed93d8,DAT_23ed6cd28);
          if (cVar8 == '\0') {
            auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
            plStack_c8 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (plStack_c8 != (longlong *)0x0) {
              if ((longlong *)plStack_c8[3] == plVar3) goto LAB_23e75fa34;
              plVar15 = (longlong *)0x0;
              plVar24 = (longlong *)0x0;
              pcStack_110 = (code *)0x0;
              plVar12 = (longlong *)0x0;
              uVar21 = 0x40e;
              pcStack_128 = (code *)0x0;
              pcStack_100 = (code *)0x0;
              plStack_108 = (longlong *)0x0;
              goto LAB_23e75e6a0;
            }
            plVar15 = (longlong *)0x0;
            plVar24 = (longlong *)0x0;
            uVar21 = 0x40e;
            pcStack_110 = (code *)0x0;
            pcStack_128 = (code *)0x0;
            pcStack_100 = (code *)0x0;
            plStack_108 = (longlong *)0x0;
            plVar12 = (longlong *)0x0;
            goto LAB_23e75eb8a;
          }
          plStack_108 = (longlong *)0x0;
          plVar24 = (longlong *)0x0;
          plVar12 = (longlong *)0x0;
LAB_23e75e3a1:
          lVar13 = FUN_23e8dffd0();
          if (lVar13 == 0) {
            FUN_23e915740(param_1,auStack_d8,DAT_23eed9400);
            if (plStack_c8 != (longlong *)0x0) {
              plVar15 = (longlong *)plStack_c8[3];
joined_r0x00023e75fe4d:
              pcStack_100 = (code *)0x0;
              if (plVar15 != plVar3) {
                plVar15 = (longlong *)0x0;
                uVar21 = 0x411;
                pcStack_110 = (code *)0x0;
                pcStack_128 = (code *)0x0;
                goto LAB_23e75e6a0;
              }
              goto LAB_23e75fe53;
            }
          }
          else {
            *(undefined4 *)(plVar3 + 5) = 0x411;
            plVar15 = (longlong *)FUN_23e91a870(param_1,lVar13);
            if (plVar15 == (longlong *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_c8 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (plStack_c8 != (longlong *)0x0) {
                if ((longlong *)plStack_c8[3] != plVar3) {
                  plVar15 = (longlong *)0x0;
                  uVar21 = 0x411;
                  pcStack_110 = (code *)0x0;
                  pcStack_100 = (code *)0x0;
                  pcStack_128 = (code *)0x0;
                  goto LAB_23e75e6a0;
                }
                goto LAB_23e75fe53;
              }
            }
            else {
              plVar16 = (longlong *)FUN_23e8c6f80(plVar15,_DAT_23eed9408);
              lVar13 = *plVar15;
              *plVar15 = lVar13 + -1;
              if (lVar13 + -1 == 0) {
                (**(code **)(plVar15[1] + 0x30))();
              }
              if (plVar16 == (longlong *)0x0) {
                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_c8 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_c8 != (longlong *)0x0) {
                  plVar15 = (longlong *)plStack_c8[3];
                  goto joined_r0x00023e75fe4d;
                }
              }
              else {
                cVar8 = FUN_23e8d9ac0(plVar11,DAT_23eed9410);
                lVar13 = *plVar16;
                *plVar16 = lVar13 + -1;
                if (lVar13 + -1 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                if (cVar8 != '\0') {
                  *(undefined4 *)(plVar3 + 5) = 0x414;
                  plVar15 = (longlong *)FUN_23e91bfe0(param_1,plVar11,DAT_23eed9418);
                  if (plVar15 == (longlong *)0x0) {
                    auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_c8 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (plStack_c8 == (longlong *)0x0) {
LAB_23e760fa9:
                      plVar15 = (longlong *)0x0;
                      uVar21 = 0x414;
                      pcStack_110 = (code *)0x0;
                      pcStack_128 = (code *)0x0;
                      pcStack_100 = (code *)0x0;
                      goto LAB_23e75eb8a;
                    }
                    if ((longlong *)plStack_c8[3] != plVar3) {
                      plVar15 = (longlong *)0x0;
                      pcStack_110 = (code *)0x0;
                      pcStack_128 = (code *)0x0;
                      uVar21 = 0x414;
                      pcStack_100 = (code *)0x0;
                      goto LAB_23e75e6a0;
                    }
                  }
                  else {
                    iVar9 = FUN_23a35f020(plVar15);
                    lVar13 = *plVar15;
                    *plVar15 = lVar13 + -1;
                    if (lVar13 + -1 == 0) {
                      (**(code **)(plVar15[1] + 0x30))(plVar15);
                    }
                    if (iVar9 == -1) {
                      auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                      plStack_c8 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      if (plStack_c8 == (longlong *)0x0) goto LAB_23e760fa9;
                      if ((longlong *)plStack_c8[3] != plVar3) {
                        plVar15 = (longlong *)0x0;
                        uVar21 = 0x414;
                        pcStack_110 = (code *)0x0;
                        pcStack_128 = (code *)0x0;
                        pcStack_100 = (code *)0x0;
                        goto LAB_23e75e6a0;
                      }
                    }
                    else {
                      if (iVar9 != 0) {
                        *(undefined4 *)(plVar3 + 5) = 0x41b;
                        uVar22 = _DAT_23eed9428;
                        *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
                        plVar15 = (longlong *)FUN_23e91bfe0(param_1,plVar11,uVar22);
                        if (plVar15 == (longlong *)0x0) {
                          plStack_c8 = *(longlong **)(param_1 + 0x70);
                          auStack_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                          auStack_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e760553:
                          uVar22 = 0x41b;
                          pcStack_110 = (code *)0x0;
                          pcStack_128 = (code *)0x0;
LAB_23e76056a:
                          plVar16 = plStack_c8;
                          plStack_c8 = (longlong *)0x0;
                          pcStack_78 = (code *)plVar16;
                          plVar15 = *(longlong **)(param_1 + 0x138);
                          uStack_88 = auStack_d8._0_8_;
                          uStack_80 = auStack_d8._8_8_;
                          auStack_d8 = (undefined1  [16])0x0;
                          if (plVar15 != (longlong *)0x0) {
                            *plVar15 = *plVar15 + 1;
                          }
                          if (plVar16 == (longlong *)0x0) {
                            pcVar17 = (code *)FUN_23e8d6280(plVar3,uVar22);
                          }
                          else {
                            pcVar17 = (code *)FUN_23e8d6280(plVar3,uVar22);
                            *(longlong **)(pcVar17 + 0x10) = plVar16;
                            *plVar16 = *plVar16 + 1;
                          }
                          if ((pcStack_78 != (code *)0x0) &&
                             (*(longlong *)pcStack_78 = *(longlong *)pcStack_78 + -1,
                             *(longlong *)pcStack_78 == 0)) {
                            FUN_23a334bc0();
                          }
                          pcStack_78 = pcVar17;
                          FUN_23a35ef40(param_1,&uStack_88);
                          iVar9 = FUN_23a35ebd0(param_1,*(undefined8 *)
                                                         (*(longlong *)(param_1 + 0x138) + 8),
                                                *(undefined8 *)PyExc_Exception_exref);
                          if (iVar9 == 0) {
                            cVar8 = FUN_23e8ba320(*(undefined8 *)(param_1 + 0x138),auStack_d8);
                            plVar16 = plStack_c8;
                            auVar7 = auStack_d8;
                            iVar9 = 0;
                            if (cVar8 == '\0') {
                              iVar9 = 0x41a;
                            }
                            if (plStack_c8 == (longlong *)0x0) {
                              auStack_d8 = (undefined1  [16])0x0;
                              FUN_23ebf6ae0(param_1);
                              plStack_c8 = (longlong *)0x0;
                              if (iVar9 == 0) {
                                pcStack_100 = _Py_FalseStruct_exref;
                                uVar21 = (undefined4)plVar3[5];
                                plVar15 = (longlong *)0x0;
                                auStack_d8 = auVar7;
                              }
                              else {
                                pcStack_100 = _Py_FalseStruct_exref;
                                plVar15 = (longlong *)0x0;
                                uVar21 = 0x41a;
                                auStack_d8 = auVar7;
                              }
                              goto LAB_23e75eb8a;
                            }
                            if ((longlong *)plStack_c8[3] == plVar3) {
                              *(undefined4 *)(plVar3 + 5) =
                                   *(undefined4 *)((longlong)plStack_c8 + 0x24);
                            }
                            plStack_c8 = (longlong *)0x0;
                            auStack_d8 = (undefined1  [16])0x0;
                            FUN_23ebf6ae0(param_1,plVar15);
                            auStack_d8 = auVar7;
                            plStack_c8 = plVar16;
                            if ((longlong *)plVar16[3] != plVar3) {
                              if (iVar9 == 0) {
                                pcStack_100 = _Py_FalseStruct_exref;
                                uVar21 = (undefined4)plVar3[5];
                                plVar15 = (longlong *)0x0;
                              }
                              else {
                                pcStack_100 = _Py_FalseStruct_exref;
                                plVar15 = (longlong *)0x0;
                                uVar21 = 0x41a;
                              }
                              goto LAB_23e75e6a0;
                            }
                          }
                          else {
                            plVar16 = *(longlong **)(param_1 + 0x138);
                            *plVar16 = *plVar16 + 1;
                            plVar18 = (longlong *)FUN_23e8bc2f0();
                            plVar20 = _DAT_23eed9440;
                            if (plVar18 == (longlong *)0x0) {
LAB_23e760d8a:
                              auStack_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                              auStack_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                              plStack_c8 = *(longlong **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            }
                            else {
                              plVar19 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2)
                              ;
                              *plVar20 = *plVar20 + 1;
                              plVar19[3] = (longlong)plVar20;
                              lVar13 = FUN_23e94f9d0(param_1,plVar16,DAT_23ed6cd28);
                              if (lVar13 == 0) {
                                auStack_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                auStack_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                plStack_c8 = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *plVar18 = *plVar18 + -1;
                                if (*plVar18 == 0) {
                                  FUN_23a334bc0(plVar18);
                                }
                                *plVar19 = *plVar19 + -1;
                                if (*plVar19 == 0) {
                                  FUN_23a334bc0(plVar19);
                                }
                              }
                              else {
                                plVar19[4] = lVar13;
                                plVar20 = (longlong *)PyUnicode_Join(DAT_23ed6cd28);
                                *plVar19 = *plVar19 + -1;
                                if (*plVar19 == 0) {
                                  FUN_23a334bc0(plVar19);
                                }
                                if (plVar20 != (longlong *)0x0) {
                                  *(undefined4 *)(plVar3 + 5) = 0x423;
                                  plVar19 = (longlong *)FUN_23e914090(param_1,plVar18);
                                  *plVar18 = *plVar18 + -1;
                                  if (*plVar18 == 0) {
                                    FUN_23a334bc0();
                                  }
                                  *plVar20 = *plVar20 + -1;
                                  if (*plVar20 == 0) {
                                    FUN_23a334bc0();
                                  }
                                  if (plVar19 != (longlong *)0x0) {
                                    *plVar19 = *plVar19 + -1;
                                    if (*plVar19 == 0) {
                                      FUN_23a334bc0(plVar19);
                                    }
                                    lVar13 = *plVar16;
                                    *plVar16 = lVar13 + -1;
                                    if (lVar13 + -1 == 0) {
                                      FUN_23a334bc0(plVar16);
                                    }
                                    FUN_23ebf6ae0(param_1,plVar15);
                                    pcStack_100 = _Py_FalseStruct_exref;
                                    goto LAB_23e75fff9;
                                  }
                                  goto LAB_23e760d8a;
                                }
                                auStack_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                auStack_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                plStack_c8 = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *plVar18 = *plVar18 + -1;
                                if (*plVar18 == 0) {
                                  FUN_23a334bc0(plVar18);
                                }
                              }
                            }
                            plVar20 = plStack_c8;
                            uVar25 = auStack_d8._8_8_;
                            uVar22 = auStack_d8._0_8_;
                            plStack_c8 = (longlong *)0x0;
                            auStack_d8 = (undefined1  [16])0x0;
                            lVar13 = *plVar16;
                            *plVar16 = lVar13 + -1;
                            if (lVar13 + -1 == 0) {
                              FUN_23a334bc0(plVar16);
                            }
                            plStack_c8 = (longlong *)0x0;
                            auStack_d8 = (undefined1  [16])0x0;
                            FUN_23ebf6ae0(param_1,plVar15);
                            pcStack_100 = _Py_FalseStruct_exref;
                            auStack_d8 = CONCAT88(uVar25,uVar22);
                            plStack_c8 = plVar20;
                            if (plVar20 == (longlong *)0x0) {
                              uVar21 = 0x423;
                              plVar15 = (longlong *)0x0;
                              goto LAB_23e75eb8a;
                            }
                            if ((longlong *)plVar20[3] != plVar3) {
                              plVar15 = (longlong *)0x0;
                              uVar21 = 0x423;
                              goto LAB_23e75e6a0;
                            }
                          }
                          plVar15 = (longlong *)0x0;
                          pcStack_100 = _Py_FalseStruct_exref;
                          plVar16 = plStack_c8;
                          goto LAB_23e75e75d;
                        }
                        iVar9 = FUN_23a35f020(plVar15);
                        pcVar17 = _Py_FalseStruct_exref;
                        lVar13 = *plVar15 + -1;
                        if (iVar9 == -1) {
                          auStack_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                          auStack_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                          plStack_c8 = *(longlong **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          *plVar15 = lVar13;
                          if (lVar13 == 0) {
                            FUN_23a334bc0(plVar15);
                          }
                          goto LAB_23e760553;
                        }
                        *plVar15 = lVar13;
                        if (lVar13 == 0) {
                          FUN_23a334bc0(plVar15);
                          pcVar17 = _Py_FalseStruct_exref;
                        }
                        pcStack_100 = _Py_TrueStruct_exref;
                        if (iVar9 == 0) {
                          *(undefined4 *)(plVar3 + 5) = 0x41f;
                          pcStack_128 = (code *)FUN_23e91bfe0(param_1,plVar11,_DAT_23eed9430);
                          if (pcStack_128 == (code *)0x0) {
                            auStack_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                            auStack_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                            plStack_c8 = *(longlong **)(param_1 + 0x70);
                            uVar22 = 0x41f;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            pcStack_110 = (code *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          }
                          else {
                            *(undefined4 *)(plVar3 + 5) = 0x420;
                            pcStack_110 = (code *)FUN_23e91bfe0(param_1,plVar11,_DAT_23eed9438);
                            if (pcStack_110 == (code *)0x0) {
                              auStack_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                              auStack_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                              plStack_c8 = *(longlong **)(param_1 + 0x70);
                              uVar22 = 0x420;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            }
                            else {
                              iVar9 = FUN_23a35f020(pcStack_128);
                              pcVar17 = _Py_FalseStruct_exref;
                              if (iVar9 != -1) {
                                pcStack_100 = pcStack_128;
                                if (iVar9 != 1) {
                                  pcStack_100 = pcStack_110;
                                }
                                *(longlong *)pcStack_100 = *(longlong *)pcStack_100 + 1;
                                *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
                                if (*(longlong *)pcVar17 == 0) {
                                  FUN_23a334bc0(pcVar17);
                                }
                                goto LAB_23e75fff9;
                              }
                              auStack_d8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                              auStack_d8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                              plStack_c8 = *(longlong **)(param_1 + 0x70);
                              uVar22 = 0x421;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            }
                          }
                          goto LAB_23e76056a;
                        }
                        *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
                        *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
                        if (*(longlong *)pcVar17 == 0) {
                          FUN_23a334bc0(pcVar17);
                        }
                        pcStack_110 = (code *)0x0;
                        pcStack_128 = (code *)0x0;
LAB_23e75fff9:
                        lVar13 = FUN_23e8e07b0();
                        if (lVar13 == 0) {
                          FUN_23e915740(param_1,auStack_d8,DAT_23eed8f68);
                          plVar15 = (longlong *)0x0;
joined_r0x00023e760ea7:
                          if (plStack_c8 == (longlong *)0x0) {
                            plVar15 = (longlong *)0x0;
                            uVar21 = 0x426;
                            goto LAB_23e75eb8a;
                          }
                          uVar21 = 0x426;
                          plVar20 = (longlong *)plStack_c8[3];
                        }
                        else {
                          *(undefined4 *)(plVar3 + 5) = 0x426;
                          plVar15 = (longlong *)FUN_23e91a870(param_1,lVar13);
                          if (plVar15 == (longlong *)0x0) {
                            auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                            plStack_c8 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            goto joined_r0x00023e760ea7;
                          }
                          iVar9 = FUN_23a35f020(pcStack_100);
                          if (iVar9 != -1) {
                            if (iVar9 == 0) {
                              *(undefined4 *)(plVar3 + 5) = 0x42a;
                              plVar16 = (longlong *)FUN_23e91bfe0(param_1,plVar15,_DAT_23eed9450);
                              if (plVar16 != (longlong *)0x0) goto LAB_23e76006b;
                              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                              plStack_c8 = *(longlong **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              if (plStack_c8 != (longlong *)0x0) {
                                uVar21 = 0x42a;
                                plVar20 = (longlong *)plStack_c8[3];
                                goto joined_r0x00023e760a86;
                              }
                              uVar21 = 0x42a;
                            }
                            else {
                              *(undefined4 *)(plVar3 + 5) = 0x428;
                              plVar16 = (longlong *)FUN_23e91bfe0(param_1,plVar15,_DAT_23eed9448);
                              if (plVar16 != (longlong *)0x0) {
LAB_23e76006b:
                                *plVar16 = *plVar16 + -1;
                                if (*plVar16 == 0) {
                                  FUN_23a334bc0();
                                }
                                FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                                *(longlong *)pcStack_f8 = *(longlong *)pcStack_f8 + 1;
                                goto LAB_23e75de42;
                              }
                              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                              plStack_c8 = *(longlong **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              if (plStack_c8 != (longlong *)0x0) {
                                uVar21 = 0x428;
                                plVar20 = (longlong *)plStack_c8[3];
                                goto joined_r0x00023e760a86;
                              }
                              uVar21 = 0x428;
                            }
                            goto LAB_23e75eb8a;
                          }
                          auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                          plStack_c8 = *(longlong **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          if (plStack_c8 == (longlong *)0x0) {
                            uVar21 = 0x427;
                            goto LAB_23e75eb8a;
                          }
                          uVar21 = 0x427;
                          plVar20 = (longlong *)plStack_c8[3];
                        }
joined_r0x00023e760a86:
                        plVar16 = plStack_c8;
                        if (plVar20 == plVar3) goto LAB_23e75e75d;
                        goto LAB_23e75e6a0;
                      }
                      *(undefined4 *)(plVar3 + 5) = 0x415;
                      plVar15 = (longlong *)FUN_23e915840(param_1,plVar1);
                      if (plVar15 != (longlong *)0x0) {
                        lVar13 = *plVar15;
                        *plVar15 = lVar13 + -1;
                        if (lVar13 + -1 == 0) {
                          FUN_23a334bc0(plVar15);
                        }
                        lVar13 = *(longlong *)pcStack_f8;
                        goto LAB_23e75ddbe;
                      }
                      auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                      plStack_c8 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      if (plStack_c8 == (longlong *)0x0) {
                        plVar15 = (longlong *)0x0;
                        uVar21 = 0x415;
                        pcStack_110 = (code *)0x0;
                        pcStack_128 = (code *)0x0;
                        pcStack_100 = (code *)0x0;
                        goto LAB_23e75eb8a;
                      }
                      if ((longlong *)plStack_c8[3] != plVar3) {
                        plVar15 = (longlong *)0x0;
                        uVar21 = 0x415;
                        pcStack_110 = (code *)0x0;
                        pcStack_100 = (code *)0x0;
                        pcStack_128 = (code *)0x0;
                        goto LAB_23e75e6a0;
                      }
                    }
                  }
LAB_23e75fe53:
                  pcStack_110 = (code *)0x0;
                  plVar15 = (longlong *)0x0;
                  pcStack_128 = (code *)0x0;
                  pcStack_100 = (code *)0x0;
                  plVar16 = plStack_c8;
                  goto LAB_23e75e75d;
                }
                auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_c8 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (plStack_c8 != (longlong *)0x0) {
                  if (plVar3 != (longlong *)plStack_c8[3]) {
                    plVar15 = (longlong *)0x0;
                    uVar21 = 0x411;
                    pcStack_110 = (code *)0x0;
                    pcStack_128 = (code *)0x0;
                    pcStack_100 = (code *)0x0;
                    goto LAB_23e75e6a0;
                  }
                  goto LAB_23e75fe53;
                }
              }
            }
          }
          plVar15 = (longlong *)0x0;
          uVar21 = 0x411;
          pcStack_110 = (code *)0x0;
          pcStack_128 = (code *)0x0;
          pcStack_100 = (code *)0x0;
        }
      }
      else {
        plStack_120 = (longlong *)(*pcStack_128)(unaff_R13,_DAT_23eed93f0);
        if (plStack_120 != (longlong *)0x0) goto LAB_23e75e2be;
        plStack_120 = (longlong *)FUN_23e8d2cf0(param_1,unaff_R13,uVar22);
LAB_23e75f2a5:
        if (plStack_120 != (longlong *)0x0) goto LAB_23e75e2be;
LAB_23e75f2b4:
        uVar22 = *(undefined8 *)(param_1 + 0x60);
        uVar25 = *(undefined8 *)(param_1 + 0x68);
        plVar16 = *(longlong **)(param_1 + 0x70);
LAB_23e75f170:
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_c8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        auStack_d8 = (undefined1  [16])0x0;
        *unaff_R13 = *unaff_R13 + -1;
        if (*unaff_R13 == 0) {
          (**(code **)(unaff_R13[1] + 0x30))(unaff_R13);
        }
        auStack_d8._8_8_ = uVar25;
        auStack_d8._0_8_ = uVar22;
        if (plVar16 != (longlong *)0x0) {
          plVar15 = (longlong *)0x0;
          pcStack_110 = (code *)0x0;
          plVar24 = (longlong *)0x0;
          pcStack_128 = (code *)0x0;
          plVar12 = (longlong *)0x0;
          pcStack_100 = (code *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_108 = (longlong *)0x0;
          if ((longlong *)plVar16[3] == plVar3) goto LAB_23e75e75d;
          goto LAB_23e75f222;
        }
        pcStack_110 = (code *)0x0;
        plVar15 = (longlong *)0x0;
        plVar24 = (longlong *)0x0;
        plVar12 = (longlong *)0x0;
        pcStack_128 = (code *)0x0;
        uVar21 = 0x40a;
        pcStack_100 = (code *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_108 = (longlong *)0x0;
        plStack_c8 = plVar16;
      }
    }
LAB_23e75eb8a:
    plVar16 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar16 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      plVar20 = plStack_c8;
    }
    else {
      plVar20 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar20;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar20 = (longlong *)0x0;
    }
    pcVar17 = _PyRuntime_exref;
    plVar16[2] = 0;
    plVar16[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar13 = *(longlong *)(pcVar17 + 0x1f8);
    *(undefined4 *)((longlong)plVar16 + 0x24) = uVar21;
    lVar13 = *(longlong *)(lVar13 + 0x10);
    *(undefined4 *)(plVar16 + 4) = 0xffffffff;
    lVar13 = *(longlong *)(lVar13 + 0x2e8);
    lVar2 = plVar16[-1];
    puVar23 = *(undefined8 **)(lVar13 + 8);
    *puVar23 = plVar16 + -2;
    plVar16[-2] = lVar13;
    plVar16[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar23;
    *(longlong **)(lVar13 + 8) = plVar16 + -2;
  }
  if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
    (**(code **)(plVar20[1] + 0x30))();
  }
LAB_23e75e75d:
  plStack_c8 = plVar16;
  FUN_23e8bba40(plVar3,"ooooooooooooo",plVar1,plVar11,plVar12,plVar24,plStack_108,plVar14,
                plStack_120,plStack_118,pcStack_100,pcStack_128,pcStack_110,0,plVar15);
  if (_DAT_23eedadb8 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eedadb8 = (longlong *)0x0;
  }
  lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar13 + 0x28);
  plVar16 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
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
  plVar16 = plStack_c8;
  plVar3[0xf] = 0;
  uVar22 = auStack_d8._0_8_;
  uVar25 = auStack_d8._8_8_;
  auStack_d8 = (undefined1  [16])0x0;
  plStack_c8 = (longlong *)0x0;
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar24 != (longlong *)0x0) && (*plVar24 = *plVar24 + -1, *plVar24 == 0)) {
    (**(code **)(plVar24[1] + 0x30))(plVar24);
  }
  if ((plStack_108 != (longlong *)0x0) &&
     (lVar13 = *plStack_108, *plStack_108 = lVar13 + -1, lVar13 + -1 == 0)) {
    (**(code **)(plStack_108[1] + 0x30))(plStack_108);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((plStack_120 != (longlong *)0x0) &&
     (lVar13 = *plStack_120, *plStack_120 = lVar13 + -1, lVar13 + -1 == 0)) {
    (**(code **)(plStack_120[1] + 0x30))(plStack_120);
  }
  if ((plStack_118 != (longlong *)0x0) &&
     (lVar13 = *plStack_118, *plStack_118 = lVar13 + -1, lVar13 + -1 == 0)) {
    (**(code **)(plStack_118[1] + 0x30))(plStack_118);
  }
  if ((pcStack_100 != (code *)0x0) &&
     (lVar13 = *(longlong *)pcStack_100, *(longlong *)pcStack_100 = lVar13 + -1, lVar13 + -1 == 0))
  {
    (**(code **)(*(longlong *)(pcStack_100 + 8) + 0x30))(pcStack_100);
  }
  if ((pcStack_128 != (code *)0x0) &&
     (lVar13 = *(longlong *)pcStack_128, *(longlong *)pcStack_128 = lVar13 + -1, lVar13 + -1 == 0))
  {
    (**(code **)(*(longlong *)(pcStack_128 + 8) + 0x30))(pcStack_128);
  }
  if ((pcStack_110 != (code *)0x0) &&
     (lVar13 = *(longlong *)pcStack_110, *(longlong *)pcStack_110 = lVar13 + -1, lVar13 + -1 == 0))
  {
    (**(code **)(*(longlong *)(pcStack_110 + 8) + 0x30))(pcStack_110);
  }
  if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  *plVar1 = *plVar1 + -1;
  plStack_c8 = plVar16;
  auStack_d8._0_8_ = uVar22;
  auStack_d8._8_8_ = uVar25;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,auStack_d8._0_8_,auStack_d8._8_8_,plStack_c8);
  return (code *)0x0;
}
