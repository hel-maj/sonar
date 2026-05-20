/* ===== 23e281710 ui.fishing_tab:c1157 ===== */
/* ghidra_name=FUN_23e281710 entry=23e281710 size=1227 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e281710(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  code *pcVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  longlong *plVar12;
  undefined4 uVar13;
  
  plVar8 = _DAT_23eeb05f0;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eeb05f0 == (longlong *)0x0) {
LAB_23e28174a:
    _DAT_23eeb05f0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb0618,DAT_23eeb0600,8);
  }
  else {
    lVar2 = *_DAT_23eeb05f0;
    if (1 < lVar2) {
      *_DAT_23eeb05f0 = lVar2 + -1;
      goto LAB_23e28174a;
    }
    if (_DAT_23eeb05f0[2] != 0) {
      *_DAT_23eeb05f0 = lVar2 + -1;
      if (lVar2 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e28174a;
    }
  }
  plVar4 = _DAT_23eeb05f0;
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eeb05f0 + 9;
  lVar3 = *(longlong *)(lVar2 + 8);
  _DAT_23eeb05f0[0xf] = lVar3;
  *(longlong **)(lVar2 + 8) = plVar8;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar10 = _DAT_23eeae840;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar10);
  if (plVar8 == (longlong *)0x0) {
    uVar10 = *(undefined8 *)(param_1 + 0x60);
    uVar11 = *(undefined8 *)(param_1 + 0x68);
    uVar13 = 0x42;
    plVar9 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
  }
  else {
    iVar7 = FUN_23a35f020(plVar8);
    lVar2 = *plVar8 + -1;
    if (iVar7 == -1) {
      uVar10 = *(undefined8 *)(param_1 + 0x60);
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      plVar9 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar8 = lVar2;
      if (lVar2 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      uVar13 = 0x42;
    }
    else {
      *plVar8 = lVar2;
      if (lVar2 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (iVar7 == 0) {
LAB_23e281819:
        lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar8 = *(longlong **)(lVar2 + 0x28);
        plVar4 = (longlong *)plVar8[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
        *(undefined4 *)(plVar8 + 8) = 0xffffffff;
        if (plVar4 != (longlong *)0x0) {
          plVar8[2] = 0;
          *plVar4 = *plVar4 + -1;
          if (*plVar4 == 0) {
            (**(code **)(plVar4[1] + 0x30))();
          }
        }
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        plVar8[0xf] = 0;
        pcVar6 = _Py_NoneStruct_exref;
        *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
        *plVar1 = *plVar1 + -1;
        if (*plVar1 != 0) {
          return pcVar6;
        }
        (**(code **)(plVar1[1] + 0x30))(plVar1);
        return pcVar6;
      }
      plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeae840);
      if (plVar8 != (longlong *)0x0) {
        *(undefined4 *)(plVar4 + 5) = 0x43;
        plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar8,_DAT_23eeae880);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if (plVar9 != (longlong *)0x0) {
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          goto LAB_23e281819;
        }
      }
      plVar9 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar13 = 0x43;
      uVar10 = *(undefined8 *)(param_1 + 0x60);
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
  }
  plVar8 = DAT_23ed6a4f8;
  if (plVar9 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar9 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar9;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar6 = _PyRuntime_exref;
    plVar8[2] = 0;
    plVar8[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar2 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)(plVar8 + 4) = 0xffffffff;
    lVar2 = *(longlong *)(lVar2 + 0x10);
    *(undefined4 *)((longlong)plVar8 + 0x24) = uVar13;
    lVar2 = *(longlong *)(lVar2 + 0x2e8);
    lVar3 = plVar8[-1];
    puVar5 = *(undefined8 **)(lVar2 + 8);
    *puVar5 = plVar8 + -2;
    plVar8[-2] = lVar2;
    plVar8[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar2 + 8) = plVar8 + -2;
    plVar12 = plVar8;
  }
  else {
    plVar12 = plVar9;
    if ((longlong *)plVar9[3] != plVar4) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar12 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar12;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar6 = _PyRuntime_exref;
      plVar8[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      lVar2 = *(longlong *)(pcVar6 + 0x1f8);
      *(undefined4 *)(plVar8 + 4) = 0xffffffff;
      *(undefined4 *)((longlong)plVar8 + 0x24) = uVar13;
      lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x2e8);
      lVar3 = plVar8[-1];
      puVar5 = *(undefined8 **)(lVar2 + 8);
      *puVar5 = plVar8 + -2;
      plVar8[-2] = lVar2;
      plVar8[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
      lVar3 = *plVar9;
      *(longlong **)(lVar2 + 8) = plVar8 + -2;
      plVar8[2] = (longlong)plVar9;
      plVar12 = plVar8;
      if (lVar3 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5b149,plVar1);
  if (_DAT_23eeb05f0 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eeb05f0 = (longlong *)0x0;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar2 + 0x28);
  plVar4 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar8[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar10,uVar11,plVar12);
  return (code *)0x0;
}
