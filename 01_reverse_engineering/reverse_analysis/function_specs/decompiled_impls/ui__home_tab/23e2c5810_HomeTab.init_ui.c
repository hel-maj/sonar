/* ===== 23e2c5810 ui.home_tab:264 ===== */
/* ghidra_name=FUN_23e2c5810 entry=23e2c5810 size=1405 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_23e2c5810(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined8 *puVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  undefined4 uVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  longlong *plVar13;
  undefined8 *puStack_78;
  undefined8 *puStack_70;
  longlong *plStack_68;
  
  plVar9 = _DAT_23eeb0308;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eeb0308 == (longlong *)0x0) {
LAB_23e2c584f:
    _DAT_23eeb0308 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeb0300,DAT_23eeb0380,8);
  }
  else {
    lVar7 = *_DAT_23eeb0308;
    if (1 < lVar7) {
      *_DAT_23eeb0308 = lVar7 + -1;
      goto LAB_23e2c584f;
    }
    if (_DAT_23eeb0308[2] != 0) {
      *_DAT_23eeb0308 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e2c584f;
    }
  }
  plVar4 = _DAT_23eeb0308;
  lVar7 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eeb0308 + 9;
  lVar2 = *(longlong *)(lVar7 + 8);
  _DAT_23eeb0308[0xf] = lVar2;
  *(longlong **)(lVar7 + 8) = plVar9;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  lVar7 = *(longlong *)(param_1 + 0x10);
  *plVar4 = *plVar4 + 1;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar8 = _DAT_23eeadcc8;
  plVar9 = *(longlong **)(lVar7 + 0xe28);
  if (plVar9 == (longlong *)0x0) {
    plVar9 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
  }
  else {
    lVar2 = plVar9[3];
    *(int *)(lVar7 + 0xec0) = *(int *)(lVar7 + 0xec0) + -1;
    *(longlong *)(lVar7 + 0xe28) = lVar2;
    *plVar9 = 1;
  }
  pcVar5 = _PyRuntime_exref;
  *(undefined1 (*) [16])(plVar9 + 4) = (undefined1  [16])0x0;
  lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
  lVar2 = plVar9[-1];
  puVar3 = *(undefined8 **)(lVar7 + 8);
  *puVar3 = plVar9 + -2;
  plVar9[-2] = lVar7;
  plVar9[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
  *(longlong **)(lVar7 + 8) = plVar9 + -2;
  *plVar8 = *plVar8 + 1;
  plVar9[3] = (longlong)plVar8;
  puVar6 = (undefined8 *)FUN_23e8f7250();
  puVar3 = DAT_23ed6cd28;
  if (puVar6 == (undefined8 *)0x0) {
    FUN_23e915740(param_1,&puStack_78,DAT_23eeadad0);
    puVar11 = puStack_78;
    puVar12 = puStack_70;
    plVar8 = plStack_68;
LAB_23e2c5acc:
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    uVar10 = 0x10d;
LAB_23e2c5b09:
    plVar9 = DAT_23ed6a4f8;
    if (plVar8 != (longlong *)0x0) {
      plVar13 = plVar8;
      if ((longlong *)plVar8[3] != plVar4) {
        if (DAT_23ed6a4f8 == (longlong *)0x0) {
          plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          plVar13 = (longlong *)*DAT_23ed6a4f8;
          *DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = plVar13;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        plVar9[3] = (longlong)plVar4;
        *plVar4 = *plVar4 + 1;
        lVar7 = *(longlong *)(pcVar5 + 0x1f8);
        *(undefined4 *)((longlong)plVar9 + 0x24) = uVar10;
        lVar7 = *(longlong *)(lVar7 + 0x10);
        *(undefined4 *)(plVar9 + 4) = 0xffffffff;
        lVar7 = *(longlong *)(lVar7 + 0x2e8);
        lVar2 = plVar9[-1];
        puVar3 = *(undefined8 **)(lVar7 + 8);
        *puVar3 = plVar9 + -2;
        plVar9[-2] = lVar7;
        plVar9[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
        lVar2 = *plVar8;
        *(longlong **)(lVar7 + 8) = plVar9 + -2;
        plVar9[2] = (longlong)plVar8;
        plVar13 = plVar9;
        if (lVar2 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
      }
      goto LAB_23e2c5bad;
    }
    if (DAT_23ed6a4f8 == (longlong *)0x0) goto LAB_23e2c5da8;
    plVar8 = (longlong *)*DAT_23ed6a4f8;
    *DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = plVar8;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  else {
    puVar12 = &DAT_23ed6a4c0;
    puVar11 = &DAT_23ed6cce0;
    if (DAT_23ed6a4c0 != (longlong *)0x0) {
LAB_23e2c598e:
      puStack_70 = puVar3;
      puStack_78 = puVar6;
      lVar7 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&puStack_78);
      if (lVar7 == 0) {
        plVar8 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        puVar11 = *(undefined8 **)(param_1 + 0x60);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        puVar12 = *(undefined8 **)(param_1 + 0x68);
        goto LAB_23e2c5acc;
      }
      plVar9[4] = lVar7;
      plVar8 = _DAT_23eeadcd0;
      *_DAT_23eeadcd0 = *_DAT_23eeadcd0 + 1;
      plVar9[5] = (longlong)plVar8;
      lVar7 = PyUnicode_Join(DAT_23ed6cd28,plVar9);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if (lVar7 != 0) {
        lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar9 = *(longlong **)(lVar2 + 0x28);
        plVar4 = (longlong *)plVar9[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
        *(undefined4 *)(plVar9 + 8) = 0xffffffff;
        if (plVar4 != (longlong *)0x0) {
          plVar9[2] = 0;
          *plVar4 = *plVar4 + -1;
          if (*plVar4 == 0) {
            (**(code **)(plVar4[1] + 0x30))();
          }
        }
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        plVar9[0xf] = 0;
        *plVar1 = *plVar1 + -1;
        if (*plVar1 != 0) {
          return lVar7;
        }
        (**(code **)(plVar1[1] + 0x30))(plVar1);
        return lVar7;
      }
      plVar8 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar10 = 0x10a;
      puVar11 = *(undefined8 **)(param_1 + 0x60);
      puVar12 = *(undefined8 **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e2c5b09;
    }
    plVar8 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
      DAT_23ed6a4c0 = plVar8;
      goto LAB_23e2c598e;
    }
    PyErr_PrintEx(0);
    uVar10 = SUB84(plVar8,0);
    Py_Exit(1);
LAB_23e2c5da8:
    plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  plVar9[2] = 0;
  plVar9[3] = (longlong)plVar4;
  *plVar4 = *plVar4 + 1;
  lVar7 = *(longlong *)(pcVar5 + 0x1f8);
  *(undefined4 *)((longlong)plVar9 + 0x24) = uVar10;
  lVar7 = *(longlong *)(lVar7 + 0x10);
  *(undefined4 *)(plVar9 + 4) = 0xffffffff;
  lVar7 = *(longlong *)(lVar7 + 0x2e8);
  lVar2 = plVar9[-1];
  puVar3 = *(undefined8 **)(lVar7 + 8);
  *puVar3 = plVar9 + -2;
  plVar9[-2] = lVar7;
  plVar9[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
  *(longlong **)(lVar7 + 8) = plVar9 + -2;
  plVar13 = plVar9;
LAB_23e2c5bad:
  FUN_23e8bba40(plVar4,&DAT_23ec5b149,plVar1);
  if (_DAT_23eeb0308 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eeb0308 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar7 + 0x28);
  plVar4 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
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
  FUN_23a33aa70(param_1,puVar11,puVar12,plVar13);
  return 0;
}
