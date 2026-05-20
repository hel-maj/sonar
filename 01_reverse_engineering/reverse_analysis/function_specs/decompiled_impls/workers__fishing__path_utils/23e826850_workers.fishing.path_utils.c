/* ===== 23e826850 workers.fishing.path_utils:c266 ===== */
/* ghidra_name=FUN_23e826850 entry=23e826850 size=1017 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_23e826850(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  longlong *plVar9;
  undefined8 uStack_58;
  undefined8 uStack_50;
  longlong *plStack_48;
  
  plVar5 = _DAT_23eede760;
  if (_DAT_23eede760 != (longlong *)0x0) {
    lVar4 = *_DAT_23eede760;
    if (lVar4 < 2) {
      if (_DAT_23eede760[2] == 0) goto LAB_23e8268a6;
      *_DAT_23eede760 = lVar4 + -1;
      if (lVar4 + -1 == 0) {
        (**(code **)(plVar5[1] + 0x30))(plVar5);
      }
    }
    else {
      *_DAT_23eede760 = lVar4 + -1;
    }
  }
  _DAT_23eede760 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eede758,DAT_23eede778,0);
LAB_23e8268a6:
  plVar2 = _DAT_23eede760;
  lVar4 = *(longlong *)(param_1 + 0x38);
  plVar5 = _DAT_23eede760 + 9;
  lVar1 = *(longlong *)(lVar4 + 8);
  _DAT_23eede760[0xf] = lVar1;
  *(longlong **)(lVar4 + 8) = plVar5;
  if ((lVar1 != 0) &&
     (((*(char *)(lVar1 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar1 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar1 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar1 + 0x38))
       ) && (plVar2[0xe] != 0)))) {
    plVar5 = *(longlong **)(lVar1 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar5;
    if (plVar5 != (longlong *)0x0) {
      *plVar5 = *plVar5 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  *(undefined4 *)(plVar2 + 8) = 0;
  lVar4 = FUN_23e8dc1d0();
  if (lVar4 == 0) {
    FUN_23e915740(param_1,&uStack_58,DAT_23eedd020);
    uVar7 = uStack_58;
    uVar8 = uStack_50;
    plVar5 = plStack_48;
  }
  else {
    *(undefined4 *)(plVar2 + 5) = 0x2f;
    plVar5 = (longlong *)FUN_23e91a870(param_1,lVar4);
    if (plVar5 != (longlong *)0x0) {
      lVar4 = FUN_23e8c6f80(plVar5,_DAT_23eedd028);
      *plVar5 = *plVar5 + -1;
      if (*plVar5 == 0) {
        (**(code **)(plVar5[1] + 0x30))(plVar5);
      }
      if (lVar4 != 0) {
        lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar5 = *(longlong **)(lVar1 + 0x28);
        plVar2 = (longlong *)plVar5[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar1 + 0x30);
        *(undefined4 *)(plVar5 + 8) = 0xffffffff;
        if (plVar2 != (longlong *)0x0) {
          plVar5[2] = 0;
          *plVar2 = *plVar2 + -1;
          if (*plVar2 == 0) {
            (**(code **)(plVar2[1] + 0x30))();
          }
        }
        *plVar5 = *plVar5 + -1;
        if (*plVar5 == 0) {
          (**(code **)(plVar5[1] + 0x30))(plVar5);
        }
        plVar5[0xf] = 0;
        return lVar4;
      }
    }
    plVar5 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar7 = *(undefined8 *)(param_1 + 0x60);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar8 = *(undefined8 *)(param_1 + 0x68);
  }
  plVar6 = DAT_23ed6a4f8;
  if (plVar5 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar6 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar5 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar5;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar6[2] = 0;
    plVar6[3] = (longlong)plVar2;
    *plVar2 = *plVar2 + 1;
    plVar6[4] = 0x2fffffffff;
    lVar4 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
    lVar1 = plVar6[-1];
    puVar3 = *(undefined8 **)(lVar4 + 8);
    *puVar3 = plVar6 + -2;
    plVar6[-2] = lVar4;
    plVar6[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar4 + 8) = plVar6 + -2;
    plVar9 = plVar6;
  }
  else {
    plVar9 = plVar5;
    if ((longlong *)plVar5[3] != plVar2) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar6 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar9 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar9;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar6[3] = (longlong)plVar2;
      *plVar2 = *plVar2 + 1;
      plVar6[4] = 0x2fffffffff;
      lVar4 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar1 = plVar6[-1];
      puVar3 = *(undefined8 **)(lVar4 + 8);
      *puVar3 = plVar6 + -2;
      plVar6[-2] = lVar4;
      plVar6[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
      lVar1 = *plVar5;
      *(longlong **)(lVar4 + 8) = plVar6 + -2;
      plVar6[2] = (longlong)plVar5;
      plVar9 = plVar6;
      if (lVar1 == 0) {
        (**(code **)(plVar5[1] + 0x30))(plVar5);
      }
    }
  }
  FUN_23e8bba40(plVar2,0);
  if (_DAT_23eede760 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    _DAT_23eede760 = (longlong *)0x0;
  }
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar5 = *(longlong **)(lVar4 + 0x28);
  plVar2 = (longlong *)plVar5[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar4 + 0x30);
  *(undefined4 *)(plVar5 + 8) = 0xffffffff;
  if (plVar2 != (longlong *)0x0) {
    plVar5[2] = 0;
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))();
    }
  }
  *plVar5 = *plVar5 + -1;
  if (*plVar5 == 0) {
    (**(code **)(plVar5[1] + 0x30))(plVar5);
  }
  plVar5[0xf] = 0;
  FUN_23a33aa70(param_1,uVar7,uVar8,plVar9);
  return 0;
}
