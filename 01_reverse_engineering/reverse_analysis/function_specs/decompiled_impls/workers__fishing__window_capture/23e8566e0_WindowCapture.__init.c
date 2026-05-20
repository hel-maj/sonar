/* ===== 23e8566e0 workers.fishing.window_capture:20 ===== */
/* ghidra_name=forced_23e8566e0 entry=23e8566e0 size=1495 */

code * forced_23e8566e0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  code *pcVar8;
  char cVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  undefined4 uVar14;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar10 = DAT_23eede310;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (DAT_23eede310 == (longlong *)0x0) {
LAB_23e85671e:
    DAT_23eede310 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eede300,DAT_23eede308,0x10);
  }
  else {
    lVar12 = *DAT_23eede310;
    if (1 < lVar12) {
      *DAT_23eede310 = lVar12 + -1;
      goto LAB_23e85671e;
    }
    if (DAT_23eede310[2] != 0) {
      *DAT_23eede310 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e85671e;
    }
  }
  plVar4 = DAT_23eede310;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar10 = DAT_23eede310 + 9;
  lVar3 = *(longlong *)(lVar12 + 8);
  DAT_23eede310[0xf] = lVar3;
  *(longlong **)(lVar12 + 8) = plVar10;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23ed6ce98);
  if (plVar10 != (longlong *)0x0) {
    *(undefined4 *)(plVar4 + 5) = 0x15;
    plVar11 = (longlong *)FUN_23e91a870(param_1,plVar10);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar11 != (longlong *)0x0) {
      cVar9 = FUN_23e8d9ac0(plVar1,DAT_23eedb780,plVar11);
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      pcVar8 = _Py_NoneStruct_exref;
      if (cVar9 != '\0') {
        cVar9 = FUN_23e8d9ac0(plVar1,DAT_23eedb788,_Py_NoneStruct_exref);
        uVar7 = DAT_23ed6cd08;
        if (cVar9 == '\0') {
          plVar10 = *(longlong **)(param_1 + 0x70);
          uVar7 = *(undefined8 *)(param_1 + 0x60);
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar14 = 0x16;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uVar5 = *(undefined8 *)(param_1 + 0x68);
          plVar11 = DAT_23ed6a4f8;
        }
        else {
          lVar12 = FUN_23e8da9a0();
          if (lVar12 == 0) {
            FUN_23e915740(param_1,&uStack_68,DAT_23eedb790);
            uVar14 = 0x17;
            plVar10 = plStack_58;
            uVar7 = uStack_68;
            uVar5 = uStack_60;
            plVar11 = DAT_23ed6a4f8;
          }
          else {
            cVar9 = FUN_23e8d9ac0(lVar12,DAT_23eedb798,uVar7);
            if (cVar9 == '\0') {
              uVar7 = *(undefined8 *)(param_1 + 0x60);
              uVar14 = 0x17;
              plVar10 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar5 = *(undefined8 *)(param_1 + 0x68);
              plVar11 = DAT_23ed6a4f8;
            }
            else {
              lVar12 = FUN_23e8da9a0();
              if (lVar12 == 0) {
                FUN_23e915740(param_1,&uStack_68,DAT_23eedb790);
                uVar14 = 0x18;
                plVar10 = plStack_58;
                uVar7 = uStack_68;
                uVar5 = uStack_60;
                plVar11 = DAT_23ed6a4f8;
              }
              else {
                cVar9 = FUN_23e8d9ac0(lVar12,DAT_23eedb7a0,_Py_FalseStruct_exref);
                if (cVar9 != '\0') {
                  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                  plVar10 = *(longlong **)(lVar12 + 0x28);
                  plVar4 = (longlong *)plVar10[2];
                  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                       *(undefined8 *)(lVar12 + 0x30);
                  *(undefined4 *)(plVar10 + 8) = 0xffffffff;
                  if (plVar4 != (longlong *)0x0) {
                    plVar10[2] = 0;
                    *plVar4 = *plVar4 + -1;
                    if (*plVar4 == 0) {
                      (**(code **)(plVar4[1] + 0x30))();
                    }
                  }
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  *(longlong *)pcVar8 = *(longlong *)pcVar8 + 1;
                  plVar10[0xf] = 0;
                  *plVar1 = *plVar1 + -1;
                  if (*plVar1 == 0) {
                    (**(code **)(plVar1[1] + 0x30))(plVar1);
                  }
                  *plVar2 = *plVar2 + -1;
                  if (*plVar2 != 0) {
                    return pcVar8;
                  }
                  (**(code **)(plVar2[1] + 0x30))(plVar2);
                  return pcVar8;
                }
                uVar7 = *(undefined8 *)(param_1 + 0x60);
                uVar14 = 0x18;
                plVar10 = *(longlong **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar5 = *(undefined8 *)(param_1 + 0x68);
                plVar11 = DAT_23ed6a4f8;
              }
            }
          }
        }
        goto joined_r0x00023e856954;
      }
    }
  }
  plVar10 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar14 = 0x15;
  uVar7 = *(undefined8 *)(param_1 + 0x60);
  uVar5 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar11 = DAT_23ed6a4f8;
joined_r0x00023e856954:
  DAT_23ed6a4f8 = plVar11;
  if (plVar10 == (longlong *)0x0) {
    if (plVar11 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar11;
      *plVar11 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar13 = plVar11;
    }
    pcVar8 = _PyRuntime_exref;
    plVar13[2] = 0;
    plVar13[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar12 = *(longlong *)(pcVar8 + 0x1f8);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar14;
    lVar12 = *(longlong *)(lVar12 + 0x10);
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(lVar12 + 0x2e8);
    lVar3 = plVar13[-1];
    puVar6 = *(undefined8 **)(lVar12 + 8);
    *puVar6 = plVar13 + -2;
    plVar13[-2] = lVar12;
    plVar13[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar12 + 8) = plVar13 + -2;
  }
  else {
    plVar13 = plVar10;
    if ((longlong *)plVar10[3] != plVar4) {
      if (plVar11 == (longlong *)0x0) {
        plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar11;
        *plVar11 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar13 = plVar11;
      }
      pcVar8 = _PyRuntime_exref;
      plVar13[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      lVar12 = *(longlong *)(pcVar8 + 0x1f8);
      *(undefined4 *)((longlong)plVar13 + 0x24) = uVar14;
      *(undefined4 *)(plVar13 + 4) = 0xffffffff;
      lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
      lVar3 = plVar13[-1];
      puVar6 = *(undefined8 **)(lVar12 + 8);
      *puVar6 = plVar13 + -2;
      plVar13[-2] = lVar12;
      plVar13[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar6;
      lVar3 = *plVar10;
      *(longlong **)(lVar12 + 8) = plVar13 + -2;
      plVar13[2] = (longlong)plVar10;
      if (lVar3 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5e407,plVar1,plVar2);
  if (DAT_23eede310 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    DAT_23eede310 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar10 = *(longlong **)(lVar12 + 0x28);
  plVar4 = (longlong *)plVar10[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar10 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar10[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  plVar10[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,uVar7,uVar5,plVar13);
  return (code *)0x0;
}
