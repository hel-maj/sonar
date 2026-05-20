/* ===== 23e80db10 workers.fishing.memory_reeling:MemoryReelingTracker._i32 ===== */
/* ghidra_name=FUN_23e80db10 entry=23e80db10 size=1186 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e80db10(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  int iVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong lVar8;
  longlong *plVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  
  plVar6 = _DAT_23eede8a8;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eede8a8 == (longlong *)0x0) {
LAB_23e80db48:
    _DAT_23eede8a8 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedd100,DAT_23eedd0f8,8);
  }
  else {
    lVar8 = *_DAT_23eede8a8;
    if (1 < lVar8) {
      *_DAT_23eede8a8 = lVar8 + -1;
      goto LAB_23e80db48;
    }
    if (_DAT_23eede8a8[2] != 0) {
      *_DAT_23eede8a8 = lVar8 + -1;
      if (lVar8 + -1 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      goto LAB_23e80db48;
    }
  }
  plVar3 = _DAT_23eede8a8;
  lVar8 = *(longlong *)(param_1 + 0x38);
  plVar6 = _DAT_23eede8a8 + 9;
  lVar2 = *(longlong *)(lVar8 + 8);
  _DAT_23eede8a8[0xf] = lVar2;
  *(longlong **)(lVar8 + 8) = plVar6;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar6 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar6;
    if (plVar6 != (longlong *)0x0) {
      *plVar6 = *plVar6 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar10 = _DAT_23eedd400;
  *(undefined4 *)(plVar3 + 8) = 0;
  *plVar1 = *plVar1 + 1;
  plVar6 = (longlong *)FUN_23e8d0dd0(uVar10,plVar1);
  if (plVar6 == (longlong *)0x0) {
    uVar10 = *(undefined8 *)(param_1 + 0x60);
    uVar11 = *(undefined8 *)(param_1 + 0x68);
    plVar7 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar1 = *plVar1 + -1;
    if (*plVar1 == 0) {
      (**(code **)(plVar1[1] + 0x30))(plVar1);
    }
  }
  else {
    iVar5 = FUN_23a35f020(plVar6);
    if (iVar5 == -1) {
      uVar10 = *(undefined8 *)(param_1 + 0x60);
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      plVar7 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar1 = *plVar1 + -1;
      lVar8 = *plVar1;
    }
    else {
      if (iVar5 == 0) {
        *plVar6 = *plVar6 + 1;
        plVar7 = plVar6;
LAB_23e80dc0a:
        *plVar1 = *plVar1 + -1;
        if (*plVar1 == 0) {
          (**(code **)(plVar1[1] + 0x30))(plVar1);
        }
        *plVar6 = *plVar6 + -1;
        if (*plVar6 == 0) {
          (**(code **)(plVar6[1] + 0x30))(plVar6);
        }
        lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar6 = *(longlong **)(lVar8 + 0x28);
        plVar3 = (longlong *)plVar6[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar8 + 0x30);
        *(undefined4 *)(plVar6 + 8) = 0xffffffff;
        if (plVar3 != (longlong *)0x0) {
          plVar6[2] = 0;
          *plVar3 = *plVar3 + -1;
          if (*plVar3 == 0) {
            (**(code **)(plVar3[1] + 0x30))();
          }
        }
        *plVar6 = *plVar6 + -1;
        if (*plVar6 == 0) {
          (**(code **)(plVar6[1] + 0x30))(plVar6);
        }
        plVar6[0xf] = 0;
        *plVar1 = *plVar1 + -1;
        if (*plVar1 != 0) {
          return plVar7;
        }
        (**(code **)(plVar1[1] + 0x30))(plVar1);
        return plVar7;
      }
      plVar7 = (longlong *)FUN_23e8d0b80(plVar1,_DAT_23eedd408);
      if (plVar7 != (longlong *)0x0) goto LAB_23e80dc0a;
      lVar8 = *plVar1;
      uVar10 = *(undefined8 *)(param_1 + 0x60);
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      plVar7 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      lVar8 = lVar8 + -1;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar1 = lVar8;
    }
    if (lVar8 == 0) {
      (**(code **)(plVar1[1] + 0x30))(plVar1);
    }
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
  }
  plVar6 = DAT_23ed6a4f8;
  if (plVar7 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar6 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar7 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar7;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar6[3] = (longlong)plVar3;
    plVar6[2] = 0;
    *plVar3 = *plVar3 + 1;
    plVar6[4] = 0x128ffffffff;
    lVar8 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
    lVar2 = plVar6[-1];
    puVar4 = *(undefined8 **)(lVar8 + 8);
    *puVar4 = plVar6 + -2;
    plVar6[-2] = lVar8;
    plVar6[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar8 + 8) = plVar6 + -2;
    plVar9 = plVar6;
  }
  else {
    plVar9 = plVar7;
    if ((longlong *)plVar7[3] != plVar3) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar6 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar9 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar9;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar6[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      plVar6[4] = 0x128ffffffff;
      lVar8 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar2 = plVar6[-1];
      puVar4 = *(undefined8 **)(lVar8 + 8);
      *puVar4 = plVar6 + -2;
      plVar6[-2] = lVar8;
      plVar6[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
      lVar2 = *plVar7;
      *(longlong **)(lVar8 + 8) = plVar6 + -2;
      plVar6[2] = (longlong)plVar7;
      plVar9 = plVar6;
      if (lVar2 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
    }
  }
  FUN_23e8bba40(plVar3,&DAT_23ec5e2bc,plVar1);
  if (_DAT_23eede8a8 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eede8a8 = (longlong *)0x0;
  }
  lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar6 = *(longlong **)(lVar8 + 0x28);
  plVar3 = (longlong *)plVar6[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar8 + 0x30);
  *(undefined4 *)(plVar6 + 8) = 0xffffffff;
  if (plVar3 != (longlong *)0x0) {
    plVar6[2] = 0;
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))();
    }
  }
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  plVar6[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar10,uVar11,plVar9);
  return (longlong *)0x0;
}
