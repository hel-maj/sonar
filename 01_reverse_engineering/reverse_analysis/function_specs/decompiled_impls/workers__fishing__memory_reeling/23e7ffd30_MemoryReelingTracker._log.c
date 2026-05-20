/* ===== 23e7ffd30 workers.fishing.memory_reeling:MemoryReelingTracker._log ===== */
/* ghidra_name=FUN_23e7ffd30 entry=23e7ffd30 size=1241 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e7ffd30(longlong param_1,undefined8 param_2,undefined8 *param_3)

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
  undefined4 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  longlong *plVar13;
  longlong *plVar14;
  
  plVar9 = _DAT_23eede938;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eede938 == (longlong *)0x0) {
LAB_23e7ffd6e:
    _DAT_23eede938 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede9a0,DAT_23eedd0f8,0x10);
  }
  else {
    lVar3 = *_DAT_23eede938;
    if (1 < lVar3) {
      *_DAT_23eede938 = lVar3 + -1;
      goto LAB_23e7ffd6e;
    }
    if (_DAT_23eede938[2] != 0) {
      *_DAT_23eede938 = lVar3 + -1;
      if (lVar3 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e7ffd6e;
    }
  }
  plVar5 = _DAT_23eede938;
  lVar3 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eede938 + 9;
  lVar4 = *(longlong *)(lVar3 + 8);
  _DAT_23eede938[0xf] = lVar4;
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
  uVar11 = _DAT_23eedd128;
  *(undefined4 *)(plVar5 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,uVar11);
  if (plVar9 == (longlong *)0x0) {
    plVar13 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar10 = 0x7b;
    uVar11 = *(undefined8 *)(param_1 + 0x60);
    uVar12 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  else {
    iVar8 = FUN_23a35f020(plVar9);
    lVar3 = *plVar9 + -1;
    if (iVar8 != -1) {
      *plVar9 = lVar3;
      if (lVar3 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if (iVar8 != 0) {
        *(undefined4 *)(plVar5 + 5) = 0x7c;
        plVar9 = (longlong *)FUN_23e915840(param_1,plVar1,_DAT_23eedd128,plVar2);
        if (plVar9 == (longlong *)0x0) {
          uVar11 = *(undefined8 *)(param_1 + 0x60);
          uVar12 = *(undefined8 *)(param_1 + 0x68);
          uVar10 = 0x7c;
          plVar13 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          goto LAB_23e7fff81;
        }
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
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
    plVar13 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar9 = lVar3;
    if (lVar3 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    uVar10 = 0x7b;
  }
LAB_23e7fff81:
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
    plVar14 = plVar9;
  }
  else {
    plVar14 = plVar13;
    if ((longlong *)plVar13[3] != plVar5) {
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
      plVar9[3] = (longlong)plVar5;
      *plVar5 = *plVar5 + 1;
      lVar3 = *(longlong *)(pcVar7 + 0x1f8);
      *(undefined4 *)((longlong)plVar9 + 0x24) = uVar10;
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
      plVar14 = plVar9;
      if (lVar4 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
    }
  }
  FUN_23e8bba40(plVar5,&DAT_23ec5e407,plVar1,plVar2);
  if (_DAT_23eede938 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23eede938 = (longlong *)0x0;
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
  FUN_23a33aa70(param_1,uVar11,uVar12,plVar14);
  return (code *)0x0;
}
