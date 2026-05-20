/* ===== 23e1318c0 telegram.notification_manager:114 ===== */
/* ghidra_name=FUN_23e1318c0 entry=23e1318c0 size=1417 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e1318c0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  int iVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  code *pcVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined4 uVar13;
  
  plVar7 = _DAT_23eeaad98;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eeaad98 == (longlong *)0x0) {
LAB_23e1318fa:
    _DAT_23eeaad98 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeaad90,DAT_23eeaae08,0x10);
  }
  else {
    lVar2 = *_DAT_23eeaad98;
    if (1 < lVar2) {
      *_DAT_23eeaad98 = lVar2 + -1;
      goto LAB_23e1318fa;
    }
    if (_DAT_23eeaad98[2] != 0) {
      *_DAT_23eeaad98 = lVar2 + -1;
      if (lVar2 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23e1318fa;
    }
  }
  plVar4 = _DAT_23eeaad98;
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar7 = _DAT_23eeaad98 + 9;
  lVar3 = *(longlong *)(lVar2 + 8);
  _DAT_23eeaad98[0xf] = lVar3;
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
  lVar2 = _DAT_23eea8278;
  *plVar4 = *plVar4 + 1;
  *(undefined4 *)(plVar4 + 8) = 0;
  uVar11 = DAT_23eea8230;
  *(undefined4 *)(plVar4 + 5) = 0x74;
  plVar7 = (longlong *)FUN_23e915840(param_1,plVar1,uVar11,*(undefined8 *)(lVar2 + 0x18));
  if (plVar7 != (longlong *)0x0) {
    iVar6 = FUN_23a35f020(plVar7);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    pcVar10 = _Py_NoneStruct_exref;
    if (iVar6 != -1) {
      if (iVar6 == 0) {
        lVar2 = *(longlong *)(param_1 + 0x38);
        lVar3 = *(longlong *)(lVar2 + 8);
        *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
        plVar7 = *(longlong **)(lVar3 + 0x28);
        plVar4 = (longlong *)plVar7[2];
        *(undefined8 *)(lVar2 + 8) = *(undefined8 *)(lVar3 + 0x30);
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
LAB_23e131b36:
        *plVar1 = *plVar1 + -1;
        if (*plVar1 != 0) {
          return pcVar10;
        }
        (**(code **)(plVar1[1] + 0x30))(plVar1);
        return pcVar10;
      }
      plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eea8268);
      lVar2 = _DAT_23eea8280;
      if (plVar8 != (longlong *)0x0) {
        *(undefined4 *)(plVar4 + 5) = 0x78;
        plVar7 = (longlong *)
                 FUN_23e915840(param_1,plVar1,DAT_23eea8220,*(undefined8 *)(lVar2 + 0x18));
        if (plVar7 == (longlong *)0x0) {
          uVar11 = *(undefined8 *)(param_1 + 0x60);
          uVar12 = *(undefined8 *)(param_1 + 0x68);
          uVar13 = 0x78;
          plVar7 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          goto LAB_23e131bb2;
        }
        *(undefined4 *)(plVar4 + 5) = 0x78;
        plVar9 = (longlong *)FUN_23e914090(param_1,plVar8,plVar7);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        if (plVar9 != (longlong *)0x0) {
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
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
          pcVar10 = _Py_NoneStruct_exref;
          *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
          goto LAB_23e131b36;
        }
      }
      uVar11 = *(undefined8 *)(param_1 + 0x60);
      uVar12 = *(undefined8 *)(param_1 + 0x68);
      uVar13 = 0x78;
      plVar7 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      goto LAB_23e131bb2;
    }
  }
  plVar7 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar13 = 0x74;
  uVar11 = *(undefined8 *)(param_1 + 0x60);
  uVar12 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e131bb2:
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
    pcVar10 = _PyRuntime_exref;
    plVar9[2] = 0;
    plVar9[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar2 = *(longlong *)(pcVar10 + 0x1f8);
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar2 = *(longlong *)(lVar2 + 0x10);
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar13;
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
      pcVar10 = _PyRuntime_exref;
      plVar9[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      lVar2 = *(longlong *)(pcVar10 + 0x1f8);
      *(undefined4 *)((longlong)plVar9 + 0x24) = uVar13;
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
  FUN_23e8bba40(plVar4,&DAT_23ec5a438,plVar1,0);
  if (_DAT_23eeaad98 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eeaad98 = (longlong *)0x0;
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
  FUN_23a33aa70(param_1,uVar11,uVar12,plVar9);
  return (code *)0x0;
}
