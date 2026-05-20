/* ===== 23e2aea00 ui.garbage_settings_dialog:? ===== */
/* ghidra_name=FUN_23e2aea00 entry=23e2aea00 size=1534 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2aea00(longlong param_1,undefined8 param_2,undefined8 *param_3)

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
  longlong *plVar10;
  int iVar11;
  undefined4 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  longlong *plVar15;
  undefined8 uStack_68;
  longlong *plStack_60;
  
  plVar7 = _DAT_23eeb03c8;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eeb03c8 != (longlong *)0x0) {
    lVar2 = *_DAT_23eeb03c8;
    if (lVar2 < 2) {
      if (_DAT_23eeb03c8[2] == 0) goto LAB_23e2aea65;
      *_DAT_23eeb03c8 = lVar2 + -1;
      if (lVar2 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
    }
    else {
      *_DAT_23eeb03c8 = lVar2 + -1;
    }
  }
  _DAT_23eeb03c8 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb0458,DAT_23eeb0428,0x18);
LAB_23e2aea65:
  plVar4 = _DAT_23eeb03c8;
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar7 = _DAT_23eeb03c8 + 9;
  lVar3 = *(longlong *)(lVar2 + 8);
  _DAT_23eeb03c8[0xf] = lVar3;
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
  *plVar4 = *plVar4 + 1;
  uVar13 = DAT_23eeae450;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,uVar13);
  if (plVar7 == (longlong *)0x0) {
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    uVar14 = *(undefined8 *)(param_1 + 0x68);
    plVar8 = (longlong *)0x0;
    uVar12 = 0xb6;
    plVar7 = *(longlong **)(param_1 + 0x70);
    plVar9 = (longlong *)0x0;
  }
  else {
    *(undefined4 *)(plVar4 + 5) = 0xb6;
    plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar7,_DAT_23eeae568);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    if (plVar8 == (longlong *)0x0) {
      uVar13 = *(undefined8 *)(param_1 + 0x60);
      uVar14 = *(undefined8 *)(param_1 + 0x68);
      plVar9 = (longlong *)0x0;
      uVar12 = 0xb6;
      plVar7 = *(longlong **)(param_1 + 0x70);
    }
    else {
      plVar7 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed6ce40);
      uVar13 = _DAT_23eeae570;
      lVar2 = DAT_23ed6cce8;
      if (plVar7 == (longlong *)0x0) {
        uVar13 = *(undefined8 *)(param_1 + 0x60);
        uVar14 = *(undefined8 *)(param_1 + 0x68);
        plVar9 = (longlong *)0x0;
        uVar12 = 0xb7;
        plVar7 = *(longlong **)(param_1 + 0x70);
      }
      else {
        lVar3 = *(longlong *)(param_1 + 0x10);
        plVar9 = *(longlong **)(DAT_23ed6cce8 + 0x20);
        iVar11 = *(int *)(lVar3 + 0x1410);
        *plVar9 = *plVar9 + 1;
        if (iVar11 == 0) {
          plVar10 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
          plVar9 = *(longlong **)(lVar2 + 0x20);
        }
        else {
          iVar11 = iVar11 + -1;
          *(int *)(lVar3 + 0x1410) = iVar11;
          plVar10 = *(longlong **)(lVar3 + 0x1190 + (longlong)iVar11 * 8);
          *plVar10 = 1;
        }
        lVar2 = *(longlong *)(lVar2 + 0x28);
        plVar10[2] = 0;
        plVar10[4] = (longlong)plVar9;
        plVar10[5] = lVar2;
        plVar10[3] = 1;
        *(undefined4 *)(plVar4 + 5) = 0xb7;
        uStack_68 = uVar13;
        plStack_60 = plVar10;
        plVar9 = (longlong *)FUN_23e94ed00(param_1,plVar7,&uStack_68);
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (plVar9 == (longlong *)0x0) {
          uVar13 = *(undefined8 *)(param_1 + 0x60);
          uVar14 = *(undefined8 *)(param_1 + 0x68);
          uVar12 = 0xb7;
          plVar7 = *(longlong **)(param_1 + 0x70);
        }
        else {
          *(undefined4 *)(plVar4 + 5) = 0xb8;
          plVar7 = (longlong *)FUN_23e915840(param_1,plVar1,_DAT_23eeae590,plVar9);
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
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            *plVar1 = *plVar1 + -1;
            if (*plVar1 != 0) {
              return pcVar6;
            }
            (**(code **)(plVar1[1] + 0x30))(plVar1);
            return pcVar6;
          }
          uVar13 = *(undefined8 *)(param_1 + 0x60);
          uVar14 = *(undefined8 *)(param_1 + 0x68);
          uVar12 = 0xb8;
          plVar7 = *(longlong **)(param_1 + 0x70);
        }
      }
    }
  }
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar10 = DAT_23ed6a4f8;
  if (plVar7 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar7 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar7;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar6 = _PyRuntime_exref;
    plVar10[2] = 0;
    plVar10[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar2 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar12;
    lVar2 = *(longlong *)(lVar2 + 0x10);
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar2 = *(longlong *)(lVar2 + 0x2e8);
    lVar3 = plVar10[-1];
    puVar5 = *(undefined8 **)(lVar2 + 8);
    *puVar5 = plVar10 + -2;
    plVar10[-2] = lVar2;
    plVar10[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar2 + 8) = plVar10 + -2;
    plVar15 = plVar10;
  }
  else {
    plVar15 = plVar7;
    if ((longlong *)plVar7[3] != plVar4) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar15 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar15;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar10[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      *(undefined4 *)((longlong)plVar10 + 0x24) = uVar12;
      pcVar6 = _PyRuntime_exref;
      *(undefined4 *)(plVar10 + 4) = 0xffffffff;
      lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10) + 0x2e8);
      lVar3 = plVar10[-1];
      puVar5 = *(undefined8 **)(lVar2 + 8);
      *puVar5 = plVar10 + -2;
      plVar10[-2] = lVar2;
      plVar10[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
      lVar3 = *plVar7;
      *(longlong **)(lVar2 + 8) = plVar10 + -2;
      plVar10[2] = (longlong)plVar7;
      plVar15 = plVar10;
      if (lVar3 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5b355,plVar1,plVar8,plVar9);
  if (_DAT_23eeb03c8 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eeb03c8 = (longlong *)0x0;
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
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar13,uVar14,plVar15);
  return (code *)0x0;
}
