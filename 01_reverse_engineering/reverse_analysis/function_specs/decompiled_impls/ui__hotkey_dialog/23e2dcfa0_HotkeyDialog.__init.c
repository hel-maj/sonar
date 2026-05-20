/* ===== 23e2dcfa0 ui.hotkey_dialog:103 ===== */
/* ghidra_name=FUN_23e2dcfa0 entry=23e2dcfa0 size=1517 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2dcfa0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  code *pcVar5;
  char cVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined4 uVar13;
  longlong *plStack_68;
  longlong *plStack_60;
  longlong *plStack_58;
  
  plVar10 = _DAT_23eeb0230;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eeb0230 == (longlong *)0x0) {
LAB_23e2dcfda:
    _DAT_23eeb0230 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb0228,DAT_23eeb0268,8);
  }
  else {
    lVar7 = *_DAT_23eeb0230;
    if (1 < lVar7) {
      *_DAT_23eeb0230 = lVar7 + -1;
      goto LAB_23e2dcfda;
    }
    if (_DAT_23eeb0230[2] != 0) {
      *_DAT_23eeb0230 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e2dcfda;
    }
  }
  plVar3 = _DAT_23eeb0230;
  lVar7 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eeb0230 + 9;
  lVar2 = *(longlong *)(lVar7 + 8);
  _DAT_23eeb0230[0xf] = lVar2;
  *(longlong **)(lVar7 + 8) = plVar10;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  lVar7 = FUN_23e8f5ff0();
  if (lVar7 == 0) {
    uVar13 = 0x69;
    FUN_23e915740(param_1,&plStack_68,_DAT_23eead598);
    plVar12 = plStack_58;
    plVar10 = plStack_68;
    plVar11 = plStack_60;
    goto LAB_23e2dd272;
  }
  plVar8 = (longlong *)FUN_23e8bc2f0(lVar7,_DAT_23eead5a0);
  if (plVar8 != (longlong *)0x0) {
    plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eead5a8);
    if (plVar9 == (longlong *)0x0) {
      plVar10 = *(longlong **)(param_1 + 0x60);
      plVar11 = *(longlong **)(param_1 + 0x68);
      plVar12 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      uVar13 = 0x6a;
      goto LAB_23e2dd272;
    }
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eead5b0);
    if (plVar10 == (longlong *)0x0) {
      plVar10 = *(longlong **)(param_1 + 0x60);
      plVar11 = *(longlong **)(param_1 + 0x68);
      plVar12 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      uVar13 = 0x6b;
      goto LAB_23e2dd272;
    }
    *(undefined4 *)(plVar3 + 5) = 0x69;
    plStack_68 = plVar9;
    plStack_60 = plVar10;
    plVar11 = (longlong *)FUN_23e9186b0(param_1,plVar8,&plStack_68,_DAT_23eead5b8);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar11 != (longlong *)0x0) {
      cVar6 = FUN_23e8d9ac0(plVar1,DAT_23eead3f8,plVar11);
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (cVar6 != '\0') {
        plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eead3f8);
        if (plVar10 != (longlong *)0x0) {
          *(undefined4 *)(plVar3 + 5) = 0x6d;
          plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar10,_DAT_23eead5c0);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if (plVar11 != (longlong *)0x0) {
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar10 = *(longlong **)(lVar7 + 0x28);
            plVar3 = (longlong *)plVar10[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
            *(undefined4 *)(plVar10 + 8) = 0xffffffff;
            if (plVar3 != (longlong *)0x0) {
              plVar10[2] = 0;
              *plVar3 = *plVar3 + -1;
              if (*plVar3 == 0) {
                (**(code **)(plVar3[1] + 0x30))();
              }
            }
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            plVar10[0xf] = 0;
            pcVar5 = _Py_NoneStruct_exref;
            *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
            *plVar1 = *plVar1 + -1;
            if (*plVar1 != 0) {
              return pcVar5;
            }
            (**(code **)(plVar1[1] + 0x30))(plVar1);
            return pcVar5;
          }
        }
        plVar10 = *(longlong **)(param_1 + 0x60);
        uVar13 = 0x6d;
        plVar12 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar11 = *(longlong **)(param_1 + 0x68);
        goto LAB_23e2dd272;
      }
    }
  }
  plVar12 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar13 = 0x69;
  plVar10 = *(longlong **)(param_1 + 0x60);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar11 = *(longlong **)(param_1 + 0x68);
LAB_23e2dd272:
  plVar8 = DAT_23ed6a4f8;
  if (plVar12 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar12 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar12;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar5 = _PyRuntime_exref;
    plVar8[3] = (longlong)plVar3;
    plVar8[2] = 0;
    *plVar3 = *plVar3 + 1;
    lVar7 = *(longlong *)(pcVar5 + 0x1f8);
    *(undefined4 *)(plVar8 + 4) = 0xffffffff;
    lVar7 = *(longlong *)(lVar7 + 0x10);
    *(undefined4 *)((longlong)plVar8 + 0x24) = uVar13;
    lVar7 = *(longlong *)(lVar7 + 0x2e8);
    lVar2 = plVar8[-1];
    puVar4 = *(undefined8 **)(lVar7 + 8);
    *puVar4 = plVar8 + -2;
    plVar8[-2] = lVar7;
    plVar8[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar7 + 8) = plVar8 + -2;
    plVar9 = plVar8;
  }
  else {
    plVar9 = plVar12;
    if ((longlong *)plVar12[3] != plVar3) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar9 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar9;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar5 = _PyRuntime_exref;
      plVar8[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      lVar7 = *(longlong *)(pcVar5 + 0x1f8);
      *(undefined4 *)(plVar8 + 4) = 0xffffffff;
      *(undefined4 *)((longlong)plVar8 + 0x24) = uVar13;
      lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
      lVar2 = plVar8[-1];
      puVar4 = *(undefined8 **)(lVar7 + 8);
      *puVar4 = plVar8 + -2;
      plVar8[-2] = lVar7;
      plVar8[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
      lVar2 = *plVar12;
      *(longlong **)(lVar7 + 8) = plVar8 + -2;
      plVar8[2] = (longlong)plVar12;
      plVar9 = plVar8;
      if (lVar2 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
    }
  }
  FUN_23e8bba40(plVar3,&DAT_23ec5b149,plVar1);
  if (_DAT_23eeb0230 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eeb0230 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar7 + 0x28);
  plVar12 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar12 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))();
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
  FUN_23a33aa70(param_1,plVar10,plVar11,plVar9);
  return (code *)0x0;
}
