/* ===== 23e7dd5d0 workers.fishing.meal_system:484 ===== */
/* ghidra_name=FUN_23e7dd5d0 entry=23e7dd5d0 size=1573 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e7dd5d0(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  code *pcVar5;
  int iVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong *unaff_RSI;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined4 uVar12;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar7 = _DAT_23eedec08;
  if (_DAT_23eedec08 == (longlong *)0x0) {
LAB_23e7dd607:
    _DAT_23eedec08 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedec00,DAT_23eed7940,8);
  }
  else {
    lVar9 = *_DAT_23eedec08;
    if (1 < lVar9) {
      *_DAT_23eedec08 = lVar9 + -1;
      goto LAB_23e7dd607;
    }
    if (_DAT_23eedec08[2] != 0) {
      *_DAT_23eedec08 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23e7dd607;
    }
  }
  plVar2 = _DAT_23eedec08;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar7 = _DAT_23eedec08 + 9;
  lVar1 = *(longlong *)(lVar9 + 8);
  _DAT_23eedec08[0xf] = lVar1;
  *(longlong **)(lVar9 + 8) = plVar7;
  if ((lVar1 != 0) &&
     (((*(char *)(lVar1 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar1 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar1 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar1 + 0x38))
       ) && (plVar2[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar1 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  *(undefined4 *)(plVar2 + 8) = 0;
  plVar7 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23ed6cf28);
  if ((plVar7 == (longlong *)0x0) || (lVar9 = *plVar7, lVar9 == 0)) {
    PyErr_PrintEx(0);
    Py_Exit(1);
  }
  else {
    *(undefined4 *)(plVar2 + 5) = 0x1e6;
    plVar7 = (longlong *)FUN_23e94bb80(param_1,lVar9,uRam000000023eed76c8);
    if (plVar7 == (longlong *)0x0) {
      uVar10 = *(undefined8 *)(param_1 + 0x60);
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      uVar12 = 0x1e6;
      plVar7 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      unaff_RSI = (longlong *)0x0;
      goto LAB_23e7dd8b8;
    }
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    lVar9 = *(longlong *)(_DAT_23eede1c0 + 0x20);
    if (*(char *)(lVar9 + 10) == '\0') {
      plVar7 = (longlong *)FUN_23a37a020(_DAT_23eede1c0,lRam000000023eed76d0);
      if (plVar7 == (longlong *)0x0) goto LAB_23e7dd86a;
      lVar9 = *plVar7;
LAB_23e7ddaf9:
      if (lVar9 == 0) goto LAB_23e7dd86a;
    }
    else {
      iVar6 = *(int *)(lVar9 + 0xc);
      if (*(int *)(lVar9 + 0xc) == 0) {
        *(int *)(lVar9 + 0xc) = _DAT_23ec15654;
        iVar6 = _DAT_23ec15654;
        _DAT_23ec15654 = _DAT_23ec15654 + 1;
      }
      if (_DAT_23ec15620 != iVar6) {
        _DAT_23ec15620 = iVar6;
        _DAT_23eedebf8 =
             FUN_23e8cbd60(lVar9,lRam000000023eed76d0,*(undefined8 *)(lRam000000023eed76d0 + 0x18));
      }
      if (-1 < _DAT_23eedebf8) {
        lVar1 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
        if (*(longlong *)(lVar1 + 8 + _DAT_23eedebf8 * 0x10) != 0) goto LAB_23e7dd761;
        _DAT_23eedebf8 =
             FUN_23e8cbd60(lVar9,lRam000000023eed76d0,*(undefined8 *)(lRam000000023eed76d0 + 0x18));
        if (-1 < _DAT_23eedebf8) {
          lVar9 = *(longlong *)(lVar1 + 8 + _DAT_23eedebf8 * 0x10);
          goto LAB_23e7ddaf9;
        }
      }
LAB_23e7dd86a:
      plVar7 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,lRam000000023eed76d0);
      if ((plVar7 == (longlong *)0x0) || (*plVar7 == 0)) {
        uVar12 = 0x1ec;
        unaff_RSI = (longlong *)0x0;
        FUN_23e915740(param_1,&uStack_68,lRam000000023eed76d0);
        plVar7 = plStack_58;
        uVar10 = uStack_68;
        uVar11 = uStack_60;
        goto LAB_23e7dd8b8;
      }
    }
LAB_23e7dd761:
    *(undefined4 *)(plVar2 + 5) = 0x1ec;
    unaff_RSI = (longlong *)FUN_23e91a870(param_1);
    if (unaff_RSI != (longlong *)0x0) {
      *(undefined4 *)(plVar2 + 5) = 0x1ed;
      plVar7 = (longlong *)FUN_23e91bfe0(param_1,unaff_RSI,uRam000000023eed76d8);
      if (plVar7 != (longlong *)0x0) {
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar7 = *(longlong **)(lVar9 + 0x28);
        plVar2 = (longlong *)plVar7[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
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
        pcVar5 = _Py_NoneStruct_exref;
        *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
        *unaff_RSI = *unaff_RSI + -1;
        if (*unaff_RSI != 0) {
          return pcVar5;
        }
        (**(code **)(unaff_RSI[1] + 0x30))(unaff_RSI);
        return pcVar5;
      }
      uVar10 = *(undefined8 *)(param_1 + 0x60);
      uVar12 = 0x1ed;
      plVar7 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e7dd8b8;
    }
  }
  uVar10 = *(undefined8 *)(param_1 + 0x60);
  uVar12 = 0x1ec;
  plVar7 = *(longlong **)(param_1 + 0x70);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar11 = *(undefined8 *)(param_1 + 0x68);
LAB_23e7dd8b8:
  plVar4 = DAT_23ed6a4f8;
  if (plVar7 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar7 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar7;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar8 = plVar4;
    }
    pcVar5 = _PyRuntime_exref;
    plVar8[2] = 0;
    plVar8[3] = (longlong)plVar2;
    *plVar2 = *plVar2 + 1;
    lVar9 = *(longlong *)(pcVar5 + 0x1f8);
    *(undefined4 *)(plVar8 + 4) = 0xffffffff;
    lVar9 = *(longlong *)(lVar9 + 0x10);
    *(undefined4 *)((longlong)plVar8 + 0x24) = uVar12;
    lVar9 = *(longlong *)(lVar9 + 0x2e8);
    lVar1 = plVar8[-1];
    puVar3 = *(undefined8 **)(lVar9 + 8);
    *puVar3 = plVar8 + -2;
    plVar8[-2] = lVar9;
    plVar8[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar9 + 8) = plVar8 + -2;
  }
  else {
    plVar8 = plVar7;
    if ((longlong *)plVar7[3] != plVar2) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar8 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar8;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar8 = plVar4;
      }
      pcVar5 = _PyRuntime_exref;
      plVar8[3] = (longlong)plVar2;
      *plVar2 = *plVar2 + 1;
      lVar9 = *(longlong *)(pcVar5 + 0x1f8);
      *(undefined4 *)((longlong)plVar8 + 0x24) = uVar12;
      *(undefined4 *)(plVar8 + 4) = 0xffffffff;
      lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
      lVar1 = plVar8[-1];
      puVar3 = *(undefined8 **)(lVar9 + 8);
      *puVar3 = plVar8 + -2;
      plVar8[-2] = lVar9;
      plVar8[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
      lVar1 = *plVar7;
      *(longlong **)(lVar9 + 8) = plVar8 + -2;
      plVar8[2] = (longlong)plVar7;
      if (lVar1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
    }
  }
  FUN_23e8bba40(plVar2,&DAT_23ec5e2bc,unaff_RSI);
  if (_DAT_23eedec08 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    _DAT_23eedec08 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar7 = *(longlong **)(lVar9 + 0x28);
  plVar2 = (longlong *)plVar7[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
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
  if ((unaff_RSI != (longlong *)0x0) && (*unaff_RSI = *unaff_RSI + -1, *unaff_RSI == 0)) {
    (**(code **)(unaff_RSI[1] + 0x30))(unaff_RSI);
  }
  FUN_23a33aa70(param_1,uVar10,uVar11,plVar8);
  return (code *)0x0;
}
