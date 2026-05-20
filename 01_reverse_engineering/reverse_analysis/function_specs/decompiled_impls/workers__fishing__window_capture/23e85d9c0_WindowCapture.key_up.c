/* ===== 23e85d9c0 workers.fishing.window_capture:147 ===== */
/* ghidra_name=FUN_23e85d9c0 entry=23e85d9c0 size=1291 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e85d9c0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  code *pcVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar9 = _DAT_23eede250;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eede250 == (longlong *)0x0) {
LAB_23e85d9fe:
    _DAT_23eede250 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede248,DAT_23eede308,0x10);
  }
  else {
    lVar7 = *_DAT_23eede250;
    if (1 < lVar7) {
      *_DAT_23eede250 = lVar7 + -1;
      goto LAB_23e85d9fe;
    }
    if (_DAT_23eede250[2] != 0) {
      *_DAT_23eede250 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e85d9fe;
    }
  }
  plVar4 = _DAT_23eede250;
  lVar7 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eede250 + 9;
  lVar3 = *(longlong *)(lVar7 + 8);
  _DAT_23eede250[0xf] = lVar3;
  *(longlong **)(lVar7 + 8) = plVar9;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  *(undefined4 *)(plVar4 + 8) = 0;
  lVar7 = FUN_23e8da9a0();
  if (lVar7 == 0) {
    FUN_23e915740(param_1,&uStack_68,DAT_23eedb790);
    uVar11 = uStack_68;
    uVar12 = uStack_60;
    plVar9 = plStack_58;
    goto LAB_23e85dc3c;
  }
  plVar8 = (longlong *)FUN_23e8bc2f0(lVar7,_DAT_23eedb9b8);
  if (plVar8 == (longlong *)0x0) {
LAB_23e85dc20:
    plVar9 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar11 = *(undefined8 *)(param_1 + 0x60);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar12 = *(undefined8 *)(param_1 + 0x68);
  }
  else {
    plVar9 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23ed6ce98);
    if (plVar9 != (longlong *)0x0) {
      *(undefined4 *)(plVar4 + 5) = 0x96;
      plVar10 = (longlong *)FUN_23e91a870(param_1,plVar9);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if (plVar10 != (longlong *)0x0) {
        *(undefined4 *)(plVar4 + 5) = 0x96;
        plVar9 = (longlong *)FUN_23e914090(param_1,plVar8,plVar10);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (plVar9 != (longlong *)0x0) {
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
          plVar9 = *(longlong **)(lVar7 + 0x28);
          plVar4 = (longlong *)plVar9[2];
          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
          *(undefined4 *)(plVar9 + 8) = 0xffffffff;
          if (plVar4 != (longlong *)0x0) {
            plVar9[2] = 0;
            *plVar4 = *plVar4 + -1;
            if (*plVar4 == 0) {
              (**(code **)(plVar4[1] + 0x30))();
            }
          }
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          plVar9[0xf] = 0;
          pcVar6 = _Py_NoneStruct_exref;
          *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
          *plVar1 = *plVar1 + -1;
          if (*plVar1 == 0) {
            (**(code **)(plVar1[1] + 0x30))(plVar1);
          }
          *plVar2 = *plVar2 + -1;
          if (*plVar2 != 0) {
            return pcVar6;
          }
          (**(code **)(plVar2[1] + 0x30))(plVar2);
          return pcVar6;
        }
        goto LAB_23e85dc20;
      }
    }
    uVar11 = *(undefined8 *)(param_1 + 0x60);
    uVar12 = *(undefined8 *)(param_1 + 0x68);
    plVar9 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
  }
LAB_23e85dc3c:
  plVar8 = DAT_23ed6a4f8;
  if (plVar9 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar9 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar9;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar8[2] = 0;
    plVar8[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    plVar8[4] = 0x96ffffffff;
    lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
    lVar3 = plVar8[-1];
    puVar5 = *(undefined8 **)(lVar7 + 8);
    *puVar5 = plVar8 + -2;
    plVar8[-2] = lVar7;
    plVar8[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar7 + 8) = plVar8 + -2;
    plVar10 = plVar8;
  }
  else {
    plVar10 = plVar9;
    if ((longlong *)plVar9[3] != plVar4) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar10 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar10;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar8[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      plVar8[4] = 0x96ffffffff;
      lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar3 = plVar8[-1];
      puVar5 = *(undefined8 **)(lVar7 + 8);
      *puVar5 = plVar8 + -2;
      plVar8[-2] = lVar7;
      plVar8[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
      lVar3 = *plVar9;
      *(longlong **)(lVar7 + 8) = plVar8 + -2;
      plVar8[2] = (longlong)plVar9;
      plVar10 = plVar8;
      if (lVar3 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5e407,plVar1,plVar2);
  if (_DAT_23eede250 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eede250 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar7 + 0x28);
  plVar4 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
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
  FUN_23a33aa70(param_1,uVar11,uVar12,plVar10);
  return (code *)0x0;
}
