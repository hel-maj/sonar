/* ===== 23e859850 workers.fishing.window_capture:96 ===== */
/* ghidra_name=FUN_23e859850 entry=23e859850 size=4113 */

longlong * FUN_23e859850(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  code *pcVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  undefined8 local_80;
  undefined8 local_78;
  undefined4 local_70;
  undefined8 local_68;
  undefined8 local_60;
  longlong *local_58;
  
  plVar11 = DAT_23eede2a0;
  plVar1 = (longlong *)param_3[1];
  plVar2 = (longlong *)*param_3;
  plVar3 = (longlong *)param_3[2];
  if (DAT_23eede2a0 == (longlong *)0x0) {
LAB_23e85989f:
    DAT_23eede2a0 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eede298,DAT_23eede308,0x38);
  }
  else {
    lVar9 = *DAT_23eede2a0;
    if (1 < lVar9) {
      *DAT_23eede2a0 = lVar9 + -1;
      goto LAB_23e85989f;
    }
    if (DAT_23eede2a0[2] != 0) {
      *DAT_23eede2a0 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e85989f;
    }
  }
  plVar7 = DAT_23eede2a0;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar11 = DAT_23eede2a0 + 9;
  lVar4 = *(longlong *)(lVar9 + 8);
  DAT_23eede2a0[0xf] = lVar4;
  *(longlong **)(lVar9 + 8) = plVar11;
  if ((lVar4 != 0) &&
     (((*(char *)(lVar4 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar4 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar4 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar4 + 0x38))
       ) && (plVar7[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar4 + 0x28);
    *(longlong **)(plVar7[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar7 = *plVar7 + 1;
  *(undefined4 *)(plVar7 + 8) = 0;
  lVar9 = FUN_23e8da870();
  if (lVar9 == 0) {
    plVar15 = (longlong *)0x0;
    plVar16 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    FUN_23e915740(param_1,&local_68,DAT_23eedb7b8);
    local_70 = 0x62;
    local_80 = local_68;
    local_78 = local_60;
    plVar12 = (longlong *)0x0;
    plVar11 = local_58;
    goto LAB_23e85a060;
  }
  plVar10 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedb918);
  if (plVar10 == (longlong *)0x0) {
    local_80 = *(undefined8 *)(param_1 + 0x60);
    plVar11 = *(longlong **)(param_1 + 0x70);
    plVar15 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    local_70 = 0x62;
    local_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar16 = (longlong *)0x0;
    goto LAB_23e85a060;
  }
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eedb788);
  if (plVar11 == (longlong *)0x0) {
    local_80 = *(undefined8 *)(param_1 + 0x60);
    plVar11 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    local_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar10 = *plVar10 + -1;
    plVar13 = (longlong *)0x0;
    if (*plVar10 == 0) {
      plVar15 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      (**(code **)(plVar10[1] + 0x30))(plVar10);
      local_70 = 0x62;
    }
    else {
      plVar15 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      local_70 = 0x62;
    }
    goto LAB_23e85a060;
  }
  *(undefined4 *)(plVar7 + 5) = 0x62;
  plVar12 = (longlong *)FUN_23e914090(param_1,plVar10,plVar11);
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if (plVar12 == (longlong *)0x0) {
    local_80 = *(undefined8 *)(param_1 + 0x60);
    plVar11 = *(longlong **)(param_1 + 0x70);
    plVar15 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar16 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    local_70 = 0x62;
    local_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e85a060;
  }
  lVar9 = FUN_23e8da870();
  if (lVar9 == 0) {
    plVar15 = (longlong *)0x0;
    plVar16 = (longlong *)0x0;
    FUN_23e915740(param_1,&local_68,DAT_23eedb7b8);
    local_70 = 99;
    local_80 = local_68;
    local_78 = local_60;
    plVar13 = (longlong *)0x0;
    plVar11 = local_58;
    goto LAB_23e85a060;
  }
  plVar10 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedb820);
  if (plVar10 == (longlong *)0x0) {
    local_80 = *(undefined8 *)(param_1 + 0x60);
    plVar11 = *(longlong **)(param_1 + 0x70);
    plVar16 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    local_70 = 99;
    local_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar15 = (longlong *)0x0;
    goto LAB_23e85a060;
  }
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eedb788);
  if (plVar11 == (longlong *)0x0) {
    local_80 = *(undefined8 *)(param_1 + 0x60);
    plVar11 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    local_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar10 = *plVar10 + -1;
    plVar16 = (longlong *)0x0;
    if (*plVar10 == 0) {
      plVar13 = (longlong *)0x0;
      plVar15 = (longlong *)0x0;
      (**(code **)(plVar10[1] + 0x30))(plVar10);
      local_70 = 99;
    }
    else {
      plVar15 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      local_70 = 99;
    }
    goto LAB_23e85a060;
  }
  *(undefined4 *)(plVar7 + 5) = 99;
  plVar13 = (longlong *)FUN_23e914090(param_1,plVar10,plVar11);
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if (plVar13 == (longlong *)0x0) {
    local_80 = *(undefined8 *)(param_1 + 0x60);
    plVar11 = *(longlong **)(param_1 + 0x70);
    plVar15 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar16 = (longlong *)0x0;
    local_70 = 99;
    local_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e85a060;
  }
  plVar10 = (longlong *)FUN_23a388650(param_1,plVar12,DAT_23eedb920,2);
  if (plVar10 == (longlong *)0x0) {
LAB_23e85a4a8:
    plVar15 = (longlong *)0x0;
    local_80 = *(undefined8 *)(param_1 + 0x60);
    plVar11 = *(longlong **)(param_1 + 0x70);
    plVar16 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    local_70 = 100;
    local_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e85a060;
  }
  plVar11 = (longlong *)FUN_23a388650(param_1,plVar12,DAT_23ed6ccf0,0);
  if (plVar11 == (longlong *)0x0) {
    local_80 = *(undefined8 *)(param_1 + 0x60);
    plVar11 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    local_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar10 = *plVar10 + -1;
    plVar16 = (longlong *)0x0;
    if (*plVar10 == 0) {
      plVar15 = (longlong *)0x0;
      (**(code **)(plVar10[1] + 0x30))(plVar10);
      local_70 = 100;
      goto LAB_23e85a060;
    }
  }
  else {
    plVar14 = (longlong *)FUN_23e8c6640(plVar10,plVar11);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (plVar14 == (longlong *)0x0) {
      local_80 = *(undefined8 *)(param_1 + 0x60);
      plVar11 = *(longlong **)(param_1 + 0x70);
      plVar15 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar16 = (longlong *)0x0;
      local_70 = 100;
      local_78 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e85a060;
    }
    plVar11 = (longlong *)FUN_23a388650(param_1,plVar13,DAT_23eedb920,2);
    if (plVar11 != (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23e8c6640(plVar14,plVar11);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (plVar15 == (longlong *)0x0) goto LAB_23e85a4a8;
      if ((code *)plVar15[1] == PyLong_Type_exref) {
        plVar16 = (longlong *)
                  (**(code **)(*(longlong *)(PyLong_Type_exref + 0x60) + 0xe8))
                            (plVar15,DAT_23eedb920);
        lVar9 = *plVar15 + -1;
        *plVar15 = lVar9;
        if (plVar16 == (longlong *)0x0) {
          if (lVar9 == 0) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          goto LAB_23e85a750;
        }
        if (lVar9 == 0) {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
        }
      }
      else {
        plVar16 = (longlong *)FUN_23e8c1be0(plVar15);
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
        }
        if (plVar16 == (longlong *)0x0) {
LAB_23e85a750:
          local_80 = *(undefined8 *)(param_1 + 0x60);
          plVar11 = *(longlong **)(param_1 + 0x70);
          plVar15 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          local_70 = 100;
          plVar16 = (longlong *)0x0;
          local_78 = *(undefined8 *)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e85a060;
        }
      }
      plVar10 = (longlong *)FUN_23a388650(param_1,plVar12,DAT_23eedb928,3);
      if (plVar10 != (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23a388650(param_1,plVar12,DAT_23ed6ccf8,1);
        if (plVar11 == (longlong *)0x0) {
          local_80 = *(undefined8 *)(param_1 + 0x60);
          plVar11 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          local_70 = 0x65;
          local_78 = *(undefined8 *)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar10 = *plVar10 + -1;
          plVar15 = (longlong *)0x0;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
            local_70 = 0x65;
          }
          goto LAB_23e85a060;
        }
        plVar14 = (longlong *)FUN_23e8c6640(plVar10,plVar11);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (plVar14 != (longlong *)0x0) {
          plVar11 = (longlong *)FUN_23a388650(param_1,plVar13,DAT_23eedb928,3);
          if (plVar11 == (longlong *)0x0) {
            local_80 = *(undefined8 *)(param_1 + 0x60);
            plVar11 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            local_70 = 0x65;
            local_78 = *(undefined8 *)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar14 = *plVar14 + -1;
            plVar15 = (longlong *)0x0;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
              local_70 = 0x65;
            }
            goto LAB_23e85a060;
          }
          plVar10 = (longlong *)FUN_23e8c6640(plVar14,plVar11);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (plVar10 != (longlong *)0x0) {
            plVar15 = (longlong *)FUN_23e8c6640(plVar10,plVar16);
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            if (plVar15 == (longlong *)0x0) {
              local_80 = *(undefined8 *)(param_1 + 0x60);
              plVar11 = *(longlong **)(param_1 + 0x70);
              local_70 = 0x65;
              *(undefined8 *)(param_1 + 0x70) = 0;
              local_78 = *(undefined8 *)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            else {
              plVar11 = (longlong *)FUN_23a388650(param_1,plVar12,DAT_23ed6ccf0,0);
              if (plVar11 != (longlong *)0x0) {
                plVar10 = (longlong *)FUN_23e8c09e0(plVar11,plVar16);
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))();
                }
                if (plVar10 != (longlong *)0x0) {
                  lVar9 = FUN_23e8c09e0(plVar10,plVar1);
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  if (lVar9 != 0) {
                    lVar4 = *(longlong *)(param_1 + 0x10);
                    plVar10 = *(longlong **)(lVar4 + 0xe20);
                    if (plVar10 == (longlong *)0x0) {
                      plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                    }
                    else {
                      lVar5 = plVar10[3];
                      *(int *)(lVar4 + 0xebc) = *(int *)(lVar4 + 0xebc) + -1;
                      *(longlong *)(lVar4 + 0xe20) = lVar5;
                      *plVar10 = 1;
                    }
                    pcVar8 = _PyRuntime_exref;
                    plVar10[4] = 0;
                    lVar4 = *(longlong *)
                             (*(longlong *)(*(longlong *)(pcVar8 + 0x1f8) + 0x10) + 0x2e8);
                    lVar5 = plVar10[-1];
                    puVar6 = *(undefined8 **)(lVar4 + 8);
                    *puVar6 = plVar10 + -2;
                    plVar10[-2] = lVar4;
                    plVar10[-1] = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar6;
                    *(longlong **)(lVar4 + 8) = plVar10 + -2;
                    plVar10[3] = lVar9;
                    plVar11 = (longlong *)FUN_23a388650(param_1,plVar12,DAT_23ed6ccf8,1);
                    if (plVar11 != (longlong *)0x0) {
                      plVar14 = (longlong *)FUN_23e8c09e0(plVar11,plVar15);
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        (**(code **)(plVar11[1] + 0x30))(plVar11);
                      }
                      if (plVar14 != (longlong *)0x0) {
                        lVar9 = FUN_23e8c09e0(plVar14,plVar3);
                        *plVar14 = *plVar14 + -1;
                        if (*plVar14 == 0) {
                          (**(code **)(plVar14[1] + 0x30))(plVar14);
                        }
                        if (lVar9 != 0) {
                          lVar4 = *(longlong *)(param_1 + 0x38);
                          plVar10[4] = lVar9;
                          lVar9 = *(longlong *)(lVar4 + 8);
                          plVar11 = *(longlong **)(lVar9 + 0x28);
                          plVar7 = (longlong *)plVar11[2];
                          *(undefined8 *)(lVar4 + 8) = *(undefined8 *)(lVar9 + 0x30);
                          *(undefined4 *)(plVar11 + 8) = 0xffffffff;
                          if (plVar7 != (longlong *)0x0) {
                            plVar11[2] = 0;
                            *plVar7 = *plVar7 + -1;
                            if (*plVar7 == 0) {
                              (**(code **)(plVar7[1] + 0x30))();
                            }
                          }
                          *plVar11 = *plVar11 + -1;
                          if (*plVar11 == 0) {
                            (**(code **)(plVar11[1] + 0x30))(plVar11);
                          }
                          plVar11[0xf] = 0;
                          *plVar12 = *plVar12 + -1;
                          if (*plVar12 == 0) {
                            (**(code **)(plVar12[1] + 0x30))(plVar12);
                          }
                          *plVar13 = *plVar13 + -1;
                          if (*plVar13 == 0) {
                            (**(code **)(plVar13[1] + 0x30))(plVar13);
                          }
                          *plVar16 = *plVar16 + -1;
                          if (*plVar16 == 0) {
                            (**(code **)(plVar16[1] + 0x30))(plVar16);
                          }
                          *plVar15 = *plVar15 + -1;
                          if (*plVar15 == 0) {
                            (**(code **)(plVar15[1] + 0x30))(plVar15);
                          }
                          *plVar2 = *plVar2 + -1;
                          if (*plVar2 == 0) {
                            (**(code **)(plVar2[1] + 0x30))(plVar2);
                          }
                          lVar9 = *plVar1;
                          *plVar1 = lVar9 + -1;
                          if (lVar9 + -1 == 0) {
                            (**(code **)(plVar1[1] + 0x30))(plVar1);
                          }
                          lVar9 = *plVar3;
                          *plVar3 = lVar9 + -1;
                          if (lVar9 + -1 != 0) {
                            return plVar10;
                          }
                          (**(code **)(plVar3[1] + 0x30))(plVar3);
                          return plVar10;
                        }
                      }
                    }
                    local_80 = *(undefined8 *)(param_1 + 0x60);
                    plVar11 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_78 = *(undefined8 *)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                    }
                    local_70 = 0x66;
                    goto LAB_23e85a060;
                  }
                }
              }
              local_80 = *(undefined8 *)(param_1 + 0x60);
              plVar11 = *(longlong **)(param_1 + 0x70);
              local_70 = 0x66;
              *(undefined8 *)(param_1 + 0x70) = 0;
              local_78 = *(undefined8 *)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            goto LAB_23e85a060;
          }
        }
      }
      local_80 = *(undefined8 *)(param_1 + 0x60);
      plVar11 = *(longlong **)(param_1 + 0x70);
      plVar15 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_70 = 0x65;
      local_78 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e85a060;
    }
    local_80 = *(undefined8 *)(param_1 + 0x60);
    plVar11 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    local_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar14 = *plVar14 + -1;
    plVar16 = (longlong *)0x0;
    if (*plVar14 == 0) {
      plVar15 = (longlong *)0x0;
      (**(code **)(plVar14[1] + 0x30))(plVar14);
      local_70 = 100;
      goto LAB_23e85a060;
    }
  }
  plVar16 = (longlong *)0x0;
  plVar15 = (longlong *)0x0;
  local_70 = 100;
LAB_23e85a060:
  plVar10 = DAT_23ed6a4f8;
  if (plVar11 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar11 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar11;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar8 = _PyRuntime_exref;
    plVar10[2] = 0;
    plVar10[3] = (longlong)plVar7;
    *plVar7 = *plVar7 + 1;
    lVar9 = *(longlong *)(pcVar8 + 0x1f8);
    *(undefined4 *)((longlong)plVar10 + 0x24) = local_70;
    lVar9 = *(longlong *)(lVar9 + 0x10);
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar9 = *(longlong *)(lVar9 + 0x2e8);
    lVar4 = plVar10[-1];
    puVar6 = *(undefined8 **)(lVar9 + 8);
    *puVar6 = plVar10 + -2;
    plVar10[-2] = lVar9;
    plVar10[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar9 + 8) = plVar10 + -2;
    plVar14 = plVar10;
  }
  else {
    plVar14 = plVar11;
    if ((longlong *)plVar11[3] != plVar7) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar14 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar14;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar10[3] = (longlong)plVar7;
      *plVar7 = *plVar7 + 1;
      *(undefined4 *)((longlong)plVar10 + 0x24) = local_70;
      pcVar8 = _PyRuntime_exref;
      *(undefined4 *)(plVar10 + 4) = 0xffffffff;
      lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar8 + 0x1f8) + 0x10) + 0x2e8);
      lVar4 = plVar10[-1];
      puVar6 = *(undefined8 **)(lVar9 + 8);
      *puVar6 = plVar10 + -2;
      plVar10[-2] = lVar9;
      plVar10[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
      lVar4 = *plVar11;
      *(longlong **)(lVar9 + 8) = plVar10 + -2;
      plVar10[2] = (longlong)plVar11;
      plVar14 = plVar10;
      if (lVar4 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
    }
  }
  FUN_23e8bba40(plVar7,"ooooooo",plVar2,plVar1,plVar3,plVar12,plVar13,plVar16,plVar15);
  if (DAT_23eede2a0 == plVar7) {
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    DAT_23eede2a0 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar11 = *(longlong **)(lVar9 + 0x28);
  plVar7 = (longlong *)plVar11[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
  *(undefined4 *)(plVar11 + 8) = 0xffffffff;
  if (plVar7 != (longlong *)0x0) {
    plVar11[2] = 0;
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))();
    }
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  plVar11[0xf] = 0;
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  lVar9 = *plVar1;
  *plVar1 = lVar9 + -1;
  if (lVar9 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  lVar9 = *plVar3;
  *plVar3 = lVar9 + -1;
  if (lVar9 + -1 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  FUN_23a33aa70(param_1,local_80,local_78,plVar14);
  return (longlong *)0x0;
}
