/* ===== 23e779790 workers.fishing.fishing_bot:FishingBot._return_to_fishing ===== */
/* ghidra_name=FUN_23e779790 entry=23e779790 size=1244 */

code * FUN_23e779790(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  code *pcVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined4 uVar12;
  
  plVar7 = DAT_23eedad50;
  plVar1 = (longlong *)*param_3;
  if (DAT_23eedad50 == (longlong *)0x0) {
LAB_23e7797ca:
    DAT_23eedad50 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedaf18,DAT_23eedaeb8,8);
  }
  else {
    lVar2 = *DAT_23eedad50;
    if (1 < lVar2) {
      *DAT_23eedad50 = lVar2 + -1;
      goto LAB_23e7797ca;
    }
    if (DAT_23eedad50[2] != 0) {
      *DAT_23eedad50 = lVar2 + -1;
      if (lVar2 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23e7797ca;
    }
  }
  plVar4 = DAT_23eedad50;
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar7 = DAT_23eedad50 + 9;
  lVar3 = *(longlong *)(lVar2 + 8);
  DAT_23eedad50[0xf] = lVar3;
  *(longlong **)(lVar2 + 8) = plVar7;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  lVar2 = DAT_23eed96d0;
  *plVar4 = *plVar4 + 1;
  *(undefined4 *)(plVar4 + 8) = 0;
  uVar10 = DAT_23eed8b40;
  *(undefined4 *)(plVar4 + 5) = 0x5f9;
  plVar7 = (longlong *)FUN_23e915840(param_1,plVar1,uVar10,*(undefined8 *)(lVar2 + 0x18));
  if (plVar7 == (longlong *)0x0) {
    uVar10 = *(undefined8 *)(param_1 + 0x60);
    uVar11 = *(undefined8 *)(param_1 + 0x68);
    uVar12 = 0x5f9;
    plVar7 = *(longlong **)(param_1 + 0x70);
  }
  else {
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a98);
    lVar2 = DAT_23eed96d8;
    if (plVar7 != (longlong *)0x0) {
      *(undefined4 *)(plVar4 + 5) = 0x5fa;
      plVar8 = (longlong *)FUN_23e915840(param_1,plVar7,DAT_23eed8c60,*(undefined8 *)(lVar2 + 0x18))
      ;
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      if (plVar8 != (longlong *)0x0) {
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        lVar2 = DAT_23eed8f50;
        *(undefined4 *)(plVar4 + 5) = 0x5fb;
        plVar7 = (longlong *)
                 FUN_23e915840(param_1,plVar1,DAT_23eed8c50,*(undefined8 *)(lVar2 + 0x18));
        if (plVar7 != (longlong *)0x0) {
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
          plVar7 = *(longlong **)(lVar2 + 0x28);
          plVar4 = (longlong *)plVar7[2];
          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
          *(undefined4 *)(plVar7 + 8) = 0xffffffff;
          if (plVar4 != (longlong *)0x0) {
            plVar7[2] = 0;
            *plVar4 = *plVar4 + -1;
            if (*plVar4 == 0) {
              (**(code **)(plVar4[1] + 0x30))();
            }
          }
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          plVar7[0xf] = 0;
          pcVar6 = _Py_NoneStruct_exref;
          *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
          *plVar1 = *plVar1 + -1;
          if (*plVar1 != 0) {
            return pcVar6;
          }
          (**(code **)(plVar1[1] + 0x30))(plVar1);
          return pcVar6;
        }
        uVar10 = *(undefined8 *)(param_1 + 0x60);
        uVar11 = *(undefined8 *)(param_1 + 0x68);
        uVar12 = 0x5fb;
        plVar7 = *(longlong **)(param_1 + 0x70);
        goto LAB_23e779a22;
      }
    }
    uVar10 = *(undefined8 *)(param_1 + 0x60);
    uVar11 = *(undefined8 *)(param_1 + 0x68);
    uVar12 = 0x5fa;
    plVar7 = *(longlong **)(param_1 + 0x70);
  }
LAB_23e779a22:
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar8 = DAT_23ed6a4f8;
  if (plVar7 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar7 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar7;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar9 = plVar8;
    }
    pcVar6 = _PyRuntime_exref;
    plVar9[2] = 0;
    plVar9[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar2 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar2 = *(longlong *)(lVar2 + 0x10);
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar12;
    lVar2 = *(longlong *)(lVar2 + 0x2e8);
    lVar3 = plVar9[-1];
    puVar5 = *(undefined8 **)(lVar2 + 8);
    *puVar5 = plVar9 + -2;
    plVar9[-2] = lVar2;
    plVar9[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar2 + 8) = plVar9 + -2;
  }
  else {
    plVar9 = plVar7;
    if ((longlong *)plVar7[3] != plVar4) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar9 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar9;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar9 = plVar8;
      }
      pcVar6 = _PyRuntime_exref;
      plVar9[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      lVar2 = *(longlong *)(pcVar6 + 0x1f8);
      *(undefined4 *)((longlong)plVar9 + 0x24) = uVar12;
      *(undefined4 *)(plVar9 + 4) = 0xffffffff;
      lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x2e8);
      lVar3 = plVar9[-1];
      puVar5 = *(undefined8 **)(lVar2 + 8);
      *puVar5 = plVar9 + -2;
      plVar9[-2] = lVar2;
      plVar9[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
      lVar3 = *plVar7;
      *(longlong **)(lVar2 + 8) = plVar9 + -2;
      plVar9[2] = (longlong)plVar7;
      if (lVar3 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5dc90,plVar1);
  if (DAT_23eedad50 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    DAT_23eedad50 = (longlong *)0x0;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar7 = *(longlong **)(lVar2 + 0x28);
  plVar4 = (longlong *)plVar7[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
  *(undefined4 *)(plVar7 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar7[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  plVar7[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar10,uVar11,plVar9);
  return (code *)0x0;
}
