/* ===== 23e322f50 ui.telegram_tab:279 ===== */
/* ghidra_name=FUN_23e322f50 entry=23e322f50 size=1558 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e322f50(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  code *pcVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  longlong *plVar13;
  undefined4 local_50;
  
  plVar9 = _DAT_23eeb4c30;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eeb4c30 == (longlong *)0x0) {
LAB_23e322f8e:
    _DAT_23eeb4c30 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb4c28,DAT_23eeb4cf0,0x10);
  }
  else {
    lVar3 = *_DAT_23eeb4c30;
    if (1 < lVar3) {
      *_DAT_23eeb4c30 = lVar3 + -1;
      goto LAB_23e322f8e;
    }
    if (_DAT_23eeb4c30[2] != 0) {
      *_DAT_23eeb4c30 = lVar3 + -1;
      if (lVar3 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e322f8e;
    }
  }
  plVar5 = _DAT_23eeb4c30;
  lVar3 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eeb4c30 + 9;
  lVar4 = *(longlong *)(lVar3 + 8);
  _DAT_23eeb4c30[0xf] = lVar4;
  *(longlong **)(lVar3 + 8) = plVar9;
  if ((lVar4 != 0) &&
     (((*(char *)(lVar4 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar4 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar4 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar4 + 0x38))
       ) && (plVar5[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar4 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  uVar11 = DAT_23eeb3990;
  *(undefined4 *)(plVar5 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,uVar11);
  if (plVar9 == (longlong *)0x0) goto LAB_23e323240;
  iVar8 = FUN_23a35f020(plVar9);
  lVar3 = *plVar9 + -1;
  if (iVar8 == -1) {
    uVar11 = *(undefined8 *)(param_1 + 0x60);
    uVar12 = *(undefined8 *)(param_1 + 0x68);
    local_50 = 0x119;
    plVar13 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar9 = lVar3;
    if (lVar3 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
      local_50 = 0x119;
    }
    goto LAB_23e323262;
  }
  *plVar9 = lVar3;
  if (lVar3 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if (iVar8 == 0) {
LAB_23e32305d:
    *(undefined4 *)(plVar5 + 5) = 0x11b;
    plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar2,_DAT_23eeb3d08);
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar9 = *(longlong **)(lVar3 + 0x28);
      plVar5 = (longlong *)plVar9[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar3 + 0x30);
      *(undefined4 *)(plVar9 + 8) = 0xffffffff;
      if (plVar5 != (longlong *)0x0) {
        plVar9[2] = 0;
        *plVar5 = *plVar5 + -1;
        if (*plVar5 == 0) {
          (**(code **)(plVar5[1] + 0x30))();
        }
      }
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      plVar9[0xf] = 0;
      pcVar7 = _Py_NoneStruct_exref;
      *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
      *plVar1 = *plVar1 + -1;
      if (*plVar1 == 0) {
        (**(code **)(plVar1[1] + 0x30))(plVar1);
      }
      *plVar2 = *plVar2 + -1;
      if (*plVar2 != 0) {
        return pcVar7;
      }
      (**(code **)(plVar2[1] + 0x30))(plVar2);
      return pcVar7;
    }
    uVar11 = *(undefined8 *)(param_1 + 0x60);
    uVar12 = *(undefined8 *)(param_1 + 0x68);
    local_50 = 0x11b;
    plVar13 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
  }
  else {
    plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeb3990);
    if (plVar9 != (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23eeb3c48);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if (plVar10 != (longlong *)0x0) {
        iVar8 = FUN_23a35f020(plVar10);
        lVar3 = *plVar10 + -1;
        if (iVar8 == -1) {
          uVar11 = *(undefined8 *)(param_1 + 0x60);
          uVar12 = *(undefined8 *)(param_1 + 0x68);
          plVar13 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *plVar10 = lVar3;
          if (lVar3 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          local_50 = 0x119;
          goto LAB_23e323262;
        }
        *plVar10 = lVar3;
        if (lVar3 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (iVar8 == 1) {
          *(undefined4 *)(plVar5 + 5) = 0x11a;
          plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar1,_DAT_23eeb3c50);
          if (plVar9 == (longlong *)0x0) {
            uVar11 = *(undefined8 *)(param_1 + 0x60);
            uVar12 = *(undefined8 *)(param_1 + 0x68);
            local_50 = 0x11a;
            plVar13 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            goto LAB_23e323262;
          }
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
        }
        goto LAB_23e32305d;
      }
    }
LAB_23e323240:
    plVar13 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    local_50 = 0x119;
    uVar11 = *(undefined8 *)(param_1 + 0x60);
    uVar12 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
LAB_23e323262:
  plVar9 = DAT_23ed6a4f8;
  if (plVar13 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar13 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar13;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar7 = _PyRuntime_exref;
    plVar9[2] = 0;
    plVar9[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar3 = *(longlong *)(pcVar7 + 0x1f8);
    *(undefined4 *)((longlong)plVar9 + 0x24) = local_50;
    lVar3 = *(longlong *)(lVar3 + 0x10);
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar3 = *(longlong *)(lVar3 + 0x2e8);
    lVar4 = plVar9[-1];
    puVar6 = *(undefined8 **)(lVar3 + 8);
    *puVar6 = plVar9 + -2;
    plVar9[-2] = lVar3;
    plVar9[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar3 + 8) = plVar9 + -2;
    plVar10 = plVar9;
  }
  else {
    plVar10 = plVar13;
    if ((longlong *)plVar13[3] != plVar5) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar10 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar10;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar7 = _PyRuntime_exref;
      plVar9[3] = (longlong)plVar5;
      *plVar5 = *plVar5 + 1;
      lVar3 = *(longlong *)(pcVar7 + 0x1f8);
      *(undefined4 *)((longlong)plVar9 + 0x24) = local_50;
      *(undefined4 *)(plVar9 + 4) = 0xffffffff;
      lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x2e8);
      lVar4 = plVar9[-1];
      puVar6 = *(undefined8 **)(lVar3 + 8);
      *puVar6 = plVar9 + -2;
      plVar9[-2] = lVar3;
      plVar9[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
      lVar4 = *plVar13;
      *(longlong **)(lVar3 + 8) = plVar9 + -2;
      plVar9[2] = (longlong)plVar13;
      plVar10 = plVar9;
      if (lVar4 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
    }
  }
  FUN_23e8bba40(plVar5,&DAT_23ec5b76c,plVar1,plVar2);
  if (_DAT_23eeb4c30 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23eeb4c30 = (longlong *)0x0;
  }
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar3 + 0x28);
  plVar5 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar3 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar5 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))();
    }
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar9[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,uVar11,uVar12,plVar10);
  return (code *)0x0;
}
