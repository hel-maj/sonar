/* ===== 23e6f9e00 workers.fishing.casting_a_fishin:172 ===== */
/* ghidra_name=FUN_23e6f9e00 entry=23e6f9e00 size=15004 */

longlong * FUN_23e6f9e00(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  code *pcVar5;
  code *pcVar6;
  undefined1 auVar7 [16];
  longlong *plVar8;
  char cVar9;
  int iVar10;
  longlong lVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  undefined8 uVar16;
  longlong *plVar17;
  longlong *plVar18;
  undefined8 uVar19;
  longlong *plVar20;
  longlong lVar21;
  undefined4 uVar22;
  longlong lVar23;
  longlong lVar24;
  bool bVar25;
  undefined8 in_stack_fffffffffffffea8;
  longlong *local_108;
  longlong *local_100;
  longlong *local_f8;
  longlong *local_e8;
  undefined1 local_c8 [16];
  longlong *local_b8;
  longlong *local_a8;
  longlong *plStack_a0;
  longlong *local_98;
  longlong *local_90;
  longlong *local_88;
  
  plVar12 = DAT_23eedb1d0;
  uVar22 = (undefined4)((ulonglong)in_stack_fffffffffffffea8 >> 0x20);
  plVar1 = (longlong *)param_3[1];
  plVar2 = (longlong *)*param_3;
  local_b8 = (longlong *)0x0;
  local_c8 = (undefined1  [16])0x0;
  if (DAT_23eedb1d0 == (longlong *)0x0) {
LAB_23e6f9e7a:
    DAT_23eedb1d0 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedb1c8,DAT_23eedb268);
  }
  else {
    lVar11 = *DAT_23eedb1d0;
    if (1 < lVar11) {
      *DAT_23eedb1d0 = lVar11 + -1;
      goto LAB_23e6f9e7a;
    }
    if (DAT_23eedb1d0[2] != 0) {
      *DAT_23eedb1d0 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      goto LAB_23e6f9e7a;
    }
  }
  plVar4 = DAT_23eedb1d0;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar12 = DAT_23eedb1d0 + 9;
  lVar21 = *(longlong *)(lVar11 + 8);
  DAT_23eedb1d0[0xf] = lVar21;
  *(longlong **)(lVar11 + 8) = plVar12;
  if ((lVar21 != 0) &&
     (((*(char *)(lVar21 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar21 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar21 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar21 + 0x38))) && (plVar4[0xe] != 0)))) {
    plVar12 = *(longlong **)(lVar21 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar12;
    if (plVar12 != (longlong *)0x0) {
      *plVar12 = *plVar12 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  *(undefined4 *)(plVar4 + 8) = 0;
  lVar11 = FUN_23e8e19b0();
  if (lVar11 == 0) {
    FUN_23e915740(param_1,local_c8,DAT_23eeda520);
    plVar12 = (longlong *)0x0;
  }
  else {
    *(undefined4 *)(plVar4 + 5) = 0xae;
    plVar12 = (longlong *)FUN_23e91bfe0(param_1,lVar11);
    if (plVar12 != (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda518);
      if (plVar13 == (longlong *)0x0) {
        local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_b8 = *(longlong **)(param_1 + 0x70);
        plVar15 = (longlong *)0x0;
        plVar17 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar14 = (longlong *)0x0;
        uVar22 = 0xb1;
        local_e8 = (longlong *)0x0;
        local_f8 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar13 = (longlong *)0x0;
        goto LAB_23e6fa01d;
      }
      local_a8 = plVar13;
      if ((code *)plVar13[1] == PyLong_Type_exref) {
        lVar11 = plVar13[2];
        lVar21 = *plVar13;
        lVar23 = *(longlong *)(DAT_23ed6ccf8 + 0x10);
        if (lVar11 < 0) {
          if (lVar11 == -1 || -lVar11 < 1) {
            if (lVar23 < 0) {
              lVar24 = -lVar23;
              if (lVar23 == -1 || lVar24 < 1) {
                iVar10 = -(int)plVar13[3];
                goto LAB_23e6fbbd2;
              }
              if (lVar21 != 1) goto LAB_23e6fb0cd;
LAB_23e6fb10e:
              plVar14 = (longlong *)FUN_23e8be680(plVar13,DAT_23ed6ccf8 + 0x18,lVar24);
              lVar11 = -plVar14[2];
              if (-1 < lVar11) {
                lVar11 = plVar14[2];
              }
              plVar14[2] = lVar11;
              goto LAB_23e6fa3f8;
            }
            if (lVar23 < 2) {
              iVar10 = -(int)plVar13[3];
              goto LAB_23e6fb142;
            }
            if (lVar21 == 1) goto LAB_23e6fbdd9;
          }
          else {
            lVar24 = -lVar23;
            if (-lVar23 < 0) {
              lVar24 = lVar23;
            }
            if (lVar21 == 1) {
              bVar25 = -1 < lVar23;
              lVar23 = lVar24;
              if (bVar25) {
LAB_23e6fbdd9:
                plVar14 = (longlong *)FUN_23e8beb80(plVar13,DAT_23ed6ccf8 + 0x18,lVar23);
                goto LAB_23e6fa3f8;
              }
              goto LAB_23e6fb10e;
            }
            bVar25 = lVar23 < 0;
            lVar23 = lVar24;
            if (bVar25) {
LAB_23e6fb0cd:
              plVar14 = (longlong *)FUN_23e8be550(plVar13 + 3,-lVar11,DAT_23ed6ccf8 + 0x18);
              plVar14[2] = -plVar14[2];
              goto LAB_23e6fb04c;
            }
          }
          plVar14 = (longlong *)FUN_23e8be900(DAT_23ed6ccf8 + 0x18,lVar23,plVar13 + 3);
        }
        else if (lVar11 < 2) {
          if (lVar23 < 0) {
            lVar24 = -lVar23;
            if (lVar23 != -1 && 0 < lVar24) {
              if (lVar21 == 1) goto LAB_23e6fbe05;
LAB_23e6fb222:
              plVar14 = (longlong *)FUN_23e8be900(plVar13 + 3,lVar11,DAT_23ed6ccf8 + 0x18);
              goto LAB_23e6fb04c;
            }
            iVar10 = 0;
            if (lVar11 != 0) {
              iVar10 = (int)plVar13[3];
            }
LAB_23e6fbbd2:
            iVar10 = iVar10 - *(int *)(DAT_23ed6ccf8 + 0x18);
          }
          else {
            if (1 < lVar23) {
              if (lVar21 == 1) goto LAB_23e6fbc8d;
              goto LAB_23e6fb035;
            }
            iVar10 = 0;
            if (lVar11 != 0) {
              iVar10 = (int)plVar13[3];
            }
LAB_23e6fb142:
            if (lVar23 != 0) {
              iVar10 = iVar10 + *(int *)(DAT_23ed6ccf8 + 0x18);
            }
          }
          if (lVar21 == 1) {
            FUN_23e8be320(&local_a8,iVar10);
            plVar14 = local_a8;
            goto LAB_23e6fa3f8;
          }
          plVar14 = (longlong *)FUN_23e8bb5f0();
        }
        else {
          lVar24 = -lVar23;
          if (-lVar23 < 0) {
            lVar24 = lVar23;
          }
          if (lVar21 == 1) {
            bVar25 = lVar23 < 0;
            lVar23 = lVar24;
            if (bVar25) {
LAB_23e6fbe05:
              plVar14 = (longlong *)FUN_23e8beb80(plVar13,DAT_23ed6ccf8 + 0x18,lVar24);
            }
            else {
LAB_23e6fbc8d:
              plVar14 = (longlong *)FUN_23e8be680(plVar13,DAT_23ed6ccf8 + 0x18,lVar23);
            }
            goto LAB_23e6fa3f8;
          }
          if (lVar23 < 0) goto LAB_23e6fb222;
LAB_23e6fb035:
          plVar14 = (longlong *)FUN_23e8be550(plVar13 + 3,lVar11,DAT_23ed6ccf8 + 0x18);
          if (plVar14 == (longlong *)0x0) goto LAB_23e6f9f87;
        }
LAB_23e6fb04c:
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
LAB_23e6fa3f8:
        plVar13 = plVar14;
        cVar9 = FUN_23e8d9ac0(plVar2,DAT_23eeda518,plVar13);
        if (cVar9 == '\0') {
          uVar19 = *(undefined8 *)(param_1 + 0x60);
          uVar16 = *(undefined8 *)(param_1 + 0x68);
          plVar14 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e6f9fa0;
        }
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda528);
        if (plVar13 == (longlong *)0x0) {
          local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_b8 = *(longlong **)(param_1 + 0x70);
          plVar15 = (longlong *)0x0;
          plVar17 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar14 = (longlong *)0x0;
          uVar22 = 0xb2;
          local_e8 = (longlong *)0x0;
          local_f8 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar13 = (longlong *)0x0;
          goto LAB_23e6fa01d;
        }
        plVar14 = (longlong *)FUN_23e8c6640(plVar12,plVar13);
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        if (plVar14 == (longlong *)0x0) {
          local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_b8 = *(longlong **)(param_1 + 0x70);
          plVar15 = (longlong *)0x0;
          plVar17 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar13 = (longlong *)0x0;
          uVar22 = 0xb2;
          local_e8 = (longlong *)0x0;
          local_f8 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar14 = (longlong *)0x0;
          goto LAB_23e6fa01d;
        }
        iVar10 = FUN_23e97d950(plVar14,DAT_23ed6cd18);
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        if (iVar10 == -1) {
          local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_b8 = *(longlong **)(param_1 + 0x70);
          uVar22 = 0xb2;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        }
        else {
          if (iVar10 == 1) {
            plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda518);
            if (plVar13 == (longlong *)0x0) {
              local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_b8 = *(longlong **)(param_1 + 0x70);
              plVar15 = (longlong *)0x0;
              plVar14 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar13 = (longlong *)0x0;
              uVar22 = 0xb3;
              local_e8 = (longlong *)0x0;
              local_f8 = (longlong *)0x0;
              local_100 = (longlong *)0x0;
              local_108 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar17 = (longlong *)0x0;
              goto LAB_23e6fa01d;
            }
            plVar14 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda528);
            if (plVar14 == (longlong *)0x0) {
              local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_b8 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
            }
            else {
              plVar17 = (longlong *)FUN_23e8c6640(plVar12,plVar14);
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              if (plVar17 == (longlong *)0x0) {
                local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_b8 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                local_100 = (longlong *)0x0;
                plVar15 = (longlong *)0x0;
                plVar17 = (longlong *)0x0;
                plVar13 = (longlong *)0x0;
                local_108 = (longlong *)0x0;
                uVar22 = 0xb3;
                local_e8 = (longlong *)0x0;
                local_f8 = (longlong *)0x0;
                plVar14 = (longlong *)0x0;
                goto LAB_23e6fa01d;
              }
              plVar14 = (longlong *)FUN_23e8c6f80(plVar13,plVar17);
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              *plVar17 = *plVar17 + -1;
              if (*plVar17 == 0) {
                (**(code **)(plVar17[1] + 0x30))(plVar17);
              }
              if (plVar14 != (longlong *)0x0) {
                cVar9 = FUN_23e8d9ac0(plVar2,DAT_23eeda530,plVar14);
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                if (cVar9 == '\0') {
                  local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_b8 = *(longlong **)(param_1 + 0x70);
                  uVar22 = 0xb3;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                }
                else {
                  cVar9 = FUN_23e8d9ac0(plVar2,DAT_23eeda518,DAT_23ed6ccf0);
                  if (cVar9 == '\0') {
                    local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_b8 = *(longlong **)(param_1 + 0x70);
                    uVar22 = 0xb4;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  else {
                    cVar9 = FUN_23e8d9ac0(plVar2,DAT_23eeda528,plVar12);
                    if (cVar9 != '\0') goto LAB_23e6fa49f;
                    local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_b8 = *(longlong **)(param_1 + 0x70);
                    uVar22 = 0xb5;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                }
                goto LAB_23e6f9fe8;
              }
              local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_b8 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            plVar13 = (longlong *)0x0;
            local_100 = (longlong *)0x0;
            plVar15 = (longlong *)0x0;
            plVar17 = (longlong *)0x0;
            plVar14 = (longlong *)0x0;
            local_108 = (longlong *)0x0;
            uVar22 = 0xb3;
            local_e8 = (longlong *)0x0;
            local_f8 = (longlong *)0x0;
            goto LAB_23e6fa01d;
          }
LAB_23e6fa49f:
          plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda4e8);
          if (plVar13 == (longlong *)0x0) {
            local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
            local_b8 = *(longlong **)(param_1 + 0x70);
            plVar15 = (longlong *)0x0;
            plVar17 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar13 = (longlong *)0x0;
            uVar22 = 0xb8;
            local_e8 = (longlong *)0x0;
            local_f8 = (longlong *)0x0;
            local_100 = (longlong *)0x0;
            local_108 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar14 = (longlong *)0x0;
            goto LAB_23e6fa01d;
          }
          plVar14 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda580);
          if (plVar14 == (longlong *)0x0) {
            local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
            local_b8 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            local_100 = (longlong *)0x0;
            plVar15 = (longlong *)0x0;
            plVar17 = (longlong *)0x0;
            plVar14 = (longlong *)0x0;
            local_108 = (longlong *)0x0;
            uVar22 = 0xb8;
            local_e8 = (longlong *)0x0;
            local_f8 = (longlong *)0x0;
            plVar13 = (longlong *)0x0;
            goto LAB_23e6fa01d;
          }
          iVar10 = FUN_23e912620(plVar13,plVar14);
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          pcVar5 = _Py_FalseStruct_exref;
          if (iVar10 == -1) {
            local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
            local_b8 = *(longlong **)(param_1 + 0x70);
            uVar22 = 0xb8;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e6f9fe8;
          }
          if (iVar10 == 1) {
            plVar14 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda500);
            if (plVar14 == (longlong *)0x0) {
              local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_b8 = *(longlong **)(param_1 + 0x70);
              plVar15 = (longlong *)0x0;
              plVar17 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar13 = (longlong *)0x0;
              uVar22 = 0xb9;
              local_e8 = (longlong *)0x0;
              local_f8 = (longlong *)0x0;
              local_100 = (longlong *)0x0;
              local_108 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar14 = (longlong *)0x0;
              goto LAB_23e6fa01d;
            }
            plVar13 = (longlong *)FUN_23e8c6640(plVar14,plVar12);
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            if (plVar13 == (longlong *)0x0) {
              local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_b8 = *(longlong **)(param_1 + 0x70);
              plVar15 = (longlong *)0x0;
              plVar17 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar14 = (longlong *)0x0;
              uVar22 = 0xb9;
              local_e8 = (longlong *)0x0;
              local_f8 = (longlong *)0x0;
              local_100 = (longlong *)0x0;
              local_108 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e6fa01d;
            }
            iVar10 = FUN_23e97b760(plVar13,DAT_23ed6ccf0);
            if (iVar10 == -1) {
              local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_b8 = *(longlong **)(param_1 + 0x70);
              uVar22 = 0xba;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            else if (iVar10 == 1) {
              plVar14 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda4e0);
              if (plVar14 == (longlong *)0x0) {
                local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_b8 = *(longlong **)(param_1 + 0x70);
                plVar15 = (longlong *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                plVar17 = (longlong *)0x0;
                local_e8 = (longlong *)0x0;
                local_f8 = (longlong *)0x0;
                local_100 = (longlong *)0x0;
                local_108 = (longlong *)0x0;
                uVar22 = 0xbb;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar14 = (longlong *)0x0;
                goto LAB_23e6fa01d;
              }
              cVar9 = FUN_23e8d9ac0(plVar2,DAT_23eeda4e8,plVar14);
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              if (cVar9 == '\0') {
                local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_b8 = *(longlong **)(param_1 + 0x70);
                uVar22 = 0xbb;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              else {
                cVar9 = FUN_23e8d9ac0(plVar2,DAT_23eeda4f0);
                if (cVar9 == '\0') {
                  local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_b8 = *(longlong **)(param_1 + 0x70);
                  uVar22 = 0xbc;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                }
                else {
                  cVar9 = FUN_23e8d9ac0(plVar2,DAT_23eeda4f8,DAT_23ed6ccf0);
                  if (cVar9 == '\0') {
                    local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_b8 = *(longlong **)(param_1 + 0x70);
                    uVar22 = 0xbd;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  else {
                    cVar9 = FUN_23e8d9ac0(plVar2,DAT_23eeda508,DAT_23ed6cd08);
                    if (cVar9 == '\0') {
                      local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_b8 = *(longlong **)(param_1 + 0x70);
                      uVar22 = 0xbe;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    }
                    else {
                      cVar9 = FUN_23e8d9ac0(plVar2,DAT_23eeda510,pcVar5);
                      if (cVar9 != '\0') goto LAB_23e6fb441;
                      local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_b8 = *(longlong **)(param_1 + 0x70);
                      uVar22 = 0xbf;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    }
                  }
                }
              }
            }
            else {
LAB_23e6fb441:
              plVar14 = DAT_23ed6ccf0;
              lVar11 = *(longlong *)(param_1 + 0x10);
              plVar18 = *(longlong **)(lVar11 + 0xe48);
              if (plVar18 == (longlong *)0x0) {
                plVar18 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,7);
                plVar17 = DAT_23ed6ccf0;
              }
              else {
                lVar21 = plVar18[3];
                *(int *)(lVar11 + 0xed0) = *(int *)(lVar11 + 0xed0) + -1;
                *(longlong *)(lVar11 + 0xe48) = lVar21;
                *plVar18 = 1;
                plVar17 = plVar14;
              }
              pcVar6 = _PyRuntime_exref;
              *(undefined1 (*) [16])(plVar18 + 8) = (undefined1  [16])0x0;
              lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10) + 0x2e8);
              lVar21 = plVar18[-1];
              puVar3 = *(undefined8 **)(lVar11 + 8);
              *puVar3 = plVar18 + -2;
              plVar18[-2] = lVar11;
              plVar18[-1] = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar3;
              *(longlong **)(lVar11 + 8) = plVar18 + -2;
              *plVar14 = *plVar14 + 1;
              plVar18[3] = (longlong)plVar14;
              *plVar17 = *plVar17 + 1;
              plVar18[4] = (longlong)plVar17;
              plVar14 = DAT_23ed6cd00;
              *DAT_23ed6cd00 = *DAT_23ed6cd00 + 1;
              plVar18[5] = (longlong)plVar14;
              plVar18[6] = (longlong)pcVar5;
              plVar18[7] = (longlong)pcVar5;
              uVar19 = DAT_23eeda530;
              *(longlong *)pcVar5 = *(longlong *)pcVar5 + 2;
              lVar11 = FUN_23e8bc2f0(plVar2,uVar19);
              if (lVar11 != 0) {
                plVar18[8] = lVar11;
                uVar19 = FUN_23a3a0d40(DAT_23eeda588);
                plVar14 = DAT_23ed6ccf0;
                plVar17 = (longlong *)PyNumber_Long(plVar13);
                if (plVar17 != (longlong *)0x0) {
                  *(undefined4 *)(plVar4 + 5) = 0xc0;
                  local_a8 = plVar14;
                  plStack_a0 = plVar17;
                  lVar11 = FUN_23e94ed00(param_1,uVar19,&local_a8);
                  *plVar17 = *plVar17 + -1;
                  if (*plVar17 == 0) {
                    (**(code **)(plVar17[1] + 0x30))(plVar17);
                  }
                  if (lVar11 != 0) {
                    plVar18[9] = lVar11;
                    plVar15 = (longlong *)0x0;
                    plVar17 = (longlong *)0x0;
                    plVar14 = (longlong *)0x0;
                    local_e8 = (longlong *)0x0;
                    local_f8 = (longlong *)0x0;
                    local_100 = (longlong *)0x0;
                    local_108 = (longlong *)0x0;
                    goto LAB_23e6fab80;
                  }
                }
              }
              local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_b8 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar18 = *plVar18 + -1;
              if (*plVar18 == 0) {
                (**(code **)(plVar18[1] + 0x30))(plVar18);
                uVar22 = 0xc0;
              }
              else {
                uVar22 = 0xc0;
              }
            }
            local_100 = (longlong *)0x0;
            plVar15 = (longlong *)0x0;
            plVar17 = (longlong *)0x0;
            plVar14 = (longlong *)0x0;
            local_e8 = (longlong *)0x0;
            local_f8 = (longlong *)0x0;
            local_108 = (longlong *)0x0;
            goto LAB_23e6fa01d;
          }
          plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda4e8);
          if (plVar13 == (longlong *)0x0) {
            local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
            local_b8 = *(longlong **)(param_1 + 0x70);
            plVar15 = (longlong *)0x0;
            plVar17 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar13 = (longlong *)0x0;
            uVar22 = 0xc3;
            local_e8 = (longlong *)0x0;
            local_f8 = (longlong *)0x0;
            local_100 = (longlong *)0x0;
            local_108 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar14 = (longlong *)0x0;
            goto LAB_23e6fa01d;
          }
          plVar14 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda4e0);
          if (plVar14 == (longlong *)0x0) {
            local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
            local_b8 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            local_100 = (longlong *)0x0;
            plVar15 = (longlong *)0x0;
            plVar17 = (longlong *)0x0;
            plVar14 = (longlong *)0x0;
            local_108 = (longlong *)0x0;
            uVar22 = 0xc3;
            local_e8 = (longlong *)0x0;
            local_f8 = (longlong *)0x0;
            plVar13 = (longlong *)0x0;
            goto LAB_23e6fa01d;
          }
          iVar10 = FUN_23e912620(plVar13,plVar14);
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (iVar10 == -1) {
            local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
            local_b8 = *(longlong **)(param_1 + 0x70);
            uVar22 = 0xc3;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e6f9fe8;
          }
          if (iVar10 == 1) {
            plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda590);
            if (plVar13 == (longlong *)0x0) {
              local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_b8 = *(longlong **)(param_1 + 0x70);
              plVar15 = (longlong *)0x0;
              plVar14 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar13 = (longlong *)0x0;
              uVar22 = 0xc4;
              local_e8 = (longlong *)0x0;
              local_f8 = (longlong *)0x0;
              local_100 = (longlong *)0x0;
              local_108 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar17 = (longlong *)0x0;
              goto LAB_23e6fa01d;
            }
            plVar17 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda4a8);
            if (plVar17 == (longlong *)0x0) {
              local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_b8 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              local_100 = (longlong *)0x0;
              plVar15 = (longlong *)0x0;
              plVar17 = (longlong *)0x0;
              plVar14 = (longlong *)0x0;
              local_108 = (longlong *)0x0;
              uVar22 = 0xc4;
              local_e8 = (longlong *)0x0;
              local_f8 = (longlong *)0x0;
              plVar13 = (longlong *)0x0;
              goto LAB_23e6fa01d;
            }
            plVar15 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda4b0);
            if (plVar15 == (longlong *)0x0) {
              local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_b8 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                FUN_23a334bc0(plVar13);
              }
              *plVar17 = *plVar17 + -1;
              if (*plVar17 == 0) {
                FUN_23a334bc0(plVar17);
              }
              local_100 = (longlong *)0x0;
              plVar17 = (longlong *)0x0;
              plVar14 = (longlong *)0x0;
              local_e8 = (longlong *)0x0;
              plVar13 = (longlong *)0x0;
              uVar22 = 0xc4;
              local_f8 = (longlong *)0x0;
              local_108 = (longlong *)0x0;
              plVar15 = (longlong *)0x0;
              goto LAB_23e6fa01d;
            }
            plVar18 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda4b8);
            if (plVar18 == (longlong *)0x0) {
              local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_b8 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                FUN_23a334bc0(plVar13);
              }
              *plVar17 = *plVar17 + -1;
              if (*plVar17 == 0) {
                FUN_23a334bc0(plVar17);
              }
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                FUN_23a334bc0(plVar15);
              }
            }
            else {
              plVar20 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda4c0);
              if (plVar20 != (longlong *)0x0) {
                *(undefined4 *)(plVar4 + 5) = 0xc4;
                local_a8 = plVar1;
                plStack_a0 = plVar17;
                local_98 = plVar15;
                local_90 = plVar18;
                local_88 = plVar20;
                plVar14 = (longlong *)FUN_23e95b390(param_1,plVar13,&local_a8);
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                *plVar17 = *plVar17 + -1;
                if (*plVar17 == 0) {
                  (**(code **)(plVar17[1] + 0x30))(plVar17);
                }
                *plVar15 = *plVar15 + -1;
                if (*plVar15 == 0) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                lVar11 = *plVar18;
                *plVar18 = lVar11 + -1;
                if (lVar11 + -1 == 0) {
                  (**(code **)(plVar18[1] + 0x30))(plVar18);
                }
                lVar11 = *plVar20;
                *plVar20 = lVar11 + -1;
                if (lVar11 + -1 == 0) {
                  (**(code **)(plVar20[1] + 0x30))(plVar20);
                }
                if (plVar14 == (longlong *)0x0) {
                  local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_b8 = *(longlong **)(param_1 + 0x70);
                  plVar15 = (longlong *)0x0;
                  plVar17 = (longlong *)0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  plVar13 = (longlong *)0x0;
                  uVar22 = 0xc4;
                  local_e8 = (longlong *)0x0;
                  local_f8 = (longlong *)0x0;
                  local_100 = (longlong *)0x0;
                  local_108 = (longlong *)0x0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e6fa01d;
                }
                plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda598);
                if (plVar13 == (longlong *)0x0) {
                  local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_b8 = *(longlong **)(param_1 + 0x70);
                  plVar15 = (longlong *)0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  plVar17 = (longlong *)0x0;
                  uVar22 = 0xc5;
                  local_e8 = (longlong *)0x0;
                  local_f8 = (longlong *)0x0;
                  local_100 = (longlong *)0x0;
                  local_108 = (longlong *)0x0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar13 = (longlong *)0x0;
                  goto LAB_23e6fa01d;
                }
                iVar10 = FUN_23e97d0c0(plVar14,plVar13);
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                if (iVar10 == -1) {
                  local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_b8 = *(longlong **)(param_1 + 0x70);
                  plVar15 = (longlong *)0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar22 = 0xc5;
                  plVar17 = (longlong *)0x0;
                  plVar13 = (longlong *)0x0;
                  local_e8 = (longlong *)0x0;
                  local_f8 = (longlong *)0x0;
                  local_100 = (longlong *)0x0;
                  local_108 = (longlong *)0x0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e6fa01d;
                }
                if (iVar10 == 1) {
                  *(undefined4 *)(plVar4 + 5) = 0xc6;
                  plVar17 = (longlong *)FUN_23e915840(param_1,plVar2,DAT_23eeda5a0,plVar1);
                  if (plVar17 == (longlong *)0x0) {
                    local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_b8 = *(longlong **)(param_1 + 0x70);
                    plVar13 = (longlong *)0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar22 = 0xc6;
                    local_e8 = (longlong *)0x0;
                    local_f8 = (longlong *)0x0;
                    local_100 = (longlong *)0x0;
                    local_108 = (longlong *)0x0;
                    plVar15 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e6fa01d;
                  }
                  iVar10 = FUN_23a35f020(plVar17);
                  if (iVar10 == -1) {
                    local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_b8 = *(longlong **)(param_1 + 0x70);
                    uVar22 = 199;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  else {
                    if (iVar10 == 0) {
                      plVar15 = (longlong *)0x0;
                      local_f8 = (longlong *)0x0;
                      local_100 = (longlong *)0x0;
                      local_108 = (longlong *)0x0;
                      goto LAB_23e6fb947;
                    }
                    cVar9 = FUN_23e8d9ac0(plVar2,DAT_23eeda4f0);
                    if (cVar9 == '\0') {
                      local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_b8 = *(longlong **)(param_1 + 0x70);
                      uVar22 = 200;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    }
                    else {
                      plVar13 = (longlong *)FUN_23a388310(plVar17);
                      if (plVar13 == (longlong *)0x0) {
                        uVar19 = *(undefined8 *)(param_1 + 0x60);
                        uVar16 = *(undefined8 *)(param_1 + 0x68);
                        plVar18 = *(longlong **)(param_1 + 0x70);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                      }
                      else {
                        plVar15 = (longlong *)
                                  FUN_23a3c1d30(param_1,local_c8,plVar13,0,CONCAT44(uVar22,4));
                        if (plVar15 == (longlong *)0x0) {
                          local_f8 = (longlong *)0x0;
                          local_100 = (longlong *)0x0;
                          local_108 = (longlong *)0x0;
                        }
                        else {
                          local_108 = (longlong *)FUN_23a3c1d30(param_1,local_c8,plVar13,1,4);
                          if (local_108 == (longlong *)0x0) {
                            local_f8 = (longlong *)0x0;
                            local_100 = (longlong *)0x0;
                          }
                          else {
                            local_100 = (longlong *)FUN_23a3c1d30(param_1,local_c8,plVar13,2,4);
                            if (local_100 == (longlong *)0x0) {
                              local_f8 = (longlong *)0x0;
                            }
                            else {
                              local_f8 = (longlong *)FUN_23a3c1d30(param_1,local_c8,plVar13,3,4);
                              if ((local_f8 != (longlong *)0x0) &&
                                 (cVar9 = FUN_23a3884a0(param_1,local_c8,plVar13,4), cVar9 != '\0'))
                              {
                                *plVar13 = *plVar13 + -1;
                                if (*plVar13 == 0) {
                                  FUN_23a334bc0(plVar13);
                                }
                                if (*plVar15 == 0) {
                                  FUN_23a334bc0(plVar15);
                                }
                                if (*local_108 == 0) {
                                  FUN_23a334bc0(local_108);
                                }
                                if (*local_100 == 0) {
                                  FUN_23a334bc0(local_100);
                                }
                                if (*local_f8 == 0) {
                                  FUN_23a334bc0(local_f8);
                                }
                                *(undefined4 *)(plVar4 + 5) = 0xca;
                                local_a8 = plVar1;
                                plStack_a0 = plVar15;
                                local_98 = local_108;
                                local_90 = local_100;
                                local_88 = local_f8;
                                plVar13 = (longlong *)
                                          FUN_23e9694c0(param_1,plVar2,DAT_23eeda590,&local_a8);
                                if (plVar13 == (longlong *)0x0) {
                                  local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  local_b8 = *(longlong **)(param_1 + 0x70);
                                  uVar22 = 0xca;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  local_e8 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  plVar13 = (longlong *)0x0;
                                  goto LAB_23e6fa01d;
                                }
                                cVar9 = FUN_23e8d9ac0(plVar2,DAT_23eeda4f8,plVar13);
                                *plVar13 = *plVar13 + -1;
                                if (*plVar13 == 0) {
                                  FUN_23a334bc0(plVar13);
                                }
                                if (cVar9 == '\0') {
                                  local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  local_b8 = *(longlong **)(param_1 + 0x70);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  uVar22 = 0xca;
                                  plVar13 = (longlong *)0x0;
                                  local_e8 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  goto LAB_23e6fa01d;
                                }
                                plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda5a8);
                                if (plVar13 == (longlong *)0x0) {
                                  local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  local_b8 = *(longlong **)(param_1 + 0x70);
                                  uVar22 = 0xcb;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  local_e8 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  plVar13 = (longlong *)0x0;
                                  goto LAB_23e6fa01d;
                                }
                                cVar9 = FUN_23e8d9ac0(plVar2,DAT_23eeda4e8);
                                *plVar13 = *plVar13 + -1;
                                if (*plVar13 == 0) {
                                  FUN_23a334bc0(plVar13);
                                }
                                if (cVar9 == '\0') {
                                  local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  local_b8 = *(longlong **)(param_1 + 0x70);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  uVar22 = 0xcb;
                                  plVar13 = (longlong *)0x0;
                                  local_e8 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  goto LAB_23e6fa01d;
                                }
                                lVar21 = FUN_23e8e1b00();
                                lVar11 = DAT_23eeda5b8;
                                if (lVar21 == 0) {
                                  FUN_23e915740(param_1,local_c8,DAT_23eeda4c8);
                                  uVar22 = 0xcc;
                                  local_e8 = (longlong *)0x0;
                                  plVar13 = (longlong *)0x0;
                                  goto LAB_23e6fa01d;
                                }
                                *(undefined4 *)(plVar4 + 5) = 0xcc;
                                plVar13 = (longlong *)
                                          FUN_23e915840(param_1,lVar21,DAT_23eeda5b0,
                                                        *(undefined8 *)(lVar11 + 0x18));
                                if (plVar13 == (longlong *)0x0) {
                                  local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  local_b8 = *(longlong **)(param_1 + 0x70);
                                  uVar22 = 0xcc;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  local_e8 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  plVar13 = (longlong *)0x0;
                                  goto LAB_23e6fa01d;
                                }
                                *plVar13 = *plVar13 + -1;
                                if (*plVar13 == 0) {
                                  FUN_23a334bc0(plVar13);
                                }
                                cVar9 = FUN_23e8d9ac0(plVar2,DAT_23eeda510,_Py_TrueStruct_exref);
                                if (cVar9 == '\0') {
                                  local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  local_b8 = *(longlong **)(param_1 + 0x70);
                                  plVar13 = (longlong *)0x0;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  uVar22 = 0xcd;
                                  local_e8 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  goto LAB_23e6fa01d;
                                }
                                cVar9 = FUN_23e8d9ac0(plVar2,DAT_23eeda508,plVar12);
                                if (cVar9 == '\0') {
                                  local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  local_b8 = *(longlong **)(param_1 + 0x70);
                                  plVar13 = (longlong *)0x0;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  uVar22 = 0xce;
                                  local_e8 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  goto LAB_23e6fa01d;
                                }
                                uVar16 = FUN_23a3a0d40(DAT_23ed6cf28);
                                plVar13 = DAT_23eeda5c0;
                                plVar18 = (longlong *)
                                          FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),5);
                                *plVar13 = *plVar13 + 1;
                                uVar19 = DAT_23eeda4f8;
                                plVar18[3] = (longlong)plVar13;
                                plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,uVar19);
                                if (plVar13 != (longlong *)0x0) {
                                  lVar11 = FUN_23e94f9d0(param_1,plVar13,DAT_23ed6cd28);
                                  *plVar13 = *plVar13 + -1;
                                  if (*plVar13 == 0) {
                                    FUN_23a334bc0();
                                  }
                                  if (lVar11 != 0) {
                                    plVar18[4] = lVar11;
                                    uVar19 = DAT_23eeda5d0;
                                    plVar13 = DAT_23eeda5c8;
                                    *DAT_23eeda5c8 = *DAT_23eeda5c8 + 1;
                                    plVar18[5] = (longlong)plVar13;
                                    plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,uVar19);
                                    if (plVar13 != (longlong *)0x0) {
                                      lVar11 = FUN_23e94f9d0(param_1,plVar13,DAT_23eeda5d8);
                                      *plVar13 = *plVar13 + -1;
                                      if (*plVar13 == 0) {
                                        FUN_23a334bc0();
                                      }
                                      if (lVar11 != 0) {
                                        plVar18[6] = lVar11;
                                        plVar13 = DAT_23eeda5e0;
                                        *DAT_23eeda5e0 = *DAT_23eeda5e0 + 1;
                                        plVar18[7] = (longlong)plVar13;
                                        plVar13 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar18);
                                        *plVar18 = *plVar18 + -1;
                                        if (*plVar18 == 0) {
                                          FUN_23a334bc0(plVar18);
                                        }
                                        if (plVar13 == (longlong *)0x0) {
                                          local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          local_b8 = *(longlong **)(param_1 + 0x70);
                                          uVar22 = 0xcf;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          local_e8 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          plVar13 = (longlong *)0x0;
                                          goto LAB_23e6fa01d;
                                        }
                                        *(undefined4 *)(plVar4 + 5) = 0xcf;
                                        plVar18 = (longlong *)FUN_23e914090(param_1,uVar16,plVar13);
                                        *plVar13 = *plVar13 + -1;
                                        if (*plVar13 == 0) {
                                          FUN_23a334bc0(plVar13);
                                        }
                                        if (plVar18 == (longlong *)0x0) {
                                          local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          local_b8 = *(longlong **)(param_1 + 0x70);
                                          plVar13 = (longlong *)0x0;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          uVar22 = 0xcf;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          local_e8 = (longlong *)0x0;
                                          goto LAB_23e6fa01d;
                                        }
                                        lVar11 = *plVar18;
                                        *plVar18 = lVar11 + -1;
                                        if (lVar11 + -1 == 0) {
                                          FUN_23a334bc0(plVar18);
                                        }
                                        goto LAB_23e6fb947;
                                      }
                                    }
                                  }
                                }
                                local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                local_b8 = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *plVar18 = *plVar18 + -1;
                                if (*plVar18 == 0) {
                                  plVar13 = (longlong *)0x0;
                                  FUN_23a334bc0(plVar18);
                                  uVar22 = 0xcf;
                                  local_e8 = (longlong *)0x0;
                                }
                                else {
                                  uVar22 = 0xcf;
                                  plVar13 = (longlong *)0x0;
                                  local_e8 = (longlong *)0x0;
                                }
                                goto LAB_23e6fa01d;
                              }
                            }
                          }
                        }
                        plVar18 = local_b8;
                        uVar19 = local_c8._0_8_;
                        uVar16 = local_c8._8_8_;
                        local_c8 = (undefined1  [16])0x0;
                        local_b8 = (longlong *)0x0;
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          FUN_23a334bc0(plVar13);
                        }
                        local_b8 = (longlong *)0x0;
                        local_c8 = (undefined1  [16])0x0;
                        if ((plVar15 != (longlong *)0x0) &&
                           (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                          FUN_23a334bc0(plVar15);
                        }
                        if ((local_108 != (longlong *)0x0) &&
                           (lVar11 = *local_108, *local_108 = lVar11 + -1, lVar11 + -1 == 0)) {
                          FUN_23a334bc0(local_108);
                        }
                        if ((local_100 != (longlong *)0x0) &&
                           (lVar11 = *local_100, *local_100 = lVar11 + -1, lVar11 + -1 == 0)) {
                          FUN_23a334bc0(local_100);
                        }
                        if ((local_f8 != (longlong *)0x0) &&
                           (lVar11 = *local_f8, *local_f8 = lVar11 + -1, lVar11 + -1 == 0)) {
                          FUN_23a334bc0(local_f8);
                        }
                      }
                      uVar22 = 0xc9;
                      local_c8._8_8_ = uVar16;
                      local_c8._0_8_ = uVar19;
                      local_b8 = plVar18;
                    }
                  }
                  plVar15 = (longlong *)0x0;
                  plVar13 = (longlong *)0x0;
                  local_e8 = (longlong *)0x0;
                  local_f8 = (longlong *)0x0;
                  local_100 = (longlong *)0x0;
                  local_108 = (longlong *)0x0;
                }
                else {
                  local_100 = (longlong *)0x0;
                  plVar15 = (longlong *)0x0;
                  plVar17 = (longlong *)0x0;
                  local_f8 = (longlong *)0x0;
                  local_108 = (longlong *)0x0;
LAB_23e6fb947:
                  lVar11 = *(longlong *)(param_1 + 0x10);
                  plVar18 = *(longlong **)(lVar11 + 0xe48);
                  if (plVar18 == (longlong *)0x0) {
                    plVar18 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,7);
                  }
                  else {
                    lVar21 = plVar18[3];
                    *(int *)(lVar11 + 0xed0) = *(int *)(lVar11 + 0xed0) + -1;
                    *(longlong *)(lVar11 + 0xe48) = lVar21;
                    *plVar18 = 1;
                  }
                  pcVar6 = _PyRuntime_exref;
                  *(undefined1 (*) [16])(plVar18 + 8) = (undefined1  [16])0x0;
                  lVar11 = *(longlong *)
                            (*(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10) + 0x2e8);
                  lVar21 = plVar18[-1];
                  puVar3 = *(undefined8 **)(lVar11 + 8);
                  *puVar3 = plVar18 + -2;
                  plVar18[-2] = lVar11;
                  plVar18[-1] = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar3;
                  lVar21 = *plVar14;
                  *(longlong **)(lVar11 + 8) = plVar18 + -2;
                  plVar18[3] = (longlong)plVar14;
                  *plVar14 = lVar21 + 2;
                  plVar18[4] = (longlong)plVar14;
                  plVar13 = DAT_23ed6cd00;
                  *DAT_23ed6cd00 = *DAT_23ed6cd00 + 1;
                  plVar18[5] = (longlong)plVar13;
                  plVar18[6] = (longlong)pcVar5;
                  plVar18[7] = (longlong)pcVar5;
                  uVar19 = DAT_23eeda530;
                  *(longlong *)pcVar5 = *(longlong *)pcVar5 + 2;
                  lVar11 = FUN_23e8bc2f0(plVar2,uVar19);
                  if (lVar11 != 0) {
                    plVar18[8] = lVar11;
                    plVar4 = DAT_23ed6ccf0;
                    plVar13 = (longlong *)0x0;
                    local_e8 = (longlong *)0x0;
                    *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
                    plVar18[9] = (longlong)plVar4;
LAB_23e6fab80:
                    lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                    plVar4 = *(longlong **)(lVar11 + 0x28);
                    plVar20 = (longlong *)plVar4[2];
                    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                         *(undefined8 *)(lVar11 + 0x30);
                    *(undefined4 *)(plVar4 + 8) = 0xffffffff;
                    if (plVar20 != (longlong *)0x0) {
                      plVar4[2] = 0;
                      *plVar20 = *plVar20 + -1;
                      if (*plVar20 == 0) {
                        (**(code **)(plVar20[1] + 0x30))();
                      }
                    }
                    *plVar4 = *plVar4 + -1;
                    if (*plVar4 == 0) {
                      (**(code **)(plVar4[1] + 0x30))(plVar4);
                    }
                    plVar4[0xf] = 0;
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      (**(code **)(plVar12[1] + 0x30))(plVar12);
                    }
                    if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                    }
                    if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
                      (**(code **)(plVar17[1] + 0x30))(plVar17);
                    }
                    if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                      (**(code **)(plVar15[1] + 0x30))(plVar15);
                    }
                    if ((local_108 != (longlong *)0x0) &&
                       (lVar11 = *local_108, *local_108 = lVar11 + -1, lVar11 + -1 == 0)) {
                      (**(code **)(local_108[1] + 0x30))(local_108);
                    }
                    if ((local_100 != (longlong *)0x0) &&
                       (lVar11 = *local_100, *local_100 = lVar11 + -1, lVar11 + -1 == 0)) {
                      (**(code **)(local_100[1] + 0x30))(local_100);
                    }
                    if ((local_f8 != (longlong *)0x0) &&
                       (lVar11 = *local_f8, *local_f8 = lVar11 + -1, lVar11 + -1 == 0)) {
                      (**(code **)(local_f8[1] + 0x30))(local_f8);
                    }
                    if ((local_e8 != (longlong *)0x0) &&
                       (lVar11 = *local_e8, *local_e8 = lVar11 + -1, lVar11 + -1 == 0)) {
                      (**(code **)(local_e8[1] + 0x30))(local_e8);
                    }
                    *plVar2 = *plVar2 + -1;
                    if (*plVar2 == 0) {
                      (**(code **)(plVar2[1] + 0x30))(plVar2);
                    }
                    lVar11 = *plVar1;
                    *plVar1 = lVar11 + -1;
                    if (lVar11 + -1 != 0) {
                      return plVar18;
                    }
                    (**(code **)(plVar1[1] + 0x30))(plVar1);
                    return plVar18;
                  }
                  local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_b8 = *(longlong **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *plVar18 = *plVar18 + -1;
                  plVar13 = (longlong *)0x0;
                  if (*plVar18 == 0) {
                    FUN_23a334bc0(plVar18);
                    uVar22 = 0xd0;
                    local_e8 = (longlong *)0x0;
                  }
                  else {
                    uVar22 = 0xd0;
                    local_e8 = (longlong *)0x0;
                  }
                }
                goto LAB_23e6fa01d;
              }
              local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_b8 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                FUN_23a334bc0(plVar13);
              }
              *plVar17 = *plVar17 + -1;
              if (*plVar17 == 0) {
                FUN_23a334bc0(plVar17);
              }
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                FUN_23a334bc0(plVar15);
              }
              lVar11 = *plVar18;
              *plVar18 = lVar11 + -1;
              if (lVar11 + -1 == 0) {
                FUN_23a334bc0(plVar18);
              }
            }
            local_100 = (longlong *)0x0;
            local_108 = (longlong *)0x0;
            local_e8 = (longlong *)0x0;
            local_f8 = (longlong *)0x0;
            plVar15 = (longlong *)0x0;
            plVar17 = (longlong *)0x0;
            plVar14 = (longlong *)0x0;
            plVar13 = (longlong *)0x0;
            uVar22 = 0xc4;
            goto LAB_23e6fa01d;
          }
          plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda4f0);
          if (plVar13 == (longlong *)0x0) {
LAB_23e6fbd21:
            uVar19 = *(undefined8 *)(param_1 + 0x60);
            uVar16 = *(undefined8 *)(param_1 + 0x68);
            plVar13 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          else {
            plVar14 = (longlong *)FUN_23a388310(plVar13);
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            if (plVar14 == (longlong *)0x0) goto LAB_23e6fbd21;
            plVar15 = (longlong *)(**(code **)(plVar14[1] + 0xe0))(plVar14);
            if ((plVar15 == (longlong *)0x0) &&
               (plVar15 = (longlong *)FUN_23a3c1b70(param_1,local_c8,0,4),
               plVar15 == (longlong *)0x0)) {
              local_f8 = (longlong *)0x0;
              local_100 = (longlong *)0x0;
              local_108 = (longlong *)0x0;
            }
            else {
              local_108 = (longlong *)(**(code **)(plVar14[1] + 0xe0))(plVar14);
              if ((local_108 == (longlong *)0x0) &&
                 (local_108 = (longlong *)FUN_23a3c1b70(param_1,local_c8,1,4),
                 local_108 == (longlong *)0x0)) {
                local_f8 = (longlong *)0x0;
                local_100 = (longlong *)0x0;
              }
              else {
                local_100 = (longlong *)(**(code **)(plVar14[1] + 0xe0))(plVar14);
                if ((local_100 == (longlong *)0x0) &&
                   (local_100 = (longlong *)FUN_23a3c1b70(param_1,local_c8,2,4),
                   local_100 == (longlong *)0x0)) {
                  local_f8 = (longlong *)0x0;
                }
                else {
                  local_f8 = (longlong *)(**(code **)(plVar14[1] + 0xe0))(plVar14);
                  if (((local_f8 != (longlong *)0x0) ||
                      (local_f8 = (longlong *)FUN_23a3c1b70(param_1,local_c8,3,4),
                      local_f8 != (longlong *)0x0)) &&
                     (cVar9 = FUN_23a3884a0(param_1,local_c8,plVar14,4), cVar9 != '\0')) {
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                    }
                    if (*plVar15 == 0) {
                      (**(code **)(plVar15[1] + 0x30))(plVar15);
                    }
                    if (*local_108 == 0) {
                      (**(code **)(local_108[1] + 0x30))();
                    }
                    if (*local_100 == 0) {
                      (**(code **)(local_100[1] + 0x30))();
                    }
                    if (*local_f8 == 0) {
                      (**(code **)(local_f8[1] + 0x30))();
                    }
                    *(undefined4 *)(plVar4 + 5) = 0xd4;
                    local_98 = local_108;
                    local_90 = local_100;
                    local_88 = local_f8;
                    local_a8 = plVar1;
                    plStack_a0 = plVar15;
                    plVar14 = (longlong *)FUN_23e9694c0(param_1,plVar2);
                    if (plVar14 == (longlong *)0x0) {
                      local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_b8 = *(longlong **)(param_1 + 0x70);
                      plVar17 = (longlong *)0x0;
                      plVar13 = (longlong *)0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar22 = 0xd4;
                      local_e8 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e6fa01d;
                    }
                    plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda508);
                    if (plVar13 == (longlong *)0x0) {
                      local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_b8 = *(longlong **)(param_1 + 0x70);
                      plVar17 = (longlong *)0x0;
                      uVar22 = 0xd5;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_e8 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plVar13 = (longlong *)0x0;
                      goto LAB_23e6fa01d;
                    }
                    local_e8 = (longlong *)FUN_23e8c6640(plVar12,plVar13);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                    if (local_e8 == (longlong *)0x0) {
                      local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_b8 = *(longlong **)(param_1 + 0x70);
                      plVar17 = (longlong *)0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      plVar13 = (longlong *)0x0;
                      uVar22 = 0xd5;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e6fa01d;
                    }
                    plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda4f8);
                    if (plVar13 == (longlong *)0x0) {
                      local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_b8 = *(longlong **)(param_1 + 0x70);
                      uVar22 = 0xd7;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      plVar17 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plVar13 = (longlong *)0x0;
                      goto LAB_23e6fa01d;
                    }
                    iVar10 = FUN_23e97d0c0(plVar14,plVar13);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                    pcVar6 = _Py_TrueStruct_exref;
                    if (iVar10 == -1) {
                      local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_b8 = *(longlong **)(param_1 + 0x70);
                      plVar17 = (longlong *)0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar22 = 0xd7;
                      plVar13 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e6fa01d;
                    }
                    if (iVar10 == 1) {
                      cVar9 = FUN_23e8d9ac0(plVar2,DAT_23eeda4f8,plVar14);
                      if (cVar9 == '\0') {
                        local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                        local_b8 = *(longlong **)(param_1 + 0x70);
                        plVar17 = (longlong *)0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar22 = 0xd9;
                        plVar13 = (longlong *)0x0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23e6fa01d;
                      }
                      plVar18 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),7);
                      lVar11 = *plVar14;
                      plVar18[3] = (longlong)plVar14;
                      *plVar14 = lVar11 + 2;
                      plVar18[4] = (longlong)plVar14;
                      plVar13 = DAT_23ed6cd00;
                      *DAT_23ed6cd00 = *DAT_23ed6cd00 + 1;
                      plVar18[5] = (longlong)plVar13;
                      plVar18[6] = (longlong)pcVar6;
                      plVar18[7] = (longlong)pcVar5;
                      uVar19 = DAT_23eeda530;
                      *(longlong *)pcVar6 = *(longlong *)pcVar6 + 1;
                      *(longlong *)pcVar5 = *(longlong *)pcVar5 + 1;
                      lVar11 = FUN_23e8bc2f0(plVar2,uVar19);
                      if (lVar11 == 0) {
                        local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                        local_b8 = *(longlong **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *plVar18 = *plVar18 + -1;
                        plVar13 = (longlong *)0x0;
                        if (*plVar18 == 0) {
                          plVar17 = (longlong *)0x0;
                          FUN_23a334bc0(plVar18);
                          uVar22 = 0xda;
                        }
                        else {
                          plVar17 = (longlong *)0x0;
                          uVar22 = 0xda;
                        }
                        goto LAB_23e6fa01d;
                      }
                    }
                    else {
                      plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda5d0);
                      if (plVar13 == (longlong *)0x0) {
                        local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                        local_b8 = *(longlong **)(param_1 + 0x70);
                        plVar17 = (longlong *)0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar22 = 0xdc;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        plVar13 = (longlong *)0x0;
                        goto LAB_23e6fa01d;
                      }
                      iVar10 = FUN_23e97c060(local_e8,plVar13);
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      if (iVar10 == -1) {
                        local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                        local_b8 = *(longlong **)(param_1 + 0x70);
                        plVar17 = (longlong *)0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar22 = 0xdc;
                        plVar13 = (longlong *)0x0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23e6fa01d;
                      }
                      if (iVar10 != 1) {
                        lVar11 = FUN_23e8e1b00();
                        if (lVar11 == 0) {
                          plVar17 = (longlong *)0x0;
                          FUN_23e915740(param_1,local_c8,DAT_23eeda4c8);
                          uVar22 = 0xe0;
                          plVar13 = (longlong *)0x0;
                          goto LAB_23e6fa01d;
                        }
                        *(undefined4 *)(plVar4 + 5) = 0xe0;
                        plVar13 = (longlong *)FUN_23e915840(param_1,lVar11,DAT_23eeda5e8);
                        if (plVar13 == (longlong *)0x0) {
                          local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                          local_b8 = *(longlong **)(param_1 + 0x70);
                          plVar17 = (longlong *)0x0;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          uVar22 = 0xe0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          plVar13 = (longlong *)0x0;
                          goto LAB_23e6fa01d;
                        }
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          FUN_23a334bc0(plVar13);
                        }
                        cVar9 = FUN_23e8d9ac0(plVar2,DAT_23eeda510,pcVar5);
                        if (cVar9 == '\0') {
                          local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                          local_b8 = *(longlong **)(param_1 + 0x70);
                          plVar17 = (longlong *)0x0;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          uVar22 = 0xe1;
                          plVar13 = (longlong *)0x0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          goto LAB_23e6fa01d;
                        }
                        uVar16 = FUN_23a3a0d40(DAT_23ed6cf28);
                        plVar13 = DAT_23eeda5f0;
                        plVar18 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),7);
                        *plVar13 = *plVar13 + 1;
                        uVar19 = DAT_23eeda4f8;
                        plVar18[3] = (longlong)plVar13;
                        plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,uVar19);
                        if (plVar13 != (longlong *)0x0) {
                          lVar11 = FUN_23e94f9d0(param_1,plVar13,DAT_23ed6cd28);
                          *plVar13 = *plVar13 + -1;
                          if (*plVar13 == 0) {
                            FUN_23a334bc0(plVar13);
                          }
                          if (lVar11 != 0) {
                            plVar18[4] = lVar11;
                            plVar13 = DAT_23eeda5f8;
                            *DAT_23eeda5f8 = *DAT_23eeda5f8 + 1;
                            plVar18[5] = (longlong)plVar13;
                            lVar11 = FUN_23e94f9d0(param_1,plVar14,DAT_23ed6cd28);
                            if (lVar11 != 0) {
                              plVar18[6] = lVar11;
                              uVar19 = DAT_23eeda608;
                              plVar13 = DAT_23eeda600;
                              *DAT_23eeda600 = *DAT_23eeda600 + 1;
                              plVar18[7] = (longlong)plVar13;
                              lVar11 = FUN_23e94f9d0(param_1,local_e8,uVar19);
                              if (lVar11 != 0) {
                                plVar18[8] = lVar11;
                                plVar13 = DAT_23eeda610;
                                *DAT_23eeda610 = *DAT_23eeda610 + 1;
                                plVar18[9] = (longlong)plVar13;
                                plVar13 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar18);
                                *plVar18 = *plVar18 + -1;
                                if (*plVar18 == 0) {
                                  FUN_23a334bc0(plVar18);
                                }
                                if (plVar13 == (longlong *)0x0) {
                                  local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  local_b8 = *(longlong **)(param_1 + 0x70);
                                  plVar17 = (longlong *)0x0;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  uVar22 = 0xe2;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  plVar13 = (longlong *)0x0;
                                  goto LAB_23e6fa01d;
                                }
                                *(undefined4 *)(plVar4 + 5) = 0xe2;
                                plVar17 = (longlong *)FUN_23e914090(param_1,uVar16,plVar13);
                                *plVar13 = *plVar13 + -1;
                                if (*plVar13 == 0) {
                                  FUN_23a334bc0(plVar13);
                                }
                                if (plVar17 == (longlong *)0x0) {
                                  local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  local_b8 = *(longlong **)(param_1 + 0x70);
                                  plVar13 = (longlong *)0x0;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  uVar22 = 0xe2;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  plVar17 = (longlong *)0x0;
                                  goto LAB_23e6fa01d;
                                }
                                *plVar17 = *plVar17 + -1;
                                if (*plVar17 == 0) {
                                  FUN_23a334bc0(plVar17);
                                }
                                plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda580);
                                if (plVar13 == (longlong *)0x0) {
                                  local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  local_b8 = *(longlong **)(param_1 + 0x70);
                                  uVar22 = 0xe3;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  plVar17 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  plVar13 = (longlong *)0x0;
                                  goto LAB_23e6fa01d;
                                }
                                cVar9 = FUN_23e8d9ac0(plVar2,DAT_23eeda4e8,plVar13);
                                *plVar13 = *plVar13 + -1;
                                if (*plVar13 == 0) {
                                  FUN_23a334bc0(plVar13);
                                }
                                if (cVar9 == '\0') {
                                  local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  local_b8 = *(longlong **)(param_1 + 0x70);
                                  plVar17 = (longlong *)0x0;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  uVar22 = 0xe3;
                                  plVar13 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  goto LAB_23e6fa01d;
                                }
                                plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeda618);
                                if (plVar13 == (longlong *)0x0) {
                                  local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  local_b8 = *(longlong **)(param_1 + 0x70);
                                  plVar17 = (longlong *)0x0;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  uVar22 = 0xe4;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  plVar13 = (longlong *)0x0;
                                  goto LAB_23e6fa01d;
                                }
                                plVar17 = (longlong *)FUN_23e8c09e0(plVar12,plVar13);
                                *plVar13 = *plVar13 + -1;
                                if (*plVar13 == 0) {
                                  FUN_23a334bc0(plVar13);
                                }
                                if (plVar17 == (longlong *)0x0) {
                                  local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  local_b8 = *(longlong **)(param_1 + 0x70);
                                  plVar13 = (longlong *)0x0;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  uVar22 = 0xe4;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  plVar17 = (longlong *)0x0;
                                  goto LAB_23e6fa01d;
                                }
                                cVar9 = FUN_23e8d9ac0(plVar2,DAT_23eeda500);
                                *plVar17 = *plVar17 + -1;
                                if (*plVar17 == 0) {
                                  FUN_23a334bc0(plVar17);
                                }
                                if (cVar9 == '\0') {
                                  local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  local_b8 = *(longlong **)(param_1 + 0x70);
                                  plVar17 = (longlong *)0x0;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  plVar13 = (longlong *)0x0;
                                  uVar22 = 0xe4;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  goto LAB_23e6fa01d;
                                }
                                plVar18 = (longlong *)
                                          FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),7);
                                lVar11 = *plVar14;
                                plVar18[3] = (longlong)plVar14;
                                *plVar14 = lVar11 + 2;
                                plVar18[4] = (longlong)plVar14;
                                plVar13 = DAT_23ed6cd00;
                                *DAT_23ed6cd00 = *DAT_23ed6cd00 + 1;
                                plVar18[5] = (longlong)plVar13;
                                *(longlong *)pcVar6 = *(longlong *)pcVar6 + 2;
                                plVar18[6] = (longlong)pcVar6;
                                plVar18[7] = (longlong)pcVar6;
                                lVar11 = FUN_23e8bc2f0(plVar2,DAT_23eeda530);
                                if (lVar11 == 0) {
                                  local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  local_b8 = *(longlong **)(param_1 + 0x70);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  *plVar18 = *plVar18 + -1;
                                  plVar13 = (longlong *)0x0;
                                  if (*plVar18 == 0) {
                                    plVar17 = (longlong *)0x0;
                                    FUN_23a334bc0(plVar18);
                                    uVar22 = 0xe5;
                                  }
                                  else {
                                    plVar17 = (longlong *)0x0;
                                    uVar22 = 0xe5;
                                  }
                                  goto LAB_23e6fa01d;
                                }
                                goto LAB_23e6fab63;
                              }
                            }
                          }
                        }
                        local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                        local_b8 = *(longlong **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *plVar18 = *plVar18 + -1;
                        if (*plVar18 == 0) {
                          plVar13 = (longlong *)0x0;
                          plVar17 = (longlong *)0x0;
                          FUN_23a334bc0(plVar18);
                          uVar22 = 0xe2;
                        }
                        else {
                          uVar22 = 0xe2;
                          plVar17 = (longlong *)0x0;
                          plVar13 = (longlong *)0x0;
                        }
                        goto LAB_23e6fa01d;
                      }
                      plVar18 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),7);
                      lVar11 = *plVar14;
                      plVar18[3] = (longlong)plVar14;
                      *plVar14 = lVar11 + 2;
                      plVar18[4] = (longlong)plVar14;
                      plVar13 = DAT_23ed6cd00;
                      *DAT_23ed6cd00 = *DAT_23ed6cd00 + 1;
                      plVar18[5] = (longlong)plVar13;
                      plVar18[6] = (longlong)pcVar6;
                      plVar18[7] = (longlong)pcVar5;
                      uVar19 = DAT_23eeda530;
                      *(longlong *)pcVar6 = *(longlong *)pcVar6 + 1;
                      *(longlong *)pcVar5 = *(longlong *)pcVar5 + 1;
                      lVar11 = FUN_23e8bc2f0(plVar2,uVar19);
                      if (lVar11 == 0) {
                        local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
                        local_b8 = *(longlong **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *plVar18 = *plVar18 + -1;
                        plVar13 = (longlong *)0x0;
                        if (*plVar18 == 0) {
                          plVar17 = (longlong *)0x0;
                          FUN_23a334bc0(plVar18);
                          uVar22 = 0xde;
                        }
                        else {
                          plVar17 = (longlong *)0x0;
                          uVar22 = 0xde;
                        }
                        goto LAB_23e6fa01d;
                      }
                    }
LAB_23e6fab63:
                    plVar18[8] = lVar11;
                    plVar4 = DAT_23ed6ccf0;
                    plVar17 = (longlong *)0x0;
                    plVar13 = (longlong *)0x0;
                    *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
                    plVar18[9] = (longlong)plVar4;
                    goto LAB_23e6fab80;
                  }
                }
              }
            }
            plVar13 = local_b8;
            uVar19 = local_c8._0_8_;
            uVar16 = local_c8._8_8_;
            local_b8 = (longlong *)0x0;
            local_c8 = (undefined1  [16])0x0;
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            local_b8 = (longlong *)0x0;
            local_c8 = (undefined1  [16])0x0;
            if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            if ((local_108 != (longlong *)0x0) &&
               (lVar11 = *local_108, *local_108 = lVar11 + -1, lVar11 + -1 == 0)) {
              (**(code **)(local_108[1] + 0x30))(local_108);
            }
            if ((local_100 != (longlong *)0x0) &&
               (lVar11 = *local_100, *local_100 = lVar11 + -1, lVar11 + -1 == 0)) {
              (**(code **)(local_100[1] + 0x30))(local_100);
            }
            if ((local_f8 != (longlong *)0x0) &&
               (lVar11 = *local_f8, *local_f8 = lVar11 + -1, lVar11 + -1 == 0)) {
              (**(code **)(local_f8[1] + 0x30))(local_f8);
            }
          }
          uVar22 = 0xd3;
          local_c8._8_8_ = uVar16;
          local_c8._0_8_ = uVar19;
          local_b8 = plVar13;
        }
      }
      else {
        cVar9 = FUN_23e8c7160(&local_a8);
        plVar14 = local_a8;
        if (cVar9 != '\0') goto LAB_23e6fa3f8;
LAB_23e6f9f87:
        plVar14 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar19 = *(undefined8 *)(param_1 + 0x60);
        uVar16 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e6f9fa0:
        local_b8 = (longlong *)0x0;
        local_c8 = (undefined1  [16])0x0;
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        uVar22 = 0xb1;
        local_c8._8_8_ = uVar16;
        local_c8._0_8_ = uVar19;
        local_b8 = plVar14;
      }
LAB_23e6f9fe8:
      local_100 = (longlong *)0x0;
      plVar15 = (longlong *)0x0;
      plVar17 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      local_e8 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      local_f8 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      goto LAB_23e6fa01d;
    }
    local_b8 = *(longlong **)(param_1 + 0x70);
    local_c8 = *(undefined1 (*) [16])(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  local_100 = (longlong *)0x0;
  plVar15 = (longlong *)0x0;
  plVar17 = (longlong *)0x0;
  plVar13 = (longlong *)0x0;
  local_e8 = (longlong *)0x0;
  plVar14 = (longlong *)0x0;
  uVar22 = 0xae;
  local_f8 = (longlong *)0x0;
  local_108 = (longlong *)0x0;
LAB_23e6fa01d:
  plVar20 = local_b8;
  plVar18 = DAT_23ed6a4f8;
  if (local_b8 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar18 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar20 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar20;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar5 = _PyRuntime_exref;
    plVar18[2] = 0;
    plVar18[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar11 = *(longlong *)(pcVar5 + 0x1f8);
    *(undefined4 *)((longlong)plVar18 + 0x24) = uVar22;
    lVar11 = *(longlong *)(lVar11 + 0x10);
    *(undefined4 *)(plVar18 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(lVar11 + 0x2e8);
    lVar21 = plVar18[-1];
    puVar3 = *(undefined8 **)(lVar11 + 8);
    *puVar3 = plVar18 + -2;
    plVar18[-2] = lVar11;
    plVar18[-1] = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar11 + 8) = plVar18 + -2;
    plVar20 = plVar18;
    if ((local_b8 != (longlong *)0x0) && (*local_b8 = *local_b8 + -1, *local_b8 == 0)) {
      (**(code **)(local_b8[1] + 0x30))(local_b8);
    }
  }
  else if ((longlong *)local_b8[3] != plVar4) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar18 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar8 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar8;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar5 = _PyRuntime_exref;
    plVar18[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar11 = *(longlong *)(pcVar5 + 0x1f8);
    *(undefined4 *)((longlong)plVar18 + 0x24) = uVar22;
    *(undefined4 *)(plVar18 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
    lVar21 = plVar18[-1];
    puVar3 = *(undefined8 **)(lVar11 + 8);
    *puVar3 = plVar18 + -2;
    plVar18[-2] = lVar11;
    plVar18[-1] = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar11 + 8) = plVar18 + -2;
    plVar18[2] = (longlong)plVar20;
    *plVar20 = *plVar20 + 1;
    plVar20 = plVar18;
    if ((local_b8 != (longlong *)0x0) && (*local_b8 = *local_b8 + -1, *local_b8 == 0)) {
      (**(code **)(local_b8[1] + 0x30))(local_b8);
    }
  }
  local_b8 = plVar20;
  FUN_23e8bba40(plVar4,"ooooooooooo",plVar2,plVar1,plVar12,plVar13,plVar14,plVar17,plVar15,local_108
                ,local_100,local_f8,local_e8);
  if (DAT_23eedb1d0 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    DAT_23eedb1d0 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar4 = *(longlong **)(lVar11 + 0x28);
  plVar18 = (longlong *)plVar4[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar4 + 8) = 0xffffffff;
  if (plVar18 != (longlong *)0x0) {
    plVar4[2] = 0;
    *plVar18 = *plVar18 + -1;
    if (*plVar18 == 0) {
      (**(code **)(plVar18[1] + 0x30))();
    }
  }
  *plVar4 = *plVar4 + -1;
  if (*plVar4 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  plVar18 = local_b8;
  auVar7 = local_c8;
  plVar4[0xf] = 0;
  local_c8 = (undefined1  [16])0x0;
  local_b8 = (longlong *)0x0;
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
    (**(code **)(plVar17[1] + 0x30))(plVar17);
  }
  if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  if ((local_108 != (longlong *)0x0) &&
     (lVar11 = *local_108, *local_108 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_108[1] + 0x30))(local_108);
  }
  if ((local_100 != (longlong *)0x0) &&
     (lVar11 = *local_100, *local_100 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_100[1] + 0x30))(local_100);
  }
  if ((local_f8 != (longlong *)0x0) &&
     (lVar11 = *local_f8, *local_f8 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_f8[1] + 0x30))(local_f8);
  }
  if ((local_e8 != (longlong *)0x0) &&
     (lVar11 = *local_e8, *local_e8 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(local_e8[1] + 0x30))(local_e8);
  }
  *plVar2 = *plVar2 + -1;
  local_c8 = auVar7;
  local_b8 = plVar18;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  lVar11 = *plVar1;
  *plVar1 = lVar11 + -1;
  if (lVar11 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,local_c8._0_8_,local_c8._8_8_,local_b8);
  return (longlong *)0x0;
}
