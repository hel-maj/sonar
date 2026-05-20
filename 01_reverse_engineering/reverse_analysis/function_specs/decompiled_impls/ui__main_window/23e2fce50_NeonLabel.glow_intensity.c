/* ===== 23e2fce50 ui.main_window:c1276 ===== */
/* ghidra_name=FUN_23e2fce50 entry=23e2fce50 size=1005 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2fce50(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  longlong *plVar10;
  char cVar11;
  code *pcVar12;
  longlong *plVar13;
  
  plVar5 = _DAT_23eeaff20;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eeaff20 != (longlong *)0x0) {
    lVar3 = *_DAT_23eeaff20;
    if (lVar3 < 2) {
      if (_DAT_23eeaff20[2] == 0) goto LAB_23e2fceb4;
      *_DAT_23eeaff20 = lVar3 + -1;
      if (lVar3 + -1 == 0) {
        (**(code **)(plVar5[1] + 0x30))(plVar5);
      }
    }
    else {
      *_DAT_23eeaff20 = lVar3 + -1;
    }
  }
  _DAT_23eeaff20 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeac688,DAT_23eeac668,0x10);
LAB_23e2fceb4:
  plVar6 = _DAT_23eeaff20;
  lVar3 = *(longlong *)(param_1 + 0x38);
  plVar5 = _DAT_23eeaff20 + 9;
  lVar4 = *(longlong *)(lVar3 + 8);
  _DAT_23eeaff20[0xf] = lVar4;
  *(longlong **)(lVar3 + 8) = plVar5;
  if ((lVar4 != 0) &&
     (((*(char *)(lVar4 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar4 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar4 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar4 + 0x38))
       ) && (plVar6[0xe] != 0)))) {
    plVar5 = *(longlong **)(lVar4 + 0x28);
    *(longlong **)(plVar6[0xe] + 0x10) = plVar5;
    if (plVar5 != (longlong *)0x0) {
      *plVar5 = *plVar5 + 1;
    }
  }
  *plVar6 = *plVar6 + 1;
  uVar7 = DAT_23eeac6e0;
  *(undefined4 *)(plVar6 + 8) = 0;
  cVar11 = FUN_23e8d9ac0(plVar1,uVar7,plVar2);
  if (cVar11 == '\0') {
    plVar5 = *(longlong **)(param_1 + 0x70);
    uVar7 = *(undefined8 *)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar8 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = DAT_23ed6a4f8;
    if (plVar5 == (longlong *)0x0) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar5 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar5;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar13 = plVar10;
      }
      plVar13[3] = (longlong)plVar6;
      plVar13[2] = 0;
      *plVar6 = *plVar6 + 1;
      plVar13[4] = 0x45ffffffff;
      lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar4 = plVar13[-1];
      puVar9 = *(undefined8 **)(lVar3 + 8);
      *puVar9 = plVar13 + -2;
      plVar13[-2] = lVar3;
      plVar13[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar9;
      *(longlong **)(lVar3 + 8) = plVar13 + -2;
    }
    else {
      plVar13 = plVar5;
      if ((longlong *)plVar5[3] != plVar6) {
        if (DAT_23ed6a4f8 == (longlong *)0x0) {
          plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          plVar13 = (longlong *)*DAT_23ed6a4f8;
          *DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = plVar13;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          plVar13 = plVar10;
        }
        plVar13[3] = (longlong)plVar6;
        *plVar6 = *plVar6 + 1;
        plVar13[4] = 0x45ffffffff;
        lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8)
        ;
        lVar4 = plVar13[-1];
        puVar9 = *(undefined8 **)(lVar3 + 8);
        *puVar9 = plVar13 + -2;
        plVar13[-2] = lVar3;
        plVar13[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar9;
        lVar4 = *plVar5;
        *(longlong **)(lVar3 + 8) = plVar13 + -2;
        plVar13[2] = (longlong)plVar5;
        if (lVar4 == 0) {
          (**(code **)(plVar5[1] + 0x30))(plVar5);
        }
      }
    }
    FUN_23e8bba40(plVar6,&DAT_23ec5b14b,plVar1,plVar2);
    if (_DAT_23eeaff20 == plVar6) {
      *plVar6 = *plVar6 + -1;
      if (*plVar6 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      _DAT_23eeaff20 = (longlong *)0x0;
    }
    lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar5 = *(longlong **)(lVar3 + 0x28);
    plVar6 = (longlong *)plVar5[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar3 + 0x30);
    *(undefined4 *)(plVar5 + 8) = 0xffffffff;
    if (plVar6 != (longlong *)0x0) {
      plVar5[2] = 0;
      *plVar6 = *plVar6 + -1;
      if (*plVar6 == 0) {
        (**(code **)(plVar6[1] + 0x30))();
      }
    }
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    plVar5[0xf] = 0;
    *plVar1 = *plVar1 + -1;
    if (*plVar1 == 0) {
      (**(code **)(plVar1[1] + 0x30))(plVar1);
    }
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    FUN_23a33aa70(param_1,uVar7,uVar8,plVar13);
    pcVar12 = (code *)0x0;
  }
  else {
    lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar5 = *(longlong **)(lVar3 + 0x28);
    plVar6 = (longlong *)plVar5[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar3 + 0x30);
    *(undefined4 *)(plVar5 + 8) = 0xffffffff;
    if (plVar6 != (longlong *)0x0) {
      plVar5[2] = 0;
      *plVar6 = *plVar6 + -1;
      if (*plVar6 == 0) {
        (**(code **)(plVar6[1] + 0x30))();
      }
    }
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    plVar5[0xf] = 0;
    pcVar12 = _Py_NoneStruct_exref;
    *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
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
