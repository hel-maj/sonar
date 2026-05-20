/* ===== 23e77e4b0 workers.fishing.fishing_bot:FishingBot._get_fish_name_ru ===== */
/* ghidra_name=FUN_23e77e4b0 entry=23e77e4b0 size=1158 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_23e77e4b0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *plStack_68;
  longlong *plStack_60;
  
  plVar8 = _DAT_23eedad20;
  plVar7 = (longlong *)param_3[1];
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eedad20 != (longlong *)0x0) {
    lVar10 = *_DAT_23eedad20;
    if (lVar10 < 2) {
      if (_DAT_23eedad20[2] == 0) goto LAB_23e77e522;
      *_DAT_23eedad20 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
    }
    else {
      *_DAT_23eedad20 = lVar10 + -1;
    }
  }
  _DAT_23eedad20 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedaf50,DAT_23eedaeb8,0x10);
LAB_23e77e522:
  plVar3 = _DAT_23eedad20;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eedad20 + 9;
  lVar2 = *(longlong *)(lVar10 + 8);
  _DAT_23eedad20[0xf] = lVar2;
  *(longlong **)(lVar10 + 8) = plVar8;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar4 = DAT_23eed8ae0;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar4);
  if (plVar8 != (longlong *)0x0) {
    plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed6ce40);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (plVar9 != (longlong *)0x0) {
      *(undefined4 *)(plVar3 + 5) = 0x64b;
      plStack_68 = plVar7;
      plStack_60 = plVar7;
      lVar10 = FUN_23e94ed00(param_1,plVar9,&plStack_68);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if (lVar10 != 0) {
        lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar8 = *(longlong **)(lVar2 + 0x28);
        plVar3 = (longlong *)plVar8[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
        *(undefined4 *)(plVar8 + 8) = 0xffffffff;
        if (plVar3 != (longlong *)0x0) {
          plVar8[2] = 0;
          *plVar3 = *plVar3 + -1;
          if (*plVar3 == 0) {
            (**(code **)(plVar3[1] + 0x30))();
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
        *plVar7 = *plVar7 + -1;
        if (*plVar7 != 0) {
          return lVar10;
        }
        (**(code **)(plVar7[1] + 0x30))(plVar7);
        return lVar10;
      }
    }
  }
  plVar8 = *(longlong **)(param_1 + 0x70);
  uVar4 = *(undefined8 *)(param_1 + 0x60);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar5 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar9 = DAT_23ed6a4f8;
  if (plVar8 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar8 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar8;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar11 = plVar9;
    }
    plVar11[2] = 0;
    plVar11[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    plVar11[4] = 0x64bffffffff;
    lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
    lVar2 = plVar11[-1];
    puVar6 = *(undefined8 **)(lVar10 + 8);
    *puVar6 = plVar11 + -2;
    plVar11[-2] = lVar10;
    plVar11[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar10 + 8) = plVar11 + -2;
  }
  else {
    plVar11 = plVar8;
    if ((longlong *)plVar8[3] != plVar3) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar11 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar11;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar11 = plVar9;
      }
      plVar11[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      plVar11[4] = 0x64bffffffff;
      lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar2 = plVar11[-1];
      puVar6 = *(undefined8 **)(lVar10 + 8);
      *puVar6 = plVar11 + -2;
      plVar11[-2] = lVar10;
      plVar11[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar6;
      lVar2 = *plVar8;
      *(longlong **)(lVar10 + 8) = plVar11 + -2;
      plVar11[2] = (longlong)plVar8;
      if (lVar2 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
    }
  }
  FUN_23e8bba40(plVar3,&DAT_23ec5dd15,plVar1,plVar7);
  if (_DAT_23eedad20 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eedad20 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar10 + 0x28);
  plVar3 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar3 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))();
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
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  FUN_23a33aa70(param_1,uVar4,uVar5,plVar11);
  return 0;
}
