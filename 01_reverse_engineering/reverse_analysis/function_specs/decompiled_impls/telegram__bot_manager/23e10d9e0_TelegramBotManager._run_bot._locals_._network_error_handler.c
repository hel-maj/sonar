/* ===== 23e10d9e0 telegram.bot_manager:43 ===== */
/* ghidra_name=FUN_23e10d9e0 entry=23e10d9e0 size=1693 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e10d9e0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  code *pcVar7;
  int iVar8;
  longlong *plVar9;
  longlong lVar10;
  undefined4 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  longlong *plVar14;
  longlong *plVar15;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar9 = _DAT_23eeab460;
  plVar2 = (longlong *)*param_3;
  plVar3 = (longlong *)param_3[1];
  if (_DAT_23eeab460 == (longlong *)0x0) {
LAB_23e10da1e:
    _DAT_23eeab460 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeab458,DAT_23eeab470,0x10);
  }
  else {
    lVar4 = *_DAT_23eeab460;
    if (1 < lVar4) {
      *_DAT_23eeab460 = lVar4 + -1;
      goto LAB_23e10da1e;
    }
    if (_DAT_23eeab460[2] != 0) {
      *_DAT_23eeab460 = lVar4 + -1;
      if (lVar4 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e10da1e;
    }
  }
  plVar5 = _DAT_23eeab460;
  lVar4 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eeab460 + 9;
  lVar10 = *(longlong *)(lVar4 + 8);
  _DAT_23eeab460[0xf] = lVar10;
  *(longlong **)(lVar4 + 8) = plVar9;
  if ((lVar10 != 0) &&
     (((*(char *)(lVar10 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar10 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar10 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar10 + 0x38))) && (plVar5[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar10 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  uVar12 = _DAT_23eea98b0;
  *(undefined4 *)(plVar5 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar2,uVar12);
  if (plVar9 == (longlong *)0x0) {
    uVar12 = *(undefined8 *)(param_1 + 0x60);
    uVar13 = *(undefined8 *)(param_1 + 0x68);
    uVar11 = 0x2d;
    plVar14 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23e10dd00;
  }
  iVar8 = FUN_23a35f020(plVar9);
  lVar4 = *plVar9 + -1;
  if (iVar8 == -1) {
    uVar12 = *(undefined8 *)(param_1 + 0x60);
    uVar13 = *(undefined8 *)(param_1 + 0x68);
    uVar11 = 0x2d;
    plVar14 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar9 = lVar4;
    if (lVar4 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
      uVar11 = 0x2d;
    }
    goto LAB_23e10dd00;
  }
  *plVar9 = lVar4;
  if (lVar4 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if (iVar8 != 0) {
    *(undefined4 *)(plVar5 + 5) = 0x2e;
    plVar9 = (longlong *)FUN_23e915840(param_1,plVar2,_DAT_23eea98b0,plVar3);
    if (plVar9 == (longlong *)0x0) {
      uVar12 = *(undefined8 *)(param_1 + 0x60);
      uVar13 = *(undefined8 *)(param_1 + 0x68);
      uVar11 = 0x2e;
      plVar14 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      goto LAB_23e10dd00;
    }
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
  }
  lVar4 = *(longlong *)(DAT_23eea9890 + 0x20);
  if (*(char *)(lVar4 + 10) == '\0') {
    plVar9 = (longlong *)FUN_23a37a020(DAT_23eea9890,_DAT_23eea98e0);
    if (plVar9 == (longlong *)0x0) goto LAB_23e10dca1;
    lVar10 = *plVar9;
LAB_23e10e018:
    if (lVar10 == 0) goto LAB_23e10dca1;
  }
  else {
    iVar8 = *(int *)(lVar4 + 0xc);
    if (*(int *)(lVar4 + 0xc) == 0) {
      *(int *)(lVar4 + 0xc) = DAT_23ec14cd8;
      iVar8 = DAT_23ec14cd8;
      DAT_23ec14cd8 = DAT_23ec14cd8 + 1;
    }
    if (_DAT_23ec14cdc != iVar8) {
      _DAT_23ec14cdc = iVar8;
      _DAT_23eeab450 = FUN_23e8cbd60(lVar4,_DAT_23eea98e0,*(undefined8 *)(_DAT_23eea98e0 + 0x18));
    }
    if (-1 < _DAT_23eeab450) {
      lVar1 = lVar4 + 0x20 + (1L << (*(byte *)(lVar4 + 9) & 0x3f));
      lVar10 = *(longlong *)(lVar1 + 8 + _DAT_23eeab450 * 0x10);
      if (lVar10 != 0) goto LAB_23e10db5a;
      _DAT_23eeab450 = FUN_23e8cbd60(lVar4,_DAT_23eea98e0,*(undefined8 *)(_DAT_23eea98e0 + 0x18));
      if (-1 < _DAT_23eeab450) {
        lVar10 = *(longlong *)(lVar1 + 8 + _DAT_23eeab450 * 0x10);
        goto LAB_23e10e018;
      }
    }
LAB_23e10dca1:
    plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eea98e0);
    if ((plVar9 == (longlong *)0x0) || (lVar10 = *plVar9, lVar10 == 0)) {
      FUN_23e915740(param_1,&uStack_68,_DAT_23eea98e0);
      uVar11 = 0x2f;
      uVar12 = uStack_68;
      uVar13 = uStack_60;
      plVar14 = plStack_58;
      goto LAB_23e10dd00;
    }
  }
LAB_23e10db5a:
  *(undefined4 *)(plVar5 + 5) = 0x2f;
  plVar9 = (longlong *)FUN_23e915840(param_1,lVar10,_DAT_23eea98e8,plVar3);
  if (plVar9 != (longlong *)0x0) {
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar9 = *(longlong **)(lVar4 + 0x28);
    plVar5 = (longlong *)plVar9[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar4 + 0x30);
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
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    *plVar3 = *plVar3 + -1;
    if (*plVar3 != 0) {
      return pcVar7;
    }
    (**(code **)(plVar3[1] + 0x30))(plVar3);
    return pcVar7;
  }
  uVar12 = *(undefined8 *)(param_1 + 0x60);
  uVar11 = 0x2f;
  plVar14 = *(longlong **)(param_1 + 0x70);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar13 = *(undefined8 *)(param_1 + 0x68);
LAB_23e10dd00:
  plVar9 = DAT_23ed6a4f8;
  if (plVar14 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar14 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar14;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar7 = _PyRuntime_exref;
    plVar9[2] = 0;
    plVar9[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar4 = *(longlong *)(pcVar7 + 0x1f8);
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar11;
    lVar4 = *(longlong *)(lVar4 + 0x10);
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar4 = *(longlong *)(lVar4 + 0x2e8);
    lVar10 = plVar9[-1];
    puVar6 = *(undefined8 **)(lVar4 + 8);
    *puVar6 = plVar9 + -2;
    plVar9[-2] = lVar4;
    plVar9[-1] = (ulonglong)((uint)lVar10 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar4 + 8) = plVar9 + -2;
    plVar15 = plVar9;
  }
  else {
    plVar15 = plVar14;
    if ((longlong *)plVar14[3] != plVar5) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar15 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar15;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar7 = _PyRuntime_exref;
      plVar9[3] = (longlong)plVar5;
      *plVar5 = *plVar5 + 1;
      lVar4 = *(longlong *)(pcVar7 + 0x1f8);
      *(undefined4 *)((longlong)plVar9 + 0x24) = uVar11;
      *(undefined4 *)(plVar9 + 4) = 0xffffffff;
      lVar4 = *(longlong *)(*(longlong *)(lVar4 + 0x10) + 0x2e8);
      lVar10 = plVar9[-1];
      puVar6 = *(undefined8 **)(lVar4 + 8);
      *puVar6 = plVar9 + -2;
      plVar9[-2] = lVar4;
      plVar9[-1] = (ulonglong)((uint)lVar10 & 3) | (ulonglong)puVar6;
      lVar10 = *plVar14;
      *(longlong **)(lVar4 + 8) = plVar9 + -2;
      plVar9[2] = (longlong)plVar14;
      plVar15 = plVar9;
      if (lVar10 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
    }
  }
  FUN_23e8bba40(plVar5,&DAT_23ec5a08f,plVar2,plVar3);
  if (_DAT_23eeab460 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23eeab460 = (longlong *)0x0;
  }
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar4 + 0x28);
  plVar5 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar4 + 0x30);
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
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  FUN_23a33aa70(param_1,uVar12,uVar13,plVar15);
  return (code *)0x0;
}
