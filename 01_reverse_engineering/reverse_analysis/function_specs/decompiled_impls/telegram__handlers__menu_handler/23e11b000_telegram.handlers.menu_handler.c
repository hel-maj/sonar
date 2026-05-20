/* ===== 23e11b000 telegram.handlers.menu_handler:10 ===== */
/* ghidra_name=forced_23e11b000 entry=23e11b000 size=1086 */

code * forced_23e11b000(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  int iVar8;
  longlong *plVar9;
  undefined4 uVar10;
  longlong *plVar11;
  code *pcVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  
  plVar11 = DAT_23eeab0b0;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (DAT_23eeab0b0 == (longlong *)0x0) {
LAB_23e11b03e:
    DAT_23eeab0b0 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeab0a0,DAT_23eeab0a8,0x10);
  }
  else {
    lVar3 = *DAT_23eeab0b0;
    if (1 < lVar3) {
      *DAT_23eeab0b0 = lVar3 + -1;
      goto LAB_23e11b03e;
    }
    if (DAT_23eeab0b0[2] != 0) {
      *DAT_23eeab0b0 = lVar3 + -1;
      if (lVar3 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e11b03e;
    }
  }
  plVar5 = DAT_23eeab0b0;
  lVar3 = *(longlong *)(param_1 + 0x38);
  plVar11 = DAT_23eeab0b0 + 9;
  lVar4 = *(longlong *)(lVar3 + 8);
  DAT_23eeab0b0[0xf] = lVar4;
  *(longlong **)(lVar3 + 8) = plVar11;
  if ((lVar4 != 0) &&
     (((*(char *)(lVar4 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar4 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar4 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar4 + 0x38))
       ) && (plVar5[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar4 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  *(undefined4 *)(plVar5 + 8) = 0;
  iVar8 = FUN_23a35f020(plVar2);
  pcVar12 = _Py_TrueStruct_exref;
  if (iVar8 == -1) {
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    uVar14 = *(undefined8 *)(param_1 + 0x68);
    uVar10 = 0xc;
    plVar11 = *(longlong **)(param_1 + 0x70);
LAB_23e11b1e9:
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar7 = DAT_23ed6a4f8;
    if (plVar11 == (longlong *)0x0) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar11 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar11;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar9 = plVar7;
      }
      pcVar12 = _PyRuntime_exref;
      plVar9[2] = 0;
      plVar9[3] = (longlong)plVar5;
      *plVar5 = *plVar5 + 1;
      lVar3 = *(longlong *)(pcVar12 + 0x1f8);
      *(undefined4 *)((longlong)plVar9 + 0x24) = uVar10;
      lVar3 = *(longlong *)(lVar3 + 0x10);
      *(undefined4 *)(plVar9 + 4) = 0xffffffff;
      lVar3 = *(longlong *)(lVar3 + 0x2e8);
      lVar4 = plVar9[-1];
      puVar6 = *(undefined8 **)(lVar3 + 8);
      *puVar6 = plVar9 + -2;
      plVar9[-2] = lVar3;
      plVar9[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
      *(longlong **)(lVar3 + 8) = plVar9 + -2;
    }
    else {
      plVar9 = plVar11;
      if ((longlong *)plVar11[3] != plVar5) {
        if (DAT_23ed6a4f8 == (longlong *)0x0) {
          plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          plVar9 = (longlong *)*DAT_23ed6a4f8;
          *DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = plVar9;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          plVar9 = plVar7;
        }
        pcVar12 = _PyRuntime_exref;
        plVar9[3] = (longlong)plVar5;
        *plVar5 = *plVar5 + 1;
        lVar3 = *(longlong *)(pcVar12 + 0x1f8);
        *(undefined4 *)((longlong)plVar9 + 0x24) = uVar10;
        *(undefined4 *)(plVar9 + 4) = 0xffffffff;
        lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x2e8);
        lVar4 = plVar9[-1];
        puVar6 = *(undefined8 **)(lVar3 + 8);
        *puVar6 = plVar9 + -2;
        plVar9[-2] = lVar3;
        plVar9[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
        lVar4 = *plVar11;
        *(longlong **)(lVar3 + 8) = plVar9 + -2;
        plVar9[2] = (longlong)plVar11;
        if (lVar4 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
      }
    }
    FUN_23e8bba40(plVar5,&DAT_23ec5a08f,plVar1,plVar2);
    if (DAT_23eeab0b0 == plVar5) {
      *plVar5 = *plVar5 + -1;
      if (*plVar5 == 0) {
        (**(code **)(plVar5[1] + 0x30))(plVar5);
      }
      DAT_23eeab0b0 = (longlong *)0x0;
    }
    lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar11 = *(longlong **)(lVar3 + 0x28);
    plVar5 = (longlong *)plVar11[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar3 + 0x30);
    *(undefined4 *)(plVar11 + 8) = 0xffffffff;
    if (plVar5 != (longlong *)0x0) {
      plVar11[2] = 0;
      *plVar5 = *plVar5 + -1;
      if (*plVar5 == 0) {
        (**(code **)(plVar5[1] + 0x30))();
      }
    }
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    plVar11[0xf] = 0;
    *plVar1 = *plVar1 + -1;
    if (*plVar1 == 0) {
      (**(code **)(plVar1[1] + 0x30))(plVar1);
    }
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    FUN_23a33aa70(param_1,uVar13,uVar14,plVar9);
    pcVar12 = (code *)0x0;
  }
  else {
    if (iVar8 == 0) {
      *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
    }
    else {
      iVar8 = PySequence_Contains(plVar2,plVar1);
      if (iVar8 == -1) {
        uVar13 = *(undefined8 *)(param_1 + 0x60);
        uVar14 = *(undefined8 *)(param_1 + 0x68);
        uVar10 = 0xe;
        plVar11 = *(longlong **)(param_1 + 0x70);
        goto LAB_23e11b1e9;
      }
      pcVar12 = _Py_TrueStruct_exref;
      if (iVar8 != 1) {
        pcVar12 = _Py_FalseStruct_exref;
      }
      *(longlong *)pcVar12 = *(longlong *)pcVar12 + 1;
    }
    lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar11 = *(longlong **)(lVar3 + 0x28);
    plVar5 = (longlong *)plVar11[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar3 + 0x30);
    *(undefined4 *)(plVar11 + 8) = 0xffffffff;
    if (plVar5 != (longlong *)0x0) {
      plVar11[2] = 0;
      *plVar5 = *plVar5 + -1;
      if (*plVar5 == 0) {
        (**(code **)(plVar5[1] + 0x30))();
      }
    }
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    plVar11[0xf] = 0;
    *plVar1 = *plVar1 + -1;
    if (*plVar1 == 0) {
      (**(code **)(plVar1[1] + 0x30))(plVar1);
    }
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
  }
  return pcVar12;
}
