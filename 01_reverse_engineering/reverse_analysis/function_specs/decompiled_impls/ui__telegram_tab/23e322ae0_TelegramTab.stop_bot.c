/* ===== 23e322ae0 ui.telegram_tab:275 ===== */
/* ghidra_name=FUN_23e322ae0 entry=23e322ae0 size=1098 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e322ae0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  code *pcVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  
  plVar10 = _DAT_23eeb4c40;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eeb4c40 != (longlong *)0x0) {
    lVar3 = *_DAT_23eeb4c40;
    if (lVar3 < 2) {
      if (_DAT_23eeb4c40[2] == 0) goto LAB_23e322b44;
      *_DAT_23eeb4c40 = lVar3 + -1;
      if (lVar3 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
    else {
      *_DAT_23eeb4c40 = lVar3 + -1;
    }
  }
  _DAT_23eeb4c40 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb4c38,DAT_23eeb4cf0,0x10);
LAB_23e322b44:
  plVar5 = _DAT_23eeb4c40;
  lVar3 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eeb4c40 + 9;
  lVar4 = *(longlong *)(lVar3 + 8);
  _DAT_23eeb4c40[0xf] = lVar4;
  *(longlong **)(lVar3 + 8) = plVar10;
  if ((lVar4 != 0) &&
     (((*(char *)(lVar4 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar4 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar4 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar4 + 0x38))
       ) && (plVar5[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar4 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  uVar6 = _DAT_23eeb3bb0;
  *(undefined4 *)(plVar5 + 8) = 0;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,uVar6);
  if (plVar10 != (longlong *)0x0) {
    *(undefined4 *)(plVar5 + 5) = 0x115;
    plVar11 = (longlong *)FUN_23e915840(param_1,plVar10,_DAT_23eeb3be0,plVar2);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar10 = *(longlong **)(lVar3 + 0x28);
      plVar5 = (longlong *)plVar10[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar3 + 0x30);
      *(undefined4 *)(plVar10 + 8) = 0xffffffff;
      if (plVar5 != (longlong *)0x0) {
        plVar10[2] = 0;
        *plVar5 = *plVar5 + -1;
        if (*plVar5 == 0) {
          (**(code **)(plVar5[1] + 0x30))();
        }
      }
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      plVar10[0xf] = 0;
      pcVar9 = _Py_NoneStruct_exref;
      *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
      *plVar1 = *plVar1 + -1;
      if (*plVar1 == 0) {
        (**(code **)(plVar1[1] + 0x30))(plVar1);
      }
      *plVar2 = *plVar2 + -1;
      if (*plVar2 != 0) {
        return pcVar9;
      }
      (**(code **)(plVar2[1] + 0x30))(plVar2);
      return pcVar9;
    }
  }
  plVar10 = *(longlong **)(param_1 + 0x70);
  uVar6 = *(undefined8 *)(param_1 + 0x60);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar7 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar11 = DAT_23ed6a4f8;
  if (plVar10 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar10 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar10;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar12 = plVar11;
    }
    plVar12[2] = 0;
    plVar12[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    plVar12[4] = 0x115ffffffff;
    lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
    lVar4 = plVar12[-1];
    puVar8 = *(undefined8 **)(lVar3 + 8);
    *puVar8 = plVar12 + -2;
    plVar12[-2] = lVar3;
    plVar12[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar8;
    *(longlong **)(lVar3 + 8) = plVar12 + -2;
  }
  else {
    plVar12 = plVar10;
    if ((longlong *)plVar10[3] != plVar5) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar12 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar12;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar12 = plVar11;
      }
      plVar12[3] = (longlong)plVar5;
      *plVar5 = *plVar5 + 1;
      plVar12[4] = 0x115ffffffff;
      lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar4 = plVar12[-1];
      puVar8 = *(undefined8 **)(lVar3 + 8);
      *puVar8 = plVar12 + -2;
      plVar12[-2] = lVar3;
      plVar12[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar8;
      lVar4 = *plVar10;
      *(longlong **)(lVar3 + 8) = plVar12 + -2;
      plVar12[2] = (longlong)plVar10;
      if (lVar4 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
  }
  FUN_23e8bba40(plVar5,&DAT_23ec5b76c,plVar1,plVar2);
  if (_DAT_23eeb4c40 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23eeb4c40 = (longlong *)0x0;
  }
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar10 = *(longlong **)(lVar3 + 0x28);
  plVar5 = (longlong *)plVar10[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar3 + 0x30);
  *(undefined4 *)(plVar10 + 8) = 0xffffffff;
  if (plVar5 != (longlong *)0x0) {
    plVar10[2] = 0;
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))();
    }
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  plVar10[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,uVar6,uVar7,plVar12);
  return (code *)0x0;
}
