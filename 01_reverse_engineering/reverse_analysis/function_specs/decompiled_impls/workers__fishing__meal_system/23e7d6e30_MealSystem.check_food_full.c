/* ===== 23e7d6e30 workers.fishing.meal_system:308 ===== */
/* ghidra_name=FUN_23e7d6e30 entry=23e7d6e30 size=4331 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e7d6e30(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *******ppppppplVar2;
  longlong lVar3;
  longlong ******pppppplVar4;
  longlong ******pppppplVar5;
  longlong *****ppppplVar6;
  longlong *plVar7;
  longlong *******ppppppplVar8;
  int iVar9;
  undefined8 *puVar10;
  longlong lVar11;
  longlong *plVar12;
  longlong *plVar13;
  undefined8 uVar14;
  longlong ******pppppplVar15;
  longlong *plVar16;
  longlong *******ppppppplVar17;
  code *pcVar18;
  longlong *******ppppppplVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  longlong *plVar22;
  longlong *******unaff_R15;
  longlong *******ppppppplVar23;
  longlong *******ppppppplVar24;
  longlong *******ppppppplStack_a0;
  longlong *******ppppppplStack_88;
  longlong *******ppppppplStack_80;
  longlong *plStack_78;
  
  plVar22 = _DAT_23eedec58;
  ppppppplVar8 = (longlong *******)param_3[1];
  ppppppplVar19 = (longlong *******)param_3[2];
  plVar1 = (longlong *)*param_3;
  ppppppplVar2 = (longlong *******)param_3[3];
  ppppppplVar23 = ppppppplVar19;
  if (_DAT_23eedec58 == (longlong *)0x0) {
LAB_23e7d6e8e:
    _DAT_23eedec58 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedec50,DAT_23eed7940,0x20);
  }
  else {
    lVar11 = *_DAT_23eedec58;
    if (1 < lVar11) {
      *_DAT_23eedec58 = lVar11 + -1;
      goto LAB_23e7d6e8e;
    }
    if (_DAT_23eedec58[2] != 0) {
      *_DAT_23eedec58 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar22[1] + 0x30))(plVar22);
      }
      goto LAB_23e7d6e8e;
    }
  }
  plVar7 = _DAT_23eedec58;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar22 = _DAT_23eedec58 + 9;
  lVar3 = *(longlong *)(lVar11 + 8);
  _DAT_23eedec58[0xf] = lVar3;
  *(longlong **)(lVar11 + 8) = plVar22;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar7[0xe] != 0)))) {
    plVar22 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar7[0xe] + 0x10) = plVar22;
    if (plVar22 != (longlong *)0x0) {
      *plVar22 = *plVar22 + 1;
    }
  }
  *plVar7 = *plVar7 + 1;
  plVar22 = &DAT_23ed6cce0;
  *(undefined4 *)(plVar7 + 8) = 0;
  puVar10 = (undefined8 *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23ed6cf28);
  ppppppplVar24 = ppppppplRam000000023eed7480;
  if ((puVar10 == (undefined8 *)0x0) ||
     (ppppppplStack_a0 = (longlong *******)*puVar10, ppppppplStack_a0 == (longlong *******)0x0))
  goto LAB_23e7d7730;
  lVar11 = *(longlong *)(param_1 + 0x10);
  plVar13 = *(longlong **)(lVar11 + 0xe28);
  if (plVar13 == (longlong *)0x0) {
    plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
  }
  else {
    lVar3 = plVar13[3];
    *(int *)(lVar11 + 0xec0) = *(int *)(lVar11 + 0xec0) + -1;
    *(longlong *)(lVar11 + 0xe28) = lVar3;
    *plVar13 = 1;
  }
  pcVar18 = _PyRuntime_exref;
  *(undefined1 (*) [16])(plVar13 + 4) = (undefined1  [16])0x0;
  lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar18 + 0x1f8) + 0x10) + 0x2e8);
  lVar3 = plVar13[-1];
  puVar10 = *(undefined8 **)(lVar11 + 8);
  *puVar10 = plVar13 + -2;
  plVar13[-2] = lVar11;
  plVar13[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar10;
  *(longlong **)(lVar11 + 8) = plVar13 + -2;
  plVar12 = DAT_23ed6a4c0;
  *ppppppplVar24 = (longlong ******)((longlong)*ppppppplVar24 + 1);
  plVar13[3] = (longlong)ppppppplVar24;
  ppppppplVar17 = DAT_23ed6cd28;
  if (plVar12 == (longlong *)0x0) {
    plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
    unaff_R15 = ppppppplVar24;
    if (plVar12 == (longlong *)0x0) goto LAB_23e7d7730;
    *plVar12 = *plVar12 + 1;
    DAT_23ed6a4c0 = plVar12;
  }
  ppppppplStack_80 = ppppppplVar17;
  ppppppplStack_88 = ppppppplVar2;
  lVar11 = FUN_23e94ed00(param_1,plVar12,&ppppppplStack_88);
  if (lVar11 == 0) {
    ppppppplStack_a0 = *(longlong ********)(param_1 + 0x60);
    unaff_R15 = *(longlong ********)(param_1 + 0x68);
    uVar21 = 0x136;
    uVar20 = 0x136;
    plVar22 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar13 = *plVar13 + -1;
    lVar11 = *plVar13;
joined_r0x00023e7d755a:
    plVar12 = DAT_23ed6a4f8;
    if (lVar11 == 0) {
      (**(code **)(*(longlong *)((longlong)plVar13 + 8) + 0x30))(plVar13);
      plVar12 = DAT_23ed6a4f8;
      uVar21 = uVar20;
    }
joined_r0x00023e7d77e5:
    DAT_23ed6a4f8 = plVar12;
    if (plVar22 == (longlong *)0x0) {
      if (plVar12 == (longlong *)0x0) {
        plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar12;
        *plVar12 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar18 = _PyRuntime_exref;
      plVar12[2] = 0;
      plVar12[3] = (longlong)plVar7;
      *plVar7 = *plVar7 + 1;
      lVar11 = *(longlong *)(pcVar18 + 0x1f8);
      *(undefined4 *)((longlong)plVar12 + 0x24) = uVar21;
      lVar11 = *(longlong *)(lVar11 + 0x10);
      *(undefined4 *)(plVar12 + 4) = 0xffffffff;
      lVar11 = *(longlong *)(lVar11 + 0x2e8);
      lVar3 = plVar12[-1];
      puVar10 = *(undefined8 **)(lVar11 + 8);
      *puVar10 = plVar12 + -2;
      plVar12[-2] = lVar11;
      plVar12[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar10;
      *(longlong **)(lVar11 + 8) = plVar12 + -2;
      plVar13 = plVar12;
      goto LAB_23e7d7604;
    }
    plVar13 = plVar22;
    if (*(longlong **)((longlong)plVar22 + 0x18) == plVar7) goto LAB_23e7d7604;
    if (plVar12 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar12;
      *plVar12 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar18 = _PyRuntime_exref;
    plVar12[3] = (longlong)plVar7;
    *plVar7 = *plVar7 + 1;
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar21;
    lVar11 = *(longlong *)(pcVar18 + 0x1f8);
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
    lVar3 = plVar12[-1];
    puVar10 = *(undefined8 **)(lVar11 + 8);
    *puVar10 = plVar12 + -2;
    plVar12[-2] = lVar11;
    plVar12[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar10;
    lVar3 = *plVar22;
    *(longlong **)(lVar11 + 8) = plVar12 + -2;
    plVar12[2] = (longlong)plVar22;
    plVar13 = plVar12;
    if (lVar3 != 0) goto LAB_23e7d7604;
  }
  else {
    plVar13[4] = lVar11;
    plVar12 = plRam000000023eed7488;
    *plRam000000023eed7488 = *plRam000000023eed7488 + 1;
    plVar13[5] = (longlong)plVar12;
    plVar12 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar13);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if (plVar12 == (longlong *)0x0) {
LAB_23e7d7880:
      ppppppplStack_a0 = *(longlong ********)(param_1 + 0x60);
      unaff_R15 = *(longlong ********)(param_1 + 0x68);
      uVar21 = 0x136;
      plVar22 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar12 = DAT_23ed6a4f8;
      goto joined_r0x00023e7d77e5;
    }
    *(undefined4 *)(plVar7 + 5) = 0x136;
    plVar13 = (longlong *)FUN_23e914090(param_1,ppppppplStack_a0);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (plVar13 == (longlong *)0x0) goto LAB_23e7d7880;
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    ppppppplStack_a0 = (longlong *******)FUN_23a3a0d40(DAT_23ed6cf28);
    plVar12 = plRam000000023eed7490;
    lVar11 = *(longlong *)(param_1 + 0x10);
    plVar13 = *(longlong **)(lVar11 + 0xe38);
    if (plVar13 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,5);
    }
    else {
      lVar3 = plVar13[3];
      *(int *)(lVar11 + 0xec8) = *(int *)(lVar11 + 0xec8) + -1;
      *(longlong *)(lVar11 + 0xe38) = lVar3;
      *plVar13 = 1;
    }
    pcVar18 = _PyRuntime_exref;
    *(undefined1 (*) [16])(plVar13 + 4) = (undefined1  [16])0x0;
    lVar11 = *(longlong *)(pcVar18 + 0x1f8);
    *(undefined1 (*) [16])(plVar13 + 6) = (undefined1  [16])0x0;
    lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
    lVar3 = plVar13[-1];
    puVar10 = *(undefined8 **)(lVar11 + 8);
    *puVar10 = plVar13 + -2;
    plVar13[-2] = lVar11;
    plVar13[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar10;
    *(longlong **)(lVar11 + 8) = plVar13 + -2;
    plVar16 = DAT_23ed6a4c0;
    *plVar12 = *plVar12 + 1;
    plVar13[3] = (longlong)plVar12;
    ppppppplVar24 = DAT_23ed6cd28;
    ppppppplVar17 = ppppppplVar23;
    unaff_R15 = (longlong *******)&ppppppplStack_88;
    if (plVar16 == (longlong *)0x0) {
      plVar16 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar16 == (longlong *)0x0) goto LAB_23e7d7730;
      *plVar16 = *plVar16 + 1;
      DAT_23ed6a4c0 = plVar16;
      ppppppplVar17 = ppppppplVar23;
    }
    ppppppplStack_80 = ppppppplVar24;
    ppppppplStack_88 = ppppppplVar8;
    lVar11 = FUN_23e94ed00(param_1,plVar16,&ppppppplStack_88);
    ppppppplVar23 = ppppppplVar17;
    if (lVar11 == 0) {
LAB_23e7d77a0:
      ppppppplStack_a0 = *(longlong ********)(param_1 + 0x60);
      unaff_R15 = *(longlong ********)(param_1 + 0x68);
      uVar21 = 0x137;
      uVar20 = 0x137;
      plVar22 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar13 = *plVar13 + -1;
      lVar11 = *plVar13;
      goto joined_r0x00023e7d755a;
    }
    plVar13[4] = lVar11;
    plVar12 = plRam000000023eed7498;
    *plRam000000023eed7498 = *plRam000000023eed7498 + 1;
    plVar13[5] = (longlong)plVar12;
    ppppppplVar24 = DAT_23ed6cd28;
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar12 == (longlong *)0x0) goto LAB_23e7d7730;
      *plVar12 = *plVar12 + 1;
      DAT_23ed6a4c0 = plVar12;
    }
    ppppppplStack_80 = ppppppplVar24;
    ppppppplStack_88 = ppppppplVar17;
    lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&ppppppplStack_88);
    if (lVar11 == 0) goto LAB_23e7d77a0;
    plVar13[6] = lVar11;
    plVar12 = DAT_23eed74a0;
    *DAT_23eed74a0 = *DAT_23eed74a0 + 1;
    plVar13[7] = (longlong)plVar12;
    plVar12 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar13);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if (plVar12 == (longlong *)0x0) {
LAB_23e7d7cb0:
      ppppppplStack_a0 = *(longlong ********)(param_1 + 0x60);
      unaff_R15 = *(longlong ********)(param_1 + 0x68);
      uVar21 = 0x137;
      plVar22 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar12 = DAT_23ed6a4f8;
      goto joined_r0x00023e7d77e5;
    }
    *(undefined4 *)(plVar7 + 5) = 0x137;
    plVar13 = (longlong *)FUN_23e914090(param_1,ppppppplStack_a0);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (plVar13 == (longlong *)0x0) goto LAB_23e7d7cb0;
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed72a8);
    if (plVar13 == (longlong *)0x0) {
LAB_23e7d78b0:
      ppppppplStack_a0 = *(longlong ********)(param_1 + 0x60);
      unaff_R15 = *(longlong ********)(param_1 + 0x68);
      uVar21 = 0x139;
      plVar22 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar12 = DAT_23ed6a4f8;
      goto joined_r0x00023e7d77e5;
    }
    *(undefined4 *)(plVar7 + 5) = 0x139;
    ppppppplStack_88 = ppppppplVar8;
    ppppppplStack_80 = ppppppplVar19;
    plVar12 = (longlong *)FUN_23e954670(param_1,plVar13,uRam000000023eed74a8,&ppppppplStack_88);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if (plVar12 == (longlong *)0x0) goto LAB_23e7d78b0;
    iVar9 = FUN_23a35f020(plVar12);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (iVar9 == -1) goto LAB_23e7d78b0;
    if (iVar9 != 0) {
      uVar14 = FUN_23a3a0d40(DAT_23ed6cf28);
      pppppplVar15 = pppppplRam000000023eed74b8;
      lVar11 = *(longlong *)(param_1 + 0x10);
      ppppppplVar19 = *(longlong ********)(lVar11 + 0xe28);
      if (ppppppplVar19 == (longlong *******)0x0) {
        ppppppplVar19 = (longlong *******)FUN_23e916a20(PyTuple_Type_exref,3);
      }
      else {
        pppppplVar4 = ppppppplVar19[3];
        *(int *)(lVar11 + 0xec0) = *(int *)(lVar11 + 0xec0) + -1;
        *(longlong *******)(lVar11 + 0xe28) = pppppplVar4;
        *ppppppplVar19 = (longlong ******)0x1;
      }
      pcVar18 = _PyRuntime_exref;
      *(undefined1 (*) [16])(ppppppplVar19 + 4) = (undefined1  [16])0x0;
      pppppplVar4 = *(longlong *******)
                     (*(longlong *)(*(longlong *)(pcVar18 + 0x1f8) + 0x10) + 0x2e8);
      pppppplVar5 = ppppppplVar19[-1];
      ppppplVar6 = pppppplVar4[1];
      *ppppplVar6 = (longlong ****)(ppppppplVar19 + -2);
      ppppppplVar19[-2] = pppppplVar4;
      ppppppplVar19[-1] =
           (longlong ******)((ulonglong)((uint)pppppplVar5 & 3) | (ulonglong)ppppplVar6);
      pppppplVar4[1] = (longlong *****)(ppppppplVar19 + -2);
      *pppppplVar15 = (longlong *****)((longlong)*pppppplVar15 + 1);
      ppppppplVar19[3] = pppppplVar15;
      ppppppplVar17 = (longlong *******)FUN_23e8ddcc0();
      ppppppplVar24 = DAT_23ed6cd28;
      if (ppppppplVar17 == (longlong *******)0x0) {
        FUN_23e915740(param_1,&ppppppplStack_88,uRam000000023eed74c0);
        ppppppplStack_a0 = ppppppplStack_88;
        unaff_R15 = ppppppplStack_80;
LAB_23e7d7de1:
        *ppppppplVar19 = (longlong ******)((longlong)*ppppppplVar19 + -1);
        pppppplVar15 = *ppppppplVar19;
        uVar21 = 0x13d;
        uVar20 = 0x13d;
        plVar22 = plStack_78;
joined_r0x00023e7d7fb2:
        plVar12 = DAT_23ed6a4f8;
        if (pppppplVar15 == (longlong ******)0x0) {
          (*(code *)ppppppplVar19[1][6])(ppppppplVar19);
          plVar12 = DAT_23ed6a4f8;
          uVar21 = uVar20;
        }
      }
      else {
        if (DAT_23ed6a4c0 == (longlong *)0x0) {
          plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          ppppppplStack_a0 = ppppppplVar19;
          if (plVar13 == (longlong *)0x0) goto LAB_23e7d7730;
          *plVar13 = *plVar13 + 1;
          DAT_23ed6a4c0 = plVar13;
        }
        ppppppplStack_80 = ppppppplVar24;
        ppppppplStack_88 = ppppppplVar17;
        pppppplVar15 = (longlong ******)FUN_23e94ed00(param_1,DAT_23ed6a4c0,&ppppppplStack_88);
        if (pppppplVar15 == (longlong ******)0x0) {
          ppppppplStack_a0 = *(longlong ********)(param_1 + 0x60);
          plStack_78 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          unaff_R15 = *(longlong ********)(param_1 + 0x68);
          goto LAB_23e7d7de1;
        }
        ppppppplVar19[4] = pppppplVar15;
        pppppplVar15 = pppppplRam000000023eed74c8;
        *pppppplRam000000023eed74c8 = (longlong *****)((longlong)*pppppplRam000000023eed74c8 + 1);
        ppppppplVar19[5] = pppppplVar15;
        plVar22 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,ppppppplVar19);
        *ppppppplVar19 = (longlong ******)((longlong)*ppppppplVar19 + -1);
        if (*ppppppplVar19 == (longlong ******)0x0) {
          (*(code *)ppppppplVar19[1][6])(ppppppplVar19);
        }
        if (plVar22 != (longlong *)0x0) {
          *(undefined4 *)(plVar7 + 5) = 0x13d;
          plVar13 = (longlong *)FUN_23e914090(param_1,uVar14,plVar22);
          *plVar22 = *plVar22 + -1;
          if (*plVar22 == 0) {
            (**(code **)(plVar22[1] + 0x30))(plVar22);
          }
          if (plVar13 == (longlong *)0x0) goto LAB_23e7d7eb0;
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          lVar11 = FUN_23e8de0b0();
          if (lVar11 == 0) {
            FUN_23e915740(param_1,&ppppppplStack_88,uRam000000023eed7260);
            uVar21 = 0x13e;
            plVar22 = plStack_78;
            unaff_R15 = ppppppplStack_80;
            plVar12 = DAT_23ed6a4f8;
            ppppppplStack_a0 = ppppppplStack_88;
            goto joined_r0x00023e7d77e5;
          }
          ppppppplVar19 = (longlong *******)FUN_23e8bc2f0(lVar11,uRam000000023eed7268);
          if (ppppppplVar19 == (longlong *******)0x0) {
LAB_23e7d7edb:
            ppppppplStack_a0 = *(longlong ********)(param_1 + 0x60);
            uVar21 = 0x13e;
            plVar22 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            unaff_R15 = *(longlong ********)(param_1 + 0x68);
            plVar12 = DAT_23ed6a4f8;
            goto joined_r0x00023e7d77e5;
          }
          lVar11 = FUN_23e8ddcc0();
          if (lVar11 != 0) {
            *(undefined4 *)(plVar7 + 5) = 0x13e;
            plVar22 = (longlong *)FUN_23e914090(param_1,ppppppplVar19,lVar11);
            *ppppppplVar19 = (longlong ******)((longlong)*ppppppplVar19 + -1);
            if (*ppppppplVar19 == (longlong ******)0x0) {
              (*(code *)ppppppplVar19[1][6])(ppppppplVar19);
            }
            if (plVar22 != (longlong *)0x0) {
              *plVar22 = *plVar22 + -1;
              if (*plVar22 == 0) {
                (**(code **)(plVar22[1] + 0x30))(plVar22);
              }
              lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar22 = *(longlong **)(lVar11 + 0x28);
              plVar7 = (longlong *)plVar22[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
              *(undefined4 *)(plVar22 + 8) = 0xffffffff;
              if (plVar7 != (longlong *)0x0) {
                plVar22[2] = 0;
                *plVar7 = *plVar7 + -1;
                if (*plVar7 == 0) {
                  (**(code **)(plVar7[1] + 0x30))();
                }
              }
              *plVar22 = *plVar22 + -1;
              if (*plVar22 == 0) {
                (**(code **)(plVar22[1] + 0x30))(plVar22);
              }
              pcVar18 = _Py_TrueStruct_exref;
              plVar22[0xf] = 0;
              *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
              goto LAB_23e7d7be6;
            }
            goto LAB_23e7d7edb;
          }
          FUN_23e915740(param_1,&ppppppplStack_88,uRam000000023eed74c0);
          uVar21 = 0x13e;
          uVar20 = 0x13e;
          *ppppppplVar19 = (longlong ******)((longlong)*ppppppplVar19 + -1);
          pppppplVar15 = *ppppppplVar19;
          ppppppplStack_a0 = ppppppplStack_88;
          unaff_R15 = ppppppplStack_80;
          plVar22 = plStack_78;
          goto joined_r0x00023e7d7fb2;
        }
LAB_23e7d7eb0:
        ppppppplStack_a0 = *(longlong ********)(param_1 + 0x60);
        unaff_R15 = *(longlong ********)(param_1 + 0x68);
        uVar21 = 0x13d;
        plVar22 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar12 = DAT_23ed6a4f8;
      }
      goto joined_r0x00023e7d77e5;
    }
    uVar14 = FUN_23a3a0d40(DAT_23ed6cf28);
    pppppplVar15 = pppppplRam000000023eed74b0;
    lVar11 = *(longlong *)(param_1 + 0x10);
    ppppppplVar19 = *(longlong ********)(lVar11 + 0xe20);
    if (ppppppplVar19 == (longlong *******)0x0) {
      ppppppplVar19 = (longlong *******)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      pppppplVar4 = ppppppplVar19[3];
      *(int *)(lVar11 + 0xebc) = *(int *)(lVar11 + 0xebc) + -1;
      *(longlong *******)(lVar11 + 0xe20) = pppppplVar4;
      *ppppppplVar19 = (longlong ******)0x1;
    }
    pcVar18 = _PyRuntime_exref;
    ppppppplVar19[4] = (longlong ******)0x0;
    pppppplVar4 = *(longlong *******)(*(longlong *)(*(longlong *)(pcVar18 + 0x1f8) + 0x10) + 0x2e8);
    pppppplVar5 = ppppppplVar19[-1];
    ppppplVar6 = pppppplVar4[1];
    *ppppplVar6 = (longlong ****)(ppppppplVar19 + -2);
    ppppppplVar19[-2] = pppppplVar4;
    ppppppplVar19[-1] =
         (longlong ******)((ulonglong)((uint)pppppplVar5 & 3) | (ulonglong)ppppplVar6);
    pppppplVar4[1] = (longlong *****)(ppppppplVar19 + -2);
    plVar13 = DAT_23ed6a4c0;
    *pppppplVar15 = (longlong *****)((longlong)*pppppplVar15 + 1);
    ppppppplVar19[3] = pppppplVar15;
    ppppppplVar24 = DAT_23ed6cd28;
    if (plVar13 != (longlong *)0x0) {
LAB_23e7d73b6:
      ppppppplStack_80 = ppppppplVar24;
      ppppppplStack_88 = ppppppplVar2;
      pppppplVar15 = (longlong ******)FUN_23e94ed00(param_1,plVar13,&ppppppplStack_88);
      if (pppppplVar15 == (longlong ******)0x0) {
        ppppppplStack_a0 = *(longlong ********)(param_1 + 0x60);
        unaff_R15 = *(longlong ********)(param_1 + 0x68);
        uVar21 = 0x13a;
        uVar20 = 0x13a;
        plVar22 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *ppppppplVar19 = (longlong ******)((longlong)*ppppppplVar19 + -1);
        pppppplVar15 = *ppppppplVar19;
        goto joined_r0x00023e7d7fb2;
      }
      ppppppplVar19[4] = pppppplVar15;
      plVar22 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,ppppppplVar19);
      *ppppppplVar19 = (longlong ******)((longlong)*ppppppplVar19 + -1);
      if (*ppppppplVar19 == (longlong ******)0x0) {
        (*(code *)ppppppplVar19[1][6])(ppppppplVar19);
      }
      if (plVar22 != (longlong *)0x0) {
        *(undefined4 *)(plVar7 + 5) = 0x13a;
        plVar13 = (longlong *)FUN_23e914090(param_1,uVar14,plVar22);
        *plVar22 = *plVar22 + -1;
        if (*plVar22 == 0) {
          (**(code **)(plVar22[1] + 0x30))(plVar22);
        }
        if (plVar13 != (longlong *)0x0) {
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          pcVar18 = _Py_FalseStruct_exref;
          lVar11 = *(longlong *)(param_1 + 0x38);
          lVar3 = *(longlong *)(lVar11 + 8);
          *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
          plVar22 = *(longlong **)(lVar3 + 0x28);
          plVar7 = (longlong *)plVar22[2];
          *(undefined8 *)(lVar11 + 8) = *(undefined8 *)(lVar3 + 0x30);
          *(undefined4 *)(plVar22 + 8) = 0xffffffff;
          if (plVar7 != (longlong *)0x0) {
            plVar22[2] = 0;
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              (**(code **)(plVar7[1] + 0x30))();
            }
          }
          *plVar22 = *plVar22 + -1;
          if (*plVar22 == 0) {
            (**(code **)(plVar22[1] + 0x30))(plVar22);
          }
          plVar22[0xf] = 0;
LAB_23e7d7be6:
          *plVar1 = *plVar1 + -1;
          if (*plVar1 == 0) {
            (**(code **)(plVar1[1] + 0x30))(plVar1);
          }
          *ppppppplVar8 = (longlong ******)((longlong)*ppppppplVar8 + -1);
          if (*ppppppplVar8 == (longlong ******)0x0) {
            (*(code *)ppppppplVar8[1][6])(ppppppplVar8);
          }
          pppppplVar15 = *ppppppplVar23;
          *ppppppplVar23 = (longlong ******)((longlong)pppppplVar15 + -1);
          if ((longlong ******)((longlong)pppppplVar15 + -1) == (longlong ******)0x0) {
            (*(code *)ppppppplVar23[1][6])(ppppppplVar23);
          }
          *ppppppplVar2 = (longlong ******)((longlong)*ppppppplVar2 + -1);
          if (*ppppppplVar2 == (longlong ******)0x0) {
            (*(code *)ppppppplVar2[1][6])(ppppppplVar2);
            return pcVar18;
          }
          return pcVar18;
        }
      }
      ppppppplStack_a0 = *(longlong ********)(param_1 + 0x60);
      plVar22 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      unaff_R15 = *(longlong ********)(param_1 + 0x68);
      plVar12 = DAT_23ed6a4f8;
      uVar21 = 0x13a;
      goto joined_r0x00023e7d77e5;
    }
    plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
    ppppppplStack_a0 = ppppppplVar19;
    if (plVar13 != (longlong *)0x0) {
      *plVar13 = *plVar13 + 1;
      DAT_23ed6a4c0 = plVar13;
      goto LAB_23e7d73b6;
    }
LAB_23e7d7730:
    PyErr_PrintEx(0);
    plVar12 = (longlong *)Py_Exit(1);
  }
  (**(code **)(plVar22[1] + 0x30))(plVar22);
  plVar13 = plVar12;
LAB_23e7d7604:
  ppppppplVar19 = ppppppplVar2;
  ppppppplVar24 = ppppppplVar23;
  FUN_23e8bba40(plVar7,&DAT_23ec5e2ee,plVar1,ppppppplVar8,ppppppplVar23,ppppppplVar2);
  if (_DAT_23eedec58 == plVar7) {
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    _DAT_23eedec58 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar22 = *(longlong **)(lVar11 + 0x28);
  plVar7 = (longlong *)plVar22[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar22 + 8) = 0xffffffff;
  if (plVar7 != (longlong *)0x0) {
    plVar22[2] = 0;
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))();
    }
  }
  *plVar22 = *plVar22 + -1;
  if (*plVar22 == 0) {
    (**(code **)(plVar22[1] + 0x30))(plVar22);
  }
  plVar22[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *ppppppplVar8 = (longlong ******)((longlong)*ppppppplVar8 + -1);
  if (*ppppppplVar8 == (longlong ******)0x0) {
    (*(code *)ppppppplVar8[1][6])(ppppppplVar8);
  }
  pppppplVar15 = *ppppppplVar24;
  *ppppppplVar24 = (longlong ******)((longlong)pppppplVar15 + -1);
  if ((longlong ******)((longlong)pppppplVar15 + -1) == (longlong ******)0x0) {
    (*(code *)ppppppplVar24[1][6])(ppppppplVar24);
  }
  *ppppppplVar2 = (longlong ******)((longlong)*ppppppplVar2 + -1);
  if (*ppppppplVar2 == (longlong ******)0x0) {
    (*(code *)ppppppplVar2[1][6])(ppppppplVar2);
  }
  FUN_23a33aa70(param_1,ppppppplStack_a0,unaff_R15,plVar13,ppppppplVar23,ppppppplVar19,pppppplVar15)
  ;
  return (code *)0x0;
}
