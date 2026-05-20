/* ===== 23e71fc80 workers.fishing.fishing_bot:FishingBot.__init__ ===== */
/* ghidra_name=FUN_23e71fc80 entry=23e71fc80 size=14140 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e71fc80(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong lVar13;
  longlong *plVar14;
  code *pcVar15;
  longlong *plVar16;
  longlong *plVar17;
  undefined8 uVar18;
  longlong lVar19;
  code *pcVar20;
  undefined1 auVar21 [8];
  undefined8 uVar22;
  undefined4 uVar23;
  code *pcStack_e8;
  longlong *plStack_a8;
  code *pcStack_a0;
  longlong *plStack_98;
  longlong *plStack_90;
  longlong *plStack_88;
  undefined1 auStack_78 [8];
  undefined8 uStack_70;
  longlong *plStack_68;
  
  plVar7 = _DAT_23eedae90;
  plVar1 = (longlong *)*param_3;
  plStack_68 = (longlong *)0x0;
  auStack_78 = (undefined1  [8])0x0;
  uStack_70 = (longlong *)0x0;
  if (_DAT_23eedae90 == (longlong *)0x0) {
LAB_23e71fcdd:
    _DAT_23eedae90 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedaed0,DAT_23eedaeb8,0x38);
  }
  else {
    lVar12 = *_DAT_23eedae90;
    if (1 < lVar12) {
      *_DAT_23eedae90 = lVar12 + -1;
      goto LAB_23e71fcdd;
    }
    if (_DAT_23eedae90[2] != 0) {
      *_DAT_23eedae90 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23e71fcdd;
    }
  }
  plVar2 = _DAT_23eedae90;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar7 = _DAT_23eedae90 + 9;
  lVar13 = *(longlong *)(lVar12 + 8);
  _DAT_23eedae90[0xf] = lVar13;
  *(longlong **)(lVar12 + 8) = plVar7;
  if ((lVar13 != 0) &&
     (((*(char *)(lVar13 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar13 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar13 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar13 + 0x38))) && (plVar2[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar13 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  uVar18 = DAT_23eed8980;
  *(undefined4 *)(plVar2 + 8) = 0;
  plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,uVar18);
  if (plVar7 == (longlong *)0x0) {
    plVar7 = *(longlong **)(param_1 + 0x70);
    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    uStack_70 = *(longlong **)(param_1 + 0x68);
    plVar11 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar9 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    iVar6 = 0xae;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar15 = (code *)0x0;
    plStack_68 = plVar7;
    goto LAB_23e720a7a;
  }
  iVar6 = FUN_23a35f020(plVar7);
  lVar12 = *plVar7 + -1;
  if (iVar6 == -1) {
    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    uStack_70 = *(longlong **)(param_1 + 0x68);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    iVar6 = 0xae;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar7 = lVar12;
    if (lVar12 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
      iVar6 = 0xae;
    }
    goto LAB_23e720e3f;
  }
  *plVar7 = lVar12;
  if (lVar12 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
    if (iVar6 == 0) goto LAB_23e71fe72;
LAB_23e71fda9:
    plVar8 = (longlong *)0x0;
    lVar12 = *(longlong *)_Py_NoneStruct_exref;
LAB_23e71fdc3:
    pcStack_e8 = _Py_NoneStruct_exref;
    *(longlong *)_Py_NoneStruct_exref = lVar12 + 1;
    lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar7 = *(longlong **)(lVar12 + 0x28);
    plVar2 = (longlong *)plVar7[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
    *(undefined4 *)(plVar7 + 8) = 0xffffffff;
    if (plVar2 != (longlong *)0x0) {
      plVar7[2] = 0;
      *plVar2 = *plVar2 + -1;
      if (*plVar2 == 0) {
        (**(code **)(plVar2[1] + 0x30))();
      }
    }
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    plVar7[0xf] = 0;
    if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
LAB_23e71fe32:
    *plVar1 = *plVar1 + -1;
    lVar12 = *plVar1;
joined_r0x00023e71fe37:
    if (lVar12 != 0) {
      return pcStack_e8;
    }
    (**(code **)(plVar1[1] + 0x30))(plVar1);
    return pcStack_e8;
  }
  if (iVar6 != 0) goto LAB_23e71fda9;
LAB_23e71fe72:
  plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed89b0);
  if (plVar7 == (longlong *)0x0) {
LAB_23e720e58:
    pcVar15 = (code *)0x0;
    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    uStack_70 = *(longlong **)(param_1 + 0x68);
    plVar7 = *(longlong **)(param_1 + 0x70);
    plVar11 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar9 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    iVar6 = 0xb0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_68 = plVar7;
    goto LAB_23e720a7a;
  }
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23eed8b58);
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  if (plVar8 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    uStack_70 = *(longlong **)(param_1 + 0x68);
    plVar7 = *(longlong **)(param_1 + 0x70);
    plVar11 = (longlong *)0x0;
    pcVar15 = (code *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar14 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    iVar6 = 0xb0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar8 = (longlong *)0x0;
    plStack_68 = plVar7;
    goto LAB_23e720a7a;
  }
  *(undefined4 *)(plVar2 + 5) = 0xb0;
  plVar7 = (longlong *)FUN_23e91a870(param_1,plVar8);
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if (plVar7 == (longlong *)0x0) goto LAB_23e720e58;
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  pcVar4 = _Py_TrueStruct_exref;
  cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eed8980,_Py_TrueStruct_exref);
  pcVar15 = _Py_FalseStruct_exref;
  if (cVar5 == '\0') {
    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    uStack_70 = *(longlong **)(param_1 + 0x68);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    iVar6 = 0xb1;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e720e3f:
    plVar11 = (longlong *)0x0;
    pcVar15 = (code *)0x0;
    plVar14 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    plVar7 = plStack_68;
LAB_23e720a7a:
    pcVar20 = _PyRuntime_exref;
    if (plVar7 == (longlong *)0x0) {
LAB_23e720d42:
      plVar10 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
        plVar7 = plStack_68;
      }
      else {
        plVar7 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar7;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar7 = (longlong *)0x0;
      }
      plVar10[2] = 0;
      plVar10[3] = (longlong)plVar2;
      *plVar2 = *plVar2 + 1;
      lVar12 = *(longlong *)(pcVar20 + 0x1f8);
      *(int *)((longlong)plVar10 + 0x24) = iVar6;
      lVar12 = *(longlong *)(lVar12 + 0x10);
      *(undefined4 *)(plVar10 + 4) = 0xffffffff;
      lVar12 = *(longlong *)(lVar12 + 0x2e8);
      lVar13 = plVar10[-1];
      puVar3 = *(undefined8 **)(lVar12 + 8);
      *puVar3 = plVar10 + -2;
      plVar10[-2] = lVar12;
      plVar10[-1] = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar3;
      *(longlong **)(lVar12 + 8) = plVar10 + -2;
      if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
        (**(code **)(plVar7[1] + 0x30))();
      }
      goto LAB_23e720b40;
    }
    plVar10 = plStack_68;
    if (plVar2 == (longlong *)plVar7[3]) goto LAB_23e720b40;
  }
  else {
    cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eed8b00,_Py_FalseStruct_exref);
    if (cVar5 == '\0') {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_70 = *(longlong **)(param_1 + 0x68);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      iVar6 = 0xb2;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e720e3f;
    }
    plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8968);
    if (plVar7 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_70 = *(longlong **)(param_1 + 0x68);
      plVar7 = *(longlong **)(param_1 + 0x70);
      plVar11 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar9 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      iVar6 = 0xb3;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcVar15 = (code *)0x0;
      plStack_68 = plVar7;
      goto LAB_23e720a7a;
    }
    *(undefined4 *)(plVar2 + 5) = 0xb3;
    plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar7,DAT_23eed8970);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    if (plVar8 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_70 = *(longlong **)(param_1 + 0x68);
      plVar7 = *(longlong **)(param_1 + 0x70);
      plVar11 = (longlong *)0x0;
      pcVar15 = (code *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar14 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      iVar6 = 0xb3;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar8 = (longlong *)0x0;
      plStack_68 = plVar7;
      goto LAB_23e720a7a;
    }
    cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eed8978,plVar8);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (cVar5 == '\0') {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_70 = *(longlong **)(param_1 + 0x68);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      iVar6 = 0xb3;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e720e3f;
    }
    plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8978);
    if (plVar7 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_70 = *(longlong **)(param_1 + 0x68);
      plVar7 = *(longlong **)(param_1 + 0x70);
      plVar11 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar9 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      iVar6 = 0xb6;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcVar15 = (code *)0x0;
      plStack_68 = plVar7;
      goto LAB_23e720a7a;
    }
    plVar9 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ed6ce40);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    plVar7 = DAT_23eed8b60;
    lVar12 = DAT_23ed6cce8;
    if (plVar9 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_70 = *(longlong **)(param_1 + 0x68);
      plVar7 = *(longlong **)(param_1 + 0x70);
      plVar11 = (longlong *)0x0;
      pcVar15 = (code *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar14 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      iVar6 = 0xb6;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar9 = (longlong *)0x0;
      plStack_68 = plVar7;
      goto LAB_23e720a7a;
    }
    lVar13 = *(longlong *)(param_1 + 0x10);
    iVar6 = *(int *)(lVar13 + 0x1410);
    plVar8 = *(longlong **)(DAT_23ed6cce8 + 0x20);
    *plVar8 = *plVar8 + 1;
    if (iVar6 == 0) {
      plVar14 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
      plVar8 = *(longlong **)(lVar12 + 0x20);
    }
    else {
      iVar6 = iVar6 + -1;
      *(int *)(lVar13 + 0x1410) = iVar6;
      plVar14 = *(longlong **)(lVar13 + 0x1190 + (longlong)iVar6 * 8);
      *plVar14 = 1;
    }
    lVar12 = *(longlong *)(lVar12 + 0x28);
    plVar14[2] = 0;
    plVar14[4] = (longlong)plVar8;
    plVar14[5] = lVar12;
    plVar14[3] = 1;
    *(undefined4 *)(plVar2 + 5) = 0xb6;
    plStack_98 = plVar7;
    plStack_90 = plVar14;
    plVar8 = (longlong *)FUN_23e94ed00(param_1,plVar9,&plStack_98);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
    if (plVar8 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_70 = *(longlong **)(param_1 + 0x68);
      plVar7 = *(longlong **)(param_1 + 0x70);
      plVar11 = (longlong *)0x0;
      pcVar15 = (code *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar14 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      iVar6 = 0xb6;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plStack_68 = plVar7;
      goto LAB_23e720a7a;
    }
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8b40);
    plVar7 = _DAT_23eed8b68;
    if (plVar10 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_70 = *(longlong **)(param_1 + 0x68);
      plVar7 = *(longlong **)(param_1 + 0x70);
      plVar11 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar9 = (longlong *)0x0;
      iVar6 = 0xb7;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcVar15 = (code *)0x0;
      plStack_68 = plVar7;
      goto LAB_23e720a7a;
    }
    lVar12 = *(longlong *)(param_1 + 0x10);
    plVar14 = *(longlong **)(lVar12 + 0xe30);
    if (plVar14 == (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,4);
    }
    else {
      lVar13 = plVar14[3];
      *(int *)(lVar12 + 0xec4) = *(int *)(lVar12 + 0xec4) + -1;
      *(longlong *)(lVar12 + 0xe30) = lVar13;
      *plVar14 = 1;
    }
    pcVar20 = _PyRuntime_exref;
    plVar14[6] = 0;
    *(undefined1 (*) [16])(plVar14 + 4) = (undefined1  [16])0x0;
    lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar20 + 0x1f8) + 0x10) + 0x2e8);
    lVar13 = plVar14[-1];
    puVar3 = *(undefined8 **)(lVar12 + 8);
    *puVar3 = plVar14 + -2;
    plVar14[-2] = lVar12;
    plVar14[-1] = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar12 + 8) = plVar14 + -2;
    uVar18 = DAT_23eed8978;
    *plVar7 = *plVar7 + 1;
    plVar14[3] = (longlong)plVar7;
    plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,uVar18);
    if (plVar7 == (longlong *)0x0) {
LAB_23e720fd8:
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_70 = *(longlong **)(param_1 + 0x68);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      plVar11 = (longlong *)0x0;
      pcVar15 = (code *)0x0;
      plVar14 = (longlong *)0x0;
      iVar6 = 0xb7;
      plVar9 = (longlong *)0x0;
      plVar7 = plStack_68;
      goto LAB_23e720a7a;
    }
    plVar11 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ed6ce40);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    uVar18 = _DAT_23eed8b70;
    if (plVar11 == (longlong *)0x0) goto LAB_23e720fd8;
    *(undefined4 *)(plVar2 + 5) = 0xb7;
    plVar9 = (longlong *)FUN_23e9557e0(param_1,plVar11,uVar18);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    plVar7 = DAT_23ed6cd28;
    if (plVar9 == (longlong *)0x0) goto LAB_23e720fd8;
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar11 != (longlong *)0x0) {
        *plVar11 = *plVar11 + 1;
        DAT_23ed6a4c0 = plVar11;
        goto LAB_23e720263;
      }
LAB_23e7213ad:
      plVar7 = (longlong *)0x0;
      PyErr_PrintEx(0);
      Py_Exit(1);
LAB_23e7213c0:
      plVar11 = (longlong *)0x0;
      pcVar15 = (code *)0x0;
      plVar14 = (longlong *)0x0;
      iVar6 = 0xb7;
      goto LAB_23e720a7a;
    }
LAB_23e720263:
    plStack_90 = plVar7;
    plStack_98 = plVar9;
    lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    plVar7 = _DAT_23eed8b78;
    if (lVar12 == 0) goto LAB_23e720fd8;
    plVar14[4] = lVar12;
    uVar18 = DAT_23eed8978;
    *plVar7 = *plVar7 + 1;
    plVar14[5] = (longlong)plVar7;
    plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,uVar18);
    if (plVar7 == (longlong *)0x0) goto LAB_23e720fd8;
    plVar11 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ed6ce40);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    uVar18 = DAT_23eed8b80;
    if (plVar11 == (longlong *)0x0) goto LAB_23e720fd8;
    *(undefined4 *)(plVar2 + 5) = 0xb7;
    plVar9 = (longlong *)FUN_23e9557e0(param_1,plVar11,uVar18);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    plVar7 = DAT_23ed6cd28;
    if (plVar9 == (longlong *)0x0) goto LAB_23e720fd8;
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar11 == (longlong *)0x0) goto LAB_23e7213ad;
      *plVar11 = *plVar11 + 1;
      DAT_23ed6a4c0 = plVar11;
    }
    plStack_90 = plVar7;
    plStack_98 = plVar9;
    lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if (lVar12 == 0) goto LAB_23e720fd8;
    plVar14[6] = lVar12;
    plVar7 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar14);
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))();
    }
    if (plVar7 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_70 = *(longlong **)(param_1 + 0x68);
      plVar7 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar10 = *plVar10 + -1;
      plVar9 = (longlong *)0x0;
      plStack_68 = plVar7;
      if (*plVar10 != 0) goto LAB_23e7213c0;
      plVar11 = (longlong *)0x0;
      pcVar15 = (code *)0x0;
      plVar14 = (longlong *)0x0;
      FUN_23a334bc0(plVar10);
      iVar6 = 0xb7;
      plVar7 = plStack_68;
      goto LAB_23e720a7a;
    }
    *(undefined4 *)(plVar2 + 5) = 0xb7;
    plVar9 = (longlong *)FUN_23e914090(param_1,plVar10,plVar7);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    if (plVar9 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_70 = *(longlong **)(param_1 + 0x68);
      plVar7 = *(longlong **)(param_1 + 0x70);
      plVar11 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar15 = (code *)0x0;
      plVar9 = (longlong *)0x0;
      iVar6 = 0xb7;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar14 = (longlong *)0x0;
      plStack_68 = plVar7;
      goto LAB_23e720a7a;
    }
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8b40);
    plVar7 = _DAT_23eed8b88;
    if (plVar10 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_70 = *(longlong **)(param_1 + 0x68);
      plVar7 = *(longlong **)(param_1 + 0x70);
      plVar11 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar15 = (code *)0x0;
      plVar9 = (longlong *)0x0;
      iVar6 = 0xb8;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar14 = (longlong *)0x0;
      plStack_68 = plVar7;
      goto LAB_23e720a7a;
    }
    lVar12 = *(longlong *)(param_1 + 0x10);
    plVar14 = *(longlong **)(lVar12 + 0xe40);
    if (plVar14 == (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,6);
    }
    else {
      lVar13 = plVar14[3];
      *(int *)(lVar12 + 0xecc) = *(int *)(lVar12 + 0xecc) + -1;
      *(longlong *)(lVar12 + 0xe40) = lVar13;
      *plVar14 = 1;
    }
    lVar12 = *(longlong *)(pcVar20 + 0x1f8);
    plVar14[8] = 0;
    *(undefined1 (*) [16])(plVar14 + 4) = (undefined1  [16])0x0;
    lVar12 = *(longlong *)(lVar12 + 0x10);
    *(undefined1 (*) [16])(plVar14 + 6) = (undefined1  [16])0x0;
    lVar12 = *(longlong *)(lVar12 + 0x2e8);
    lVar13 = plVar14[-1];
    puVar3 = *(undefined8 **)(lVar12 + 8);
    *puVar3 = plVar14 + -2;
    plVar14[-2] = lVar12;
    plVar14[-1] = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar12 + 8) = plVar14 + -2;
    *plVar7 = *plVar7 + 1;
    plVar14[3] = (longlong)plVar7;
    plVar7 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed6ce40);
    uVar18 = _DAT_23eed8b90;
    if (plVar7 == (longlong *)0x0) {
LAB_23e721219:
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_70 = *(longlong **)(param_1 + 0x68);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      plVar11 = (longlong *)0x0;
      pcVar15 = (code *)0x0;
      plVar14 = (longlong *)0x0;
      iVar6 = 0xb8;
      plVar9 = (longlong *)0x0;
      plVar7 = plStack_68;
      goto LAB_23e720a7a;
    }
    *(undefined4 *)(plVar2 + 5) = 0xb8;
    plVar9 = (longlong *)FUN_23e9557e0(param_1,plVar7,uVar18);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    plVar7 = DAT_23ed6cd28;
    if (plVar9 == (longlong *)0x0) goto LAB_23e721219;
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar11 == (longlong *)0x0) goto LAB_23e7213ad;
      *plVar11 = *plVar11 + 1;
      DAT_23ed6a4c0 = plVar11;
    }
    plStack_90 = plVar7;
    plStack_98 = plVar9;
    lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    plVar7 = _DAT_23eed8b98;
    if (lVar12 == 0) goto LAB_23e721219;
    plVar14[4] = lVar12;
    *plVar7 = *plVar7 + 1;
    plVar14[5] = (longlong)plVar7;
    plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed6ce40);
    if (plVar9 == (longlong *)0x0) goto LAB_23e721219;
    *(undefined4 *)(plVar2 + 5) = 0xb8;
    plVar7 = (longlong *)FUN_23e9557e0(param_1,plVar9,_DAT_23eed8ba0);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      FUN_23a334bc0(plVar9);
    }
    plVar11 = DAT_23ed6cd28;
    if (plVar7 == (longlong *)0x0) goto LAB_23e721219;
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar16 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar16 == (longlong *)0x0) goto LAB_23e7213ad;
      *plVar16 = *plVar16 + 1;
      DAT_23ed6a4c0 = plVar16;
    }
    plStack_90 = plVar11;
    plStack_98 = plVar7;
    lVar13 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
    lVar12 = *plVar7;
    *plVar7 = lVar12 + -1;
    if (lVar12 + -1 == 0) {
      FUN_23a334bc0(plVar7);
    }
    plVar7 = _DAT_23eed8ba8;
    if (lVar13 == 0) goto LAB_23e721219;
    plVar14[6] = lVar13;
    *plVar7 = *plVar7 + 1;
    plVar14[7] = (longlong)plVar7;
    plVar7 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed6ce40);
    if (plVar7 == (longlong *)0x0) goto LAB_23e721219;
    *(undefined4 *)(plVar2 + 5) = 0xb8;
    plVar9 = (longlong *)FUN_23e9557e0(param_1,plVar7,_DAT_23eed8bb0);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      FUN_23a334bc0(plVar7);
    }
    if (plVar9 == (longlong *)0x0) goto LAB_23e721219;
    lVar12 = FUN_23e94f9d0(param_1,plVar9,DAT_23ed6cd28);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      FUN_23a334bc0(plVar9);
    }
    if (lVar12 == 0) goto LAB_23e721219;
    plVar14[8] = lVar12;
    plVar7 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar14);
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      FUN_23a334bc0(plVar14);
    }
    if (plVar7 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_70 = *(longlong **)(param_1 + 0x68);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar10 = *plVar10 + -1;
      plVar9 = (longlong *)0x0;
      if (*plVar10 == 0) {
        plVar11 = (longlong *)0x0;
        pcVar15 = (code *)0x0;
        plVar14 = (longlong *)0x0;
        FUN_23a334bc0(plVar10);
        iVar6 = 0xb8;
        plVar7 = plStack_68;
      }
      else {
        plVar11 = (longlong *)0x0;
        pcVar15 = (code *)0x0;
        plVar14 = (longlong *)0x0;
        iVar6 = 0xb8;
        plVar7 = plStack_68;
      }
      goto LAB_23e720a7a;
    }
    *(undefined4 *)(plVar2 + 5) = 0xb8;
    plVar9 = (longlong *)FUN_23e914090(param_1,plVar10,plVar7);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      FUN_23a334bc0(plVar10);
    }
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      FUN_23a334bc0(plVar7);
    }
    if (plVar9 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_70 = *(longlong **)(param_1 + 0x68);
      plVar7 = *(longlong **)(param_1 + 0x70);
      plVar11 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar14 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      iVar6 = 0xb8;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcVar15 = (code *)0x0;
      plStack_68 = plVar7;
      goto LAB_23e720a7a;
    }
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      FUN_23a334bc0(plVar9);
    }
    plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a98);
    if (plVar7 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_70 = *(longlong **)(param_1 + 0x68);
      plVar7 = *(longlong **)(param_1 + 0x70);
      plVar11 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar14 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      iVar6 = 0xbb;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcVar15 = (code *)0x0;
      plStack_68 = plVar7;
      goto LAB_23e720a7a;
    }
    *(undefined4 *)(plVar2 + 5) = 0xbb;
    plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar7,_DAT_23eed8bb8);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      FUN_23a334bc0(plVar7);
    }
    if (plVar9 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_70 = *(longlong **)(param_1 + 0x68);
      plVar7 = *(longlong **)(param_1 + 0x70);
      plVar11 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar15 = (code *)0x0;
      plVar14 = (longlong *)0x0;
      iVar6 = 0xbb;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar9 = (longlong *)0x0;
      plStack_68 = plVar7;
      goto LAB_23e720a7a;
    }
    iVar6 = FUN_23a35f020(plVar9);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      FUN_23a334bc0(plVar9);
    }
    uVar22 = _DAT_23eed8bd0;
    uVar18 = _DAT_23eed8bc8;
    lVar12 = _DAT_23eed8bc0;
    if (iVar6 == -1) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_70 = *(longlong **)(param_1 + 0x68);
      plVar7 = *(longlong **)(param_1 + 0x70);
      pcVar15 = (code *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      iVar6 = 0xbb;
      plVar11 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plStack_68 = plVar7;
      goto LAB_23e720a7a;
    }
    if (iVar6 == 0) {
      *(undefined4 *)(plVar2 + 5) = 0xbc;
      plVar7 = (longlong *)
               FUN_23e915840(param_1,plVar1,DAT_23eed8b40,*(undefined8 *)(lVar12 + 0x18));
      if (plVar7 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        plVar7 = *(longlong **)(param_1 + 0x70);
        plVar11 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar14 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        iVar6 = 0xbc;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar15 = (code *)0x0;
        plStack_68 = plVar7;
        uStack_70 = (longlong *)*(undefined8 *)(param_1 + 0x68);
      }
      else {
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          FUN_23a334bc0(plVar7);
        }
        cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eed8980,pcVar15);
        if (cVar5 != '\0') {
          lVar12 = *(longlong *)_Py_NoneStruct_exref;
          goto LAB_23e71fdc3;
        }
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        plVar7 = *(longlong **)(param_1 + 0x70);
        plVar11 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        iVar6 = 0xbd;
        pcVar15 = (code *)0x0;
        plVar14 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plStack_68 = plVar7;
        uStack_70 = (longlong *)*(undefined8 *)(param_1 + 0x68);
      }
      goto LAB_23e720a7a;
    }
    *(undefined4 *)(plVar2 + 5) = 0xc2;
    pcStack_e8 = _Py_NoneStruct_exref;
    plVar7 = (longlong *)
             FUN_23e95c160(param_1,uVar18,DAT_23eed8950,_Py_NoneStruct_exref,uVar22,DAT_23ed6ccf0);
    uVar23 = (undefined4)((ulonglong)uVar22 >> 0x20);
    if (plVar7 != (longlong *)0x0) {
      if (((code *)plVar7[1] == PyModule_Type_exref) || (iVar6 = PyType_IsSubtype(), iVar6 != 0)) {
        uVar18 = DAT_23ed6ccf0;
        plVar9 = (longlong *)
                 FUN_23e970d20(param_1,plVar7,DAT_23eed8950,_DAT_23eed8bd8,DAT_23ed6ccf0);
        uVar23 = (undefined4)((ulonglong)uVar18 >> 0x20);
      }
      else {
        plVar9 = (longlong *)FUN_23e8d2f70(param_1,plVar7,_DAT_23eed8bd8);
      }
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        FUN_23a334bc0(plVar7);
      }
      if (plVar9 == (longlong *)0x0) goto LAB_23e7223b7;
      *(undefined4 *)(plVar2 + 5) = 0xc3;
      plVar7 = (longlong *)FUN_23e915840(param_1,plVar1);
      if (plVar7 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        uStack_70 = *(longlong **)(param_1 + 0x68);
        plStack_68 = *(longlong **)(param_1 + 0x70);
        uVar18 = 0xc3;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e7223e6;
      }
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        FUN_23a334bc0(plVar7);
      }
      plVar7 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23eed8be8);
      if (plVar7 == (longlong *)0x0) {
LAB_23e722ba3:
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        uStack_70 = *(longlong **)(param_1 + 0x68);
        plStack_68 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e722b13:
        uVar18 = 0xc4;
        goto LAB_23e7223e6;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a98);
      if (plVar14 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        uStack_70 = *(longlong **)(param_1 + 0x68);
        plStack_68 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          FUN_23a334bc0(plVar7);
          uVar18 = 0xc4;
          goto LAB_23e7223e6;
        }
        goto LAB_23e722b13;
      }
      lVar12 = FUN_23e8bc2f0(plVar14,_DAT_23eed8bf0);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        FUN_23a334bc0();
      }
      if (lVar12 == 0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        uStack_70 = *(longlong **)(param_1 + 0x68);
        plStack_68 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          FUN_23a334bc0(plVar7);
        }
        goto LAB_23e722b13;
      }
      plVar14 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),1);
      uVar18 = _DAT_23eed8bf8;
      plVar14[3] = lVar12;
      plVar11 = (longlong *)FUN_23e8d7870(param_1,uVar18);
      *(undefined4 *)(plVar2 + 5) = 0xc4;
      plVar10 = (longlong *)FUN_23a334c60(param_1,plVar7,plVar14);
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        FUN_23a334bc0(plVar7);
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        FUN_23a334bc0(plVar14);
      }
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        FUN_23a334bc0(plVar11);
      }
      if (plVar10 == (longlong *)0x0) goto LAB_23e722ba3;
      iVar6 = FUN_23a35f020(plVar10);
      lVar12 = *plVar10 + -1;
      if (iVar6 == -1) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        uStack_70 = *(longlong **)(param_1 + 0x68);
        plStack_68 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar10 = lVar12;
        if (lVar12 == 0) {
          FUN_23a334bc0(plVar10);
        }
        goto LAB_23e722b13;
      }
      *plVar10 = lVar12;
      if (lVar12 == 0) {
        FUN_23a334bc0(plVar10);
      }
      uVar18 = DAT_23eed8b40;
      if (iVar6 == 0) {
        *(undefined4 *)(plVar2 + 5) = 199;
        plVar7 = (longlong *)FUN_23e915840(param_1,plVar1,uVar18);
        if (plVar7 != (longlong *)0x0) goto LAB_23e721799;
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        uStack_70 = *(longlong **)(param_1 + 0x68);
        plStack_68 = *(longlong **)(param_1 + 0x70);
        uVar18 = 199;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e7223e6;
      }
      *(undefined4 *)(plVar2 + 5) = 0xc5;
      plVar7 = (longlong *)FUN_23e915840(param_1,plVar1,uVar18);
      if (plVar7 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        uStack_70 = *(longlong **)(param_1 + 0x68);
        plStack_68 = *(longlong **)(param_1 + 0x70);
        uVar18 = 0xc5;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e7223e6;
      }
LAB_23e721799:
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        FUN_23a334bc0();
      }
LAB_23e7217a4:
      plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a98);
      if (plVar7 == (longlong *)0x0) {
LAB_23e7233e9:
        auVar21 = *(undefined1 (*) [8])(param_1 + 0x60);
        uVar18 = *(undefined8 *)(param_1 + 0x68);
        plVar7 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
      }
      else {
        *(undefined4 *)(plVar2 + 5) = 0xcc;
        plVar14 = (longlong *)FUN_23e91bfe0(param_1,plVar7,_DAT_23eed8c18);
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          FUN_23a334bc0(plVar7);
        }
        if (plVar14 == (longlong *)0x0) goto LAB_23e7233e9;
        plVar11 = (longlong *)FUN_23a388310(plVar14);
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          FUN_23a334bc0(plVar14);
        }
        if (plVar11 == (longlong *)0x0) goto LAB_23e7233e9;
        uVar18 = CONCAT44(uVar23,2);
        plVar14 = (longlong *)FUN_23a3c1d30(param_1,auStack_78,plVar11,0,uVar18);
        if (plVar14 == (longlong *)0x0) {
          pcVar15 = (code *)0x0;
          *plVar11 = *plVar11 + -1;
          plVar7 = plStack_68;
          auVar21 = auStack_78;
          uVar18 = uStack_70;
          if (*plVar11 == 0) {
LAB_23e7233b3:
            uStack_70 = (longlong *)0x0;
            auStack_78 = (undefined1  [8])0x0;
            plStack_68 = (longlong *)0x0;
            FUN_23a334bc0();
            plStack_68 = (longlong *)0x0;
            auStack_78 = (undefined1  [8])0x0;
            uStack_70 = (longlong *)0x0;
            if (plVar14 != (longlong *)0x0) goto LAB_23e723329;
            goto LAB_23e723341;
          }
        }
        else {
          uVar18 = CONCAT44((int)((ulonglong)uVar18 >> 0x20),2);
          pcVar15 = (code *)FUN_23a3c1d30(param_1,auStack_78,plVar11,1,uVar18);
          uVar23 = (undefined4)((ulonglong)uVar18 >> 0x20);
          if ((pcVar15 != (code *)0x0) &&
             (cVar5 = FUN_23a3884a0(param_1,auStack_78,plVar11,2), cVar5 != '\0')) {
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              FUN_23a334bc0(plVar11);
            }
            if (*plVar14 == 0) {
              FUN_23a334bc0(plVar14);
            }
            if (*(longlong *)pcVar15 == 0) {
              FUN_23a334bc0(pcVar15);
            }
            lVar12 = *(longlong *)(DAT_23eed8950 + 0x20);
            if (*(char *)(lVar12 + 10) == '\0') {
              plVar7 = (longlong *)FUN_23a37a020(DAT_23eed8950,_DAT_23eed8c20);
              if (plVar7 == (longlong *)0x0) goto LAB_23e723290;
              lVar19 = *plVar7;
LAB_23e723287:
              if (lVar19 == 0) goto LAB_23e723290;
LAB_23e721943:
              *(undefined4 *)(plVar2 + 5) = 0xcd;
              plStack_a8 = plVar14;
              pcStack_a0 = pcVar15;
              plVar7 = (longlong *)FUN_23e94ed00(param_1,lVar19,&plStack_a8);
              if (plVar7 == (longlong *)0x0) {
LAB_23e723223:
                plStack_68 = *(longlong **)(param_1 + 0x70);
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                uStack_70 = *(longlong **)(param_1 + 0x68);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e72324a;
              }
              plVar10 = (longlong *)FUN_23a388310(plVar7);
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                FUN_23a334bc0(plVar7);
              }
              if (plVar10 == (longlong *)0x0) goto LAB_23e723223;
              plVar11 = (longlong *)FUN_23a3c1d30(param_1,auStack_78,plVar10,0,CONCAT44(uVar23,2));
              if (plVar11 != (longlong *)0x0) {
                plVar16 = (longlong *)FUN_23a3c1d30(param_1,auStack_78,plVar10,1,2);
                if ((plVar16 == (longlong *)0x0) ||
                   (cVar5 = FUN_23a3884a0(param_1,auStack_78), cVar5 == '\0')) {
                  *plVar10 = *plVar10 + -1;
                  plVar7 = plStack_68;
                  auVar21 = auStack_78;
                  uVar18 = uStack_70;
                  if (*plVar10 == 0) goto LAB_23e7231e6;
LAB_23e723185:
                  plStack_68 = (longlong *)0x0;
                  _auStack_78 = (undefined1  [16])0x0;
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    FUN_23a334bc0(plVar11);
                  }
                  goto LAB_23e7231a7;
                }
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  FUN_23a334bc0(plVar10);
                }
                if (*plVar11 == 0) {
                  FUN_23a334bc0(plVar11);
                }
                cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eed8aa8,plVar16);
                if (cVar5 != '\0') {
                  *plVar16 = *plVar16 + -1;
                  if (*plVar16 == 0) {
                    FUN_23a334bc0(plVar16);
                  }
                  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8b40);
                  plVar7 = _DAT_23eed8c28;
                  if (plVar10 == (longlong *)0x0) {
LAB_23e72308c:
                    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                    plVar7 = *(longlong **)(param_1 + 0x70);
                    iVar6 = 0xce;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plStack_68 = plVar7;
                    uStack_70 = (longlong *)*(undefined8 *)(param_1 + 0x68);
                    goto LAB_23e720a7a;
                  }
                  plVar16 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),6);
                  *plVar7 = *plVar7 + 1;
                  plVar16[3] = (longlong)plVar7;
                  lVar12 = FUN_23e94f9d0(param_1,plVar14,DAT_23ed6cd28);
                  if (lVar12 != 0) {
                    plVar16[4] = lVar12;
                    plVar7 = _DAT_23eed8c30;
                    *_DAT_23eed8c30 = *_DAT_23eed8c30 + 1;
                    plVar16[5] = (longlong)plVar7;
                    lVar12 = FUN_23e94f9d0(param_1,pcVar15,DAT_23ed6cd28);
                    if (lVar12 != 0) {
                      plVar16[6] = lVar12;
                      plVar7 = _DAT_23eed8c38;
                      *_DAT_23eed8c38 = *_DAT_23eed8c38 + 1;
                      plVar16[7] = (longlong)plVar7;
                      plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8aa8);
                      if (plVar7 != (longlong *)0x0) {
                        plVar17 = (longlong *)FUN_23e8bc2f0(plVar7,_DAT_23eed8c40);
                        *plVar7 = *plVar7 + -1;
                        if (*plVar7 == 0) {
                          FUN_23a334bc0();
                        }
                        if (plVar17 != (longlong *)0x0) {
                          *(undefined4 *)(plVar2 + 5) = 0xce;
                          plVar7 = (longlong *)FUN_23e91a870(param_1,plVar17);
                          *plVar17 = *plVar17 + -1;
                          if (*plVar17 == 0) {
                            FUN_23a334bc0(plVar17);
                          }
                          if (plVar7 != (longlong *)0x0) {
                            lVar12 = FUN_23e94f9d0(param_1,plVar7,DAT_23ed6cd28);
                            *plVar7 = *plVar7 + -1;
                            if (*plVar7 == 0) {
                              FUN_23a334bc0(plVar7);
                            }
                            if (lVar12 != 0) {
                              plVar16[8] = lVar12;
                              plVar7 = (longlong *)PyUnicode_Join(DAT_23ed6cd28);
                              lVar12 = *plVar16;
                              *plVar16 = lVar12 + -1;
                              if (lVar12 + -1 == 0) {
                                FUN_23a334bc0(plVar16);
                              }
                              if (plVar7 == (longlong *)0x0) {
                                plStack_68 = *(longlong **)(param_1 + 0x70);
                                iVar6 = 0xce;
                                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                uStack_70 = *(longlong **)(param_1 + 0x68);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                lVar12 = *plVar10;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *plVar10 = lVar12 + -1;
                                plVar7 = plStack_68;
                                if (lVar12 + -1 == 0) {
                                  FUN_23a334bc0();
                                  iVar6 = 0xce;
                                  plVar7 = plStack_68;
                                }
                              }
                              else {
                                *(undefined4 *)(plVar2 + 5) = 0xce;
                                plVar16 = (longlong *)FUN_23e914090(param_1,plVar10);
                                lVar12 = *plVar10;
                                *plVar10 = lVar12 + -1;
                                if (lVar12 + -1 == 0) {
                                  FUN_23a334bc0();
                                }
                                *plVar7 = *plVar7 + -1;
                                if (*plVar7 == 0) {
                                  FUN_23a334bc0(plVar7);
                                }
                                if (plVar16 == (longlong *)0x0) goto LAB_23e72308c;
                                *plVar16 = *plVar16 + -1;
                                if (*plVar16 == 0) {
                                  FUN_23a334bc0(plVar16);
                                }
                                lVar12 = _DAT_23eed8c48;
                                *(undefined4 *)(plVar2 + 5) = 0xd1;
                                plVar7 = (longlong *)
                                         FUN_23e915840(param_1,plVar1,DAT_23eed8b40,
                                                       *(undefined8 *)(lVar12 + 0x18));
                                if (plVar7 == (longlong *)0x0) {
                                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                  plVar7 = *(longlong **)(param_1 + 0x70);
                                  iVar6 = 0xd1;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  plStack_68 = plVar7;
                                  uStack_70 = (longlong *)*(undefined8 *)(param_1 + 0x68);
                                }
                                else {
                                  *plVar7 = *plVar7 + -1;
                                  if (*plVar7 == 0) {
                                    FUN_23a334bc0(plVar7);
                                  }
                                  *(undefined4 *)(plVar2 + 5) = 0xd2;
                                  plVar7 = (longlong *)FUN_23e915840(param_1,plVar1,DAT_23eed8c50);
                                  if (plVar7 == (longlong *)0x0) {
                                    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                    plVar7 = *(longlong **)(param_1 + 0x70);
                                    iVar6 = 0xd2;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    plStack_68 = plVar7;
                                    uStack_70 = (longlong *)*(undefined8 *)(param_1 + 0x68);
                                  }
                                  else {
                                    *plVar7 = *plVar7 + -1;
                                    if (*plVar7 == 0) {
                                      FUN_23a334bc0(plVar7);
                                    }
                                    plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a98);
                                    if (plVar7 != (longlong *)0x0) {
                                      *(undefined4 *)(plVar2 + 5) = 0xd3;
                                      plVar10 = (longlong *)
                                                FUN_23e915840(param_1,plVar7,DAT_23eed8c60);
                                      *plVar7 = *plVar7 + -1;
                                      if (*plVar7 == 0) {
                                        FUN_23a334bc0(plVar7);
                                      }
                                      if (plVar10 != (longlong *)0x0) {
                                        *plVar10 = *plVar10 + -1;
                                        if (*plVar10 == 0) {
                                          FUN_23a334bc0(plVar10);
                                        }
                                        lVar12 = FUN_23e8e0ba0();
                                        if (lVar12 == 0) {
                                          FUN_23e915740(param_1,auStack_78,DAT_23eed8c70);
                                          iVar6 = 0xd4;
                                          plVar7 = plStack_68;
                                          goto LAB_23e720a7a;
                                        }
                                        *(undefined4 *)(plVar2 + 5) = 0xd4;
                                        plVar7 = (longlong *)FUN_23e91bfe0(param_1,lVar12);
                                        if (plVar7 != (longlong *)0x0) {
                                          cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eed8b30);
                                          *plVar7 = *plVar7 + -1;
                                          if (*plVar7 == 0) {
                                            FUN_23a334bc0(plVar7);
                                          }
                                          if (cVar5 != '\0') {
                                            cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eed8b38,pcVar4);
                                            lVar12 = DAT_23eed8c78;
                                            if (cVar5 == '\0') {
                                              auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                              plVar7 = *(longlong **)(param_1 + 0x70);
                                              iVar6 = 0xd5;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              plStack_68 = plVar7;
                                              uStack_70 = (longlong *)
                                                          *(undefined8 *)(param_1 + 0x68);
                                            }
                                            else {
                                              *(undefined4 *)(plVar2 + 5) = 0xd6;
                                              plVar7 = (longlong *)
                                                       FUN_23e915840(param_1,plVar1,DAT_23eed8c50,
                                                                     *(undefined8 *)(lVar12 + 0x18))
                                              ;
                                              if (plVar7 == (longlong *)0x0) {
                                                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                                plVar7 = *(longlong **)(param_1 + 0x70);
                                                iVar6 = 0xd6;
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                plStack_68 = plVar7;
                                                uStack_70 = (longlong *)
                                                            *(undefined8 *)(param_1 + 0x68);
                                              }
                                              else {
                                                *plVar7 = *plVar7 + -1;
                                                if (*plVar7 == 0) {
                                                  FUN_23a334bc0(plVar7);
                                                }
                                                lVar12 = FUN_23e8e0ba0();
                                                if (lVar12 == 0) {
                                                  FUN_23e915740(param_1,auStack_78,DAT_23eed8c70);
                                                  iVar6 = 0xda;
                                                  plVar7 = plStack_68;
                                                }
                                                else {
                                                  *(undefined4 *)(plVar2 + 5) = 0xda;
                                                  plVar7 = (longlong *)FUN_23e91bfe0(param_1,lVar12)
                                                  ;
                                                  if (plVar7 != (longlong *)0x0) {
                                                    plVar10 = (longlong *)
                                                              FUN_23e8bfe00(plVar7,_DAT_23eed8c80);
                                                    *plVar7 = *plVar7 + -1;
                                                    if (*plVar7 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    if (plVar10 != (longlong *)0x0) {
                                                      cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eed8a80);
                                                      *plVar10 = *plVar10 + -1;
                                                      if (*plVar10 == 0) {
                                                        FUN_23a334bc0(plVar10);
                                                      }
                                                      if (cVar5 != '\0') {
                                                        lVar12 = FUN_23e8e0cf0();
                                                        if (lVar12 == 0) {
                                                          FUN_23e915740(param_1,auStack_78,
                                                                        DAT_23eed89a0);
                                                          iVar6 = 0xdd;
                                                          plVar7 = plStack_68;
                                                        }
                                                        else {
                                                          plVar10 = (longlong *)
                                                                    FUN_23e8bc2f0(lVar12,
                                                  DAT_23eed8c88);
                                                  if (plVar10 != (longlong *)0x0) {
                                                    plVar7 = (longlong *)
                                                             FUN_23e8bc2f0(plVar1,DAT_23eed8c90);
                                                    if (plVar7 == (longlong *)0x0) {
                                                      auStack_78 = *(undefined1 (*) [8])
                                                                    (param_1 + 0x60);
                                                      uStack_70 = *(longlong **)(param_1 + 0x68);
                                                      plStack_68 = *(longlong **)(param_1 + 0x70);
                                                      iVar6 = 0xdd;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *plVar10 = *plVar10 + -1;
                                                      lVar12 = *plVar10;
joined_r0x00023e722dab:
                                                      plVar7 = plStack_68;
                                                      if (lVar12 == 0) {
                                                        FUN_23a334bc0(plVar10);
                                                        plVar7 = plStack_68;
                                                      }
                                                      goto LAB_23e720a7a;
                                                    }
                                                    *(undefined4 *)(plVar2 + 5) = 0xdd;
                                                    pcStack_a0 = pcVar4;
                                                    plStack_a8 = plVar7;
                                                    plVar16 = (longlong *)
                                                              FUN_23e9186b0(param_1,plVar10,
                                                                            &plStack_a8,
                                                                            DAT_23eed8c98);
                                                    *plVar10 = *plVar10 + -1;
                                                    if (*plVar10 == 0) {
                                                      FUN_23a334bc0(plVar10);
                                                    }
                                                    *plVar7 = *plVar7 + -1;
                                                    if (*plVar7 == 0) {
                                                      FUN_23a334bc0(plVar7);
                                                    }
                                                    if (plVar16 != (longlong *)0x0) {
                                                      cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eed8ad0);
                                                      *plVar16 = *plVar16 + -1;
                                                      if (*plVar16 == 0) {
                                                        FUN_23a334bc0(plVar16);
                                                      }
                                                      if (cVar5 != '\0') {
                                                        lVar12 = FUN_23e8e0cf0();
                                                        if (lVar12 == 0) {
                                                          FUN_23e915740(param_1,auStack_78,
                                                                        DAT_23eed89a0);
                                                          iVar6 = 0xde;
                                                          plVar7 = plStack_68;
                                                        }
                                                        else {
                                                          plVar10 = (longlong *)
                                                                    FUN_23e8bc2f0(lVar12,
                                                  DAT_23eed8c88);
                                                  if (plVar10 != (longlong *)0x0) {
                                                    plVar7 = (longlong *)
                                                             FUN_23e8bc2f0(plVar1,DAT_23eed8ca0);
                                                    if (plVar7 == (longlong *)0x0) {
                                                      auStack_78 = *(undefined1 (*) [8])
                                                                    (param_1 + 0x60);
                                                      uStack_70 = *(longlong **)(param_1 + 0x68);
                                                      plStack_68 = *(longlong **)(param_1 + 0x70);
                                                      iVar6 = 0xde;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *plVar10 = *plVar10 + -1;
                                                      lVar12 = *plVar10;
                                                      goto joined_r0x00023e722dab;
                                                    }
                                                    *(undefined4 *)(plVar2 + 5) = 0xde;
                                                    pcStack_a0 = pcVar4;
                                                    plStack_a8 = plVar7;
                                                    plVar16 = (longlong *)
                                                              FUN_23e9186b0(param_1,plVar10,
                                                                            &plStack_a8);
                                                    *plVar10 = *plVar10 + -1;
                                                    if (*plVar10 == 0) {
                                                      FUN_23a334bc0(plVar10);
                                                    }
                                                    *plVar7 = *plVar7 + -1;
                                                    if (*plVar7 == 0) {
                                                      FUN_23a334bc0(plVar7);
                                                    }
                                                    if (plVar16 != (longlong *)0x0) {
                                                      cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eed8ad8);
                                                      *plVar16 = *plVar16 + -1;
                                                      if (*plVar16 == 0) {
                                                        FUN_23a334bc0(plVar16);
                                                      }
                                                      if (cVar5 != '\0') {
                                                        plVar7 = (longlong *)
                                                                 FUN_23e8bc2f0(plVar1,DAT_23eed8ad0)
                                                        ;
                                                        uVar18 = DAT_23eed8ca8;
                                                        if (plVar7 != (longlong *)0x0) {
                                                          *(undefined4 *)(plVar2 + 5) = 0xdf;
                                                          plVar10 = (longlong *)
                                                                    FUN_23e91bfe0(param_1,plVar7,
                                                                                  uVar18);
                                                          *plVar7 = *plVar7 + -1;
                                                          if (*plVar7 == 0) {
                                                            FUN_23a334bc0(plVar7);
                                                          }
                                                          if (plVar10 != (longlong *)0x0) {
                                                            *plVar10 = *plVar10 + -1;
                                                            if (*plVar10 == 0) {
                                                              FUN_23a334bc0(plVar10);
                                                            }
                                                            plVar7 = (longlong *)
                                                                     FUN_23e8bc2f0(plVar1,
                                                  DAT_23eed8ad8);
                                                  if (plVar7 != (longlong *)0x0) {
                                                    *(undefined4 *)(plVar2 + 5) = 0xe0;
                                                    plVar10 = (longlong *)
                                                              FUN_23e91bfe0(param_1,plVar7);
                                                    *plVar7 = *plVar7 + -1;
                                                    if (*plVar7 == 0) {
                                                      FUN_23a334bc0(plVar7);
                                                    }
                                                    if (plVar10 != (longlong *)0x0) {
                                                      *plVar10 = *plVar10 + -1;
                                                      if (*plVar10 == 0) {
                                                        FUN_23a334bc0(plVar10);
                                                      }
                                                      plVar7 = (longlong *)
                                                               FUN_23e8bc2f0(plVar1,DAT_23eed8af8);
                                                      if (plVar7 != (longlong *)0x0) {
                                                        *(undefined4 *)(plVar2 + 5) = 0xe3;
                                                        plVar10 = (longlong *)
                                                                  FUN_23e91bfe0(param_1,plVar7);
                                                        *plVar7 = *plVar7 + -1;
                                                        if (*plVar7 == 0) {
                                                          FUN_23a334bc0(plVar7);
                                                        }
                                                        if (plVar10 != (longlong *)0x0) {
                                                          *plVar10 = *plVar10 + -1;
                                                          if (*plVar10 == 0) {
                                                            FUN_23a334bc0(plVar10);
                                                          }
                                                          lVar12 = _DAT_23eed8cb0;
                                                          *(undefined4 *)(plVar2 + 5) = 0xe4;
                                                          plVar7 = (longlong *)
                                                                   FUN_23e915840(param_1,plVar1,
                                                                                 DAT_23eed8b40,
                                                                                 *(undefined8 *)
                                                                                  (lVar12 + 0x18));
                                                          if (plVar7 != (longlong *)0x0) {
                                                            *plVar7 = *plVar7 + -1;
                                                            if (*plVar7 == 0) {
                                                              FUN_23a334bc0();
                                                            }
                                                            FUN_23ebf6b20(*(undefined8 *)
                                                                           (param_1 + 0x38));
                                                            *(longlong *)pcStack_e8 =
                                                                 *(longlong *)pcStack_e8 + 1;
                                                            *plVar8 = *plVar8 + -1;
                                                            if (*plVar8 == 0) {
                                                              (**(code **)(plVar8[1] + 0x30))
                                                                        (plVar8);
                                                            }
                                                            if ((plVar9 != (longlong *)0x0) &&
                                                               (*plVar9 = *plVar9 + -1, *plVar9 == 0
                                                               )) {
                                                              (**(code **)(plVar9[1] + 0x30))
                                                                        (plVar9);
                                                            }
                                                            *plVar14 = *plVar14 + -1;
                                                            if (*plVar14 == 0) {
                                                              (**(code **)(plVar14[1] + 0x30))
                                                                        (plVar14);
                                                            }
                                                            *(longlong *)pcVar15 =
                                                                 *(longlong *)pcVar15 + -1;
                                                            if (*(longlong *)pcVar15 == 0) {
                                                              (**(code **)(*(longlong *)
                                                                            (pcVar15 + 8) + 0x30))
                                                                        (pcVar15);
                                                            }
                                                            *plVar11 = *plVar11 + -1;
                                                            if (*plVar11 == 0) {
                                                              (**(code **)(plVar11[1] + 0x30))
                                                                        (plVar11);
                                                              *plVar1 = *plVar1 + -1;
                                                              lVar12 = *plVar1;
                                                              goto joined_r0x00023e71fe37;
                                                            }
                                                            goto LAB_23e71fe32;
                                                          }
                                                          auStack_78 = *(undefined1 (*) [8])
                                                                        (param_1 + 0x60);
                                                          plVar7 = *(longlong **)(param_1 + 0x70);
                                                          iVar6 = 0xe4;
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          plStack_68 = plVar7;
                                                          uStack_70 = (longlong *)
                                                                      *(undefined8 *)
                                                                       (param_1 + 0x68);
                                                          goto LAB_23e720a7a;
                                                        }
                                                      }
                                                      auStack_78 = *(undefined1 (*) [8])
                                                                    (param_1 + 0x60);
                                                      plVar7 = *(longlong **)(param_1 + 0x70);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      iVar6 = 0xe3;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      plStack_68 = plVar7;
                                                      uStack_70 = (longlong *)
                                                                  *(undefined8 *)(param_1 + 0x68);
                                                      goto LAB_23e720a7a;
                                                    }
                                                  }
                                                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  plVar7 = *(longlong **)(param_1 + 0x70);
                                                  iVar6 = 0xe0;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  plStack_68 = plVar7;
                                                  uStack_70 = (longlong *)
                                                              *(undefined8 *)(param_1 + 0x68);
                                                  goto LAB_23e720a7a;
                                                  }
                                                  }
                                                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  plVar7 = *(longlong **)(param_1 + 0x70);
                                                  iVar6 = 0xdf;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  plStack_68 = plVar7;
                                                  uStack_70 = (longlong *)
                                                              *(undefined8 *)(param_1 + 0x68);
                                                  goto LAB_23e720a7a;
                                                  }
                                                  }
                                                  }
                                                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  plVar7 = *(longlong **)(param_1 + 0x70);
                                                  iVar6 = 0xde;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  plStack_68 = plVar7;
                                                  uStack_70 = (longlong *)
                                                              *(undefined8 *)(param_1 + 0x68);
                                                  }
                                                  goto LAB_23e720a7a;
                                                  }
                                                  }
                                                  }
                                                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  plVar7 = *(longlong **)(param_1 + 0x70);
                                                  iVar6 = 0xdd;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  plStack_68 = plVar7;
                                                  uStack_70 = (longlong *)
                                                              *(undefined8 *)(param_1 + 0x68);
                                                  }
                                                  goto LAB_23e720a7a;
                                                  }
                                                  }
                                                  }
                                                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  plVar7 = *(longlong **)(param_1 + 0x70);
                                                  iVar6 = 0xda;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  plStack_68 = plVar7;
                                                  uStack_70 = (longlong *)
                                                              *(undefined8 *)(param_1 + 0x68);
                                                }
                                              }
                                            }
                                            goto LAB_23e720a7a;
                                          }
                                        }
                                        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                        plVar7 = *(longlong **)(param_1 + 0x70);
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        iVar6 = 0xd4;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        plStack_68 = plVar7;
                                        uStack_70 = (longlong *)*(undefined8 *)(param_1 + 0x68);
                                        goto LAB_23e720a7a;
                                      }
                                    }
                                    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                    plVar7 = *(longlong **)(param_1 + 0x70);
                                    iVar6 = 0xd3;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    plStack_68 = plVar7;
                                    uStack_70 = (longlong *)*(undefined8 *)(param_1 + 0x68);
                                  }
                                }
                              }
                              goto LAB_23e720a7a;
                            }
                          }
                        }
                      }
                    }
                  }
                  plStack_68 = *(longlong **)(param_1 + 0x70);
                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  uStack_70 = *(longlong **)(param_1 + 0x68);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  lVar12 = *plVar10;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar10 = lVar12 + -1;
                  if (lVar12 + -1 == 0) {
                    FUN_23a334bc0(plVar10);
                  }
                  lVar12 = *plVar16;
                  *plVar16 = lVar12 + -1;
                  if (lVar12 + -1 == 0) {
                    FUN_23a334bc0(plVar16);
                  }
                  iVar6 = 0xce;
                  plVar7 = plStack_68;
                  goto LAB_23e720a7a;
                }
                plStack_68 = *(longlong **)(param_1 + 0x70);
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                uStack_70 = *(longlong **)(param_1 + 0x68);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e7230e5;
              }
              plVar16 = (longlong *)0x0;
              *plVar10 = *plVar10 + -1;
              plVar7 = plStack_68;
              auVar21 = auStack_78;
              uVar18 = uStack_70;
              if (*plVar10 == 0) {
LAB_23e7231e6:
                plStack_68 = (longlong *)0x0;
                _auStack_78 = (undefined1  [16])0x0;
                FUN_23a334bc0(plVar10);
                plStack_68 = (longlong *)0x0;
                _auStack_78 = (undefined1  [16])0x0;
                if (plVar11 != (longlong *)0x0) goto LAB_23e723185;
LAB_23e7231a7:
                plVar11 = (longlong *)0x0;
                goto LAB_23e72310c;
              }
            }
            else {
              iVar6 = *(int *)(lVar12 + 0xc);
              if (*(int *)(lVar12 + 0xc) == 0) {
                *(int *)(lVar12 + 0xc) = DAT_23ec1545c;
                iVar6 = DAT_23ec1545c;
                DAT_23ec1545c = DAT_23ec1545c + 1;
              }
              if (_DAT_23ec15450 != iVar6) {
                _DAT_23ec15450 = iVar6;
                _DAT_23eedae88 =
                     FUN_23e8cbd60(lVar12,_DAT_23eed8c20,*(undefined8 *)(_DAT_23eed8c20 + 0x18));
              }
              if (-1 < _DAT_23eedae88) {
                lVar13 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
                lVar19 = *(longlong *)(lVar13 + 8 + _DAT_23eedae88 * 0x10);
                if (lVar19 != 0) goto LAB_23e721943;
                _DAT_23eedae88 =
                     FUN_23e8cbd60(lVar12,_DAT_23eed8c20,*(undefined8 *)(_DAT_23eed8c20 + 0x18));
                if (-1 < _DAT_23eedae88) {
                  lVar19 = *(longlong *)(lVar13 + 8 + _DAT_23eedae88 * 0x10);
                  goto LAB_23e723287;
                }
              }
LAB_23e723290:
              plVar7 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eed8c20);
              if ((plVar7 != (longlong *)0x0) && (lVar19 = *plVar7, lVar19 != 0))
              goto LAB_23e721943;
              FUN_23e915740(param_1,auStack_78,_DAT_23eed8c20);
LAB_23e72324a:
              plVar16 = (longlong *)0x0;
              plVar11 = (longlong *)0x0;
LAB_23e7230e5:
              plVar7 = plStack_68;
              uVar18 = uStack_70;
              auVar21 = auStack_78;
              plStack_68 = (longlong *)0x0;
              _auStack_78 = (undefined1  [16])0x0;
LAB_23e72310c:
              if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
                FUN_23a334bc0(plVar16);
              }
            }
            iVar6 = 0xcd;
            plStack_68 = plVar7;
            auStack_78 = auVar21;
            uStack_70 = (longlong *)uVar18;
            goto LAB_23e720a7a;
          }
          *plVar11 = *plVar11 + -1;
          plVar7 = plStack_68;
          auVar21 = auStack_78;
          uVar18 = uStack_70;
          if (*plVar11 == 0) goto LAB_23e7233b3;
LAB_23e723329:
          uStack_70 = (longlong *)0x0;
          auStack_78 = (undefined1  [8])0x0;
          plStack_68 = (longlong *)0x0;
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            FUN_23a334bc0(plVar14);
          }
LAB_23e723341:
          if ((pcVar15 != (code *)0x0) &&
             (*(longlong *)pcVar15 = *(longlong *)pcVar15 + -1, *(longlong *)pcVar15 == 0)) {
            FUN_23a334bc0(pcVar15);
          }
        }
      }
      plVar11 = (longlong *)0x0;
      pcVar15 = (code *)0x0;
      plVar14 = (longlong *)0x0;
      iVar6 = 0xcc;
      plStack_68 = plVar7;
      auStack_78 = auVar21;
      uStack_70 = (longlong *)uVar18;
      goto LAB_23e720a7a;
    }
LAB_23e7223b7:
    plStack_68 = *(longlong **)(param_1 + 0x70);
    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    uStack_70 = *(longlong **)(param_1 + 0x68);
    uVar18 = 0xc2;
    plVar9 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7223e6:
    plVar7 = plStack_68;
    plStack_90 = uStack_70;
    plStack_98 = (longlong *)auStack_78;
    plVar14 = *(longlong **)(param_1 + 0x138);
    auStack_78 = (undefined1  [8])0x0;
    uStack_70 = (longlong *)0x0;
    plStack_88 = plStack_68;
    plStack_68 = (longlong *)0x0;
    if (plVar14 != (longlong *)0x0) {
      *plVar14 = *plVar14 + 1;
    }
    if (plVar7 == (longlong *)0x0) {
      lVar12 = FUN_23e8d6280(plVar2,uVar18);
    }
    else {
      lVar12 = FUN_23e8d6280(plVar2,uVar18);
      *(longlong **)(lVar12 + 0x10) = plVar7;
      *plVar7 = *plVar7 + 1;
    }
    if ((plStack_88 != (longlong *)0x0) && (*plStack_88 = *plStack_88 + -1, *plStack_88 == 0)) {
      FUN_23a334bc0();
    }
    plStack_88 = (longlong *)lVar12;
    FUN_23a35ef40(param_1,&plStack_98);
    iVar6 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8));
    uVar18 = DAT_23eed8b40;
    if (iVar6 == 0) {
      cVar5 = FUN_23e8ba320(*(undefined8 *)(param_1 + 0x138),auStack_78);
      plVar7 = plStack_68;
      uVar18 = uStack_70;
      iVar6 = 0;
      if (cVar5 == '\0') {
        iVar6 = 0xc1;
      }
      uStack_70 = (longlong *)uVar18;
      if (plStack_68 != (longlong *)0x0) {
        if ((longlong *)plStack_68[3] == plVar2) {
          *(undefined4 *)(plVar2 + 5) = *(undefined4 *)((longlong)plStack_68 + 0x24);
        }
        plStack_68 = (longlong *)0x0;
        _auStack_78 = (undefined1  [16])0x0;
        FUN_23ebf6ae0(param_1,plVar14);
        goto LAB_23e7227d2;
      }
      _auStack_78 = (undefined1  [16])0x0;
      FUN_23ebf6ae0(param_1,plVar14);
      plStack_68 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      if (iVar6 == 0) {
        iVar6 = (int)plVar2[5];
        plVar11 = (longlong *)0x0;
        pcVar15 = (code *)0x0;
      }
      else {
        plVar11 = (longlong *)0x0;
        pcVar15 = (code *)0x0;
        iVar6 = 0xc1;
      }
      goto LAB_23e720d42;
    }
    plVar11 = *(longlong **)(param_1 + 0x138);
    *plVar11 = *plVar11 + 1;
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,uVar18);
    plVar7 = _DAT_23eed8c10;
    if (plVar10 == (longlong *)0x0) {
LAB_23e7227ea:
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      uStack_70 = *(longlong **)(param_1 + 0x68);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
    else {
      plVar16 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
      *plVar7 = *plVar7 + 1;
      plVar16[3] = (longlong)plVar7;
      lVar12 = FUN_23e94f9d0(param_1,plVar11);
      if (lVar12 == 0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        uStack_70 = *(longlong **)(param_1 + 0x68);
        plStack_68 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          FUN_23a334bc0(plVar10);
        }
        *plVar16 = *plVar16 + -1;
        if (*plVar16 == 0) {
          FUN_23a334bc0(plVar16);
        }
      }
      else {
        plVar16[4] = lVar12;
        plVar7 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
        *plVar16 = *plVar16 + -1;
        if (*plVar16 == 0) {
          FUN_23a334bc0(plVar16);
        }
        if (plVar7 != (longlong *)0x0) {
          *(undefined4 *)(plVar2 + 5) = 0xc9;
          plVar16 = (longlong *)FUN_23e914090(param_1,plVar10);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            FUN_23a334bc0(plVar10);
          }
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            FUN_23a334bc0(plVar7);
          }
          if (plVar16 != (longlong *)0x0) {
            *plVar16 = *plVar16 + -1;
            if (*plVar16 == 0) {
              FUN_23a334bc0(plVar16);
            }
            lVar12 = *plVar11;
            *plVar11 = lVar12 + -1;
            if (lVar12 + -1 == 0) {
              FUN_23a334bc0(plVar11);
            }
            FUN_23ebf6ae0(param_1,plVar14);
            goto LAB_23e7217a4;
          }
          goto LAB_23e7227ea;
        }
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        uStack_70 = *(longlong **)(param_1 + 0x68);
        plStack_68 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          FUN_23a334bc0(plVar10);
        }
      }
    }
    plVar7 = plStack_68;
    uVar18 = uStack_70;
    auVar21 = auStack_78;
    _auStack_78 = (undefined1  [16])0x0;
    lVar12 = *plVar11;
    plStack_68 = (longlong *)0x0;
    *plVar11 = lVar12 + -1;
    if (lVar12 + -1 == 0) {
      FUN_23a334bc0(plVar11);
    }
    plStack_68 = (longlong *)0x0;
    _auStack_78 = (undefined1  [16])0x0;
    FUN_23ebf6ae0(param_1,plVar14);
    iVar6 = 0xc9;
    auStack_78 = auVar21;
    uStack_70 = (longlong *)uVar18;
    if (plVar7 == (longlong *)0x0) {
      plVar11 = (longlong *)0x0;
      pcVar15 = (code *)0x0;
      iVar6 = 0xc9;
      plVar14 = (longlong *)0x0;
      plStack_68 = plVar7;
      goto LAB_23e720d42;
    }
LAB_23e7227d2:
    if ((longlong *)plVar7[3] == plVar2) {
      plVar11 = (longlong *)0x0;
      pcVar15 = (code *)0x0;
      plVar14 = (longlong *)0x0;
      plVar10 = plVar7;
      goto LAB_23e720b40;
    }
    plStack_68 = plVar7;
    if (iVar6 == 0) {
      iVar6 = (int)plVar2[5];
      plVar11 = (longlong *)0x0;
      pcVar15 = (code *)0x0;
      plVar14 = (longlong *)0x0;
    }
    else {
      plVar11 = (longlong *)0x0;
      pcVar15 = (code *)0x0;
      plVar14 = (longlong *)0x0;
    }
  }
  plVar10 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (longlong *)0x0) {
    plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    plVar16 = plStack_68;
  }
  else {
    plVar16 = (longlong *)*DAT_23ed6a4f8;
    *DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = plVar16;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    plVar16 = plVar7;
  }
  plVar10[3] = (longlong)plVar2;
  *plVar2 = *plVar2 + 1;
  lVar12 = *(longlong *)(pcVar20 + 0x1f8);
  *(int *)((longlong)plVar10 + 0x24) = iVar6;
  lVar12 = *(longlong *)(lVar12 + 0x10);
  *(undefined4 *)(plVar10 + 4) = 0xffffffff;
  lVar12 = *(longlong *)(lVar12 + 0x2e8);
  lVar13 = plVar10[-1];
  puVar3 = *(undefined8 **)(lVar12 + 8);
  *puVar3 = plVar10 + -2;
  plVar10[-2] = lVar12;
  plVar10[-1] = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar3;
  *(longlong **)(lVar12 + 8) = plVar10 + -2;
  plVar10[2] = (longlong)plVar7;
  *plVar7 = *plVar7 + 1;
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
LAB_23e720b40:
  plStack_68 = plVar10;
  FUN_23e8bba40(plVar2,"ooooooo",plVar1,plVar8,plVar9,0,plVar14,pcVar15,plVar11);
  if (_DAT_23eedae90 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    _DAT_23eedae90 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar7 = *(longlong **)(lVar12 + 0x28);
  plVar2 = (longlong *)plVar7[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar7 + 8) = 0xffffffff;
  if (plVar2 != (longlong *)0x0) {
    plVar7[2] = 0;
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))();
    }
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  plVar2 = plStack_68;
  uVar18 = uStack_70;
  auVar21 = auStack_78;
  plVar7[0xf] = 0;
  _auStack_78 = (undefined1  [16])0x0;
  plStack_68 = (longlong *)0x0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((pcVar15 != (code *)0x0) &&
     (*(longlong *)pcVar15 = *(longlong *)pcVar15 + -1, *(longlong *)pcVar15 == 0)) {
    (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  *plVar1 = *plVar1 + -1;
  plStack_68 = plVar2;
  auStack_78 = auVar21;
  uStack_70 = (longlong *)uVar18;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,auStack_78,uStack_70,plStack_68);
  return (code *)0x0;
}
