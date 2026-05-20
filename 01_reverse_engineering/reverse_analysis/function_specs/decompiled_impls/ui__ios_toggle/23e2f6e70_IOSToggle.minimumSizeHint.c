/* ===== 23e2f6e70 ui.ios_toggle:92 ===== */
/* ghidra_name=FUN_23e2f6e70 entry=23e2f6e70 size=1175 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_23e2f6e70(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plStack_58;
  longlong *plStack_50;
  longlong *plStack_48;
  
  plVar7 = _DAT_23eeafff0;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eeafff0 == (longlong *)0x0) {
LAB_23e2f6ea8:
    _DAT_23eeafff0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeaffe8,DAT_23eeb0078,8);
  }
  else {
    lVar5 = *_DAT_23eeafff0;
    if (1 < lVar5) {
      *_DAT_23eeafff0 = lVar5 + -1;
      goto LAB_23e2f6ea8;
    }
    if (_DAT_23eeafff0[2] != 0) {
      *_DAT_23eeafff0 = lVar5 + -1;
      if (lVar5 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23e2f6ea8;
    }
  }
  plVar3 = _DAT_23eeafff0;
  lVar5 = *(longlong *)(param_1 + 0x38);
  plVar7 = _DAT_23eeafff0 + 9;
  lVar2 = *(longlong *)(lVar5 + 8);
  _DAT_23eeafff0[0xf] = lVar2;
  *(longlong **)(lVar5 + 8) = plVar7;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  lVar5 = FUN_23e8f5c20();
  if (lVar5 == 0) {
    FUN_23e915740(param_1,&plStack_58,DAT_23eeacdb8);
    plVar8 = plStack_48;
    plVar7 = plStack_58;
    plVar10 = plStack_50;
  }
  else {
    plVar6 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeacd38);
    if (plVar6 != (longlong *)0x0) {
      plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeacd48);
      if (plVar7 == (longlong *)0x0) {
        plVar7 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x68);
        plVar8 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar6 = *plVar6 + -1;
        if (*plVar6 == 0) {
          (**(code **)(plVar6[1] + 0x30))(plVar6);
        }
        goto LAB_23e2f707c;
      }
      *(undefined4 *)(plVar3 + 5) = 0x5d;
      plStack_58 = plVar6;
      plStack_50 = plVar7;
      lVar5 = FUN_23e94ed00(param_1,lVar5,&plStack_58);
      *plVar6 = *plVar6 + -1;
      if (*plVar6 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      if (lVar5 != 0) {
        lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar7 = *(longlong **)(lVar2 + 0x28);
        plVar3 = (longlong *)plVar7[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
        *(undefined4 *)(plVar7 + 8) = 0xffffffff;
        if (plVar3 != (longlong *)0x0) {
          plVar7[2] = 0;
          *plVar3 = *plVar3 + -1;
          if (*plVar3 == 0) {
            (**(code **)(plVar3[1] + 0x30))();
          }
        }
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        plVar7[0xf] = 0;
        *plVar1 = *plVar1 + -1;
        if (*plVar1 != 0) {
          return lVar5;
        }
        (**(code **)(plVar1[1] + 0x30))(plVar1);
        return lVar5;
      }
    }
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar7 = *(longlong **)(param_1 + 0x60);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = *(longlong **)(param_1 + 0x68);
  }
LAB_23e2f707c:
  plVar6 = DAT_23ed6a4f8;
  if (plVar8 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar6 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar8 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar8;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar6[3] = (longlong)plVar3;
    plVar6[2] = 0;
    *plVar3 = *plVar3 + 1;
    plVar6[4] = 0x5dffffffff;
    lVar5 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
    lVar2 = plVar6[-1];
    puVar4 = *(undefined8 **)(lVar5 + 8);
    *puVar4 = plVar6 + -2;
    plVar6[-2] = lVar5;
    plVar6[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar5 + 8) = plVar6 + -2;
    plVar9 = plVar6;
  }
  else {
    plVar9 = plVar8;
    if ((longlong *)plVar8[3] != plVar3) {
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
      plVar6[4] = 0x5dffffffff;
      lVar5 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar2 = plVar6[-1];
      puVar4 = *(undefined8 **)(lVar5 + 8);
      *puVar4 = plVar6 + -2;
      plVar6[-2] = lVar5;
      plVar6[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
      lVar2 = *plVar8;
      *(longlong **)(lVar5 + 8) = plVar6 + -2;
      plVar6[2] = (longlong)plVar8;
      plVar9 = plVar6;
      if (lVar2 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
    }
  }
  FUN_23e8bba40(plVar3,&DAT_23ec5b149,plVar1);
  if (_DAT_23eeafff0 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eeafff0 = (longlong *)0x0;
  }
  lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar5 + 0x28);
  plVar8 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar5 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar8 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar3[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,plVar7,plVar10,plVar9);
  return 0;
}
